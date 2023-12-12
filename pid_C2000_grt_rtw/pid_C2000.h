/*
 * pid_C2000.h
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

#ifndef RTW_HEADER_pid_C2000_h_
#define RTW_HEADER_pid_C2000_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef pid_C2000_COMMON_INCLUDES_
# define pid_C2000_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "DSP281x_Device.h"
#endif                                 /* pid_C2000_COMMON_INCLUDES_ */

#include "pid_C2000_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T Kp;                           /* '<Root>/Kp' */
  real_T Ki;                           /* '<Root>/Ki' */
  real_T Add;                          /* '<Root>/Add' */
  uint32_T QEP;                        /* '<Root>/QEP' */
} B_pid_C2000_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    real_T modelTStart;
    real_T TUbufferArea[131072];
  } pre_error_RWORK;                   /* '<Root>/pre_error' */

  struct {
    void *TUbufferPtrs[2];
  } pre_error_PWORK;                   /* '<Root>/pre_error' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } pre_error_IWORK;                   /* '<Root>/pre_error' */

  uint16_T QEP_OLD_PULSE_COUNT;        /* '<Root>/QEP' */
} DW_pid_C2000_T;

/* Parameters (default storage) */
struct P_pid_C2000_T_ {
  real_T velo_desirerpm_Value;         /* Expression: 1
                                        * Referenced by: '<Root>/velo_desire rpm'
                                        */
  real_T rpm_Value;                    /* Expression: 4.5
                                        * Referenced by: '<Root>/rpm'
                                        */
  real_T Kp_Gain;                      /* Expression: 1
                                        * Referenced by: '<Root>/Kp'
                                        */
  real_T initial_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/initial'
                                        */
  real_T t_Gain;                       /* Expression: 0.01
                                        * Referenced by: '<Root>/t'
                                        */
  real_T Ki_Gain;                      /* Expression: 1
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T pre_error_Delay;              /* Expression: 0.01
                                        * Referenced by: '<Root>/pre_error'
                                        */
  real_T pre_error_InitOutput;         /* Expression: 0
                                        * Referenced by: '<Root>/pre_error'
                                        */
  real_T ut_Gain;                      /* Expression: 0.01
                                        * Referenced by: '<Root>/1//t'
                                        */
  real_T Kd_Gain;                      /* Expression: 1
                                        * Referenced by: '<Root>/Kd'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pid_C2000_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_pid_C2000_T pid_C2000_P;

/* Block signals (default storage) */
extern B_pid_C2000_T pid_C2000_B;

/* Block states (default storage) */
extern DW_pid_C2000_T pid_C2000_DW;

/* Model entry point functions */
extern void pid_C2000_initialize(void);
extern void pid_C2000_step(void);
extern void pid_C2000_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pid_C2000_T *const pid_C2000_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pid_C2000'
 */
#endif                                 /* RTW_HEADER_pid_C2000_h_ */
