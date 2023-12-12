/*
 * pid_C2000.c
 *
 * Code generation for model "pid_C2000".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sat Jul  3 23:13:26 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pid_C2000.h"
#include "pid_C2000_private.h"

/* Block signals (default storage) */
B_pid_C2000_T pid_C2000_B;

/* Block states (default storage) */
DW_pid_C2000_T pid_C2000_DW;

/* Real-time model */
RT_MODEL_pid_C2000_T pid_C2000_M_;
RT_MODEL_pid_C2000_T *const pid_C2000_M = &pid_C2000_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/* Model step function */
void pid_C2000_step(void)
{
  /* local block i/o variables */
  real_T rtb_pre_error;

  /* S-Function (c28xqep): '<Root>/QEP' */
  {
    pid_C2000_B.QEP = EvaRegs.T2CNT;
  }

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/rpm'
   *  Constant: '<Root>/velo_desire rpm'
   *  Product: '<Root>/Product'
   */
  pid_C2000_B.Subtract = pid_C2000_P.velo_desirerpm_Value - (real_T)
    pid_C2000_B.QEP * pid_C2000_P.rpm_Value;

  /* Gain: '<Root>/Kp' */
  pid_C2000_B.Kp = pid_C2000_P.Kp_Gain * pid_C2000_B.Subtract;

  /* Gain: '<Root>/Ki' incorporates:
   *  Constant: '<Root>/initial'
   *  Gain: '<Root>/t'
   *  Sum: '<Root>/Sum'
   */
  pid_C2000_B.Ki = (pid_C2000_B.Subtract + pid_C2000_P.initial_Value) *
    pid_C2000_P.t_Gain * pid_C2000_P.Ki_Gain;

  /* TransportDelay: '<Root>/pre_error' */
  {
    real_T **uBuffer = (real_T**)&pid_C2000_DW.pre_error_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&pid_C2000_DW.pre_error_PWORK.TUbufferPtrs[1];
    real_T simTime = pid_C2000_M->Timing.t[0];
    real_T tMinusDelay = simTime - pid_C2000_P.pre_error_Delay;
    rtb_pre_error = rt_TDelayInterpolate(
      tMinusDelay,
      0.0,
      *tBuffer,
      *uBuffer,
      pid_C2000_DW.pre_error_IWORK.CircularBufSize,
      &pid_C2000_DW.pre_error_IWORK.Last,
      pid_C2000_DW.pre_error_IWORK.Tail,
      pid_C2000_DW.pre_error_IWORK.Head,
      pid_C2000_P.pre_error_InitOutput,
      1,
      0);
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/1//t'
   *  Gain: '<Root>/Kd'
   *  Sum: '<Root>/Add2'
   */
  pid_C2000_B.Add = (pid_C2000_B.Subtract - rtb_pre_error) * pid_C2000_P.ut_Gain
    * pid_C2000_P.Kd_Gain + (pid_C2000_B.Kp + pid_C2000_B.Ki);

  /* S-Function (c28xpwm): '<Root>/PWM' */
  {
    EvaRegs.CMPR1 = (uint16_T)pid_C2000_B.Add;
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(pid_C2000_M->rtwLogInfo, (pid_C2000_M->Timing.t));

  /* Update for TransportDelay: '<Root>/pre_error' */
  {
    real_T **uBuffer = (real_T**)&pid_C2000_DW.pre_error_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&pid_C2000_DW.pre_error_PWORK.TUbufferPtrs[1];
    real_T simTime = pid_C2000_M->Timing.t[0];
    pid_C2000_DW.pre_error_IWORK.Head = ((pid_C2000_DW.pre_error_IWORK.Head <
      (pid_C2000_DW.pre_error_IWORK.CircularBufSize-1)) ?
      (pid_C2000_DW.pre_error_IWORK.Head+1) : 0);
    if (pid_C2000_DW.pre_error_IWORK.Head == pid_C2000_DW.pre_error_IWORK.Tail)
    {
      pid_C2000_DW.pre_error_IWORK.Tail = ((pid_C2000_DW.pre_error_IWORK.Tail <
        (pid_C2000_DW.pre_error_IWORK.CircularBufSize-1)) ?
        (pid_C2000_DW.pre_error_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[pid_C2000_DW.pre_error_IWORK.Head] = simTime;
    (*uBuffer)[pid_C2000_DW.pre_error_IWORK.Head] = pid_C2000_B.Subtract;
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(pid_C2000_M)!=-1) &&
        !((rtmGetTFinal(pid_C2000_M)-pid_C2000_M->Timing.t[0]) >
          pid_C2000_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(pid_C2000_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++pid_C2000_M->Timing.clockTick0)) {
    ++pid_C2000_M->Timing.clockTickH0;
  }

  pid_C2000_M->Timing.t[0] = pid_C2000_M->Timing.clockTick0 *
    pid_C2000_M->Timing.stepSize0 + pid_C2000_M->Timing.clockTickH0 *
    pid_C2000_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    pid_C2000_M->Timing.clockTick1++;
    if (!pid_C2000_M->Timing.clockTick1) {
      pid_C2000_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void pid_C2000_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pid_C2000_M, 0,
                sizeof(RT_MODEL_pid_C2000_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pid_C2000_M->solverInfo,
                          &pid_C2000_M->Timing.simTimeStep);
    rtsiSetTPtr(&pid_C2000_M->solverInfo, &rtmGetTPtr(pid_C2000_M));
    rtsiSetStepSizePtr(&pid_C2000_M->solverInfo, &pid_C2000_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&pid_C2000_M->solverInfo, (&rtmGetErrorStatus
      (pid_C2000_M)));
    rtsiSetRTModelPtr(&pid_C2000_M->solverInfo, pid_C2000_M);
  }

  rtsiSetSimTimeStep(&pid_C2000_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&pid_C2000_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(pid_C2000_M, &pid_C2000_M->Timing.tArray[0]);
  rtmSetTFinal(pid_C2000_M, -1);
  pid_C2000_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    pid_C2000_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(pid_C2000_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(pid_C2000_M->rtwLogInfo, (NULL));
    rtliSetLogT(pid_C2000_M->rtwLogInfo, "tout");
    rtliSetLogX(pid_C2000_M->rtwLogInfo, "");
    rtliSetLogXFinal(pid_C2000_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(pid_C2000_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(pid_C2000_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(pid_C2000_M->rtwLogInfo, 0);
    rtliSetLogDecimation(pid_C2000_M->rtwLogInfo, 1);
    rtliSetLogY(pid_C2000_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(pid_C2000_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(pid_C2000_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &pid_C2000_B), 0,
                sizeof(B_pid_C2000_T));

  /* states (dwork) */
  (void) memset((void *)&pid_C2000_DW, 0,
                sizeof(DW_pid_C2000_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(pid_C2000_M->rtwLogInfo, 0.0, rtmGetTFinal
    (pid_C2000_M), pid_C2000_M->Timing.stepSize0, (&rtmGetErrorStatus
    (pid_C2000_M)));

  /* Start for S-Function (c28xqep): '<Root>/QEP' */
  config_QEP_A (0, 65535, 1, 0);

  /* Start for TransportDelay: '<Root>/pre_error' */
  {
    real_T *pBuffer = &pid_C2000_DW.pre_error_RWORK.TUbufferArea[0];
    pid_C2000_DW.pre_error_IWORK.Tail = 0;
    pid_C2000_DW.pre_error_IWORK.Head = 0;
    pid_C2000_DW.pre_error_IWORK.Last = 0;
    pid_C2000_DW.pre_error_IWORK.CircularBufSize = 65536;
    pBuffer[0] = pid_C2000_P.pre_error_InitOutput;
    pBuffer[65536] = pid_C2000_M->Timing.t[0];
    pid_C2000_DW.pre_error_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
    pid_C2000_DW.pre_error_PWORK.TUbufferPtrs[1] = (void *) &pBuffer[65536];
  }

  /* Start for S-Function (c28xpwm): '<Root>/PWM' */
  EALLOW;
  GpioMuxRegs.GPAMUX.all |= 3U;        /* EVA PWM 1-6  pins*/
  config_PWM_A (37594.0,2,1,"INPUT_PORT",0.0,
                0,"SPECIFY_VIA_DIALOG",0.0,0,"SPECIFY_VIA_DIALOG",0.0,1638,
                0, 0, 0, 0, 1, 0, 1);
  EDIS;
}

/* Model terminate function */
void pid_C2000_terminate(void)
{
  /* (no terminate code required) */
}
