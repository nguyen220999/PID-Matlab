/*
 * pid_C2000_data.c
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

/* Block parameters (default storage) */
P_pid_C2000_T pid_C2000_P = {
  /* Expression: 1
   * Referenced by: '<Root>/velo_desire rpm'
   */
  1.0,

  /* Expression: 4.5
   * Referenced by: '<Root>/rpm'
   */
  4.5,

  /* Expression: 1
   * Referenced by: '<Root>/Kp'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/initial'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/t'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<Root>/Ki'
   */
  1.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/pre_error'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<Root>/pre_error'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<Root>/1//t'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<Root>/Kd'
   */
  1.0
};
