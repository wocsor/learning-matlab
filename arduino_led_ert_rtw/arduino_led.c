/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: arduino_led.c
 *
 * Code generated for Simulink model 'arduino_led'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jun  1 14:01:56 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_led.h"
#include "arduino_led_private.h"

/* Block states (default storage) */
DW_arduino_led_T arduino_led_DW;

/* Real-time model */
RT_MODEL_arduino_led_T arduino_led_M_;
RT_MODEL_arduino_led_T *const arduino_led_M = &arduino_led_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void arduino_led_step(void)
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (arduino_led_DW.clockTickCounter <
                        arduino_led_P.PulseGenerator_Duty) &&
    (arduino_led_DW.clockTickCounter >= 0L) ? arduino_led_P.PulseGenerator_Amp :
    0.0;
  if (arduino_led_DW.clockTickCounter >= arduino_led_P.PulseGenerator_Period -
      1.0) {
    arduino_led_DW.clockTickCounter = 0L;
  } else {
    arduino_led_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
}

/* Model initialize function */
void arduino_led_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Output' */
  arduino_led_DW.obj.matlabCodegenIsDeleted = false;
  arduino_led_DW.obj.isInitialized = 1L;
  digitalIOSetup(13, 1);
  arduino_led_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void arduino_led_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&arduino_led_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
