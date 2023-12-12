/*
 * File: test.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Jul 24 23:51:40 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "test.h"

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void test_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtDW.PulseGenerator = ((rtDW.clockTickCounter < 1L) && (rtDW.clockTickCounter >=
    0L));
  if (rtDW.clockTickCounter >= 99L) {
    rtDW.clockTickCounter = 0L;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* S-Function (c28xgpio_do): '<Root>/Digital Output' */
  {
    GpioDataRegs.GPASET.bit.GPIOA0 = (boolean_T) (rtDW.PulseGenerator);
    GpioDataRegs.GPACLEAR.bit.GPIOA0 = !(boolean_T) (rtDW.PulseGenerator);
  }
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(rtM, (NULL));

  /* states (dwork) */
  (void) memset((void *)&rtDW, 0,
                sizeof(DW));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtDW.clockTickCounter = 0L;

  /* Start for S-Function (c28xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioMuxRegs.GPAMUX.all &= 0xFFFE;
  GpioMuxRegs.GPADIR.all |= 0x1;
  EDIS;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
