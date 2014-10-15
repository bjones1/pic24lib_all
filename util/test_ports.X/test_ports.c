// .. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
//    All rights reserved.
//    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
//    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
//    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
//
//    Permission to use, copy, modify, and distribute this software and its
//    documentation for any purpose, without fee, and without written agreement is
//    hereby granted, provided that the above copyright notice, the following
//    two paragraphs and the authors appear in all copies of this software.
//
//    IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
//    DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
//    OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
//    HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
//    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
//    AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
//    ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
//    PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
//
//    Please maintain this header in its entirety when copying/modifying
//    these files.
//
// *********************************************************************************
// test_ports.c - Test the GPIO configuration macros in include\pic24_ports_config.h
// *********************************************************************************

// To test GPIO macros create some dummy values for testing for the non-existing test port RT.
#define _RT1
#define RT1_RP 100
#define RT1_AN 200
#define RT1_CN 300
#define _CN300PDE
#define _ODCT1

#define _RT2

#define _RT3
#define _ODT3



#include "pic24_all.h"

// Undefine these, now that macro testing is done, to test them as local variables below.
#undef _CN300PDE
#undef _ODCT1
void test_rt1_low_level() {
  uint16_t _PCFG200 = 0;
  uint16_t _TRIST1 = 0;
  uint16_t _ODCT1 = 0;
  uint16_t _CN300PUE = 0;
  uint16_t _CN300PDE = 0;
  uint16_t _CN300IE = 0;

  ASSERT(RT1_RP == 100);
  ASSERT(RT1_AN == 200);

  ENABLE_RT1_ANALOG();
  ASSERT(_PCFG200 == 1);
  DISABLE_RT1_ANALOG();
  ASSERT(_PCFG200 == 0);


  CONFIG_RT1_AS_INPUT();
  ASSERT(_TRIST1 == 1);
  CONFIG_RT1_AS_OUTPUT();
  ASSERT(_TRIST1 == 0);

  ENABLE_RT1_OPENDRAIN();
  ASSERT(_ODCT1 == 1);
  DISABLE_RT1_OPENDRAIN();
  ASSERT(_ODCT1 == 0);

  ENABLE_RT1_PULLUP();
  ASSERT(_CN300PUE == 1);
  DISABLE_RT1_PULLUP();
  ASSERT(_CN300PUE == 0);

  ENABLE_RT1_PULLDOWN();
  ASSERT(_CN300PDE == 1);
  DISABLE_RT1_PULLDOWN();
  ASSERT(_CN300PDE == 0);

  ENABLE_RT1_CN_INTERRUPT();
  ASSERT(_CN300IE == 1);
  DISABLE_RT1_CN_INTERRUPT();
  ASSERT(_CN300IE == 0);
}


void test_rt1_high_level() {
  uint16_t _PCFG200 = 0;
  uint16_t _TRIST1 = 0;
  uint16_t _ODCT1 = 0;
  uint16_t _CN300PUE = 0;
  uint16_t _CN300PDE = 0;

  CONFIG_RT1_AS_ANALOG();
  ASSERT(_PCFG200 == 1);
  ASSERT(_TRIST1 == 1);
  ASSERT(_ODCT1 == 0);
  ASSERT(_CN300PUE == 0);
  ASSERT(_CN300PDE == 0);

  CONFIG_RT1_AS_DIG_INPUT();
  ASSERT(_PCFG200 == 0);
  ASSERT(_TRIST1 == 1);
  ASSERT(_ODCT1 == 0);
  ASSERT(_CN300PUE == 0);
  ASSERT(_CN300PDE == 0);

  CONFIG_RT1_AS_DIG_OUTPUT();
  ASSERT(_PCFG200 == 0);
  ASSERT(_TRIST1 == 0);
  ASSERT(_ODCT1 == 0);
  ASSERT(_CN300PUE == 0);
  ASSERT(_CN300PDE == 0);
}

// RT2 should not have most of the enable macros.
#ifdef RT2_REMAPPABLE
# error
#endif

#ifdef RT2_AN_PORT
# error
#endif

#ifdef ENABLE_RT2_ANALOG
# error
#endif

#ifdef ENABLE_RT2_OPENDRAIN
# error
#endif

#ifdef ENABLE_RT2_PULLUP
# error
#endif

#ifdef ENABLE_RT2_PULLDOWN
# error
#endif

#ifdef ENABLE_RT2_CN_INTERRUPT
# error
#endif

void test_rt2_low_level() {
  uint16_t _TRIST2 = 0;

  CONFIG_RT2_AS_INPUT();
  ASSERT(_TRIST2 == 1);
  CONFIG_RT2_AS_OUTPUT();
  ASSERT(_TRIST2 == 0);

  // These should exist, but do nothing.
  DISABLE_RT2_ANALOG();
  DISABLE_RT2_OPENDRAIN();
  DISABLE_RT2_PULLUP();
  DISABLE_RT2_PULLDOWN();
  DISABLE_RT2_CN_INTERRUPT();
}


#ifdef CONFIG_RT2_AS_ANALOG
# error
#endif

void test_rt2_high_level() {
  uint16_t _TRIST2 = 0;

  CONFIG_RT2_AS_DIG_INPUT();
  ASSERT(_TRIST2 == 1);

  CONFIG_RT2_AS_DIG_OUTPUT();
  ASSERT(_TRIST2 == 0);
}

#undef _ODT3
void test_rt3_low_level() {
  uint16_t _ODT3 = 0;

  ENABLE_RT3_OPENDRAIN();
  ASSERT(_ODT3 == 1);
  DISABLE_RT3_OPENDRAIN();
  ASSERT(_ODT3 == 0);
}


void test_rt3_high_level() {
  uint16_t _TRIST3 = 0;
  uint16_t _ODT3 = 1;

  _ODT3 = 1;
  CONFIG_RT3_AS_DIG_INPUT();
  ASSERT(_ODT3 == 0);

  _ODT3 = 1;
  CONFIG_RT3_AS_DIG_OUTPUT();
  ASSERT(_ODT3 == 0);
}

int main(void) {
  configBasic(HELLO_MSG);
  test_rt1_low_level();
  test_rt1_high_level();
  test_rt2_low_level();
  test_rt2_high_level();
  test_rt3_low_level();
  test_rt3_high_level();
  outString("Tests complete.\n");

  return 0;
}
