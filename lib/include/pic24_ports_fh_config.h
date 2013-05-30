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



// Provide GPIO for RA0
// ====================
#ifdef _RA0
# ifndef RA0_GPIO
#   warning "RA0_GPIO not defined, but pin RA0 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA0_GPIO)
# define RA0_REMAPPABLE RXY_REMAPPABLE_PIN(RA0_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA0_GPIO)
#   define ENABLE_RA0_ANALOG()  (RXY_GPIO_PCFG(RA0_GPIO) = 1)
#   define DISABLE_RA0_ANALOG() (RXY_GPIO_PCFG(RA0_GPIO) = 0)
#   define RA0_AN_PORT RXY_AN_PORT(RA0_GPIO)
# else
#   define DISABLE_RA0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA0_AS_INPUT()  (_TRISA0 = 1)
# define CONFIG_RA0_AS_OUTPUT() (_TRISA0 = 0)

// Open-drain:
#if defined(_ODCA0)
# define ENABLE_RA0_OPENDRAIN()  (_ODCA0 = 1)
# define DISABLE_RA0_OPENDRAIN() (_ODCA0 = 0)
#elif defined(_ODA0)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA0_OPENDRAIN()  (_ODA0 = 1)
# define DISABLE_RA0_OPENDRAIN() (_ODA0 = 0)
#else
# define DISABLE_RA0_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA0_GPIO)
#   define ENABLE_RA0_PULLUP()  (RXY_GPIO_CNPUE(RA0_GPIO) = 1)
#   define DISABLE_RA0_PULLUP() (RXY_GPIO_CNPUE(RA0_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA0_GPIO)
#     define ENABLE_RA0_PULLDOWN()  (RXY_GPIO_CNPDE(RA0_GPIO) = 1)
#     define DISABLE_RA0_PULLDOWN() (RXY_GPIO_CNPDE(RA0_GPIO) = 0)
#   else
#     define DISABLE_RA0_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA0_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA0_GPIO) = 1)
#   define DISABLE_RA0_CN_INTERRUPT() (RXY_GPIO_CNIE(RA0_GPIO) = 0)

# else
#   define DISABLE_RA0_PULLUP() ((void) 0)
#   define DISABLE_RA0_PULLDOWN() ((void) 0)
#   define DISABLE_RA0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA0_AS_ANALOG()       \
    do {                              \
      ENABLE_RA0_ANALOG();            \
      CONFIG_RA0_AS_INPUT();          \
      DISABLE_RA0_OPENDRAIN();        \
      DISABLE_RA0_PULLUP();           \
      DISABLE_RA0_PULLDOWN();         \
    } while (0)

# define CONFIG_RA0_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA0_ANALOG();           \
      CONFIG_RA0_AS_INPUT();          \
      DISABLE_RA0_OPENDRAIN();        \
      DISABLE_RA0_PULLUP();           \
      DISABLE_RA0_PULLDOWN();         \
    } while (0)

# define CONFIG_RA0_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA0_ANALOG();           \
      CONFIG_RA0_AS_OUTPUT();         \
      DISABLE_RA0_OPENDRAIN();        \
      DISABLE_RA0_PULLUP();           \
      DISABLE_RA0_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA0: Provide GPIO for RA0


// Provide GPIO for RA1
// ====================
#ifdef _RA1
# ifndef RA1_GPIO
#   warning "RA1_GPIO not defined, but pin RA1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA1_GPIO)
# define RA1_REMAPPABLE RXY_REMAPPABLE_PIN(RA1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA1_GPIO)
#   define ENABLE_RA1_ANALOG()  (RXY_GPIO_PCFG(RA1_GPIO) = 1)
#   define DISABLE_RA1_ANALOG() (RXY_GPIO_PCFG(RA1_GPIO) = 0)
#   define RA1_AN_PORT RXY_AN_PORT(RA1_GPIO)
# else
#   define DISABLE_RA1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA1_AS_INPUT()  (_TRISA1 = 1)
# define CONFIG_RA1_AS_OUTPUT() (_TRISA1 = 0)

// Open-drain:
#if defined(_ODCA1)
# define ENABLE_RA1_OPENDRAIN()  (_ODCA1 = 1)
# define DISABLE_RA1_OPENDRAIN() (_ODCA1 = 0)
#elif defined(_ODA1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA1_OPENDRAIN()  (_ODA1 = 1)
# define DISABLE_RA1_OPENDRAIN() (_ODA1 = 0)
#else
# define DISABLE_RA1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA1_GPIO)
#   define ENABLE_RA1_PULLUP()  (RXY_GPIO_CNPUE(RA1_GPIO) = 1)
#   define DISABLE_RA1_PULLUP() (RXY_GPIO_CNPUE(RA1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA1_GPIO)
#     define ENABLE_RA1_PULLDOWN()  (RXY_GPIO_CNPDE(RA1_GPIO) = 1)
#     define DISABLE_RA1_PULLDOWN() (RXY_GPIO_CNPDE(RA1_GPIO) = 0)
#   else
#     define DISABLE_RA1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA1_GPIO) = 1)
#   define DISABLE_RA1_CN_INTERRUPT() (RXY_GPIO_CNIE(RA1_GPIO) = 0)

# else
#   define DISABLE_RA1_PULLUP() ((void) 0)
#   define DISABLE_RA1_PULLDOWN() ((void) 0)
#   define DISABLE_RA1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA1_AS_ANALOG()       \
    do {                              \
      ENABLE_RA1_ANALOG();            \
      CONFIG_RA1_AS_INPUT();          \
      DISABLE_RA1_OPENDRAIN();        \
      DISABLE_RA1_PULLUP();           \
      DISABLE_RA1_PULLDOWN();         \
    } while (0)

# define CONFIG_RA1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA1_ANALOG();           \
      CONFIG_RA1_AS_INPUT();          \
      DISABLE_RA1_OPENDRAIN();        \
      DISABLE_RA1_PULLUP();           \
      DISABLE_RA1_PULLDOWN();         \
    } while (0)

# define CONFIG_RA1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA1_ANALOG();           \
      CONFIG_RA1_AS_OUTPUT();         \
      DISABLE_RA1_OPENDRAIN();        \
      DISABLE_RA1_PULLUP();           \
      DISABLE_RA1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA1: Provide GPIO for RA1


// Provide GPIO for RA2
// ====================
#ifdef _RA2
# ifndef RA2_GPIO
#   warning "RA2_GPIO not defined, but pin RA2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA2_GPIO)
# define RA2_REMAPPABLE RXY_REMAPPABLE_PIN(RA2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA2_GPIO)
#   define ENABLE_RA2_ANALOG()  (RXY_GPIO_PCFG(RA2_GPIO) = 1)
#   define DISABLE_RA2_ANALOG() (RXY_GPIO_PCFG(RA2_GPIO) = 0)
#   define RA2_AN_PORT RXY_AN_PORT(RA2_GPIO)
# else
#   define DISABLE_RA2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA2_AS_INPUT()  (_TRISA2 = 1)
# define CONFIG_RA2_AS_OUTPUT() (_TRISA2 = 0)

// Open-drain:
#if defined(_ODCA2)
# define ENABLE_RA2_OPENDRAIN()  (_ODCA2 = 1)
# define DISABLE_RA2_OPENDRAIN() (_ODCA2 = 0)
#elif defined(_ODA2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA2_OPENDRAIN()  (_ODA2 = 1)
# define DISABLE_RA2_OPENDRAIN() (_ODA2 = 0)
#else
# define DISABLE_RA2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA2_GPIO)
#   define ENABLE_RA2_PULLUP()  (RXY_GPIO_CNPUE(RA2_GPIO) = 1)
#   define DISABLE_RA2_PULLUP() (RXY_GPIO_CNPUE(RA2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA2_GPIO)
#     define ENABLE_RA2_PULLDOWN()  (RXY_GPIO_CNPDE(RA2_GPIO) = 1)
#     define DISABLE_RA2_PULLDOWN() (RXY_GPIO_CNPDE(RA2_GPIO) = 0)
#   else
#     define DISABLE_RA2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA2_GPIO) = 1)
#   define DISABLE_RA2_CN_INTERRUPT() (RXY_GPIO_CNIE(RA2_GPIO) = 0)

# else
#   define DISABLE_RA2_PULLUP() ((void) 0)
#   define DISABLE_RA2_PULLDOWN() ((void) 0)
#   define DISABLE_RA2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA2_AS_ANALOG()       \
    do {                              \
      ENABLE_RA2_ANALOG();            \
      CONFIG_RA2_AS_INPUT();          \
      DISABLE_RA2_OPENDRAIN();        \
      DISABLE_RA2_PULLUP();           \
      DISABLE_RA2_PULLDOWN();         \
    } while (0)

# define CONFIG_RA2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA2_ANALOG();           \
      CONFIG_RA2_AS_INPUT();          \
      DISABLE_RA2_OPENDRAIN();        \
      DISABLE_RA2_PULLUP();           \
      DISABLE_RA2_PULLDOWN();         \
    } while (0)

# define CONFIG_RA2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA2_ANALOG();           \
      CONFIG_RA2_AS_OUTPUT();         \
      DISABLE_RA2_OPENDRAIN();        \
      DISABLE_RA2_PULLUP();           \
      DISABLE_RA2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA2: Provide GPIO for RA2


// Provide GPIO for RA3
// ====================
#ifdef _RA3
# ifndef RA3_GPIO
#   warning "RA3_GPIO not defined, but pin RA3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA3_GPIO)
# define RA3_REMAPPABLE RXY_REMAPPABLE_PIN(RA3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA3_GPIO)
#   define ENABLE_RA3_ANALOG()  (RXY_GPIO_PCFG(RA3_GPIO) = 1)
#   define DISABLE_RA3_ANALOG() (RXY_GPIO_PCFG(RA3_GPIO) = 0)
#   define RA3_AN_PORT RXY_AN_PORT(RA3_GPIO)
# else
#   define DISABLE_RA3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA3_AS_INPUT()  (_TRISA3 = 1)
# define CONFIG_RA3_AS_OUTPUT() (_TRISA3 = 0)

// Open-drain:
#if defined(_ODCA3)
# define ENABLE_RA3_OPENDRAIN()  (_ODCA3 = 1)
# define DISABLE_RA3_OPENDRAIN() (_ODCA3 = 0)
#elif defined(_ODA3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA3_OPENDRAIN()  (_ODA3 = 1)
# define DISABLE_RA3_OPENDRAIN() (_ODA3 = 0)
#else
# define DISABLE_RA3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA3_GPIO)
#   define ENABLE_RA3_PULLUP()  (RXY_GPIO_CNPUE(RA3_GPIO) = 1)
#   define DISABLE_RA3_PULLUP() (RXY_GPIO_CNPUE(RA3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA3_GPIO)
#     define ENABLE_RA3_PULLDOWN()  (RXY_GPIO_CNPDE(RA3_GPIO) = 1)
#     define DISABLE_RA3_PULLDOWN() (RXY_GPIO_CNPDE(RA3_GPIO) = 0)
#   else
#     define DISABLE_RA3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA3_GPIO) = 1)
#   define DISABLE_RA3_CN_INTERRUPT() (RXY_GPIO_CNIE(RA3_GPIO) = 0)

# else
#   define DISABLE_RA3_PULLUP() ((void) 0)
#   define DISABLE_RA3_PULLDOWN() ((void) 0)
#   define DISABLE_RA3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA3_AS_ANALOG()       \
    do {                              \
      ENABLE_RA3_ANALOG();            \
      CONFIG_RA3_AS_INPUT();          \
      DISABLE_RA3_OPENDRAIN();        \
      DISABLE_RA3_PULLUP();           \
      DISABLE_RA3_PULLDOWN();         \
    } while (0)

# define CONFIG_RA3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA3_ANALOG();           \
      CONFIG_RA3_AS_INPUT();          \
      DISABLE_RA3_OPENDRAIN();        \
      DISABLE_RA3_PULLUP();           \
      DISABLE_RA3_PULLDOWN();         \
    } while (0)

# define CONFIG_RA3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA3_ANALOG();           \
      CONFIG_RA3_AS_OUTPUT();         \
      DISABLE_RA3_OPENDRAIN();        \
      DISABLE_RA3_PULLUP();           \
      DISABLE_RA3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA3: Provide GPIO for RA3


// Provide GPIO for RA4
// ====================
#ifdef _RA4
# ifndef RA4_GPIO
#   warning "RA4_GPIO not defined, but pin RA4 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA4_GPIO)
# define RA4_REMAPPABLE RXY_REMAPPABLE_PIN(RA4_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA4_GPIO)
#   define ENABLE_RA4_ANALOG()  (RXY_GPIO_PCFG(RA4_GPIO) = 1)
#   define DISABLE_RA4_ANALOG() (RXY_GPIO_PCFG(RA4_GPIO) = 0)
#   define RA4_AN_PORT RXY_AN_PORT(RA4_GPIO)
# else
#   define DISABLE_RA4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA4_AS_INPUT()  (_TRISA4 = 1)
# define CONFIG_RA4_AS_OUTPUT() (_TRISA4 = 0)

// Open-drain:
#if defined(_ODCA4)
# define ENABLE_RA4_OPENDRAIN()  (_ODCA4 = 1)
# define DISABLE_RA4_OPENDRAIN() (_ODCA4 = 0)
#elif defined(_ODA4)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA4_OPENDRAIN()  (_ODA4 = 1)
# define DISABLE_RA4_OPENDRAIN() (_ODA4 = 0)
#else
# define DISABLE_RA4_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA4_GPIO)
#   define ENABLE_RA4_PULLUP()  (RXY_GPIO_CNPUE(RA4_GPIO) = 1)
#   define DISABLE_RA4_PULLUP() (RXY_GPIO_CNPUE(RA4_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA4_GPIO)
#     define ENABLE_RA4_PULLDOWN()  (RXY_GPIO_CNPDE(RA4_GPIO) = 1)
#     define DISABLE_RA4_PULLDOWN() (RXY_GPIO_CNPDE(RA4_GPIO) = 0)
#   else
#     define DISABLE_RA4_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA4_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA4_GPIO) = 1)
#   define DISABLE_RA4_CN_INTERRUPT() (RXY_GPIO_CNIE(RA4_GPIO) = 0)

# else
#   define DISABLE_RA4_PULLUP() ((void) 0)
#   define DISABLE_RA4_PULLDOWN() ((void) 0)
#   define DISABLE_RA4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA4_AS_ANALOG()       \
    do {                              \
      ENABLE_RA4_ANALOG();            \
      CONFIG_RA4_AS_INPUT();          \
      DISABLE_RA4_OPENDRAIN();        \
      DISABLE_RA4_PULLUP();           \
      DISABLE_RA4_PULLDOWN();         \
    } while (0)

# define CONFIG_RA4_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA4_ANALOG();           \
      CONFIG_RA4_AS_INPUT();          \
      DISABLE_RA4_OPENDRAIN();        \
      DISABLE_RA4_PULLUP();           \
      DISABLE_RA4_PULLDOWN();         \
    } while (0)

# define CONFIG_RA4_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA4_ANALOG();           \
      CONFIG_RA4_AS_OUTPUT();         \
      DISABLE_RA4_OPENDRAIN();        \
      DISABLE_RA4_PULLUP();           \
      DISABLE_RA4_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA4: Provide GPIO for RA4


// Provide GPIO for RA5
// ====================
#ifdef _RA5
# ifndef RA5_GPIO
#   warning "RA5_GPIO not defined, but pin RA5 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA5_GPIO)
# define RA5_REMAPPABLE RXY_REMAPPABLE_PIN(RA5_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA5_GPIO)
#   define ENABLE_RA5_ANALOG()  (RXY_GPIO_PCFG(RA5_GPIO) = 1)
#   define DISABLE_RA5_ANALOG() (RXY_GPIO_PCFG(RA5_GPIO) = 0)
#   define RA5_AN_PORT RXY_AN_PORT(RA5_GPIO)
# else
#   define DISABLE_RA5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA5_AS_INPUT()  (_TRISA5 = 1)
# define CONFIG_RA5_AS_OUTPUT() (_TRISA5 = 0)

// Open-drain:
#if defined(_ODCA5)
# define ENABLE_RA5_OPENDRAIN()  (_ODCA5 = 1)
# define DISABLE_RA5_OPENDRAIN() (_ODCA5 = 0)
#elif defined(_ODA5)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA5_OPENDRAIN()  (_ODA5 = 1)
# define DISABLE_RA5_OPENDRAIN() (_ODA5 = 0)
#else
# define DISABLE_RA5_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA5_GPIO)
#   define ENABLE_RA5_PULLUP()  (RXY_GPIO_CNPUE(RA5_GPIO) = 1)
#   define DISABLE_RA5_PULLUP() (RXY_GPIO_CNPUE(RA5_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA5_GPIO)
#     define ENABLE_RA5_PULLDOWN()  (RXY_GPIO_CNPDE(RA5_GPIO) = 1)
#     define DISABLE_RA5_PULLDOWN() (RXY_GPIO_CNPDE(RA5_GPIO) = 0)
#   else
#     define DISABLE_RA5_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA5_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA5_GPIO) = 1)
#   define DISABLE_RA5_CN_INTERRUPT() (RXY_GPIO_CNIE(RA5_GPIO) = 0)

# else
#   define DISABLE_RA5_PULLUP() ((void) 0)
#   define DISABLE_RA5_PULLDOWN() ((void) 0)
#   define DISABLE_RA5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA5_AS_ANALOG()       \
    do {                              \
      ENABLE_RA5_ANALOG();            \
      CONFIG_RA5_AS_INPUT();          \
      DISABLE_RA5_OPENDRAIN();        \
      DISABLE_RA5_PULLUP();           \
      DISABLE_RA5_PULLDOWN();         \
    } while (0)

# define CONFIG_RA5_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA5_ANALOG();           \
      CONFIG_RA5_AS_INPUT();          \
      DISABLE_RA5_OPENDRAIN();        \
      DISABLE_RA5_PULLUP();           \
      DISABLE_RA5_PULLDOWN();         \
    } while (0)

# define CONFIG_RA5_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA5_ANALOG();           \
      CONFIG_RA5_AS_OUTPUT();         \
      DISABLE_RA5_OPENDRAIN();        \
      DISABLE_RA5_PULLUP();           \
      DISABLE_RA5_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA5: Provide GPIO for RA5


// Provide GPIO for RA6
// ====================
#ifdef _RA6
# ifndef RA6_GPIO
#   warning "RA6_GPIO not defined, but pin RA6 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA6_GPIO)
# define RA6_REMAPPABLE RXY_REMAPPABLE_PIN(RA6_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA6_GPIO)
#   define ENABLE_RA6_ANALOG()  (RXY_GPIO_PCFG(RA6_GPIO) = 1)
#   define DISABLE_RA6_ANALOG() (RXY_GPIO_PCFG(RA6_GPIO) = 0)
#   define RA6_AN_PORT RXY_AN_PORT(RA6_GPIO)
# else
#   define DISABLE_RA6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA6_AS_INPUT()  (_TRISA6 = 1)
# define CONFIG_RA6_AS_OUTPUT() (_TRISA6 = 0)

// Open-drain:
#if defined(_ODCA6)
# define ENABLE_RA6_OPENDRAIN()  (_ODCA6 = 1)
# define DISABLE_RA6_OPENDRAIN() (_ODCA6 = 0)
#elif defined(_ODA6)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA6_OPENDRAIN()  (_ODA6 = 1)
# define DISABLE_RA6_OPENDRAIN() (_ODA6 = 0)
#else
# define DISABLE_RA6_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA6_GPIO)
#   define ENABLE_RA6_PULLUP()  (RXY_GPIO_CNPUE(RA6_GPIO) = 1)
#   define DISABLE_RA6_PULLUP() (RXY_GPIO_CNPUE(RA6_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA6_GPIO)
#     define ENABLE_RA6_PULLDOWN()  (RXY_GPIO_CNPDE(RA6_GPIO) = 1)
#     define DISABLE_RA6_PULLDOWN() (RXY_GPIO_CNPDE(RA6_GPIO) = 0)
#   else
#     define DISABLE_RA6_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA6_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA6_GPIO) = 1)
#   define DISABLE_RA6_CN_INTERRUPT() (RXY_GPIO_CNIE(RA6_GPIO) = 0)

# else
#   define DISABLE_RA6_PULLUP() ((void) 0)
#   define DISABLE_RA6_PULLDOWN() ((void) 0)
#   define DISABLE_RA6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA6_AS_ANALOG()       \
    do {                              \
      ENABLE_RA6_ANALOG();            \
      CONFIG_RA6_AS_INPUT();          \
      DISABLE_RA6_OPENDRAIN();        \
      DISABLE_RA6_PULLUP();           \
      DISABLE_RA6_PULLDOWN();         \
    } while (0)

# define CONFIG_RA6_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA6_ANALOG();           \
      CONFIG_RA6_AS_INPUT();          \
      DISABLE_RA6_OPENDRAIN();        \
      DISABLE_RA6_PULLUP();           \
      DISABLE_RA6_PULLDOWN();         \
    } while (0)

# define CONFIG_RA6_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA6_ANALOG();           \
      CONFIG_RA6_AS_OUTPUT();         \
      DISABLE_RA6_OPENDRAIN();        \
      DISABLE_RA6_PULLUP();           \
      DISABLE_RA6_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA6: Provide GPIO for RA6


// Provide GPIO for RA7
// ====================
#ifdef _RA7
# ifndef RA7_GPIO
#   warning "RA7_GPIO not defined, but pin RA7 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA7_GPIO)
# define RA7_REMAPPABLE RXY_REMAPPABLE_PIN(RA7_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA7_GPIO)
#   define ENABLE_RA7_ANALOG()  (RXY_GPIO_PCFG(RA7_GPIO) = 1)
#   define DISABLE_RA7_ANALOG() (RXY_GPIO_PCFG(RA7_GPIO) = 0)
#   define RA7_AN_PORT RXY_AN_PORT(RA7_GPIO)
# else
#   define DISABLE_RA7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA7_AS_INPUT()  (_TRISA7 = 1)
# define CONFIG_RA7_AS_OUTPUT() (_TRISA7 = 0)

// Open-drain:
#if defined(_ODCA7)
# define ENABLE_RA7_OPENDRAIN()  (_ODCA7 = 1)
# define DISABLE_RA7_OPENDRAIN() (_ODCA7 = 0)
#elif defined(_ODA7)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA7_OPENDRAIN()  (_ODA7 = 1)
# define DISABLE_RA7_OPENDRAIN() (_ODA7 = 0)
#else
# define DISABLE_RA7_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA7_GPIO)
#   define ENABLE_RA7_PULLUP()  (RXY_GPIO_CNPUE(RA7_GPIO) = 1)
#   define DISABLE_RA7_PULLUP() (RXY_GPIO_CNPUE(RA7_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA7_GPIO)
#     define ENABLE_RA7_PULLDOWN()  (RXY_GPIO_CNPDE(RA7_GPIO) = 1)
#     define DISABLE_RA7_PULLDOWN() (RXY_GPIO_CNPDE(RA7_GPIO) = 0)
#   else
#     define DISABLE_RA7_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA7_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA7_GPIO) = 1)
#   define DISABLE_RA7_CN_INTERRUPT() (RXY_GPIO_CNIE(RA7_GPIO) = 0)

# else
#   define DISABLE_RA7_PULLUP() ((void) 0)
#   define DISABLE_RA7_PULLDOWN() ((void) 0)
#   define DISABLE_RA7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA7_AS_ANALOG()       \
    do {                              \
      ENABLE_RA7_ANALOG();            \
      CONFIG_RA7_AS_INPUT();          \
      DISABLE_RA7_OPENDRAIN();        \
      DISABLE_RA7_PULLUP();           \
      DISABLE_RA7_PULLDOWN();         \
    } while (0)

# define CONFIG_RA7_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA7_ANALOG();           \
      CONFIG_RA7_AS_INPUT();          \
      DISABLE_RA7_OPENDRAIN();        \
      DISABLE_RA7_PULLUP();           \
      DISABLE_RA7_PULLDOWN();         \
    } while (0)

# define CONFIG_RA7_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA7_ANALOG();           \
      CONFIG_RA7_AS_OUTPUT();         \
      DISABLE_RA7_OPENDRAIN();        \
      DISABLE_RA7_PULLUP();           \
      DISABLE_RA7_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA7: Provide GPIO for RA7


// Provide GPIO for RA8
// ====================
#ifdef _RA8
# ifndef RA8_GPIO
#   warning "RA8_GPIO not defined, but pin RA8 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA8_GPIO)
# define RA8_REMAPPABLE RXY_REMAPPABLE_PIN(RA8_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA8_GPIO)
#   define ENABLE_RA8_ANALOG()  (RXY_GPIO_PCFG(RA8_GPIO) = 1)
#   define DISABLE_RA8_ANALOG() (RXY_GPIO_PCFG(RA8_GPIO) = 0)
#   define RA8_AN_PORT RXY_AN_PORT(RA8_GPIO)
# else
#   define DISABLE_RA8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA8_AS_INPUT()  (_TRISA8 = 1)
# define CONFIG_RA8_AS_OUTPUT() (_TRISA8 = 0)

// Open-drain:
#if defined(_ODCA8)
# define ENABLE_RA8_OPENDRAIN()  (_ODCA8 = 1)
# define DISABLE_RA8_OPENDRAIN() (_ODCA8 = 0)
#elif defined(_ODA8)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA8_OPENDRAIN()  (_ODA8 = 1)
# define DISABLE_RA8_OPENDRAIN() (_ODA8 = 0)
#else
# define DISABLE_RA8_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA8_GPIO)
#   define ENABLE_RA8_PULLUP()  (RXY_GPIO_CNPUE(RA8_GPIO) = 1)
#   define DISABLE_RA8_PULLUP() (RXY_GPIO_CNPUE(RA8_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA8_GPIO)
#     define ENABLE_RA8_PULLDOWN()  (RXY_GPIO_CNPDE(RA8_GPIO) = 1)
#     define DISABLE_RA8_PULLDOWN() (RXY_GPIO_CNPDE(RA8_GPIO) = 0)
#   else
#     define DISABLE_RA8_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA8_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA8_GPIO) = 1)
#   define DISABLE_RA8_CN_INTERRUPT() (RXY_GPIO_CNIE(RA8_GPIO) = 0)

# else
#   define DISABLE_RA8_PULLUP() ((void) 0)
#   define DISABLE_RA8_PULLDOWN() ((void) 0)
#   define DISABLE_RA8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA8_AS_ANALOG()       \
    do {                              \
      ENABLE_RA8_ANALOG();            \
      CONFIG_RA8_AS_INPUT();          \
      DISABLE_RA8_OPENDRAIN();        \
      DISABLE_RA8_PULLUP();           \
      DISABLE_RA8_PULLDOWN();         \
    } while (0)

# define CONFIG_RA8_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA8_ANALOG();           \
      CONFIG_RA8_AS_INPUT();          \
      DISABLE_RA8_OPENDRAIN();        \
      DISABLE_RA8_PULLUP();           \
      DISABLE_RA8_PULLDOWN();         \
    } while (0)

# define CONFIG_RA8_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA8_ANALOG();           \
      CONFIG_RA8_AS_OUTPUT();         \
      DISABLE_RA8_OPENDRAIN();        \
      DISABLE_RA8_PULLUP();           \
      DISABLE_RA8_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA8: Provide GPIO for RA8


// Provide GPIO for RA9
// ====================
#ifdef _RA9
# ifndef RA9_GPIO
#   warning "RA9_GPIO not defined, but pin RA9 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA9_GPIO)
# define RA9_REMAPPABLE RXY_REMAPPABLE_PIN(RA9_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA9_GPIO)
#   define ENABLE_RA9_ANALOG()  (RXY_GPIO_PCFG(RA9_GPIO) = 1)
#   define DISABLE_RA9_ANALOG() (RXY_GPIO_PCFG(RA9_GPIO) = 0)
#   define RA9_AN_PORT RXY_AN_PORT(RA9_GPIO)
# else
#   define DISABLE_RA9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA9_AS_INPUT()  (_TRISA9 = 1)
# define CONFIG_RA9_AS_OUTPUT() (_TRISA9 = 0)

// Open-drain:
#if defined(_ODCA9)
# define ENABLE_RA9_OPENDRAIN()  (_ODCA9 = 1)
# define DISABLE_RA9_OPENDRAIN() (_ODCA9 = 0)
#elif defined(_ODA9)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA9_OPENDRAIN()  (_ODA9 = 1)
# define DISABLE_RA9_OPENDRAIN() (_ODA9 = 0)
#else
# define DISABLE_RA9_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA9_GPIO)
#   define ENABLE_RA9_PULLUP()  (RXY_GPIO_CNPUE(RA9_GPIO) = 1)
#   define DISABLE_RA9_PULLUP() (RXY_GPIO_CNPUE(RA9_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA9_GPIO)
#     define ENABLE_RA9_PULLDOWN()  (RXY_GPIO_CNPDE(RA9_GPIO) = 1)
#     define DISABLE_RA9_PULLDOWN() (RXY_GPIO_CNPDE(RA9_GPIO) = 0)
#   else
#     define DISABLE_RA9_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA9_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA9_GPIO) = 1)
#   define DISABLE_RA9_CN_INTERRUPT() (RXY_GPIO_CNIE(RA9_GPIO) = 0)

# else
#   define DISABLE_RA9_PULLUP() ((void) 0)
#   define DISABLE_RA9_PULLDOWN() ((void) 0)
#   define DISABLE_RA9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA9_AS_ANALOG()       \
    do {                              \
      ENABLE_RA9_ANALOG();            \
      CONFIG_RA9_AS_INPUT();          \
      DISABLE_RA9_OPENDRAIN();        \
      DISABLE_RA9_PULLUP();           \
      DISABLE_RA9_PULLDOWN();         \
    } while (0)

# define CONFIG_RA9_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA9_ANALOG();           \
      CONFIG_RA9_AS_INPUT();          \
      DISABLE_RA9_OPENDRAIN();        \
      DISABLE_RA9_PULLUP();           \
      DISABLE_RA9_PULLDOWN();         \
    } while (0)

# define CONFIG_RA9_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA9_ANALOG();           \
      CONFIG_RA9_AS_OUTPUT();         \
      DISABLE_RA9_OPENDRAIN();        \
      DISABLE_RA9_PULLUP();           \
      DISABLE_RA9_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA9: Provide GPIO for RA9


// Provide GPIO for RA10
// ====================
#ifdef _RA10
# ifndef RA10_GPIO
#   warning "RA10_GPIO not defined, but pin RA10 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA10_GPIO)
# define RA10_REMAPPABLE RXY_REMAPPABLE_PIN(RA10_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA10_GPIO)
#   define ENABLE_RA10_ANALOG()  (RXY_GPIO_PCFG(RA10_GPIO) = 1)
#   define DISABLE_RA10_ANALOG() (RXY_GPIO_PCFG(RA10_GPIO) = 0)
#   define RA10_AN_PORT RXY_AN_PORT(RA10_GPIO)
# else
#   define DISABLE_RA10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA10_AS_INPUT()  (_TRISA10 = 1)
# define CONFIG_RA10_AS_OUTPUT() (_TRISA10 = 0)

// Open-drain:
#if defined(_ODCA10)
# define ENABLE_RA10_OPENDRAIN()  (_ODCA10 = 1)
# define DISABLE_RA10_OPENDRAIN() (_ODCA10 = 0)
#elif defined(_ODA10)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA10_OPENDRAIN()  (_ODA10 = 1)
# define DISABLE_RA10_OPENDRAIN() (_ODA10 = 0)
#else
# define DISABLE_RA10_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA10_GPIO)
#   define ENABLE_RA10_PULLUP()  (RXY_GPIO_CNPUE(RA10_GPIO) = 1)
#   define DISABLE_RA10_PULLUP() (RXY_GPIO_CNPUE(RA10_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA10_GPIO)
#     define ENABLE_RA10_PULLDOWN()  (RXY_GPIO_CNPDE(RA10_GPIO) = 1)
#     define DISABLE_RA10_PULLDOWN() (RXY_GPIO_CNPDE(RA10_GPIO) = 0)
#   else
#     define DISABLE_RA10_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA10_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA10_GPIO) = 1)
#   define DISABLE_RA10_CN_INTERRUPT() (RXY_GPIO_CNIE(RA10_GPIO) = 0)

# else
#   define DISABLE_RA10_PULLUP() ((void) 0)
#   define DISABLE_RA10_PULLDOWN() ((void) 0)
#   define DISABLE_RA10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA10_AS_ANALOG()       \
    do {                              \
      ENABLE_RA10_ANALOG();            \
      CONFIG_RA10_AS_INPUT();          \
      DISABLE_RA10_OPENDRAIN();        \
      DISABLE_RA10_PULLUP();           \
      DISABLE_RA10_PULLDOWN();         \
    } while (0)

# define CONFIG_RA10_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA10_ANALOG();           \
      CONFIG_RA10_AS_INPUT();          \
      DISABLE_RA10_OPENDRAIN();        \
      DISABLE_RA10_PULLUP();           \
      DISABLE_RA10_PULLDOWN();         \
    } while (0)

# define CONFIG_RA10_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA10_ANALOG();           \
      CONFIG_RA10_AS_OUTPUT();         \
      DISABLE_RA10_OPENDRAIN();        \
      DISABLE_RA10_PULLUP();           \
      DISABLE_RA10_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA10: Provide GPIO for RA10


// Provide GPIO for RA11
// ====================
#ifdef _RA11
# ifndef RA11_GPIO
#   warning "RA11_GPIO not defined, but pin RA11 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA11_GPIO)
# define RA11_REMAPPABLE RXY_REMAPPABLE_PIN(RA11_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA11_GPIO)
#   define ENABLE_RA11_ANALOG()  (RXY_GPIO_PCFG(RA11_GPIO) = 1)
#   define DISABLE_RA11_ANALOG() (RXY_GPIO_PCFG(RA11_GPIO) = 0)
#   define RA11_AN_PORT RXY_AN_PORT(RA11_GPIO)
# else
#   define DISABLE_RA11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA11_AS_INPUT()  (_TRISA11 = 1)
# define CONFIG_RA11_AS_OUTPUT() (_TRISA11 = 0)

// Open-drain:
#if defined(_ODCA11)
# define ENABLE_RA11_OPENDRAIN()  (_ODCA11 = 1)
# define DISABLE_RA11_OPENDRAIN() (_ODCA11 = 0)
#elif defined(_ODA11)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA11_OPENDRAIN()  (_ODA11 = 1)
# define DISABLE_RA11_OPENDRAIN() (_ODA11 = 0)
#else
# define DISABLE_RA11_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA11_GPIO)
#   define ENABLE_RA11_PULLUP()  (RXY_GPIO_CNPUE(RA11_GPIO) = 1)
#   define DISABLE_RA11_PULLUP() (RXY_GPIO_CNPUE(RA11_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA11_GPIO)
#     define ENABLE_RA11_PULLDOWN()  (RXY_GPIO_CNPDE(RA11_GPIO) = 1)
#     define DISABLE_RA11_PULLDOWN() (RXY_GPIO_CNPDE(RA11_GPIO) = 0)
#   else
#     define DISABLE_RA11_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA11_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA11_GPIO) = 1)
#   define DISABLE_RA11_CN_INTERRUPT() (RXY_GPIO_CNIE(RA11_GPIO) = 0)

# else
#   define DISABLE_RA11_PULLUP() ((void) 0)
#   define DISABLE_RA11_PULLDOWN() ((void) 0)
#   define DISABLE_RA11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA11_AS_ANALOG()       \
    do {                              \
      ENABLE_RA11_ANALOG();            \
      CONFIG_RA11_AS_INPUT();          \
      DISABLE_RA11_OPENDRAIN();        \
      DISABLE_RA11_PULLUP();           \
      DISABLE_RA11_PULLDOWN();         \
    } while (0)

# define CONFIG_RA11_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA11_ANALOG();           \
      CONFIG_RA11_AS_INPUT();          \
      DISABLE_RA11_OPENDRAIN();        \
      DISABLE_RA11_PULLUP();           \
      DISABLE_RA11_PULLDOWN();         \
    } while (0)

# define CONFIG_RA11_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA11_ANALOG();           \
      CONFIG_RA11_AS_OUTPUT();         \
      DISABLE_RA11_OPENDRAIN();        \
      DISABLE_RA11_PULLUP();           \
      DISABLE_RA11_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA11: Provide GPIO for RA11


// Provide GPIO for RA12
// ====================
#ifdef _RA12
# ifndef RA12_GPIO
#   warning "RA12_GPIO not defined, but pin RA12 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA12_GPIO)
# define RA12_REMAPPABLE RXY_REMAPPABLE_PIN(RA12_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA12_GPIO)
#   define ENABLE_RA12_ANALOG()  (RXY_GPIO_PCFG(RA12_GPIO) = 1)
#   define DISABLE_RA12_ANALOG() (RXY_GPIO_PCFG(RA12_GPIO) = 0)
#   define RA12_AN_PORT RXY_AN_PORT(RA12_GPIO)
# else
#   define DISABLE_RA12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA12_AS_INPUT()  (_TRISA12 = 1)
# define CONFIG_RA12_AS_OUTPUT() (_TRISA12 = 0)

// Open-drain:
#if defined(_ODCA12)
# define ENABLE_RA12_OPENDRAIN()  (_ODCA12 = 1)
# define DISABLE_RA12_OPENDRAIN() (_ODCA12 = 0)
#elif defined(_ODA12)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA12_OPENDRAIN()  (_ODA12 = 1)
# define DISABLE_RA12_OPENDRAIN() (_ODA12 = 0)
#else
# define DISABLE_RA12_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA12_GPIO)
#   define ENABLE_RA12_PULLUP()  (RXY_GPIO_CNPUE(RA12_GPIO) = 1)
#   define DISABLE_RA12_PULLUP() (RXY_GPIO_CNPUE(RA12_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA12_GPIO)
#     define ENABLE_RA12_PULLDOWN()  (RXY_GPIO_CNPDE(RA12_GPIO) = 1)
#     define DISABLE_RA12_PULLDOWN() (RXY_GPIO_CNPDE(RA12_GPIO) = 0)
#   else
#     define DISABLE_RA12_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA12_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA12_GPIO) = 1)
#   define DISABLE_RA12_CN_INTERRUPT() (RXY_GPIO_CNIE(RA12_GPIO) = 0)

# else
#   define DISABLE_RA12_PULLUP() ((void) 0)
#   define DISABLE_RA12_PULLDOWN() ((void) 0)
#   define DISABLE_RA12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA12_AS_ANALOG()       \
    do {                              \
      ENABLE_RA12_ANALOG();            \
      CONFIG_RA12_AS_INPUT();          \
      DISABLE_RA12_OPENDRAIN();        \
      DISABLE_RA12_PULLUP();           \
      DISABLE_RA12_PULLDOWN();         \
    } while (0)

# define CONFIG_RA12_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA12_ANALOG();           \
      CONFIG_RA12_AS_INPUT();          \
      DISABLE_RA12_OPENDRAIN();        \
      DISABLE_RA12_PULLUP();           \
      DISABLE_RA12_PULLDOWN();         \
    } while (0)

# define CONFIG_RA12_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA12_ANALOG();           \
      CONFIG_RA12_AS_OUTPUT();         \
      DISABLE_RA12_OPENDRAIN();        \
      DISABLE_RA12_PULLUP();           \
      DISABLE_RA12_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA12: Provide GPIO for RA12


// Provide GPIO for RA13
// ====================
#ifdef _RA13
# ifndef RA13_GPIO
#   warning "RA13_GPIO not defined, but pin RA13 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA13_GPIO)
# define RA13_REMAPPABLE RXY_REMAPPABLE_PIN(RA13_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA13_GPIO)
#   define ENABLE_RA13_ANALOG()  (RXY_GPIO_PCFG(RA13_GPIO) = 1)
#   define DISABLE_RA13_ANALOG() (RXY_GPIO_PCFG(RA13_GPIO) = 0)
#   define RA13_AN_PORT RXY_AN_PORT(RA13_GPIO)
# else
#   define DISABLE_RA13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA13_AS_INPUT()  (_TRISA13 = 1)
# define CONFIG_RA13_AS_OUTPUT() (_TRISA13 = 0)

// Open-drain:
#if defined(_ODCA13)
# define ENABLE_RA13_OPENDRAIN()  (_ODCA13 = 1)
# define DISABLE_RA13_OPENDRAIN() (_ODCA13 = 0)
#elif defined(_ODA13)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA13_OPENDRAIN()  (_ODA13 = 1)
# define DISABLE_RA13_OPENDRAIN() (_ODA13 = 0)
#else
# define DISABLE_RA13_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA13_GPIO)
#   define ENABLE_RA13_PULLUP()  (RXY_GPIO_CNPUE(RA13_GPIO) = 1)
#   define DISABLE_RA13_PULLUP() (RXY_GPIO_CNPUE(RA13_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA13_GPIO)
#     define ENABLE_RA13_PULLDOWN()  (RXY_GPIO_CNPDE(RA13_GPIO) = 1)
#     define DISABLE_RA13_PULLDOWN() (RXY_GPIO_CNPDE(RA13_GPIO) = 0)
#   else
#     define DISABLE_RA13_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA13_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA13_GPIO) = 1)
#   define DISABLE_RA13_CN_INTERRUPT() (RXY_GPIO_CNIE(RA13_GPIO) = 0)

# else
#   define DISABLE_RA13_PULLUP() ((void) 0)
#   define DISABLE_RA13_PULLDOWN() ((void) 0)
#   define DISABLE_RA13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA13_AS_ANALOG()       \
    do {                              \
      ENABLE_RA13_ANALOG();            \
      CONFIG_RA13_AS_INPUT();          \
      DISABLE_RA13_OPENDRAIN();        \
      DISABLE_RA13_PULLUP();           \
      DISABLE_RA13_PULLDOWN();         \
    } while (0)

# define CONFIG_RA13_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA13_ANALOG();           \
      CONFIG_RA13_AS_INPUT();          \
      DISABLE_RA13_OPENDRAIN();        \
      DISABLE_RA13_PULLUP();           \
      DISABLE_RA13_PULLDOWN();         \
    } while (0)

# define CONFIG_RA13_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA13_ANALOG();           \
      CONFIG_RA13_AS_OUTPUT();         \
      DISABLE_RA13_OPENDRAIN();        \
      DISABLE_RA13_PULLUP();           \
      DISABLE_RA13_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA13: Provide GPIO for RA13


// Provide GPIO for RA14
// ====================
#ifdef _RA14
# ifndef RA14_GPIO
#   warning "RA14_GPIO not defined, but pin RA14 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA14_GPIO)
# define RA14_REMAPPABLE RXY_REMAPPABLE_PIN(RA14_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA14_GPIO)
#   define ENABLE_RA14_ANALOG()  (RXY_GPIO_PCFG(RA14_GPIO) = 1)
#   define DISABLE_RA14_ANALOG() (RXY_GPIO_PCFG(RA14_GPIO) = 0)
#   define RA14_AN_PORT RXY_AN_PORT(RA14_GPIO)
# else
#   define DISABLE_RA14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA14_AS_INPUT()  (_TRISA14 = 1)
# define CONFIG_RA14_AS_OUTPUT() (_TRISA14 = 0)

// Open-drain:
#if defined(_ODCA14)
# define ENABLE_RA14_OPENDRAIN()  (_ODCA14 = 1)
# define DISABLE_RA14_OPENDRAIN() (_ODCA14 = 0)
#elif defined(_ODA14)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA14_OPENDRAIN()  (_ODA14 = 1)
# define DISABLE_RA14_OPENDRAIN() (_ODA14 = 0)
#else
# define DISABLE_RA14_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA14_GPIO)
#   define ENABLE_RA14_PULLUP()  (RXY_GPIO_CNPUE(RA14_GPIO) = 1)
#   define DISABLE_RA14_PULLUP() (RXY_GPIO_CNPUE(RA14_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA14_GPIO)
#     define ENABLE_RA14_PULLDOWN()  (RXY_GPIO_CNPDE(RA14_GPIO) = 1)
#     define DISABLE_RA14_PULLDOWN() (RXY_GPIO_CNPDE(RA14_GPIO) = 0)
#   else
#     define DISABLE_RA14_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA14_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA14_GPIO) = 1)
#   define DISABLE_RA14_CN_INTERRUPT() (RXY_GPIO_CNIE(RA14_GPIO) = 0)

# else
#   define DISABLE_RA14_PULLUP() ((void) 0)
#   define DISABLE_RA14_PULLDOWN() ((void) 0)
#   define DISABLE_RA14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA14_AS_ANALOG()       \
    do {                              \
      ENABLE_RA14_ANALOG();            \
      CONFIG_RA14_AS_INPUT();          \
      DISABLE_RA14_OPENDRAIN();        \
      DISABLE_RA14_PULLUP();           \
      DISABLE_RA14_PULLDOWN();         \
    } while (0)

# define CONFIG_RA14_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA14_ANALOG();           \
      CONFIG_RA14_AS_INPUT();          \
      DISABLE_RA14_OPENDRAIN();        \
      DISABLE_RA14_PULLUP();           \
      DISABLE_RA14_PULLDOWN();         \
    } while (0)

# define CONFIG_RA14_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA14_ANALOG();           \
      CONFIG_RA14_AS_OUTPUT();         \
      DISABLE_RA14_OPENDRAIN();        \
      DISABLE_RA14_PULLUP();           \
      DISABLE_RA14_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA14: Provide GPIO for RA14


// Provide GPIO for RA15
// ====================
#ifdef _RA15
# ifndef RA15_GPIO
#   warning "RA15_GPIO not defined, but pin RA15 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RA15_GPIO)
# define RA15_REMAPPABLE RXY_REMAPPABLE_PIN(RA15_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RA15_GPIO)
#   define ENABLE_RA15_ANALOG()  (RXY_GPIO_PCFG(RA15_GPIO) = 1)
#   define DISABLE_RA15_ANALOG() (RXY_GPIO_PCFG(RA15_GPIO) = 0)
#   define RA15_AN_PORT RXY_AN_PORT(RA15_GPIO)
# else
#   define DISABLE_RA15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA15_AS_INPUT()  (_TRISA15 = 1)
# define CONFIG_RA15_AS_OUTPUT() (_TRISA15 = 0)

// Open-drain:
#if defined(_ODCA15)
# define ENABLE_RA15_OPENDRAIN()  (_ODCA15 = 1)
# define DISABLE_RA15_OPENDRAIN() (_ODCA15 = 0)
#elif defined(_ODA15)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RA15_OPENDRAIN()  (_ODA15 = 1)
# define DISABLE_RA15_OPENDRAIN() (_ODA15 = 0)
#else
# define DISABLE_RA15_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RA15_GPIO)
#   define ENABLE_RA15_PULLUP()  (RXY_GPIO_CNPUE(RA15_GPIO) = 1)
#   define DISABLE_RA15_PULLUP() (RXY_GPIO_CNPUE(RA15_GPIO) = 0)

#   if RXY_HAS_CNPDE(RA15_GPIO)
#     define ENABLE_RA15_PULLDOWN()  (RXY_GPIO_CNPDE(RA15_GPIO) = 1)
#     define DISABLE_RA15_PULLDOWN() (RXY_GPIO_CNPDE(RA15_GPIO) = 0)
#   else
#     define DISABLE_RA15_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RA15_CN_INTERRUPT()  (RXY_GPIO_CNIE(RA15_GPIO) = 1)
#   define DISABLE_RA15_CN_INTERRUPT() (RXY_GPIO_CNIE(RA15_GPIO) = 0)

# else
#   define DISABLE_RA15_PULLUP() ((void) 0)
#   define DISABLE_RA15_PULLDOWN() ((void) 0)
#   define DISABLE_RA15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RA15_AS_ANALOG()       \
    do {                              \
      ENABLE_RA15_ANALOG();            \
      CONFIG_RA15_AS_INPUT();          \
      DISABLE_RA15_OPENDRAIN();        \
      DISABLE_RA15_PULLUP();           \
      DISABLE_RA15_PULLDOWN();         \
    } while (0)

# define CONFIG_RA15_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RA15_ANALOG();           \
      CONFIG_RA15_AS_INPUT();          \
      DISABLE_RA15_OPENDRAIN();        \
      DISABLE_RA15_PULLUP();           \
      DISABLE_RA15_PULLDOWN();         \
    } while (0)

# define CONFIG_RA15_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RA15_ANALOG();           \
      CONFIG_RA15_AS_OUTPUT();         \
      DISABLE_RA15_OPENDRAIN();        \
      DISABLE_RA15_PULLUP();           \
      DISABLE_RA15_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RA15: Provide GPIO for RA15


// Provide GPIO for RB0
// ====================
#ifdef _RB0
# ifndef RB0_GPIO
#   warning "RB0_GPIO not defined, but pin RB0 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB0_GPIO)
# define RB0_REMAPPABLE RXY_REMAPPABLE_PIN(RB0_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB0_GPIO)
#   define ENABLE_RB0_ANALOG()  (RXY_GPIO_PCFG(RB0_GPIO) = 1)
#   define DISABLE_RB0_ANALOG() (RXY_GPIO_PCFG(RB0_GPIO) = 0)
#   define RB0_AN_PORT RXY_AN_PORT(RB0_GPIO)
# else
#   define DISABLE_RB0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB0_AS_INPUT()  (_TRISB0 = 1)
# define CONFIG_RB0_AS_OUTPUT() (_TRISB0 = 0)

// Open-drain:
#if defined(_ODCB0)
# define ENABLE_RB0_OPENDRAIN()  (_ODCB0 = 1)
# define DISABLE_RB0_OPENDRAIN() (_ODCB0 = 0)
#elif defined(_ODB0)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB0_OPENDRAIN()  (_ODB0 = 1)
# define DISABLE_RB0_OPENDRAIN() (_ODB0 = 0)
#else
# define DISABLE_RB0_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB0_GPIO)
#   define ENABLE_RB0_PULLUP()  (RXY_GPIO_CNPUE(RB0_GPIO) = 1)
#   define DISABLE_RB0_PULLUP() (RXY_GPIO_CNPUE(RB0_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB0_GPIO)
#     define ENABLE_RB0_PULLDOWN()  (RXY_GPIO_CNPDE(RB0_GPIO) = 1)
#     define DISABLE_RB0_PULLDOWN() (RXY_GPIO_CNPDE(RB0_GPIO) = 0)
#   else
#     define DISABLE_RB0_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB0_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB0_GPIO) = 1)
#   define DISABLE_RB0_CN_INTERRUPT() (RXY_GPIO_CNIE(RB0_GPIO) = 0)

# else
#   define DISABLE_RB0_PULLUP() ((void) 0)
#   define DISABLE_RB0_PULLDOWN() ((void) 0)
#   define DISABLE_RB0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB0_AS_ANALOG()       \
    do {                              \
      ENABLE_RB0_ANALOG();            \
      CONFIG_RB0_AS_INPUT();          \
      DISABLE_RB0_OPENDRAIN();        \
      DISABLE_RB0_PULLUP();           \
      DISABLE_RB0_PULLDOWN();         \
    } while (0)

# define CONFIG_RB0_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB0_ANALOG();           \
      CONFIG_RB0_AS_INPUT();          \
      DISABLE_RB0_OPENDRAIN();        \
      DISABLE_RB0_PULLUP();           \
      DISABLE_RB0_PULLDOWN();         \
    } while (0)

# define CONFIG_RB0_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB0_ANALOG();           \
      CONFIG_RB0_AS_OUTPUT();         \
      DISABLE_RB0_OPENDRAIN();        \
      DISABLE_RB0_PULLUP();           \
      DISABLE_RB0_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB0: Provide GPIO for RB0


// Provide GPIO for RB1
// ====================
#ifdef _RB1
# ifndef RB1_GPIO
#   warning "RB1_GPIO not defined, but pin RB1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB1_GPIO)
# define RB1_REMAPPABLE RXY_REMAPPABLE_PIN(RB1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB1_GPIO)
#   define ENABLE_RB1_ANALOG()  (RXY_GPIO_PCFG(RB1_GPIO) = 1)
#   define DISABLE_RB1_ANALOG() (RXY_GPIO_PCFG(RB1_GPIO) = 0)
#   define RB1_AN_PORT RXY_AN_PORT(RB1_GPIO)
# else
#   define DISABLE_RB1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB1_AS_INPUT()  (_TRISB1 = 1)
# define CONFIG_RB1_AS_OUTPUT() (_TRISB1 = 0)

// Open-drain:
#if defined(_ODCB1)
# define ENABLE_RB1_OPENDRAIN()  (_ODCB1 = 1)
# define DISABLE_RB1_OPENDRAIN() (_ODCB1 = 0)
#elif defined(_ODB1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB1_OPENDRAIN()  (_ODB1 = 1)
# define DISABLE_RB1_OPENDRAIN() (_ODB1 = 0)
#else
# define DISABLE_RB1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB1_GPIO)
#   define ENABLE_RB1_PULLUP()  (RXY_GPIO_CNPUE(RB1_GPIO) = 1)
#   define DISABLE_RB1_PULLUP() (RXY_GPIO_CNPUE(RB1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB1_GPIO)
#     define ENABLE_RB1_PULLDOWN()  (RXY_GPIO_CNPDE(RB1_GPIO) = 1)
#     define DISABLE_RB1_PULLDOWN() (RXY_GPIO_CNPDE(RB1_GPIO) = 0)
#   else
#     define DISABLE_RB1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB1_GPIO) = 1)
#   define DISABLE_RB1_CN_INTERRUPT() (RXY_GPIO_CNIE(RB1_GPIO) = 0)

# else
#   define DISABLE_RB1_PULLUP() ((void) 0)
#   define DISABLE_RB1_PULLDOWN() ((void) 0)
#   define DISABLE_RB1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB1_AS_ANALOG()       \
    do {                              \
      ENABLE_RB1_ANALOG();            \
      CONFIG_RB1_AS_INPUT();          \
      DISABLE_RB1_OPENDRAIN();        \
      DISABLE_RB1_PULLUP();           \
      DISABLE_RB1_PULLDOWN();         \
    } while (0)

# define CONFIG_RB1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB1_ANALOG();           \
      CONFIG_RB1_AS_INPUT();          \
      DISABLE_RB1_OPENDRAIN();        \
      DISABLE_RB1_PULLUP();           \
      DISABLE_RB1_PULLDOWN();         \
    } while (0)

# define CONFIG_RB1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB1_ANALOG();           \
      CONFIG_RB1_AS_OUTPUT();         \
      DISABLE_RB1_OPENDRAIN();        \
      DISABLE_RB1_PULLUP();           \
      DISABLE_RB1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB1: Provide GPIO for RB1


// Provide GPIO for RB2
// ====================
#ifdef _RB2
# ifndef RB2_GPIO
#   warning "RB2_GPIO not defined, but pin RB2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB2_GPIO)
# define RB2_REMAPPABLE RXY_REMAPPABLE_PIN(RB2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB2_GPIO)
#   define ENABLE_RB2_ANALOG()  (RXY_GPIO_PCFG(RB2_GPIO) = 1)
#   define DISABLE_RB2_ANALOG() (RXY_GPIO_PCFG(RB2_GPIO) = 0)
#   define RB2_AN_PORT RXY_AN_PORT(RB2_GPIO)
# else
#   define DISABLE_RB2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB2_AS_INPUT()  (_TRISB2 = 1)
# define CONFIG_RB2_AS_OUTPUT() (_TRISB2 = 0)

// Open-drain:
#if defined(_ODCB2)
# define ENABLE_RB2_OPENDRAIN()  (_ODCB2 = 1)
# define DISABLE_RB2_OPENDRAIN() (_ODCB2 = 0)
#elif defined(_ODB2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB2_OPENDRAIN()  (_ODB2 = 1)
# define DISABLE_RB2_OPENDRAIN() (_ODB2 = 0)
#else
# define DISABLE_RB2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB2_GPIO)
#   define ENABLE_RB2_PULLUP()  (RXY_GPIO_CNPUE(RB2_GPIO) = 1)
#   define DISABLE_RB2_PULLUP() (RXY_GPIO_CNPUE(RB2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB2_GPIO)
#     define ENABLE_RB2_PULLDOWN()  (RXY_GPIO_CNPDE(RB2_GPIO) = 1)
#     define DISABLE_RB2_PULLDOWN() (RXY_GPIO_CNPDE(RB2_GPIO) = 0)
#   else
#     define DISABLE_RB2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB2_GPIO) = 1)
#   define DISABLE_RB2_CN_INTERRUPT() (RXY_GPIO_CNIE(RB2_GPIO) = 0)

# else
#   define DISABLE_RB2_PULLUP() ((void) 0)
#   define DISABLE_RB2_PULLDOWN() ((void) 0)
#   define DISABLE_RB2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB2_AS_ANALOG()       \
    do {                              \
      ENABLE_RB2_ANALOG();            \
      CONFIG_RB2_AS_INPUT();          \
      DISABLE_RB2_OPENDRAIN();        \
      DISABLE_RB2_PULLUP();           \
      DISABLE_RB2_PULLDOWN();         \
    } while (0)

# define CONFIG_RB2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB2_ANALOG();           \
      CONFIG_RB2_AS_INPUT();          \
      DISABLE_RB2_OPENDRAIN();        \
      DISABLE_RB2_PULLUP();           \
      DISABLE_RB2_PULLDOWN();         \
    } while (0)

# define CONFIG_RB2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB2_ANALOG();           \
      CONFIG_RB2_AS_OUTPUT();         \
      DISABLE_RB2_OPENDRAIN();        \
      DISABLE_RB2_PULLUP();           \
      DISABLE_RB2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB2: Provide GPIO for RB2


// Provide GPIO for RB3
// ====================
#ifdef _RB3
# ifndef RB3_GPIO
#   warning "RB3_GPIO not defined, but pin RB3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB3_GPIO)
# define RB3_REMAPPABLE RXY_REMAPPABLE_PIN(RB3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB3_GPIO)
#   define ENABLE_RB3_ANALOG()  (RXY_GPIO_PCFG(RB3_GPIO) = 1)
#   define DISABLE_RB3_ANALOG() (RXY_GPIO_PCFG(RB3_GPIO) = 0)
#   define RB3_AN_PORT RXY_AN_PORT(RB3_GPIO)
# else
#   define DISABLE_RB3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB3_AS_INPUT()  (_TRISB3 = 1)
# define CONFIG_RB3_AS_OUTPUT() (_TRISB3 = 0)

// Open-drain:
#if defined(_ODCB3)
# define ENABLE_RB3_OPENDRAIN()  (_ODCB3 = 1)
# define DISABLE_RB3_OPENDRAIN() (_ODCB3 = 0)
#elif defined(_ODB3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB3_OPENDRAIN()  (_ODB3 = 1)
# define DISABLE_RB3_OPENDRAIN() (_ODB3 = 0)
#else
# define DISABLE_RB3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB3_GPIO)
#   define ENABLE_RB3_PULLUP()  (RXY_GPIO_CNPUE(RB3_GPIO) = 1)
#   define DISABLE_RB3_PULLUP() (RXY_GPIO_CNPUE(RB3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB3_GPIO)
#     define ENABLE_RB3_PULLDOWN()  (RXY_GPIO_CNPDE(RB3_GPIO) = 1)
#     define DISABLE_RB3_PULLDOWN() (RXY_GPIO_CNPDE(RB3_GPIO) = 0)
#   else
#     define DISABLE_RB3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB3_GPIO) = 1)
#   define DISABLE_RB3_CN_INTERRUPT() (RXY_GPIO_CNIE(RB3_GPIO) = 0)

# else
#   define DISABLE_RB3_PULLUP() ((void) 0)
#   define DISABLE_RB3_PULLDOWN() ((void) 0)
#   define DISABLE_RB3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB3_AS_ANALOG()       \
    do {                              \
      ENABLE_RB3_ANALOG();            \
      CONFIG_RB3_AS_INPUT();          \
      DISABLE_RB3_OPENDRAIN();        \
      DISABLE_RB3_PULLUP();           \
      DISABLE_RB3_PULLDOWN();         \
    } while (0)

# define CONFIG_RB3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB3_ANALOG();           \
      CONFIG_RB3_AS_INPUT();          \
      DISABLE_RB3_OPENDRAIN();        \
      DISABLE_RB3_PULLUP();           \
      DISABLE_RB3_PULLDOWN();         \
    } while (0)

# define CONFIG_RB3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB3_ANALOG();           \
      CONFIG_RB3_AS_OUTPUT();         \
      DISABLE_RB3_OPENDRAIN();        \
      DISABLE_RB3_PULLUP();           \
      DISABLE_RB3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB3: Provide GPIO for RB3


// Provide GPIO for RB4
// ====================
#ifdef _RB4
# ifndef RB4_GPIO
#   warning "RB4_GPIO not defined, but pin RB4 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB4_GPIO)
# define RB4_REMAPPABLE RXY_REMAPPABLE_PIN(RB4_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB4_GPIO)
#   define ENABLE_RB4_ANALOG()  (RXY_GPIO_PCFG(RB4_GPIO) = 1)
#   define DISABLE_RB4_ANALOG() (RXY_GPIO_PCFG(RB4_GPIO) = 0)
#   define RB4_AN_PORT RXY_AN_PORT(RB4_GPIO)
# else
#   define DISABLE_RB4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB4_AS_INPUT()  (_TRISB4 = 1)
# define CONFIG_RB4_AS_OUTPUT() (_TRISB4 = 0)

// Open-drain:
#if defined(_ODCB4)
# define ENABLE_RB4_OPENDRAIN()  (_ODCB4 = 1)
# define DISABLE_RB4_OPENDRAIN() (_ODCB4 = 0)
#elif defined(_ODB4)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB4_OPENDRAIN()  (_ODB4 = 1)
# define DISABLE_RB4_OPENDRAIN() (_ODB4 = 0)
#else
# define DISABLE_RB4_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB4_GPIO)
#   define ENABLE_RB4_PULLUP()  (RXY_GPIO_CNPUE(RB4_GPIO) = 1)
#   define DISABLE_RB4_PULLUP() (RXY_GPIO_CNPUE(RB4_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB4_GPIO)
#     define ENABLE_RB4_PULLDOWN()  (RXY_GPIO_CNPDE(RB4_GPIO) = 1)
#     define DISABLE_RB4_PULLDOWN() (RXY_GPIO_CNPDE(RB4_GPIO) = 0)
#   else
#     define DISABLE_RB4_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB4_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB4_GPIO) = 1)
#   define DISABLE_RB4_CN_INTERRUPT() (RXY_GPIO_CNIE(RB4_GPIO) = 0)

# else
#   define DISABLE_RB4_PULLUP() ((void) 0)
#   define DISABLE_RB4_PULLDOWN() ((void) 0)
#   define DISABLE_RB4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB4_AS_ANALOG()       \
    do {                              \
      ENABLE_RB4_ANALOG();            \
      CONFIG_RB4_AS_INPUT();          \
      DISABLE_RB4_OPENDRAIN();        \
      DISABLE_RB4_PULLUP();           \
      DISABLE_RB4_PULLDOWN();         \
    } while (0)

# define CONFIG_RB4_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB4_ANALOG();           \
      CONFIG_RB4_AS_INPUT();          \
      DISABLE_RB4_OPENDRAIN();        \
      DISABLE_RB4_PULLUP();           \
      DISABLE_RB4_PULLDOWN();         \
    } while (0)

# define CONFIG_RB4_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB4_ANALOG();           \
      CONFIG_RB4_AS_OUTPUT();         \
      DISABLE_RB4_OPENDRAIN();        \
      DISABLE_RB4_PULLUP();           \
      DISABLE_RB4_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB4: Provide GPIO for RB4


// Provide GPIO for RB5
// ====================
#ifdef _RB5
# ifndef RB5_GPIO
#   warning "RB5_GPIO not defined, but pin RB5 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB5_GPIO)
# define RB5_REMAPPABLE RXY_REMAPPABLE_PIN(RB5_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB5_GPIO)
#   define ENABLE_RB5_ANALOG()  (RXY_GPIO_PCFG(RB5_GPIO) = 1)
#   define DISABLE_RB5_ANALOG() (RXY_GPIO_PCFG(RB5_GPIO) = 0)
#   define RB5_AN_PORT RXY_AN_PORT(RB5_GPIO)
# else
#   define DISABLE_RB5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB5_AS_INPUT()  (_TRISB5 = 1)
# define CONFIG_RB5_AS_OUTPUT() (_TRISB5 = 0)

// Open-drain:
#if defined(_ODCB5)
# define ENABLE_RB5_OPENDRAIN()  (_ODCB5 = 1)
# define DISABLE_RB5_OPENDRAIN() (_ODCB5 = 0)
#elif defined(_ODB5)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB5_OPENDRAIN()  (_ODB5 = 1)
# define DISABLE_RB5_OPENDRAIN() (_ODB5 = 0)
#else
# define DISABLE_RB5_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB5_GPIO)
#   define ENABLE_RB5_PULLUP()  (RXY_GPIO_CNPUE(RB5_GPIO) = 1)
#   define DISABLE_RB5_PULLUP() (RXY_GPIO_CNPUE(RB5_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB5_GPIO)
#     define ENABLE_RB5_PULLDOWN()  (RXY_GPIO_CNPDE(RB5_GPIO) = 1)
#     define DISABLE_RB5_PULLDOWN() (RXY_GPIO_CNPDE(RB5_GPIO) = 0)
#   else
#     define DISABLE_RB5_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB5_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB5_GPIO) = 1)
#   define DISABLE_RB5_CN_INTERRUPT() (RXY_GPIO_CNIE(RB5_GPIO) = 0)

# else
#   define DISABLE_RB5_PULLUP() ((void) 0)
#   define DISABLE_RB5_PULLDOWN() ((void) 0)
#   define DISABLE_RB5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB5_AS_ANALOG()       \
    do {                              \
      ENABLE_RB5_ANALOG();            \
      CONFIG_RB5_AS_INPUT();          \
      DISABLE_RB5_OPENDRAIN();        \
      DISABLE_RB5_PULLUP();           \
      DISABLE_RB5_PULLDOWN();         \
    } while (0)

# define CONFIG_RB5_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB5_ANALOG();           \
      CONFIG_RB5_AS_INPUT();          \
      DISABLE_RB5_OPENDRAIN();        \
      DISABLE_RB5_PULLUP();           \
      DISABLE_RB5_PULLDOWN();         \
    } while (0)

# define CONFIG_RB5_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB5_ANALOG();           \
      CONFIG_RB5_AS_OUTPUT();         \
      DISABLE_RB5_OPENDRAIN();        \
      DISABLE_RB5_PULLUP();           \
      DISABLE_RB5_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB5: Provide GPIO for RB5


// Provide GPIO for RB6
// ====================
#ifdef _RB6
# ifndef RB6_GPIO
#   warning "RB6_GPIO not defined, but pin RB6 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB6_GPIO)
# define RB6_REMAPPABLE RXY_REMAPPABLE_PIN(RB6_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB6_GPIO)
#   define ENABLE_RB6_ANALOG()  (RXY_GPIO_PCFG(RB6_GPIO) = 1)
#   define DISABLE_RB6_ANALOG() (RXY_GPIO_PCFG(RB6_GPIO) = 0)
#   define RB6_AN_PORT RXY_AN_PORT(RB6_GPIO)
# else
#   define DISABLE_RB6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB6_AS_INPUT()  (_TRISB6 = 1)
# define CONFIG_RB6_AS_OUTPUT() (_TRISB6 = 0)

// Open-drain:
#if defined(_ODCB6)
# define ENABLE_RB6_OPENDRAIN()  (_ODCB6 = 1)
# define DISABLE_RB6_OPENDRAIN() (_ODCB6 = 0)
#elif defined(_ODB6)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB6_OPENDRAIN()  (_ODB6 = 1)
# define DISABLE_RB6_OPENDRAIN() (_ODB6 = 0)
#else
# define DISABLE_RB6_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB6_GPIO)
#   define ENABLE_RB6_PULLUP()  (RXY_GPIO_CNPUE(RB6_GPIO) = 1)
#   define DISABLE_RB6_PULLUP() (RXY_GPIO_CNPUE(RB6_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB6_GPIO)
#     define ENABLE_RB6_PULLDOWN()  (RXY_GPIO_CNPDE(RB6_GPIO) = 1)
#     define DISABLE_RB6_PULLDOWN() (RXY_GPIO_CNPDE(RB6_GPIO) = 0)
#   else
#     define DISABLE_RB6_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB6_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB6_GPIO) = 1)
#   define DISABLE_RB6_CN_INTERRUPT() (RXY_GPIO_CNIE(RB6_GPIO) = 0)

# else
#   define DISABLE_RB6_PULLUP() ((void) 0)
#   define DISABLE_RB6_PULLDOWN() ((void) 0)
#   define DISABLE_RB6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB6_AS_ANALOG()       \
    do {                              \
      ENABLE_RB6_ANALOG();            \
      CONFIG_RB6_AS_INPUT();          \
      DISABLE_RB6_OPENDRAIN();        \
      DISABLE_RB6_PULLUP();           \
      DISABLE_RB6_PULLDOWN();         \
    } while (0)

# define CONFIG_RB6_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB6_ANALOG();           \
      CONFIG_RB6_AS_INPUT();          \
      DISABLE_RB6_OPENDRAIN();        \
      DISABLE_RB6_PULLUP();           \
      DISABLE_RB6_PULLDOWN();         \
    } while (0)

# define CONFIG_RB6_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB6_ANALOG();           \
      CONFIG_RB6_AS_OUTPUT();         \
      DISABLE_RB6_OPENDRAIN();        \
      DISABLE_RB6_PULLUP();           \
      DISABLE_RB6_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB6: Provide GPIO for RB6


// Provide GPIO for RB7
// ====================
#ifdef _RB7
# ifndef RB7_GPIO
#   warning "RB7_GPIO not defined, but pin RB7 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB7_GPIO)
# define RB7_REMAPPABLE RXY_REMAPPABLE_PIN(RB7_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB7_GPIO)
#   define ENABLE_RB7_ANALOG()  (RXY_GPIO_PCFG(RB7_GPIO) = 1)
#   define DISABLE_RB7_ANALOG() (RXY_GPIO_PCFG(RB7_GPIO) = 0)
#   define RB7_AN_PORT RXY_AN_PORT(RB7_GPIO)
# else
#   define DISABLE_RB7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB7_AS_INPUT()  (_TRISB7 = 1)
# define CONFIG_RB7_AS_OUTPUT() (_TRISB7 = 0)

// Open-drain:
#if defined(_ODCB7)
# define ENABLE_RB7_OPENDRAIN()  (_ODCB7 = 1)
# define DISABLE_RB7_OPENDRAIN() (_ODCB7 = 0)
#elif defined(_ODB7)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB7_OPENDRAIN()  (_ODB7 = 1)
# define DISABLE_RB7_OPENDRAIN() (_ODB7 = 0)
#else
# define DISABLE_RB7_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB7_GPIO)
#   define ENABLE_RB7_PULLUP()  (RXY_GPIO_CNPUE(RB7_GPIO) = 1)
#   define DISABLE_RB7_PULLUP() (RXY_GPIO_CNPUE(RB7_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB7_GPIO)
#     define ENABLE_RB7_PULLDOWN()  (RXY_GPIO_CNPDE(RB7_GPIO) = 1)
#     define DISABLE_RB7_PULLDOWN() (RXY_GPIO_CNPDE(RB7_GPIO) = 0)
#   else
#     define DISABLE_RB7_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB7_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB7_GPIO) = 1)
#   define DISABLE_RB7_CN_INTERRUPT() (RXY_GPIO_CNIE(RB7_GPIO) = 0)

# else
#   define DISABLE_RB7_PULLUP() ((void) 0)
#   define DISABLE_RB7_PULLDOWN() ((void) 0)
#   define DISABLE_RB7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB7_AS_ANALOG()       \
    do {                              \
      ENABLE_RB7_ANALOG();            \
      CONFIG_RB7_AS_INPUT();          \
      DISABLE_RB7_OPENDRAIN();        \
      DISABLE_RB7_PULLUP();           \
      DISABLE_RB7_PULLDOWN();         \
    } while (0)

# define CONFIG_RB7_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB7_ANALOG();           \
      CONFIG_RB7_AS_INPUT();          \
      DISABLE_RB7_OPENDRAIN();        \
      DISABLE_RB7_PULLUP();           \
      DISABLE_RB7_PULLDOWN();         \
    } while (0)

# define CONFIG_RB7_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB7_ANALOG();           \
      CONFIG_RB7_AS_OUTPUT();         \
      DISABLE_RB7_OPENDRAIN();        \
      DISABLE_RB7_PULLUP();           \
      DISABLE_RB7_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB7: Provide GPIO for RB7


// Provide GPIO for RB8
// ====================
#ifdef _RB8
# ifndef RB8_GPIO
#   warning "RB8_GPIO not defined, but pin RB8 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB8_GPIO)
# define RB8_REMAPPABLE RXY_REMAPPABLE_PIN(RB8_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB8_GPIO)
#   define ENABLE_RB8_ANALOG()  (RXY_GPIO_PCFG(RB8_GPIO) = 1)
#   define DISABLE_RB8_ANALOG() (RXY_GPIO_PCFG(RB8_GPIO) = 0)
#   define RB8_AN_PORT RXY_AN_PORT(RB8_GPIO)
# else
#   define DISABLE_RB8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB8_AS_INPUT()  (_TRISB8 = 1)
# define CONFIG_RB8_AS_OUTPUT() (_TRISB8 = 0)

// Open-drain:
#if defined(_ODCB8)
# define ENABLE_RB8_OPENDRAIN()  (_ODCB8 = 1)
# define DISABLE_RB8_OPENDRAIN() (_ODCB8 = 0)
#elif defined(_ODB8)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB8_OPENDRAIN()  (_ODB8 = 1)
# define DISABLE_RB8_OPENDRAIN() (_ODB8 = 0)
#else
# define DISABLE_RB8_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB8_GPIO)
#   define ENABLE_RB8_PULLUP()  (RXY_GPIO_CNPUE(RB8_GPIO) = 1)
#   define DISABLE_RB8_PULLUP() (RXY_GPIO_CNPUE(RB8_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB8_GPIO)
#     define ENABLE_RB8_PULLDOWN()  (RXY_GPIO_CNPDE(RB8_GPIO) = 1)
#     define DISABLE_RB8_PULLDOWN() (RXY_GPIO_CNPDE(RB8_GPIO) = 0)
#   else
#     define DISABLE_RB8_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB8_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB8_GPIO) = 1)
#   define DISABLE_RB8_CN_INTERRUPT() (RXY_GPIO_CNIE(RB8_GPIO) = 0)

# else
#   define DISABLE_RB8_PULLUP() ((void) 0)
#   define DISABLE_RB8_PULLDOWN() ((void) 0)
#   define DISABLE_RB8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB8_AS_ANALOG()       \
    do {                              \
      ENABLE_RB8_ANALOG();            \
      CONFIG_RB8_AS_INPUT();          \
      DISABLE_RB8_OPENDRAIN();        \
      DISABLE_RB8_PULLUP();           \
      DISABLE_RB8_PULLDOWN();         \
    } while (0)

# define CONFIG_RB8_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB8_ANALOG();           \
      CONFIG_RB8_AS_INPUT();          \
      DISABLE_RB8_OPENDRAIN();        \
      DISABLE_RB8_PULLUP();           \
      DISABLE_RB8_PULLDOWN();         \
    } while (0)

# define CONFIG_RB8_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB8_ANALOG();           \
      CONFIG_RB8_AS_OUTPUT();         \
      DISABLE_RB8_OPENDRAIN();        \
      DISABLE_RB8_PULLUP();           \
      DISABLE_RB8_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB8: Provide GPIO for RB8


// Provide GPIO for RB9
// ====================
#ifdef _RB9
# ifndef RB9_GPIO
#   warning "RB9_GPIO not defined, but pin RB9 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB9_GPIO)
# define RB9_REMAPPABLE RXY_REMAPPABLE_PIN(RB9_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB9_GPIO)
#   define ENABLE_RB9_ANALOG()  (RXY_GPIO_PCFG(RB9_GPIO) = 1)
#   define DISABLE_RB9_ANALOG() (RXY_GPIO_PCFG(RB9_GPIO) = 0)
#   define RB9_AN_PORT RXY_AN_PORT(RB9_GPIO)
# else
#   define DISABLE_RB9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB9_AS_INPUT()  (_TRISB9 = 1)
# define CONFIG_RB9_AS_OUTPUT() (_TRISB9 = 0)

// Open-drain:
#if defined(_ODCB9)
# define ENABLE_RB9_OPENDRAIN()  (_ODCB9 = 1)
# define DISABLE_RB9_OPENDRAIN() (_ODCB9 = 0)
#elif defined(_ODB9)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB9_OPENDRAIN()  (_ODB9 = 1)
# define DISABLE_RB9_OPENDRAIN() (_ODB9 = 0)
#else
# define DISABLE_RB9_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB9_GPIO)
#   define ENABLE_RB9_PULLUP()  (RXY_GPIO_CNPUE(RB9_GPIO) = 1)
#   define DISABLE_RB9_PULLUP() (RXY_GPIO_CNPUE(RB9_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB9_GPIO)
#     define ENABLE_RB9_PULLDOWN()  (RXY_GPIO_CNPDE(RB9_GPIO) = 1)
#     define DISABLE_RB9_PULLDOWN() (RXY_GPIO_CNPDE(RB9_GPIO) = 0)
#   else
#     define DISABLE_RB9_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB9_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB9_GPIO) = 1)
#   define DISABLE_RB9_CN_INTERRUPT() (RXY_GPIO_CNIE(RB9_GPIO) = 0)

# else
#   define DISABLE_RB9_PULLUP() ((void) 0)
#   define DISABLE_RB9_PULLDOWN() ((void) 0)
#   define DISABLE_RB9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB9_AS_ANALOG()       \
    do {                              \
      ENABLE_RB9_ANALOG();            \
      CONFIG_RB9_AS_INPUT();          \
      DISABLE_RB9_OPENDRAIN();        \
      DISABLE_RB9_PULLUP();           \
      DISABLE_RB9_PULLDOWN();         \
    } while (0)

# define CONFIG_RB9_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB9_ANALOG();           \
      CONFIG_RB9_AS_INPUT();          \
      DISABLE_RB9_OPENDRAIN();        \
      DISABLE_RB9_PULLUP();           \
      DISABLE_RB9_PULLDOWN();         \
    } while (0)

# define CONFIG_RB9_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB9_ANALOG();           \
      CONFIG_RB9_AS_OUTPUT();         \
      DISABLE_RB9_OPENDRAIN();        \
      DISABLE_RB9_PULLUP();           \
      DISABLE_RB9_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB9: Provide GPIO for RB9


// Provide GPIO for RB10
// ====================
#ifdef _RB10
# ifndef RB10_GPIO
#   warning "RB10_GPIO not defined, but pin RB10 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB10_GPIO)
# define RB10_REMAPPABLE RXY_REMAPPABLE_PIN(RB10_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB10_GPIO)
#   define ENABLE_RB10_ANALOG()  (RXY_GPIO_PCFG(RB10_GPIO) = 1)
#   define DISABLE_RB10_ANALOG() (RXY_GPIO_PCFG(RB10_GPIO) = 0)
#   define RB10_AN_PORT RXY_AN_PORT(RB10_GPIO)
# else
#   define DISABLE_RB10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB10_AS_INPUT()  (_TRISB10 = 1)
# define CONFIG_RB10_AS_OUTPUT() (_TRISB10 = 0)

// Open-drain:
#if defined(_ODCB10)
# define ENABLE_RB10_OPENDRAIN()  (_ODCB10 = 1)
# define DISABLE_RB10_OPENDRAIN() (_ODCB10 = 0)
#elif defined(_ODB10)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB10_OPENDRAIN()  (_ODB10 = 1)
# define DISABLE_RB10_OPENDRAIN() (_ODB10 = 0)
#else
# define DISABLE_RB10_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB10_GPIO)
#   define ENABLE_RB10_PULLUP()  (RXY_GPIO_CNPUE(RB10_GPIO) = 1)
#   define DISABLE_RB10_PULLUP() (RXY_GPIO_CNPUE(RB10_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB10_GPIO)
#     define ENABLE_RB10_PULLDOWN()  (RXY_GPIO_CNPDE(RB10_GPIO) = 1)
#     define DISABLE_RB10_PULLDOWN() (RXY_GPIO_CNPDE(RB10_GPIO) = 0)
#   else
#     define DISABLE_RB10_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB10_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB10_GPIO) = 1)
#   define DISABLE_RB10_CN_INTERRUPT() (RXY_GPIO_CNIE(RB10_GPIO) = 0)

# else
#   define DISABLE_RB10_PULLUP() ((void) 0)
#   define DISABLE_RB10_PULLDOWN() ((void) 0)
#   define DISABLE_RB10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB10_AS_ANALOG()       \
    do {                              \
      ENABLE_RB10_ANALOG();            \
      CONFIG_RB10_AS_INPUT();          \
      DISABLE_RB10_OPENDRAIN();        \
      DISABLE_RB10_PULLUP();           \
      DISABLE_RB10_PULLDOWN();         \
    } while (0)

# define CONFIG_RB10_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB10_ANALOG();           \
      CONFIG_RB10_AS_INPUT();          \
      DISABLE_RB10_OPENDRAIN();        \
      DISABLE_RB10_PULLUP();           \
      DISABLE_RB10_PULLDOWN();         \
    } while (0)

# define CONFIG_RB10_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB10_ANALOG();           \
      CONFIG_RB10_AS_OUTPUT();         \
      DISABLE_RB10_OPENDRAIN();        \
      DISABLE_RB10_PULLUP();           \
      DISABLE_RB10_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB10: Provide GPIO for RB10


// Provide GPIO for RB11
// ====================
#ifdef _RB11
# ifndef RB11_GPIO
#   warning "RB11_GPIO not defined, but pin RB11 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB11_GPIO)
# define RB11_REMAPPABLE RXY_REMAPPABLE_PIN(RB11_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB11_GPIO)
#   define ENABLE_RB11_ANALOG()  (RXY_GPIO_PCFG(RB11_GPIO) = 1)
#   define DISABLE_RB11_ANALOG() (RXY_GPIO_PCFG(RB11_GPIO) = 0)
#   define RB11_AN_PORT RXY_AN_PORT(RB11_GPIO)
# else
#   define DISABLE_RB11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB11_AS_INPUT()  (_TRISB11 = 1)
# define CONFIG_RB11_AS_OUTPUT() (_TRISB11 = 0)

// Open-drain:
#if defined(_ODCB11)
# define ENABLE_RB11_OPENDRAIN()  (_ODCB11 = 1)
# define DISABLE_RB11_OPENDRAIN() (_ODCB11 = 0)
#elif defined(_ODB11)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB11_OPENDRAIN()  (_ODB11 = 1)
# define DISABLE_RB11_OPENDRAIN() (_ODB11 = 0)
#else
# define DISABLE_RB11_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB11_GPIO)
#   define ENABLE_RB11_PULLUP()  (RXY_GPIO_CNPUE(RB11_GPIO) = 1)
#   define DISABLE_RB11_PULLUP() (RXY_GPIO_CNPUE(RB11_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB11_GPIO)
#     define ENABLE_RB11_PULLDOWN()  (RXY_GPIO_CNPDE(RB11_GPIO) = 1)
#     define DISABLE_RB11_PULLDOWN() (RXY_GPIO_CNPDE(RB11_GPIO) = 0)
#   else
#     define DISABLE_RB11_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB11_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB11_GPIO) = 1)
#   define DISABLE_RB11_CN_INTERRUPT() (RXY_GPIO_CNIE(RB11_GPIO) = 0)

# else
#   define DISABLE_RB11_PULLUP() ((void) 0)
#   define DISABLE_RB11_PULLDOWN() ((void) 0)
#   define DISABLE_RB11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB11_AS_ANALOG()       \
    do {                              \
      ENABLE_RB11_ANALOG();            \
      CONFIG_RB11_AS_INPUT();          \
      DISABLE_RB11_OPENDRAIN();        \
      DISABLE_RB11_PULLUP();           \
      DISABLE_RB11_PULLDOWN();         \
    } while (0)

# define CONFIG_RB11_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB11_ANALOG();           \
      CONFIG_RB11_AS_INPUT();          \
      DISABLE_RB11_OPENDRAIN();        \
      DISABLE_RB11_PULLUP();           \
      DISABLE_RB11_PULLDOWN();         \
    } while (0)

# define CONFIG_RB11_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB11_ANALOG();           \
      CONFIG_RB11_AS_OUTPUT();         \
      DISABLE_RB11_OPENDRAIN();        \
      DISABLE_RB11_PULLUP();           \
      DISABLE_RB11_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB11: Provide GPIO for RB11


// Provide GPIO for RB12
// ====================
#ifdef _RB12
# ifndef RB12_GPIO
#   warning "RB12_GPIO not defined, but pin RB12 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB12_GPIO)
# define RB12_REMAPPABLE RXY_REMAPPABLE_PIN(RB12_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB12_GPIO)
#   define ENABLE_RB12_ANALOG()  (RXY_GPIO_PCFG(RB12_GPIO) = 1)
#   define DISABLE_RB12_ANALOG() (RXY_GPIO_PCFG(RB12_GPIO) = 0)
#   define RB12_AN_PORT RXY_AN_PORT(RB12_GPIO)
# else
#   define DISABLE_RB12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB12_AS_INPUT()  (_TRISB12 = 1)
# define CONFIG_RB12_AS_OUTPUT() (_TRISB12 = 0)

// Open-drain:
#if defined(_ODCB12)
# define ENABLE_RB12_OPENDRAIN()  (_ODCB12 = 1)
# define DISABLE_RB12_OPENDRAIN() (_ODCB12 = 0)
#elif defined(_ODB12)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB12_OPENDRAIN()  (_ODB12 = 1)
# define DISABLE_RB12_OPENDRAIN() (_ODB12 = 0)
#else
# define DISABLE_RB12_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB12_GPIO)
#   define ENABLE_RB12_PULLUP()  (RXY_GPIO_CNPUE(RB12_GPIO) = 1)
#   define DISABLE_RB12_PULLUP() (RXY_GPIO_CNPUE(RB12_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB12_GPIO)
#     define ENABLE_RB12_PULLDOWN()  (RXY_GPIO_CNPDE(RB12_GPIO) = 1)
#     define DISABLE_RB12_PULLDOWN() (RXY_GPIO_CNPDE(RB12_GPIO) = 0)
#   else
#     define DISABLE_RB12_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB12_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB12_GPIO) = 1)
#   define DISABLE_RB12_CN_INTERRUPT() (RXY_GPIO_CNIE(RB12_GPIO) = 0)

# else
#   define DISABLE_RB12_PULLUP() ((void) 0)
#   define DISABLE_RB12_PULLDOWN() ((void) 0)
#   define DISABLE_RB12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB12_AS_ANALOG()       \
    do {                              \
      ENABLE_RB12_ANALOG();            \
      CONFIG_RB12_AS_INPUT();          \
      DISABLE_RB12_OPENDRAIN();        \
      DISABLE_RB12_PULLUP();           \
      DISABLE_RB12_PULLDOWN();         \
    } while (0)

# define CONFIG_RB12_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB12_ANALOG();           \
      CONFIG_RB12_AS_INPUT();          \
      DISABLE_RB12_OPENDRAIN();        \
      DISABLE_RB12_PULLUP();           \
      DISABLE_RB12_PULLDOWN();         \
    } while (0)

# define CONFIG_RB12_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB12_ANALOG();           \
      CONFIG_RB12_AS_OUTPUT();         \
      DISABLE_RB12_OPENDRAIN();        \
      DISABLE_RB12_PULLUP();           \
      DISABLE_RB12_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB12: Provide GPIO for RB12


// Provide GPIO for RB13
// ====================
#ifdef _RB13
# ifndef RB13_GPIO
#   warning "RB13_GPIO not defined, but pin RB13 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB13_GPIO)
# define RB13_REMAPPABLE RXY_REMAPPABLE_PIN(RB13_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB13_GPIO)
#   define ENABLE_RB13_ANALOG()  (RXY_GPIO_PCFG(RB13_GPIO) = 1)
#   define DISABLE_RB13_ANALOG() (RXY_GPIO_PCFG(RB13_GPIO) = 0)
#   define RB13_AN_PORT RXY_AN_PORT(RB13_GPIO)
# else
#   define DISABLE_RB13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB13_AS_INPUT()  (_TRISB13 = 1)
# define CONFIG_RB13_AS_OUTPUT() (_TRISB13 = 0)

// Open-drain:
#if defined(_ODCB13)
# define ENABLE_RB13_OPENDRAIN()  (_ODCB13 = 1)
# define DISABLE_RB13_OPENDRAIN() (_ODCB13 = 0)
#elif defined(_ODB13)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB13_OPENDRAIN()  (_ODB13 = 1)
# define DISABLE_RB13_OPENDRAIN() (_ODB13 = 0)
#else
# define DISABLE_RB13_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB13_GPIO)
#   define ENABLE_RB13_PULLUP()  (RXY_GPIO_CNPUE(RB13_GPIO) = 1)
#   define DISABLE_RB13_PULLUP() (RXY_GPIO_CNPUE(RB13_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB13_GPIO)
#     define ENABLE_RB13_PULLDOWN()  (RXY_GPIO_CNPDE(RB13_GPIO) = 1)
#     define DISABLE_RB13_PULLDOWN() (RXY_GPIO_CNPDE(RB13_GPIO) = 0)
#   else
#     define DISABLE_RB13_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB13_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB13_GPIO) = 1)
#   define DISABLE_RB13_CN_INTERRUPT() (RXY_GPIO_CNIE(RB13_GPIO) = 0)

# else
#   define DISABLE_RB13_PULLUP() ((void) 0)
#   define DISABLE_RB13_PULLDOWN() ((void) 0)
#   define DISABLE_RB13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB13_AS_ANALOG()       \
    do {                              \
      ENABLE_RB13_ANALOG();            \
      CONFIG_RB13_AS_INPUT();          \
      DISABLE_RB13_OPENDRAIN();        \
      DISABLE_RB13_PULLUP();           \
      DISABLE_RB13_PULLDOWN();         \
    } while (0)

# define CONFIG_RB13_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB13_ANALOG();           \
      CONFIG_RB13_AS_INPUT();          \
      DISABLE_RB13_OPENDRAIN();        \
      DISABLE_RB13_PULLUP();           \
      DISABLE_RB13_PULLDOWN();         \
    } while (0)

# define CONFIG_RB13_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB13_ANALOG();           \
      CONFIG_RB13_AS_OUTPUT();         \
      DISABLE_RB13_OPENDRAIN();        \
      DISABLE_RB13_PULLUP();           \
      DISABLE_RB13_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB13: Provide GPIO for RB13


// Provide GPIO for RB14
// ====================
#ifdef _RB14
# ifndef RB14_GPIO
#   warning "RB14_GPIO not defined, but pin RB14 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB14_GPIO)
# define RB14_REMAPPABLE RXY_REMAPPABLE_PIN(RB14_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB14_GPIO)
#   define ENABLE_RB14_ANALOG()  (RXY_GPIO_PCFG(RB14_GPIO) = 1)
#   define DISABLE_RB14_ANALOG() (RXY_GPIO_PCFG(RB14_GPIO) = 0)
#   define RB14_AN_PORT RXY_AN_PORT(RB14_GPIO)
# else
#   define DISABLE_RB14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB14_AS_INPUT()  (_TRISB14 = 1)
# define CONFIG_RB14_AS_OUTPUT() (_TRISB14 = 0)

// Open-drain:
#if defined(_ODCB14)
# define ENABLE_RB14_OPENDRAIN()  (_ODCB14 = 1)
# define DISABLE_RB14_OPENDRAIN() (_ODCB14 = 0)
#elif defined(_ODB14)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB14_OPENDRAIN()  (_ODB14 = 1)
# define DISABLE_RB14_OPENDRAIN() (_ODB14 = 0)
#else
# define DISABLE_RB14_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB14_GPIO)
#   define ENABLE_RB14_PULLUP()  (RXY_GPIO_CNPUE(RB14_GPIO) = 1)
#   define DISABLE_RB14_PULLUP() (RXY_GPIO_CNPUE(RB14_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB14_GPIO)
#     define ENABLE_RB14_PULLDOWN()  (RXY_GPIO_CNPDE(RB14_GPIO) = 1)
#     define DISABLE_RB14_PULLDOWN() (RXY_GPIO_CNPDE(RB14_GPIO) = 0)
#   else
#     define DISABLE_RB14_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB14_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB14_GPIO) = 1)
#   define DISABLE_RB14_CN_INTERRUPT() (RXY_GPIO_CNIE(RB14_GPIO) = 0)

# else
#   define DISABLE_RB14_PULLUP() ((void) 0)
#   define DISABLE_RB14_PULLDOWN() ((void) 0)
#   define DISABLE_RB14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB14_AS_ANALOG()       \
    do {                              \
      ENABLE_RB14_ANALOG();            \
      CONFIG_RB14_AS_INPUT();          \
      DISABLE_RB14_OPENDRAIN();        \
      DISABLE_RB14_PULLUP();           \
      DISABLE_RB14_PULLDOWN();         \
    } while (0)

# define CONFIG_RB14_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB14_ANALOG();           \
      CONFIG_RB14_AS_INPUT();          \
      DISABLE_RB14_OPENDRAIN();        \
      DISABLE_RB14_PULLUP();           \
      DISABLE_RB14_PULLDOWN();         \
    } while (0)

# define CONFIG_RB14_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB14_ANALOG();           \
      CONFIG_RB14_AS_OUTPUT();         \
      DISABLE_RB14_OPENDRAIN();        \
      DISABLE_RB14_PULLUP();           \
      DISABLE_RB14_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB14: Provide GPIO for RB14


// Provide GPIO for RB15
// ====================
#ifdef _RB15
# ifndef RB15_GPIO
#   warning "RB15_GPIO not defined, but pin RB15 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RB15_GPIO)
# define RB15_REMAPPABLE RXY_REMAPPABLE_PIN(RB15_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RB15_GPIO)
#   define ENABLE_RB15_ANALOG()  (RXY_GPIO_PCFG(RB15_GPIO) = 1)
#   define DISABLE_RB15_ANALOG() (RXY_GPIO_PCFG(RB15_GPIO) = 0)
#   define RB15_AN_PORT RXY_AN_PORT(RB15_GPIO)
# else
#   define DISABLE_RB15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB15_AS_INPUT()  (_TRISB15 = 1)
# define CONFIG_RB15_AS_OUTPUT() (_TRISB15 = 0)

// Open-drain:
#if defined(_ODCB15)
# define ENABLE_RB15_OPENDRAIN()  (_ODCB15 = 1)
# define DISABLE_RB15_OPENDRAIN() (_ODCB15 = 0)
#elif defined(_ODB15)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RB15_OPENDRAIN()  (_ODB15 = 1)
# define DISABLE_RB15_OPENDRAIN() (_ODB15 = 0)
#else
# define DISABLE_RB15_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RB15_GPIO)
#   define ENABLE_RB15_PULLUP()  (RXY_GPIO_CNPUE(RB15_GPIO) = 1)
#   define DISABLE_RB15_PULLUP() (RXY_GPIO_CNPUE(RB15_GPIO) = 0)

#   if RXY_HAS_CNPDE(RB15_GPIO)
#     define ENABLE_RB15_PULLDOWN()  (RXY_GPIO_CNPDE(RB15_GPIO) = 1)
#     define DISABLE_RB15_PULLDOWN() (RXY_GPIO_CNPDE(RB15_GPIO) = 0)
#   else
#     define DISABLE_RB15_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RB15_CN_INTERRUPT()  (RXY_GPIO_CNIE(RB15_GPIO) = 1)
#   define DISABLE_RB15_CN_INTERRUPT() (RXY_GPIO_CNIE(RB15_GPIO) = 0)

# else
#   define DISABLE_RB15_PULLUP() ((void) 0)
#   define DISABLE_RB15_PULLDOWN() ((void) 0)
#   define DISABLE_RB15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RB15_AS_ANALOG()       \
    do {                              \
      ENABLE_RB15_ANALOG();            \
      CONFIG_RB15_AS_INPUT();          \
      DISABLE_RB15_OPENDRAIN();        \
      DISABLE_RB15_PULLUP();           \
      DISABLE_RB15_PULLDOWN();         \
    } while (0)

# define CONFIG_RB15_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RB15_ANALOG();           \
      CONFIG_RB15_AS_INPUT();          \
      DISABLE_RB15_OPENDRAIN();        \
      DISABLE_RB15_PULLUP();           \
      DISABLE_RB15_PULLDOWN();         \
    } while (0)

# define CONFIG_RB15_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RB15_ANALOG();           \
      CONFIG_RB15_AS_OUTPUT();         \
      DISABLE_RB15_OPENDRAIN();        \
      DISABLE_RB15_PULLUP();           \
      DISABLE_RB15_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RB15: Provide GPIO for RB15


// Provide GPIO for RC0
// ====================
#ifdef _RC0
# ifndef RC0_GPIO
#   warning "RC0_GPIO not defined, but pin RC0 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC0_GPIO)
# define RC0_REMAPPABLE RXY_REMAPPABLE_PIN(RC0_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC0_GPIO)
#   define ENABLE_RC0_ANALOG()  (RXY_GPIO_PCFG(RC0_GPIO) = 1)
#   define DISABLE_RC0_ANALOG() (RXY_GPIO_PCFG(RC0_GPIO) = 0)
#   define RC0_AN_PORT RXY_AN_PORT(RC0_GPIO)
# else
#   define DISABLE_RC0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC0_AS_INPUT()  (_TRISC0 = 1)
# define CONFIG_RC0_AS_OUTPUT() (_TRISC0 = 0)

// Open-drain:
#if defined(_ODCC0)
# define ENABLE_RC0_OPENDRAIN()  (_ODCC0 = 1)
# define DISABLE_RC0_OPENDRAIN() (_ODCC0 = 0)
#elif defined(_ODC0)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC0_OPENDRAIN()  (_ODC0 = 1)
# define DISABLE_RC0_OPENDRAIN() (_ODC0 = 0)
#else
# define DISABLE_RC0_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC0_GPIO)
#   define ENABLE_RC0_PULLUP()  (RXY_GPIO_CNPUE(RC0_GPIO) = 1)
#   define DISABLE_RC0_PULLUP() (RXY_GPIO_CNPUE(RC0_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC0_GPIO)
#     define ENABLE_RC0_PULLDOWN()  (RXY_GPIO_CNPDE(RC0_GPIO) = 1)
#     define DISABLE_RC0_PULLDOWN() (RXY_GPIO_CNPDE(RC0_GPIO) = 0)
#   else
#     define DISABLE_RC0_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC0_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC0_GPIO) = 1)
#   define DISABLE_RC0_CN_INTERRUPT() (RXY_GPIO_CNIE(RC0_GPIO) = 0)

# else
#   define DISABLE_RC0_PULLUP() ((void) 0)
#   define DISABLE_RC0_PULLDOWN() ((void) 0)
#   define DISABLE_RC0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC0_AS_ANALOG()       \
    do {                              \
      ENABLE_RC0_ANALOG();            \
      CONFIG_RC0_AS_INPUT();          \
      DISABLE_RC0_OPENDRAIN();        \
      DISABLE_RC0_PULLUP();           \
      DISABLE_RC0_PULLDOWN();         \
    } while (0)

# define CONFIG_RC0_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC0_ANALOG();           \
      CONFIG_RC0_AS_INPUT();          \
      DISABLE_RC0_OPENDRAIN();        \
      DISABLE_RC0_PULLUP();           \
      DISABLE_RC0_PULLDOWN();         \
    } while (0)

# define CONFIG_RC0_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC0_ANALOG();           \
      CONFIG_RC0_AS_OUTPUT();         \
      DISABLE_RC0_OPENDRAIN();        \
      DISABLE_RC0_PULLUP();           \
      DISABLE_RC0_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC0: Provide GPIO for RC0


// Provide GPIO for RC1
// ====================
#ifdef _RC1
# ifndef RC1_GPIO
#   warning "RC1_GPIO not defined, but pin RC1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC1_GPIO)
# define RC1_REMAPPABLE RXY_REMAPPABLE_PIN(RC1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC1_GPIO)
#   define ENABLE_RC1_ANALOG()  (RXY_GPIO_PCFG(RC1_GPIO) = 1)
#   define DISABLE_RC1_ANALOG() (RXY_GPIO_PCFG(RC1_GPIO) = 0)
#   define RC1_AN_PORT RXY_AN_PORT(RC1_GPIO)
# else
#   define DISABLE_RC1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC1_AS_INPUT()  (_TRISC1 = 1)
# define CONFIG_RC1_AS_OUTPUT() (_TRISC1 = 0)

// Open-drain:
#if defined(_ODCC1)
# define ENABLE_RC1_OPENDRAIN()  (_ODCC1 = 1)
# define DISABLE_RC1_OPENDRAIN() (_ODCC1 = 0)
#elif defined(_ODC1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC1_OPENDRAIN()  (_ODC1 = 1)
# define DISABLE_RC1_OPENDRAIN() (_ODC1 = 0)
#else
# define DISABLE_RC1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC1_GPIO)
#   define ENABLE_RC1_PULLUP()  (RXY_GPIO_CNPUE(RC1_GPIO) = 1)
#   define DISABLE_RC1_PULLUP() (RXY_GPIO_CNPUE(RC1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC1_GPIO)
#     define ENABLE_RC1_PULLDOWN()  (RXY_GPIO_CNPDE(RC1_GPIO) = 1)
#     define DISABLE_RC1_PULLDOWN() (RXY_GPIO_CNPDE(RC1_GPIO) = 0)
#   else
#     define DISABLE_RC1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC1_GPIO) = 1)
#   define DISABLE_RC1_CN_INTERRUPT() (RXY_GPIO_CNIE(RC1_GPIO) = 0)

# else
#   define DISABLE_RC1_PULLUP() ((void) 0)
#   define DISABLE_RC1_PULLDOWN() ((void) 0)
#   define DISABLE_RC1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC1_AS_ANALOG()       \
    do {                              \
      ENABLE_RC1_ANALOG();            \
      CONFIG_RC1_AS_INPUT();          \
      DISABLE_RC1_OPENDRAIN();        \
      DISABLE_RC1_PULLUP();           \
      DISABLE_RC1_PULLDOWN();         \
    } while (0)

# define CONFIG_RC1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC1_ANALOG();           \
      CONFIG_RC1_AS_INPUT();          \
      DISABLE_RC1_OPENDRAIN();        \
      DISABLE_RC1_PULLUP();           \
      DISABLE_RC1_PULLDOWN();         \
    } while (0)

# define CONFIG_RC1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC1_ANALOG();           \
      CONFIG_RC1_AS_OUTPUT();         \
      DISABLE_RC1_OPENDRAIN();        \
      DISABLE_RC1_PULLUP();           \
      DISABLE_RC1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC1: Provide GPIO for RC1


// Provide GPIO for RC2
// ====================
#ifdef _RC2
# ifndef RC2_GPIO
#   warning "RC2_GPIO not defined, but pin RC2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC2_GPIO)
# define RC2_REMAPPABLE RXY_REMAPPABLE_PIN(RC2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC2_GPIO)
#   define ENABLE_RC2_ANALOG()  (RXY_GPIO_PCFG(RC2_GPIO) = 1)
#   define DISABLE_RC2_ANALOG() (RXY_GPIO_PCFG(RC2_GPIO) = 0)
#   define RC2_AN_PORT RXY_AN_PORT(RC2_GPIO)
# else
#   define DISABLE_RC2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC2_AS_INPUT()  (_TRISC2 = 1)
# define CONFIG_RC2_AS_OUTPUT() (_TRISC2 = 0)

// Open-drain:
#if defined(_ODCC2)
# define ENABLE_RC2_OPENDRAIN()  (_ODCC2 = 1)
# define DISABLE_RC2_OPENDRAIN() (_ODCC2 = 0)
#elif defined(_ODC2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC2_OPENDRAIN()  (_ODC2 = 1)
# define DISABLE_RC2_OPENDRAIN() (_ODC2 = 0)
#else
# define DISABLE_RC2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC2_GPIO)
#   define ENABLE_RC2_PULLUP()  (RXY_GPIO_CNPUE(RC2_GPIO) = 1)
#   define DISABLE_RC2_PULLUP() (RXY_GPIO_CNPUE(RC2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC2_GPIO)
#     define ENABLE_RC2_PULLDOWN()  (RXY_GPIO_CNPDE(RC2_GPIO) = 1)
#     define DISABLE_RC2_PULLDOWN() (RXY_GPIO_CNPDE(RC2_GPIO) = 0)
#   else
#     define DISABLE_RC2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC2_GPIO) = 1)
#   define DISABLE_RC2_CN_INTERRUPT() (RXY_GPIO_CNIE(RC2_GPIO) = 0)

# else
#   define DISABLE_RC2_PULLUP() ((void) 0)
#   define DISABLE_RC2_PULLDOWN() ((void) 0)
#   define DISABLE_RC2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC2_AS_ANALOG()       \
    do {                              \
      ENABLE_RC2_ANALOG();            \
      CONFIG_RC2_AS_INPUT();          \
      DISABLE_RC2_OPENDRAIN();        \
      DISABLE_RC2_PULLUP();           \
      DISABLE_RC2_PULLDOWN();         \
    } while (0)

# define CONFIG_RC2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC2_ANALOG();           \
      CONFIG_RC2_AS_INPUT();          \
      DISABLE_RC2_OPENDRAIN();        \
      DISABLE_RC2_PULLUP();           \
      DISABLE_RC2_PULLDOWN();         \
    } while (0)

# define CONFIG_RC2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC2_ANALOG();           \
      CONFIG_RC2_AS_OUTPUT();         \
      DISABLE_RC2_OPENDRAIN();        \
      DISABLE_RC2_PULLUP();           \
      DISABLE_RC2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC2: Provide GPIO for RC2


// Provide GPIO for RC3
// ====================
#ifdef _RC3
# ifndef RC3_GPIO
#   warning "RC3_GPIO not defined, but pin RC3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC3_GPIO)
# define RC3_REMAPPABLE RXY_REMAPPABLE_PIN(RC3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC3_GPIO)
#   define ENABLE_RC3_ANALOG()  (RXY_GPIO_PCFG(RC3_GPIO) = 1)
#   define DISABLE_RC3_ANALOG() (RXY_GPIO_PCFG(RC3_GPIO) = 0)
#   define RC3_AN_PORT RXY_AN_PORT(RC3_GPIO)
# else
#   define DISABLE_RC3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC3_AS_INPUT()  (_TRISC3 = 1)
# define CONFIG_RC3_AS_OUTPUT() (_TRISC3 = 0)

// Open-drain:
#if defined(_ODCC3)
# define ENABLE_RC3_OPENDRAIN()  (_ODCC3 = 1)
# define DISABLE_RC3_OPENDRAIN() (_ODCC3 = 0)
#elif defined(_ODC3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC3_OPENDRAIN()  (_ODC3 = 1)
# define DISABLE_RC3_OPENDRAIN() (_ODC3 = 0)
#else
# define DISABLE_RC3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC3_GPIO)
#   define ENABLE_RC3_PULLUP()  (RXY_GPIO_CNPUE(RC3_GPIO) = 1)
#   define DISABLE_RC3_PULLUP() (RXY_GPIO_CNPUE(RC3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC3_GPIO)
#     define ENABLE_RC3_PULLDOWN()  (RXY_GPIO_CNPDE(RC3_GPIO) = 1)
#     define DISABLE_RC3_PULLDOWN() (RXY_GPIO_CNPDE(RC3_GPIO) = 0)
#   else
#     define DISABLE_RC3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC3_GPIO) = 1)
#   define DISABLE_RC3_CN_INTERRUPT() (RXY_GPIO_CNIE(RC3_GPIO) = 0)

# else
#   define DISABLE_RC3_PULLUP() ((void) 0)
#   define DISABLE_RC3_PULLDOWN() ((void) 0)
#   define DISABLE_RC3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC3_AS_ANALOG()       \
    do {                              \
      ENABLE_RC3_ANALOG();            \
      CONFIG_RC3_AS_INPUT();          \
      DISABLE_RC3_OPENDRAIN();        \
      DISABLE_RC3_PULLUP();           \
      DISABLE_RC3_PULLDOWN();         \
    } while (0)

# define CONFIG_RC3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC3_ANALOG();           \
      CONFIG_RC3_AS_INPUT();          \
      DISABLE_RC3_OPENDRAIN();        \
      DISABLE_RC3_PULLUP();           \
      DISABLE_RC3_PULLDOWN();         \
    } while (0)

# define CONFIG_RC3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC3_ANALOG();           \
      CONFIG_RC3_AS_OUTPUT();         \
      DISABLE_RC3_OPENDRAIN();        \
      DISABLE_RC3_PULLUP();           \
      DISABLE_RC3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC3: Provide GPIO for RC3


// Provide GPIO for RC4
// ====================
#ifdef _RC4
# ifndef RC4_GPIO
#   warning "RC4_GPIO not defined, but pin RC4 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC4_GPIO)
# define RC4_REMAPPABLE RXY_REMAPPABLE_PIN(RC4_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC4_GPIO)
#   define ENABLE_RC4_ANALOG()  (RXY_GPIO_PCFG(RC4_GPIO) = 1)
#   define DISABLE_RC4_ANALOG() (RXY_GPIO_PCFG(RC4_GPIO) = 0)
#   define RC4_AN_PORT RXY_AN_PORT(RC4_GPIO)
# else
#   define DISABLE_RC4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC4_AS_INPUT()  (_TRISC4 = 1)
# define CONFIG_RC4_AS_OUTPUT() (_TRISC4 = 0)

// Open-drain:
#if defined(_ODCC4)
# define ENABLE_RC4_OPENDRAIN()  (_ODCC4 = 1)
# define DISABLE_RC4_OPENDRAIN() (_ODCC4 = 0)
#elif defined(_ODC4)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC4_OPENDRAIN()  (_ODC4 = 1)
# define DISABLE_RC4_OPENDRAIN() (_ODC4 = 0)
#else
# define DISABLE_RC4_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC4_GPIO)
#   define ENABLE_RC4_PULLUP()  (RXY_GPIO_CNPUE(RC4_GPIO) = 1)
#   define DISABLE_RC4_PULLUP() (RXY_GPIO_CNPUE(RC4_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC4_GPIO)
#     define ENABLE_RC4_PULLDOWN()  (RXY_GPIO_CNPDE(RC4_GPIO) = 1)
#     define DISABLE_RC4_PULLDOWN() (RXY_GPIO_CNPDE(RC4_GPIO) = 0)
#   else
#     define DISABLE_RC4_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC4_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC4_GPIO) = 1)
#   define DISABLE_RC4_CN_INTERRUPT() (RXY_GPIO_CNIE(RC4_GPIO) = 0)

# else
#   define DISABLE_RC4_PULLUP() ((void) 0)
#   define DISABLE_RC4_PULLDOWN() ((void) 0)
#   define DISABLE_RC4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC4_AS_ANALOG()       \
    do {                              \
      ENABLE_RC4_ANALOG();            \
      CONFIG_RC4_AS_INPUT();          \
      DISABLE_RC4_OPENDRAIN();        \
      DISABLE_RC4_PULLUP();           \
      DISABLE_RC4_PULLDOWN();         \
    } while (0)

# define CONFIG_RC4_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC4_ANALOG();           \
      CONFIG_RC4_AS_INPUT();          \
      DISABLE_RC4_OPENDRAIN();        \
      DISABLE_RC4_PULLUP();           \
      DISABLE_RC4_PULLDOWN();         \
    } while (0)

# define CONFIG_RC4_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC4_ANALOG();           \
      CONFIG_RC4_AS_OUTPUT();         \
      DISABLE_RC4_OPENDRAIN();        \
      DISABLE_RC4_PULLUP();           \
      DISABLE_RC4_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC4: Provide GPIO for RC4


// Provide GPIO for RC5
// ====================
#ifdef _RC5
# ifndef RC5_GPIO
#   warning "RC5_GPIO not defined, but pin RC5 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC5_GPIO)
# define RC5_REMAPPABLE RXY_REMAPPABLE_PIN(RC5_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC5_GPIO)
#   define ENABLE_RC5_ANALOG()  (RXY_GPIO_PCFG(RC5_GPIO) = 1)
#   define DISABLE_RC5_ANALOG() (RXY_GPIO_PCFG(RC5_GPIO) = 0)
#   define RC5_AN_PORT RXY_AN_PORT(RC5_GPIO)
# else
#   define DISABLE_RC5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC5_AS_INPUT()  (_TRISC5 = 1)
# define CONFIG_RC5_AS_OUTPUT() (_TRISC5 = 0)

// Open-drain:
#if defined(_ODCC5)
# define ENABLE_RC5_OPENDRAIN()  (_ODCC5 = 1)
# define DISABLE_RC5_OPENDRAIN() (_ODCC5 = 0)
#elif defined(_ODC5)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC5_OPENDRAIN()  (_ODC5 = 1)
# define DISABLE_RC5_OPENDRAIN() (_ODC5 = 0)
#else
# define DISABLE_RC5_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC5_GPIO)
#   define ENABLE_RC5_PULLUP()  (RXY_GPIO_CNPUE(RC5_GPIO) = 1)
#   define DISABLE_RC5_PULLUP() (RXY_GPIO_CNPUE(RC5_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC5_GPIO)
#     define ENABLE_RC5_PULLDOWN()  (RXY_GPIO_CNPDE(RC5_GPIO) = 1)
#     define DISABLE_RC5_PULLDOWN() (RXY_GPIO_CNPDE(RC5_GPIO) = 0)
#   else
#     define DISABLE_RC5_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC5_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC5_GPIO) = 1)
#   define DISABLE_RC5_CN_INTERRUPT() (RXY_GPIO_CNIE(RC5_GPIO) = 0)

# else
#   define DISABLE_RC5_PULLUP() ((void) 0)
#   define DISABLE_RC5_PULLDOWN() ((void) 0)
#   define DISABLE_RC5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC5_AS_ANALOG()       \
    do {                              \
      ENABLE_RC5_ANALOG();            \
      CONFIG_RC5_AS_INPUT();          \
      DISABLE_RC5_OPENDRAIN();        \
      DISABLE_RC5_PULLUP();           \
      DISABLE_RC5_PULLDOWN();         \
    } while (0)

# define CONFIG_RC5_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC5_ANALOG();           \
      CONFIG_RC5_AS_INPUT();          \
      DISABLE_RC5_OPENDRAIN();        \
      DISABLE_RC5_PULLUP();           \
      DISABLE_RC5_PULLDOWN();         \
    } while (0)

# define CONFIG_RC5_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC5_ANALOG();           \
      CONFIG_RC5_AS_OUTPUT();         \
      DISABLE_RC5_OPENDRAIN();        \
      DISABLE_RC5_PULLUP();           \
      DISABLE_RC5_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC5: Provide GPIO for RC5


// Provide GPIO for RC6
// ====================
#ifdef _RC6
# ifndef RC6_GPIO
#   warning "RC6_GPIO not defined, but pin RC6 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC6_GPIO)
# define RC6_REMAPPABLE RXY_REMAPPABLE_PIN(RC6_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC6_GPIO)
#   define ENABLE_RC6_ANALOG()  (RXY_GPIO_PCFG(RC6_GPIO) = 1)
#   define DISABLE_RC6_ANALOG() (RXY_GPIO_PCFG(RC6_GPIO) = 0)
#   define RC6_AN_PORT RXY_AN_PORT(RC6_GPIO)
# else
#   define DISABLE_RC6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC6_AS_INPUT()  (_TRISC6 = 1)
# define CONFIG_RC6_AS_OUTPUT() (_TRISC6 = 0)

// Open-drain:
#if defined(_ODCC6)
# define ENABLE_RC6_OPENDRAIN()  (_ODCC6 = 1)
# define DISABLE_RC6_OPENDRAIN() (_ODCC6 = 0)
#elif defined(_ODC6)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC6_OPENDRAIN()  (_ODC6 = 1)
# define DISABLE_RC6_OPENDRAIN() (_ODC6 = 0)
#else
# define DISABLE_RC6_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC6_GPIO)
#   define ENABLE_RC6_PULLUP()  (RXY_GPIO_CNPUE(RC6_GPIO) = 1)
#   define DISABLE_RC6_PULLUP() (RXY_GPIO_CNPUE(RC6_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC6_GPIO)
#     define ENABLE_RC6_PULLDOWN()  (RXY_GPIO_CNPDE(RC6_GPIO) = 1)
#     define DISABLE_RC6_PULLDOWN() (RXY_GPIO_CNPDE(RC6_GPIO) = 0)
#   else
#     define DISABLE_RC6_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC6_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC6_GPIO) = 1)
#   define DISABLE_RC6_CN_INTERRUPT() (RXY_GPIO_CNIE(RC6_GPIO) = 0)

# else
#   define DISABLE_RC6_PULLUP() ((void) 0)
#   define DISABLE_RC6_PULLDOWN() ((void) 0)
#   define DISABLE_RC6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC6_AS_ANALOG()       \
    do {                              \
      ENABLE_RC6_ANALOG();            \
      CONFIG_RC6_AS_INPUT();          \
      DISABLE_RC6_OPENDRAIN();        \
      DISABLE_RC6_PULLUP();           \
      DISABLE_RC6_PULLDOWN();         \
    } while (0)

# define CONFIG_RC6_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC6_ANALOG();           \
      CONFIG_RC6_AS_INPUT();          \
      DISABLE_RC6_OPENDRAIN();        \
      DISABLE_RC6_PULLUP();           \
      DISABLE_RC6_PULLDOWN();         \
    } while (0)

# define CONFIG_RC6_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC6_ANALOG();           \
      CONFIG_RC6_AS_OUTPUT();         \
      DISABLE_RC6_OPENDRAIN();        \
      DISABLE_RC6_PULLUP();           \
      DISABLE_RC6_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC6: Provide GPIO for RC6


// Provide GPIO for RC7
// ====================
#ifdef _RC7
# ifndef RC7_GPIO
#   warning "RC7_GPIO not defined, but pin RC7 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC7_GPIO)
# define RC7_REMAPPABLE RXY_REMAPPABLE_PIN(RC7_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC7_GPIO)
#   define ENABLE_RC7_ANALOG()  (RXY_GPIO_PCFG(RC7_GPIO) = 1)
#   define DISABLE_RC7_ANALOG() (RXY_GPIO_PCFG(RC7_GPIO) = 0)
#   define RC7_AN_PORT RXY_AN_PORT(RC7_GPIO)
# else
#   define DISABLE_RC7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC7_AS_INPUT()  (_TRISC7 = 1)
# define CONFIG_RC7_AS_OUTPUT() (_TRISC7 = 0)

// Open-drain:
#if defined(_ODCC7)
# define ENABLE_RC7_OPENDRAIN()  (_ODCC7 = 1)
# define DISABLE_RC7_OPENDRAIN() (_ODCC7 = 0)
#elif defined(_ODC7)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC7_OPENDRAIN()  (_ODC7 = 1)
# define DISABLE_RC7_OPENDRAIN() (_ODC7 = 0)
#else
# define DISABLE_RC7_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC7_GPIO)
#   define ENABLE_RC7_PULLUP()  (RXY_GPIO_CNPUE(RC7_GPIO) = 1)
#   define DISABLE_RC7_PULLUP() (RXY_GPIO_CNPUE(RC7_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC7_GPIO)
#     define ENABLE_RC7_PULLDOWN()  (RXY_GPIO_CNPDE(RC7_GPIO) = 1)
#     define DISABLE_RC7_PULLDOWN() (RXY_GPIO_CNPDE(RC7_GPIO) = 0)
#   else
#     define DISABLE_RC7_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC7_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC7_GPIO) = 1)
#   define DISABLE_RC7_CN_INTERRUPT() (RXY_GPIO_CNIE(RC7_GPIO) = 0)

# else
#   define DISABLE_RC7_PULLUP() ((void) 0)
#   define DISABLE_RC7_PULLDOWN() ((void) 0)
#   define DISABLE_RC7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC7_AS_ANALOG()       \
    do {                              \
      ENABLE_RC7_ANALOG();            \
      CONFIG_RC7_AS_INPUT();          \
      DISABLE_RC7_OPENDRAIN();        \
      DISABLE_RC7_PULLUP();           \
      DISABLE_RC7_PULLDOWN();         \
    } while (0)

# define CONFIG_RC7_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC7_ANALOG();           \
      CONFIG_RC7_AS_INPUT();          \
      DISABLE_RC7_OPENDRAIN();        \
      DISABLE_RC7_PULLUP();           \
      DISABLE_RC7_PULLDOWN();         \
    } while (0)

# define CONFIG_RC7_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC7_ANALOG();           \
      CONFIG_RC7_AS_OUTPUT();         \
      DISABLE_RC7_OPENDRAIN();        \
      DISABLE_RC7_PULLUP();           \
      DISABLE_RC7_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC7: Provide GPIO for RC7


// Provide GPIO for RC8
// ====================
#ifdef _RC8
# ifndef RC8_GPIO
#   warning "RC8_GPIO not defined, but pin RC8 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC8_GPIO)
# define RC8_REMAPPABLE RXY_REMAPPABLE_PIN(RC8_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC8_GPIO)
#   define ENABLE_RC8_ANALOG()  (RXY_GPIO_PCFG(RC8_GPIO) = 1)
#   define DISABLE_RC8_ANALOG() (RXY_GPIO_PCFG(RC8_GPIO) = 0)
#   define RC8_AN_PORT RXY_AN_PORT(RC8_GPIO)
# else
#   define DISABLE_RC8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC8_AS_INPUT()  (_TRISC8 = 1)
# define CONFIG_RC8_AS_OUTPUT() (_TRISC8 = 0)

// Open-drain:
#if defined(_ODCC8)
# define ENABLE_RC8_OPENDRAIN()  (_ODCC8 = 1)
# define DISABLE_RC8_OPENDRAIN() (_ODCC8 = 0)
#elif defined(_ODC8)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC8_OPENDRAIN()  (_ODC8 = 1)
# define DISABLE_RC8_OPENDRAIN() (_ODC8 = 0)
#else
# define DISABLE_RC8_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC8_GPIO)
#   define ENABLE_RC8_PULLUP()  (RXY_GPIO_CNPUE(RC8_GPIO) = 1)
#   define DISABLE_RC8_PULLUP() (RXY_GPIO_CNPUE(RC8_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC8_GPIO)
#     define ENABLE_RC8_PULLDOWN()  (RXY_GPIO_CNPDE(RC8_GPIO) = 1)
#     define DISABLE_RC8_PULLDOWN() (RXY_GPIO_CNPDE(RC8_GPIO) = 0)
#   else
#     define DISABLE_RC8_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC8_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC8_GPIO) = 1)
#   define DISABLE_RC8_CN_INTERRUPT() (RXY_GPIO_CNIE(RC8_GPIO) = 0)

# else
#   define DISABLE_RC8_PULLUP() ((void) 0)
#   define DISABLE_RC8_PULLDOWN() ((void) 0)
#   define DISABLE_RC8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC8_AS_ANALOG()       \
    do {                              \
      ENABLE_RC8_ANALOG();            \
      CONFIG_RC8_AS_INPUT();          \
      DISABLE_RC8_OPENDRAIN();        \
      DISABLE_RC8_PULLUP();           \
      DISABLE_RC8_PULLDOWN();         \
    } while (0)

# define CONFIG_RC8_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC8_ANALOG();           \
      CONFIG_RC8_AS_INPUT();          \
      DISABLE_RC8_OPENDRAIN();        \
      DISABLE_RC8_PULLUP();           \
      DISABLE_RC8_PULLDOWN();         \
    } while (0)

# define CONFIG_RC8_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC8_ANALOG();           \
      CONFIG_RC8_AS_OUTPUT();         \
      DISABLE_RC8_OPENDRAIN();        \
      DISABLE_RC8_PULLUP();           \
      DISABLE_RC8_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC8: Provide GPIO for RC8


// Provide GPIO for RC9
// ====================
#ifdef _RC9
# ifndef RC9_GPIO
#   warning "RC9_GPIO not defined, but pin RC9 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC9_GPIO)
# define RC9_REMAPPABLE RXY_REMAPPABLE_PIN(RC9_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC9_GPIO)
#   define ENABLE_RC9_ANALOG()  (RXY_GPIO_PCFG(RC9_GPIO) = 1)
#   define DISABLE_RC9_ANALOG() (RXY_GPIO_PCFG(RC9_GPIO) = 0)
#   define RC9_AN_PORT RXY_AN_PORT(RC9_GPIO)
# else
#   define DISABLE_RC9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC9_AS_INPUT()  (_TRISC9 = 1)
# define CONFIG_RC9_AS_OUTPUT() (_TRISC9 = 0)

// Open-drain:
#if defined(_ODCC9)
# define ENABLE_RC9_OPENDRAIN()  (_ODCC9 = 1)
# define DISABLE_RC9_OPENDRAIN() (_ODCC9 = 0)
#elif defined(_ODC9)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC9_OPENDRAIN()  (_ODC9 = 1)
# define DISABLE_RC9_OPENDRAIN() (_ODC9 = 0)
#else
# define DISABLE_RC9_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC9_GPIO)
#   define ENABLE_RC9_PULLUP()  (RXY_GPIO_CNPUE(RC9_GPIO) = 1)
#   define DISABLE_RC9_PULLUP() (RXY_GPIO_CNPUE(RC9_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC9_GPIO)
#     define ENABLE_RC9_PULLDOWN()  (RXY_GPIO_CNPDE(RC9_GPIO) = 1)
#     define DISABLE_RC9_PULLDOWN() (RXY_GPIO_CNPDE(RC9_GPIO) = 0)
#   else
#     define DISABLE_RC9_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC9_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC9_GPIO) = 1)
#   define DISABLE_RC9_CN_INTERRUPT() (RXY_GPIO_CNIE(RC9_GPIO) = 0)

# else
#   define DISABLE_RC9_PULLUP() ((void) 0)
#   define DISABLE_RC9_PULLDOWN() ((void) 0)
#   define DISABLE_RC9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC9_AS_ANALOG()       \
    do {                              \
      ENABLE_RC9_ANALOG();            \
      CONFIG_RC9_AS_INPUT();          \
      DISABLE_RC9_OPENDRAIN();        \
      DISABLE_RC9_PULLUP();           \
      DISABLE_RC9_PULLDOWN();         \
    } while (0)

# define CONFIG_RC9_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC9_ANALOG();           \
      CONFIG_RC9_AS_INPUT();          \
      DISABLE_RC9_OPENDRAIN();        \
      DISABLE_RC9_PULLUP();           \
      DISABLE_RC9_PULLDOWN();         \
    } while (0)

# define CONFIG_RC9_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC9_ANALOG();           \
      CONFIG_RC9_AS_OUTPUT();         \
      DISABLE_RC9_OPENDRAIN();        \
      DISABLE_RC9_PULLUP();           \
      DISABLE_RC9_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC9: Provide GPIO for RC9


// Provide GPIO for RC10
// ====================
#ifdef _RC10
# ifndef RC10_GPIO
#   warning "RC10_GPIO not defined, but pin RC10 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC10_GPIO)
# define RC10_REMAPPABLE RXY_REMAPPABLE_PIN(RC10_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC10_GPIO)
#   define ENABLE_RC10_ANALOG()  (RXY_GPIO_PCFG(RC10_GPIO) = 1)
#   define DISABLE_RC10_ANALOG() (RXY_GPIO_PCFG(RC10_GPIO) = 0)
#   define RC10_AN_PORT RXY_AN_PORT(RC10_GPIO)
# else
#   define DISABLE_RC10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC10_AS_INPUT()  (_TRISC10 = 1)
# define CONFIG_RC10_AS_OUTPUT() (_TRISC10 = 0)

// Open-drain:
#if defined(_ODCC10)
# define ENABLE_RC10_OPENDRAIN()  (_ODCC10 = 1)
# define DISABLE_RC10_OPENDRAIN() (_ODCC10 = 0)
#elif defined(_ODC10)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC10_OPENDRAIN()  (_ODC10 = 1)
# define DISABLE_RC10_OPENDRAIN() (_ODC10 = 0)
#else
# define DISABLE_RC10_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC10_GPIO)
#   define ENABLE_RC10_PULLUP()  (RXY_GPIO_CNPUE(RC10_GPIO) = 1)
#   define DISABLE_RC10_PULLUP() (RXY_GPIO_CNPUE(RC10_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC10_GPIO)
#     define ENABLE_RC10_PULLDOWN()  (RXY_GPIO_CNPDE(RC10_GPIO) = 1)
#     define DISABLE_RC10_PULLDOWN() (RXY_GPIO_CNPDE(RC10_GPIO) = 0)
#   else
#     define DISABLE_RC10_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC10_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC10_GPIO) = 1)
#   define DISABLE_RC10_CN_INTERRUPT() (RXY_GPIO_CNIE(RC10_GPIO) = 0)

# else
#   define DISABLE_RC10_PULLUP() ((void) 0)
#   define DISABLE_RC10_PULLDOWN() ((void) 0)
#   define DISABLE_RC10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC10_AS_ANALOG()       \
    do {                              \
      ENABLE_RC10_ANALOG();            \
      CONFIG_RC10_AS_INPUT();          \
      DISABLE_RC10_OPENDRAIN();        \
      DISABLE_RC10_PULLUP();           \
      DISABLE_RC10_PULLDOWN();         \
    } while (0)

# define CONFIG_RC10_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC10_ANALOG();           \
      CONFIG_RC10_AS_INPUT();          \
      DISABLE_RC10_OPENDRAIN();        \
      DISABLE_RC10_PULLUP();           \
      DISABLE_RC10_PULLDOWN();         \
    } while (0)

# define CONFIG_RC10_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC10_ANALOG();           \
      CONFIG_RC10_AS_OUTPUT();         \
      DISABLE_RC10_OPENDRAIN();        \
      DISABLE_RC10_PULLUP();           \
      DISABLE_RC10_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC10: Provide GPIO for RC10


// Provide GPIO for RC11
// ====================
#ifdef _RC11
# ifndef RC11_GPIO
#   warning "RC11_GPIO not defined, but pin RC11 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC11_GPIO)
# define RC11_REMAPPABLE RXY_REMAPPABLE_PIN(RC11_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC11_GPIO)
#   define ENABLE_RC11_ANALOG()  (RXY_GPIO_PCFG(RC11_GPIO) = 1)
#   define DISABLE_RC11_ANALOG() (RXY_GPIO_PCFG(RC11_GPIO) = 0)
#   define RC11_AN_PORT RXY_AN_PORT(RC11_GPIO)
# else
#   define DISABLE_RC11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC11_AS_INPUT()  (_TRISC11 = 1)
# define CONFIG_RC11_AS_OUTPUT() (_TRISC11 = 0)

// Open-drain:
#if defined(_ODCC11)
# define ENABLE_RC11_OPENDRAIN()  (_ODCC11 = 1)
# define DISABLE_RC11_OPENDRAIN() (_ODCC11 = 0)
#elif defined(_ODC11)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC11_OPENDRAIN()  (_ODC11 = 1)
# define DISABLE_RC11_OPENDRAIN() (_ODC11 = 0)
#else
# define DISABLE_RC11_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC11_GPIO)
#   define ENABLE_RC11_PULLUP()  (RXY_GPIO_CNPUE(RC11_GPIO) = 1)
#   define DISABLE_RC11_PULLUP() (RXY_GPIO_CNPUE(RC11_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC11_GPIO)
#     define ENABLE_RC11_PULLDOWN()  (RXY_GPIO_CNPDE(RC11_GPIO) = 1)
#     define DISABLE_RC11_PULLDOWN() (RXY_GPIO_CNPDE(RC11_GPIO) = 0)
#   else
#     define DISABLE_RC11_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC11_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC11_GPIO) = 1)
#   define DISABLE_RC11_CN_INTERRUPT() (RXY_GPIO_CNIE(RC11_GPIO) = 0)

# else
#   define DISABLE_RC11_PULLUP() ((void) 0)
#   define DISABLE_RC11_PULLDOWN() ((void) 0)
#   define DISABLE_RC11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC11_AS_ANALOG()       \
    do {                              \
      ENABLE_RC11_ANALOG();            \
      CONFIG_RC11_AS_INPUT();          \
      DISABLE_RC11_OPENDRAIN();        \
      DISABLE_RC11_PULLUP();           \
      DISABLE_RC11_PULLDOWN();         \
    } while (0)

# define CONFIG_RC11_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC11_ANALOG();           \
      CONFIG_RC11_AS_INPUT();          \
      DISABLE_RC11_OPENDRAIN();        \
      DISABLE_RC11_PULLUP();           \
      DISABLE_RC11_PULLDOWN();         \
    } while (0)

# define CONFIG_RC11_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC11_ANALOG();           \
      CONFIG_RC11_AS_OUTPUT();         \
      DISABLE_RC11_OPENDRAIN();        \
      DISABLE_RC11_PULLUP();           \
      DISABLE_RC11_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC11: Provide GPIO for RC11


// Provide GPIO for RC12
// ====================
#ifdef _RC12
# ifndef RC12_GPIO
#   warning "RC12_GPIO not defined, but pin RC12 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC12_GPIO)
# define RC12_REMAPPABLE RXY_REMAPPABLE_PIN(RC12_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC12_GPIO)
#   define ENABLE_RC12_ANALOG()  (RXY_GPIO_PCFG(RC12_GPIO) = 1)
#   define DISABLE_RC12_ANALOG() (RXY_GPIO_PCFG(RC12_GPIO) = 0)
#   define RC12_AN_PORT RXY_AN_PORT(RC12_GPIO)
# else
#   define DISABLE_RC12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC12_AS_INPUT()  (_TRISC12 = 1)
# define CONFIG_RC12_AS_OUTPUT() (_TRISC12 = 0)

// Open-drain:
#if defined(_ODCC12)
# define ENABLE_RC12_OPENDRAIN()  (_ODCC12 = 1)
# define DISABLE_RC12_OPENDRAIN() (_ODCC12 = 0)
#elif defined(_ODC12)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC12_OPENDRAIN()  (_ODC12 = 1)
# define DISABLE_RC12_OPENDRAIN() (_ODC12 = 0)
#else
# define DISABLE_RC12_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC12_GPIO)
#   define ENABLE_RC12_PULLUP()  (RXY_GPIO_CNPUE(RC12_GPIO) = 1)
#   define DISABLE_RC12_PULLUP() (RXY_GPIO_CNPUE(RC12_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC12_GPIO)
#     define ENABLE_RC12_PULLDOWN()  (RXY_GPIO_CNPDE(RC12_GPIO) = 1)
#     define DISABLE_RC12_PULLDOWN() (RXY_GPIO_CNPDE(RC12_GPIO) = 0)
#   else
#     define DISABLE_RC12_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC12_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC12_GPIO) = 1)
#   define DISABLE_RC12_CN_INTERRUPT() (RXY_GPIO_CNIE(RC12_GPIO) = 0)

# else
#   define DISABLE_RC12_PULLUP() ((void) 0)
#   define DISABLE_RC12_PULLDOWN() ((void) 0)
#   define DISABLE_RC12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC12_AS_ANALOG()       \
    do {                              \
      ENABLE_RC12_ANALOG();            \
      CONFIG_RC12_AS_INPUT();          \
      DISABLE_RC12_OPENDRAIN();        \
      DISABLE_RC12_PULLUP();           \
      DISABLE_RC12_PULLDOWN();         \
    } while (0)

# define CONFIG_RC12_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC12_ANALOG();           \
      CONFIG_RC12_AS_INPUT();          \
      DISABLE_RC12_OPENDRAIN();        \
      DISABLE_RC12_PULLUP();           \
      DISABLE_RC12_PULLDOWN();         \
    } while (0)

# define CONFIG_RC12_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC12_ANALOG();           \
      CONFIG_RC12_AS_OUTPUT();         \
      DISABLE_RC12_OPENDRAIN();        \
      DISABLE_RC12_PULLUP();           \
      DISABLE_RC12_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC12: Provide GPIO for RC12


// Provide GPIO for RC13
// ====================
#ifdef _RC13
# ifndef RC13_GPIO
#   warning "RC13_GPIO not defined, but pin RC13 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC13_GPIO)
# define RC13_REMAPPABLE RXY_REMAPPABLE_PIN(RC13_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC13_GPIO)
#   define ENABLE_RC13_ANALOG()  (RXY_GPIO_PCFG(RC13_GPIO) = 1)
#   define DISABLE_RC13_ANALOG() (RXY_GPIO_PCFG(RC13_GPIO) = 0)
#   define RC13_AN_PORT RXY_AN_PORT(RC13_GPIO)
# else
#   define DISABLE_RC13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC13_AS_INPUT()  (_TRISC13 = 1)
# define CONFIG_RC13_AS_OUTPUT() (_TRISC13 = 0)

// Open-drain:
#if defined(_ODCC13)
# define ENABLE_RC13_OPENDRAIN()  (_ODCC13 = 1)
# define DISABLE_RC13_OPENDRAIN() (_ODCC13 = 0)
#elif defined(_ODC13)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC13_OPENDRAIN()  (_ODC13 = 1)
# define DISABLE_RC13_OPENDRAIN() (_ODC13 = 0)
#else
# define DISABLE_RC13_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC13_GPIO)
#   define ENABLE_RC13_PULLUP()  (RXY_GPIO_CNPUE(RC13_GPIO) = 1)
#   define DISABLE_RC13_PULLUP() (RXY_GPIO_CNPUE(RC13_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC13_GPIO)
#     define ENABLE_RC13_PULLDOWN()  (RXY_GPIO_CNPDE(RC13_GPIO) = 1)
#     define DISABLE_RC13_PULLDOWN() (RXY_GPIO_CNPDE(RC13_GPIO) = 0)
#   else
#     define DISABLE_RC13_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC13_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC13_GPIO) = 1)
#   define DISABLE_RC13_CN_INTERRUPT() (RXY_GPIO_CNIE(RC13_GPIO) = 0)

# else
#   define DISABLE_RC13_PULLUP() ((void) 0)
#   define DISABLE_RC13_PULLDOWN() ((void) 0)
#   define DISABLE_RC13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC13_AS_ANALOG()       \
    do {                              \
      ENABLE_RC13_ANALOG();            \
      CONFIG_RC13_AS_INPUT();          \
      DISABLE_RC13_OPENDRAIN();        \
      DISABLE_RC13_PULLUP();           \
      DISABLE_RC13_PULLDOWN();         \
    } while (0)

# define CONFIG_RC13_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC13_ANALOG();           \
      CONFIG_RC13_AS_INPUT();          \
      DISABLE_RC13_OPENDRAIN();        \
      DISABLE_RC13_PULLUP();           \
      DISABLE_RC13_PULLDOWN();         \
    } while (0)

# define CONFIG_RC13_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC13_ANALOG();           \
      CONFIG_RC13_AS_OUTPUT();         \
      DISABLE_RC13_OPENDRAIN();        \
      DISABLE_RC13_PULLUP();           \
      DISABLE_RC13_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC13: Provide GPIO for RC13


// Provide GPIO for RC14
// ====================
#ifdef _RC14
# ifndef RC14_GPIO
#   warning "RC14_GPIO not defined, but pin RC14 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC14_GPIO)
# define RC14_REMAPPABLE RXY_REMAPPABLE_PIN(RC14_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC14_GPIO)
#   define ENABLE_RC14_ANALOG()  (RXY_GPIO_PCFG(RC14_GPIO) = 1)
#   define DISABLE_RC14_ANALOG() (RXY_GPIO_PCFG(RC14_GPIO) = 0)
#   define RC14_AN_PORT RXY_AN_PORT(RC14_GPIO)
# else
#   define DISABLE_RC14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC14_AS_INPUT()  (_TRISC14 = 1)
# define CONFIG_RC14_AS_OUTPUT() (_TRISC14 = 0)

// Open-drain:
#if defined(_ODCC14)
# define ENABLE_RC14_OPENDRAIN()  (_ODCC14 = 1)
# define DISABLE_RC14_OPENDRAIN() (_ODCC14 = 0)
#elif defined(_ODC14)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC14_OPENDRAIN()  (_ODC14 = 1)
# define DISABLE_RC14_OPENDRAIN() (_ODC14 = 0)
#else
# define DISABLE_RC14_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC14_GPIO)
#   define ENABLE_RC14_PULLUP()  (RXY_GPIO_CNPUE(RC14_GPIO) = 1)
#   define DISABLE_RC14_PULLUP() (RXY_GPIO_CNPUE(RC14_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC14_GPIO)
#     define ENABLE_RC14_PULLDOWN()  (RXY_GPIO_CNPDE(RC14_GPIO) = 1)
#     define DISABLE_RC14_PULLDOWN() (RXY_GPIO_CNPDE(RC14_GPIO) = 0)
#   else
#     define DISABLE_RC14_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC14_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC14_GPIO) = 1)
#   define DISABLE_RC14_CN_INTERRUPT() (RXY_GPIO_CNIE(RC14_GPIO) = 0)

# else
#   define DISABLE_RC14_PULLUP() ((void) 0)
#   define DISABLE_RC14_PULLDOWN() ((void) 0)
#   define DISABLE_RC14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC14_AS_ANALOG()       \
    do {                              \
      ENABLE_RC14_ANALOG();            \
      CONFIG_RC14_AS_INPUT();          \
      DISABLE_RC14_OPENDRAIN();        \
      DISABLE_RC14_PULLUP();           \
      DISABLE_RC14_PULLDOWN();         \
    } while (0)

# define CONFIG_RC14_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC14_ANALOG();           \
      CONFIG_RC14_AS_INPUT();          \
      DISABLE_RC14_OPENDRAIN();        \
      DISABLE_RC14_PULLUP();           \
      DISABLE_RC14_PULLDOWN();         \
    } while (0)

# define CONFIG_RC14_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC14_ANALOG();           \
      CONFIG_RC14_AS_OUTPUT();         \
      DISABLE_RC14_OPENDRAIN();        \
      DISABLE_RC14_PULLUP();           \
      DISABLE_RC14_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC14: Provide GPIO for RC14


// Provide GPIO for RC15
// ====================
#ifdef _RC15
# ifndef RC15_GPIO
#   warning "RC15_GPIO not defined, but pin RC15 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RC15_GPIO)
# define RC15_REMAPPABLE RXY_REMAPPABLE_PIN(RC15_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RC15_GPIO)
#   define ENABLE_RC15_ANALOG()  (RXY_GPIO_PCFG(RC15_GPIO) = 1)
#   define DISABLE_RC15_ANALOG() (RXY_GPIO_PCFG(RC15_GPIO) = 0)
#   define RC15_AN_PORT RXY_AN_PORT(RC15_GPIO)
# else
#   define DISABLE_RC15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC15_AS_INPUT()  (_TRISC15 = 1)
# define CONFIG_RC15_AS_OUTPUT() (_TRISC15 = 0)

// Open-drain:
#if defined(_ODCC15)
# define ENABLE_RC15_OPENDRAIN()  (_ODCC15 = 1)
# define DISABLE_RC15_OPENDRAIN() (_ODCC15 = 0)
#elif defined(_ODC15)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RC15_OPENDRAIN()  (_ODC15 = 1)
# define DISABLE_RC15_OPENDRAIN() (_ODC15 = 0)
#else
# define DISABLE_RC15_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RC15_GPIO)
#   define ENABLE_RC15_PULLUP()  (RXY_GPIO_CNPUE(RC15_GPIO) = 1)
#   define DISABLE_RC15_PULLUP() (RXY_GPIO_CNPUE(RC15_GPIO) = 0)

#   if RXY_HAS_CNPDE(RC15_GPIO)
#     define ENABLE_RC15_PULLDOWN()  (RXY_GPIO_CNPDE(RC15_GPIO) = 1)
#     define DISABLE_RC15_PULLDOWN() (RXY_GPIO_CNPDE(RC15_GPIO) = 0)
#   else
#     define DISABLE_RC15_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RC15_CN_INTERRUPT()  (RXY_GPIO_CNIE(RC15_GPIO) = 1)
#   define DISABLE_RC15_CN_INTERRUPT() (RXY_GPIO_CNIE(RC15_GPIO) = 0)

# else
#   define DISABLE_RC15_PULLUP() ((void) 0)
#   define DISABLE_RC15_PULLDOWN() ((void) 0)
#   define DISABLE_RC15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RC15_AS_ANALOG()       \
    do {                              \
      ENABLE_RC15_ANALOG();            \
      CONFIG_RC15_AS_INPUT();          \
      DISABLE_RC15_OPENDRAIN();        \
      DISABLE_RC15_PULLUP();           \
      DISABLE_RC15_PULLDOWN();         \
    } while (0)

# define CONFIG_RC15_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RC15_ANALOG();           \
      CONFIG_RC15_AS_INPUT();          \
      DISABLE_RC15_OPENDRAIN();        \
      DISABLE_RC15_PULLUP();           \
      DISABLE_RC15_PULLDOWN();         \
    } while (0)

# define CONFIG_RC15_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RC15_ANALOG();           \
      CONFIG_RC15_AS_OUTPUT();         \
      DISABLE_RC15_OPENDRAIN();        \
      DISABLE_RC15_PULLUP();           \
      DISABLE_RC15_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RC15: Provide GPIO for RC15


// Provide GPIO for RD0
// ====================
#ifdef _RD0
# ifndef RD0_GPIO
#   warning "RD0_GPIO not defined, but pin RD0 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD0_GPIO)
# define RD0_REMAPPABLE RXY_REMAPPABLE_PIN(RD0_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD0_GPIO)
#   define ENABLE_RD0_ANALOG()  (RXY_GPIO_PCFG(RD0_GPIO) = 1)
#   define DISABLE_RD0_ANALOG() (RXY_GPIO_PCFG(RD0_GPIO) = 0)
#   define RD0_AN_PORT RXY_AN_PORT(RD0_GPIO)
# else
#   define DISABLE_RD0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD0_AS_INPUT()  (_TRISD0 = 1)
# define CONFIG_RD0_AS_OUTPUT() (_TRISD0 = 0)

// Open-drain:
#if defined(_ODCD0)
# define ENABLE_RD0_OPENDRAIN()  (_ODCD0 = 1)
# define DISABLE_RD0_OPENDRAIN() (_ODCD0 = 0)
#elif defined(_ODD0)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD0_OPENDRAIN()  (_ODD0 = 1)
# define DISABLE_RD0_OPENDRAIN() (_ODD0 = 0)
#else
# define DISABLE_RD0_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD0_GPIO)
#   define ENABLE_RD0_PULLUP()  (RXY_GPIO_CNPUE(RD0_GPIO) = 1)
#   define DISABLE_RD0_PULLUP() (RXY_GPIO_CNPUE(RD0_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD0_GPIO)
#     define ENABLE_RD0_PULLDOWN()  (RXY_GPIO_CNPDE(RD0_GPIO) = 1)
#     define DISABLE_RD0_PULLDOWN() (RXY_GPIO_CNPDE(RD0_GPIO) = 0)
#   else
#     define DISABLE_RD0_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD0_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD0_GPIO) = 1)
#   define DISABLE_RD0_CN_INTERRUPT() (RXY_GPIO_CNIE(RD0_GPIO) = 0)

# else
#   define DISABLE_RD0_PULLUP() ((void) 0)
#   define DISABLE_RD0_PULLDOWN() ((void) 0)
#   define DISABLE_RD0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD0_AS_ANALOG()       \
    do {                              \
      ENABLE_RD0_ANALOG();            \
      CONFIG_RD0_AS_INPUT();          \
      DISABLE_RD0_OPENDRAIN();        \
      DISABLE_RD0_PULLUP();           \
      DISABLE_RD0_PULLDOWN();         \
    } while (0)

# define CONFIG_RD0_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD0_ANALOG();           \
      CONFIG_RD0_AS_INPUT();          \
      DISABLE_RD0_OPENDRAIN();        \
      DISABLE_RD0_PULLUP();           \
      DISABLE_RD0_PULLDOWN();         \
    } while (0)

# define CONFIG_RD0_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD0_ANALOG();           \
      CONFIG_RD0_AS_OUTPUT();         \
      DISABLE_RD0_OPENDRAIN();        \
      DISABLE_RD0_PULLUP();           \
      DISABLE_RD0_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD0: Provide GPIO for RD0


// Provide GPIO for RD1
// ====================
#ifdef _RD1
# ifndef RD1_GPIO
#   warning "RD1_GPIO not defined, but pin RD1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD1_GPIO)
# define RD1_REMAPPABLE RXY_REMAPPABLE_PIN(RD1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD1_GPIO)
#   define ENABLE_RD1_ANALOG()  (RXY_GPIO_PCFG(RD1_GPIO) = 1)
#   define DISABLE_RD1_ANALOG() (RXY_GPIO_PCFG(RD1_GPIO) = 0)
#   define RD1_AN_PORT RXY_AN_PORT(RD1_GPIO)
# else
#   define DISABLE_RD1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD1_AS_INPUT()  (_TRISD1 = 1)
# define CONFIG_RD1_AS_OUTPUT() (_TRISD1 = 0)

// Open-drain:
#if defined(_ODCD1)
# define ENABLE_RD1_OPENDRAIN()  (_ODCD1 = 1)
# define DISABLE_RD1_OPENDRAIN() (_ODCD1 = 0)
#elif defined(_ODD1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD1_OPENDRAIN()  (_ODD1 = 1)
# define DISABLE_RD1_OPENDRAIN() (_ODD1 = 0)
#else
# define DISABLE_RD1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD1_GPIO)
#   define ENABLE_RD1_PULLUP()  (RXY_GPIO_CNPUE(RD1_GPIO) = 1)
#   define DISABLE_RD1_PULLUP() (RXY_GPIO_CNPUE(RD1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD1_GPIO)
#     define ENABLE_RD1_PULLDOWN()  (RXY_GPIO_CNPDE(RD1_GPIO) = 1)
#     define DISABLE_RD1_PULLDOWN() (RXY_GPIO_CNPDE(RD1_GPIO) = 0)
#   else
#     define DISABLE_RD1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD1_GPIO) = 1)
#   define DISABLE_RD1_CN_INTERRUPT() (RXY_GPIO_CNIE(RD1_GPIO) = 0)

# else
#   define DISABLE_RD1_PULLUP() ((void) 0)
#   define DISABLE_RD1_PULLDOWN() ((void) 0)
#   define DISABLE_RD1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD1_AS_ANALOG()       \
    do {                              \
      ENABLE_RD1_ANALOG();            \
      CONFIG_RD1_AS_INPUT();          \
      DISABLE_RD1_OPENDRAIN();        \
      DISABLE_RD1_PULLUP();           \
      DISABLE_RD1_PULLDOWN();         \
    } while (0)

# define CONFIG_RD1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD1_ANALOG();           \
      CONFIG_RD1_AS_INPUT();          \
      DISABLE_RD1_OPENDRAIN();        \
      DISABLE_RD1_PULLUP();           \
      DISABLE_RD1_PULLDOWN();         \
    } while (0)

# define CONFIG_RD1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD1_ANALOG();           \
      CONFIG_RD1_AS_OUTPUT();         \
      DISABLE_RD1_OPENDRAIN();        \
      DISABLE_RD1_PULLUP();           \
      DISABLE_RD1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD1: Provide GPIO for RD1


// Provide GPIO for RD2
// ====================
#ifdef _RD2
# ifndef RD2_GPIO
#   warning "RD2_GPIO not defined, but pin RD2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD2_GPIO)
# define RD2_REMAPPABLE RXY_REMAPPABLE_PIN(RD2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD2_GPIO)
#   define ENABLE_RD2_ANALOG()  (RXY_GPIO_PCFG(RD2_GPIO) = 1)
#   define DISABLE_RD2_ANALOG() (RXY_GPIO_PCFG(RD2_GPIO) = 0)
#   define RD2_AN_PORT RXY_AN_PORT(RD2_GPIO)
# else
#   define DISABLE_RD2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD2_AS_INPUT()  (_TRISD2 = 1)
# define CONFIG_RD2_AS_OUTPUT() (_TRISD2 = 0)

// Open-drain:
#if defined(_ODCD2)
# define ENABLE_RD2_OPENDRAIN()  (_ODCD2 = 1)
# define DISABLE_RD2_OPENDRAIN() (_ODCD2 = 0)
#elif defined(_ODD2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD2_OPENDRAIN()  (_ODD2 = 1)
# define DISABLE_RD2_OPENDRAIN() (_ODD2 = 0)
#else
# define DISABLE_RD2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD2_GPIO)
#   define ENABLE_RD2_PULLUP()  (RXY_GPIO_CNPUE(RD2_GPIO) = 1)
#   define DISABLE_RD2_PULLUP() (RXY_GPIO_CNPUE(RD2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD2_GPIO)
#     define ENABLE_RD2_PULLDOWN()  (RXY_GPIO_CNPDE(RD2_GPIO) = 1)
#     define DISABLE_RD2_PULLDOWN() (RXY_GPIO_CNPDE(RD2_GPIO) = 0)
#   else
#     define DISABLE_RD2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD2_GPIO) = 1)
#   define DISABLE_RD2_CN_INTERRUPT() (RXY_GPIO_CNIE(RD2_GPIO) = 0)

# else
#   define DISABLE_RD2_PULLUP() ((void) 0)
#   define DISABLE_RD2_PULLDOWN() ((void) 0)
#   define DISABLE_RD2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD2_AS_ANALOG()       \
    do {                              \
      ENABLE_RD2_ANALOG();            \
      CONFIG_RD2_AS_INPUT();          \
      DISABLE_RD2_OPENDRAIN();        \
      DISABLE_RD2_PULLUP();           \
      DISABLE_RD2_PULLDOWN();         \
    } while (0)

# define CONFIG_RD2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD2_ANALOG();           \
      CONFIG_RD2_AS_INPUT();          \
      DISABLE_RD2_OPENDRAIN();        \
      DISABLE_RD2_PULLUP();           \
      DISABLE_RD2_PULLDOWN();         \
    } while (0)

# define CONFIG_RD2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD2_ANALOG();           \
      CONFIG_RD2_AS_OUTPUT();         \
      DISABLE_RD2_OPENDRAIN();        \
      DISABLE_RD2_PULLUP();           \
      DISABLE_RD2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD2: Provide GPIO for RD2


// Provide GPIO for RD3
// ====================
#ifdef _RD3
# ifndef RD3_GPIO
#   warning "RD3_GPIO not defined, but pin RD3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD3_GPIO)
# define RD3_REMAPPABLE RXY_REMAPPABLE_PIN(RD3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD3_GPIO)
#   define ENABLE_RD3_ANALOG()  (RXY_GPIO_PCFG(RD3_GPIO) = 1)
#   define DISABLE_RD3_ANALOG() (RXY_GPIO_PCFG(RD3_GPIO) = 0)
#   define RD3_AN_PORT RXY_AN_PORT(RD3_GPIO)
# else
#   define DISABLE_RD3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD3_AS_INPUT()  (_TRISD3 = 1)
# define CONFIG_RD3_AS_OUTPUT() (_TRISD3 = 0)

// Open-drain:
#if defined(_ODCD3)
# define ENABLE_RD3_OPENDRAIN()  (_ODCD3 = 1)
# define DISABLE_RD3_OPENDRAIN() (_ODCD3 = 0)
#elif defined(_ODD3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD3_OPENDRAIN()  (_ODD3 = 1)
# define DISABLE_RD3_OPENDRAIN() (_ODD3 = 0)
#else
# define DISABLE_RD3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD3_GPIO)
#   define ENABLE_RD3_PULLUP()  (RXY_GPIO_CNPUE(RD3_GPIO) = 1)
#   define DISABLE_RD3_PULLUP() (RXY_GPIO_CNPUE(RD3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD3_GPIO)
#     define ENABLE_RD3_PULLDOWN()  (RXY_GPIO_CNPDE(RD3_GPIO) = 1)
#     define DISABLE_RD3_PULLDOWN() (RXY_GPIO_CNPDE(RD3_GPIO) = 0)
#   else
#     define DISABLE_RD3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD3_GPIO) = 1)
#   define DISABLE_RD3_CN_INTERRUPT() (RXY_GPIO_CNIE(RD3_GPIO) = 0)

# else
#   define DISABLE_RD3_PULLUP() ((void) 0)
#   define DISABLE_RD3_PULLDOWN() ((void) 0)
#   define DISABLE_RD3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD3_AS_ANALOG()       \
    do {                              \
      ENABLE_RD3_ANALOG();            \
      CONFIG_RD3_AS_INPUT();          \
      DISABLE_RD3_OPENDRAIN();        \
      DISABLE_RD3_PULLUP();           \
      DISABLE_RD3_PULLDOWN();         \
    } while (0)

# define CONFIG_RD3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD3_ANALOG();           \
      CONFIG_RD3_AS_INPUT();          \
      DISABLE_RD3_OPENDRAIN();        \
      DISABLE_RD3_PULLUP();           \
      DISABLE_RD3_PULLDOWN();         \
    } while (0)

# define CONFIG_RD3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD3_ANALOG();           \
      CONFIG_RD3_AS_OUTPUT();         \
      DISABLE_RD3_OPENDRAIN();        \
      DISABLE_RD3_PULLUP();           \
      DISABLE_RD3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD3: Provide GPIO for RD3


// Provide GPIO for RD4
// ====================
#ifdef _RD4
# ifndef RD4_GPIO
#   warning "RD4_GPIO not defined, but pin RD4 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD4_GPIO)
# define RD4_REMAPPABLE RXY_REMAPPABLE_PIN(RD4_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD4_GPIO)
#   define ENABLE_RD4_ANALOG()  (RXY_GPIO_PCFG(RD4_GPIO) = 1)
#   define DISABLE_RD4_ANALOG() (RXY_GPIO_PCFG(RD4_GPIO) = 0)
#   define RD4_AN_PORT RXY_AN_PORT(RD4_GPIO)
# else
#   define DISABLE_RD4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD4_AS_INPUT()  (_TRISD4 = 1)
# define CONFIG_RD4_AS_OUTPUT() (_TRISD4 = 0)

// Open-drain:
#if defined(_ODCD4)
# define ENABLE_RD4_OPENDRAIN()  (_ODCD4 = 1)
# define DISABLE_RD4_OPENDRAIN() (_ODCD4 = 0)
#elif defined(_ODD4)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD4_OPENDRAIN()  (_ODD4 = 1)
# define DISABLE_RD4_OPENDRAIN() (_ODD4 = 0)
#else
# define DISABLE_RD4_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD4_GPIO)
#   define ENABLE_RD4_PULLUP()  (RXY_GPIO_CNPUE(RD4_GPIO) = 1)
#   define DISABLE_RD4_PULLUP() (RXY_GPIO_CNPUE(RD4_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD4_GPIO)
#     define ENABLE_RD4_PULLDOWN()  (RXY_GPIO_CNPDE(RD4_GPIO) = 1)
#     define DISABLE_RD4_PULLDOWN() (RXY_GPIO_CNPDE(RD4_GPIO) = 0)
#   else
#     define DISABLE_RD4_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD4_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD4_GPIO) = 1)
#   define DISABLE_RD4_CN_INTERRUPT() (RXY_GPIO_CNIE(RD4_GPIO) = 0)

# else
#   define DISABLE_RD4_PULLUP() ((void) 0)
#   define DISABLE_RD4_PULLDOWN() ((void) 0)
#   define DISABLE_RD4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD4_AS_ANALOG()       \
    do {                              \
      ENABLE_RD4_ANALOG();            \
      CONFIG_RD4_AS_INPUT();          \
      DISABLE_RD4_OPENDRAIN();        \
      DISABLE_RD4_PULLUP();           \
      DISABLE_RD4_PULLDOWN();         \
    } while (0)

# define CONFIG_RD4_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD4_ANALOG();           \
      CONFIG_RD4_AS_INPUT();          \
      DISABLE_RD4_OPENDRAIN();        \
      DISABLE_RD4_PULLUP();           \
      DISABLE_RD4_PULLDOWN();         \
    } while (0)

# define CONFIG_RD4_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD4_ANALOG();           \
      CONFIG_RD4_AS_OUTPUT();         \
      DISABLE_RD4_OPENDRAIN();        \
      DISABLE_RD4_PULLUP();           \
      DISABLE_RD4_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD4: Provide GPIO for RD4


// Provide GPIO for RD5
// ====================
#ifdef _RD5
# ifndef RD5_GPIO
#   warning "RD5_GPIO not defined, but pin RD5 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD5_GPIO)
# define RD5_REMAPPABLE RXY_REMAPPABLE_PIN(RD5_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD5_GPIO)
#   define ENABLE_RD5_ANALOG()  (RXY_GPIO_PCFG(RD5_GPIO) = 1)
#   define DISABLE_RD5_ANALOG() (RXY_GPIO_PCFG(RD5_GPIO) = 0)
#   define RD5_AN_PORT RXY_AN_PORT(RD5_GPIO)
# else
#   define DISABLE_RD5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD5_AS_INPUT()  (_TRISD5 = 1)
# define CONFIG_RD5_AS_OUTPUT() (_TRISD5 = 0)

// Open-drain:
#if defined(_ODCD5)
# define ENABLE_RD5_OPENDRAIN()  (_ODCD5 = 1)
# define DISABLE_RD5_OPENDRAIN() (_ODCD5 = 0)
#elif defined(_ODD5)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD5_OPENDRAIN()  (_ODD5 = 1)
# define DISABLE_RD5_OPENDRAIN() (_ODD5 = 0)
#else
# define DISABLE_RD5_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD5_GPIO)
#   define ENABLE_RD5_PULLUP()  (RXY_GPIO_CNPUE(RD5_GPIO) = 1)
#   define DISABLE_RD5_PULLUP() (RXY_GPIO_CNPUE(RD5_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD5_GPIO)
#     define ENABLE_RD5_PULLDOWN()  (RXY_GPIO_CNPDE(RD5_GPIO) = 1)
#     define DISABLE_RD5_PULLDOWN() (RXY_GPIO_CNPDE(RD5_GPIO) = 0)
#   else
#     define DISABLE_RD5_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD5_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD5_GPIO) = 1)
#   define DISABLE_RD5_CN_INTERRUPT() (RXY_GPIO_CNIE(RD5_GPIO) = 0)

# else
#   define DISABLE_RD5_PULLUP() ((void) 0)
#   define DISABLE_RD5_PULLDOWN() ((void) 0)
#   define DISABLE_RD5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD5_AS_ANALOG()       \
    do {                              \
      ENABLE_RD5_ANALOG();            \
      CONFIG_RD5_AS_INPUT();          \
      DISABLE_RD5_OPENDRAIN();        \
      DISABLE_RD5_PULLUP();           \
      DISABLE_RD5_PULLDOWN();         \
    } while (0)

# define CONFIG_RD5_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD5_ANALOG();           \
      CONFIG_RD5_AS_INPUT();          \
      DISABLE_RD5_OPENDRAIN();        \
      DISABLE_RD5_PULLUP();           \
      DISABLE_RD5_PULLDOWN();         \
    } while (0)

# define CONFIG_RD5_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD5_ANALOG();           \
      CONFIG_RD5_AS_OUTPUT();         \
      DISABLE_RD5_OPENDRAIN();        \
      DISABLE_RD5_PULLUP();           \
      DISABLE_RD5_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD5: Provide GPIO for RD5


// Provide GPIO for RD6
// ====================
#ifdef _RD6
# ifndef RD6_GPIO
#   warning "RD6_GPIO not defined, but pin RD6 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD6_GPIO)
# define RD6_REMAPPABLE RXY_REMAPPABLE_PIN(RD6_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD6_GPIO)
#   define ENABLE_RD6_ANALOG()  (RXY_GPIO_PCFG(RD6_GPIO) = 1)
#   define DISABLE_RD6_ANALOG() (RXY_GPIO_PCFG(RD6_GPIO) = 0)
#   define RD6_AN_PORT RXY_AN_PORT(RD6_GPIO)
# else
#   define DISABLE_RD6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD6_AS_INPUT()  (_TRISD6 = 1)
# define CONFIG_RD6_AS_OUTPUT() (_TRISD6 = 0)

// Open-drain:
#if defined(_ODCD6)
# define ENABLE_RD6_OPENDRAIN()  (_ODCD6 = 1)
# define DISABLE_RD6_OPENDRAIN() (_ODCD6 = 0)
#elif defined(_ODD6)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD6_OPENDRAIN()  (_ODD6 = 1)
# define DISABLE_RD6_OPENDRAIN() (_ODD6 = 0)
#else
# define DISABLE_RD6_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD6_GPIO)
#   define ENABLE_RD6_PULLUP()  (RXY_GPIO_CNPUE(RD6_GPIO) = 1)
#   define DISABLE_RD6_PULLUP() (RXY_GPIO_CNPUE(RD6_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD6_GPIO)
#     define ENABLE_RD6_PULLDOWN()  (RXY_GPIO_CNPDE(RD6_GPIO) = 1)
#     define DISABLE_RD6_PULLDOWN() (RXY_GPIO_CNPDE(RD6_GPIO) = 0)
#   else
#     define DISABLE_RD6_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD6_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD6_GPIO) = 1)
#   define DISABLE_RD6_CN_INTERRUPT() (RXY_GPIO_CNIE(RD6_GPIO) = 0)

# else
#   define DISABLE_RD6_PULLUP() ((void) 0)
#   define DISABLE_RD6_PULLDOWN() ((void) 0)
#   define DISABLE_RD6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD6_AS_ANALOG()       \
    do {                              \
      ENABLE_RD6_ANALOG();            \
      CONFIG_RD6_AS_INPUT();          \
      DISABLE_RD6_OPENDRAIN();        \
      DISABLE_RD6_PULLUP();           \
      DISABLE_RD6_PULLDOWN();         \
    } while (0)

# define CONFIG_RD6_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD6_ANALOG();           \
      CONFIG_RD6_AS_INPUT();          \
      DISABLE_RD6_OPENDRAIN();        \
      DISABLE_RD6_PULLUP();           \
      DISABLE_RD6_PULLDOWN();         \
    } while (0)

# define CONFIG_RD6_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD6_ANALOG();           \
      CONFIG_RD6_AS_OUTPUT();         \
      DISABLE_RD6_OPENDRAIN();        \
      DISABLE_RD6_PULLUP();           \
      DISABLE_RD6_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD6: Provide GPIO for RD6


// Provide GPIO for RD7
// ====================
#ifdef _RD7
# ifndef RD7_GPIO
#   warning "RD7_GPIO not defined, but pin RD7 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD7_GPIO)
# define RD7_REMAPPABLE RXY_REMAPPABLE_PIN(RD7_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD7_GPIO)
#   define ENABLE_RD7_ANALOG()  (RXY_GPIO_PCFG(RD7_GPIO) = 1)
#   define DISABLE_RD7_ANALOG() (RXY_GPIO_PCFG(RD7_GPIO) = 0)
#   define RD7_AN_PORT RXY_AN_PORT(RD7_GPIO)
# else
#   define DISABLE_RD7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD7_AS_INPUT()  (_TRISD7 = 1)
# define CONFIG_RD7_AS_OUTPUT() (_TRISD7 = 0)

// Open-drain:
#if defined(_ODCD7)
# define ENABLE_RD7_OPENDRAIN()  (_ODCD7 = 1)
# define DISABLE_RD7_OPENDRAIN() (_ODCD7 = 0)
#elif defined(_ODD7)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD7_OPENDRAIN()  (_ODD7 = 1)
# define DISABLE_RD7_OPENDRAIN() (_ODD7 = 0)
#else
# define DISABLE_RD7_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD7_GPIO)
#   define ENABLE_RD7_PULLUP()  (RXY_GPIO_CNPUE(RD7_GPIO) = 1)
#   define DISABLE_RD7_PULLUP() (RXY_GPIO_CNPUE(RD7_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD7_GPIO)
#     define ENABLE_RD7_PULLDOWN()  (RXY_GPIO_CNPDE(RD7_GPIO) = 1)
#     define DISABLE_RD7_PULLDOWN() (RXY_GPIO_CNPDE(RD7_GPIO) = 0)
#   else
#     define DISABLE_RD7_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD7_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD7_GPIO) = 1)
#   define DISABLE_RD7_CN_INTERRUPT() (RXY_GPIO_CNIE(RD7_GPIO) = 0)

# else
#   define DISABLE_RD7_PULLUP() ((void) 0)
#   define DISABLE_RD7_PULLDOWN() ((void) 0)
#   define DISABLE_RD7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD7_AS_ANALOG()       \
    do {                              \
      ENABLE_RD7_ANALOG();            \
      CONFIG_RD7_AS_INPUT();          \
      DISABLE_RD7_OPENDRAIN();        \
      DISABLE_RD7_PULLUP();           \
      DISABLE_RD7_PULLDOWN();         \
    } while (0)

# define CONFIG_RD7_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD7_ANALOG();           \
      CONFIG_RD7_AS_INPUT();          \
      DISABLE_RD7_OPENDRAIN();        \
      DISABLE_RD7_PULLUP();           \
      DISABLE_RD7_PULLDOWN();         \
    } while (0)

# define CONFIG_RD7_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD7_ANALOG();           \
      CONFIG_RD7_AS_OUTPUT();         \
      DISABLE_RD7_OPENDRAIN();        \
      DISABLE_RD7_PULLUP();           \
      DISABLE_RD7_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD7: Provide GPIO for RD7


// Provide GPIO for RD8
// ====================
#ifdef _RD8
# ifndef RD8_GPIO
#   warning "RD8_GPIO not defined, but pin RD8 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD8_GPIO)
# define RD8_REMAPPABLE RXY_REMAPPABLE_PIN(RD8_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD8_GPIO)
#   define ENABLE_RD8_ANALOG()  (RXY_GPIO_PCFG(RD8_GPIO) = 1)
#   define DISABLE_RD8_ANALOG() (RXY_GPIO_PCFG(RD8_GPIO) = 0)
#   define RD8_AN_PORT RXY_AN_PORT(RD8_GPIO)
# else
#   define DISABLE_RD8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD8_AS_INPUT()  (_TRISD8 = 1)
# define CONFIG_RD8_AS_OUTPUT() (_TRISD8 = 0)

// Open-drain:
#if defined(_ODCD8)
# define ENABLE_RD8_OPENDRAIN()  (_ODCD8 = 1)
# define DISABLE_RD8_OPENDRAIN() (_ODCD8 = 0)
#elif defined(_ODD8)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD8_OPENDRAIN()  (_ODD8 = 1)
# define DISABLE_RD8_OPENDRAIN() (_ODD8 = 0)
#else
# define DISABLE_RD8_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD8_GPIO)
#   define ENABLE_RD8_PULLUP()  (RXY_GPIO_CNPUE(RD8_GPIO) = 1)
#   define DISABLE_RD8_PULLUP() (RXY_GPIO_CNPUE(RD8_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD8_GPIO)
#     define ENABLE_RD8_PULLDOWN()  (RXY_GPIO_CNPDE(RD8_GPIO) = 1)
#     define DISABLE_RD8_PULLDOWN() (RXY_GPIO_CNPDE(RD8_GPIO) = 0)
#   else
#     define DISABLE_RD8_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD8_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD8_GPIO) = 1)
#   define DISABLE_RD8_CN_INTERRUPT() (RXY_GPIO_CNIE(RD8_GPIO) = 0)

# else
#   define DISABLE_RD8_PULLUP() ((void) 0)
#   define DISABLE_RD8_PULLDOWN() ((void) 0)
#   define DISABLE_RD8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD8_AS_ANALOG()       \
    do {                              \
      ENABLE_RD8_ANALOG();            \
      CONFIG_RD8_AS_INPUT();          \
      DISABLE_RD8_OPENDRAIN();        \
      DISABLE_RD8_PULLUP();           \
      DISABLE_RD8_PULLDOWN();         \
    } while (0)

# define CONFIG_RD8_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD8_ANALOG();           \
      CONFIG_RD8_AS_INPUT();          \
      DISABLE_RD8_OPENDRAIN();        \
      DISABLE_RD8_PULLUP();           \
      DISABLE_RD8_PULLDOWN();         \
    } while (0)

# define CONFIG_RD8_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD8_ANALOG();           \
      CONFIG_RD8_AS_OUTPUT();         \
      DISABLE_RD8_OPENDRAIN();        \
      DISABLE_RD8_PULLUP();           \
      DISABLE_RD8_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD8: Provide GPIO for RD8


// Provide GPIO for RD9
// ====================
#ifdef _RD9
# ifndef RD9_GPIO
#   warning "RD9_GPIO not defined, but pin RD9 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD9_GPIO)
# define RD9_REMAPPABLE RXY_REMAPPABLE_PIN(RD9_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD9_GPIO)
#   define ENABLE_RD9_ANALOG()  (RXY_GPIO_PCFG(RD9_GPIO) = 1)
#   define DISABLE_RD9_ANALOG() (RXY_GPIO_PCFG(RD9_GPIO) = 0)
#   define RD9_AN_PORT RXY_AN_PORT(RD9_GPIO)
# else
#   define DISABLE_RD9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD9_AS_INPUT()  (_TRISD9 = 1)
# define CONFIG_RD9_AS_OUTPUT() (_TRISD9 = 0)

// Open-drain:
#if defined(_ODCD9)
# define ENABLE_RD9_OPENDRAIN()  (_ODCD9 = 1)
# define DISABLE_RD9_OPENDRAIN() (_ODCD9 = 0)
#elif defined(_ODD9)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD9_OPENDRAIN()  (_ODD9 = 1)
# define DISABLE_RD9_OPENDRAIN() (_ODD9 = 0)
#else
# define DISABLE_RD9_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD9_GPIO)
#   define ENABLE_RD9_PULLUP()  (RXY_GPIO_CNPUE(RD9_GPIO) = 1)
#   define DISABLE_RD9_PULLUP() (RXY_GPIO_CNPUE(RD9_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD9_GPIO)
#     define ENABLE_RD9_PULLDOWN()  (RXY_GPIO_CNPDE(RD9_GPIO) = 1)
#     define DISABLE_RD9_PULLDOWN() (RXY_GPIO_CNPDE(RD9_GPIO) = 0)
#   else
#     define DISABLE_RD9_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD9_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD9_GPIO) = 1)
#   define DISABLE_RD9_CN_INTERRUPT() (RXY_GPIO_CNIE(RD9_GPIO) = 0)

# else
#   define DISABLE_RD9_PULLUP() ((void) 0)
#   define DISABLE_RD9_PULLDOWN() ((void) 0)
#   define DISABLE_RD9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD9_AS_ANALOG()       \
    do {                              \
      ENABLE_RD9_ANALOG();            \
      CONFIG_RD9_AS_INPUT();          \
      DISABLE_RD9_OPENDRAIN();        \
      DISABLE_RD9_PULLUP();           \
      DISABLE_RD9_PULLDOWN();         \
    } while (0)

# define CONFIG_RD9_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD9_ANALOG();           \
      CONFIG_RD9_AS_INPUT();          \
      DISABLE_RD9_OPENDRAIN();        \
      DISABLE_RD9_PULLUP();           \
      DISABLE_RD9_PULLDOWN();         \
    } while (0)

# define CONFIG_RD9_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD9_ANALOG();           \
      CONFIG_RD9_AS_OUTPUT();         \
      DISABLE_RD9_OPENDRAIN();        \
      DISABLE_RD9_PULLUP();           \
      DISABLE_RD9_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD9: Provide GPIO for RD9


// Provide GPIO for RD10
// ====================
#ifdef _RD10
# ifndef RD10_GPIO
#   warning "RD10_GPIO not defined, but pin RD10 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD10_GPIO)
# define RD10_REMAPPABLE RXY_REMAPPABLE_PIN(RD10_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD10_GPIO)
#   define ENABLE_RD10_ANALOG()  (RXY_GPIO_PCFG(RD10_GPIO) = 1)
#   define DISABLE_RD10_ANALOG() (RXY_GPIO_PCFG(RD10_GPIO) = 0)
#   define RD10_AN_PORT RXY_AN_PORT(RD10_GPIO)
# else
#   define DISABLE_RD10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD10_AS_INPUT()  (_TRISD10 = 1)
# define CONFIG_RD10_AS_OUTPUT() (_TRISD10 = 0)

// Open-drain:
#if defined(_ODCD10)
# define ENABLE_RD10_OPENDRAIN()  (_ODCD10 = 1)
# define DISABLE_RD10_OPENDRAIN() (_ODCD10 = 0)
#elif defined(_ODD10)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD10_OPENDRAIN()  (_ODD10 = 1)
# define DISABLE_RD10_OPENDRAIN() (_ODD10 = 0)
#else
# define DISABLE_RD10_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD10_GPIO)
#   define ENABLE_RD10_PULLUP()  (RXY_GPIO_CNPUE(RD10_GPIO) = 1)
#   define DISABLE_RD10_PULLUP() (RXY_GPIO_CNPUE(RD10_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD10_GPIO)
#     define ENABLE_RD10_PULLDOWN()  (RXY_GPIO_CNPDE(RD10_GPIO) = 1)
#     define DISABLE_RD10_PULLDOWN() (RXY_GPIO_CNPDE(RD10_GPIO) = 0)
#   else
#     define DISABLE_RD10_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD10_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD10_GPIO) = 1)
#   define DISABLE_RD10_CN_INTERRUPT() (RXY_GPIO_CNIE(RD10_GPIO) = 0)

# else
#   define DISABLE_RD10_PULLUP() ((void) 0)
#   define DISABLE_RD10_PULLDOWN() ((void) 0)
#   define DISABLE_RD10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD10_AS_ANALOG()       \
    do {                              \
      ENABLE_RD10_ANALOG();            \
      CONFIG_RD10_AS_INPUT();          \
      DISABLE_RD10_OPENDRAIN();        \
      DISABLE_RD10_PULLUP();           \
      DISABLE_RD10_PULLDOWN();         \
    } while (0)

# define CONFIG_RD10_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD10_ANALOG();           \
      CONFIG_RD10_AS_INPUT();          \
      DISABLE_RD10_OPENDRAIN();        \
      DISABLE_RD10_PULLUP();           \
      DISABLE_RD10_PULLDOWN();         \
    } while (0)

# define CONFIG_RD10_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD10_ANALOG();           \
      CONFIG_RD10_AS_OUTPUT();         \
      DISABLE_RD10_OPENDRAIN();        \
      DISABLE_RD10_PULLUP();           \
      DISABLE_RD10_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD10: Provide GPIO for RD10


// Provide GPIO for RD11
// ====================
#ifdef _RD11
# ifndef RD11_GPIO
#   warning "RD11_GPIO not defined, but pin RD11 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD11_GPIO)
# define RD11_REMAPPABLE RXY_REMAPPABLE_PIN(RD11_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD11_GPIO)
#   define ENABLE_RD11_ANALOG()  (RXY_GPIO_PCFG(RD11_GPIO) = 1)
#   define DISABLE_RD11_ANALOG() (RXY_GPIO_PCFG(RD11_GPIO) = 0)
#   define RD11_AN_PORT RXY_AN_PORT(RD11_GPIO)
# else
#   define DISABLE_RD11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD11_AS_INPUT()  (_TRISD11 = 1)
# define CONFIG_RD11_AS_OUTPUT() (_TRISD11 = 0)

// Open-drain:
#if defined(_ODCD11)
# define ENABLE_RD11_OPENDRAIN()  (_ODCD11 = 1)
# define DISABLE_RD11_OPENDRAIN() (_ODCD11 = 0)
#elif defined(_ODD11)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD11_OPENDRAIN()  (_ODD11 = 1)
# define DISABLE_RD11_OPENDRAIN() (_ODD11 = 0)
#else
# define DISABLE_RD11_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD11_GPIO)
#   define ENABLE_RD11_PULLUP()  (RXY_GPIO_CNPUE(RD11_GPIO) = 1)
#   define DISABLE_RD11_PULLUP() (RXY_GPIO_CNPUE(RD11_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD11_GPIO)
#     define ENABLE_RD11_PULLDOWN()  (RXY_GPIO_CNPDE(RD11_GPIO) = 1)
#     define DISABLE_RD11_PULLDOWN() (RXY_GPIO_CNPDE(RD11_GPIO) = 0)
#   else
#     define DISABLE_RD11_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD11_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD11_GPIO) = 1)
#   define DISABLE_RD11_CN_INTERRUPT() (RXY_GPIO_CNIE(RD11_GPIO) = 0)

# else
#   define DISABLE_RD11_PULLUP() ((void) 0)
#   define DISABLE_RD11_PULLDOWN() ((void) 0)
#   define DISABLE_RD11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD11_AS_ANALOG()       \
    do {                              \
      ENABLE_RD11_ANALOG();            \
      CONFIG_RD11_AS_INPUT();          \
      DISABLE_RD11_OPENDRAIN();        \
      DISABLE_RD11_PULLUP();           \
      DISABLE_RD11_PULLDOWN();         \
    } while (0)

# define CONFIG_RD11_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD11_ANALOG();           \
      CONFIG_RD11_AS_INPUT();          \
      DISABLE_RD11_OPENDRAIN();        \
      DISABLE_RD11_PULLUP();           \
      DISABLE_RD11_PULLDOWN();         \
    } while (0)

# define CONFIG_RD11_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD11_ANALOG();           \
      CONFIG_RD11_AS_OUTPUT();         \
      DISABLE_RD11_OPENDRAIN();        \
      DISABLE_RD11_PULLUP();           \
      DISABLE_RD11_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD11: Provide GPIO for RD11


// Provide GPIO for RD12
// ====================
#ifdef _RD12
# ifndef RD12_GPIO
#   warning "RD12_GPIO not defined, but pin RD12 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD12_GPIO)
# define RD12_REMAPPABLE RXY_REMAPPABLE_PIN(RD12_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD12_GPIO)
#   define ENABLE_RD12_ANALOG()  (RXY_GPIO_PCFG(RD12_GPIO) = 1)
#   define DISABLE_RD12_ANALOG() (RXY_GPIO_PCFG(RD12_GPIO) = 0)
#   define RD12_AN_PORT RXY_AN_PORT(RD12_GPIO)
# else
#   define DISABLE_RD12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD12_AS_INPUT()  (_TRISD12 = 1)
# define CONFIG_RD12_AS_OUTPUT() (_TRISD12 = 0)

// Open-drain:
#if defined(_ODCD12)
# define ENABLE_RD12_OPENDRAIN()  (_ODCD12 = 1)
# define DISABLE_RD12_OPENDRAIN() (_ODCD12 = 0)
#elif defined(_ODD12)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD12_OPENDRAIN()  (_ODD12 = 1)
# define DISABLE_RD12_OPENDRAIN() (_ODD12 = 0)
#else
# define DISABLE_RD12_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD12_GPIO)
#   define ENABLE_RD12_PULLUP()  (RXY_GPIO_CNPUE(RD12_GPIO) = 1)
#   define DISABLE_RD12_PULLUP() (RXY_GPIO_CNPUE(RD12_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD12_GPIO)
#     define ENABLE_RD12_PULLDOWN()  (RXY_GPIO_CNPDE(RD12_GPIO) = 1)
#     define DISABLE_RD12_PULLDOWN() (RXY_GPIO_CNPDE(RD12_GPIO) = 0)
#   else
#     define DISABLE_RD12_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD12_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD12_GPIO) = 1)
#   define DISABLE_RD12_CN_INTERRUPT() (RXY_GPIO_CNIE(RD12_GPIO) = 0)

# else
#   define DISABLE_RD12_PULLUP() ((void) 0)
#   define DISABLE_RD12_PULLDOWN() ((void) 0)
#   define DISABLE_RD12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD12_AS_ANALOG()       \
    do {                              \
      ENABLE_RD12_ANALOG();            \
      CONFIG_RD12_AS_INPUT();          \
      DISABLE_RD12_OPENDRAIN();        \
      DISABLE_RD12_PULLUP();           \
      DISABLE_RD12_PULLDOWN();         \
    } while (0)

# define CONFIG_RD12_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD12_ANALOG();           \
      CONFIG_RD12_AS_INPUT();          \
      DISABLE_RD12_OPENDRAIN();        \
      DISABLE_RD12_PULLUP();           \
      DISABLE_RD12_PULLDOWN();         \
    } while (0)

# define CONFIG_RD12_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD12_ANALOG();           \
      CONFIG_RD12_AS_OUTPUT();         \
      DISABLE_RD12_OPENDRAIN();        \
      DISABLE_RD12_PULLUP();           \
      DISABLE_RD12_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD12: Provide GPIO for RD12


// Provide GPIO for RD13
// ====================
#ifdef _RD13
# ifndef RD13_GPIO
#   warning "RD13_GPIO not defined, but pin RD13 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD13_GPIO)
# define RD13_REMAPPABLE RXY_REMAPPABLE_PIN(RD13_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD13_GPIO)
#   define ENABLE_RD13_ANALOG()  (RXY_GPIO_PCFG(RD13_GPIO) = 1)
#   define DISABLE_RD13_ANALOG() (RXY_GPIO_PCFG(RD13_GPIO) = 0)
#   define RD13_AN_PORT RXY_AN_PORT(RD13_GPIO)
# else
#   define DISABLE_RD13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD13_AS_INPUT()  (_TRISD13 = 1)
# define CONFIG_RD13_AS_OUTPUT() (_TRISD13 = 0)

// Open-drain:
#if defined(_ODCD13)
# define ENABLE_RD13_OPENDRAIN()  (_ODCD13 = 1)
# define DISABLE_RD13_OPENDRAIN() (_ODCD13 = 0)
#elif defined(_ODD13)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD13_OPENDRAIN()  (_ODD13 = 1)
# define DISABLE_RD13_OPENDRAIN() (_ODD13 = 0)
#else
# define DISABLE_RD13_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD13_GPIO)
#   define ENABLE_RD13_PULLUP()  (RXY_GPIO_CNPUE(RD13_GPIO) = 1)
#   define DISABLE_RD13_PULLUP() (RXY_GPIO_CNPUE(RD13_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD13_GPIO)
#     define ENABLE_RD13_PULLDOWN()  (RXY_GPIO_CNPDE(RD13_GPIO) = 1)
#     define DISABLE_RD13_PULLDOWN() (RXY_GPIO_CNPDE(RD13_GPIO) = 0)
#   else
#     define DISABLE_RD13_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD13_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD13_GPIO) = 1)
#   define DISABLE_RD13_CN_INTERRUPT() (RXY_GPIO_CNIE(RD13_GPIO) = 0)

# else
#   define DISABLE_RD13_PULLUP() ((void) 0)
#   define DISABLE_RD13_PULLDOWN() ((void) 0)
#   define DISABLE_RD13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD13_AS_ANALOG()       \
    do {                              \
      ENABLE_RD13_ANALOG();            \
      CONFIG_RD13_AS_INPUT();          \
      DISABLE_RD13_OPENDRAIN();        \
      DISABLE_RD13_PULLUP();           \
      DISABLE_RD13_PULLDOWN();         \
    } while (0)

# define CONFIG_RD13_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD13_ANALOG();           \
      CONFIG_RD13_AS_INPUT();          \
      DISABLE_RD13_OPENDRAIN();        \
      DISABLE_RD13_PULLUP();           \
      DISABLE_RD13_PULLDOWN();         \
    } while (0)

# define CONFIG_RD13_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD13_ANALOG();           \
      CONFIG_RD13_AS_OUTPUT();         \
      DISABLE_RD13_OPENDRAIN();        \
      DISABLE_RD13_PULLUP();           \
      DISABLE_RD13_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD13: Provide GPIO for RD13


// Provide GPIO for RD14
// ====================
#ifdef _RD14
# ifndef RD14_GPIO
#   warning "RD14_GPIO not defined, but pin RD14 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD14_GPIO)
# define RD14_REMAPPABLE RXY_REMAPPABLE_PIN(RD14_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD14_GPIO)
#   define ENABLE_RD14_ANALOG()  (RXY_GPIO_PCFG(RD14_GPIO) = 1)
#   define DISABLE_RD14_ANALOG() (RXY_GPIO_PCFG(RD14_GPIO) = 0)
#   define RD14_AN_PORT RXY_AN_PORT(RD14_GPIO)
# else
#   define DISABLE_RD14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD14_AS_INPUT()  (_TRISD14 = 1)
# define CONFIG_RD14_AS_OUTPUT() (_TRISD14 = 0)

// Open-drain:
#if defined(_ODCD14)
# define ENABLE_RD14_OPENDRAIN()  (_ODCD14 = 1)
# define DISABLE_RD14_OPENDRAIN() (_ODCD14 = 0)
#elif defined(_ODD14)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD14_OPENDRAIN()  (_ODD14 = 1)
# define DISABLE_RD14_OPENDRAIN() (_ODD14 = 0)
#else
# define DISABLE_RD14_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD14_GPIO)
#   define ENABLE_RD14_PULLUP()  (RXY_GPIO_CNPUE(RD14_GPIO) = 1)
#   define DISABLE_RD14_PULLUP() (RXY_GPIO_CNPUE(RD14_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD14_GPIO)
#     define ENABLE_RD14_PULLDOWN()  (RXY_GPIO_CNPDE(RD14_GPIO) = 1)
#     define DISABLE_RD14_PULLDOWN() (RXY_GPIO_CNPDE(RD14_GPIO) = 0)
#   else
#     define DISABLE_RD14_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD14_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD14_GPIO) = 1)
#   define DISABLE_RD14_CN_INTERRUPT() (RXY_GPIO_CNIE(RD14_GPIO) = 0)

# else
#   define DISABLE_RD14_PULLUP() ((void) 0)
#   define DISABLE_RD14_PULLDOWN() ((void) 0)
#   define DISABLE_RD14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD14_AS_ANALOG()       \
    do {                              \
      ENABLE_RD14_ANALOG();            \
      CONFIG_RD14_AS_INPUT();          \
      DISABLE_RD14_OPENDRAIN();        \
      DISABLE_RD14_PULLUP();           \
      DISABLE_RD14_PULLDOWN();         \
    } while (0)

# define CONFIG_RD14_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD14_ANALOG();           \
      CONFIG_RD14_AS_INPUT();          \
      DISABLE_RD14_OPENDRAIN();        \
      DISABLE_RD14_PULLUP();           \
      DISABLE_RD14_PULLDOWN();         \
    } while (0)

# define CONFIG_RD14_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD14_ANALOG();           \
      CONFIG_RD14_AS_OUTPUT();         \
      DISABLE_RD14_OPENDRAIN();        \
      DISABLE_RD14_PULLUP();           \
      DISABLE_RD14_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD14: Provide GPIO for RD14


// Provide GPIO for RD15
// ====================
#ifdef _RD15
# ifndef RD15_GPIO
#   warning "RD15_GPIO not defined, but pin RD15 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RD15_GPIO)
# define RD15_REMAPPABLE RXY_REMAPPABLE_PIN(RD15_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RD15_GPIO)
#   define ENABLE_RD15_ANALOG()  (RXY_GPIO_PCFG(RD15_GPIO) = 1)
#   define DISABLE_RD15_ANALOG() (RXY_GPIO_PCFG(RD15_GPIO) = 0)
#   define RD15_AN_PORT RXY_AN_PORT(RD15_GPIO)
# else
#   define DISABLE_RD15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD15_AS_INPUT()  (_TRISD15 = 1)
# define CONFIG_RD15_AS_OUTPUT() (_TRISD15 = 0)

// Open-drain:
#if defined(_ODCD15)
# define ENABLE_RD15_OPENDRAIN()  (_ODCD15 = 1)
# define DISABLE_RD15_OPENDRAIN() (_ODCD15 = 0)
#elif defined(_ODD15)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RD15_OPENDRAIN()  (_ODD15 = 1)
# define DISABLE_RD15_OPENDRAIN() (_ODD15 = 0)
#else
# define DISABLE_RD15_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RD15_GPIO)
#   define ENABLE_RD15_PULLUP()  (RXY_GPIO_CNPUE(RD15_GPIO) = 1)
#   define DISABLE_RD15_PULLUP() (RXY_GPIO_CNPUE(RD15_GPIO) = 0)

#   if RXY_HAS_CNPDE(RD15_GPIO)
#     define ENABLE_RD15_PULLDOWN()  (RXY_GPIO_CNPDE(RD15_GPIO) = 1)
#     define DISABLE_RD15_PULLDOWN() (RXY_GPIO_CNPDE(RD15_GPIO) = 0)
#   else
#     define DISABLE_RD15_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RD15_CN_INTERRUPT()  (RXY_GPIO_CNIE(RD15_GPIO) = 1)
#   define DISABLE_RD15_CN_INTERRUPT() (RXY_GPIO_CNIE(RD15_GPIO) = 0)

# else
#   define DISABLE_RD15_PULLUP() ((void) 0)
#   define DISABLE_RD15_PULLDOWN() ((void) 0)
#   define DISABLE_RD15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RD15_AS_ANALOG()       \
    do {                              \
      ENABLE_RD15_ANALOG();            \
      CONFIG_RD15_AS_INPUT();          \
      DISABLE_RD15_OPENDRAIN();        \
      DISABLE_RD15_PULLUP();           \
      DISABLE_RD15_PULLDOWN();         \
    } while (0)

# define CONFIG_RD15_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RD15_ANALOG();           \
      CONFIG_RD15_AS_INPUT();          \
      DISABLE_RD15_OPENDRAIN();        \
      DISABLE_RD15_PULLUP();           \
      DISABLE_RD15_PULLDOWN();         \
    } while (0)

# define CONFIG_RD15_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RD15_ANALOG();           \
      CONFIG_RD15_AS_OUTPUT();         \
      DISABLE_RD15_OPENDRAIN();        \
      DISABLE_RD15_PULLUP();           \
      DISABLE_RD15_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RD15: Provide GPIO for RD15


// Provide GPIO for RE0
// ====================
#ifdef _RE0
# ifndef RE0_GPIO
#   warning "RE0_GPIO not defined, but pin RE0 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE0_GPIO)
# define RE0_REMAPPABLE RXY_REMAPPABLE_PIN(RE0_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE0_GPIO)
#   define ENABLE_RE0_ANALOG()  (RXY_GPIO_PCFG(RE0_GPIO) = 1)
#   define DISABLE_RE0_ANALOG() (RXY_GPIO_PCFG(RE0_GPIO) = 0)
#   define RE0_AN_PORT RXY_AN_PORT(RE0_GPIO)
# else
#   define DISABLE_RE0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE0_AS_INPUT()  (_TRISE0 = 1)
# define CONFIG_RE0_AS_OUTPUT() (_TRISE0 = 0)

// Open-drain:
#if defined(_ODCE0)
# define ENABLE_RE0_OPENDRAIN()  (_ODCE0 = 1)
# define DISABLE_RE0_OPENDRAIN() (_ODCE0 = 0)
#elif defined(_ODE0)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE0_OPENDRAIN()  (_ODE0 = 1)
# define DISABLE_RE0_OPENDRAIN() (_ODE0 = 0)
#else
# define DISABLE_RE0_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE0_GPIO)
#   define ENABLE_RE0_PULLUP()  (RXY_GPIO_CNPUE(RE0_GPIO) = 1)
#   define DISABLE_RE0_PULLUP() (RXY_GPIO_CNPUE(RE0_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE0_GPIO)
#     define ENABLE_RE0_PULLDOWN()  (RXY_GPIO_CNPDE(RE0_GPIO) = 1)
#     define DISABLE_RE0_PULLDOWN() (RXY_GPIO_CNPDE(RE0_GPIO) = 0)
#   else
#     define DISABLE_RE0_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE0_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE0_GPIO) = 1)
#   define DISABLE_RE0_CN_INTERRUPT() (RXY_GPIO_CNIE(RE0_GPIO) = 0)

# else
#   define DISABLE_RE0_PULLUP() ((void) 0)
#   define DISABLE_RE0_PULLDOWN() ((void) 0)
#   define DISABLE_RE0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE0_AS_ANALOG()       \
    do {                              \
      ENABLE_RE0_ANALOG();            \
      CONFIG_RE0_AS_INPUT();          \
      DISABLE_RE0_OPENDRAIN();        \
      DISABLE_RE0_PULLUP();           \
      DISABLE_RE0_PULLDOWN();         \
    } while (0)

# define CONFIG_RE0_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE0_ANALOG();           \
      CONFIG_RE0_AS_INPUT();          \
      DISABLE_RE0_OPENDRAIN();        \
      DISABLE_RE0_PULLUP();           \
      DISABLE_RE0_PULLDOWN();         \
    } while (0)

# define CONFIG_RE0_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE0_ANALOG();           \
      CONFIG_RE0_AS_OUTPUT();         \
      DISABLE_RE0_OPENDRAIN();        \
      DISABLE_RE0_PULLUP();           \
      DISABLE_RE0_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE0: Provide GPIO for RE0


// Provide GPIO for RE1
// ====================
#ifdef _RE1
# ifndef RE1_GPIO
#   warning "RE1_GPIO not defined, but pin RE1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE1_GPIO)
# define RE1_REMAPPABLE RXY_REMAPPABLE_PIN(RE1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE1_GPIO)
#   define ENABLE_RE1_ANALOG()  (RXY_GPIO_PCFG(RE1_GPIO) = 1)
#   define DISABLE_RE1_ANALOG() (RXY_GPIO_PCFG(RE1_GPIO) = 0)
#   define RE1_AN_PORT RXY_AN_PORT(RE1_GPIO)
# else
#   define DISABLE_RE1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE1_AS_INPUT()  (_TRISE1 = 1)
# define CONFIG_RE1_AS_OUTPUT() (_TRISE1 = 0)

// Open-drain:
#if defined(_ODCE1)
# define ENABLE_RE1_OPENDRAIN()  (_ODCE1 = 1)
# define DISABLE_RE1_OPENDRAIN() (_ODCE1 = 0)
#elif defined(_ODE1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE1_OPENDRAIN()  (_ODE1 = 1)
# define DISABLE_RE1_OPENDRAIN() (_ODE1 = 0)
#else
# define DISABLE_RE1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE1_GPIO)
#   define ENABLE_RE1_PULLUP()  (RXY_GPIO_CNPUE(RE1_GPIO) = 1)
#   define DISABLE_RE1_PULLUP() (RXY_GPIO_CNPUE(RE1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE1_GPIO)
#     define ENABLE_RE1_PULLDOWN()  (RXY_GPIO_CNPDE(RE1_GPIO) = 1)
#     define DISABLE_RE1_PULLDOWN() (RXY_GPIO_CNPDE(RE1_GPIO) = 0)
#   else
#     define DISABLE_RE1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE1_GPIO) = 1)
#   define DISABLE_RE1_CN_INTERRUPT() (RXY_GPIO_CNIE(RE1_GPIO) = 0)

# else
#   define DISABLE_RE1_PULLUP() ((void) 0)
#   define DISABLE_RE1_PULLDOWN() ((void) 0)
#   define DISABLE_RE1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE1_AS_ANALOG()       \
    do {                              \
      ENABLE_RE1_ANALOG();            \
      CONFIG_RE1_AS_INPUT();          \
      DISABLE_RE1_OPENDRAIN();        \
      DISABLE_RE1_PULLUP();           \
      DISABLE_RE1_PULLDOWN();         \
    } while (0)

# define CONFIG_RE1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE1_ANALOG();           \
      CONFIG_RE1_AS_INPUT();          \
      DISABLE_RE1_OPENDRAIN();        \
      DISABLE_RE1_PULLUP();           \
      DISABLE_RE1_PULLDOWN();         \
    } while (0)

# define CONFIG_RE1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE1_ANALOG();           \
      CONFIG_RE1_AS_OUTPUT();         \
      DISABLE_RE1_OPENDRAIN();        \
      DISABLE_RE1_PULLUP();           \
      DISABLE_RE1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE1: Provide GPIO for RE1


// Provide GPIO for RE2
// ====================
#ifdef _RE2
# ifndef RE2_GPIO
#   warning "RE2_GPIO not defined, but pin RE2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE2_GPIO)
# define RE2_REMAPPABLE RXY_REMAPPABLE_PIN(RE2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE2_GPIO)
#   define ENABLE_RE2_ANALOG()  (RXY_GPIO_PCFG(RE2_GPIO) = 1)
#   define DISABLE_RE2_ANALOG() (RXY_GPIO_PCFG(RE2_GPIO) = 0)
#   define RE2_AN_PORT RXY_AN_PORT(RE2_GPIO)
# else
#   define DISABLE_RE2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE2_AS_INPUT()  (_TRISE2 = 1)
# define CONFIG_RE2_AS_OUTPUT() (_TRISE2 = 0)

// Open-drain:
#if defined(_ODCE2)
# define ENABLE_RE2_OPENDRAIN()  (_ODCE2 = 1)
# define DISABLE_RE2_OPENDRAIN() (_ODCE2 = 0)
#elif defined(_ODE2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE2_OPENDRAIN()  (_ODE2 = 1)
# define DISABLE_RE2_OPENDRAIN() (_ODE2 = 0)
#else
# define DISABLE_RE2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE2_GPIO)
#   define ENABLE_RE2_PULLUP()  (RXY_GPIO_CNPUE(RE2_GPIO) = 1)
#   define DISABLE_RE2_PULLUP() (RXY_GPIO_CNPUE(RE2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE2_GPIO)
#     define ENABLE_RE2_PULLDOWN()  (RXY_GPIO_CNPDE(RE2_GPIO) = 1)
#     define DISABLE_RE2_PULLDOWN() (RXY_GPIO_CNPDE(RE2_GPIO) = 0)
#   else
#     define DISABLE_RE2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE2_GPIO) = 1)
#   define DISABLE_RE2_CN_INTERRUPT() (RXY_GPIO_CNIE(RE2_GPIO) = 0)

# else
#   define DISABLE_RE2_PULLUP() ((void) 0)
#   define DISABLE_RE2_PULLDOWN() ((void) 0)
#   define DISABLE_RE2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE2_AS_ANALOG()       \
    do {                              \
      ENABLE_RE2_ANALOG();            \
      CONFIG_RE2_AS_INPUT();          \
      DISABLE_RE2_OPENDRAIN();        \
      DISABLE_RE2_PULLUP();           \
      DISABLE_RE2_PULLDOWN();         \
    } while (0)

# define CONFIG_RE2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE2_ANALOG();           \
      CONFIG_RE2_AS_INPUT();          \
      DISABLE_RE2_OPENDRAIN();        \
      DISABLE_RE2_PULLUP();           \
      DISABLE_RE2_PULLDOWN();         \
    } while (0)

# define CONFIG_RE2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE2_ANALOG();           \
      CONFIG_RE2_AS_OUTPUT();         \
      DISABLE_RE2_OPENDRAIN();        \
      DISABLE_RE2_PULLUP();           \
      DISABLE_RE2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE2: Provide GPIO for RE2


// Provide GPIO for RE3
// ====================
#ifdef _RE3
# ifndef RE3_GPIO
#   warning "RE3_GPIO not defined, but pin RE3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE3_GPIO)
# define RE3_REMAPPABLE RXY_REMAPPABLE_PIN(RE3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE3_GPIO)
#   define ENABLE_RE3_ANALOG()  (RXY_GPIO_PCFG(RE3_GPIO) = 1)
#   define DISABLE_RE3_ANALOG() (RXY_GPIO_PCFG(RE3_GPIO) = 0)
#   define RE3_AN_PORT RXY_AN_PORT(RE3_GPIO)
# else
#   define DISABLE_RE3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE3_AS_INPUT()  (_TRISE3 = 1)
# define CONFIG_RE3_AS_OUTPUT() (_TRISE3 = 0)

// Open-drain:
#if defined(_ODCE3)
# define ENABLE_RE3_OPENDRAIN()  (_ODCE3 = 1)
# define DISABLE_RE3_OPENDRAIN() (_ODCE3 = 0)
#elif defined(_ODE3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE3_OPENDRAIN()  (_ODE3 = 1)
# define DISABLE_RE3_OPENDRAIN() (_ODE3 = 0)
#else
# define DISABLE_RE3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE3_GPIO)
#   define ENABLE_RE3_PULLUP()  (RXY_GPIO_CNPUE(RE3_GPIO) = 1)
#   define DISABLE_RE3_PULLUP() (RXY_GPIO_CNPUE(RE3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE3_GPIO)
#     define ENABLE_RE3_PULLDOWN()  (RXY_GPIO_CNPDE(RE3_GPIO) = 1)
#     define DISABLE_RE3_PULLDOWN() (RXY_GPIO_CNPDE(RE3_GPIO) = 0)
#   else
#     define DISABLE_RE3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE3_GPIO) = 1)
#   define DISABLE_RE3_CN_INTERRUPT() (RXY_GPIO_CNIE(RE3_GPIO) = 0)

# else
#   define DISABLE_RE3_PULLUP() ((void) 0)
#   define DISABLE_RE3_PULLDOWN() ((void) 0)
#   define DISABLE_RE3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE3_AS_ANALOG()       \
    do {                              \
      ENABLE_RE3_ANALOG();            \
      CONFIG_RE3_AS_INPUT();          \
      DISABLE_RE3_OPENDRAIN();        \
      DISABLE_RE3_PULLUP();           \
      DISABLE_RE3_PULLDOWN();         \
    } while (0)

# define CONFIG_RE3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE3_ANALOG();           \
      CONFIG_RE3_AS_INPUT();          \
      DISABLE_RE3_OPENDRAIN();        \
      DISABLE_RE3_PULLUP();           \
      DISABLE_RE3_PULLDOWN();         \
    } while (0)

# define CONFIG_RE3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE3_ANALOG();           \
      CONFIG_RE3_AS_OUTPUT();         \
      DISABLE_RE3_OPENDRAIN();        \
      DISABLE_RE3_PULLUP();           \
      DISABLE_RE3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE3: Provide GPIO for RE3


// Provide GPIO for RE4
// ====================
#ifdef _RE4
# ifndef RE4_GPIO
#   warning "RE4_GPIO not defined, but pin RE4 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE4_GPIO)
# define RE4_REMAPPABLE RXY_REMAPPABLE_PIN(RE4_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE4_GPIO)
#   define ENABLE_RE4_ANALOG()  (RXY_GPIO_PCFG(RE4_GPIO) = 1)
#   define DISABLE_RE4_ANALOG() (RXY_GPIO_PCFG(RE4_GPIO) = 0)
#   define RE4_AN_PORT RXY_AN_PORT(RE4_GPIO)
# else
#   define DISABLE_RE4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE4_AS_INPUT()  (_TRISE4 = 1)
# define CONFIG_RE4_AS_OUTPUT() (_TRISE4 = 0)

// Open-drain:
#if defined(_ODCE4)
# define ENABLE_RE4_OPENDRAIN()  (_ODCE4 = 1)
# define DISABLE_RE4_OPENDRAIN() (_ODCE4 = 0)
#elif defined(_ODE4)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE4_OPENDRAIN()  (_ODE4 = 1)
# define DISABLE_RE4_OPENDRAIN() (_ODE4 = 0)
#else
# define DISABLE_RE4_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE4_GPIO)
#   define ENABLE_RE4_PULLUP()  (RXY_GPIO_CNPUE(RE4_GPIO) = 1)
#   define DISABLE_RE4_PULLUP() (RXY_GPIO_CNPUE(RE4_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE4_GPIO)
#     define ENABLE_RE4_PULLDOWN()  (RXY_GPIO_CNPDE(RE4_GPIO) = 1)
#     define DISABLE_RE4_PULLDOWN() (RXY_GPIO_CNPDE(RE4_GPIO) = 0)
#   else
#     define DISABLE_RE4_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE4_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE4_GPIO) = 1)
#   define DISABLE_RE4_CN_INTERRUPT() (RXY_GPIO_CNIE(RE4_GPIO) = 0)

# else
#   define DISABLE_RE4_PULLUP() ((void) 0)
#   define DISABLE_RE4_PULLDOWN() ((void) 0)
#   define DISABLE_RE4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE4_AS_ANALOG()       \
    do {                              \
      ENABLE_RE4_ANALOG();            \
      CONFIG_RE4_AS_INPUT();          \
      DISABLE_RE4_OPENDRAIN();        \
      DISABLE_RE4_PULLUP();           \
      DISABLE_RE4_PULLDOWN();         \
    } while (0)

# define CONFIG_RE4_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE4_ANALOG();           \
      CONFIG_RE4_AS_INPUT();          \
      DISABLE_RE4_OPENDRAIN();        \
      DISABLE_RE4_PULLUP();           \
      DISABLE_RE4_PULLDOWN();         \
    } while (0)

# define CONFIG_RE4_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE4_ANALOG();           \
      CONFIG_RE4_AS_OUTPUT();         \
      DISABLE_RE4_OPENDRAIN();        \
      DISABLE_RE4_PULLUP();           \
      DISABLE_RE4_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE4: Provide GPIO for RE4


// Provide GPIO for RE5
// ====================
#ifdef _RE5
# ifndef RE5_GPIO
#   warning "RE5_GPIO not defined, but pin RE5 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE5_GPIO)
# define RE5_REMAPPABLE RXY_REMAPPABLE_PIN(RE5_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE5_GPIO)
#   define ENABLE_RE5_ANALOG()  (RXY_GPIO_PCFG(RE5_GPIO) = 1)
#   define DISABLE_RE5_ANALOG() (RXY_GPIO_PCFG(RE5_GPIO) = 0)
#   define RE5_AN_PORT RXY_AN_PORT(RE5_GPIO)
# else
#   define DISABLE_RE5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE5_AS_INPUT()  (_TRISE5 = 1)
# define CONFIG_RE5_AS_OUTPUT() (_TRISE5 = 0)

// Open-drain:
#if defined(_ODCE5)
# define ENABLE_RE5_OPENDRAIN()  (_ODCE5 = 1)
# define DISABLE_RE5_OPENDRAIN() (_ODCE5 = 0)
#elif defined(_ODE5)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE5_OPENDRAIN()  (_ODE5 = 1)
# define DISABLE_RE5_OPENDRAIN() (_ODE5 = 0)
#else
# define DISABLE_RE5_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE5_GPIO)
#   define ENABLE_RE5_PULLUP()  (RXY_GPIO_CNPUE(RE5_GPIO) = 1)
#   define DISABLE_RE5_PULLUP() (RXY_GPIO_CNPUE(RE5_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE5_GPIO)
#     define ENABLE_RE5_PULLDOWN()  (RXY_GPIO_CNPDE(RE5_GPIO) = 1)
#     define DISABLE_RE5_PULLDOWN() (RXY_GPIO_CNPDE(RE5_GPIO) = 0)
#   else
#     define DISABLE_RE5_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE5_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE5_GPIO) = 1)
#   define DISABLE_RE5_CN_INTERRUPT() (RXY_GPIO_CNIE(RE5_GPIO) = 0)

# else
#   define DISABLE_RE5_PULLUP() ((void) 0)
#   define DISABLE_RE5_PULLDOWN() ((void) 0)
#   define DISABLE_RE5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE5_AS_ANALOG()       \
    do {                              \
      ENABLE_RE5_ANALOG();            \
      CONFIG_RE5_AS_INPUT();          \
      DISABLE_RE5_OPENDRAIN();        \
      DISABLE_RE5_PULLUP();           \
      DISABLE_RE5_PULLDOWN();         \
    } while (0)

# define CONFIG_RE5_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE5_ANALOG();           \
      CONFIG_RE5_AS_INPUT();          \
      DISABLE_RE5_OPENDRAIN();        \
      DISABLE_RE5_PULLUP();           \
      DISABLE_RE5_PULLDOWN();         \
    } while (0)

# define CONFIG_RE5_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE5_ANALOG();           \
      CONFIG_RE5_AS_OUTPUT();         \
      DISABLE_RE5_OPENDRAIN();        \
      DISABLE_RE5_PULLUP();           \
      DISABLE_RE5_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE5: Provide GPIO for RE5


// Provide GPIO for RE6
// ====================
#ifdef _RE6
# ifndef RE6_GPIO
#   warning "RE6_GPIO not defined, but pin RE6 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE6_GPIO)
# define RE6_REMAPPABLE RXY_REMAPPABLE_PIN(RE6_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE6_GPIO)
#   define ENABLE_RE6_ANALOG()  (RXY_GPIO_PCFG(RE6_GPIO) = 1)
#   define DISABLE_RE6_ANALOG() (RXY_GPIO_PCFG(RE6_GPIO) = 0)
#   define RE6_AN_PORT RXY_AN_PORT(RE6_GPIO)
# else
#   define DISABLE_RE6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE6_AS_INPUT()  (_TRISE6 = 1)
# define CONFIG_RE6_AS_OUTPUT() (_TRISE6 = 0)

// Open-drain:
#if defined(_ODCE6)
# define ENABLE_RE6_OPENDRAIN()  (_ODCE6 = 1)
# define DISABLE_RE6_OPENDRAIN() (_ODCE6 = 0)
#elif defined(_ODE6)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE6_OPENDRAIN()  (_ODE6 = 1)
# define DISABLE_RE6_OPENDRAIN() (_ODE6 = 0)
#else
# define DISABLE_RE6_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE6_GPIO)
#   define ENABLE_RE6_PULLUP()  (RXY_GPIO_CNPUE(RE6_GPIO) = 1)
#   define DISABLE_RE6_PULLUP() (RXY_GPIO_CNPUE(RE6_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE6_GPIO)
#     define ENABLE_RE6_PULLDOWN()  (RXY_GPIO_CNPDE(RE6_GPIO) = 1)
#     define DISABLE_RE6_PULLDOWN() (RXY_GPIO_CNPDE(RE6_GPIO) = 0)
#   else
#     define DISABLE_RE6_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE6_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE6_GPIO) = 1)
#   define DISABLE_RE6_CN_INTERRUPT() (RXY_GPIO_CNIE(RE6_GPIO) = 0)

# else
#   define DISABLE_RE6_PULLUP() ((void) 0)
#   define DISABLE_RE6_PULLDOWN() ((void) 0)
#   define DISABLE_RE6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE6_AS_ANALOG()       \
    do {                              \
      ENABLE_RE6_ANALOG();            \
      CONFIG_RE6_AS_INPUT();          \
      DISABLE_RE6_OPENDRAIN();        \
      DISABLE_RE6_PULLUP();           \
      DISABLE_RE6_PULLDOWN();         \
    } while (0)

# define CONFIG_RE6_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE6_ANALOG();           \
      CONFIG_RE6_AS_INPUT();          \
      DISABLE_RE6_OPENDRAIN();        \
      DISABLE_RE6_PULLUP();           \
      DISABLE_RE6_PULLDOWN();         \
    } while (0)

# define CONFIG_RE6_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE6_ANALOG();           \
      CONFIG_RE6_AS_OUTPUT();         \
      DISABLE_RE6_OPENDRAIN();        \
      DISABLE_RE6_PULLUP();           \
      DISABLE_RE6_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE6: Provide GPIO for RE6


// Provide GPIO for RE7
// ====================
#ifdef _RE7
# ifndef RE7_GPIO
#   warning "RE7_GPIO not defined, but pin RE7 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE7_GPIO)
# define RE7_REMAPPABLE RXY_REMAPPABLE_PIN(RE7_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE7_GPIO)
#   define ENABLE_RE7_ANALOG()  (RXY_GPIO_PCFG(RE7_GPIO) = 1)
#   define DISABLE_RE7_ANALOG() (RXY_GPIO_PCFG(RE7_GPIO) = 0)
#   define RE7_AN_PORT RXY_AN_PORT(RE7_GPIO)
# else
#   define DISABLE_RE7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE7_AS_INPUT()  (_TRISE7 = 1)
# define CONFIG_RE7_AS_OUTPUT() (_TRISE7 = 0)

// Open-drain:
#if defined(_ODCE7)
# define ENABLE_RE7_OPENDRAIN()  (_ODCE7 = 1)
# define DISABLE_RE7_OPENDRAIN() (_ODCE7 = 0)
#elif defined(_ODE7)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE7_OPENDRAIN()  (_ODE7 = 1)
# define DISABLE_RE7_OPENDRAIN() (_ODE7 = 0)
#else
# define DISABLE_RE7_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE7_GPIO)
#   define ENABLE_RE7_PULLUP()  (RXY_GPIO_CNPUE(RE7_GPIO) = 1)
#   define DISABLE_RE7_PULLUP() (RXY_GPIO_CNPUE(RE7_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE7_GPIO)
#     define ENABLE_RE7_PULLDOWN()  (RXY_GPIO_CNPDE(RE7_GPIO) = 1)
#     define DISABLE_RE7_PULLDOWN() (RXY_GPIO_CNPDE(RE7_GPIO) = 0)
#   else
#     define DISABLE_RE7_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE7_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE7_GPIO) = 1)
#   define DISABLE_RE7_CN_INTERRUPT() (RXY_GPIO_CNIE(RE7_GPIO) = 0)

# else
#   define DISABLE_RE7_PULLUP() ((void) 0)
#   define DISABLE_RE7_PULLDOWN() ((void) 0)
#   define DISABLE_RE7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE7_AS_ANALOG()       \
    do {                              \
      ENABLE_RE7_ANALOG();            \
      CONFIG_RE7_AS_INPUT();          \
      DISABLE_RE7_OPENDRAIN();        \
      DISABLE_RE7_PULLUP();           \
      DISABLE_RE7_PULLDOWN();         \
    } while (0)

# define CONFIG_RE7_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE7_ANALOG();           \
      CONFIG_RE7_AS_INPUT();          \
      DISABLE_RE7_OPENDRAIN();        \
      DISABLE_RE7_PULLUP();           \
      DISABLE_RE7_PULLDOWN();         \
    } while (0)

# define CONFIG_RE7_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE7_ANALOG();           \
      CONFIG_RE7_AS_OUTPUT();         \
      DISABLE_RE7_OPENDRAIN();        \
      DISABLE_RE7_PULLUP();           \
      DISABLE_RE7_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE7: Provide GPIO for RE7


// Provide GPIO for RE8
// ====================
#ifdef _RE8
# ifndef RE8_GPIO
#   warning "RE8_GPIO not defined, but pin RE8 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE8_GPIO)
# define RE8_REMAPPABLE RXY_REMAPPABLE_PIN(RE8_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE8_GPIO)
#   define ENABLE_RE8_ANALOG()  (RXY_GPIO_PCFG(RE8_GPIO) = 1)
#   define DISABLE_RE8_ANALOG() (RXY_GPIO_PCFG(RE8_GPIO) = 0)
#   define RE8_AN_PORT RXY_AN_PORT(RE8_GPIO)
# else
#   define DISABLE_RE8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE8_AS_INPUT()  (_TRISE8 = 1)
# define CONFIG_RE8_AS_OUTPUT() (_TRISE8 = 0)

// Open-drain:
#if defined(_ODCE8)
# define ENABLE_RE8_OPENDRAIN()  (_ODCE8 = 1)
# define DISABLE_RE8_OPENDRAIN() (_ODCE8 = 0)
#elif defined(_ODE8)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE8_OPENDRAIN()  (_ODE8 = 1)
# define DISABLE_RE8_OPENDRAIN() (_ODE8 = 0)
#else
# define DISABLE_RE8_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE8_GPIO)
#   define ENABLE_RE8_PULLUP()  (RXY_GPIO_CNPUE(RE8_GPIO) = 1)
#   define DISABLE_RE8_PULLUP() (RXY_GPIO_CNPUE(RE8_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE8_GPIO)
#     define ENABLE_RE8_PULLDOWN()  (RXY_GPIO_CNPDE(RE8_GPIO) = 1)
#     define DISABLE_RE8_PULLDOWN() (RXY_GPIO_CNPDE(RE8_GPIO) = 0)
#   else
#     define DISABLE_RE8_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE8_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE8_GPIO) = 1)
#   define DISABLE_RE8_CN_INTERRUPT() (RXY_GPIO_CNIE(RE8_GPIO) = 0)

# else
#   define DISABLE_RE8_PULLUP() ((void) 0)
#   define DISABLE_RE8_PULLDOWN() ((void) 0)
#   define DISABLE_RE8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE8_AS_ANALOG()       \
    do {                              \
      ENABLE_RE8_ANALOG();            \
      CONFIG_RE8_AS_INPUT();          \
      DISABLE_RE8_OPENDRAIN();        \
      DISABLE_RE8_PULLUP();           \
      DISABLE_RE8_PULLDOWN();         \
    } while (0)

# define CONFIG_RE8_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE8_ANALOG();           \
      CONFIG_RE8_AS_INPUT();          \
      DISABLE_RE8_OPENDRAIN();        \
      DISABLE_RE8_PULLUP();           \
      DISABLE_RE8_PULLDOWN();         \
    } while (0)

# define CONFIG_RE8_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE8_ANALOG();           \
      CONFIG_RE8_AS_OUTPUT();         \
      DISABLE_RE8_OPENDRAIN();        \
      DISABLE_RE8_PULLUP();           \
      DISABLE_RE8_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE8: Provide GPIO for RE8


// Provide GPIO for RE9
// ====================
#ifdef _RE9
# ifndef RE9_GPIO
#   warning "RE9_GPIO not defined, but pin RE9 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE9_GPIO)
# define RE9_REMAPPABLE RXY_REMAPPABLE_PIN(RE9_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE9_GPIO)
#   define ENABLE_RE9_ANALOG()  (RXY_GPIO_PCFG(RE9_GPIO) = 1)
#   define DISABLE_RE9_ANALOG() (RXY_GPIO_PCFG(RE9_GPIO) = 0)
#   define RE9_AN_PORT RXY_AN_PORT(RE9_GPIO)
# else
#   define DISABLE_RE9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE9_AS_INPUT()  (_TRISE9 = 1)
# define CONFIG_RE9_AS_OUTPUT() (_TRISE9 = 0)

// Open-drain:
#if defined(_ODCE9)
# define ENABLE_RE9_OPENDRAIN()  (_ODCE9 = 1)
# define DISABLE_RE9_OPENDRAIN() (_ODCE9 = 0)
#elif defined(_ODE9)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE9_OPENDRAIN()  (_ODE9 = 1)
# define DISABLE_RE9_OPENDRAIN() (_ODE9 = 0)
#else
# define DISABLE_RE9_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE9_GPIO)
#   define ENABLE_RE9_PULLUP()  (RXY_GPIO_CNPUE(RE9_GPIO) = 1)
#   define DISABLE_RE9_PULLUP() (RXY_GPIO_CNPUE(RE9_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE9_GPIO)
#     define ENABLE_RE9_PULLDOWN()  (RXY_GPIO_CNPDE(RE9_GPIO) = 1)
#     define DISABLE_RE9_PULLDOWN() (RXY_GPIO_CNPDE(RE9_GPIO) = 0)
#   else
#     define DISABLE_RE9_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE9_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE9_GPIO) = 1)
#   define DISABLE_RE9_CN_INTERRUPT() (RXY_GPIO_CNIE(RE9_GPIO) = 0)

# else
#   define DISABLE_RE9_PULLUP() ((void) 0)
#   define DISABLE_RE9_PULLDOWN() ((void) 0)
#   define DISABLE_RE9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE9_AS_ANALOG()       \
    do {                              \
      ENABLE_RE9_ANALOG();            \
      CONFIG_RE9_AS_INPUT();          \
      DISABLE_RE9_OPENDRAIN();        \
      DISABLE_RE9_PULLUP();           \
      DISABLE_RE9_PULLDOWN();         \
    } while (0)

# define CONFIG_RE9_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE9_ANALOG();           \
      CONFIG_RE9_AS_INPUT();          \
      DISABLE_RE9_OPENDRAIN();        \
      DISABLE_RE9_PULLUP();           \
      DISABLE_RE9_PULLDOWN();         \
    } while (0)

# define CONFIG_RE9_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE9_ANALOG();           \
      CONFIG_RE9_AS_OUTPUT();         \
      DISABLE_RE9_OPENDRAIN();        \
      DISABLE_RE9_PULLUP();           \
      DISABLE_RE9_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE9: Provide GPIO for RE9


// Provide GPIO for RE10
// ====================
#ifdef _RE10
# ifndef RE10_GPIO
#   warning "RE10_GPIO not defined, but pin RE10 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE10_GPIO)
# define RE10_REMAPPABLE RXY_REMAPPABLE_PIN(RE10_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE10_GPIO)
#   define ENABLE_RE10_ANALOG()  (RXY_GPIO_PCFG(RE10_GPIO) = 1)
#   define DISABLE_RE10_ANALOG() (RXY_GPIO_PCFG(RE10_GPIO) = 0)
#   define RE10_AN_PORT RXY_AN_PORT(RE10_GPIO)
# else
#   define DISABLE_RE10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE10_AS_INPUT()  (_TRISE10 = 1)
# define CONFIG_RE10_AS_OUTPUT() (_TRISE10 = 0)

// Open-drain:
#if defined(_ODCE10)
# define ENABLE_RE10_OPENDRAIN()  (_ODCE10 = 1)
# define DISABLE_RE10_OPENDRAIN() (_ODCE10 = 0)
#elif defined(_ODE10)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE10_OPENDRAIN()  (_ODE10 = 1)
# define DISABLE_RE10_OPENDRAIN() (_ODE10 = 0)
#else
# define DISABLE_RE10_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE10_GPIO)
#   define ENABLE_RE10_PULLUP()  (RXY_GPIO_CNPUE(RE10_GPIO) = 1)
#   define DISABLE_RE10_PULLUP() (RXY_GPIO_CNPUE(RE10_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE10_GPIO)
#     define ENABLE_RE10_PULLDOWN()  (RXY_GPIO_CNPDE(RE10_GPIO) = 1)
#     define DISABLE_RE10_PULLDOWN() (RXY_GPIO_CNPDE(RE10_GPIO) = 0)
#   else
#     define DISABLE_RE10_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE10_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE10_GPIO) = 1)
#   define DISABLE_RE10_CN_INTERRUPT() (RXY_GPIO_CNIE(RE10_GPIO) = 0)

# else
#   define DISABLE_RE10_PULLUP() ((void) 0)
#   define DISABLE_RE10_PULLDOWN() ((void) 0)
#   define DISABLE_RE10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE10_AS_ANALOG()       \
    do {                              \
      ENABLE_RE10_ANALOG();            \
      CONFIG_RE10_AS_INPUT();          \
      DISABLE_RE10_OPENDRAIN();        \
      DISABLE_RE10_PULLUP();           \
      DISABLE_RE10_PULLDOWN();         \
    } while (0)

# define CONFIG_RE10_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE10_ANALOG();           \
      CONFIG_RE10_AS_INPUT();          \
      DISABLE_RE10_OPENDRAIN();        \
      DISABLE_RE10_PULLUP();           \
      DISABLE_RE10_PULLDOWN();         \
    } while (0)

# define CONFIG_RE10_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE10_ANALOG();           \
      CONFIG_RE10_AS_OUTPUT();         \
      DISABLE_RE10_OPENDRAIN();        \
      DISABLE_RE10_PULLUP();           \
      DISABLE_RE10_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE10: Provide GPIO for RE10


// Provide GPIO for RE11
// ====================
#ifdef _RE11
# ifndef RE11_GPIO
#   warning "RE11_GPIO not defined, but pin RE11 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE11_GPIO)
# define RE11_REMAPPABLE RXY_REMAPPABLE_PIN(RE11_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE11_GPIO)
#   define ENABLE_RE11_ANALOG()  (RXY_GPIO_PCFG(RE11_GPIO) = 1)
#   define DISABLE_RE11_ANALOG() (RXY_GPIO_PCFG(RE11_GPIO) = 0)
#   define RE11_AN_PORT RXY_AN_PORT(RE11_GPIO)
# else
#   define DISABLE_RE11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE11_AS_INPUT()  (_TRISE11 = 1)
# define CONFIG_RE11_AS_OUTPUT() (_TRISE11 = 0)

// Open-drain:
#if defined(_ODCE11)
# define ENABLE_RE11_OPENDRAIN()  (_ODCE11 = 1)
# define DISABLE_RE11_OPENDRAIN() (_ODCE11 = 0)
#elif defined(_ODE11)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE11_OPENDRAIN()  (_ODE11 = 1)
# define DISABLE_RE11_OPENDRAIN() (_ODE11 = 0)
#else
# define DISABLE_RE11_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE11_GPIO)
#   define ENABLE_RE11_PULLUP()  (RXY_GPIO_CNPUE(RE11_GPIO) = 1)
#   define DISABLE_RE11_PULLUP() (RXY_GPIO_CNPUE(RE11_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE11_GPIO)
#     define ENABLE_RE11_PULLDOWN()  (RXY_GPIO_CNPDE(RE11_GPIO) = 1)
#     define DISABLE_RE11_PULLDOWN() (RXY_GPIO_CNPDE(RE11_GPIO) = 0)
#   else
#     define DISABLE_RE11_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE11_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE11_GPIO) = 1)
#   define DISABLE_RE11_CN_INTERRUPT() (RXY_GPIO_CNIE(RE11_GPIO) = 0)

# else
#   define DISABLE_RE11_PULLUP() ((void) 0)
#   define DISABLE_RE11_PULLDOWN() ((void) 0)
#   define DISABLE_RE11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE11_AS_ANALOG()       \
    do {                              \
      ENABLE_RE11_ANALOG();            \
      CONFIG_RE11_AS_INPUT();          \
      DISABLE_RE11_OPENDRAIN();        \
      DISABLE_RE11_PULLUP();           \
      DISABLE_RE11_PULLDOWN();         \
    } while (0)

# define CONFIG_RE11_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE11_ANALOG();           \
      CONFIG_RE11_AS_INPUT();          \
      DISABLE_RE11_OPENDRAIN();        \
      DISABLE_RE11_PULLUP();           \
      DISABLE_RE11_PULLDOWN();         \
    } while (0)

# define CONFIG_RE11_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE11_ANALOG();           \
      CONFIG_RE11_AS_OUTPUT();         \
      DISABLE_RE11_OPENDRAIN();        \
      DISABLE_RE11_PULLUP();           \
      DISABLE_RE11_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE11: Provide GPIO for RE11


// Provide GPIO for RE12
// ====================
#ifdef _RE12
# ifndef RE12_GPIO
#   warning "RE12_GPIO not defined, but pin RE12 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE12_GPIO)
# define RE12_REMAPPABLE RXY_REMAPPABLE_PIN(RE12_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE12_GPIO)
#   define ENABLE_RE12_ANALOG()  (RXY_GPIO_PCFG(RE12_GPIO) = 1)
#   define DISABLE_RE12_ANALOG() (RXY_GPIO_PCFG(RE12_GPIO) = 0)
#   define RE12_AN_PORT RXY_AN_PORT(RE12_GPIO)
# else
#   define DISABLE_RE12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE12_AS_INPUT()  (_TRISE12 = 1)
# define CONFIG_RE12_AS_OUTPUT() (_TRISE12 = 0)

// Open-drain:
#if defined(_ODCE12)
# define ENABLE_RE12_OPENDRAIN()  (_ODCE12 = 1)
# define DISABLE_RE12_OPENDRAIN() (_ODCE12 = 0)
#elif defined(_ODE12)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE12_OPENDRAIN()  (_ODE12 = 1)
# define DISABLE_RE12_OPENDRAIN() (_ODE12 = 0)
#else
# define DISABLE_RE12_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE12_GPIO)
#   define ENABLE_RE12_PULLUP()  (RXY_GPIO_CNPUE(RE12_GPIO) = 1)
#   define DISABLE_RE12_PULLUP() (RXY_GPIO_CNPUE(RE12_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE12_GPIO)
#     define ENABLE_RE12_PULLDOWN()  (RXY_GPIO_CNPDE(RE12_GPIO) = 1)
#     define DISABLE_RE12_PULLDOWN() (RXY_GPIO_CNPDE(RE12_GPIO) = 0)
#   else
#     define DISABLE_RE12_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE12_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE12_GPIO) = 1)
#   define DISABLE_RE12_CN_INTERRUPT() (RXY_GPIO_CNIE(RE12_GPIO) = 0)

# else
#   define DISABLE_RE12_PULLUP() ((void) 0)
#   define DISABLE_RE12_PULLDOWN() ((void) 0)
#   define DISABLE_RE12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE12_AS_ANALOG()       \
    do {                              \
      ENABLE_RE12_ANALOG();            \
      CONFIG_RE12_AS_INPUT();          \
      DISABLE_RE12_OPENDRAIN();        \
      DISABLE_RE12_PULLUP();           \
      DISABLE_RE12_PULLDOWN();         \
    } while (0)

# define CONFIG_RE12_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE12_ANALOG();           \
      CONFIG_RE12_AS_INPUT();          \
      DISABLE_RE12_OPENDRAIN();        \
      DISABLE_RE12_PULLUP();           \
      DISABLE_RE12_PULLDOWN();         \
    } while (0)

# define CONFIG_RE12_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE12_ANALOG();           \
      CONFIG_RE12_AS_OUTPUT();         \
      DISABLE_RE12_OPENDRAIN();        \
      DISABLE_RE12_PULLUP();           \
      DISABLE_RE12_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE12: Provide GPIO for RE12


// Provide GPIO for RE13
// ====================
#ifdef _RE13
# ifndef RE13_GPIO
#   warning "RE13_GPIO not defined, but pin RE13 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE13_GPIO)
# define RE13_REMAPPABLE RXY_REMAPPABLE_PIN(RE13_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE13_GPIO)
#   define ENABLE_RE13_ANALOG()  (RXY_GPIO_PCFG(RE13_GPIO) = 1)
#   define DISABLE_RE13_ANALOG() (RXY_GPIO_PCFG(RE13_GPIO) = 0)
#   define RE13_AN_PORT RXY_AN_PORT(RE13_GPIO)
# else
#   define DISABLE_RE13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE13_AS_INPUT()  (_TRISE13 = 1)
# define CONFIG_RE13_AS_OUTPUT() (_TRISE13 = 0)

// Open-drain:
#if defined(_ODCE13)
# define ENABLE_RE13_OPENDRAIN()  (_ODCE13 = 1)
# define DISABLE_RE13_OPENDRAIN() (_ODCE13 = 0)
#elif defined(_ODE13)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE13_OPENDRAIN()  (_ODE13 = 1)
# define DISABLE_RE13_OPENDRAIN() (_ODE13 = 0)
#else
# define DISABLE_RE13_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE13_GPIO)
#   define ENABLE_RE13_PULLUP()  (RXY_GPIO_CNPUE(RE13_GPIO) = 1)
#   define DISABLE_RE13_PULLUP() (RXY_GPIO_CNPUE(RE13_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE13_GPIO)
#     define ENABLE_RE13_PULLDOWN()  (RXY_GPIO_CNPDE(RE13_GPIO) = 1)
#     define DISABLE_RE13_PULLDOWN() (RXY_GPIO_CNPDE(RE13_GPIO) = 0)
#   else
#     define DISABLE_RE13_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE13_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE13_GPIO) = 1)
#   define DISABLE_RE13_CN_INTERRUPT() (RXY_GPIO_CNIE(RE13_GPIO) = 0)

# else
#   define DISABLE_RE13_PULLUP() ((void) 0)
#   define DISABLE_RE13_PULLDOWN() ((void) 0)
#   define DISABLE_RE13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE13_AS_ANALOG()       \
    do {                              \
      ENABLE_RE13_ANALOG();            \
      CONFIG_RE13_AS_INPUT();          \
      DISABLE_RE13_OPENDRAIN();        \
      DISABLE_RE13_PULLUP();           \
      DISABLE_RE13_PULLDOWN();         \
    } while (0)

# define CONFIG_RE13_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE13_ANALOG();           \
      CONFIG_RE13_AS_INPUT();          \
      DISABLE_RE13_OPENDRAIN();        \
      DISABLE_RE13_PULLUP();           \
      DISABLE_RE13_PULLDOWN();         \
    } while (0)

# define CONFIG_RE13_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE13_ANALOG();           \
      CONFIG_RE13_AS_OUTPUT();         \
      DISABLE_RE13_OPENDRAIN();        \
      DISABLE_RE13_PULLUP();           \
      DISABLE_RE13_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE13: Provide GPIO for RE13


// Provide GPIO for RE14
// ====================
#ifdef _RE14
# ifndef RE14_GPIO
#   warning "RE14_GPIO not defined, but pin RE14 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE14_GPIO)
# define RE14_REMAPPABLE RXY_REMAPPABLE_PIN(RE14_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE14_GPIO)
#   define ENABLE_RE14_ANALOG()  (RXY_GPIO_PCFG(RE14_GPIO) = 1)
#   define DISABLE_RE14_ANALOG() (RXY_GPIO_PCFG(RE14_GPIO) = 0)
#   define RE14_AN_PORT RXY_AN_PORT(RE14_GPIO)
# else
#   define DISABLE_RE14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE14_AS_INPUT()  (_TRISE14 = 1)
# define CONFIG_RE14_AS_OUTPUT() (_TRISE14 = 0)

// Open-drain:
#if defined(_ODCE14)
# define ENABLE_RE14_OPENDRAIN()  (_ODCE14 = 1)
# define DISABLE_RE14_OPENDRAIN() (_ODCE14 = 0)
#elif defined(_ODE14)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE14_OPENDRAIN()  (_ODE14 = 1)
# define DISABLE_RE14_OPENDRAIN() (_ODE14 = 0)
#else
# define DISABLE_RE14_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE14_GPIO)
#   define ENABLE_RE14_PULLUP()  (RXY_GPIO_CNPUE(RE14_GPIO) = 1)
#   define DISABLE_RE14_PULLUP() (RXY_GPIO_CNPUE(RE14_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE14_GPIO)
#     define ENABLE_RE14_PULLDOWN()  (RXY_GPIO_CNPDE(RE14_GPIO) = 1)
#     define DISABLE_RE14_PULLDOWN() (RXY_GPIO_CNPDE(RE14_GPIO) = 0)
#   else
#     define DISABLE_RE14_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE14_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE14_GPIO) = 1)
#   define DISABLE_RE14_CN_INTERRUPT() (RXY_GPIO_CNIE(RE14_GPIO) = 0)

# else
#   define DISABLE_RE14_PULLUP() ((void) 0)
#   define DISABLE_RE14_PULLDOWN() ((void) 0)
#   define DISABLE_RE14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE14_AS_ANALOG()       \
    do {                              \
      ENABLE_RE14_ANALOG();            \
      CONFIG_RE14_AS_INPUT();          \
      DISABLE_RE14_OPENDRAIN();        \
      DISABLE_RE14_PULLUP();           \
      DISABLE_RE14_PULLDOWN();         \
    } while (0)

# define CONFIG_RE14_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE14_ANALOG();           \
      CONFIG_RE14_AS_INPUT();          \
      DISABLE_RE14_OPENDRAIN();        \
      DISABLE_RE14_PULLUP();           \
      DISABLE_RE14_PULLDOWN();         \
    } while (0)

# define CONFIG_RE14_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE14_ANALOG();           \
      CONFIG_RE14_AS_OUTPUT();         \
      DISABLE_RE14_OPENDRAIN();        \
      DISABLE_RE14_PULLUP();           \
      DISABLE_RE14_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE14: Provide GPIO for RE14


// Provide GPIO for RE15
// ====================
#ifdef _RE15
# ifndef RE15_GPIO
#   warning "RE15_GPIO not defined, but pin RE15 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RE15_GPIO)
# define RE15_REMAPPABLE RXY_REMAPPABLE_PIN(RE15_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RE15_GPIO)
#   define ENABLE_RE15_ANALOG()  (RXY_GPIO_PCFG(RE15_GPIO) = 1)
#   define DISABLE_RE15_ANALOG() (RXY_GPIO_PCFG(RE15_GPIO) = 0)
#   define RE15_AN_PORT RXY_AN_PORT(RE15_GPIO)
# else
#   define DISABLE_RE15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE15_AS_INPUT()  (_TRISE15 = 1)
# define CONFIG_RE15_AS_OUTPUT() (_TRISE15 = 0)

// Open-drain:
#if defined(_ODCE15)
# define ENABLE_RE15_OPENDRAIN()  (_ODCE15 = 1)
# define DISABLE_RE15_OPENDRAIN() (_ODCE15 = 0)
#elif defined(_ODE15)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RE15_OPENDRAIN()  (_ODE15 = 1)
# define DISABLE_RE15_OPENDRAIN() (_ODE15 = 0)
#else
# define DISABLE_RE15_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RE15_GPIO)
#   define ENABLE_RE15_PULLUP()  (RXY_GPIO_CNPUE(RE15_GPIO) = 1)
#   define DISABLE_RE15_PULLUP() (RXY_GPIO_CNPUE(RE15_GPIO) = 0)

#   if RXY_HAS_CNPDE(RE15_GPIO)
#     define ENABLE_RE15_PULLDOWN()  (RXY_GPIO_CNPDE(RE15_GPIO) = 1)
#     define DISABLE_RE15_PULLDOWN() (RXY_GPIO_CNPDE(RE15_GPIO) = 0)
#   else
#     define DISABLE_RE15_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RE15_CN_INTERRUPT()  (RXY_GPIO_CNIE(RE15_GPIO) = 1)
#   define DISABLE_RE15_CN_INTERRUPT() (RXY_GPIO_CNIE(RE15_GPIO) = 0)

# else
#   define DISABLE_RE15_PULLUP() ((void) 0)
#   define DISABLE_RE15_PULLDOWN() ((void) 0)
#   define DISABLE_RE15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RE15_AS_ANALOG()       \
    do {                              \
      ENABLE_RE15_ANALOG();            \
      CONFIG_RE15_AS_INPUT();          \
      DISABLE_RE15_OPENDRAIN();        \
      DISABLE_RE15_PULLUP();           \
      DISABLE_RE15_PULLDOWN();         \
    } while (0)

# define CONFIG_RE15_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RE15_ANALOG();           \
      CONFIG_RE15_AS_INPUT();          \
      DISABLE_RE15_OPENDRAIN();        \
      DISABLE_RE15_PULLUP();           \
      DISABLE_RE15_PULLDOWN();         \
    } while (0)

# define CONFIG_RE15_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RE15_ANALOG();           \
      CONFIG_RE15_AS_OUTPUT();         \
      DISABLE_RE15_OPENDRAIN();        \
      DISABLE_RE15_PULLUP();           \
      DISABLE_RE15_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RE15: Provide GPIO for RE15


// Provide GPIO for RF0
// ====================
#ifdef _RF0
# ifndef RF0_GPIO
#   warning "RF0_GPIO not defined, but pin RF0 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF0_GPIO)
# define RF0_REMAPPABLE RXY_REMAPPABLE_PIN(RF0_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF0_GPIO)
#   define ENABLE_RF0_ANALOG()  (RXY_GPIO_PCFG(RF0_GPIO) = 1)
#   define DISABLE_RF0_ANALOG() (RXY_GPIO_PCFG(RF0_GPIO) = 0)
#   define RF0_AN_PORT RXY_AN_PORT(RF0_GPIO)
# else
#   define DISABLE_RF0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF0_AS_INPUT()  (_TRISF0 = 1)
# define CONFIG_RF0_AS_OUTPUT() (_TRISF0 = 0)

// Open-drain:
#if defined(_ODCF0)
# define ENABLE_RF0_OPENDRAIN()  (_ODCF0 = 1)
# define DISABLE_RF0_OPENDRAIN() (_ODCF0 = 0)
#elif defined(_ODF0)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF0_OPENDRAIN()  (_ODF0 = 1)
# define DISABLE_RF0_OPENDRAIN() (_ODF0 = 0)
#else
# define DISABLE_RF0_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF0_GPIO)
#   define ENABLE_RF0_PULLUP()  (RXY_GPIO_CNPUE(RF0_GPIO) = 1)
#   define DISABLE_RF0_PULLUP() (RXY_GPIO_CNPUE(RF0_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF0_GPIO)
#     define ENABLE_RF0_PULLDOWN()  (RXY_GPIO_CNPDE(RF0_GPIO) = 1)
#     define DISABLE_RF0_PULLDOWN() (RXY_GPIO_CNPDE(RF0_GPIO) = 0)
#   else
#     define DISABLE_RF0_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF0_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF0_GPIO) = 1)
#   define DISABLE_RF0_CN_INTERRUPT() (RXY_GPIO_CNIE(RF0_GPIO) = 0)

# else
#   define DISABLE_RF0_PULLUP() ((void) 0)
#   define DISABLE_RF0_PULLDOWN() ((void) 0)
#   define DISABLE_RF0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF0_AS_ANALOG()       \
    do {                              \
      ENABLE_RF0_ANALOG();            \
      CONFIG_RF0_AS_INPUT();          \
      DISABLE_RF0_OPENDRAIN();        \
      DISABLE_RF0_PULLUP();           \
      DISABLE_RF0_PULLDOWN();         \
    } while (0)

# define CONFIG_RF0_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF0_ANALOG();           \
      CONFIG_RF0_AS_INPUT();          \
      DISABLE_RF0_OPENDRAIN();        \
      DISABLE_RF0_PULLUP();           \
      DISABLE_RF0_PULLDOWN();         \
    } while (0)

# define CONFIG_RF0_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF0_ANALOG();           \
      CONFIG_RF0_AS_OUTPUT();         \
      DISABLE_RF0_OPENDRAIN();        \
      DISABLE_RF0_PULLUP();           \
      DISABLE_RF0_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF0: Provide GPIO for RF0


// Provide GPIO for RF1
// ====================
#ifdef _RF1
# ifndef RF1_GPIO
#   warning "RF1_GPIO not defined, but pin RF1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF1_GPIO)
# define RF1_REMAPPABLE RXY_REMAPPABLE_PIN(RF1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF1_GPIO)
#   define ENABLE_RF1_ANALOG()  (RXY_GPIO_PCFG(RF1_GPIO) = 1)
#   define DISABLE_RF1_ANALOG() (RXY_GPIO_PCFG(RF1_GPIO) = 0)
#   define RF1_AN_PORT RXY_AN_PORT(RF1_GPIO)
# else
#   define DISABLE_RF1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF1_AS_INPUT()  (_TRISF1 = 1)
# define CONFIG_RF1_AS_OUTPUT() (_TRISF1 = 0)

// Open-drain:
#if defined(_ODCF1)
# define ENABLE_RF1_OPENDRAIN()  (_ODCF1 = 1)
# define DISABLE_RF1_OPENDRAIN() (_ODCF1 = 0)
#elif defined(_ODF1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF1_OPENDRAIN()  (_ODF1 = 1)
# define DISABLE_RF1_OPENDRAIN() (_ODF1 = 0)
#else
# define DISABLE_RF1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF1_GPIO)
#   define ENABLE_RF1_PULLUP()  (RXY_GPIO_CNPUE(RF1_GPIO) = 1)
#   define DISABLE_RF1_PULLUP() (RXY_GPIO_CNPUE(RF1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF1_GPIO)
#     define ENABLE_RF1_PULLDOWN()  (RXY_GPIO_CNPDE(RF1_GPIO) = 1)
#     define DISABLE_RF1_PULLDOWN() (RXY_GPIO_CNPDE(RF1_GPIO) = 0)
#   else
#     define DISABLE_RF1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF1_GPIO) = 1)
#   define DISABLE_RF1_CN_INTERRUPT() (RXY_GPIO_CNIE(RF1_GPIO) = 0)

# else
#   define DISABLE_RF1_PULLUP() ((void) 0)
#   define DISABLE_RF1_PULLDOWN() ((void) 0)
#   define DISABLE_RF1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF1_AS_ANALOG()       \
    do {                              \
      ENABLE_RF1_ANALOG();            \
      CONFIG_RF1_AS_INPUT();          \
      DISABLE_RF1_OPENDRAIN();        \
      DISABLE_RF1_PULLUP();           \
      DISABLE_RF1_PULLDOWN();         \
    } while (0)

# define CONFIG_RF1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF1_ANALOG();           \
      CONFIG_RF1_AS_INPUT();          \
      DISABLE_RF1_OPENDRAIN();        \
      DISABLE_RF1_PULLUP();           \
      DISABLE_RF1_PULLDOWN();         \
    } while (0)

# define CONFIG_RF1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF1_ANALOG();           \
      CONFIG_RF1_AS_OUTPUT();         \
      DISABLE_RF1_OPENDRAIN();        \
      DISABLE_RF1_PULLUP();           \
      DISABLE_RF1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF1: Provide GPIO for RF1


// Provide GPIO for RF2
// ====================
#ifdef _RF2
# ifndef RF2_GPIO
#   warning "RF2_GPIO not defined, but pin RF2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF2_GPIO)
# define RF2_REMAPPABLE RXY_REMAPPABLE_PIN(RF2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF2_GPIO)
#   define ENABLE_RF2_ANALOG()  (RXY_GPIO_PCFG(RF2_GPIO) = 1)
#   define DISABLE_RF2_ANALOG() (RXY_GPIO_PCFG(RF2_GPIO) = 0)
#   define RF2_AN_PORT RXY_AN_PORT(RF2_GPIO)
# else
#   define DISABLE_RF2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF2_AS_INPUT()  (_TRISF2 = 1)
# define CONFIG_RF2_AS_OUTPUT() (_TRISF2 = 0)

// Open-drain:
#if defined(_ODCF2)
# define ENABLE_RF2_OPENDRAIN()  (_ODCF2 = 1)
# define DISABLE_RF2_OPENDRAIN() (_ODCF2 = 0)
#elif defined(_ODF2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF2_OPENDRAIN()  (_ODF2 = 1)
# define DISABLE_RF2_OPENDRAIN() (_ODF2 = 0)
#else
# define DISABLE_RF2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF2_GPIO)
#   define ENABLE_RF2_PULLUP()  (RXY_GPIO_CNPUE(RF2_GPIO) = 1)
#   define DISABLE_RF2_PULLUP() (RXY_GPIO_CNPUE(RF2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF2_GPIO)
#     define ENABLE_RF2_PULLDOWN()  (RXY_GPIO_CNPDE(RF2_GPIO) = 1)
#     define DISABLE_RF2_PULLDOWN() (RXY_GPIO_CNPDE(RF2_GPIO) = 0)
#   else
#     define DISABLE_RF2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF2_GPIO) = 1)
#   define DISABLE_RF2_CN_INTERRUPT() (RXY_GPIO_CNIE(RF2_GPIO) = 0)

# else
#   define DISABLE_RF2_PULLUP() ((void) 0)
#   define DISABLE_RF2_PULLDOWN() ((void) 0)
#   define DISABLE_RF2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF2_AS_ANALOG()       \
    do {                              \
      ENABLE_RF2_ANALOG();            \
      CONFIG_RF2_AS_INPUT();          \
      DISABLE_RF2_OPENDRAIN();        \
      DISABLE_RF2_PULLUP();           \
      DISABLE_RF2_PULLDOWN();         \
    } while (0)

# define CONFIG_RF2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF2_ANALOG();           \
      CONFIG_RF2_AS_INPUT();          \
      DISABLE_RF2_OPENDRAIN();        \
      DISABLE_RF2_PULLUP();           \
      DISABLE_RF2_PULLDOWN();         \
    } while (0)

# define CONFIG_RF2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF2_ANALOG();           \
      CONFIG_RF2_AS_OUTPUT();         \
      DISABLE_RF2_OPENDRAIN();        \
      DISABLE_RF2_PULLUP();           \
      DISABLE_RF2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF2: Provide GPIO for RF2


// Provide GPIO for RF3
// ====================
#ifdef _RF3
# ifndef RF3_GPIO
#   warning "RF3_GPIO not defined, but pin RF3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF3_GPIO)
# define RF3_REMAPPABLE RXY_REMAPPABLE_PIN(RF3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF3_GPIO)
#   define ENABLE_RF3_ANALOG()  (RXY_GPIO_PCFG(RF3_GPIO) = 1)
#   define DISABLE_RF3_ANALOG() (RXY_GPIO_PCFG(RF3_GPIO) = 0)
#   define RF3_AN_PORT RXY_AN_PORT(RF3_GPIO)
# else
#   define DISABLE_RF3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF3_AS_INPUT()  (_TRISF3 = 1)
# define CONFIG_RF3_AS_OUTPUT() (_TRISF3 = 0)

// Open-drain:
#if defined(_ODCF3)
# define ENABLE_RF3_OPENDRAIN()  (_ODCF3 = 1)
# define DISABLE_RF3_OPENDRAIN() (_ODCF3 = 0)
#elif defined(_ODF3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF3_OPENDRAIN()  (_ODF3 = 1)
# define DISABLE_RF3_OPENDRAIN() (_ODF3 = 0)
#else
# define DISABLE_RF3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF3_GPIO)
#   define ENABLE_RF3_PULLUP()  (RXY_GPIO_CNPUE(RF3_GPIO) = 1)
#   define DISABLE_RF3_PULLUP() (RXY_GPIO_CNPUE(RF3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF3_GPIO)
#     define ENABLE_RF3_PULLDOWN()  (RXY_GPIO_CNPDE(RF3_GPIO) = 1)
#     define DISABLE_RF3_PULLDOWN() (RXY_GPIO_CNPDE(RF3_GPIO) = 0)
#   else
#     define DISABLE_RF3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF3_GPIO) = 1)
#   define DISABLE_RF3_CN_INTERRUPT() (RXY_GPIO_CNIE(RF3_GPIO) = 0)

# else
#   define DISABLE_RF3_PULLUP() ((void) 0)
#   define DISABLE_RF3_PULLDOWN() ((void) 0)
#   define DISABLE_RF3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF3_AS_ANALOG()       \
    do {                              \
      ENABLE_RF3_ANALOG();            \
      CONFIG_RF3_AS_INPUT();          \
      DISABLE_RF3_OPENDRAIN();        \
      DISABLE_RF3_PULLUP();           \
      DISABLE_RF3_PULLDOWN();         \
    } while (0)

# define CONFIG_RF3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF3_ANALOG();           \
      CONFIG_RF3_AS_INPUT();          \
      DISABLE_RF3_OPENDRAIN();        \
      DISABLE_RF3_PULLUP();           \
      DISABLE_RF3_PULLDOWN();         \
    } while (0)

# define CONFIG_RF3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF3_ANALOG();           \
      CONFIG_RF3_AS_OUTPUT();         \
      DISABLE_RF3_OPENDRAIN();        \
      DISABLE_RF3_PULLUP();           \
      DISABLE_RF3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF3: Provide GPIO for RF3


// Provide GPIO for RF4
// ====================
#ifdef _RF4
# ifndef RF4_GPIO
#   warning "RF4_GPIO not defined, but pin RF4 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF4_GPIO)
# define RF4_REMAPPABLE RXY_REMAPPABLE_PIN(RF4_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF4_GPIO)
#   define ENABLE_RF4_ANALOG()  (RXY_GPIO_PCFG(RF4_GPIO) = 1)
#   define DISABLE_RF4_ANALOG() (RXY_GPIO_PCFG(RF4_GPIO) = 0)
#   define RF4_AN_PORT RXY_AN_PORT(RF4_GPIO)
# else
#   define DISABLE_RF4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF4_AS_INPUT()  (_TRISF4 = 1)
# define CONFIG_RF4_AS_OUTPUT() (_TRISF4 = 0)

// Open-drain:
#if defined(_ODCF4)
# define ENABLE_RF4_OPENDRAIN()  (_ODCF4 = 1)
# define DISABLE_RF4_OPENDRAIN() (_ODCF4 = 0)
#elif defined(_ODF4)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF4_OPENDRAIN()  (_ODF4 = 1)
# define DISABLE_RF4_OPENDRAIN() (_ODF4 = 0)
#else
# define DISABLE_RF4_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF4_GPIO)
#   define ENABLE_RF4_PULLUP()  (RXY_GPIO_CNPUE(RF4_GPIO) = 1)
#   define DISABLE_RF4_PULLUP() (RXY_GPIO_CNPUE(RF4_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF4_GPIO)
#     define ENABLE_RF4_PULLDOWN()  (RXY_GPIO_CNPDE(RF4_GPIO) = 1)
#     define DISABLE_RF4_PULLDOWN() (RXY_GPIO_CNPDE(RF4_GPIO) = 0)
#   else
#     define DISABLE_RF4_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF4_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF4_GPIO) = 1)
#   define DISABLE_RF4_CN_INTERRUPT() (RXY_GPIO_CNIE(RF4_GPIO) = 0)

# else
#   define DISABLE_RF4_PULLUP() ((void) 0)
#   define DISABLE_RF4_PULLDOWN() ((void) 0)
#   define DISABLE_RF4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF4_AS_ANALOG()       \
    do {                              \
      ENABLE_RF4_ANALOG();            \
      CONFIG_RF4_AS_INPUT();          \
      DISABLE_RF4_OPENDRAIN();        \
      DISABLE_RF4_PULLUP();           \
      DISABLE_RF4_PULLDOWN();         \
    } while (0)

# define CONFIG_RF4_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF4_ANALOG();           \
      CONFIG_RF4_AS_INPUT();          \
      DISABLE_RF4_OPENDRAIN();        \
      DISABLE_RF4_PULLUP();           \
      DISABLE_RF4_PULLDOWN();         \
    } while (0)

# define CONFIG_RF4_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF4_ANALOG();           \
      CONFIG_RF4_AS_OUTPUT();         \
      DISABLE_RF4_OPENDRAIN();        \
      DISABLE_RF4_PULLUP();           \
      DISABLE_RF4_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF4: Provide GPIO for RF4


// Provide GPIO for RF5
// ====================
#ifdef _RF5
# ifndef RF5_GPIO
#   warning "RF5_GPIO not defined, but pin RF5 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF5_GPIO)
# define RF5_REMAPPABLE RXY_REMAPPABLE_PIN(RF5_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF5_GPIO)
#   define ENABLE_RF5_ANALOG()  (RXY_GPIO_PCFG(RF5_GPIO) = 1)
#   define DISABLE_RF5_ANALOG() (RXY_GPIO_PCFG(RF5_GPIO) = 0)
#   define RF5_AN_PORT RXY_AN_PORT(RF5_GPIO)
# else
#   define DISABLE_RF5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF5_AS_INPUT()  (_TRISF5 = 1)
# define CONFIG_RF5_AS_OUTPUT() (_TRISF5 = 0)

// Open-drain:
#if defined(_ODCF5)
# define ENABLE_RF5_OPENDRAIN()  (_ODCF5 = 1)
# define DISABLE_RF5_OPENDRAIN() (_ODCF5 = 0)
#elif defined(_ODF5)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF5_OPENDRAIN()  (_ODF5 = 1)
# define DISABLE_RF5_OPENDRAIN() (_ODF5 = 0)
#else
# define DISABLE_RF5_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF5_GPIO)
#   define ENABLE_RF5_PULLUP()  (RXY_GPIO_CNPUE(RF5_GPIO) = 1)
#   define DISABLE_RF5_PULLUP() (RXY_GPIO_CNPUE(RF5_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF5_GPIO)
#     define ENABLE_RF5_PULLDOWN()  (RXY_GPIO_CNPDE(RF5_GPIO) = 1)
#     define DISABLE_RF5_PULLDOWN() (RXY_GPIO_CNPDE(RF5_GPIO) = 0)
#   else
#     define DISABLE_RF5_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF5_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF5_GPIO) = 1)
#   define DISABLE_RF5_CN_INTERRUPT() (RXY_GPIO_CNIE(RF5_GPIO) = 0)

# else
#   define DISABLE_RF5_PULLUP() ((void) 0)
#   define DISABLE_RF5_PULLDOWN() ((void) 0)
#   define DISABLE_RF5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF5_AS_ANALOG()       \
    do {                              \
      ENABLE_RF5_ANALOG();            \
      CONFIG_RF5_AS_INPUT();          \
      DISABLE_RF5_OPENDRAIN();        \
      DISABLE_RF5_PULLUP();           \
      DISABLE_RF5_PULLDOWN();         \
    } while (0)

# define CONFIG_RF5_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF5_ANALOG();           \
      CONFIG_RF5_AS_INPUT();          \
      DISABLE_RF5_OPENDRAIN();        \
      DISABLE_RF5_PULLUP();           \
      DISABLE_RF5_PULLDOWN();         \
    } while (0)

# define CONFIG_RF5_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF5_ANALOG();           \
      CONFIG_RF5_AS_OUTPUT();         \
      DISABLE_RF5_OPENDRAIN();        \
      DISABLE_RF5_PULLUP();           \
      DISABLE_RF5_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF5: Provide GPIO for RF5


// Provide GPIO for RF6
// ====================
#ifdef _RF6
# ifndef RF6_GPIO
#   warning "RF6_GPIO not defined, but pin RF6 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF6_GPIO)
# define RF6_REMAPPABLE RXY_REMAPPABLE_PIN(RF6_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF6_GPIO)
#   define ENABLE_RF6_ANALOG()  (RXY_GPIO_PCFG(RF6_GPIO) = 1)
#   define DISABLE_RF6_ANALOG() (RXY_GPIO_PCFG(RF6_GPIO) = 0)
#   define RF6_AN_PORT RXY_AN_PORT(RF6_GPIO)
# else
#   define DISABLE_RF6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF6_AS_INPUT()  (_TRISF6 = 1)
# define CONFIG_RF6_AS_OUTPUT() (_TRISF6 = 0)

// Open-drain:
#if defined(_ODCF6)
# define ENABLE_RF6_OPENDRAIN()  (_ODCF6 = 1)
# define DISABLE_RF6_OPENDRAIN() (_ODCF6 = 0)
#elif defined(_ODF6)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF6_OPENDRAIN()  (_ODF6 = 1)
# define DISABLE_RF6_OPENDRAIN() (_ODF6 = 0)
#else
# define DISABLE_RF6_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF6_GPIO)
#   define ENABLE_RF6_PULLUP()  (RXY_GPIO_CNPUE(RF6_GPIO) = 1)
#   define DISABLE_RF6_PULLUP() (RXY_GPIO_CNPUE(RF6_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF6_GPIO)
#     define ENABLE_RF6_PULLDOWN()  (RXY_GPIO_CNPDE(RF6_GPIO) = 1)
#     define DISABLE_RF6_PULLDOWN() (RXY_GPIO_CNPDE(RF6_GPIO) = 0)
#   else
#     define DISABLE_RF6_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF6_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF6_GPIO) = 1)
#   define DISABLE_RF6_CN_INTERRUPT() (RXY_GPIO_CNIE(RF6_GPIO) = 0)

# else
#   define DISABLE_RF6_PULLUP() ((void) 0)
#   define DISABLE_RF6_PULLDOWN() ((void) 0)
#   define DISABLE_RF6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF6_AS_ANALOG()       \
    do {                              \
      ENABLE_RF6_ANALOG();            \
      CONFIG_RF6_AS_INPUT();          \
      DISABLE_RF6_OPENDRAIN();        \
      DISABLE_RF6_PULLUP();           \
      DISABLE_RF6_PULLDOWN();         \
    } while (0)

# define CONFIG_RF6_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF6_ANALOG();           \
      CONFIG_RF6_AS_INPUT();          \
      DISABLE_RF6_OPENDRAIN();        \
      DISABLE_RF6_PULLUP();           \
      DISABLE_RF6_PULLDOWN();         \
    } while (0)

# define CONFIG_RF6_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF6_ANALOG();           \
      CONFIG_RF6_AS_OUTPUT();         \
      DISABLE_RF6_OPENDRAIN();        \
      DISABLE_RF6_PULLUP();           \
      DISABLE_RF6_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF6: Provide GPIO for RF6


// Provide GPIO for RF7
// ====================
#ifdef _RF7
# ifndef RF7_GPIO
#   warning "RF7_GPIO not defined, but pin RF7 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF7_GPIO)
# define RF7_REMAPPABLE RXY_REMAPPABLE_PIN(RF7_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF7_GPIO)
#   define ENABLE_RF7_ANALOG()  (RXY_GPIO_PCFG(RF7_GPIO) = 1)
#   define DISABLE_RF7_ANALOG() (RXY_GPIO_PCFG(RF7_GPIO) = 0)
#   define RF7_AN_PORT RXY_AN_PORT(RF7_GPIO)
# else
#   define DISABLE_RF7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF7_AS_INPUT()  (_TRISF7 = 1)
# define CONFIG_RF7_AS_OUTPUT() (_TRISF7 = 0)

// Open-drain:
#if defined(_ODCF7)
# define ENABLE_RF7_OPENDRAIN()  (_ODCF7 = 1)
# define DISABLE_RF7_OPENDRAIN() (_ODCF7 = 0)
#elif defined(_ODF7)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF7_OPENDRAIN()  (_ODF7 = 1)
# define DISABLE_RF7_OPENDRAIN() (_ODF7 = 0)
#else
# define DISABLE_RF7_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF7_GPIO)
#   define ENABLE_RF7_PULLUP()  (RXY_GPIO_CNPUE(RF7_GPIO) = 1)
#   define DISABLE_RF7_PULLUP() (RXY_GPIO_CNPUE(RF7_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF7_GPIO)
#     define ENABLE_RF7_PULLDOWN()  (RXY_GPIO_CNPDE(RF7_GPIO) = 1)
#     define DISABLE_RF7_PULLDOWN() (RXY_GPIO_CNPDE(RF7_GPIO) = 0)
#   else
#     define DISABLE_RF7_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF7_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF7_GPIO) = 1)
#   define DISABLE_RF7_CN_INTERRUPT() (RXY_GPIO_CNIE(RF7_GPIO) = 0)

# else
#   define DISABLE_RF7_PULLUP() ((void) 0)
#   define DISABLE_RF7_PULLDOWN() ((void) 0)
#   define DISABLE_RF7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF7_AS_ANALOG()       \
    do {                              \
      ENABLE_RF7_ANALOG();            \
      CONFIG_RF7_AS_INPUT();          \
      DISABLE_RF7_OPENDRAIN();        \
      DISABLE_RF7_PULLUP();           \
      DISABLE_RF7_PULLDOWN();         \
    } while (0)

# define CONFIG_RF7_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF7_ANALOG();           \
      CONFIG_RF7_AS_INPUT();          \
      DISABLE_RF7_OPENDRAIN();        \
      DISABLE_RF7_PULLUP();           \
      DISABLE_RF7_PULLDOWN();         \
    } while (0)

# define CONFIG_RF7_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF7_ANALOG();           \
      CONFIG_RF7_AS_OUTPUT();         \
      DISABLE_RF7_OPENDRAIN();        \
      DISABLE_RF7_PULLUP();           \
      DISABLE_RF7_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF7: Provide GPIO for RF7


// Provide GPIO for RF8
// ====================
#ifdef _RF8
# ifndef RF8_GPIO
#   warning "RF8_GPIO not defined, but pin RF8 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF8_GPIO)
# define RF8_REMAPPABLE RXY_REMAPPABLE_PIN(RF8_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF8_GPIO)
#   define ENABLE_RF8_ANALOG()  (RXY_GPIO_PCFG(RF8_GPIO) = 1)
#   define DISABLE_RF8_ANALOG() (RXY_GPIO_PCFG(RF8_GPIO) = 0)
#   define RF8_AN_PORT RXY_AN_PORT(RF8_GPIO)
# else
#   define DISABLE_RF8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF8_AS_INPUT()  (_TRISF8 = 1)
# define CONFIG_RF8_AS_OUTPUT() (_TRISF8 = 0)

// Open-drain:
#if defined(_ODCF8)
# define ENABLE_RF8_OPENDRAIN()  (_ODCF8 = 1)
# define DISABLE_RF8_OPENDRAIN() (_ODCF8 = 0)
#elif defined(_ODF8)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF8_OPENDRAIN()  (_ODF8 = 1)
# define DISABLE_RF8_OPENDRAIN() (_ODF8 = 0)
#else
# define DISABLE_RF8_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF8_GPIO)
#   define ENABLE_RF8_PULLUP()  (RXY_GPIO_CNPUE(RF8_GPIO) = 1)
#   define DISABLE_RF8_PULLUP() (RXY_GPIO_CNPUE(RF8_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF8_GPIO)
#     define ENABLE_RF8_PULLDOWN()  (RXY_GPIO_CNPDE(RF8_GPIO) = 1)
#     define DISABLE_RF8_PULLDOWN() (RXY_GPIO_CNPDE(RF8_GPIO) = 0)
#   else
#     define DISABLE_RF8_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF8_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF8_GPIO) = 1)
#   define DISABLE_RF8_CN_INTERRUPT() (RXY_GPIO_CNIE(RF8_GPIO) = 0)

# else
#   define DISABLE_RF8_PULLUP() ((void) 0)
#   define DISABLE_RF8_PULLDOWN() ((void) 0)
#   define DISABLE_RF8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF8_AS_ANALOG()       \
    do {                              \
      ENABLE_RF8_ANALOG();            \
      CONFIG_RF8_AS_INPUT();          \
      DISABLE_RF8_OPENDRAIN();        \
      DISABLE_RF8_PULLUP();           \
      DISABLE_RF8_PULLDOWN();         \
    } while (0)

# define CONFIG_RF8_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF8_ANALOG();           \
      CONFIG_RF8_AS_INPUT();          \
      DISABLE_RF8_OPENDRAIN();        \
      DISABLE_RF8_PULLUP();           \
      DISABLE_RF8_PULLDOWN();         \
    } while (0)

# define CONFIG_RF8_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF8_ANALOG();           \
      CONFIG_RF8_AS_OUTPUT();         \
      DISABLE_RF8_OPENDRAIN();        \
      DISABLE_RF8_PULLUP();           \
      DISABLE_RF8_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF8: Provide GPIO for RF8


// Provide GPIO for RF9
// ====================
#ifdef _RF9
# ifndef RF9_GPIO
#   warning "RF9_GPIO not defined, but pin RF9 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF9_GPIO)
# define RF9_REMAPPABLE RXY_REMAPPABLE_PIN(RF9_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF9_GPIO)
#   define ENABLE_RF9_ANALOG()  (RXY_GPIO_PCFG(RF9_GPIO) = 1)
#   define DISABLE_RF9_ANALOG() (RXY_GPIO_PCFG(RF9_GPIO) = 0)
#   define RF9_AN_PORT RXY_AN_PORT(RF9_GPIO)
# else
#   define DISABLE_RF9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF9_AS_INPUT()  (_TRISF9 = 1)
# define CONFIG_RF9_AS_OUTPUT() (_TRISF9 = 0)

// Open-drain:
#if defined(_ODCF9)
# define ENABLE_RF9_OPENDRAIN()  (_ODCF9 = 1)
# define DISABLE_RF9_OPENDRAIN() (_ODCF9 = 0)
#elif defined(_ODF9)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF9_OPENDRAIN()  (_ODF9 = 1)
# define DISABLE_RF9_OPENDRAIN() (_ODF9 = 0)
#else
# define DISABLE_RF9_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF9_GPIO)
#   define ENABLE_RF9_PULLUP()  (RXY_GPIO_CNPUE(RF9_GPIO) = 1)
#   define DISABLE_RF9_PULLUP() (RXY_GPIO_CNPUE(RF9_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF9_GPIO)
#     define ENABLE_RF9_PULLDOWN()  (RXY_GPIO_CNPDE(RF9_GPIO) = 1)
#     define DISABLE_RF9_PULLDOWN() (RXY_GPIO_CNPDE(RF9_GPIO) = 0)
#   else
#     define DISABLE_RF9_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF9_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF9_GPIO) = 1)
#   define DISABLE_RF9_CN_INTERRUPT() (RXY_GPIO_CNIE(RF9_GPIO) = 0)

# else
#   define DISABLE_RF9_PULLUP() ((void) 0)
#   define DISABLE_RF9_PULLDOWN() ((void) 0)
#   define DISABLE_RF9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF9_AS_ANALOG()       \
    do {                              \
      ENABLE_RF9_ANALOG();            \
      CONFIG_RF9_AS_INPUT();          \
      DISABLE_RF9_OPENDRAIN();        \
      DISABLE_RF9_PULLUP();           \
      DISABLE_RF9_PULLDOWN();         \
    } while (0)

# define CONFIG_RF9_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF9_ANALOG();           \
      CONFIG_RF9_AS_INPUT();          \
      DISABLE_RF9_OPENDRAIN();        \
      DISABLE_RF9_PULLUP();           \
      DISABLE_RF9_PULLDOWN();         \
    } while (0)

# define CONFIG_RF9_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF9_ANALOG();           \
      CONFIG_RF9_AS_OUTPUT();         \
      DISABLE_RF9_OPENDRAIN();        \
      DISABLE_RF9_PULLUP();           \
      DISABLE_RF9_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF9: Provide GPIO for RF9


// Provide GPIO for RF10
// ====================
#ifdef _RF10
# ifndef RF10_GPIO
#   warning "RF10_GPIO not defined, but pin RF10 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF10_GPIO)
# define RF10_REMAPPABLE RXY_REMAPPABLE_PIN(RF10_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF10_GPIO)
#   define ENABLE_RF10_ANALOG()  (RXY_GPIO_PCFG(RF10_GPIO) = 1)
#   define DISABLE_RF10_ANALOG() (RXY_GPIO_PCFG(RF10_GPIO) = 0)
#   define RF10_AN_PORT RXY_AN_PORT(RF10_GPIO)
# else
#   define DISABLE_RF10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF10_AS_INPUT()  (_TRISF10 = 1)
# define CONFIG_RF10_AS_OUTPUT() (_TRISF10 = 0)

// Open-drain:
#if defined(_ODCF10)
# define ENABLE_RF10_OPENDRAIN()  (_ODCF10 = 1)
# define DISABLE_RF10_OPENDRAIN() (_ODCF10 = 0)
#elif defined(_ODF10)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF10_OPENDRAIN()  (_ODF10 = 1)
# define DISABLE_RF10_OPENDRAIN() (_ODF10 = 0)
#else
# define DISABLE_RF10_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF10_GPIO)
#   define ENABLE_RF10_PULLUP()  (RXY_GPIO_CNPUE(RF10_GPIO) = 1)
#   define DISABLE_RF10_PULLUP() (RXY_GPIO_CNPUE(RF10_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF10_GPIO)
#     define ENABLE_RF10_PULLDOWN()  (RXY_GPIO_CNPDE(RF10_GPIO) = 1)
#     define DISABLE_RF10_PULLDOWN() (RXY_GPIO_CNPDE(RF10_GPIO) = 0)
#   else
#     define DISABLE_RF10_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF10_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF10_GPIO) = 1)
#   define DISABLE_RF10_CN_INTERRUPT() (RXY_GPIO_CNIE(RF10_GPIO) = 0)

# else
#   define DISABLE_RF10_PULLUP() ((void) 0)
#   define DISABLE_RF10_PULLDOWN() ((void) 0)
#   define DISABLE_RF10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF10_AS_ANALOG()       \
    do {                              \
      ENABLE_RF10_ANALOG();            \
      CONFIG_RF10_AS_INPUT();          \
      DISABLE_RF10_OPENDRAIN();        \
      DISABLE_RF10_PULLUP();           \
      DISABLE_RF10_PULLDOWN();         \
    } while (0)

# define CONFIG_RF10_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF10_ANALOG();           \
      CONFIG_RF10_AS_INPUT();          \
      DISABLE_RF10_OPENDRAIN();        \
      DISABLE_RF10_PULLUP();           \
      DISABLE_RF10_PULLDOWN();         \
    } while (0)

# define CONFIG_RF10_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF10_ANALOG();           \
      CONFIG_RF10_AS_OUTPUT();         \
      DISABLE_RF10_OPENDRAIN();        \
      DISABLE_RF10_PULLUP();           \
      DISABLE_RF10_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF10: Provide GPIO for RF10


// Provide GPIO for RF11
// ====================
#ifdef _RF11
# ifndef RF11_GPIO
#   warning "RF11_GPIO not defined, but pin RF11 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF11_GPIO)
# define RF11_REMAPPABLE RXY_REMAPPABLE_PIN(RF11_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF11_GPIO)
#   define ENABLE_RF11_ANALOG()  (RXY_GPIO_PCFG(RF11_GPIO) = 1)
#   define DISABLE_RF11_ANALOG() (RXY_GPIO_PCFG(RF11_GPIO) = 0)
#   define RF11_AN_PORT RXY_AN_PORT(RF11_GPIO)
# else
#   define DISABLE_RF11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF11_AS_INPUT()  (_TRISF11 = 1)
# define CONFIG_RF11_AS_OUTPUT() (_TRISF11 = 0)

// Open-drain:
#if defined(_ODCF11)
# define ENABLE_RF11_OPENDRAIN()  (_ODCF11 = 1)
# define DISABLE_RF11_OPENDRAIN() (_ODCF11 = 0)
#elif defined(_ODF11)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF11_OPENDRAIN()  (_ODF11 = 1)
# define DISABLE_RF11_OPENDRAIN() (_ODF11 = 0)
#else
# define DISABLE_RF11_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF11_GPIO)
#   define ENABLE_RF11_PULLUP()  (RXY_GPIO_CNPUE(RF11_GPIO) = 1)
#   define DISABLE_RF11_PULLUP() (RXY_GPIO_CNPUE(RF11_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF11_GPIO)
#     define ENABLE_RF11_PULLDOWN()  (RXY_GPIO_CNPDE(RF11_GPIO) = 1)
#     define DISABLE_RF11_PULLDOWN() (RXY_GPIO_CNPDE(RF11_GPIO) = 0)
#   else
#     define DISABLE_RF11_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF11_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF11_GPIO) = 1)
#   define DISABLE_RF11_CN_INTERRUPT() (RXY_GPIO_CNIE(RF11_GPIO) = 0)

# else
#   define DISABLE_RF11_PULLUP() ((void) 0)
#   define DISABLE_RF11_PULLDOWN() ((void) 0)
#   define DISABLE_RF11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF11_AS_ANALOG()       \
    do {                              \
      ENABLE_RF11_ANALOG();            \
      CONFIG_RF11_AS_INPUT();          \
      DISABLE_RF11_OPENDRAIN();        \
      DISABLE_RF11_PULLUP();           \
      DISABLE_RF11_PULLDOWN();         \
    } while (0)

# define CONFIG_RF11_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF11_ANALOG();           \
      CONFIG_RF11_AS_INPUT();          \
      DISABLE_RF11_OPENDRAIN();        \
      DISABLE_RF11_PULLUP();           \
      DISABLE_RF11_PULLDOWN();         \
    } while (0)

# define CONFIG_RF11_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF11_ANALOG();           \
      CONFIG_RF11_AS_OUTPUT();         \
      DISABLE_RF11_OPENDRAIN();        \
      DISABLE_RF11_PULLUP();           \
      DISABLE_RF11_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF11: Provide GPIO for RF11


// Provide GPIO for RF12
// ====================
#ifdef _RF12
# ifndef RF12_GPIO
#   warning "RF12_GPIO not defined, but pin RF12 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF12_GPIO)
# define RF12_REMAPPABLE RXY_REMAPPABLE_PIN(RF12_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF12_GPIO)
#   define ENABLE_RF12_ANALOG()  (RXY_GPIO_PCFG(RF12_GPIO) = 1)
#   define DISABLE_RF12_ANALOG() (RXY_GPIO_PCFG(RF12_GPIO) = 0)
#   define RF12_AN_PORT RXY_AN_PORT(RF12_GPIO)
# else
#   define DISABLE_RF12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF12_AS_INPUT()  (_TRISF12 = 1)
# define CONFIG_RF12_AS_OUTPUT() (_TRISF12 = 0)

// Open-drain:
#if defined(_ODCF12)
# define ENABLE_RF12_OPENDRAIN()  (_ODCF12 = 1)
# define DISABLE_RF12_OPENDRAIN() (_ODCF12 = 0)
#elif defined(_ODF12)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF12_OPENDRAIN()  (_ODF12 = 1)
# define DISABLE_RF12_OPENDRAIN() (_ODF12 = 0)
#else
# define DISABLE_RF12_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF12_GPIO)
#   define ENABLE_RF12_PULLUP()  (RXY_GPIO_CNPUE(RF12_GPIO) = 1)
#   define DISABLE_RF12_PULLUP() (RXY_GPIO_CNPUE(RF12_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF12_GPIO)
#     define ENABLE_RF12_PULLDOWN()  (RXY_GPIO_CNPDE(RF12_GPIO) = 1)
#     define DISABLE_RF12_PULLDOWN() (RXY_GPIO_CNPDE(RF12_GPIO) = 0)
#   else
#     define DISABLE_RF12_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF12_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF12_GPIO) = 1)
#   define DISABLE_RF12_CN_INTERRUPT() (RXY_GPIO_CNIE(RF12_GPIO) = 0)

# else
#   define DISABLE_RF12_PULLUP() ((void) 0)
#   define DISABLE_RF12_PULLDOWN() ((void) 0)
#   define DISABLE_RF12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF12_AS_ANALOG()       \
    do {                              \
      ENABLE_RF12_ANALOG();            \
      CONFIG_RF12_AS_INPUT();          \
      DISABLE_RF12_OPENDRAIN();        \
      DISABLE_RF12_PULLUP();           \
      DISABLE_RF12_PULLDOWN();         \
    } while (0)

# define CONFIG_RF12_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF12_ANALOG();           \
      CONFIG_RF12_AS_INPUT();          \
      DISABLE_RF12_OPENDRAIN();        \
      DISABLE_RF12_PULLUP();           \
      DISABLE_RF12_PULLDOWN();         \
    } while (0)

# define CONFIG_RF12_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF12_ANALOG();           \
      CONFIG_RF12_AS_OUTPUT();         \
      DISABLE_RF12_OPENDRAIN();        \
      DISABLE_RF12_PULLUP();           \
      DISABLE_RF12_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF12: Provide GPIO for RF12


// Provide GPIO for RF13
// ====================
#ifdef _RF13
# ifndef RF13_GPIO
#   warning "RF13_GPIO not defined, but pin RF13 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF13_GPIO)
# define RF13_REMAPPABLE RXY_REMAPPABLE_PIN(RF13_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF13_GPIO)
#   define ENABLE_RF13_ANALOG()  (RXY_GPIO_PCFG(RF13_GPIO) = 1)
#   define DISABLE_RF13_ANALOG() (RXY_GPIO_PCFG(RF13_GPIO) = 0)
#   define RF13_AN_PORT RXY_AN_PORT(RF13_GPIO)
# else
#   define DISABLE_RF13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF13_AS_INPUT()  (_TRISF13 = 1)
# define CONFIG_RF13_AS_OUTPUT() (_TRISF13 = 0)

// Open-drain:
#if defined(_ODCF13)
# define ENABLE_RF13_OPENDRAIN()  (_ODCF13 = 1)
# define DISABLE_RF13_OPENDRAIN() (_ODCF13 = 0)
#elif defined(_ODF13)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF13_OPENDRAIN()  (_ODF13 = 1)
# define DISABLE_RF13_OPENDRAIN() (_ODF13 = 0)
#else
# define DISABLE_RF13_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF13_GPIO)
#   define ENABLE_RF13_PULLUP()  (RXY_GPIO_CNPUE(RF13_GPIO) = 1)
#   define DISABLE_RF13_PULLUP() (RXY_GPIO_CNPUE(RF13_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF13_GPIO)
#     define ENABLE_RF13_PULLDOWN()  (RXY_GPIO_CNPDE(RF13_GPIO) = 1)
#     define DISABLE_RF13_PULLDOWN() (RXY_GPIO_CNPDE(RF13_GPIO) = 0)
#   else
#     define DISABLE_RF13_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF13_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF13_GPIO) = 1)
#   define DISABLE_RF13_CN_INTERRUPT() (RXY_GPIO_CNIE(RF13_GPIO) = 0)

# else
#   define DISABLE_RF13_PULLUP() ((void) 0)
#   define DISABLE_RF13_PULLDOWN() ((void) 0)
#   define DISABLE_RF13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF13_AS_ANALOG()       \
    do {                              \
      ENABLE_RF13_ANALOG();            \
      CONFIG_RF13_AS_INPUT();          \
      DISABLE_RF13_OPENDRAIN();        \
      DISABLE_RF13_PULLUP();           \
      DISABLE_RF13_PULLDOWN();         \
    } while (0)

# define CONFIG_RF13_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF13_ANALOG();           \
      CONFIG_RF13_AS_INPUT();          \
      DISABLE_RF13_OPENDRAIN();        \
      DISABLE_RF13_PULLUP();           \
      DISABLE_RF13_PULLDOWN();         \
    } while (0)

# define CONFIG_RF13_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF13_ANALOG();           \
      CONFIG_RF13_AS_OUTPUT();         \
      DISABLE_RF13_OPENDRAIN();        \
      DISABLE_RF13_PULLUP();           \
      DISABLE_RF13_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF13: Provide GPIO for RF13


// Provide GPIO for RF14
// ====================
#ifdef _RF14
# ifndef RF14_GPIO
#   warning "RF14_GPIO not defined, but pin RF14 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF14_GPIO)
# define RF14_REMAPPABLE RXY_REMAPPABLE_PIN(RF14_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF14_GPIO)
#   define ENABLE_RF14_ANALOG()  (RXY_GPIO_PCFG(RF14_GPIO) = 1)
#   define DISABLE_RF14_ANALOG() (RXY_GPIO_PCFG(RF14_GPIO) = 0)
#   define RF14_AN_PORT RXY_AN_PORT(RF14_GPIO)
# else
#   define DISABLE_RF14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF14_AS_INPUT()  (_TRISF14 = 1)
# define CONFIG_RF14_AS_OUTPUT() (_TRISF14 = 0)

// Open-drain:
#if defined(_ODCF14)
# define ENABLE_RF14_OPENDRAIN()  (_ODCF14 = 1)
# define DISABLE_RF14_OPENDRAIN() (_ODCF14 = 0)
#elif defined(_ODF14)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF14_OPENDRAIN()  (_ODF14 = 1)
# define DISABLE_RF14_OPENDRAIN() (_ODF14 = 0)
#else
# define DISABLE_RF14_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF14_GPIO)
#   define ENABLE_RF14_PULLUP()  (RXY_GPIO_CNPUE(RF14_GPIO) = 1)
#   define DISABLE_RF14_PULLUP() (RXY_GPIO_CNPUE(RF14_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF14_GPIO)
#     define ENABLE_RF14_PULLDOWN()  (RXY_GPIO_CNPDE(RF14_GPIO) = 1)
#     define DISABLE_RF14_PULLDOWN() (RXY_GPIO_CNPDE(RF14_GPIO) = 0)
#   else
#     define DISABLE_RF14_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF14_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF14_GPIO) = 1)
#   define DISABLE_RF14_CN_INTERRUPT() (RXY_GPIO_CNIE(RF14_GPIO) = 0)

# else
#   define DISABLE_RF14_PULLUP() ((void) 0)
#   define DISABLE_RF14_PULLDOWN() ((void) 0)
#   define DISABLE_RF14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF14_AS_ANALOG()       \
    do {                              \
      ENABLE_RF14_ANALOG();            \
      CONFIG_RF14_AS_INPUT();          \
      DISABLE_RF14_OPENDRAIN();        \
      DISABLE_RF14_PULLUP();           \
      DISABLE_RF14_PULLDOWN();         \
    } while (0)

# define CONFIG_RF14_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF14_ANALOG();           \
      CONFIG_RF14_AS_INPUT();          \
      DISABLE_RF14_OPENDRAIN();        \
      DISABLE_RF14_PULLUP();           \
      DISABLE_RF14_PULLDOWN();         \
    } while (0)

# define CONFIG_RF14_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF14_ANALOG();           \
      CONFIG_RF14_AS_OUTPUT();         \
      DISABLE_RF14_OPENDRAIN();        \
      DISABLE_RF14_PULLUP();           \
      DISABLE_RF14_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF14: Provide GPIO for RF14


// Provide GPIO for RF15
// ====================
#ifdef _RF15
# ifndef RF15_GPIO
#   warning "RF15_GPIO not defined, but pin RF15 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RF15_GPIO)
# define RF15_REMAPPABLE RXY_REMAPPABLE_PIN(RF15_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RF15_GPIO)
#   define ENABLE_RF15_ANALOG()  (RXY_GPIO_PCFG(RF15_GPIO) = 1)
#   define DISABLE_RF15_ANALOG() (RXY_GPIO_PCFG(RF15_GPIO) = 0)
#   define RF15_AN_PORT RXY_AN_PORT(RF15_GPIO)
# else
#   define DISABLE_RF15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF15_AS_INPUT()  (_TRISF15 = 1)
# define CONFIG_RF15_AS_OUTPUT() (_TRISF15 = 0)

// Open-drain:
#if defined(_ODCF15)
# define ENABLE_RF15_OPENDRAIN()  (_ODCF15 = 1)
# define DISABLE_RF15_OPENDRAIN() (_ODCF15 = 0)
#elif defined(_ODF15)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RF15_OPENDRAIN()  (_ODF15 = 1)
# define DISABLE_RF15_OPENDRAIN() (_ODF15 = 0)
#else
# define DISABLE_RF15_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RF15_GPIO)
#   define ENABLE_RF15_PULLUP()  (RXY_GPIO_CNPUE(RF15_GPIO) = 1)
#   define DISABLE_RF15_PULLUP() (RXY_GPIO_CNPUE(RF15_GPIO) = 0)

#   if RXY_HAS_CNPDE(RF15_GPIO)
#     define ENABLE_RF15_PULLDOWN()  (RXY_GPIO_CNPDE(RF15_GPIO) = 1)
#     define DISABLE_RF15_PULLDOWN() (RXY_GPIO_CNPDE(RF15_GPIO) = 0)
#   else
#     define DISABLE_RF15_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RF15_CN_INTERRUPT()  (RXY_GPIO_CNIE(RF15_GPIO) = 1)
#   define DISABLE_RF15_CN_INTERRUPT() (RXY_GPIO_CNIE(RF15_GPIO) = 0)

# else
#   define DISABLE_RF15_PULLUP() ((void) 0)
#   define DISABLE_RF15_PULLDOWN() ((void) 0)
#   define DISABLE_RF15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RF15_AS_ANALOG()       \
    do {                              \
      ENABLE_RF15_ANALOG();            \
      CONFIG_RF15_AS_INPUT();          \
      DISABLE_RF15_OPENDRAIN();        \
      DISABLE_RF15_PULLUP();           \
      DISABLE_RF15_PULLDOWN();         \
    } while (0)

# define CONFIG_RF15_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RF15_ANALOG();           \
      CONFIG_RF15_AS_INPUT();          \
      DISABLE_RF15_OPENDRAIN();        \
      DISABLE_RF15_PULLUP();           \
      DISABLE_RF15_PULLDOWN();         \
    } while (0)

# define CONFIG_RF15_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RF15_ANALOG();           \
      CONFIG_RF15_AS_OUTPUT();         \
      DISABLE_RF15_OPENDRAIN();        \
      DISABLE_RF15_PULLUP();           \
      DISABLE_RF15_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RF15: Provide GPIO for RF15


// Provide GPIO for RG0
// ====================
#ifdef _RG0
# ifndef RG0_GPIO
#   warning "RG0_GPIO not defined, but pin RG0 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG0_GPIO)
# define RG0_REMAPPABLE RXY_REMAPPABLE_PIN(RG0_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG0_GPIO)
#   define ENABLE_RG0_ANALOG()  (RXY_GPIO_PCFG(RG0_GPIO) = 1)
#   define DISABLE_RG0_ANALOG() (RXY_GPIO_PCFG(RG0_GPIO) = 0)
#   define RG0_AN_PORT RXY_AN_PORT(RG0_GPIO)
# else
#   define DISABLE_RG0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG0_AS_INPUT()  (_TRISG0 = 1)
# define CONFIG_RG0_AS_OUTPUT() (_TRISG0 = 0)

// Open-drain:
#if defined(_ODCG0)
# define ENABLE_RG0_OPENDRAIN()  (_ODCG0 = 1)
# define DISABLE_RG0_OPENDRAIN() (_ODCG0 = 0)
#elif defined(_ODG0)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG0_OPENDRAIN()  (_ODG0 = 1)
# define DISABLE_RG0_OPENDRAIN() (_ODG0 = 0)
#else
# define DISABLE_RG0_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG0_GPIO)
#   define ENABLE_RG0_PULLUP()  (RXY_GPIO_CNPUE(RG0_GPIO) = 1)
#   define DISABLE_RG0_PULLUP() (RXY_GPIO_CNPUE(RG0_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG0_GPIO)
#     define ENABLE_RG0_PULLDOWN()  (RXY_GPIO_CNPDE(RG0_GPIO) = 1)
#     define DISABLE_RG0_PULLDOWN() (RXY_GPIO_CNPDE(RG0_GPIO) = 0)
#   else
#     define DISABLE_RG0_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG0_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG0_GPIO) = 1)
#   define DISABLE_RG0_CN_INTERRUPT() (RXY_GPIO_CNIE(RG0_GPIO) = 0)

# else
#   define DISABLE_RG0_PULLUP() ((void) 0)
#   define DISABLE_RG0_PULLDOWN() ((void) 0)
#   define DISABLE_RG0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG0_AS_ANALOG()       \
    do {                              \
      ENABLE_RG0_ANALOG();            \
      CONFIG_RG0_AS_INPUT();          \
      DISABLE_RG0_OPENDRAIN();        \
      DISABLE_RG0_PULLUP();           \
      DISABLE_RG0_PULLDOWN();         \
    } while (0)

# define CONFIG_RG0_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG0_ANALOG();           \
      CONFIG_RG0_AS_INPUT();          \
      DISABLE_RG0_OPENDRAIN();        \
      DISABLE_RG0_PULLUP();           \
      DISABLE_RG0_PULLDOWN();         \
    } while (0)

# define CONFIG_RG0_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG0_ANALOG();           \
      CONFIG_RG0_AS_OUTPUT();         \
      DISABLE_RG0_OPENDRAIN();        \
      DISABLE_RG0_PULLUP();           \
      DISABLE_RG0_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG0: Provide GPIO for RG0


// Provide GPIO for RG1
// ====================
#ifdef _RG1
# ifndef RG1_GPIO
#   warning "RG1_GPIO not defined, but pin RG1 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG1_GPIO)
# define RG1_REMAPPABLE RXY_REMAPPABLE_PIN(RG1_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG1_GPIO)
#   define ENABLE_RG1_ANALOG()  (RXY_GPIO_PCFG(RG1_GPIO) = 1)
#   define DISABLE_RG1_ANALOG() (RXY_GPIO_PCFG(RG1_GPIO) = 0)
#   define RG1_AN_PORT RXY_AN_PORT(RG1_GPIO)
# else
#   define DISABLE_RG1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG1_AS_INPUT()  (_TRISG1 = 1)
# define CONFIG_RG1_AS_OUTPUT() (_TRISG1 = 0)

// Open-drain:
#if defined(_ODCG1)
# define ENABLE_RG1_OPENDRAIN()  (_ODCG1 = 1)
# define DISABLE_RG1_OPENDRAIN() (_ODCG1 = 0)
#elif defined(_ODG1)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG1_OPENDRAIN()  (_ODG1 = 1)
# define DISABLE_RG1_OPENDRAIN() (_ODG1 = 0)
#else
# define DISABLE_RG1_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG1_GPIO)
#   define ENABLE_RG1_PULLUP()  (RXY_GPIO_CNPUE(RG1_GPIO) = 1)
#   define DISABLE_RG1_PULLUP() (RXY_GPIO_CNPUE(RG1_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG1_GPIO)
#     define ENABLE_RG1_PULLDOWN()  (RXY_GPIO_CNPDE(RG1_GPIO) = 1)
#     define DISABLE_RG1_PULLDOWN() (RXY_GPIO_CNPDE(RG1_GPIO) = 0)
#   else
#     define DISABLE_RG1_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG1_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG1_GPIO) = 1)
#   define DISABLE_RG1_CN_INTERRUPT() (RXY_GPIO_CNIE(RG1_GPIO) = 0)

# else
#   define DISABLE_RG1_PULLUP() ((void) 0)
#   define DISABLE_RG1_PULLDOWN() ((void) 0)
#   define DISABLE_RG1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG1_AS_ANALOG()       \
    do {                              \
      ENABLE_RG1_ANALOG();            \
      CONFIG_RG1_AS_INPUT();          \
      DISABLE_RG1_OPENDRAIN();        \
      DISABLE_RG1_PULLUP();           \
      DISABLE_RG1_PULLDOWN();         \
    } while (0)

# define CONFIG_RG1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG1_ANALOG();           \
      CONFIG_RG1_AS_INPUT();          \
      DISABLE_RG1_OPENDRAIN();        \
      DISABLE_RG1_PULLUP();           \
      DISABLE_RG1_PULLDOWN();         \
    } while (0)

# define CONFIG_RG1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG1_ANALOG();           \
      CONFIG_RG1_AS_OUTPUT();         \
      DISABLE_RG1_OPENDRAIN();        \
      DISABLE_RG1_PULLUP();           \
      DISABLE_RG1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG1: Provide GPIO for RG1


// Provide GPIO for RG2
// ====================
#ifdef _RG2
# ifndef RG2_GPIO
#   warning "RG2_GPIO not defined, but pin RG2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG2_GPIO)
# define RG2_REMAPPABLE RXY_REMAPPABLE_PIN(RG2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG2_GPIO)
#   define ENABLE_RG2_ANALOG()  (RXY_GPIO_PCFG(RG2_GPIO) = 1)
#   define DISABLE_RG2_ANALOG() (RXY_GPIO_PCFG(RG2_GPIO) = 0)
#   define RG2_AN_PORT RXY_AN_PORT(RG2_GPIO)
# else
#   define DISABLE_RG2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG2_AS_INPUT()  (_TRISG2 = 1)
# define CONFIG_RG2_AS_OUTPUT() (_TRISG2 = 0)

// Open-drain:
#if defined(_ODCG2)
# define ENABLE_RG2_OPENDRAIN()  (_ODCG2 = 1)
# define DISABLE_RG2_OPENDRAIN() (_ODCG2 = 0)
#elif defined(_ODG2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG2_OPENDRAIN()  (_ODG2 = 1)
# define DISABLE_RG2_OPENDRAIN() (_ODG2 = 0)
#else
# define DISABLE_RG2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG2_GPIO)
#   define ENABLE_RG2_PULLUP()  (RXY_GPIO_CNPUE(RG2_GPIO) = 1)
#   define DISABLE_RG2_PULLUP() (RXY_GPIO_CNPUE(RG2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG2_GPIO)
#     define ENABLE_RG2_PULLDOWN()  (RXY_GPIO_CNPDE(RG2_GPIO) = 1)
#     define DISABLE_RG2_PULLDOWN() (RXY_GPIO_CNPDE(RG2_GPIO) = 0)
#   else
#     define DISABLE_RG2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG2_GPIO) = 1)
#   define DISABLE_RG2_CN_INTERRUPT() (RXY_GPIO_CNIE(RG2_GPIO) = 0)

# else
#   define DISABLE_RG2_PULLUP() ((void) 0)
#   define DISABLE_RG2_PULLDOWN() ((void) 0)
#   define DISABLE_RG2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG2_AS_ANALOG()       \
    do {                              \
      ENABLE_RG2_ANALOG();            \
      CONFIG_RG2_AS_INPUT();          \
      DISABLE_RG2_OPENDRAIN();        \
      DISABLE_RG2_PULLUP();           \
      DISABLE_RG2_PULLDOWN();         \
    } while (0)

# define CONFIG_RG2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG2_ANALOG();           \
      CONFIG_RG2_AS_INPUT();          \
      DISABLE_RG2_OPENDRAIN();        \
      DISABLE_RG2_PULLUP();           \
      DISABLE_RG2_PULLDOWN();         \
    } while (0)

# define CONFIG_RG2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG2_ANALOG();           \
      CONFIG_RG2_AS_OUTPUT();         \
      DISABLE_RG2_OPENDRAIN();        \
      DISABLE_RG2_PULLUP();           \
      DISABLE_RG2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG2: Provide GPIO for RG2


// Provide GPIO for RG3
// ====================
#ifdef _RG3
# ifndef RG3_GPIO
#   warning "RG3_GPIO not defined, but pin RG3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG3_GPIO)
# define RG3_REMAPPABLE RXY_REMAPPABLE_PIN(RG3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG3_GPIO)
#   define ENABLE_RG3_ANALOG()  (RXY_GPIO_PCFG(RG3_GPIO) = 1)
#   define DISABLE_RG3_ANALOG() (RXY_GPIO_PCFG(RG3_GPIO) = 0)
#   define RG3_AN_PORT RXY_AN_PORT(RG3_GPIO)
# else
#   define DISABLE_RG3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG3_AS_INPUT()  (_TRISG3 = 1)
# define CONFIG_RG3_AS_OUTPUT() (_TRISG3 = 0)

// Open-drain:
#if defined(_ODCG3)
# define ENABLE_RG3_OPENDRAIN()  (_ODCG3 = 1)
# define DISABLE_RG3_OPENDRAIN() (_ODCG3 = 0)
#elif defined(_ODG3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG3_OPENDRAIN()  (_ODG3 = 1)
# define DISABLE_RG3_OPENDRAIN() (_ODG3 = 0)
#else
# define DISABLE_RG3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG3_GPIO)
#   define ENABLE_RG3_PULLUP()  (RXY_GPIO_CNPUE(RG3_GPIO) = 1)
#   define DISABLE_RG3_PULLUP() (RXY_GPIO_CNPUE(RG3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG3_GPIO)
#     define ENABLE_RG3_PULLDOWN()  (RXY_GPIO_CNPDE(RG3_GPIO) = 1)
#     define DISABLE_RG3_PULLDOWN() (RXY_GPIO_CNPDE(RG3_GPIO) = 0)
#   else
#     define DISABLE_RG3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG3_GPIO) = 1)
#   define DISABLE_RG3_CN_INTERRUPT() (RXY_GPIO_CNIE(RG3_GPIO) = 0)

# else
#   define DISABLE_RG3_PULLUP() ((void) 0)
#   define DISABLE_RG3_PULLDOWN() ((void) 0)
#   define DISABLE_RG3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG3_AS_ANALOG()       \
    do {                              \
      ENABLE_RG3_ANALOG();            \
      CONFIG_RG3_AS_INPUT();          \
      DISABLE_RG3_OPENDRAIN();        \
      DISABLE_RG3_PULLUP();           \
      DISABLE_RG3_PULLDOWN();         \
    } while (0)

# define CONFIG_RG3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG3_ANALOG();           \
      CONFIG_RG3_AS_INPUT();          \
      DISABLE_RG3_OPENDRAIN();        \
      DISABLE_RG3_PULLUP();           \
      DISABLE_RG3_PULLDOWN();         \
    } while (0)

# define CONFIG_RG3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG3_ANALOG();           \
      CONFIG_RG3_AS_OUTPUT();         \
      DISABLE_RG3_OPENDRAIN();        \
      DISABLE_RG3_PULLUP();           \
      DISABLE_RG3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG3: Provide GPIO for RG3


// Provide GPIO for RG4
// ====================
#ifdef _RG4
# ifndef RG4_GPIO
#   warning "RG4_GPIO not defined, but pin RG4 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG4_GPIO)
# define RG4_REMAPPABLE RXY_REMAPPABLE_PIN(RG4_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG4_GPIO)
#   define ENABLE_RG4_ANALOG()  (RXY_GPIO_PCFG(RG4_GPIO) = 1)
#   define DISABLE_RG4_ANALOG() (RXY_GPIO_PCFG(RG4_GPIO) = 0)
#   define RG4_AN_PORT RXY_AN_PORT(RG4_GPIO)
# else
#   define DISABLE_RG4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG4_AS_INPUT()  (_TRISG4 = 1)
# define CONFIG_RG4_AS_OUTPUT() (_TRISG4 = 0)

// Open-drain:
#if defined(_ODCG4)
# define ENABLE_RG4_OPENDRAIN()  (_ODCG4 = 1)
# define DISABLE_RG4_OPENDRAIN() (_ODCG4 = 0)
#elif defined(_ODG4)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG4_OPENDRAIN()  (_ODG4 = 1)
# define DISABLE_RG4_OPENDRAIN() (_ODG4 = 0)
#else
# define DISABLE_RG4_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG4_GPIO)
#   define ENABLE_RG4_PULLUP()  (RXY_GPIO_CNPUE(RG4_GPIO) = 1)
#   define DISABLE_RG4_PULLUP() (RXY_GPIO_CNPUE(RG4_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG4_GPIO)
#     define ENABLE_RG4_PULLDOWN()  (RXY_GPIO_CNPDE(RG4_GPIO) = 1)
#     define DISABLE_RG4_PULLDOWN() (RXY_GPIO_CNPDE(RG4_GPIO) = 0)
#   else
#     define DISABLE_RG4_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG4_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG4_GPIO) = 1)
#   define DISABLE_RG4_CN_INTERRUPT() (RXY_GPIO_CNIE(RG4_GPIO) = 0)

# else
#   define DISABLE_RG4_PULLUP() ((void) 0)
#   define DISABLE_RG4_PULLDOWN() ((void) 0)
#   define DISABLE_RG4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG4_AS_ANALOG()       \
    do {                              \
      ENABLE_RG4_ANALOG();            \
      CONFIG_RG4_AS_INPUT();          \
      DISABLE_RG4_OPENDRAIN();        \
      DISABLE_RG4_PULLUP();           \
      DISABLE_RG4_PULLDOWN();         \
    } while (0)

# define CONFIG_RG4_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG4_ANALOG();           \
      CONFIG_RG4_AS_INPUT();          \
      DISABLE_RG4_OPENDRAIN();        \
      DISABLE_RG4_PULLUP();           \
      DISABLE_RG4_PULLDOWN();         \
    } while (0)

# define CONFIG_RG4_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG4_ANALOG();           \
      CONFIG_RG4_AS_OUTPUT();         \
      DISABLE_RG4_OPENDRAIN();        \
      DISABLE_RG4_PULLUP();           \
      DISABLE_RG4_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG4: Provide GPIO for RG4


// Provide GPIO for RG5
// ====================
#ifdef _RG5
# ifndef RG5_GPIO
#   warning "RG5_GPIO not defined, but pin RG5 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG5_GPIO)
# define RG5_REMAPPABLE RXY_REMAPPABLE_PIN(RG5_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG5_GPIO)
#   define ENABLE_RG5_ANALOG()  (RXY_GPIO_PCFG(RG5_GPIO) = 1)
#   define DISABLE_RG5_ANALOG() (RXY_GPIO_PCFG(RG5_GPIO) = 0)
#   define RG5_AN_PORT RXY_AN_PORT(RG5_GPIO)
# else
#   define DISABLE_RG5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG5_AS_INPUT()  (_TRISG5 = 1)
# define CONFIG_RG5_AS_OUTPUT() (_TRISG5 = 0)

// Open-drain:
#if defined(_ODCG5)
# define ENABLE_RG5_OPENDRAIN()  (_ODCG5 = 1)
# define DISABLE_RG5_OPENDRAIN() (_ODCG5 = 0)
#elif defined(_ODG5)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG5_OPENDRAIN()  (_ODG5 = 1)
# define DISABLE_RG5_OPENDRAIN() (_ODG5 = 0)
#else
# define DISABLE_RG5_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG5_GPIO)
#   define ENABLE_RG5_PULLUP()  (RXY_GPIO_CNPUE(RG5_GPIO) = 1)
#   define DISABLE_RG5_PULLUP() (RXY_GPIO_CNPUE(RG5_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG5_GPIO)
#     define ENABLE_RG5_PULLDOWN()  (RXY_GPIO_CNPDE(RG5_GPIO) = 1)
#     define DISABLE_RG5_PULLDOWN() (RXY_GPIO_CNPDE(RG5_GPIO) = 0)
#   else
#     define DISABLE_RG5_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG5_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG5_GPIO) = 1)
#   define DISABLE_RG5_CN_INTERRUPT() (RXY_GPIO_CNIE(RG5_GPIO) = 0)

# else
#   define DISABLE_RG5_PULLUP() ((void) 0)
#   define DISABLE_RG5_PULLDOWN() ((void) 0)
#   define DISABLE_RG5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG5_AS_ANALOG()       \
    do {                              \
      ENABLE_RG5_ANALOG();            \
      CONFIG_RG5_AS_INPUT();          \
      DISABLE_RG5_OPENDRAIN();        \
      DISABLE_RG5_PULLUP();           \
      DISABLE_RG5_PULLDOWN();         \
    } while (0)

# define CONFIG_RG5_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG5_ANALOG();           \
      CONFIG_RG5_AS_INPUT();          \
      DISABLE_RG5_OPENDRAIN();        \
      DISABLE_RG5_PULLUP();           \
      DISABLE_RG5_PULLDOWN();         \
    } while (0)

# define CONFIG_RG5_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG5_ANALOG();           \
      CONFIG_RG5_AS_OUTPUT();         \
      DISABLE_RG5_OPENDRAIN();        \
      DISABLE_RG5_PULLUP();           \
      DISABLE_RG5_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG5: Provide GPIO for RG5


// Provide GPIO for RG6
// ====================
#ifdef _RG6
# ifndef RG6_GPIO
#   warning "RG6_GPIO not defined, but pin RG6 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG6_GPIO)
# define RG6_REMAPPABLE RXY_REMAPPABLE_PIN(RG6_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG6_GPIO)
#   define ENABLE_RG6_ANALOG()  (RXY_GPIO_PCFG(RG6_GPIO) = 1)
#   define DISABLE_RG6_ANALOG() (RXY_GPIO_PCFG(RG6_GPIO) = 0)
#   define RG6_AN_PORT RXY_AN_PORT(RG6_GPIO)
# else
#   define DISABLE_RG6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG6_AS_INPUT()  (_TRISG6 = 1)
# define CONFIG_RG6_AS_OUTPUT() (_TRISG6 = 0)

// Open-drain:
#if defined(_ODCG6)
# define ENABLE_RG6_OPENDRAIN()  (_ODCG6 = 1)
# define DISABLE_RG6_OPENDRAIN() (_ODCG6 = 0)
#elif defined(_ODG6)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG6_OPENDRAIN()  (_ODG6 = 1)
# define DISABLE_RG6_OPENDRAIN() (_ODG6 = 0)
#else
# define DISABLE_RG6_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG6_GPIO)
#   define ENABLE_RG6_PULLUP()  (RXY_GPIO_CNPUE(RG6_GPIO) = 1)
#   define DISABLE_RG6_PULLUP() (RXY_GPIO_CNPUE(RG6_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG6_GPIO)
#     define ENABLE_RG6_PULLDOWN()  (RXY_GPIO_CNPDE(RG6_GPIO) = 1)
#     define DISABLE_RG6_PULLDOWN() (RXY_GPIO_CNPDE(RG6_GPIO) = 0)
#   else
#     define DISABLE_RG6_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG6_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG6_GPIO) = 1)
#   define DISABLE_RG6_CN_INTERRUPT() (RXY_GPIO_CNIE(RG6_GPIO) = 0)

# else
#   define DISABLE_RG6_PULLUP() ((void) 0)
#   define DISABLE_RG6_PULLDOWN() ((void) 0)
#   define DISABLE_RG6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG6_AS_ANALOG()       \
    do {                              \
      ENABLE_RG6_ANALOG();            \
      CONFIG_RG6_AS_INPUT();          \
      DISABLE_RG6_OPENDRAIN();        \
      DISABLE_RG6_PULLUP();           \
      DISABLE_RG6_PULLDOWN();         \
    } while (0)

# define CONFIG_RG6_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG6_ANALOG();           \
      CONFIG_RG6_AS_INPUT();          \
      DISABLE_RG6_OPENDRAIN();        \
      DISABLE_RG6_PULLUP();           \
      DISABLE_RG6_PULLDOWN();         \
    } while (0)

# define CONFIG_RG6_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG6_ANALOG();           \
      CONFIG_RG6_AS_OUTPUT();         \
      DISABLE_RG6_OPENDRAIN();        \
      DISABLE_RG6_PULLUP();           \
      DISABLE_RG6_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG6: Provide GPIO for RG6


// Provide GPIO for RG7
// ====================
#ifdef _RG7
# ifndef RG7_GPIO
#   warning "RG7_GPIO not defined, but pin RG7 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG7_GPIO)
# define RG7_REMAPPABLE RXY_REMAPPABLE_PIN(RG7_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG7_GPIO)
#   define ENABLE_RG7_ANALOG()  (RXY_GPIO_PCFG(RG7_GPIO) = 1)
#   define DISABLE_RG7_ANALOG() (RXY_GPIO_PCFG(RG7_GPIO) = 0)
#   define RG7_AN_PORT RXY_AN_PORT(RG7_GPIO)
# else
#   define DISABLE_RG7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG7_AS_INPUT()  (_TRISG7 = 1)
# define CONFIG_RG7_AS_OUTPUT() (_TRISG7 = 0)

// Open-drain:
#if defined(_ODCG7)
# define ENABLE_RG7_OPENDRAIN()  (_ODCG7 = 1)
# define DISABLE_RG7_OPENDRAIN() (_ODCG7 = 0)
#elif defined(_ODG7)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG7_OPENDRAIN()  (_ODG7 = 1)
# define DISABLE_RG7_OPENDRAIN() (_ODG7 = 0)
#else
# define DISABLE_RG7_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG7_GPIO)
#   define ENABLE_RG7_PULLUP()  (RXY_GPIO_CNPUE(RG7_GPIO) = 1)
#   define DISABLE_RG7_PULLUP() (RXY_GPIO_CNPUE(RG7_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG7_GPIO)
#     define ENABLE_RG7_PULLDOWN()  (RXY_GPIO_CNPDE(RG7_GPIO) = 1)
#     define DISABLE_RG7_PULLDOWN() (RXY_GPIO_CNPDE(RG7_GPIO) = 0)
#   else
#     define DISABLE_RG7_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG7_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG7_GPIO) = 1)
#   define DISABLE_RG7_CN_INTERRUPT() (RXY_GPIO_CNIE(RG7_GPIO) = 0)

# else
#   define DISABLE_RG7_PULLUP() ((void) 0)
#   define DISABLE_RG7_PULLDOWN() ((void) 0)
#   define DISABLE_RG7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG7_AS_ANALOG()       \
    do {                              \
      ENABLE_RG7_ANALOG();            \
      CONFIG_RG7_AS_INPUT();          \
      DISABLE_RG7_OPENDRAIN();        \
      DISABLE_RG7_PULLUP();           \
      DISABLE_RG7_PULLDOWN();         \
    } while (0)

# define CONFIG_RG7_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG7_ANALOG();           \
      CONFIG_RG7_AS_INPUT();          \
      DISABLE_RG7_OPENDRAIN();        \
      DISABLE_RG7_PULLUP();           \
      DISABLE_RG7_PULLDOWN();         \
    } while (0)

# define CONFIG_RG7_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG7_ANALOG();           \
      CONFIG_RG7_AS_OUTPUT();         \
      DISABLE_RG7_OPENDRAIN();        \
      DISABLE_RG7_PULLUP();           \
      DISABLE_RG7_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG7: Provide GPIO for RG7


// Provide GPIO for RG8
// ====================
#ifdef _RG8
# ifndef RG8_GPIO
#   warning "RG8_GPIO not defined, but pin RG8 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG8_GPIO)
# define RG8_REMAPPABLE RXY_REMAPPABLE_PIN(RG8_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG8_GPIO)
#   define ENABLE_RG8_ANALOG()  (RXY_GPIO_PCFG(RG8_GPIO) = 1)
#   define DISABLE_RG8_ANALOG() (RXY_GPIO_PCFG(RG8_GPIO) = 0)
#   define RG8_AN_PORT RXY_AN_PORT(RG8_GPIO)
# else
#   define DISABLE_RG8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG8_AS_INPUT()  (_TRISG8 = 1)
# define CONFIG_RG8_AS_OUTPUT() (_TRISG8 = 0)

// Open-drain:
#if defined(_ODCG8)
# define ENABLE_RG8_OPENDRAIN()  (_ODCG8 = 1)
# define DISABLE_RG8_OPENDRAIN() (_ODCG8 = 0)
#elif defined(_ODG8)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG8_OPENDRAIN()  (_ODG8 = 1)
# define DISABLE_RG8_OPENDRAIN() (_ODG8 = 0)
#else
# define DISABLE_RG8_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG8_GPIO)
#   define ENABLE_RG8_PULLUP()  (RXY_GPIO_CNPUE(RG8_GPIO) = 1)
#   define DISABLE_RG8_PULLUP() (RXY_GPIO_CNPUE(RG8_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG8_GPIO)
#     define ENABLE_RG8_PULLDOWN()  (RXY_GPIO_CNPDE(RG8_GPIO) = 1)
#     define DISABLE_RG8_PULLDOWN() (RXY_GPIO_CNPDE(RG8_GPIO) = 0)
#   else
#     define DISABLE_RG8_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG8_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG8_GPIO) = 1)
#   define DISABLE_RG8_CN_INTERRUPT() (RXY_GPIO_CNIE(RG8_GPIO) = 0)

# else
#   define DISABLE_RG8_PULLUP() ((void) 0)
#   define DISABLE_RG8_PULLDOWN() ((void) 0)
#   define DISABLE_RG8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG8_AS_ANALOG()       \
    do {                              \
      ENABLE_RG8_ANALOG();            \
      CONFIG_RG8_AS_INPUT();          \
      DISABLE_RG8_OPENDRAIN();        \
      DISABLE_RG8_PULLUP();           \
      DISABLE_RG8_PULLDOWN();         \
    } while (0)

# define CONFIG_RG8_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG8_ANALOG();           \
      CONFIG_RG8_AS_INPUT();          \
      DISABLE_RG8_OPENDRAIN();        \
      DISABLE_RG8_PULLUP();           \
      DISABLE_RG8_PULLDOWN();         \
    } while (0)

# define CONFIG_RG8_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG8_ANALOG();           \
      CONFIG_RG8_AS_OUTPUT();         \
      DISABLE_RG8_OPENDRAIN();        \
      DISABLE_RG8_PULLUP();           \
      DISABLE_RG8_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG8: Provide GPIO for RG8


// Provide GPIO for RG9
// ====================
#ifdef _RG9
# ifndef RG9_GPIO
#   warning "RG9_GPIO not defined, but pin RG9 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG9_GPIO)
# define RG9_REMAPPABLE RXY_REMAPPABLE_PIN(RG9_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG9_GPIO)
#   define ENABLE_RG9_ANALOG()  (RXY_GPIO_PCFG(RG9_GPIO) = 1)
#   define DISABLE_RG9_ANALOG() (RXY_GPIO_PCFG(RG9_GPIO) = 0)
#   define RG9_AN_PORT RXY_AN_PORT(RG9_GPIO)
# else
#   define DISABLE_RG9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG9_AS_INPUT()  (_TRISG9 = 1)
# define CONFIG_RG9_AS_OUTPUT() (_TRISG9 = 0)

// Open-drain:
#if defined(_ODCG9)
# define ENABLE_RG9_OPENDRAIN()  (_ODCG9 = 1)
# define DISABLE_RG9_OPENDRAIN() (_ODCG9 = 0)
#elif defined(_ODG9)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG9_OPENDRAIN()  (_ODG9 = 1)
# define DISABLE_RG9_OPENDRAIN() (_ODG9 = 0)
#else
# define DISABLE_RG9_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG9_GPIO)
#   define ENABLE_RG9_PULLUP()  (RXY_GPIO_CNPUE(RG9_GPIO) = 1)
#   define DISABLE_RG9_PULLUP() (RXY_GPIO_CNPUE(RG9_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG9_GPIO)
#     define ENABLE_RG9_PULLDOWN()  (RXY_GPIO_CNPDE(RG9_GPIO) = 1)
#     define DISABLE_RG9_PULLDOWN() (RXY_GPIO_CNPDE(RG9_GPIO) = 0)
#   else
#     define DISABLE_RG9_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG9_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG9_GPIO) = 1)
#   define DISABLE_RG9_CN_INTERRUPT() (RXY_GPIO_CNIE(RG9_GPIO) = 0)

# else
#   define DISABLE_RG9_PULLUP() ((void) 0)
#   define DISABLE_RG9_PULLDOWN() ((void) 0)
#   define DISABLE_RG9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG9_AS_ANALOG()       \
    do {                              \
      ENABLE_RG9_ANALOG();            \
      CONFIG_RG9_AS_INPUT();          \
      DISABLE_RG9_OPENDRAIN();        \
      DISABLE_RG9_PULLUP();           \
      DISABLE_RG9_PULLDOWN();         \
    } while (0)

# define CONFIG_RG9_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG9_ANALOG();           \
      CONFIG_RG9_AS_INPUT();          \
      DISABLE_RG9_OPENDRAIN();        \
      DISABLE_RG9_PULLUP();           \
      DISABLE_RG9_PULLDOWN();         \
    } while (0)

# define CONFIG_RG9_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG9_ANALOG();           \
      CONFIG_RG9_AS_OUTPUT();         \
      DISABLE_RG9_OPENDRAIN();        \
      DISABLE_RG9_PULLUP();           \
      DISABLE_RG9_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG9: Provide GPIO for RG9


// Provide GPIO for RG10
// ====================
#ifdef _RG10
# ifndef RG10_GPIO
#   warning "RG10_GPIO not defined, but pin RG10 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG10_GPIO)
# define RG10_REMAPPABLE RXY_REMAPPABLE_PIN(RG10_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG10_GPIO)
#   define ENABLE_RG10_ANALOG()  (RXY_GPIO_PCFG(RG10_GPIO) = 1)
#   define DISABLE_RG10_ANALOG() (RXY_GPIO_PCFG(RG10_GPIO) = 0)
#   define RG10_AN_PORT RXY_AN_PORT(RG10_GPIO)
# else
#   define DISABLE_RG10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG10_AS_INPUT()  (_TRISG10 = 1)
# define CONFIG_RG10_AS_OUTPUT() (_TRISG10 = 0)

// Open-drain:
#if defined(_ODCG10)
# define ENABLE_RG10_OPENDRAIN()  (_ODCG10 = 1)
# define DISABLE_RG10_OPENDRAIN() (_ODCG10 = 0)
#elif defined(_ODG10)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG10_OPENDRAIN()  (_ODG10 = 1)
# define DISABLE_RG10_OPENDRAIN() (_ODG10 = 0)
#else
# define DISABLE_RG10_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG10_GPIO)
#   define ENABLE_RG10_PULLUP()  (RXY_GPIO_CNPUE(RG10_GPIO) = 1)
#   define DISABLE_RG10_PULLUP() (RXY_GPIO_CNPUE(RG10_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG10_GPIO)
#     define ENABLE_RG10_PULLDOWN()  (RXY_GPIO_CNPDE(RG10_GPIO) = 1)
#     define DISABLE_RG10_PULLDOWN() (RXY_GPIO_CNPDE(RG10_GPIO) = 0)
#   else
#     define DISABLE_RG10_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG10_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG10_GPIO) = 1)
#   define DISABLE_RG10_CN_INTERRUPT() (RXY_GPIO_CNIE(RG10_GPIO) = 0)

# else
#   define DISABLE_RG10_PULLUP() ((void) 0)
#   define DISABLE_RG10_PULLDOWN() ((void) 0)
#   define DISABLE_RG10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG10_AS_ANALOG()       \
    do {                              \
      ENABLE_RG10_ANALOG();            \
      CONFIG_RG10_AS_INPUT();          \
      DISABLE_RG10_OPENDRAIN();        \
      DISABLE_RG10_PULLUP();           \
      DISABLE_RG10_PULLDOWN();         \
    } while (0)

# define CONFIG_RG10_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG10_ANALOG();           \
      CONFIG_RG10_AS_INPUT();          \
      DISABLE_RG10_OPENDRAIN();        \
      DISABLE_RG10_PULLUP();           \
      DISABLE_RG10_PULLDOWN();         \
    } while (0)

# define CONFIG_RG10_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG10_ANALOG();           \
      CONFIG_RG10_AS_OUTPUT();         \
      DISABLE_RG10_OPENDRAIN();        \
      DISABLE_RG10_PULLUP();           \
      DISABLE_RG10_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG10: Provide GPIO for RG10


// Provide GPIO for RG11
// ====================
#ifdef _RG11
# ifndef RG11_GPIO
#   warning "RG11_GPIO not defined, but pin RG11 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG11_GPIO)
# define RG11_REMAPPABLE RXY_REMAPPABLE_PIN(RG11_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG11_GPIO)
#   define ENABLE_RG11_ANALOG()  (RXY_GPIO_PCFG(RG11_GPIO) = 1)
#   define DISABLE_RG11_ANALOG() (RXY_GPIO_PCFG(RG11_GPIO) = 0)
#   define RG11_AN_PORT RXY_AN_PORT(RG11_GPIO)
# else
#   define DISABLE_RG11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG11_AS_INPUT()  (_TRISG11 = 1)
# define CONFIG_RG11_AS_OUTPUT() (_TRISG11 = 0)

// Open-drain:
#if defined(_ODCG11)
# define ENABLE_RG11_OPENDRAIN()  (_ODCG11 = 1)
# define DISABLE_RG11_OPENDRAIN() (_ODCG11 = 0)
#elif defined(_ODG11)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG11_OPENDRAIN()  (_ODG11 = 1)
# define DISABLE_RG11_OPENDRAIN() (_ODG11 = 0)
#else
# define DISABLE_RG11_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG11_GPIO)
#   define ENABLE_RG11_PULLUP()  (RXY_GPIO_CNPUE(RG11_GPIO) = 1)
#   define DISABLE_RG11_PULLUP() (RXY_GPIO_CNPUE(RG11_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG11_GPIO)
#     define ENABLE_RG11_PULLDOWN()  (RXY_GPIO_CNPDE(RG11_GPIO) = 1)
#     define DISABLE_RG11_PULLDOWN() (RXY_GPIO_CNPDE(RG11_GPIO) = 0)
#   else
#     define DISABLE_RG11_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG11_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG11_GPIO) = 1)
#   define DISABLE_RG11_CN_INTERRUPT() (RXY_GPIO_CNIE(RG11_GPIO) = 0)

# else
#   define DISABLE_RG11_PULLUP() ((void) 0)
#   define DISABLE_RG11_PULLDOWN() ((void) 0)
#   define DISABLE_RG11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG11_AS_ANALOG()       \
    do {                              \
      ENABLE_RG11_ANALOG();            \
      CONFIG_RG11_AS_INPUT();          \
      DISABLE_RG11_OPENDRAIN();        \
      DISABLE_RG11_PULLUP();           \
      DISABLE_RG11_PULLDOWN();         \
    } while (0)

# define CONFIG_RG11_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG11_ANALOG();           \
      CONFIG_RG11_AS_INPUT();          \
      DISABLE_RG11_OPENDRAIN();        \
      DISABLE_RG11_PULLUP();           \
      DISABLE_RG11_PULLDOWN();         \
    } while (0)

# define CONFIG_RG11_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG11_ANALOG();           \
      CONFIG_RG11_AS_OUTPUT();         \
      DISABLE_RG11_OPENDRAIN();        \
      DISABLE_RG11_PULLUP();           \
      DISABLE_RG11_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG11: Provide GPIO for RG11


// Provide GPIO for RG12
// ====================
#ifdef _RG12
# ifndef RG12_GPIO
#   warning "RG12_GPIO not defined, but pin RG12 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG12_GPIO)
# define RG12_REMAPPABLE RXY_REMAPPABLE_PIN(RG12_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG12_GPIO)
#   define ENABLE_RG12_ANALOG()  (RXY_GPIO_PCFG(RG12_GPIO) = 1)
#   define DISABLE_RG12_ANALOG() (RXY_GPIO_PCFG(RG12_GPIO) = 0)
#   define RG12_AN_PORT RXY_AN_PORT(RG12_GPIO)
# else
#   define DISABLE_RG12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG12_AS_INPUT()  (_TRISG12 = 1)
# define CONFIG_RG12_AS_OUTPUT() (_TRISG12 = 0)

// Open-drain:
#if defined(_ODCG12)
# define ENABLE_RG12_OPENDRAIN()  (_ODCG12 = 1)
# define DISABLE_RG12_OPENDRAIN() (_ODCG12 = 0)
#elif defined(_ODG12)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG12_OPENDRAIN()  (_ODG12 = 1)
# define DISABLE_RG12_OPENDRAIN() (_ODG12 = 0)
#else
# define DISABLE_RG12_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG12_GPIO)
#   define ENABLE_RG12_PULLUP()  (RXY_GPIO_CNPUE(RG12_GPIO) = 1)
#   define DISABLE_RG12_PULLUP() (RXY_GPIO_CNPUE(RG12_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG12_GPIO)
#     define ENABLE_RG12_PULLDOWN()  (RXY_GPIO_CNPDE(RG12_GPIO) = 1)
#     define DISABLE_RG12_PULLDOWN() (RXY_GPIO_CNPDE(RG12_GPIO) = 0)
#   else
#     define DISABLE_RG12_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG12_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG12_GPIO) = 1)
#   define DISABLE_RG12_CN_INTERRUPT() (RXY_GPIO_CNIE(RG12_GPIO) = 0)

# else
#   define DISABLE_RG12_PULLUP() ((void) 0)
#   define DISABLE_RG12_PULLDOWN() ((void) 0)
#   define DISABLE_RG12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG12_AS_ANALOG()       \
    do {                              \
      ENABLE_RG12_ANALOG();            \
      CONFIG_RG12_AS_INPUT();          \
      DISABLE_RG12_OPENDRAIN();        \
      DISABLE_RG12_PULLUP();           \
      DISABLE_RG12_PULLDOWN();         \
    } while (0)

# define CONFIG_RG12_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG12_ANALOG();           \
      CONFIG_RG12_AS_INPUT();          \
      DISABLE_RG12_OPENDRAIN();        \
      DISABLE_RG12_PULLUP();           \
      DISABLE_RG12_PULLDOWN();         \
    } while (0)

# define CONFIG_RG12_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG12_ANALOG();           \
      CONFIG_RG12_AS_OUTPUT();         \
      DISABLE_RG12_OPENDRAIN();        \
      DISABLE_RG12_PULLUP();           \
      DISABLE_RG12_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG12: Provide GPIO for RG12


// Provide GPIO for RG13
// ====================
#ifdef _RG13
# ifndef RG13_GPIO
#   warning "RG13_GPIO not defined, but pin RG13 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG13_GPIO)
# define RG13_REMAPPABLE RXY_REMAPPABLE_PIN(RG13_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG13_GPIO)
#   define ENABLE_RG13_ANALOG()  (RXY_GPIO_PCFG(RG13_GPIO) = 1)
#   define DISABLE_RG13_ANALOG() (RXY_GPIO_PCFG(RG13_GPIO) = 0)
#   define RG13_AN_PORT RXY_AN_PORT(RG13_GPIO)
# else
#   define DISABLE_RG13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG13_AS_INPUT()  (_TRISG13 = 1)
# define CONFIG_RG13_AS_OUTPUT() (_TRISG13 = 0)

// Open-drain:
#if defined(_ODCG13)
# define ENABLE_RG13_OPENDRAIN()  (_ODCG13 = 1)
# define DISABLE_RG13_OPENDRAIN() (_ODCG13 = 0)
#elif defined(_ODG13)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG13_OPENDRAIN()  (_ODG13 = 1)
# define DISABLE_RG13_OPENDRAIN() (_ODG13 = 0)
#else
# define DISABLE_RG13_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG13_GPIO)
#   define ENABLE_RG13_PULLUP()  (RXY_GPIO_CNPUE(RG13_GPIO) = 1)
#   define DISABLE_RG13_PULLUP() (RXY_GPIO_CNPUE(RG13_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG13_GPIO)
#     define ENABLE_RG13_PULLDOWN()  (RXY_GPIO_CNPDE(RG13_GPIO) = 1)
#     define DISABLE_RG13_PULLDOWN() (RXY_GPIO_CNPDE(RG13_GPIO) = 0)
#   else
#     define DISABLE_RG13_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG13_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG13_GPIO) = 1)
#   define DISABLE_RG13_CN_INTERRUPT() (RXY_GPIO_CNIE(RG13_GPIO) = 0)

# else
#   define DISABLE_RG13_PULLUP() ((void) 0)
#   define DISABLE_RG13_PULLDOWN() ((void) 0)
#   define DISABLE_RG13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG13_AS_ANALOG()       \
    do {                              \
      ENABLE_RG13_ANALOG();            \
      CONFIG_RG13_AS_INPUT();          \
      DISABLE_RG13_OPENDRAIN();        \
      DISABLE_RG13_PULLUP();           \
      DISABLE_RG13_PULLDOWN();         \
    } while (0)

# define CONFIG_RG13_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG13_ANALOG();           \
      CONFIG_RG13_AS_INPUT();          \
      DISABLE_RG13_OPENDRAIN();        \
      DISABLE_RG13_PULLUP();           \
      DISABLE_RG13_PULLDOWN();         \
    } while (0)

# define CONFIG_RG13_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG13_ANALOG();           \
      CONFIG_RG13_AS_OUTPUT();         \
      DISABLE_RG13_OPENDRAIN();        \
      DISABLE_RG13_PULLUP();           \
      DISABLE_RG13_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG13: Provide GPIO for RG13


// Provide GPIO for RG14
// ====================
#ifdef _RG14
# ifndef RG14_GPIO
#   warning "RG14_GPIO not defined, but pin RG14 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG14_GPIO)
# define RG14_REMAPPABLE RXY_REMAPPABLE_PIN(RG14_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG14_GPIO)
#   define ENABLE_RG14_ANALOG()  (RXY_GPIO_PCFG(RG14_GPIO) = 1)
#   define DISABLE_RG14_ANALOG() (RXY_GPIO_PCFG(RG14_GPIO) = 0)
#   define RG14_AN_PORT RXY_AN_PORT(RG14_GPIO)
# else
#   define DISABLE_RG14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG14_AS_INPUT()  (_TRISG14 = 1)
# define CONFIG_RG14_AS_OUTPUT() (_TRISG14 = 0)

// Open-drain:
#if defined(_ODCG14)
# define ENABLE_RG14_OPENDRAIN()  (_ODCG14 = 1)
# define DISABLE_RG14_OPENDRAIN() (_ODCG14 = 0)
#elif defined(_ODG14)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG14_OPENDRAIN()  (_ODG14 = 1)
# define DISABLE_RG14_OPENDRAIN() (_ODG14 = 0)
#else
# define DISABLE_RG14_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG14_GPIO)
#   define ENABLE_RG14_PULLUP()  (RXY_GPIO_CNPUE(RG14_GPIO) = 1)
#   define DISABLE_RG14_PULLUP() (RXY_GPIO_CNPUE(RG14_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG14_GPIO)
#     define ENABLE_RG14_PULLDOWN()  (RXY_GPIO_CNPDE(RG14_GPIO) = 1)
#     define DISABLE_RG14_PULLDOWN() (RXY_GPIO_CNPDE(RG14_GPIO) = 0)
#   else
#     define DISABLE_RG14_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG14_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG14_GPIO) = 1)
#   define DISABLE_RG14_CN_INTERRUPT() (RXY_GPIO_CNIE(RG14_GPIO) = 0)

# else
#   define DISABLE_RG14_PULLUP() ((void) 0)
#   define DISABLE_RG14_PULLDOWN() ((void) 0)
#   define DISABLE_RG14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG14_AS_ANALOG()       \
    do {                              \
      ENABLE_RG14_ANALOG();            \
      CONFIG_RG14_AS_INPUT();          \
      DISABLE_RG14_OPENDRAIN();        \
      DISABLE_RG14_PULLUP();           \
      DISABLE_RG14_PULLDOWN();         \
    } while (0)

# define CONFIG_RG14_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG14_ANALOG();           \
      CONFIG_RG14_AS_INPUT();          \
      DISABLE_RG14_OPENDRAIN();        \
      DISABLE_RG14_PULLUP();           \
      DISABLE_RG14_PULLDOWN();         \
    } while (0)

# define CONFIG_RG14_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG14_ANALOG();           \
      CONFIG_RG14_AS_OUTPUT();         \
      DISABLE_RG14_OPENDRAIN();        \
      DISABLE_RG14_PULLUP();           \
      DISABLE_RG14_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG14: Provide GPIO for RG14


// Provide GPIO for RG15
// ====================
#ifdef _RG15
# ifndef RG15_GPIO
#   warning "RG15_GPIO not defined, but pin RG15 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RG15_GPIO)
# define RG15_REMAPPABLE RXY_REMAPPABLE_PIN(RG15_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RG15_GPIO)
#   define ENABLE_RG15_ANALOG()  (RXY_GPIO_PCFG(RG15_GPIO) = 1)
#   define DISABLE_RG15_ANALOG() (RXY_GPIO_PCFG(RG15_GPIO) = 0)
#   define RG15_AN_PORT RXY_AN_PORT(RG15_GPIO)
# else
#   define DISABLE_RG15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG15_AS_INPUT()  (_TRISG15 = 1)
# define CONFIG_RG15_AS_OUTPUT() (_TRISG15 = 0)

// Open-drain:
#if defined(_ODCG15)
# define ENABLE_RG15_OPENDRAIN()  (_ODCG15 = 1)
# define DISABLE_RG15_OPENDRAIN() (_ODCG15 = 0)
#elif defined(_ODG15)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RG15_OPENDRAIN()  (_ODG15 = 1)
# define DISABLE_RG15_OPENDRAIN() (_ODG15 = 0)
#else
# define DISABLE_RG15_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RG15_GPIO)
#   define ENABLE_RG15_PULLUP()  (RXY_GPIO_CNPUE(RG15_GPIO) = 1)
#   define DISABLE_RG15_PULLUP() (RXY_GPIO_CNPUE(RG15_GPIO) = 0)

#   if RXY_HAS_CNPDE(RG15_GPIO)
#     define ENABLE_RG15_PULLDOWN()  (RXY_GPIO_CNPDE(RG15_GPIO) = 1)
#     define DISABLE_RG15_PULLDOWN() (RXY_GPIO_CNPDE(RG15_GPIO) = 0)
#   else
#     define DISABLE_RG15_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RG15_CN_INTERRUPT()  (RXY_GPIO_CNIE(RG15_GPIO) = 1)
#   define DISABLE_RG15_CN_INTERRUPT() (RXY_GPIO_CNIE(RG15_GPIO) = 0)

# else
#   define DISABLE_RG15_PULLUP() ((void) 0)
#   define DISABLE_RG15_PULLDOWN() ((void) 0)
#   define DISABLE_RG15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RG15_AS_ANALOG()       \
    do {                              \
      ENABLE_RG15_ANALOG();            \
      CONFIG_RG15_AS_INPUT();          \
      DISABLE_RG15_OPENDRAIN();        \
      DISABLE_RG15_PULLUP();           \
      DISABLE_RG15_PULLDOWN();         \
    } while (0)

# define CONFIG_RG15_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RG15_ANALOG();           \
      CONFIG_RG15_AS_INPUT();          \
      DISABLE_RG15_OPENDRAIN();        \
      DISABLE_RG15_PULLUP();           \
      DISABLE_RG15_PULLDOWN();         \
    } while (0)

# define CONFIG_RG15_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RG15_ANALOG();           \
      CONFIG_RG15_AS_OUTPUT();         \
      DISABLE_RG15_OPENDRAIN();        \
      DISABLE_RG15_PULLUP();           \
      DISABLE_RG15_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RG15: Provide GPIO for RG15


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
# define CONFIG_RT1_AS_ANALOG()       \
    do {                              \
      ENABLE_RT1_ANALOG();            \
      CONFIG_RT1_AS_INPUT();          \
      DISABLE_RT1_OPENDRAIN();        \
      DISABLE_RT1_PULLUP();           \
      DISABLE_RT1_PULLDOWN();         \
    } while (0)

# define CONFIG_RT1_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RT1_ANALOG();           \
      CONFIG_RT1_AS_INPUT();          \
      DISABLE_RT1_OPENDRAIN();        \
      DISABLE_RT1_PULLUP();           \
      DISABLE_RT1_PULLDOWN();         \
    } while (0)

# define CONFIG_RT1_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RT1_ANALOG();           \
      CONFIG_RT1_AS_OUTPUT();         \
      DISABLE_RT1_OPENDRAIN();        \
      DISABLE_RT1_PULLUP();           \
      DISABLE_RT1_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RT1: Provide GPIO for RT1


// Provide GPIO for RT2
// ====================
#ifdef _RT2
# ifndef RT2_GPIO
#   warning "RT2_GPIO not defined, but pin RT2 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RT2_GPIO)
# define RT2_REMAPPABLE RXY_REMAPPABLE_PIN(RT2_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RT2_GPIO)
#   define ENABLE_RT2_ANALOG()  (RXY_GPIO_PCFG(RT2_GPIO) = 1)
#   define DISABLE_RT2_ANALOG() (RXY_GPIO_PCFG(RT2_GPIO) = 0)
#   define RT2_AN_PORT RXY_AN_PORT(RT2_GPIO)
# else
#   define DISABLE_RT2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RT2_AS_INPUT()  (_TRIST2 = 1)
# define CONFIG_RT2_AS_OUTPUT() (_TRIST2 = 0)

// Open-drain:
#if defined(_ODCT2)
# define ENABLE_RT2_OPENDRAIN()  (_ODCT2 = 1)
# define DISABLE_RT2_OPENDRAIN() (_ODCT2 = 0)
#elif defined(_ODT2)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RT2_OPENDRAIN()  (_ODT2 = 1)
# define DISABLE_RT2_OPENDRAIN() (_ODT2 = 0)
#else
# define DISABLE_RT2_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RT2_GPIO)
#   define ENABLE_RT2_PULLUP()  (RXY_GPIO_CNPUE(RT2_GPIO) = 1)
#   define DISABLE_RT2_PULLUP() (RXY_GPIO_CNPUE(RT2_GPIO) = 0)

#   if RXY_HAS_CNPDE(RT2_GPIO)
#     define ENABLE_RT2_PULLDOWN()  (RXY_GPIO_CNPDE(RT2_GPIO) = 1)
#     define DISABLE_RT2_PULLDOWN() (RXY_GPIO_CNPDE(RT2_GPIO) = 0)
#   else
#     define DISABLE_RT2_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RT2_CN_INTERRUPT()  (RXY_GPIO_CNIE(RT2_GPIO) = 1)
#   define DISABLE_RT2_CN_INTERRUPT() (RXY_GPIO_CNIE(RT2_GPIO) = 0)

# else
#   define DISABLE_RT2_PULLUP() ((void) 0)
#   define DISABLE_RT2_PULLDOWN() ((void) 0)
#   define DISABLE_RT2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RT2_AS_ANALOG()       \
    do {                              \
      ENABLE_RT2_ANALOG();            \
      CONFIG_RT2_AS_INPUT();          \
      DISABLE_RT2_OPENDRAIN();        \
      DISABLE_RT2_PULLUP();           \
      DISABLE_RT2_PULLDOWN();         \
    } while (0)

# define CONFIG_RT2_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RT2_ANALOG();           \
      CONFIG_RT2_AS_INPUT();          \
      DISABLE_RT2_OPENDRAIN();        \
      DISABLE_RT2_PULLUP();           \
      DISABLE_RT2_PULLDOWN();         \
    } while (0)

# define CONFIG_RT2_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RT2_ANALOG();           \
      CONFIG_RT2_AS_OUTPUT();         \
      DISABLE_RT2_OPENDRAIN();        \
      DISABLE_RT2_PULLUP();           \
      DISABLE_RT2_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RT2: Provide GPIO for RT2


// Provide GPIO for RT3
// ====================
#ifdef _RT3
# ifndef RT3_GPIO
#   warning "RT3_GPIO not defined, but pin RT3 exists. No GPIO and related"
#   warning "configuration macros will be provided for this pin. Edit the table"
#   warning "in this file to provide the information needed to generate this"
#   warning "configuration macros."
# endif

// Low-level config
// ----------------
// Remappable pins:
#if RXY_HAS_REMAPPABLE(RT3_GPIO)
# define RT3_REMAPPABLE RXY_REMAPPABLE_PIN(RT3_GPIO)
#endif

// Analog:
# if RXY_HAS_ANALOG(RT3_GPIO)
#   define ENABLE_RT3_ANALOG()  (RXY_GPIO_PCFG(RT3_GPIO) = 1)
#   define DISABLE_RT3_ANALOG() (RXY_GPIO_PCFG(RT3_GPIO) = 0)
#   define RT3_AN_PORT RXY_AN_PORT(RT3_GPIO)
# else
#   define DISABLE_RT3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RT3_AS_INPUT()  (_TRIST3 = 1)
# define CONFIG_RT3_AS_OUTPUT() (_TRIST3 = 0)

// Open-drain:
#if defined(_ODCT3)
# define ENABLE_RT3_OPENDRAIN()  (_ODCT3 = 1)
# define DISABLE_RT3_OPENDRAIN() (_ODCT3 = 0)
#elif defined(_ODT3)   // The PIF24F names this bit _OD instead of _ODC.
# define ENABLE_RT3_OPENDRAIN()  (_ODT3 = 1)
# define DISABLE_RT3_OPENDRAIN() (_ODT3 = 0)
#else
# define DISABLE_RT3_OPENDRAIN() ((void) 0)
#endif

// Change notification, pullups and pulldowns:
# if RXY_HAS_CHANGE_NOTIFICATION(RT3_GPIO)
#   define ENABLE_RT3_PULLUP()  (RXY_GPIO_CNPUE(RT3_GPIO) = 1)
#   define DISABLE_RT3_PULLUP() (RXY_GPIO_CNPUE(RT3_GPIO) = 0)

#   if RXY_HAS_CNPDE(RT3_GPIO)
#     define ENABLE_RT3_PULLDOWN()  (RXY_GPIO_CNPDE(RT3_GPIO) = 1)
#     define DISABLE_RT3_PULLDOWN() (RXY_GPIO_CNPDE(RT3_GPIO) = 0)
#   else
#     define DISABLE_RT3_PULLDOWN() ((void) 0)
#   endif

#   define ENABLE_RT3_CN_INTERRUPT()  (RXY_GPIO_CNIE(RT3_GPIO) = 1)
#   define DISABLE_RT3_CN_INTERRUPT() (RXY_GPIO_CNIE(RT3_GPIO) = 0)

# else
#   define DISABLE_RT3_PULLUP() ((void) 0)
#   define DISABLE_RT3_PULLDOWN() ((void) 0)
#   define DISABLE_RT3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# define CONFIG_RT3_AS_ANALOG()       \
    do {                              \
      ENABLE_RT3_ANALOG();            \
      CONFIG_RT3_AS_INPUT();          \
      DISABLE_RT3_OPENDRAIN();        \
      DISABLE_RT3_PULLUP();           \
      DISABLE_RT3_PULLDOWN();         \
    } while (0)

# define CONFIG_RT3_AS_DIG_INPUT()    \
    do {                              \
      DISABLE_RT3_ANALOG();           \
      CONFIG_RT3_AS_INPUT();          \
      DISABLE_RT3_OPENDRAIN();        \
      DISABLE_RT3_PULLUP();           \
      DISABLE_RT3_PULLDOWN();         \
    } while (0)

# define CONFIG_RT3_AS_DIG_OUTPUT()   \
    do {                              \
      DISABLE_RT3_ANALOG();           \
      CONFIG_RT3_AS_OUTPUT();         \
      DISABLE_RT3_OPENDRAIN();        \
      DISABLE_RT3_PULLUP();           \
      DISABLE_RT3_PULLDOWN();         \
    } while (0)

#endif // #ifdef _RT3: Provide GPIO for RT3


