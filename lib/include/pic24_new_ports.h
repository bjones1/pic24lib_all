/*
 * "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
 * All rights reserved.
 * (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
 * (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
 * (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the authors appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Please maintain this header in its entirety when copying/modifying
 * these files.
 *
 *
 */

/** \file
 * This file defines a series of macros which provide GPIO and related configuration for
 * each pin of a given PIC24/dsPIC33. Configuration is first defined at a low level,
 * by providing the following:
 *
 * * Analog/digital configuration: ENABLE/DISABLE_Rxy_ANALOG(). The DISABLE version
 *   will always exist; the ENABLE version exists only if the given pin has analog
 *   capability.
 * * Input/output configuration: CONFIG_Rxy_AS_INPUT/OUTPUT(). This exists for every pin.
 * * Open collector/normal (totem-pole) output driver configuration:
 *   ENABLE/DISABLE_Rxy_OPENDRAIN().  The DISABLE version
 *   will always exist; the ENABLE version exists only if the given pin has open-drain
 *   capability.
 * * Pullup/pulldown configuration: ENABLE/DISABLE_Rxy_PULLUP/DOWN().  The DISABLE version
 *   will always exist; the ENABLE version exists only if the given pin has pullup/pulldown
 *   capability.
 *
 * Related low-level configuration:
 * * Change notification interrupts: ENABLE/DISABLE_Rxy_CN_INTERRUPT().  The DISABLE version
 *   will always exist; the ENABLE version exists only if the given pin has change notification
 *   capability.
 * * Remappable pin to Rxy translation: the Rxy_REMAPPABLE macro identifies the RPy value for
 *   the given Rxy port. Typical usage with the remappable macros: CONFIG_INT1_TO(RB4_REMAPPABLE);
 * * Analog port to Rxy translation: The Rxy_AN_PORT macro identifies the ANn value for
 *   the given Rxy port. Typical usage: configADC1_ManualCH0(RB4_AN_PORT, 31, 0).
 *
 * Combining these produces higher-level configuration:
 * * CONFIG_Rxy_AS_ANALOG(), CONFIG_Rxy_AS_DIG_INPUT/OUTPUT() TODO
 *
 * Implementation notes
 * --------------------
 * This is a table-driven approach, which maps from the PIC's various naming
 * conventions to the Rxy naming convention. The mapping consists of one tables.
 * The table is indexed by Rxy, and matches every Rxy pin on the chip with
 * its remappable (RPy) number, analog (ANn) number, and its change notification
 * (CNm) number. For example:
 * //      Rxy       RPy,  ANn  CNm
 * #define RA0_GPIO    0,   4,   3
 * indiates that pin RA0 is also RP0, AN4, and CN3.
 *
 * To implement this approach, each of the following function-like macros takes as input a table
 * entry Rxy_GPIO, which gives information about that pin of the chip.
 * These macros always require a two-step approach: first, split the table entry
 * into invidiual values; then extract the desired value. For example:
 * //                RPy,        ANn         CNm
 * #define RB14_GPIO 3,          1,          GPIO_NONE
 * #define RXY_GPIO_PCFG(Rxy_GPIO) _RXY_GPIO_PCFG(Rxy_GPIO), where Rxy_GPIO
 * #define _RXY_GPIO_PCFG(RPy, ANn, CNm) _PCFG ## ANn
 * Then RXY_GPIO_PCFG(RB14_GPIO) evaluates to _RXY_GPIO_PCFG(3, 1, GPIO_NONE).
 * _RXY_GPIO_PCFG(3, 1, GPIO_NONE) evaluates to _PCFG ## 1, which is _PCFG1.
 */

#include <stdint.h>


// This value indicates that this Rxy pin does not provide the given functionality.
#define GPIO_NONE -1

// This table maps from Rxy pints to the corresponding ANn and CNm values.
//                RPy,        ANn         CNm
#define RB15_GPIO GPIO_NONE,  GPIO_NONE,  14
#define RB14_GPIO 3,          1,          GPIO_NONE

// Remappable pins
// ---------------
// Return true if the given Rxy_GPIO pin is remappable.
#define RXY_HAS_REMAPPABLE(Rxy_GPIO) _RXY_HAS_REMAPPABLE(Rxy_GPIO)
#define _RXY_HAS_REMAPPABLE(RPy, ANn, CNm) (RPy != GPIO_NONE)
// Return the remappable pin number for the given Rxy_GPIO value.
#define RXY_REMAPPABLE_PIN(Rxy_GPIO) _RXY_REMAPPABLE_PIN(Rxy_GPIO)
#define _RXY_REMAPPABLE_PIN(RPy, ANn, CNm) (RPy)

// Analog
// ------
// Return true if the given Rxy_GPIO pin has analog capabilities.
#define RXY_HAS_ANALOG(Rxy_GPIO) _RXY_HAS_ANALOG(Rxy_GPIO)
#define _RXY_HAS_ANALOG(RPy, ANn, CNm) (ANn != GPIO_NONE)
// Return the analog port number (the n in ANn) for the given Rxy_GPIO value.
#define RXY_AN_PORT(Rxy_GPIO) _RXY_AN_PORT(Rxy_GPIO)
#define _RXY_AN_PORT(RPy, ANn, CNm) (ANn)
// Return the PCFG pin for the given Rxy_GPIO value.
#define RXY_GPIO_PCFG(Rxy_GPIO) _RXY_GPIO_PCFG(Rxy_GPIO)
#define _RXY_GPIO_PCFG(RPy, ANn, CNm) (_PCFG ## ANn)

// Change notification / pullups and pulldowns
// -------------------------------------------
// Return true if the given Rxy_GPIO pin has change notification capabilities.
#define RXY_HAS_CHANGE_NOTIFICATION(Rxy_GPIO) _RXY_HAS_CHANGE_NOTIFICATION(Rxy_GPIO)
#define _RXY_HAS_CHANGE_NOTIFICATION(RPy, ANn, CNm) (CNm != GPIO_NONE)
// Return the _CNmPUE pin for the given Rxy_GPIO value.
#define RXY_GPIO_CNPUE(Rxy_GPIO) _RXY_GPIO_CNPUE(Rxy_GPIO)
#define _RXY_GPIO_CNPUE(RPy, ANn, CNm) (_CN ## CNm ## PUE)
// Return the _CNmIE pin  for the given Rxy_GPIO value.
#define RXY_GPIO_CNIE(Rxy_GPIO) _RXY_GPIO_CNIE(Rxy_GPIO)
#define _RXY_GPIO_CNIE(RPy, ANn, CNm) (_CN ## CNm ## IE)

// Return true if the given Rxy_GPIO pin has pulldown capabilities. This
// should only be called if RXY_HAS_CHANGE_NOTIFICATION for the given pin is true.
#define RXY_HAS_CNPDE(Rxy_GPIO) _RXY_HAS_CNPDE(Rxy_GPIO)
#define _RXY_HAS_CNPDE(RPy, ANn, CNm) defined(_CN ## CNm ## PDE)
// Return the _CNmPDE pin for the given Rxy_GPIO value.
#define RXY_GPIO_CNPDE(Rxy_GPIO) _RXY_GPIO_CNPDE(Rxy_GPIO)
#define _RXY_GPIO_CNPDE(RPy, ANn, CNm) (_CN ## CNm ## PDE)



/// To test this, just compile; all the "code" runs in the preprocessor. First,
/// create some dummy values for testing for the non-existing test port RT.
#define _RT1
#define _RT2

//                RPy,        ANn         CNm
#define RT1_GPIO  100,        200,        300
#define RT2_GPIO  GPIO_NONE,  GPIO_NONE,  GPIO_NONE

#define _CN300PDE
#define _ODCT1




// Provide GPIO for RT1
// ====================
#ifdef _RT1
# ifndef RT1_GPIO
#   warning "RT1_GPIO not defined, but pin RT1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RT1_GPIO)
# define RT1_REMAPPABLE RXY_REMAPPABLE_PIN(RT1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RT1_GPIO)
#   define ENABLE_RT1_ANALOG()  (RXY_GPIO_PCFG(RT1_GPIO) = 1)
#   define DISABLE_RT1_ANALOG() (RXY_GPIO_PCFG(RT1_GPIO) = 0)
#   define RT1_AN_PORT RXY_AN_PORT(RT1_GPIO)
# else
#   define DISABLE_RT1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RT1_AS_INPUT()  (_TRIST1 = 1)
# define CONFIG_RT1_AS_OUTPUT() (_TRIST1 = 0)

// Open-drain:
#if defined(_ODCT1)
# define ENABLE_RT1_OPENDRAIN()  (_ODCT1 = 1)
# define DISABLE_RT1_OPENDRAIN() (_ODCT1 = 0)
#elif defined(_ODT1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RT1_OPENDRAIN()  (_ODT1 = 1)
# define DISABLE_RT1_OPENDRAIN() (_ODT1 = 0)
#else
# define DISABLE_RT1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RT1_GPIO)
#   define ENABLE_RT1_PULLUP()  (RXY_GPIO_CNPUE(RT1_GPIO) = 1)
#   define DISABLE_RT1_PULLUP() (RXY_GPIO_CNPUE(RT1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RT1_GPIO)
#     define ENABLE_RT1_PULLDOWN()  (RXY_GPIO_CNPDE(RT1_GPIO) = 1)
#     define DISABLE_RT1_PULLDOWN() (RXY_GPIO_CNPDE(RT1_GPIO) = 0)
#   else
#     define DISABLE_RT1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RT1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RT1_GPIO) = 1)
#   define DISABLE_RT1_CN_INTERRUPT() (RXY_GPIO_CNIE(RT1_GPIO) = 0)

# else
#   define DISABLE_RT1_PULLUP() ((void) 0)
#   define DISABLE_RT1_PULLDOWN() ((void) 0)
#   define DISABLE_RT1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
#if 0
void CONFIG_RT1_AS_DIG_INPUT() {
  DISABLE_RT1_ANALOG();
  CONFIG_RT1_AS_INPUT();
  //DISABLE_RT1_OPENDRAIN();
  //DISABLE_RT1_PULLUP();
  //DISABLE_RB14_PULLDOWN();
}
#endif

#endif // #ifdef _RT1: Provide GPIO for RT1








// Undefine these, now that macro testing is done, to test them as local variables below.
#undef _CN300PDE
#undef _ODCT1
// RT1 should have the following:
void test_rt1_low_level() {
  uint16_t _PCFG200 = 0;
  uint16_t _TRIST1 = 0;
  uint16_t _ODCT1 = 0;
  uint16_t _CN300PUE = 0;
  uint16_t _CN300PDE = 0;
  uint16_t _CN300IE = 0;

  ASSERT(RT1_REMAPPABLE == 100);

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
