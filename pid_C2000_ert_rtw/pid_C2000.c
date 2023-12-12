/*
 * File: pid_C2000.c
 *
 * Code generated for Simulink model 'pid_C2000'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Jul 24 22:34:31 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "pid_C2000.h"
#define QEP_A_scaler                   (60/((float)-1.0*334*4))

void config_QEP_A(uint16_T initialCount, uint16_T period, uint16_T qepIndex,
                  uint16_T qepIndexQual);
void config_PWM_A(uint16_T timerPeriod, uint16_T waveformType,
                  uint16_T unit1Status, char* unit1Source, uint16_T unit1Value,
                  uint16_T unit2Status, char* unit2Source, uint16_T unit2Value,
                  uint16_T unit3Status, char* unit3Source, uint16_T unit3Value,
                  uint16_T controlLogic,
                  uint16_T enableDeadband1, uint16_T enableDeadband2, uint16_T
                  enableDeadband3,
                  uint16_T deadbandPrescaler, uint16_T deadbandPeriod, uint16_T
                  timerToADC, uint16_T preScaler);

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void pid_C2000_step(void)
{
  int32_T rtb_Add1;
  real_T Add_tmp;

  /* S-Function (c28xqep): '<Root>/QEP' */
  {
    uint16_T* ptrOldPulseCount = &rtDW.QEP_OLD_PULSE_COUNT;
    rtDW.QEP = ((int16_T)(*ptrOldPulseCount - EvaRegs.T2CNT))*QEP_A_scaler;
    *ptrOldPulseCount = EvaRegs.T2CNT;
  }

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/velo_desire rpm'
   *  Product: '<Root>/Product'
   */
  rtb_Add1 = 1000L - rtDW.QEP;

  /* Gain: '<Root>/t' incorporates:
   *  Gain: '<Root>/di t'
   */
  Add_tmp = 0.01 * (real_T)rtb_Add1;

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Kp'
   *  Gain: '<Root>/t'
   *
   * Block description for '<Root>/Kp':
   *  Kp
   */
  rtDW.Add = (500.0 * (real_T)rtb_Add1 + Add_tmp) + Add_tmp;

  /* S-Function (c28xpwm): '<Root>/PWM' */
  {
    EvaRegs.CMPR1 = (uint16_T)rtDW.Add;
  }
}

/* Model initialize function */
void pid_C2000_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(rtM, (NULL));

  /* states (dwork) */
  (void) memset((void *)&rtDW, 0,
                sizeof(DW));

  /* Start for S-Function (c28xqep): '<Root>/QEP' */
  config_QEP_A (0, 65535, 0, 0);

  /* Start for S-Function (c28xpwm): '<Root>/PWM' */
  EALLOW;
  GpioMuxRegs.GPAMUX.all |= 3U;        /* EVA PWM 1-6  pins*/
  config_PWM_A (37594.0,2,1,"INPUT_PORT",0.0,
                0,"SPECIFY_VIA_DIALOG",0.0,0,"SPECIFY_VIA_DIALOG",0.0,1637,
                0, 0, 0, 0, 1, 0, 1);
  EDIS;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
