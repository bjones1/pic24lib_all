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


#pragma once

// Documentation for this file. If the \file tag isn't present,
// this file won't be documented.
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
 * * CONFIG_Rxy_AS_ANALOG(): disables pullups/pulldowns, makes pin an input, and
 *   of course enables analog.
 * * CONFIG_Rxy_AS_DIG_INPUT/OUTPUT(): disables analog, pullups/pulldowns, and
 *   open-drain.
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
 *
 *  \todo
 *  - Put stub documentation for ALL port macros (doxygen only) so
 *    they hyperlink in source code
 */

// Dummy macros for documentation only
#ifdef __DOXYGEN__
/** \name High-level port configuration
 *  <a name="highLevelPortConfig">These</a> macros choose
 *  digital or analog, input or
 *  output, open-drain or standard. Use the low-level
 *  \ref ENABLE_Rxy_PULLUP() "ENABLE"/\ref DISABLE_Rxy_PULLUP() to
 *  configure the pullup.
 */
//@{
/** This macro disables open-drain and pullups,
 *  configures port x pin y for digital (not analog) operation, and
 *  sets the pin as an output. For example, CONFIG_RA10_AS_DIG_OUTPUT()
 *  makes port A, pin 10 a digital output.
 */
static inline void CONFIG_Rxy_AS_DIG_OUTPUT() {}

/** This macro enables open-drain, disables pullups,
 *  configures port x pin y for digital (not analog) operation, and
 *  sets the pin as an output. For example, CONFIG_RA10_AS_DIG_OD_OUTPUT()
 *  makes port A, pin 10 a digital output.
 */
static inline void CONFIG_Rxy_AS_DIG_OD_OUTPUT() {}

/** This macro disables pullups and analog functionality and sets
 *  the pin as an input. For example, CONFIG_RA10_AS_DIG_OUTPUT() makes
 *  port A, pin 10 a digital input.
 */
static inline void CONFIG_Rxy_AS_DIG_INPUT() {}

/** This macro first calls \ref CONFIG_Rxy_AS_DIG_INPUT() to disable
 *  pullups on the pin then enables analog functionality on the pin.
 *  For example, CONFIG_AN1_AS_ANALOG() makes AN1 an analog input pin.
 */
static inline void CONFIG_ANx_AS_ANALOG() {}
//@}

/** \name Low-level port configuration macros
 *  <a name="lowLevelPortConfig">These</a> macros support low-level pin
 *  configuration in the following areas:
 *  - Digital vs. analog configuration:
 *    - ENABLE_Rxy_ANALOG() sets the corresponding _PCFGn bit,
 *      while DISABLE_Rxy_ANALOG() clears the corresponding _PCFGn bit.
 *    - CONFIG_RPy_AS_DIG_PIN() sets the corresponding _PCFGn bit.
 *  - Input vs. output configuration: none. Instead, simply assign to
 *    the _TRISxy flag directly: _TRISB1 = 1 makes port B, pin 1 an input
 *    while _TRISB1 = 0 makes it an output.
 *  - Open-drain vs. standard output driver: ENABLE_Rxy_OPENDRAIN(),
 *    DISABLE_Rxy_OPENDRAIN()
 *  - Pull-up configuration: ENABLE_Rxy_PULLUP(), DISABLE_Rxy_PULLUP()
 *  - Change notification configuration: ENABLE_Rxy_CN_INTERRUPT(),
 *    DISABLE_Rxy_CN_INTERRUPT()
 */
//@{

/** Enables analog functionality on port x of pin y by clearing the
 *  corresponding _PCFGn bit. For example, ENABLE_RA10_ANALOG() enables
 *  analog functionality on port A pin 10.
 */
#define ENABLE_Rxy_ANALOG() _PCFGn = 0

/** Disables analog functionality on port x of pin y by setting the
 *  corresponding _PCFGn bit. For example, DISABLE_RA10_ANALOG() disables
 *  analog functionality on port A pin 10.
 */
#define DISABLE_Rxy_ANALOG() _PCFGn = 1

/** Makes port P, pin y a digital pin by disabling analog functionality
 *  on that pin. This is done by setting the
 *  corresponding _PCFGn bit. For example, CONFIG_RP10_AS_DIG_PIN() makes
 *  port P, pin 10 a digital pin by disabling analog its functionality.
 */
#define CONFIG_RPy_AS_DIG_PIN() _PCFG = 1

/** Enables the open-drain driver on port x, pin y. For example,
 *  ENABLE_Rxy_OPENDRAIN()
 */
#define ENABLE_Rxy_OPENDRAIN() _ODCxy = 1

/** Disables the open-drain driver on port x, pin y. For example,
 *  DISABLE_Rxy_OPENDRAIN()
 */
#define DISABLE_Rxy_OPENDRAIN() _ODCxy = 0

/** Enable the pullup on port x, pin y. For example,
 *  ENABLE_RA10_PULLUP() enables the pullup on port A, pin 10.
 */
#define ENABLE_Rxy_PULLUP() _CNmPUE = 1

/** Disable the pullup on port x, pin y. For example,
 *  DISABLE_RA10_PULLUP() disables the pullup on port A, pin 10.
 */
#define DISABLE_Rxy_PULLUP() _CNmPUE = 1

/** Enables the change notification interrupt on port x, pin y.
 *  For example, ENABLE_RA10_CN_INTERRUPT() enables the change
 *  notification interrupt on port A, pin 10.
 */
#define ENABLE_Rxy_CN_INTERRUPT() _CNmIE = 1

/** Disables the change notification interrupt on port x, pin y.
 *  For example, DISABLE_RA10_CN_INTERRUPT() disables the change
 *  notification interrupt on port A, pin 10.
 */
#define DISABLE_Rxy_CN_INTERRUPT() _CNmIE = 0
//@}
#endif // #ifdef __DOXYGEN__


// Port configuration
// ==================
// Analog
// ------
// Return the PCFG pin for the given Rxy_AN value.
#define RXY_GPIO_PCFG(Rxy_AN) _RXY_GPIO_PCFG(Rxy_AN)
#define _RXY_GPIO_PCFG(Rxy_AN) (_PCFG ## Rxy_AN)

// Change notification / pullups and pulldowns
// -------------------------------------------
// Return the _CNmPUE pin for the given Rxy_CN value.
#define RXY_GPIO_CNPUE(Rxy_CN) _RXY_GPIO_CNPUE(Rxy_CN)
#define _RXY_GPIO_CNPUE(Rxy_CN) (_CN ## Rxy_CN ## PUE)
// Return the _CNmIE pin  for the given Rxy_CN value.
#define RXY_GPIO_CNIE(Rxy_CN) _RXY_GPIO_CNIE(Rxy_CN)
#define _RXY_GPIO_CNIE(Rxy_CN) (_CN ## Rxy_CN ## IE)

// Return true if the given Rxy_CN pin has pulldown capabilities.
#define RXY_HAS_CNPDE(Rxy_CN) _RXY_HAS_CNPDE(Rxy_CN)
#define _RXY_HAS_CNPDE(Rxy_CN) defined(_CN ## Rxy_CN ## PDE)
// Return the _CNmPDE pin for the given Rxy_GPIO value.
#define RXY_GPIO_CNPDE(Rxy_CN) _RXY_GPIO_CNPDE(Rxy_CN)
#define _RXY_GPIO_CNPDE(Rxy_CN) (_CN ## Rxy_CN ## PDE)

// Include the table data used to drive GPIO config.
#include "pic24_ports_mapping.h"
// Process this table into GPIO config.
#if defined(__PIC24E__) || defined(__dsPIC33E__)
# include "pic24_ports_e_config.h"
#else
# include "pic24_ports_fh_config.h"
#endif



/** \name Remappable peripheral input support
 *  <a name="remappableInputs">These</a> funcions map an input internal
 *  to the PIC to an input pin.
 *  For example, CONFIG_INT1_TO_RP(10) maps the INT1 edge-triggered
 *  interrupt to port P, pin 10.
 *
 *  Not all devices support remappable peripherals. In these cases,
 *  the macros below evalaute to nothing: \ref CONFIG_INT1_TO_RP(10) is
 *  a valid C statement which does nothing.
 */
//@{

#if defined(_INT1R) || defined(__DOXYGEN__)
/// Maps INT1 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more information.
#define CONFIG_INT1_TO_RP(pin) _INT1R = pin
#else
#define CONFIG_INT1_TO_RP(pin)
#endif

/// Maps INT2 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_INT2R) || defined(__DOXYGEN__)
#define CONFIG_INT2_TO_RP(pin) _INT2R = pin
#else
#define CONFIG_INT2_TO_RP(pin)
#endif

/// Maps T2CK to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_T2CKR) || defined(__DOXYGEN__)
#define CONFIG_T2CK_TO_RP(pin) _T2CKR = pin
#else
#define CONFIG_T2CK_TO_RP(pin)
#endif

/// Maps T3CK to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_T3CKR) || defined(__DOXYGEN__)
#define CONFIG_T3CK_TO_RP(pin) _T3CKR = pin
#else
#define CONFIG_T3CK_TO_RP(pin)
#endif

/// Maps T4CK to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_T4CKR) || defined(__DOXYGEN__)
#define CONFIG_T4CK_TO_RP(pin) _T4CKR = pin
#else
#define CONFIG_T4CK_TO_RP(pin)
#endif

/// Maps T5CK to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_T5CKR) || defined(__DOXYGEN__)
#define CONFIG_T5CK_TO_RP(pin) _T5CKR = pin
#else
#define CONFIG_T5CK_TO_RP(pin)
#endif

/// Maps IC1 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC1R) || defined(__DOXYGEN__)
#define CONFIG_IC1_TO_RP(pin) _IC1R = pin
#else
#define CONFIG_IC1_TO_RP(pin)
#endif

/// Maps IC2 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC2R) || defined(__DOXYGEN__)
#define CONFIG_IC2_TO_RP(pin) _IC2R = pin
#else
#define CONFIG_IC2_TO_RP(pin)
#endif

/// Maps IC3 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC3R) || defined(__DOXYGEN__)
#define CONFIG_IC3_TO_RP(pin) _IC3R = pin
#else
#define CONFIG_IC3_TO_RP(pin)
#endif

/// Maps IC4 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC4R) || defined(__DOXYGEN__)
#define CONFIG_IC4_TO_RP(pin) _IC4R = pin
#else
#define CONFIG_IC4_TO_RP(pin)
#endif

/// Maps IC5 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC5R) || defined(__DOXYGEN__)
#define CONFIG_IC5_TO_RP(pin) _IC5R = pin
#else
#define CONFIG_IC5_TO_RP(pin)
#endif

/// Maps IC6 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC6R) || defined(__DOXYGEN__)
#define CONFIG_IC6_TO_RP(pin) _IC6R = pin
#else
#define CONFIG_IC6_TO_RP(pin)
#endif

/// Maps IC7 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC7R) || defined(__DOXYGEN__)
#define CONFIG_IC7_TO_RP(pin) _IC7R = pin
#else
#define CONFIG_IC7_TO_RP(pin)
#endif

/// Maps IC8 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_IC8R) || defined(__DOXYGEN__)
#define CONFIG_IC8_TO_RP(pin) _IC8R = pin
#else
#define CONFIG_IC8_TO_RP(pin)
#endif

/// Maps OCFA to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_OCFAR) || defined(__DOXYGEN__)
#define CONFIG_OCFA_TO_RP(pin) _OCFAR = pin
#else
#define CONFIG_OCFA_TO_RP(pin)
#endif

/// Maps OCFB to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_OCFBR) || defined(__DOXYGEN__)
#define CONFIG_OCFB_TO_RP(pin) _OCFBR = pin
#else
#define CONFIG_OCFB_TO_RP(pin)
#endif

/// Maps U1RX to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_U1RXR) || defined(__DOXYGEN__)
#define CONFIG_U1RX_TO_RP(pin) _U1RXR = pin
#else
#define CONFIG_U1RX_TO_RP(pin)
#endif

/// Maps U1CTS to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_U1CTSR) || defined(__DOXYGEN__)
#define CONFIG_U1CTS_TO_RP(pin) _U1CTSR = pin
#else
#define CONFIG_U1CTS_TO_RP(pin)
#endif

/// Maps U2RX to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_U2RXR) || defined(__DOXYGEN__)
#define CONFIG_U2RX_TO_RP(pin) _U2RXR = pin
#else
#define CONFIG_U2RX_TO_RP(pin)
#endif

/// Maps U2CTS to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_U2CTSR) || defined(__DOXYGEN__)
#define CONFIG_U2CTS_TO_RP(pin) _U2CTSR = pin
#else
#define CONFIG_U2CTS_TO_RP(pin)
#endif

/// Maps SDI1 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_SDI1R) || defined(__DOXYGEN__)
#define CONFIG_SDI1_TO_RP(pin) _SDI1R = pin
#else
#define CONFIG_SDI1_TO_RP(pin)
#endif

/// Maps SCK1 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_SCK1R) || defined(__DOXYGEN__)
#define CONFIG_SCK1IN_TO_RP(pin) _SCK1R = pin
#else
#define CONFIG_SCK1IN_TO_RP(pin)
#endif

/// Maps SS1 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_SS1R) || defined(__DOXYGEN__)
#define CONFIG_SS1IN_TO_RP(pin) _SS1R = pin
#else
#define CONFIG_SS1IN_TO_RP(pin)
#endif

/// Maps SDI2 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_SDI2R) || defined(__DOXYGEN__)
#define CONFIG_SDI2_TO_RP(pin) _SDI2R = pin
#else
#define CONFIG_SDI2_TO_RP(pin)
#endif

/// Maps SCK2 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_SCK2R) || defined(__DOXYGEN__)
#define CONFIG_SCK2IN_TO_RP(pin) _SCK2R = pin
#else
#define CONFIG_SCK2IN_TO_RP(pin)
#endif

/// Maps SS2 to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_SS2R) || defined(__DOXYGEN__)
#define CONFIG_SS2IN_TO_RP(pin) _SS2R = pin
#else
#define CONFIG_SS2IN_TO_RP(pin)
#endif

/// Maps C1RX to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_C1RXR) || defined(__DOXYGEN__)
#define CONFIG_C1RXR_TO_RP(pin) _C1RXR = pin
#else
#define CONFIG_C1RXR_TO_RP(pin)
#endif

/// Maps C2RX to a remappable pin;
/// see <a href="#remappableInputs">remappable peripheral input support</a>
/// for more informatino.
#if defined(_C2RXR) || defined(__DOXYGEN__)
#define CONFIG_C2RXR_TO_RP(pin) _C2RXR = pin
#else
#define CONFIG_C2RXR_TO_RP(pin)
#endif
//@}


/** \name Remappable peripheral output support
 *  <a name="remappableOutputs">These</a> functions maps an output
 *  internal to the PIC to an output pin.
 *  For example, CONFIG_C1OUT_TO_RP(10) maps the C1OUT comparator
 *  output to port P, pin 10.
 *
 *  Not all devices support remappable peripherals. In these cases,
 *  the macros below evalaute to nothing: CONFIG_C1OUT_TO_RP(10) is
 *  a valid C statement which does nothing.
 */
//@{

/// Define peripheral pins.
/// \todo Isn't this defined in the Microchip includes somewhere?
#if defined(__PIC24E__) || defined(__dsPIC33F__)
#define RPMAP_C1OUT   24
#define RPMAP_C2OUT   25
#define RPMAP_U1TX  1
#define RPMAP_U1RTS   2
#define RPMAP_U2TX    3
#define RPMAP_U2RTS   4
#define RPMAP_SD01    5
#define RPMAP_SCK1OUT   6
#define RPMAP_SS1OUT    7
#define RPMAP_SDO2    8
#define RPMAP_SCK2OUT   9
#define RPMAP_SS2OUT    10
#define RPMAP_C1TX    14
#define RPMAP_OC1     16
#define RPMAP_OC2     17
#define RPMAP_OC3     18
#define RPMAP_OC4     19
#define RPMAP_OC5     20

#else

#define RPMAP_C1OUT   1
#define RPMAP_C2OUT   2
#define RPMAP_U1TX  3
#define RPMAP_U1RTS   4
#define RPMAP_U2TX    5
#define RPMAP_U2RTS   6
#define RPMAP_SD01    7
#define RPMAP_SCK1OUT   8
#define RPMAP_SS1OUT    9
#define RPMAP_SDO2    10
#define RPMAP_SCK2OUT   11
#define RPMAP_SS2OUT    12
#define RPMAP_C1TX    16
#define RPMAP_OC1     18
#define RPMAP_OC2     19
#define RPMAP_OC3     20
#define RPMAP_OC4     21
#define RPMAP_OC5     22

#endif

///  CONFIG_NULL_TO_RP(n) returns RPn to an 'unmapped' state
/// (i.e, the reset condition).
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_NULL_TO_RP(pin) _RP##pin##R = 0
#else
#define CONFIG_NULL_TO_RP(pin)
#endif

/// Maps C1OUT to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_C1OUT_TO_RP(pin) _RP##pin##R = RPMAP_C1OUT
#else
#define CONFIG_C1OUT_TO_RP(pin)
#endif

/// Maps C2OUT to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_C2OUT_TO_RP(pin) _RP##pin##R = RPMAP_C2OUT
#else
#define CONFIG_C2OUT_TO_RP(pin)
#endif

/// Maps U1TX to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_U1TX_TO_RP(pin) _CONFIG_U1TX_TO_RP(pin)
#define _CONFIG_U1TX_TO_RP(pin) _RP##pin##R = RPMAP_U1TX
#else
#define CONFIG_U1TX_TO_RP(pin)
#endif

/// Maps U1RTS to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_U1RTS_TO_RP(pin) _RP##pin##R = RPMAP_U1RTS
#else
#define CONFIG_U1RTS_TO_RP(pin)
#endif

/// Maps U2TX to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_U2TX_TO_RP(pin) _RP##pin##R = RPMAP_U2TX
#else
#define CONFIG_U2TX_TO_RP(pin)
#endif

/// Maps U2RTS to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_U2RTS_TO_RP(pin) _RP##pin##R = RPMAP_U2RTS
#else
#define CONFIG_U2RTS_TO_RP(pin)
#endif

/// Maps SDO1 to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_SDO1_TO_RP(pin) _RP##pin##R = RPMAP_SD01
#else
#define CONFIG_SDO1_TO_RP(pin)
#endif

/// Maps SCK1OUT to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_SCK1OUT_TO_RP(pin) _RP##pin##R = RPMAP_SCK1OUT
#else
#define CONFIG_SCK1OUT_TO_RP(pin)
#endif

/// Maps SS11OUT to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_SS1OUT_TO_RP(pin) _RP##pin##R = RPMAP_SS1OUT
#else
#define CONFIG_SS1OUT_TO_RP(pin)
#endif

/// Maps SDO2 to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_SDO2_TO_RP(pin) _RP##pin##R = RPMAP_SDO2
#else
#define CONFIG_SDO2_TO_RP(pin)
#endif

/// Maps SCK2OUT to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_SCK2OUT_TO_RP(pin) _RP##pin##R = RPMAP_SCK2OUT
#else
#define CONFIG_SCK2OUT_TO_RP(pin)
#endif

/// Maps SS2OUT to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_SS2OUT_TO_RP(pin) _RP##pin##R = RPMAP_SS2OUT
#else
#define CONFIG_SS2OUT_TO_RP(pin)
#endif

/// Maps C1TX to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_C1TX_TO_RP(pin) _RP##pin##R = RPMAP_C1TX
#else
#define CONFIG_C1TX_TO_RP(pin)
#endif

/// Maps OC1 to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_OC1_TO_RP(pin) _RP##pin##R = RPMAP_OC1
#else
#define CONFIG_OC1_TO_RP(pin)
#endif

/// Maps OC2 to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_OC2_TO_RP(pin) _RP##pin##R = RPMAP_OC2
#else
#define CONFIG_OC2_TO_RP(pin)
#endif

/// Maps OC3 to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_OC3_TO_RP(pin) _RP##pin##R = RPMAP_OC3
#else
#define CONFIG_OC3_TO_RP(pin)
#endif

/// Maps OC4 to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_OC4_TO_RP(pin) _RP##pin##R = RPMAP_OC4
#else
#define CONFIG_OC4_TO_RP(pin)
#endif

/// Maps OC5 to a remappable pin;
/// see <a href="#remappableOutputs">remappable peripheral output support</a>
/// for more information.
#if defined(_RP0R) || defined(_RP20R)  || defined(__DOXYGEN__)
#define CONFIG_OC5_TO_RP(pin) _RP##pin##R = RPMAP_OC5
#else
#define CONFIG_OC5_TO_RP(pin)
#endif
//@}

