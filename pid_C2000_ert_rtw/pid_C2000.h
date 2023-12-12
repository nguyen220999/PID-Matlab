/*
 * File: pid_C2000.h
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

#ifndef RTW_HEADER_pid_C2000_h_
#define RTW_HEADER_pid_C2000_h_
#include <stddef.h>
#include <string.h>
#ifndef pid_C2000_COMMON_INCLUDES_
# define pid_C2000_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "DSP281x_Device.h"
#endif                                 /* pid_C2000_COMMON_INCLUDES_ */

#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define pid_C2000_M                    (rtM)

extern void enable_interrupts(void);

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Add;                          /* '<Root>/Add' */
  uint16_T QEP;                        /* '<Root>/QEP' */
  uint16_T QEP_OLD_PULSE_COUNT;        /* '<Root>/QEP' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void pid_C2000_initialize(void);
extern void pid_C2000_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Kd' : Eliminated nontunable gain of 1
 * Block '<Root>/Ki' : Eliminated nontunable gain of 1
 */

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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
