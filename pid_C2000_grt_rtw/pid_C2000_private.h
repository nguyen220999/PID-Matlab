/*
 * pid_C2000_private.h
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

#ifndef RTW_HEADER_pid_C2000_private_h_
#define RTW_HEADER_pid_C2000_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#define QEP_A_scaler                   (60/((float)0.01*1024*4))

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
  ;

#endif                                 /* RTW_HEADER_pid_C2000_private_h_ */
