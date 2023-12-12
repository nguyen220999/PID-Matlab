/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Jul 24 23:14:56 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  untitled_B.PulseGenerator = (untitled_DW.clockTickCounter <
    untitled_P.PulseGenerator_Duty) && (untitled_DW.clockTickCounter >= 0L) ?
    untitled_P.PulseGenerator_Amp : 0.0;
  if (untitled_DW.clockTickCounter >= untitled_P.PulseGenerator_Period - 1.0) {
    untitled_DW.clockTickCounter = 0L;
  } else {
    untitled_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* S-Function (c28xgpio_do): '<Root>/Digital Output' */
  {
    GpioDataRegs.GPASET.bit.GPIOA0 = (boolean_T) (untitled_B.PulseGenerator);
    GpioDataRegs.GPACLEAR.bit.GPIOA0 = !(boolean_T) (untitled_B.PulseGenerator);
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(untitled_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  untitled_DW.clockTickCounter = 0L;

  /* Start for S-Function (c28xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioMuxRegs.GPAMUX.all &= 0xFFFE;
  GpioMuxRegs.GPADIR.all |= 0x1;
  EDIS;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
