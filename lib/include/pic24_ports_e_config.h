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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA0
#   define ENABLE_RA0_ANALOG()  (_ANSA0 = 1)
#   define DISABLE_RA0_ANALOG() (_ANSA0 = 0)
# else
#   define DISABLE_RA0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA0_AS_INPUT()  (_TRISA0 = 1)
# define CONFIG_RA0_AS_OUTPUT() (_TRISA0 = 0)

// Open-drain:
# if defined(_ODCA0)
#   define ENABLE_RA0_OPENDRAIN()  (_ODCA0 = 1)
#   define DISABLE_RA0_OPENDRAIN() (_ODCA0 = 0)
# else
#   define DISABLE_RA0_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA0
#   define ENABLE_RA0_PULLUP()  (_CNPUA0 = 1)
#   define DISABLE_RA0_PULLUP() (_CNPUA0 = 0)

#   define ENABLE_RA0_PULLDOWN()  (_CNPDA0 = 1)
#   define DISABLE_RA0_PULLDOWN() (_CNPDA0 = 0)

#   define ENABLE_RA0_CN_INTERRUPT()  (_CNIEA0 = 1)
#   define DISABLE_RA0_CN_INTERRUPT() (_CNIEA0 = 0)

# else
#   define DISABLE_RA0_PULLUP() ((void) 0)
#   define DISABLE_RA0_PULLDOWN() ((void) 0)
#   define DISABLE_RA0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA0
#   define CONFIG_RA0_AS_ANALOG()       \
      do {                              \
        ENABLE_RA0_ANALOG();            \
        CONFIG_RA0_AS_INPUT();          \
        DISABLE_RA0_OPENDRAIN();        \
        DISABLE_RA0_PULLUP();           \
        DISABLE_RA0_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA1
#   define ENABLE_RA1_ANALOG()  (_ANSA1 = 1)
#   define DISABLE_RA1_ANALOG() (_ANSA1 = 0)
# else
#   define DISABLE_RA1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA1_AS_INPUT()  (_TRISA1 = 1)
# define CONFIG_RA1_AS_OUTPUT() (_TRISA1 = 0)

// Open-drain:
# if defined(_ODCA1)
#   define ENABLE_RA1_OPENDRAIN()  (_ODCA1 = 1)
#   define DISABLE_RA1_OPENDRAIN() (_ODCA1 = 0)
# else
#   define DISABLE_RA1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA1
#   define ENABLE_RA1_PULLUP()  (_CNPUA1 = 1)
#   define DISABLE_RA1_PULLUP() (_CNPUA1 = 0)

#   define ENABLE_RA1_PULLDOWN()  (_CNPDA1 = 1)
#   define DISABLE_RA1_PULLDOWN() (_CNPDA1 = 0)

#   define ENABLE_RA1_CN_INTERRUPT()  (_CNIEA1 = 1)
#   define DISABLE_RA1_CN_INTERRUPT() (_CNIEA1 = 0)

# else
#   define DISABLE_RA1_PULLUP() ((void) 0)
#   define DISABLE_RA1_PULLDOWN() ((void) 0)
#   define DISABLE_RA1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA1
#   define CONFIG_RA1_AS_ANALOG()       \
      do {                              \
        ENABLE_RA1_ANALOG();            \
        CONFIG_RA1_AS_INPUT();          \
        DISABLE_RA1_OPENDRAIN();        \
        DISABLE_RA1_PULLUP();           \
        DISABLE_RA1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA2
#   define ENABLE_RA2_ANALOG()  (_ANSA2 = 1)
#   define DISABLE_RA2_ANALOG() (_ANSA2 = 0)
# else
#   define DISABLE_RA2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA2_AS_INPUT()  (_TRISA2 = 1)
# define CONFIG_RA2_AS_OUTPUT() (_TRISA2 = 0)

// Open-drain:
# if defined(_ODCA2)
#   define ENABLE_RA2_OPENDRAIN()  (_ODCA2 = 1)
#   define DISABLE_RA2_OPENDRAIN() (_ODCA2 = 0)
# else
#   define DISABLE_RA2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA2
#   define ENABLE_RA2_PULLUP()  (_CNPUA2 = 1)
#   define DISABLE_RA2_PULLUP() (_CNPUA2 = 0)

#   define ENABLE_RA2_PULLDOWN()  (_CNPDA2 = 1)
#   define DISABLE_RA2_PULLDOWN() (_CNPDA2 = 0)

#   define ENABLE_RA2_CN_INTERRUPT()  (_CNIEA2 = 1)
#   define DISABLE_RA2_CN_INTERRUPT() (_CNIEA2 = 0)

# else
#   define DISABLE_RA2_PULLUP() ((void) 0)
#   define DISABLE_RA2_PULLDOWN() ((void) 0)
#   define DISABLE_RA2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA2
#   define CONFIG_RA2_AS_ANALOG()       \
      do {                              \
        ENABLE_RA2_ANALOG();            \
        CONFIG_RA2_AS_INPUT();          \
        DISABLE_RA2_OPENDRAIN();        \
        DISABLE_RA2_PULLUP();           \
        DISABLE_RA2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA3
#   define ENABLE_RA3_ANALOG()  (_ANSA3 = 1)
#   define DISABLE_RA3_ANALOG() (_ANSA3 = 0)
# else
#   define DISABLE_RA3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA3_AS_INPUT()  (_TRISA3 = 1)
# define CONFIG_RA3_AS_OUTPUT() (_TRISA3 = 0)

// Open-drain:
# if defined(_ODCA3)
#   define ENABLE_RA3_OPENDRAIN()  (_ODCA3 = 1)
#   define DISABLE_RA3_OPENDRAIN() (_ODCA3 = 0)
# else
#   define DISABLE_RA3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA3
#   define ENABLE_RA3_PULLUP()  (_CNPUA3 = 1)
#   define DISABLE_RA3_PULLUP() (_CNPUA3 = 0)

#   define ENABLE_RA3_PULLDOWN()  (_CNPDA3 = 1)
#   define DISABLE_RA3_PULLDOWN() (_CNPDA3 = 0)

#   define ENABLE_RA3_CN_INTERRUPT()  (_CNIEA3 = 1)
#   define DISABLE_RA3_CN_INTERRUPT() (_CNIEA3 = 0)

# else
#   define DISABLE_RA3_PULLUP() ((void) 0)
#   define DISABLE_RA3_PULLDOWN() ((void) 0)
#   define DISABLE_RA3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA3
#   define CONFIG_RA3_AS_ANALOG()       \
      do {                              \
        ENABLE_RA3_ANALOG();            \
        CONFIG_RA3_AS_INPUT();          \
        DISABLE_RA3_OPENDRAIN();        \
        DISABLE_RA3_PULLUP();           \
        DISABLE_RA3_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA4
#   define ENABLE_RA4_ANALOG()  (_ANSA4 = 1)
#   define DISABLE_RA4_ANALOG() (_ANSA4 = 0)
# else
#   define DISABLE_RA4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA4_AS_INPUT()  (_TRISA4 = 1)
# define CONFIG_RA4_AS_OUTPUT() (_TRISA4 = 0)

// Open-drain:
# if defined(_ODCA4)
#   define ENABLE_RA4_OPENDRAIN()  (_ODCA4 = 1)
#   define DISABLE_RA4_OPENDRAIN() (_ODCA4 = 0)
# else
#   define DISABLE_RA4_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA4
#   define ENABLE_RA4_PULLUP()  (_CNPUA4 = 1)
#   define DISABLE_RA4_PULLUP() (_CNPUA4 = 0)

#   define ENABLE_RA4_PULLDOWN()  (_CNPDA4 = 1)
#   define DISABLE_RA4_PULLDOWN() (_CNPDA4 = 0)

#   define ENABLE_RA4_CN_INTERRUPT()  (_CNIEA4 = 1)
#   define DISABLE_RA4_CN_INTERRUPT() (_CNIEA4 = 0)

# else
#   define DISABLE_RA4_PULLUP() ((void) 0)
#   define DISABLE_RA4_PULLDOWN() ((void) 0)
#   define DISABLE_RA4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA4
#   define CONFIG_RA4_AS_ANALOG()       \
      do {                              \
        ENABLE_RA4_ANALOG();            \
        CONFIG_RA4_AS_INPUT();          \
        DISABLE_RA4_OPENDRAIN();        \
        DISABLE_RA4_PULLUP();           \
        DISABLE_RA4_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA5
#   define ENABLE_RA5_ANALOG()  (_ANSA5 = 1)
#   define DISABLE_RA5_ANALOG() (_ANSA5 = 0)
# else
#   define DISABLE_RA5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA5_AS_INPUT()  (_TRISA5 = 1)
# define CONFIG_RA5_AS_OUTPUT() (_TRISA5 = 0)

// Open-drain:
# if defined(_ODCA5)
#   define ENABLE_RA5_OPENDRAIN()  (_ODCA5 = 1)
#   define DISABLE_RA5_OPENDRAIN() (_ODCA5 = 0)
# else
#   define DISABLE_RA5_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA5
#   define ENABLE_RA5_PULLUP()  (_CNPUA5 = 1)
#   define DISABLE_RA5_PULLUP() (_CNPUA5 = 0)

#   define ENABLE_RA5_PULLDOWN()  (_CNPDA5 = 1)
#   define DISABLE_RA5_PULLDOWN() (_CNPDA5 = 0)

#   define ENABLE_RA5_CN_INTERRUPT()  (_CNIEA5 = 1)
#   define DISABLE_RA5_CN_INTERRUPT() (_CNIEA5 = 0)

# else
#   define DISABLE_RA5_PULLUP() ((void) 0)
#   define DISABLE_RA5_PULLDOWN() ((void) 0)
#   define DISABLE_RA5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA5
#   define CONFIG_RA5_AS_ANALOG()       \
      do {                              \
        ENABLE_RA5_ANALOG();            \
        CONFIG_RA5_AS_INPUT();          \
        DISABLE_RA5_OPENDRAIN();        \
        DISABLE_RA5_PULLUP();           \
        DISABLE_RA5_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA6
#   define ENABLE_RA6_ANALOG()  (_ANSA6 = 1)
#   define DISABLE_RA6_ANALOG() (_ANSA6 = 0)
# else
#   define DISABLE_RA6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA6_AS_INPUT()  (_TRISA6 = 1)
# define CONFIG_RA6_AS_OUTPUT() (_TRISA6 = 0)

// Open-drain:
# if defined(_ODCA6)
#   define ENABLE_RA6_OPENDRAIN()  (_ODCA6 = 1)
#   define DISABLE_RA6_OPENDRAIN() (_ODCA6 = 0)
# else
#   define DISABLE_RA6_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA6
#   define ENABLE_RA6_PULLUP()  (_CNPUA6 = 1)
#   define DISABLE_RA6_PULLUP() (_CNPUA6 = 0)

#   define ENABLE_RA6_PULLDOWN()  (_CNPDA6 = 1)
#   define DISABLE_RA6_PULLDOWN() (_CNPDA6 = 0)

#   define ENABLE_RA6_CN_INTERRUPT()  (_CNIEA6 = 1)
#   define DISABLE_RA6_CN_INTERRUPT() (_CNIEA6 = 0)

# else
#   define DISABLE_RA6_PULLUP() ((void) 0)
#   define DISABLE_RA6_PULLDOWN() ((void) 0)
#   define DISABLE_RA6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA6
#   define CONFIG_RA6_AS_ANALOG()       \
      do {                              \
        ENABLE_RA6_ANALOG();            \
        CONFIG_RA6_AS_INPUT();          \
        DISABLE_RA6_OPENDRAIN();        \
        DISABLE_RA6_PULLUP();           \
        DISABLE_RA6_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA7
#   define ENABLE_RA7_ANALOG()  (_ANSA7 = 1)
#   define DISABLE_RA7_ANALOG() (_ANSA7 = 0)
# else
#   define DISABLE_RA7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA7_AS_INPUT()  (_TRISA7 = 1)
# define CONFIG_RA7_AS_OUTPUT() (_TRISA7 = 0)

// Open-drain:
# if defined(_ODCA7)
#   define ENABLE_RA7_OPENDRAIN()  (_ODCA7 = 1)
#   define DISABLE_RA7_OPENDRAIN() (_ODCA7 = 0)
# else
#   define DISABLE_RA7_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA7
#   define ENABLE_RA7_PULLUP()  (_CNPUA7 = 1)
#   define DISABLE_RA7_PULLUP() (_CNPUA7 = 0)

#   define ENABLE_RA7_PULLDOWN()  (_CNPDA7 = 1)
#   define DISABLE_RA7_PULLDOWN() (_CNPDA7 = 0)

#   define ENABLE_RA7_CN_INTERRUPT()  (_CNIEA7 = 1)
#   define DISABLE_RA7_CN_INTERRUPT() (_CNIEA7 = 0)

# else
#   define DISABLE_RA7_PULLUP() ((void) 0)
#   define DISABLE_RA7_PULLDOWN() ((void) 0)
#   define DISABLE_RA7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA7
#   define CONFIG_RA7_AS_ANALOG()       \
      do {                              \
        ENABLE_RA7_ANALOG();            \
        CONFIG_RA7_AS_INPUT();          \
        DISABLE_RA7_OPENDRAIN();        \
        DISABLE_RA7_PULLUP();           \
        DISABLE_RA7_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA8
#   define ENABLE_RA8_ANALOG()  (_ANSA8 = 1)
#   define DISABLE_RA8_ANALOG() (_ANSA8 = 0)
# else
#   define DISABLE_RA8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA8_AS_INPUT()  (_TRISA8 = 1)
# define CONFIG_RA8_AS_OUTPUT() (_TRISA8 = 0)

// Open-drain:
# if defined(_ODCA8)
#   define ENABLE_RA8_OPENDRAIN()  (_ODCA8 = 1)
#   define DISABLE_RA8_OPENDRAIN() (_ODCA8 = 0)
# else
#   define DISABLE_RA8_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA8
#   define ENABLE_RA8_PULLUP()  (_CNPUA8 = 1)
#   define DISABLE_RA8_PULLUP() (_CNPUA8 = 0)

#   define ENABLE_RA8_PULLDOWN()  (_CNPDA8 = 1)
#   define DISABLE_RA8_PULLDOWN() (_CNPDA8 = 0)

#   define ENABLE_RA8_CN_INTERRUPT()  (_CNIEA8 = 1)
#   define DISABLE_RA8_CN_INTERRUPT() (_CNIEA8 = 0)

# else
#   define DISABLE_RA8_PULLUP() ((void) 0)
#   define DISABLE_RA8_PULLDOWN() ((void) 0)
#   define DISABLE_RA8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA8
#   define CONFIG_RA8_AS_ANALOG()       \
      do {                              \
        ENABLE_RA8_ANALOG();            \
        CONFIG_RA8_AS_INPUT();          \
        DISABLE_RA8_OPENDRAIN();        \
        DISABLE_RA8_PULLUP();           \
        DISABLE_RA8_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA9
#   define ENABLE_RA9_ANALOG()  (_ANSA9 = 1)
#   define DISABLE_RA9_ANALOG() (_ANSA9 = 0)
# else
#   define DISABLE_RA9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA9_AS_INPUT()  (_TRISA9 = 1)
# define CONFIG_RA9_AS_OUTPUT() (_TRISA9 = 0)

// Open-drain:
# if defined(_ODCA9)
#   define ENABLE_RA9_OPENDRAIN()  (_ODCA9 = 1)
#   define DISABLE_RA9_OPENDRAIN() (_ODCA9 = 0)
# else
#   define DISABLE_RA9_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA9
#   define ENABLE_RA9_PULLUP()  (_CNPUA9 = 1)
#   define DISABLE_RA9_PULLUP() (_CNPUA9 = 0)

#   define ENABLE_RA9_PULLDOWN()  (_CNPDA9 = 1)
#   define DISABLE_RA9_PULLDOWN() (_CNPDA9 = 0)

#   define ENABLE_RA9_CN_INTERRUPT()  (_CNIEA9 = 1)
#   define DISABLE_RA9_CN_INTERRUPT() (_CNIEA9 = 0)

# else
#   define DISABLE_RA9_PULLUP() ((void) 0)
#   define DISABLE_RA9_PULLDOWN() ((void) 0)
#   define DISABLE_RA9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA9
#   define CONFIG_RA9_AS_ANALOG()       \
      do {                              \
        ENABLE_RA9_ANALOG();            \
        CONFIG_RA9_AS_INPUT();          \
        DISABLE_RA9_OPENDRAIN();        \
        DISABLE_RA9_PULLUP();           \
        DISABLE_RA9_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA10
#   define ENABLE_RA10_ANALOG()  (_ANSA10 = 1)
#   define DISABLE_RA10_ANALOG() (_ANSA10 = 0)
# else
#   define DISABLE_RA10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA10_AS_INPUT()  (_TRISA10 = 1)
# define CONFIG_RA10_AS_OUTPUT() (_TRISA10 = 0)

// Open-drain:
# if defined(_ODCA10)
#   define ENABLE_RA10_OPENDRAIN()  (_ODCA10 = 1)
#   define DISABLE_RA10_OPENDRAIN() (_ODCA10 = 0)
# else
#   define DISABLE_RA10_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA10
#   define ENABLE_RA10_PULLUP()  (_CNPUA10 = 1)
#   define DISABLE_RA10_PULLUP() (_CNPUA10 = 0)

#   define ENABLE_RA10_PULLDOWN()  (_CNPDA10 = 1)
#   define DISABLE_RA10_PULLDOWN() (_CNPDA10 = 0)

#   define ENABLE_RA10_CN_INTERRUPT()  (_CNIEA10 = 1)
#   define DISABLE_RA10_CN_INTERRUPT() (_CNIEA10 = 0)

# else
#   define DISABLE_RA10_PULLUP() ((void) 0)
#   define DISABLE_RA10_PULLDOWN() ((void) 0)
#   define DISABLE_RA10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA10
#   define CONFIG_RA10_AS_ANALOG()       \
      do {                              \
        ENABLE_RA10_ANALOG();            \
        CONFIG_RA10_AS_INPUT();          \
        DISABLE_RA10_OPENDRAIN();        \
        DISABLE_RA10_PULLUP();           \
        DISABLE_RA10_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA11
#   define ENABLE_RA11_ANALOG()  (_ANSA11 = 1)
#   define DISABLE_RA11_ANALOG() (_ANSA11 = 0)
# else
#   define DISABLE_RA11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA11_AS_INPUT()  (_TRISA11 = 1)
# define CONFIG_RA11_AS_OUTPUT() (_TRISA11 = 0)

// Open-drain:
# if defined(_ODCA11)
#   define ENABLE_RA11_OPENDRAIN()  (_ODCA11 = 1)
#   define DISABLE_RA11_OPENDRAIN() (_ODCA11 = 0)
# else
#   define DISABLE_RA11_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA11
#   define ENABLE_RA11_PULLUP()  (_CNPUA11 = 1)
#   define DISABLE_RA11_PULLUP() (_CNPUA11 = 0)

#   define ENABLE_RA11_PULLDOWN()  (_CNPDA11 = 1)
#   define DISABLE_RA11_PULLDOWN() (_CNPDA11 = 0)

#   define ENABLE_RA11_CN_INTERRUPT()  (_CNIEA11 = 1)
#   define DISABLE_RA11_CN_INTERRUPT() (_CNIEA11 = 0)

# else
#   define DISABLE_RA11_PULLUP() ((void) 0)
#   define DISABLE_RA11_PULLDOWN() ((void) 0)
#   define DISABLE_RA11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA11
#   define CONFIG_RA11_AS_ANALOG()       \
      do {                              \
        ENABLE_RA11_ANALOG();            \
        CONFIG_RA11_AS_INPUT();          \
        DISABLE_RA11_OPENDRAIN();        \
        DISABLE_RA11_PULLUP();           \
        DISABLE_RA11_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA12
#   define ENABLE_RA12_ANALOG()  (_ANSA12 = 1)
#   define DISABLE_RA12_ANALOG() (_ANSA12 = 0)
# else
#   define DISABLE_RA12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA12_AS_INPUT()  (_TRISA12 = 1)
# define CONFIG_RA12_AS_OUTPUT() (_TRISA12 = 0)

// Open-drain:
# if defined(_ODCA12)
#   define ENABLE_RA12_OPENDRAIN()  (_ODCA12 = 1)
#   define DISABLE_RA12_OPENDRAIN() (_ODCA12 = 0)
# else
#   define DISABLE_RA12_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA12
#   define ENABLE_RA12_PULLUP()  (_CNPUA12 = 1)
#   define DISABLE_RA12_PULLUP() (_CNPUA12 = 0)

#   define ENABLE_RA12_PULLDOWN()  (_CNPDA12 = 1)
#   define DISABLE_RA12_PULLDOWN() (_CNPDA12 = 0)

#   define ENABLE_RA12_CN_INTERRUPT()  (_CNIEA12 = 1)
#   define DISABLE_RA12_CN_INTERRUPT() (_CNIEA12 = 0)

# else
#   define DISABLE_RA12_PULLUP() ((void) 0)
#   define DISABLE_RA12_PULLDOWN() ((void) 0)
#   define DISABLE_RA12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA12
#   define CONFIG_RA12_AS_ANALOG()       \
      do {                              \
        ENABLE_RA12_ANALOG();            \
        CONFIG_RA12_AS_INPUT();          \
        DISABLE_RA12_OPENDRAIN();        \
        DISABLE_RA12_PULLUP();           \
        DISABLE_RA12_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA13
#   define ENABLE_RA13_ANALOG()  (_ANSA13 = 1)
#   define DISABLE_RA13_ANALOG() (_ANSA13 = 0)
# else
#   define DISABLE_RA13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA13_AS_INPUT()  (_TRISA13 = 1)
# define CONFIG_RA13_AS_OUTPUT() (_TRISA13 = 0)

// Open-drain:
# if defined(_ODCA13)
#   define ENABLE_RA13_OPENDRAIN()  (_ODCA13 = 1)
#   define DISABLE_RA13_OPENDRAIN() (_ODCA13 = 0)
# else
#   define DISABLE_RA13_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA13
#   define ENABLE_RA13_PULLUP()  (_CNPUA13 = 1)
#   define DISABLE_RA13_PULLUP() (_CNPUA13 = 0)

#   define ENABLE_RA13_PULLDOWN()  (_CNPDA13 = 1)
#   define DISABLE_RA13_PULLDOWN() (_CNPDA13 = 0)

#   define ENABLE_RA13_CN_INTERRUPT()  (_CNIEA13 = 1)
#   define DISABLE_RA13_CN_INTERRUPT() (_CNIEA13 = 0)

# else
#   define DISABLE_RA13_PULLUP() ((void) 0)
#   define DISABLE_RA13_PULLDOWN() ((void) 0)
#   define DISABLE_RA13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA13
#   define CONFIG_RA13_AS_ANALOG()       \
      do {                              \
        ENABLE_RA13_ANALOG();            \
        CONFIG_RA13_AS_INPUT();          \
        DISABLE_RA13_OPENDRAIN();        \
        DISABLE_RA13_PULLUP();           \
        DISABLE_RA13_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA14
#   define ENABLE_RA14_ANALOG()  (_ANSA14 = 1)
#   define DISABLE_RA14_ANALOG() (_ANSA14 = 0)
# else
#   define DISABLE_RA14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA14_AS_INPUT()  (_TRISA14 = 1)
# define CONFIG_RA14_AS_OUTPUT() (_TRISA14 = 0)

// Open-drain:
# if defined(_ODCA14)
#   define ENABLE_RA14_OPENDRAIN()  (_ODCA14 = 1)
#   define DISABLE_RA14_OPENDRAIN() (_ODCA14 = 0)
# else
#   define DISABLE_RA14_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA14
#   define ENABLE_RA14_PULLUP()  (_CNPUA14 = 1)
#   define DISABLE_RA14_PULLUP() (_CNPUA14 = 0)

#   define ENABLE_RA14_PULLDOWN()  (_CNPDA14 = 1)
#   define DISABLE_RA14_PULLDOWN() (_CNPDA14 = 0)

#   define ENABLE_RA14_CN_INTERRUPT()  (_CNIEA14 = 1)
#   define DISABLE_RA14_CN_INTERRUPT() (_CNIEA14 = 0)

# else
#   define DISABLE_RA14_PULLUP() ((void) 0)
#   define DISABLE_RA14_PULLDOWN() ((void) 0)
#   define DISABLE_RA14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA14
#   define CONFIG_RA14_AS_ANALOG()       \
      do {                              \
        ENABLE_RA14_ANALOG();            \
        CONFIG_RA14_AS_INPUT();          \
        DISABLE_RA14_OPENDRAIN();        \
        DISABLE_RA14_PULLUP();           \
        DISABLE_RA14_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSA15
#   define ENABLE_RA15_ANALOG()  (_ANSA15 = 1)
#   define DISABLE_RA15_ANALOG() (_ANSA15 = 0)
# else
#   define DISABLE_RA15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RA15_AS_INPUT()  (_TRISA15 = 1)
# define CONFIG_RA15_AS_OUTPUT() (_TRISA15 = 0)

// Open-drain:
# if defined(_ODCA15)
#   define ENABLE_RA15_OPENDRAIN()  (_ODCA15 = 1)
#   define DISABLE_RA15_OPENDRAIN() (_ODCA15 = 0)
# else
#   define DISABLE_RA15_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEA15
#   define ENABLE_RA15_PULLUP()  (_CNPUA15 = 1)
#   define DISABLE_RA15_PULLUP() (_CNPUA15 = 0)

#   define ENABLE_RA15_PULLDOWN()  (_CNPDA15 = 1)
#   define DISABLE_RA15_PULLDOWN() (_CNPDA15 = 0)

#   define ENABLE_RA15_CN_INTERRUPT()  (_CNIEA15 = 1)
#   define DISABLE_RA15_CN_INTERRUPT() (_CNIEA15 = 0)

# else
#   define DISABLE_RA15_PULLUP() ((void) 0)
#   define DISABLE_RA15_PULLDOWN() ((void) 0)
#   define DISABLE_RA15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSA15
#   define CONFIG_RA15_AS_ANALOG()       \
      do {                              \
        ENABLE_RA15_ANALOG();            \
        CONFIG_RA15_AS_INPUT();          \
        DISABLE_RA15_OPENDRAIN();        \
        DISABLE_RA15_PULLUP();           \
        DISABLE_RA15_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB0
#   define ENABLE_RB0_ANALOG()  (_ANSB0 = 1)
#   define DISABLE_RB0_ANALOG() (_ANSB0 = 0)
# else
#   define DISABLE_RB0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB0_AS_INPUT()  (_TRISB0 = 1)
# define CONFIG_RB0_AS_OUTPUT() (_TRISB0 = 0)

// Open-drain:
# if defined(_ODCB0)
#   define ENABLE_RB0_OPENDRAIN()  (_ODCB0 = 1)
#   define DISABLE_RB0_OPENDRAIN() (_ODCB0 = 0)
# else
#   define DISABLE_RB0_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB0
#   define ENABLE_RB0_PULLUP()  (_CNPUB0 = 1)
#   define DISABLE_RB0_PULLUP() (_CNPUB0 = 0)

#   define ENABLE_RB0_PULLDOWN()  (_CNPDB0 = 1)
#   define DISABLE_RB0_PULLDOWN() (_CNPDB0 = 0)

#   define ENABLE_RB0_CN_INTERRUPT()  (_CNIEB0 = 1)
#   define DISABLE_RB0_CN_INTERRUPT() (_CNIEB0 = 0)

# else
#   define DISABLE_RB0_PULLUP() ((void) 0)
#   define DISABLE_RB0_PULLDOWN() ((void) 0)
#   define DISABLE_RB0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB0
#   define CONFIG_RB0_AS_ANALOG()       \
      do {                              \
        ENABLE_RB0_ANALOG();            \
        CONFIG_RB0_AS_INPUT();          \
        DISABLE_RB0_OPENDRAIN();        \
        DISABLE_RB0_PULLUP();           \
        DISABLE_RB0_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB1
#   define ENABLE_RB1_ANALOG()  (_ANSB1 = 1)
#   define DISABLE_RB1_ANALOG() (_ANSB1 = 0)
# else
#   define DISABLE_RB1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB1_AS_INPUT()  (_TRISB1 = 1)
# define CONFIG_RB1_AS_OUTPUT() (_TRISB1 = 0)

// Open-drain:
# if defined(_ODCB1)
#   define ENABLE_RB1_OPENDRAIN()  (_ODCB1 = 1)
#   define DISABLE_RB1_OPENDRAIN() (_ODCB1 = 0)
# else
#   define DISABLE_RB1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB1
#   define ENABLE_RB1_PULLUP()  (_CNPUB1 = 1)
#   define DISABLE_RB1_PULLUP() (_CNPUB1 = 0)

#   define ENABLE_RB1_PULLDOWN()  (_CNPDB1 = 1)
#   define DISABLE_RB1_PULLDOWN() (_CNPDB1 = 0)

#   define ENABLE_RB1_CN_INTERRUPT()  (_CNIEB1 = 1)
#   define DISABLE_RB1_CN_INTERRUPT() (_CNIEB1 = 0)

# else
#   define DISABLE_RB1_PULLUP() ((void) 0)
#   define DISABLE_RB1_PULLDOWN() ((void) 0)
#   define DISABLE_RB1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB1
#   define CONFIG_RB1_AS_ANALOG()       \
      do {                              \
        ENABLE_RB1_ANALOG();            \
        CONFIG_RB1_AS_INPUT();          \
        DISABLE_RB1_OPENDRAIN();        \
        DISABLE_RB1_PULLUP();           \
        DISABLE_RB1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB2
#   define ENABLE_RB2_ANALOG()  (_ANSB2 = 1)
#   define DISABLE_RB2_ANALOG() (_ANSB2 = 0)
# else
#   define DISABLE_RB2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB2_AS_INPUT()  (_TRISB2 = 1)
# define CONFIG_RB2_AS_OUTPUT() (_TRISB2 = 0)

// Open-drain:
# if defined(_ODCB2)
#   define ENABLE_RB2_OPENDRAIN()  (_ODCB2 = 1)
#   define DISABLE_RB2_OPENDRAIN() (_ODCB2 = 0)
# else
#   define DISABLE_RB2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB2
#   define ENABLE_RB2_PULLUP()  (_CNPUB2 = 1)
#   define DISABLE_RB2_PULLUP() (_CNPUB2 = 0)

#   define ENABLE_RB2_PULLDOWN()  (_CNPDB2 = 1)
#   define DISABLE_RB2_PULLDOWN() (_CNPDB2 = 0)

#   define ENABLE_RB2_CN_INTERRUPT()  (_CNIEB2 = 1)
#   define DISABLE_RB2_CN_INTERRUPT() (_CNIEB2 = 0)

# else
#   define DISABLE_RB2_PULLUP() ((void) 0)
#   define DISABLE_RB2_PULLDOWN() ((void) 0)
#   define DISABLE_RB2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB2
#   define CONFIG_RB2_AS_ANALOG()       \
      do {                              \
        ENABLE_RB2_ANALOG();            \
        CONFIG_RB2_AS_INPUT();          \
        DISABLE_RB2_OPENDRAIN();        \
        DISABLE_RB2_PULLUP();           \
        DISABLE_RB2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB3
#   define ENABLE_RB3_ANALOG()  (_ANSB3 = 1)
#   define DISABLE_RB3_ANALOG() (_ANSB3 = 0)
# else
#   define DISABLE_RB3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB3_AS_INPUT()  (_TRISB3 = 1)
# define CONFIG_RB3_AS_OUTPUT() (_TRISB3 = 0)

// Open-drain:
# if defined(_ODCB3)
#   define ENABLE_RB3_OPENDRAIN()  (_ODCB3 = 1)
#   define DISABLE_RB3_OPENDRAIN() (_ODCB3 = 0)
# else
#   define DISABLE_RB3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB3
#   define ENABLE_RB3_PULLUP()  (_CNPUB3 = 1)
#   define DISABLE_RB3_PULLUP() (_CNPUB3 = 0)

#   define ENABLE_RB3_PULLDOWN()  (_CNPDB3 = 1)
#   define DISABLE_RB3_PULLDOWN() (_CNPDB3 = 0)

#   define ENABLE_RB3_CN_INTERRUPT()  (_CNIEB3 = 1)
#   define DISABLE_RB3_CN_INTERRUPT() (_CNIEB3 = 0)

# else
#   define DISABLE_RB3_PULLUP() ((void) 0)
#   define DISABLE_RB3_PULLDOWN() ((void) 0)
#   define DISABLE_RB3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB3
#   define CONFIG_RB3_AS_ANALOG()       \
      do {                              \
        ENABLE_RB3_ANALOG();            \
        CONFIG_RB3_AS_INPUT();          \
        DISABLE_RB3_OPENDRAIN();        \
        DISABLE_RB3_PULLUP();           \
        DISABLE_RB3_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB4
#   define ENABLE_RB4_ANALOG()  (_ANSB4 = 1)
#   define DISABLE_RB4_ANALOG() (_ANSB4 = 0)
# else
#   define DISABLE_RB4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB4_AS_INPUT()  (_TRISB4 = 1)
# define CONFIG_RB4_AS_OUTPUT() (_TRISB4 = 0)

// Open-drain:
# if defined(_ODCB4)
#   define ENABLE_RB4_OPENDRAIN()  (_ODCB4 = 1)
#   define DISABLE_RB4_OPENDRAIN() (_ODCB4 = 0)
# else
#   define DISABLE_RB4_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB4
#   define ENABLE_RB4_PULLUP()  (_CNPUB4 = 1)
#   define DISABLE_RB4_PULLUP() (_CNPUB4 = 0)

#   define ENABLE_RB4_PULLDOWN()  (_CNPDB4 = 1)
#   define DISABLE_RB4_PULLDOWN() (_CNPDB4 = 0)

#   define ENABLE_RB4_CN_INTERRUPT()  (_CNIEB4 = 1)
#   define DISABLE_RB4_CN_INTERRUPT() (_CNIEB4 = 0)

# else
#   define DISABLE_RB4_PULLUP() ((void) 0)
#   define DISABLE_RB4_PULLDOWN() ((void) 0)
#   define DISABLE_RB4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB4
#   define CONFIG_RB4_AS_ANALOG()       \
      do {                              \
        ENABLE_RB4_ANALOG();            \
        CONFIG_RB4_AS_INPUT();          \
        DISABLE_RB4_OPENDRAIN();        \
        DISABLE_RB4_PULLUP();           \
        DISABLE_RB4_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB5
#   define ENABLE_RB5_ANALOG()  (_ANSB5 = 1)
#   define DISABLE_RB5_ANALOG() (_ANSB5 = 0)
# else
#   define DISABLE_RB5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB5_AS_INPUT()  (_TRISB5 = 1)
# define CONFIG_RB5_AS_OUTPUT() (_TRISB5 = 0)

// Open-drain:
# if defined(_ODCB5)
#   define ENABLE_RB5_OPENDRAIN()  (_ODCB5 = 1)
#   define DISABLE_RB5_OPENDRAIN() (_ODCB5 = 0)
# else
#   define DISABLE_RB5_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB5
#   define ENABLE_RB5_PULLUP()  (_CNPUB5 = 1)
#   define DISABLE_RB5_PULLUP() (_CNPUB5 = 0)

#   define ENABLE_RB5_PULLDOWN()  (_CNPDB5 = 1)
#   define DISABLE_RB5_PULLDOWN() (_CNPDB5 = 0)

#   define ENABLE_RB5_CN_INTERRUPT()  (_CNIEB5 = 1)
#   define DISABLE_RB5_CN_INTERRUPT() (_CNIEB5 = 0)

# else
#   define DISABLE_RB5_PULLUP() ((void) 0)
#   define DISABLE_RB5_PULLDOWN() ((void) 0)
#   define DISABLE_RB5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB5
#   define CONFIG_RB5_AS_ANALOG()       \
      do {                              \
        ENABLE_RB5_ANALOG();            \
        CONFIG_RB5_AS_INPUT();          \
        DISABLE_RB5_OPENDRAIN();        \
        DISABLE_RB5_PULLUP();           \
        DISABLE_RB5_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB6
#   define ENABLE_RB6_ANALOG()  (_ANSB6 = 1)
#   define DISABLE_RB6_ANALOG() (_ANSB6 = 0)
# else
#   define DISABLE_RB6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB6_AS_INPUT()  (_TRISB6 = 1)
# define CONFIG_RB6_AS_OUTPUT() (_TRISB6 = 0)

// Open-drain:
# if defined(_ODCB6)
#   define ENABLE_RB6_OPENDRAIN()  (_ODCB6 = 1)
#   define DISABLE_RB6_OPENDRAIN() (_ODCB6 = 0)
# else
#   define DISABLE_RB6_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB6
#   define ENABLE_RB6_PULLUP()  (_CNPUB6 = 1)
#   define DISABLE_RB6_PULLUP() (_CNPUB6 = 0)

#   define ENABLE_RB6_PULLDOWN()  (_CNPDB6 = 1)
#   define DISABLE_RB6_PULLDOWN() (_CNPDB6 = 0)

#   define ENABLE_RB6_CN_INTERRUPT()  (_CNIEB6 = 1)
#   define DISABLE_RB6_CN_INTERRUPT() (_CNIEB6 = 0)

# else
#   define DISABLE_RB6_PULLUP() ((void) 0)
#   define DISABLE_RB6_PULLDOWN() ((void) 0)
#   define DISABLE_RB6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB6
#   define CONFIG_RB6_AS_ANALOG()       \
      do {                              \
        ENABLE_RB6_ANALOG();            \
        CONFIG_RB6_AS_INPUT();          \
        DISABLE_RB6_OPENDRAIN();        \
        DISABLE_RB6_PULLUP();           \
        DISABLE_RB6_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB7
#   define ENABLE_RB7_ANALOG()  (_ANSB7 = 1)
#   define DISABLE_RB7_ANALOG() (_ANSB7 = 0)
# else
#   define DISABLE_RB7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB7_AS_INPUT()  (_TRISB7 = 1)
# define CONFIG_RB7_AS_OUTPUT() (_TRISB7 = 0)

// Open-drain:
# if defined(_ODCB7)
#   define ENABLE_RB7_OPENDRAIN()  (_ODCB7 = 1)
#   define DISABLE_RB7_OPENDRAIN() (_ODCB7 = 0)
# else
#   define DISABLE_RB7_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB7
#   define ENABLE_RB7_PULLUP()  (_CNPUB7 = 1)
#   define DISABLE_RB7_PULLUP() (_CNPUB7 = 0)

#   define ENABLE_RB7_PULLDOWN()  (_CNPDB7 = 1)
#   define DISABLE_RB7_PULLDOWN() (_CNPDB7 = 0)

#   define ENABLE_RB7_CN_INTERRUPT()  (_CNIEB7 = 1)
#   define DISABLE_RB7_CN_INTERRUPT() (_CNIEB7 = 0)

# else
#   define DISABLE_RB7_PULLUP() ((void) 0)
#   define DISABLE_RB7_PULLDOWN() ((void) 0)
#   define DISABLE_RB7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB7
#   define CONFIG_RB7_AS_ANALOG()       \
      do {                              \
        ENABLE_RB7_ANALOG();            \
        CONFIG_RB7_AS_INPUT();          \
        DISABLE_RB7_OPENDRAIN();        \
        DISABLE_RB7_PULLUP();           \
        DISABLE_RB7_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB8
#   define ENABLE_RB8_ANALOG()  (_ANSB8 = 1)
#   define DISABLE_RB8_ANALOG() (_ANSB8 = 0)
# else
#   define DISABLE_RB8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB8_AS_INPUT()  (_TRISB8 = 1)
# define CONFIG_RB8_AS_OUTPUT() (_TRISB8 = 0)

// Open-drain:
# if defined(_ODCB8)
#   define ENABLE_RB8_OPENDRAIN()  (_ODCB8 = 1)
#   define DISABLE_RB8_OPENDRAIN() (_ODCB8 = 0)
# else
#   define DISABLE_RB8_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB8
#   define ENABLE_RB8_PULLUP()  (_CNPUB8 = 1)
#   define DISABLE_RB8_PULLUP() (_CNPUB8 = 0)

#   define ENABLE_RB8_PULLDOWN()  (_CNPDB8 = 1)
#   define DISABLE_RB8_PULLDOWN() (_CNPDB8 = 0)

#   define ENABLE_RB8_CN_INTERRUPT()  (_CNIEB8 = 1)
#   define DISABLE_RB8_CN_INTERRUPT() (_CNIEB8 = 0)

# else
#   define DISABLE_RB8_PULLUP() ((void) 0)
#   define DISABLE_RB8_PULLDOWN() ((void) 0)
#   define DISABLE_RB8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB8
#   define CONFIG_RB8_AS_ANALOG()       \
      do {                              \
        ENABLE_RB8_ANALOG();            \
        CONFIG_RB8_AS_INPUT();          \
        DISABLE_RB8_OPENDRAIN();        \
        DISABLE_RB8_PULLUP();           \
        DISABLE_RB8_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB9
#   define ENABLE_RB9_ANALOG()  (_ANSB9 = 1)
#   define DISABLE_RB9_ANALOG() (_ANSB9 = 0)
# else
#   define DISABLE_RB9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB9_AS_INPUT()  (_TRISB9 = 1)
# define CONFIG_RB9_AS_OUTPUT() (_TRISB9 = 0)

// Open-drain:
# if defined(_ODCB9)
#   define ENABLE_RB9_OPENDRAIN()  (_ODCB9 = 1)
#   define DISABLE_RB9_OPENDRAIN() (_ODCB9 = 0)
# else
#   define DISABLE_RB9_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB9
#   define ENABLE_RB9_PULLUP()  (_CNPUB9 = 1)
#   define DISABLE_RB9_PULLUP() (_CNPUB9 = 0)

#   define ENABLE_RB9_PULLDOWN()  (_CNPDB9 = 1)
#   define DISABLE_RB9_PULLDOWN() (_CNPDB9 = 0)

#   define ENABLE_RB9_CN_INTERRUPT()  (_CNIEB9 = 1)
#   define DISABLE_RB9_CN_INTERRUPT() (_CNIEB9 = 0)

# else
#   define DISABLE_RB9_PULLUP() ((void) 0)
#   define DISABLE_RB9_PULLDOWN() ((void) 0)
#   define DISABLE_RB9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB9
#   define CONFIG_RB9_AS_ANALOG()       \
      do {                              \
        ENABLE_RB9_ANALOG();            \
        CONFIG_RB9_AS_INPUT();          \
        DISABLE_RB9_OPENDRAIN();        \
        DISABLE_RB9_PULLUP();           \
        DISABLE_RB9_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB10
#   define ENABLE_RB10_ANALOG()  (_ANSB10 = 1)
#   define DISABLE_RB10_ANALOG() (_ANSB10 = 0)
# else
#   define DISABLE_RB10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB10_AS_INPUT()  (_TRISB10 = 1)
# define CONFIG_RB10_AS_OUTPUT() (_TRISB10 = 0)

// Open-drain:
# if defined(_ODCB10)
#   define ENABLE_RB10_OPENDRAIN()  (_ODCB10 = 1)
#   define DISABLE_RB10_OPENDRAIN() (_ODCB10 = 0)
# else
#   define DISABLE_RB10_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB10
#   define ENABLE_RB10_PULLUP()  (_CNPUB10 = 1)
#   define DISABLE_RB10_PULLUP() (_CNPUB10 = 0)

#   define ENABLE_RB10_PULLDOWN()  (_CNPDB10 = 1)
#   define DISABLE_RB10_PULLDOWN() (_CNPDB10 = 0)

#   define ENABLE_RB10_CN_INTERRUPT()  (_CNIEB10 = 1)
#   define DISABLE_RB10_CN_INTERRUPT() (_CNIEB10 = 0)

# else
#   define DISABLE_RB10_PULLUP() ((void) 0)
#   define DISABLE_RB10_PULLDOWN() ((void) 0)
#   define DISABLE_RB10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB10
#   define CONFIG_RB10_AS_ANALOG()       \
      do {                              \
        ENABLE_RB10_ANALOG();            \
        CONFIG_RB10_AS_INPUT();          \
        DISABLE_RB10_OPENDRAIN();        \
        DISABLE_RB10_PULLUP();           \
        DISABLE_RB10_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB11
#   define ENABLE_RB11_ANALOG()  (_ANSB11 = 1)
#   define DISABLE_RB11_ANALOG() (_ANSB11 = 0)
# else
#   define DISABLE_RB11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB11_AS_INPUT()  (_TRISB11 = 1)
# define CONFIG_RB11_AS_OUTPUT() (_TRISB11 = 0)

// Open-drain:
# if defined(_ODCB11)
#   define ENABLE_RB11_OPENDRAIN()  (_ODCB11 = 1)
#   define DISABLE_RB11_OPENDRAIN() (_ODCB11 = 0)
# else
#   define DISABLE_RB11_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB11
#   define ENABLE_RB11_PULLUP()  (_CNPUB11 = 1)
#   define DISABLE_RB11_PULLUP() (_CNPUB11 = 0)

#   define ENABLE_RB11_PULLDOWN()  (_CNPDB11 = 1)
#   define DISABLE_RB11_PULLDOWN() (_CNPDB11 = 0)

#   define ENABLE_RB11_CN_INTERRUPT()  (_CNIEB11 = 1)
#   define DISABLE_RB11_CN_INTERRUPT() (_CNIEB11 = 0)

# else
#   define DISABLE_RB11_PULLUP() ((void) 0)
#   define DISABLE_RB11_PULLDOWN() ((void) 0)
#   define DISABLE_RB11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB11
#   define CONFIG_RB11_AS_ANALOG()       \
      do {                              \
        ENABLE_RB11_ANALOG();            \
        CONFIG_RB11_AS_INPUT();          \
        DISABLE_RB11_OPENDRAIN();        \
        DISABLE_RB11_PULLUP();           \
        DISABLE_RB11_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB12
#   define ENABLE_RB12_ANALOG()  (_ANSB12 = 1)
#   define DISABLE_RB12_ANALOG() (_ANSB12 = 0)
# else
#   define DISABLE_RB12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB12_AS_INPUT()  (_TRISB12 = 1)
# define CONFIG_RB12_AS_OUTPUT() (_TRISB12 = 0)

// Open-drain:
# if defined(_ODCB12)
#   define ENABLE_RB12_OPENDRAIN()  (_ODCB12 = 1)
#   define DISABLE_RB12_OPENDRAIN() (_ODCB12 = 0)
# else
#   define DISABLE_RB12_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB12
#   define ENABLE_RB12_PULLUP()  (_CNPUB12 = 1)
#   define DISABLE_RB12_PULLUP() (_CNPUB12 = 0)

#   define ENABLE_RB12_PULLDOWN()  (_CNPDB12 = 1)
#   define DISABLE_RB12_PULLDOWN() (_CNPDB12 = 0)

#   define ENABLE_RB12_CN_INTERRUPT()  (_CNIEB12 = 1)
#   define DISABLE_RB12_CN_INTERRUPT() (_CNIEB12 = 0)

# else
#   define DISABLE_RB12_PULLUP() ((void) 0)
#   define DISABLE_RB12_PULLDOWN() ((void) 0)
#   define DISABLE_RB12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB12
#   define CONFIG_RB12_AS_ANALOG()       \
      do {                              \
        ENABLE_RB12_ANALOG();            \
        CONFIG_RB12_AS_INPUT();          \
        DISABLE_RB12_OPENDRAIN();        \
        DISABLE_RB12_PULLUP();           \
        DISABLE_RB12_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB13
#   define ENABLE_RB13_ANALOG()  (_ANSB13 = 1)
#   define DISABLE_RB13_ANALOG() (_ANSB13 = 0)
# else
#   define DISABLE_RB13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB13_AS_INPUT()  (_TRISB13 = 1)
# define CONFIG_RB13_AS_OUTPUT() (_TRISB13 = 0)

// Open-drain:
# if defined(_ODCB13)
#   define ENABLE_RB13_OPENDRAIN()  (_ODCB13 = 1)
#   define DISABLE_RB13_OPENDRAIN() (_ODCB13 = 0)
# else
#   define DISABLE_RB13_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB13
#   define ENABLE_RB13_PULLUP()  (_CNPUB13 = 1)
#   define DISABLE_RB13_PULLUP() (_CNPUB13 = 0)

#   define ENABLE_RB13_PULLDOWN()  (_CNPDB13 = 1)
#   define DISABLE_RB13_PULLDOWN() (_CNPDB13 = 0)

#   define ENABLE_RB13_CN_INTERRUPT()  (_CNIEB13 = 1)
#   define DISABLE_RB13_CN_INTERRUPT() (_CNIEB13 = 0)

# else
#   define DISABLE_RB13_PULLUP() ((void) 0)
#   define DISABLE_RB13_PULLDOWN() ((void) 0)
#   define DISABLE_RB13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB13
#   define CONFIG_RB13_AS_ANALOG()       \
      do {                              \
        ENABLE_RB13_ANALOG();            \
        CONFIG_RB13_AS_INPUT();          \
        DISABLE_RB13_OPENDRAIN();        \
        DISABLE_RB13_PULLUP();           \
        DISABLE_RB13_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB14
#   define ENABLE_RB14_ANALOG()  (_ANSB14 = 1)
#   define DISABLE_RB14_ANALOG() (_ANSB14 = 0)
# else
#   define DISABLE_RB14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB14_AS_INPUT()  (_TRISB14 = 1)
# define CONFIG_RB14_AS_OUTPUT() (_TRISB14 = 0)

// Open-drain:
# if defined(_ODCB14)
#   define ENABLE_RB14_OPENDRAIN()  (_ODCB14 = 1)
#   define DISABLE_RB14_OPENDRAIN() (_ODCB14 = 0)
# else
#   define DISABLE_RB14_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB14
#   define ENABLE_RB14_PULLUP()  (_CNPUB14 = 1)
#   define DISABLE_RB14_PULLUP() (_CNPUB14 = 0)

#   define ENABLE_RB14_PULLDOWN()  (_CNPDB14 = 1)
#   define DISABLE_RB14_PULLDOWN() (_CNPDB14 = 0)

#   define ENABLE_RB14_CN_INTERRUPT()  (_CNIEB14 = 1)
#   define DISABLE_RB14_CN_INTERRUPT() (_CNIEB14 = 0)

# else
#   define DISABLE_RB14_PULLUP() ((void) 0)
#   define DISABLE_RB14_PULLDOWN() ((void) 0)
#   define DISABLE_RB14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB14
#   define CONFIG_RB14_AS_ANALOG()       \
      do {                              \
        ENABLE_RB14_ANALOG();            \
        CONFIG_RB14_AS_INPUT();          \
        DISABLE_RB14_OPENDRAIN();        \
        DISABLE_RB14_PULLUP();           \
        DISABLE_RB14_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSB15
#   define ENABLE_RB15_ANALOG()  (_ANSB15 = 1)
#   define DISABLE_RB15_ANALOG() (_ANSB15 = 0)
# else
#   define DISABLE_RB15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RB15_AS_INPUT()  (_TRISB15 = 1)
# define CONFIG_RB15_AS_OUTPUT() (_TRISB15 = 0)

// Open-drain:
# if defined(_ODCB15)
#   define ENABLE_RB15_OPENDRAIN()  (_ODCB15 = 1)
#   define DISABLE_RB15_OPENDRAIN() (_ODCB15 = 0)
# else
#   define DISABLE_RB15_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEB15
#   define ENABLE_RB15_PULLUP()  (_CNPUB15 = 1)
#   define DISABLE_RB15_PULLUP() (_CNPUB15 = 0)

#   define ENABLE_RB15_PULLDOWN()  (_CNPDB15 = 1)
#   define DISABLE_RB15_PULLDOWN() (_CNPDB15 = 0)

#   define ENABLE_RB15_CN_INTERRUPT()  (_CNIEB15 = 1)
#   define DISABLE_RB15_CN_INTERRUPT() (_CNIEB15 = 0)

# else
#   define DISABLE_RB15_PULLUP() ((void) 0)
#   define DISABLE_RB15_PULLDOWN() ((void) 0)
#   define DISABLE_RB15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSB15
#   define CONFIG_RB15_AS_ANALOG()       \
      do {                              \
        ENABLE_RB15_ANALOG();            \
        CONFIG_RB15_AS_INPUT();          \
        DISABLE_RB15_OPENDRAIN();        \
        DISABLE_RB15_PULLUP();           \
        DISABLE_RB15_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC0
#   define ENABLE_RC0_ANALOG()  (_ANSC0 = 1)
#   define DISABLE_RC0_ANALOG() (_ANSC0 = 0)
# else
#   define DISABLE_RC0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC0_AS_INPUT()  (_TRISC0 = 1)
# define CONFIG_RC0_AS_OUTPUT() (_TRISC0 = 0)

// Open-drain:
# if defined(_ODCC0)
#   define ENABLE_RC0_OPENDRAIN()  (_ODCC0 = 1)
#   define DISABLE_RC0_OPENDRAIN() (_ODCC0 = 0)
# else
#   define DISABLE_RC0_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC0
#   define ENABLE_RC0_PULLUP()  (_CNPUC0 = 1)
#   define DISABLE_RC0_PULLUP() (_CNPUC0 = 0)

#   define ENABLE_RC0_PULLDOWN()  (_CNPDC0 = 1)
#   define DISABLE_RC0_PULLDOWN() (_CNPDC0 = 0)

#   define ENABLE_RC0_CN_INTERRUPT()  (_CNIEC0 = 1)
#   define DISABLE_RC0_CN_INTERRUPT() (_CNIEC0 = 0)

# else
#   define DISABLE_RC0_PULLUP() ((void) 0)
#   define DISABLE_RC0_PULLDOWN() ((void) 0)
#   define DISABLE_RC0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC0
#   define CONFIG_RC0_AS_ANALOG()       \
      do {                              \
        ENABLE_RC0_ANALOG();            \
        CONFIG_RC0_AS_INPUT();          \
        DISABLE_RC0_OPENDRAIN();        \
        DISABLE_RC0_PULLUP();           \
        DISABLE_RC0_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC1
#   define ENABLE_RC1_ANALOG()  (_ANSC1 = 1)
#   define DISABLE_RC1_ANALOG() (_ANSC1 = 0)
# else
#   define DISABLE_RC1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC1_AS_INPUT()  (_TRISC1 = 1)
# define CONFIG_RC1_AS_OUTPUT() (_TRISC1 = 0)

// Open-drain:
# if defined(_ODCC1)
#   define ENABLE_RC1_OPENDRAIN()  (_ODCC1 = 1)
#   define DISABLE_RC1_OPENDRAIN() (_ODCC1 = 0)
# else
#   define DISABLE_RC1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC1
#   define ENABLE_RC1_PULLUP()  (_CNPUC1 = 1)
#   define DISABLE_RC1_PULLUP() (_CNPUC1 = 0)

#   define ENABLE_RC1_PULLDOWN()  (_CNPDC1 = 1)
#   define DISABLE_RC1_PULLDOWN() (_CNPDC1 = 0)

#   define ENABLE_RC1_CN_INTERRUPT()  (_CNIEC1 = 1)
#   define DISABLE_RC1_CN_INTERRUPT() (_CNIEC1 = 0)

# else
#   define DISABLE_RC1_PULLUP() ((void) 0)
#   define DISABLE_RC1_PULLDOWN() ((void) 0)
#   define DISABLE_RC1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC1
#   define CONFIG_RC1_AS_ANALOG()       \
      do {                              \
        ENABLE_RC1_ANALOG();            \
        CONFIG_RC1_AS_INPUT();          \
        DISABLE_RC1_OPENDRAIN();        \
        DISABLE_RC1_PULLUP();           \
        DISABLE_RC1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC2
#   define ENABLE_RC2_ANALOG()  (_ANSC2 = 1)
#   define DISABLE_RC2_ANALOG() (_ANSC2 = 0)
# else
#   define DISABLE_RC2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC2_AS_INPUT()  (_TRISC2 = 1)
# define CONFIG_RC2_AS_OUTPUT() (_TRISC2 = 0)

// Open-drain:
# if defined(_ODCC2)
#   define ENABLE_RC2_OPENDRAIN()  (_ODCC2 = 1)
#   define DISABLE_RC2_OPENDRAIN() (_ODCC2 = 0)
# else
#   define DISABLE_RC2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC2
#   define ENABLE_RC2_PULLUP()  (_CNPUC2 = 1)
#   define DISABLE_RC2_PULLUP() (_CNPUC2 = 0)

#   define ENABLE_RC2_PULLDOWN()  (_CNPDC2 = 1)
#   define DISABLE_RC2_PULLDOWN() (_CNPDC2 = 0)

#   define ENABLE_RC2_CN_INTERRUPT()  (_CNIEC2 = 1)
#   define DISABLE_RC2_CN_INTERRUPT() (_CNIEC2 = 0)

# else
#   define DISABLE_RC2_PULLUP() ((void) 0)
#   define DISABLE_RC2_PULLDOWN() ((void) 0)
#   define DISABLE_RC2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC2
#   define CONFIG_RC2_AS_ANALOG()       \
      do {                              \
        ENABLE_RC2_ANALOG();            \
        CONFIG_RC2_AS_INPUT();          \
        DISABLE_RC2_OPENDRAIN();        \
        DISABLE_RC2_PULLUP();           \
        DISABLE_RC2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC3
#   define ENABLE_RC3_ANALOG()  (_ANSC3 = 1)
#   define DISABLE_RC3_ANALOG() (_ANSC3 = 0)
# else
#   define DISABLE_RC3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC3_AS_INPUT()  (_TRISC3 = 1)
# define CONFIG_RC3_AS_OUTPUT() (_TRISC3 = 0)

// Open-drain:
# if defined(_ODCC3)
#   define ENABLE_RC3_OPENDRAIN()  (_ODCC3 = 1)
#   define DISABLE_RC3_OPENDRAIN() (_ODCC3 = 0)
# else
#   define DISABLE_RC3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC3
#   define ENABLE_RC3_PULLUP()  (_CNPUC3 = 1)
#   define DISABLE_RC3_PULLUP() (_CNPUC3 = 0)

#   define ENABLE_RC3_PULLDOWN()  (_CNPDC3 = 1)
#   define DISABLE_RC3_PULLDOWN() (_CNPDC3 = 0)

#   define ENABLE_RC3_CN_INTERRUPT()  (_CNIEC3 = 1)
#   define DISABLE_RC3_CN_INTERRUPT() (_CNIEC3 = 0)

# else
#   define DISABLE_RC3_PULLUP() ((void) 0)
#   define DISABLE_RC3_PULLDOWN() ((void) 0)
#   define DISABLE_RC3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC3
#   define CONFIG_RC3_AS_ANALOG()       \
      do {                              \
        ENABLE_RC3_ANALOG();            \
        CONFIG_RC3_AS_INPUT();          \
        DISABLE_RC3_OPENDRAIN();        \
        DISABLE_RC3_PULLUP();           \
        DISABLE_RC3_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC4
#   define ENABLE_RC4_ANALOG()  (_ANSC4 = 1)
#   define DISABLE_RC4_ANALOG() (_ANSC4 = 0)
# else
#   define DISABLE_RC4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC4_AS_INPUT()  (_TRISC4 = 1)
# define CONFIG_RC4_AS_OUTPUT() (_TRISC4 = 0)

// Open-drain:
# if defined(_ODCC4)
#   define ENABLE_RC4_OPENDRAIN()  (_ODCC4 = 1)
#   define DISABLE_RC4_OPENDRAIN() (_ODCC4 = 0)
# else
#   define DISABLE_RC4_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC4
#   define ENABLE_RC4_PULLUP()  (_CNPUC4 = 1)
#   define DISABLE_RC4_PULLUP() (_CNPUC4 = 0)

#   define ENABLE_RC4_PULLDOWN()  (_CNPDC4 = 1)
#   define DISABLE_RC4_PULLDOWN() (_CNPDC4 = 0)

#   define ENABLE_RC4_CN_INTERRUPT()  (_CNIEC4 = 1)
#   define DISABLE_RC4_CN_INTERRUPT() (_CNIEC4 = 0)

# else
#   define DISABLE_RC4_PULLUP() ((void) 0)
#   define DISABLE_RC4_PULLDOWN() ((void) 0)
#   define DISABLE_RC4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC4
#   define CONFIG_RC4_AS_ANALOG()       \
      do {                              \
        ENABLE_RC4_ANALOG();            \
        CONFIG_RC4_AS_INPUT();          \
        DISABLE_RC4_OPENDRAIN();        \
        DISABLE_RC4_PULLUP();           \
        DISABLE_RC4_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC5
#   define ENABLE_RC5_ANALOG()  (_ANSC5 = 1)
#   define DISABLE_RC5_ANALOG() (_ANSC5 = 0)
# else
#   define DISABLE_RC5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC5_AS_INPUT()  (_TRISC5 = 1)
# define CONFIG_RC5_AS_OUTPUT() (_TRISC5 = 0)

// Open-drain:
# if defined(_ODCC5)
#   define ENABLE_RC5_OPENDRAIN()  (_ODCC5 = 1)
#   define DISABLE_RC5_OPENDRAIN() (_ODCC5 = 0)
# else
#   define DISABLE_RC5_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC5
#   define ENABLE_RC5_PULLUP()  (_CNPUC5 = 1)
#   define DISABLE_RC5_PULLUP() (_CNPUC5 = 0)

#   define ENABLE_RC5_PULLDOWN()  (_CNPDC5 = 1)
#   define DISABLE_RC5_PULLDOWN() (_CNPDC5 = 0)

#   define ENABLE_RC5_CN_INTERRUPT()  (_CNIEC5 = 1)
#   define DISABLE_RC5_CN_INTERRUPT() (_CNIEC5 = 0)

# else
#   define DISABLE_RC5_PULLUP() ((void) 0)
#   define DISABLE_RC5_PULLDOWN() ((void) 0)
#   define DISABLE_RC5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC5
#   define CONFIG_RC5_AS_ANALOG()       \
      do {                              \
        ENABLE_RC5_ANALOG();            \
        CONFIG_RC5_AS_INPUT();          \
        DISABLE_RC5_OPENDRAIN();        \
        DISABLE_RC5_PULLUP();           \
        DISABLE_RC5_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC6
#   define ENABLE_RC6_ANALOG()  (_ANSC6 = 1)
#   define DISABLE_RC6_ANALOG() (_ANSC6 = 0)
# else
#   define DISABLE_RC6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC6_AS_INPUT()  (_TRISC6 = 1)
# define CONFIG_RC6_AS_OUTPUT() (_TRISC6 = 0)

// Open-drain:
# if defined(_ODCC6)
#   define ENABLE_RC6_OPENDRAIN()  (_ODCC6 = 1)
#   define DISABLE_RC6_OPENDRAIN() (_ODCC6 = 0)
# else
#   define DISABLE_RC6_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC6
#   define ENABLE_RC6_PULLUP()  (_CNPUC6 = 1)
#   define DISABLE_RC6_PULLUP() (_CNPUC6 = 0)

#   define ENABLE_RC6_PULLDOWN()  (_CNPDC6 = 1)
#   define DISABLE_RC6_PULLDOWN() (_CNPDC6 = 0)

#   define ENABLE_RC6_CN_INTERRUPT()  (_CNIEC6 = 1)
#   define DISABLE_RC6_CN_INTERRUPT() (_CNIEC6 = 0)

# else
#   define DISABLE_RC6_PULLUP() ((void) 0)
#   define DISABLE_RC6_PULLDOWN() ((void) 0)
#   define DISABLE_RC6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC6
#   define CONFIG_RC6_AS_ANALOG()       \
      do {                              \
        ENABLE_RC6_ANALOG();            \
        CONFIG_RC6_AS_INPUT();          \
        DISABLE_RC6_OPENDRAIN();        \
        DISABLE_RC6_PULLUP();           \
        DISABLE_RC6_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC7
#   define ENABLE_RC7_ANALOG()  (_ANSC7 = 1)
#   define DISABLE_RC7_ANALOG() (_ANSC7 = 0)
# else
#   define DISABLE_RC7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC7_AS_INPUT()  (_TRISC7 = 1)
# define CONFIG_RC7_AS_OUTPUT() (_TRISC7 = 0)

// Open-drain:
# if defined(_ODCC7)
#   define ENABLE_RC7_OPENDRAIN()  (_ODCC7 = 1)
#   define DISABLE_RC7_OPENDRAIN() (_ODCC7 = 0)
# else
#   define DISABLE_RC7_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC7
#   define ENABLE_RC7_PULLUP()  (_CNPUC7 = 1)
#   define DISABLE_RC7_PULLUP() (_CNPUC7 = 0)

#   define ENABLE_RC7_PULLDOWN()  (_CNPDC7 = 1)
#   define DISABLE_RC7_PULLDOWN() (_CNPDC7 = 0)

#   define ENABLE_RC7_CN_INTERRUPT()  (_CNIEC7 = 1)
#   define DISABLE_RC7_CN_INTERRUPT() (_CNIEC7 = 0)

# else
#   define DISABLE_RC7_PULLUP() ((void) 0)
#   define DISABLE_RC7_PULLDOWN() ((void) 0)
#   define DISABLE_RC7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC7
#   define CONFIG_RC7_AS_ANALOG()       \
      do {                              \
        ENABLE_RC7_ANALOG();            \
        CONFIG_RC7_AS_INPUT();          \
        DISABLE_RC7_OPENDRAIN();        \
        DISABLE_RC7_PULLUP();           \
        DISABLE_RC7_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC8
#   define ENABLE_RC8_ANALOG()  (_ANSC8 = 1)
#   define DISABLE_RC8_ANALOG() (_ANSC8 = 0)
# else
#   define DISABLE_RC8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC8_AS_INPUT()  (_TRISC8 = 1)
# define CONFIG_RC8_AS_OUTPUT() (_TRISC8 = 0)

// Open-drain:
# if defined(_ODCC8)
#   define ENABLE_RC8_OPENDRAIN()  (_ODCC8 = 1)
#   define DISABLE_RC8_OPENDRAIN() (_ODCC8 = 0)
# else
#   define DISABLE_RC8_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC8
#   define ENABLE_RC8_PULLUP()  (_CNPUC8 = 1)
#   define DISABLE_RC8_PULLUP() (_CNPUC8 = 0)

#   define ENABLE_RC8_PULLDOWN()  (_CNPDC8 = 1)
#   define DISABLE_RC8_PULLDOWN() (_CNPDC8 = 0)

#   define ENABLE_RC8_CN_INTERRUPT()  (_CNIEC8 = 1)
#   define DISABLE_RC8_CN_INTERRUPT() (_CNIEC8 = 0)

# else
#   define DISABLE_RC8_PULLUP() ((void) 0)
#   define DISABLE_RC8_PULLDOWN() ((void) 0)
#   define DISABLE_RC8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC8
#   define CONFIG_RC8_AS_ANALOG()       \
      do {                              \
        ENABLE_RC8_ANALOG();            \
        CONFIG_RC8_AS_INPUT();          \
        DISABLE_RC8_OPENDRAIN();        \
        DISABLE_RC8_PULLUP();           \
        DISABLE_RC8_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC9
#   define ENABLE_RC9_ANALOG()  (_ANSC9 = 1)
#   define DISABLE_RC9_ANALOG() (_ANSC9 = 0)
# else
#   define DISABLE_RC9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC9_AS_INPUT()  (_TRISC9 = 1)
# define CONFIG_RC9_AS_OUTPUT() (_TRISC9 = 0)

// Open-drain:
# if defined(_ODCC9)
#   define ENABLE_RC9_OPENDRAIN()  (_ODCC9 = 1)
#   define DISABLE_RC9_OPENDRAIN() (_ODCC9 = 0)
# else
#   define DISABLE_RC9_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC9
#   define ENABLE_RC9_PULLUP()  (_CNPUC9 = 1)
#   define DISABLE_RC9_PULLUP() (_CNPUC9 = 0)

#   define ENABLE_RC9_PULLDOWN()  (_CNPDC9 = 1)
#   define DISABLE_RC9_PULLDOWN() (_CNPDC9 = 0)

#   define ENABLE_RC9_CN_INTERRUPT()  (_CNIEC9 = 1)
#   define DISABLE_RC9_CN_INTERRUPT() (_CNIEC9 = 0)

# else
#   define DISABLE_RC9_PULLUP() ((void) 0)
#   define DISABLE_RC9_PULLDOWN() ((void) 0)
#   define DISABLE_RC9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC9
#   define CONFIG_RC9_AS_ANALOG()       \
      do {                              \
        ENABLE_RC9_ANALOG();            \
        CONFIG_RC9_AS_INPUT();          \
        DISABLE_RC9_OPENDRAIN();        \
        DISABLE_RC9_PULLUP();           \
        DISABLE_RC9_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC10
#   define ENABLE_RC10_ANALOG()  (_ANSC10 = 1)
#   define DISABLE_RC10_ANALOG() (_ANSC10 = 0)
# else
#   define DISABLE_RC10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC10_AS_INPUT()  (_TRISC10 = 1)
# define CONFIG_RC10_AS_OUTPUT() (_TRISC10 = 0)

// Open-drain:
# if defined(_ODCC10)
#   define ENABLE_RC10_OPENDRAIN()  (_ODCC10 = 1)
#   define DISABLE_RC10_OPENDRAIN() (_ODCC10 = 0)
# else
#   define DISABLE_RC10_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC10
#   define ENABLE_RC10_PULLUP()  (_CNPUC10 = 1)
#   define DISABLE_RC10_PULLUP() (_CNPUC10 = 0)

#   define ENABLE_RC10_PULLDOWN()  (_CNPDC10 = 1)
#   define DISABLE_RC10_PULLDOWN() (_CNPDC10 = 0)

#   define ENABLE_RC10_CN_INTERRUPT()  (_CNIEC10 = 1)
#   define DISABLE_RC10_CN_INTERRUPT() (_CNIEC10 = 0)

# else
#   define DISABLE_RC10_PULLUP() ((void) 0)
#   define DISABLE_RC10_PULLDOWN() ((void) 0)
#   define DISABLE_RC10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC10
#   define CONFIG_RC10_AS_ANALOG()       \
      do {                              \
        ENABLE_RC10_ANALOG();            \
        CONFIG_RC10_AS_INPUT();          \
        DISABLE_RC10_OPENDRAIN();        \
        DISABLE_RC10_PULLUP();           \
        DISABLE_RC10_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC11
#   define ENABLE_RC11_ANALOG()  (_ANSC11 = 1)
#   define DISABLE_RC11_ANALOG() (_ANSC11 = 0)
# else
#   define DISABLE_RC11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC11_AS_INPUT()  (_TRISC11 = 1)
# define CONFIG_RC11_AS_OUTPUT() (_TRISC11 = 0)

// Open-drain:
# if defined(_ODCC11)
#   define ENABLE_RC11_OPENDRAIN()  (_ODCC11 = 1)
#   define DISABLE_RC11_OPENDRAIN() (_ODCC11 = 0)
# else
#   define DISABLE_RC11_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC11
#   define ENABLE_RC11_PULLUP()  (_CNPUC11 = 1)
#   define DISABLE_RC11_PULLUP() (_CNPUC11 = 0)

#   define ENABLE_RC11_PULLDOWN()  (_CNPDC11 = 1)
#   define DISABLE_RC11_PULLDOWN() (_CNPDC11 = 0)

#   define ENABLE_RC11_CN_INTERRUPT()  (_CNIEC11 = 1)
#   define DISABLE_RC11_CN_INTERRUPT() (_CNIEC11 = 0)

# else
#   define DISABLE_RC11_PULLUP() ((void) 0)
#   define DISABLE_RC11_PULLDOWN() ((void) 0)
#   define DISABLE_RC11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC11
#   define CONFIG_RC11_AS_ANALOG()       \
      do {                              \
        ENABLE_RC11_ANALOG();            \
        CONFIG_RC11_AS_INPUT();          \
        DISABLE_RC11_OPENDRAIN();        \
        DISABLE_RC11_PULLUP();           \
        DISABLE_RC11_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC12
#   define ENABLE_RC12_ANALOG()  (_ANSC12 = 1)
#   define DISABLE_RC12_ANALOG() (_ANSC12 = 0)
# else
#   define DISABLE_RC12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC12_AS_INPUT()  (_TRISC12 = 1)
# define CONFIG_RC12_AS_OUTPUT() (_TRISC12 = 0)

// Open-drain:
# if defined(_ODCC12)
#   define ENABLE_RC12_OPENDRAIN()  (_ODCC12 = 1)
#   define DISABLE_RC12_OPENDRAIN() (_ODCC12 = 0)
# else
#   define DISABLE_RC12_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC12
#   define ENABLE_RC12_PULLUP()  (_CNPUC12 = 1)
#   define DISABLE_RC12_PULLUP() (_CNPUC12 = 0)

#   define ENABLE_RC12_PULLDOWN()  (_CNPDC12 = 1)
#   define DISABLE_RC12_PULLDOWN() (_CNPDC12 = 0)

#   define ENABLE_RC12_CN_INTERRUPT()  (_CNIEC12 = 1)
#   define DISABLE_RC12_CN_INTERRUPT() (_CNIEC12 = 0)

# else
#   define DISABLE_RC12_PULLUP() ((void) 0)
#   define DISABLE_RC12_PULLDOWN() ((void) 0)
#   define DISABLE_RC12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC12
#   define CONFIG_RC12_AS_ANALOG()       \
      do {                              \
        ENABLE_RC12_ANALOG();            \
        CONFIG_RC12_AS_INPUT();          \
        DISABLE_RC12_OPENDRAIN();        \
        DISABLE_RC12_PULLUP();           \
        DISABLE_RC12_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC13
#   define ENABLE_RC13_ANALOG()  (_ANSC13 = 1)
#   define DISABLE_RC13_ANALOG() (_ANSC13 = 0)
# else
#   define DISABLE_RC13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC13_AS_INPUT()  (_TRISC13 = 1)
# define CONFIG_RC13_AS_OUTPUT() (_TRISC13 = 0)

// Open-drain:
# if defined(_ODCC13)
#   define ENABLE_RC13_OPENDRAIN()  (_ODCC13 = 1)
#   define DISABLE_RC13_OPENDRAIN() (_ODCC13 = 0)
# else
#   define DISABLE_RC13_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC13
#   define ENABLE_RC13_PULLUP()  (_CNPUC13 = 1)
#   define DISABLE_RC13_PULLUP() (_CNPUC13 = 0)

#   define ENABLE_RC13_PULLDOWN()  (_CNPDC13 = 1)
#   define DISABLE_RC13_PULLDOWN() (_CNPDC13 = 0)

#   define ENABLE_RC13_CN_INTERRUPT()  (_CNIEC13 = 1)
#   define DISABLE_RC13_CN_INTERRUPT() (_CNIEC13 = 0)

# else
#   define DISABLE_RC13_PULLUP() ((void) 0)
#   define DISABLE_RC13_PULLDOWN() ((void) 0)
#   define DISABLE_RC13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC13
#   define CONFIG_RC13_AS_ANALOG()       \
      do {                              \
        ENABLE_RC13_ANALOG();            \
        CONFIG_RC13_AS_INPUT();          \
        DISABLE_RC13_OPENDRAIN();        \
        DISABLE_RC13_PULLUP();           \
        DISABLE_RC13_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC14
#   define ENABLE_RC14_ANALOG()  (_ANSC14 = 1)
#   define DISABLE_RC14_ANALOG() (_ANSC14 = 0)
# else
#   define DISABLE_RC14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC14_AS_INPUT()  (_TRISC14 = 1)
# define CONFIG_RC14_AS_OUTPUT() (_TRISC14 = 0)

// Open-drain:
# if defined(_ODCC14)
#   define ENABLE_RC14_OPENDRAIN()  (_ODCC14 = 1)
#   define DISABLE_RC14_OPENDRAIN() (_ODCC14 = 0)
# else
#   define DISABLE_RC14_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC14
#   define ENABLE_RC14_PULLUP()  (_CNPUC14 = 1)
#   define DISABLE_RC14_PULLUP() (_CNPUC14 = 0)

#   define ENABLE_RC14_PULLDOWN()  (_CNPDC14 = 1)
#   define DISABLE_RC14_PULLDOWN() (_CNPDC14 = 0)

#   define ENABLE_RC14_CN_INTERRUPT()  (_CNIEC14 = 1)
#   define DISABLE_RC14_CN_INTERRUPT() (_CNIEC14 = 0)

# else
#   define DISABLE_RC14_PULLUP() ((void) 0)
#   define DISABLE_RC14_PULLDOWN() ((void) 0)
#   define DISABLE_RC14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC14
#   define CONFIG_RC14_AS_ANALOG()       \
      do {                              \
        ENABLE_RC14_ANALOG();            \
        CONFIG_RC14_AS_INPUT();          \
        DISABLE_RC14_OPENDRAIN();        \
        DISABLE_RC14_PULLUP();           \
        DISABLE_RC14_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSC15
#   define ENABLE_RC15_ANALOG()  (_ANSC15 = 1)
#   define DISABLE_RC15_ANALOG() (_ANSC15 = 0)
# else
#   define DISABLE_RC15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RC15_AS_INPUT()  (_TRISC15 = 1)
# define CONFIG_RC15_AS_OUTPUT() (_TRISC15 = 0)

// Open-drain:
# if defined(_ODCC15)
#   define ENABLE_RC15_OPENDRAIN()  (_ODCC15 = 1)
#   define DISABLE_RC15_OPENDRAIN() (_ODCC15 = 0)
# else
#   define DISABLE_RC15_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEC15
#   define ENABLE_RC15_PULLUP()  (_CNPUC15 = 1)
#   define DISABLE_RC15_PULLUP() (_CNPUC15 = 0)

#   define ENABLE_RC15_PULLDOWN()  (_CNPDC15 = 1)
#   define DISABLE_RC15_PULLDOWN() (_CNPDC15 = 0)

#   define ENABLE_RC15_CN_INTERRUPT()  (_CNIEC15 = 1)
#   define DISABLE_RC15_CN_INTERRUPT() (_CNIEC15 = 0)

# else
#   define DISABLE_RC15_PULLUP() ((void) 0)
#   define DISABLE_RC15_PULLDOWN() ((void) 0)
#   define DISABLE_RC15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSC15
#   define CONFIG_RC15_AS_ANALOG()       \
      do {                              \
        ENABLE_RC15_ANALOG();            \
        CONFIG_RC15_AS_INPUT();          \
        DISABLE_RC15_OPENDRAIN();        \
        DISABLE_RC15_PULLUP();           \
        DISABLE_RC15_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD0
#   define ENABLE_RD0_ANALOG()  (_ANSD0 = 1)
#   define DISABLE_RD0_ANALOG() (_ANSD0 = 0)
# else
#   define DISABLE_RD0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD0_AS_INPUT()  (_TRISD0 = 1)
# define CONFIG_RD0_AS_OUTPUT() (_TRISD0 = 0)

// Open-drain:
# if defined(_ODCD0)
#   define ENABLE_RD0_OPENDRAIN()  (_ODCD0 = 1)
#   define DISABLE_RD0_OPENDRAIN() (_ODCD0 = 0)
# else
#   define DISABLE_RD0_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED0
#   define ENABLE_RD0_PULLUP()  (_CNPUD0 = 1)
#   define DISABLE_RD0_PULLUP() (_CNPUD0 = 0)

#   define ENABLE_RD0_PULLDOWN()  (_CNPDD0 = 1)
#   define DISABLE_RD0_PULLDOWN() (_CNPDD0 = 0)

#   define ENABLE_RD0_CN_INTERRUPT()  (_CNIED0 = 1)
#   define DISABLE_RD0_CN_INTERRUPT() (_CNIED0 = 0)

# else
#   define DISABLE_RD0_PULLUP() ((void) 0)
#   define DISABLE_RD0_PULLDOWN() ((void) 0)
#   define DISABLE_RD0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD0
#   define CONFIG_RD0_AS_ANALOG()       \
      do {                              \
        ENABLE_RD0_ANALOG();            \
        CONFIG_RD0_AS_INPUT();          \
        DISABLE_RD0_OPENDRAIN();        \
        DISABLE_RD0_PULLUP();           \
        DISABLE_RD0_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD1
#   define ENABLE_RD1_ANALOG()  (_ANSD1 = 1)
#   define DISABLE_RD1_ANALOG() (_ANSD1 = 0)
# else
#   define DISABLE_RD1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD1_AS_INPUT()  (_TRISD1 = 1)
# define CONFIG_RD1_AS_OUTPUT() (_TRISD1 = 0)

// Open-drain:
# if defined(_ODCD1)
#   define ENABLE_RD1_OPENDRAIN()  (_ODCD1 = 1)
#   define DISABLE_RD1_OPENDRAIN() (_ODCD1 = 0)
# else
#   define DISABLE_RD1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED1
#   define ENABLE_RD1_PULLUP()  (_CNPUD1 = 1)
#   define DISABLE_RD1_PULLUP() (_CNPUD1 = 0)

#   define ENABLE_RD1_PULLDOWN()  (_CNPDD1 = 1)
#   define DISABLE_RD1_PULLDOWN() (_CNPDD1 = 0)

#   define ENABLE_RD1_CN_INTERRUPT()  (_CNIED1 = 1)
#   define DISABLE_RD1_CN_INTERRUPT() (_CNIED1 = 0)

# else
#   define DISABLE_RD1_PULLUP() ((void) 0)
#   define DISABLE_RD1_PULLDOWN() ((void) 0)
#   define DISABLE_RD1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD1
#   define CONFIG_RD1_AS_ANALOG()       \
      do {                              \
        ENABLE_RD1_ANALOG();            \
        CONFIG_RD1_AS_INPUT();          \
        DISABLE_RD1_OPENDRAIN();        \
        DISABLE_RD1_PULLUP();           \
        DISABLE_RD1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD2
#   define ENABLE_RD2_ANALOG()  (_ANSD2 = 1)
#   define DISABLE_RD2_ANALOG() (_ANSD2 = 0)
# else
#   define DISABLE_RD2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD2_AS_INPUT()  (_TRISD2 = 1)
# define CONFIG_RD2_AS_OUTPUT() (_TRISD2 = 0)

// Open-drain:
# if defined(_ODCD2)
#   define ENABLE_RD2_OPENDRAIN()  (_ODCD2 = 1)
#   define DISABLE_RD2_OPENDRAIN() (_ODCD2 = 0)
# else
#   define DISABLE_RD2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED2
#   define ENABLE_RD2_PULLUP()  (_CNPUD2 = 1)
#   define DISABLE_RD2_PULLUP() (_CNPUD2 = 0)

#   define ENABLE_RD2_PULLDOWN()  (_CNPDD2 = 1)
#   define DISABLE_RD2_PULLDOWN() (_CNPDD2 = 0)

#   define ENABLE_RD2_CN_INTERRUPT()  (_CNIED2 = 1)
#   define DISABLE_RD2_CN_INTERRUPT() (_CNIED2 = 0)

# else
#   define DISABLE_RD2_PULLUP() ((void) 0)
#   define DISABLE_RD2_PULLDOWN() ((void) 0)
#   define DISABLE_RD2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD2
#   define CONFIG_RD2_AS_ANALOG()       \
      do {                              \
        ENABLE_RD2_ANALOG();            \
        CONFIG_RD2_AS_INPUT();          \
        DISABLE_RD2_OPENDRAIN();        \
        DISABLE_RD2_PULLUP();           \
        DISABLE_RD2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD3
#   define ENABLE_RD3_ANALOG()  (_ANSD3 = 1)
#   define DISABLE_RD3_ANALOG() (_ANSD3 = 0)
# else
#   define DISABLE_RD3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD3_AS_INPUT()  (_TRISD3 = 1)
# define CONFIG_RD3_AS_OUTPUT() (_TRISD3 = 0)

// Open-drain:
# if defined(_ODCD3)
#   define ENABLE_RD3_OPENDRAIN()  (_ODCD3 = 1)
#   define DISABLE_RD3_OPENDRAIN() (_ODCD3 = 0)
# else
#   define DISABLE_RD3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED3
#   define ENABLE_RD3_PULLUP()  (_CNPUD3 = 1)
#   define DISABLE_RD3_PULLUP() (_CNPUD3 = 0)

#   define ENABLE_RD3_PULLDOWN()  (_CNPDD3 = 1)
#   define DISABLE_RD3_PULLDOWN() (_CNPDD3 = 0)

#   define ENABLE_RD3_CN_INTERRUPT()  (_CNIED3 = 1)
#   define DISABLE_RD3_CN_INTERRUPT() (_CNIED3 = 0)

# else
#   define DISABLE_RD3_PULLUP() ((void) 0)
#   define DISABLE_RD3_PULLDOWN() ((void) 0)
#   define DISABLE_RD3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD3
#   define CONFIG_RD3_AS_ANALOG()       \
      do {                              \
        ENABLE_RD3_ANALOG();            \
        CONFIG_RD3_AS_INPUT();          \
        DISABLE_RD3_OPENDRAIN();        \
        DISABLE_RD3_PULLUP();           \
        DISABLE_RD3_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD4
#   define ENABLE_RD4_ANALOG()  (_ANSD4 = 1)
#   define DISABLE_RD4_ANALOG() (_ANSD4 = 0)
# else
#   define DISABLE_RD4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD4_AS_INPUT()  (_TRISD4 = 1)
# define CONFIG_RD4_AS_OUTPUT() (_TRISD4 = 0)

// Open-drain:
# if defined(_ODCD4)
#   define ENABLE_RD4_OPENDRAIN()  (_ODCD4 = 1)
#   define DISABLE_RD4_OPENDRAIN() (_ODCD4 = 0)
# else
#   define DISABLE_RD4_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED4
#   define ENABLE_RD4_PULLUP()  (_CNPUD4 = 1)
#   define DISABLE_RD4_PULLUP() (_CNPUD4 = 0)

#   define ENABLE_RD4_PULLDOWN()  (_CNPDD4 = 1)
#   define DISABLE_RD4_PULLDOWN() (_CNPDD4 = 0)

#   define ENABLE_RD4_CN_INTERRUPT()  (_CNIED4 = 1)
#   define DISABLE_RD4_CN_INTERRUPT() (_CNIED4 = 0)

# else
#   define DISABLE_RD4_PULLUP() ((void) 0)
#   define DISABLE_RD4_PULLDOWN() ((void) 0)
#   define DISABLE_RD4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD4
#   define CONFIG_RD4_AS_ANALOG()       \
      do {                              \
        ENABLE_RD4_ANALOG();            \
        CONFIG_RD4_AS_INPUT();          \
        DISABLE_RD4_OPENDRAIN();        \
        DISABLE_RD4_PULLUP();           \
        DISABLE_RD4_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD5
#   define ENABLE_RD5_ANALOG()  (_ANSD5 = 1)
#   define DISABLE_RD5_ANALOG() (_ANSD5 = 0)
# else
#   define DISABLE_RD5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD5_AS_INPUT()  (_TRISD5 = 1)
# define CONFIG_RD5_AS_OUTPUT() (_TRISD5 = 0)

// Open-drain:
# if defined(_ODCD5)
#   define ENABLE_RD5_OPENDRAIN()  (_ODCD5 = 1)
#   define DISABLE_RD5_OPENDRAIN() (_ODCD5 = 0)
# else
#   define DISABLE_RD5_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED5
#   define ENABLE_RD5_PULLUP()  (_CNPUD5 = 1)
#   define DISABLE_RD5_PULLUP() (_CNPUD5 = 0)

#   define ENABLE_RD5_PULLDOWN()  (_CNPDD5 = 1)
#   define DISABLE_RD5_PULLDOWN() (_CNPDD5 = 0)

#   define ENABLE_RD5_CN_INTERRUPT()  (_CNIED5 = 1)
#   define DISABLE_RD5_CN_INTERRUPT() (_CNIED5 = 0)

# else
#   define DISABLE_RD5_PULLUP() ((void) 0)
#   define DISABLE_RD5_PULLDOWN() ((void) 0)
#   define DISABLE_RD5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD5
#   define CONFIG_RD5_AS_ANALOG()       \
      do {                              \
        ENABLE_RD5_ANALOG();            \
        CONFIG_RD5_AS_INPUT();          \
        DISABLE_RD5_OPENDRAIN();        \
        DISABLE_RD5_PULLUP();           \
        DISABLE_RD5_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD6
#   define ENABLE_RD6_ANALOG()  (_ANSD6 = 1)
#   define DISABLE_RD6_ANALOG() (_ANSD6 = 0)
# else
#   define DISABLE_RD6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD6_AS_INPUT()  (_TRISD6 = 1)
# define CONFIG_RD6_AS_OUTPUT() (_TRISD6 = 0)

// Open-drain:
# if defined(_ODCD6)
#   define ENABLE_RD6_OPENDRAIN()  (_ODCD6 = 1)
#   define DISABLE_RD6_OPENDRAIN() (_ODCD6 = 0)
# else
#   define DISABLE_RD6_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED6
#   define ENABLE_RD6_PULLUP()  (_CNPUD6 = 1)
#   define DISABLE_RD6_PULLUP() (_CNPUD6 = 0)

#   define ENABLE_RD6_PULLDOWN()  (_CNPDD6 = 1)
#   define DISABLE_RD6_PULLDOWN() (_CNPDD6 = 0)

#   define ENABLE_RD6_CN_INTERRUPT()  (_CNIED6 = 1)
#   define DISABLE_RD6_CN_INTERRUPT() (_CNIED6 = 0)

# else
#   define DISABLE_RD6_PULLUP() ((void) 0)
#   define DISABLE_RD6_PULLDOWN() ((void) 0)
#   define DISABLE_RD6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD6
#   define CONFIG_RD6_AS_ANALOG()       \
      do {                              \
        ENABLE_RD6_ANALOG();            \
        CONFIG_RD6_AS_INPUT();          \
        DISABLE_RD6_OPENDRAIN();        \
        DISABLE_RD6_PULLUP();           \
        DISABLE_RD6_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD7
#   define ENABLE_RD7_ANALOG()  (_ANSD7 = 1)
#   define DISABLE_RD7_ANALOG() (_ANSD7 = 0)
# else
#   define DISABLE_RD7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD7_AS_INPUT()  (_TRISD7 = 1)
# define CONFIG_RD7_AS_OUTPUT() (_TRISD7 = 0)

// Open-drain:
# if defined(_ODCD7)
#   define ENABLE_RD7_OPENDRAIN()  (_ODCD7 = 1)
#   define DISABLE_RD7_OPENDRAIN() (_ODCD7 = 0)
# else
#   define DISABLE_RD7_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED7
#   define ENABLE_RD7_PULLUP()  (_CNPUD7 = 1)
#   define DISABLE_RD7_PULLUP() (_CNPUD7 = 0)

#   define ENABLE_RD7_PULLDOWN()  (_CNPDD7 = 1)
#   define DISABLE_RD7_PULLDOWN() (_CNPDD7 = 0)

#   define ENABLE_RD7_CN_INTERRUPT()  (_CNIED7 = 1)
#   define DISABLE_RD7_CN_INTERRUPT() (_CNIED7 = 0)

# else
#   define DISABLE_RD7_PULLUP() ((void) 0)
#   define DISABLE_RD7_PULLDOWN() ((void) 0)
#   define DISABLE_RD7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD7
#   define CONFIG_RD7_AS_ANALOG()       \
      do {                              \
        ENABLE_RD7_ANALOG();            \
        CONFIG_RD7_AS_INPUT();          \
        DISABLE_RD7_OPENDRAIN();        \
        DISABLE_RD7_PULLUP();           \
        DISABLE_RD7_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD8
#   define ENABLE_RD8_ANALOG()  (_ANSD8 = 1)
#   define DISABLE_RD8_ANALOG() (_ANSD8 = 0)
# else
#   define DISABLE_RD8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD8_AS_INPUT()  (_TRISD8 = 1)
# define CONFIG_RD8_AS_OUTPUT() (_TRISD8 = 0)

// Open-drain:
# if defined(_ODCD8)
#   define ENABLE_RD8_OPENDRAIN()  (_ODCD8 = 1)
#   define DISABLE_RD8_OPENDRAIN() (_ODCD8 = 0)
# else
#   define DISABLE_RD8_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED8
#   define ENABLE_RD8_PULLUP()  (_CNPUD8 = 1)
#   define DISABLE_RD8_PULLUP() (_CNPUD8 = 0)

#   define ENABLE_RD8_PULLDOWN()  (_CNPDD8 = 1)
#   define DISABLE_RD8_PULLDOWN() (_CNPDD8 = 0)

#   define ENABLE_RD8_CN_INTERRUPT()  (_CNIED8 = 1)
#   define DISABLE_RD8_CN_INTERRUPT() (_CNIED8 = 0)

# else
#   define DISABLE_RD8_PULLUP() ((void) 0)
#   define DISABLE_RD8_PULLDOWN() ((void) 0)
#   define DISABLE_RD8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD8
#   define CONFIG_RD8_AS_ANALOG()       \
      do {                              \
        ENABLE_RD8_ANALOG();            \
        CONFIG_RD8_AS_INPUT();          \
        DISABLE_RD8_OPENDRAIN();        \
        DISABLE_RD8_PULLUP();           \
        DISABLE_RD8_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD9
#   define ENABLE_RD9_ANALOG()  (_ANSD9 = 1)
#   define DISABLE_RD9_ANALOG() (_ANSD9 = 0)
# else
#   define DISABLE_RD9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD9_AS_INPUT()  (_TRISD9 = 1)
# define CONFIG_RD9_AS_OUTPUT() (_TRISD9 = 0)

// Open-drain:
# if defined(_ODCD9)
#   define ENABLE_RD9_OPENDRAIN()  (_ODCD9 = 1)
#   define DISABLE_RD9_OPENDRAIN() (_ODCD9 = 0)
# else
#   define DISABLE_RD9_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED9
#   define ENABLE_RD9_PULLUP()  (_CNPUD9 = 1)
#   define DISABLE_RD9_PULLUP() (_CNPUD9 = 0)

#   define ENABLE_RD9_PULLDOWN()  (_CNPDD9 = 1)
#   define DISABLE_RD9_PULLDOWN() (_CNPDD9 = 0)

#   define ENABLE_RD9_CN_INTERRUPT()  (_CNIED9 = 1)
#   define DISABLE_RD9_CN_INTERRUPT() (_CNIED9 = 0)

# else
#   define DISABLE_RD9_PULLUP() ((void) 0)
#   define DISABLE_RD9_PULLDOWN() ((void) 0)
#   define DISABLE_RD9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD9
#   define CONFIG_RD9_AS_ANALOG()       \
      do {                              \
        ENABLE_RD9_ANALOG();            \
        CONFIG_RD9_AS_INPUT();          \
        DISABLE_RD9_OPENDRAIN();        \
        DISABLE_RD9_PULLUP();           \
        DISABLE_RD9_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD10
#   define ENABLE_RD10_ANALOG()  (_ANSD10 = 1)
#   define DISABLE_RD10_ANALOG() (_ANSD10 = 0)
# else
#   define DISABLE_RD10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD10_AS_INPUT()  (_TRISD10 = 1)
# define CONFIG_RD10_AS_OUTPUT() (_TRISD10 = 0)

// Open-drain:
# if defined(_ODCD10)
#   define ENABLE_RD10_OPENDRAIN()  (_ODCD10 = 1)
#   define DISABLE_RD10_OPENDRAIN() (_ODCD10 = 0)
# else
#   define DISABLE_RD10_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED10
#   define ENABLE_RD10_PULLUP()  (_CNPUD10 = 1)
#   define DISABLE_RD10_PULLUP() (_CNPUD10 = 0)

#   define ENABLE_RD10_PULLDOWN()  (_CNPDD10 = 1)
#   define DISABLE_RD10_PULLDOWN() (_CNPDD10 = 0)

#   define ENABLE_RD10_CN_INTERRUPT()  (_CNIED10 = 1)
#   define DISABLE_RD10_CN_INTERRUPT() (_CNIED10 = 0)

# else
#   define DISABLE_RD10_PULLUP() ((void) 0)
#   define DISABLE_RD10_PULLDOWN() ((void) 0)
#   define DISABLE_RD10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD10
#   define CONFIG_RD10_AS_ANALOG()       \
      do {                              \
        ENABLE_RD10_ANALOG();            \
        CONFIG_RD10_AS_INPUT();          \
        DISABLE_RD10_OPENDRAIN();        \
        DISABLE_RD10_PULLUP();           \
        DISABLE_RD10_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD11
#   define ENABLE_RD11_ANALOG()  (_ANSD11 = 1)
#   define DISABLE_RD11_ANALOG() (_ANSD11 = 0)
# else
#   define DISABLE_RD11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD11_AS_INPUT()  (_TRISD11 = 1)
# define CONFIG_RD11_AS_OUTPUT() (_TRISD11 = 0)

// Open-drain:
# if defined(_ODCD11)
#   define ENABLE_RD11_OPENDRAIN()  (_ODCD11 = 1)
#   define DISABLE_RD11_OPENDRAIN() (_ODCD11 = 0)
# else
#   define DISABLE_RD11_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED11
#   define ENABLE_RD11_PULLUP()  (_CNPUD11 = 1)
#   define DISABLE_RD11_PULLUP() (_CNPUD11 = 0)

#   define ENABLE_RD11_PULLDOWN()  (_CNPDD11 = 1)
#   define DISABLE_RD11_PULLDOWN() (_CNPDD11 = 0)

#   define ENABLE_RD11_CN_INTERRUPT()  (_CNIED11 = 1)
#   define DISABLE_RD11_CN_INTERRUPT() (_CNIED11 = 0)

# else
#   define DISABLE_RD11_PULLUP() ((void) 0)
#   define DISABLE_RD11_PULLDOWN() ((void) 0)
#   define DISABLE_RD11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD11
#   define CONFIG_RD11_AS_ANALOG()       \
      do {                              \
        ENABLE_RD11_ANALOG();            \
        CONFIG_RD11_AS_INPUT();          \
        DISABLE_RD11_OPENDRAIN();        \
        DISABLE_RD11_PULLUP();           \
        DISABLE_RD11_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD12
#   define ENABLE_RD12_ANALOG()  (_ANSD12 = 1)
#   define DISABLE_RD12_ANALOG() (_ANSD12 = 0)
# else
#   define DISABLE_RD12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD12_AS_INPUT()  (_TRISD12 = 1)
# define CONFIG_RD12_AS_OUTPUT() (_TRISD12 = 0)

// Open-drain:
# if defined(_ODCD12)
#   define ENABLE_RD12_OPENDRAIN()  (_ODCD12 = 1)
#   define DISABLE_RD12_OPENDRAIN() (_ODCD12 = 0)
# else
#   define DISABLE_RD12_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED12
#   define ENABLE_RD12_PULLUP()  (_CNPUD12 = 1)
#   define DISABLE_RD12_PULLUP() (_CNPUD12 = 0)

#   define ENABLE_RD12_PULLDOWN()  (_CNPDD12 = 1)
#   define DISABLE_RD12_PULLDOWN() (_CNPDD12 = 0)

#   define ENABLE_RD12_CN_INTERRUPT()  (_CNIED12 = 1)
#   define DISABLE_RD12_CN_INTERRUPT() (_CNIED12 = 0)

# else
#   define DISABLE_RD12_PULLUP() ((void) 0)
#   define DISABLE_RD12_PULLDOWN() ((void) 0)
#   define DISABLE_RD12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD12
#   define CONFIG_RD12_AS_ANALOG()       \
      do {                              \
        ENABLE_RD12_ANALOG();            \
        CONFIG_RD12_AS_INPUT();          \
        DISABLE_RD12_OPENDRAIN();        \
        DISABLE_RD12_PULLUP();           \
        DISABLE_RD12_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD13
#   define ENABLE_RD13_ANALOG()  (_ANSD13 = 1)
#   define DISABLE_RD13_ANALOG() (_ANSD13 = 0)
# else
#   define DISABLE_RD13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD13_AS_INPUT()  (_TRISD13 = 1)
# define CONFIG_RD13_AS_OUTPUT() (_TRISD13 = 0)

// Open-drain:
# if defined(_ODCD13)
#   define ENABLE_RD13_OPENDRAIN()  (_ODCD13 = 1)
#   define DISABLE_RD13_OPENDRAIN() (_ODCD13 = 0)
# else
#   define DISABLE_RD13_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED13
#   define ENABLE_RD13_PULLUP()  (_CNPUD13 = 1)
#   define DISABLE_RD13_PULLUP() (_CNPUD13 = 0)

#   define ENABLE_RD13_PULLDOWN()  (_CNPDD13 = 1)
#   define DISABLE_RD13_PULLDOWN() (_CNPDD13 = 0)

#   define ENABLE_RD13_CN_INTERRUPT()  (_CNIED13 = 1)
#   define DISABLE_RD13_CN_INTERRUPT() (_CNIED13 = 0)

# else
#   define DISABLE_RD13_PULLUP() ((void) 0)
#   define DISABLE_RD13_PULLDOWN() ((void) 0)
#   define DISABLE_RD13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD13
#   define CONFIG_RD13_AS_ANALOG()       \
      do {                              \
        ENABLE_RD13_ANALOG();            \
        CONFIG_RD13_AS_INPUT();          \
        DISABLE_RD13_OPENDRAIN();        \
        DISABLE_RD13_PULLUP();           \
        DISABLE_RD13_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD14
#   define ENABLE_RD14_ANALOG()  (_ANSD14 = 1)
#   define DISABLE_RD14_ANALOG() (_ANSD14 = 0)
# else
#   define DISABLE_RD14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD14_AS_INPUT()  (_TRISD14 = 1)
# define CONFIG_RD14_AS_OUTPUT() (_TRISD14 = 0)

// Open-drain:
# if defined(_ODCD14)
#   define ENABLE_RD14_OPENDRAIN()  (_ODCD14 = 1)
#   define DISABLE_RD14_OPENDRAIN() (_ODCD14 = 0)
# else
#   define DISABLE_RD14_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED14
#   define ENABLE_RD14_PULLUP()  (_CNPUD14 = 1)
#   define DISABLE_RD14_PULLUP() (_CNPUD14 = 0)

#   define ENABLE_RD14_PULLDOWN()  (_CNPDD14 = 1)
#   define DISABLE_RD14_PULLDOWN() (_CNPDD14 = 0)

#   define ENABLE_RD14_CN_INTERRUPT()  (_CNIED14 = 1)
#   define DISABLE_RD14_CN_INTERRUPT() (_CNIED14 = 0)

# else
#   define DISABLE_RD14_PULLUP() ((void) 0)
#   define DISABLE_RD14_PULLDOWN() ((void) 0)
#   define DISABLE_RD14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD14
#   define CONFIG_RD14_AS_ANALOG()       \
      do {                              \
        ENABLE_RD14_ANALOG();            \
        CONFIG_RD14_AS_INPUT();          \
        DISABLE_RD14_OPENDRAIN();        \
        DISABLE_RD14_PULLUP();           \
        DISABLE_RD14_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSD15
#   define ENABLE_RD15_ANALOG()  (_ANSD15 = 1)
#   define DISABLE_RD15_ANALOG() (_ANSD15 = 0)
# else
#   define DISABLE_RD15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RD15_AS_INPUT()  (_TRISD15 = 1)
# define CONFIG_RD15_AS_OUTPUT() (_TRISD15 = 0)

// Open-drain:
# if defined(_ODCD15)
#   define ENABLE_RD15_OPENDRAIN()  (_ODCD15 = 1)
#   define DISABLE_RD15_OPENDRAIN() (_ODCD15 = 0)
# else
#   define DISABLE_RD15_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIED15
#   define ENABLE_RD15_PULLUP()  (_CNPUD15 = 1)
#   define DISABLE_RD15_PULLUP() (_CNPUD15 = 0)

#   define ENABLE_RD15_PULLDOWN()  (_CNPDD15 = 1)
#   define DISABLE_RD15_PULLDOWN() (_CNPDD15 = 0)

#   define ENABLE_RD15_CN_INTERRUPT()  (_CNIED15 = 1)
#   define DISABLE_RD15_CN_INTERRUPT() (_CNIED15 = 0)

# else
#   define DISABLE_RD15_PULLUP() ((void) 0)
#   define DISABLE_RD15_PULLDOWN() ((void) 0)
#   define DISABLE_RD15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSD15
#   define CONFIG_RD15_AS_ANALOG()       \
      do {                              \
        ENABLE_RD15_ANALOG();            \
        CONFIG_RD15_AS_INPUT();          \
        DISABLE_RD15_OPENDRAIN();        \
        DISABLE_RD15_PULLUP();           \
        DISABLE_RD15_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE0
#   define ENABLE_RE0_ANALOG()  (_ANSE0 = 1)
#   define DISABLE_RE0_ANALOG() (_ANSE0 = 0)
# else
#   define DISABLE_RE0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE0_AS_INPUT()  (_TRISE0 = 1)
# define CONFIG_RE0_AS_OUTPUT() (_TRISE0 = 0)

// Open-drain:
# if defined(_ODCE0)
#   define ENABLE_RE0_OPENDRAIN()  (_ODCE0 = 1)
#   define DISABLE_RE0_OPENDRAIN() (_ODCE0 = 0)
# else
#   define DISABLE_RE0_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE0
#   define ENABLE_RE0_PULLUP()  (_CNPUE0 = 1)
#   define DISABLE_RE0_PULLUP() (_CNPUE0 = 0)

#   define ENABLE_RE0_PULLDOWN()  (_CNPDE0 = 1)
#   define DISABLE_RE0_PULLDOWN() (_CNPDE0 = 0)

#   define ENABLE_RE0_CN_INTERRUPT()  (_CNIEE0 = 1)
#   define DISABLE_RE0_CN_INTERRUPT() (_CNIEE0 = 0)

# else
#   define DISABLE_RE0_PULLUP() ((void) 0)
#   define DISABLE_RE0_PULLDOWN() ((void) 0)
#   define DISABLE_RE0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE0
#   define CONFIG_RE0_AS_ANALOG()       \
      do {                              \
        ENABLE_RE0_ANALOG();            \
        CONFIG_RE0_AS_INPUT();          \
        DISABLE_RE0_OPENDRAIN();        \
        DISABLE_RE0_PULLUP();           \
        DISABLE_RE0_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE1
#   define ENABLE_RE1_ANALOG()  (_ANSE1 = 1)
#   define DISABLE_RE1_ANALOG() (_ANSE1 = 0)
# else
#   define DISABLE_RE1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE1_AS_INPUT()  (_TRISE1 = 1)
# define CONFIG_RE1_AS_OUTPUT() (_TRISE1 = 0)

// Open-drain:
# if defined(_ODCE1)
#   define ENABLE_RE1_OPENDRAIN()  (_ODCE1 = 1)
#   define DISABLE_RE1_OPENDRAIN() (_ODCE1 = 0)
# else
#   define DISABLE_RE1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE1
#   define ENABLE_RE1_PULLUP()  (_CNPUE1 = 1)
#   define DISABLE_RE1_PULLUP() (_CNPUE1 = 0)

#   define ENABLE_RE1_PULLDOWN()  (_CNPDE1 = 1)
#   define DISABLE_RE1_PULLDOWN() (_CNPDE1 = 0)

#   define ENABLE_RE1_CN_INTERRUPT()  (_CNIEE1 = 1)
#   define DISABLE_RE1_CN_INTERRUPT() (_CNIEE1 = 0)

# else
#   define DISABLE_RE1_PULLUP() ((void) 0)
#   define DISABLE_RE1_PULLDOWN() ((void) 0)
#   define DISABLE_RE1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE1
#   define CONFIG_RE1_AS_ANALOG()       \
      do {                              \
        ENABLE_RE1_ANALOG();            \
        CONFIG_RE1_AS_INPUT();          \
        DISABLE_RE1_OPENDRAIN();        \
        DISABLE_RE1_PULLUP();           \
        DISABLE_RE1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE2
#   define ENABLE_RE2_ANALOG()  (_ANSE2 = 1)
#   define DISABLE_RE2_ANALOG() (_ANSE2 = 0)
# else
#   define DISABLE_RE2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE2_AS_INPUT()  (_TRISE2 = 1)
# define CONFIG_RE2_AS_OUTPUT() (_TRISE2 = 0)

// Open-drain:
# if defined(_ODCE2)
#   define ENABLE_RE2_OPENDRAIN()  (_ODCE2 = 1)
#   define DISABLE_RE2_OPENDRAIN() (_ODCE2 = 0)
# else
#   define DISABLE_RE2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE2
#   define ENABLE_RE2_PULLUP()  (_CNPUE2 = 1)
#   define DISABLE_RE2_PULLUP() (_CNPUE2 = 0)

#   define ENABLE_RE2_PULLDOWN()  (_CNPDE2 = 1)
#   define DISABLE_RE2_PULLDOWN() (_CNPDE2 = 0)

#   define ENABLE_RE2_CN_INTERRUPT()  (_CNIEE2 = 1)
#   define DISABLE_RE2_CN_INTERRUPT() (_CNIEE2 = 0)

# else
#   define DISABLE_RE2_PULLUP() ((void) 0)
#   define DISABLE_RE2_PULLDOWN() ((void) 0)
#   define DISABLE_RE2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE2
#   define CONFIG_RE2_AS_ANALOG()       \
      do {                              \
        ENABLE_RE2_ANALOG();            \
        CONFIG_RE2_AS_INPUT();          \
        DISABLE_RE2_OPENDRAIN();        \
        DISABLE_RE2_PULLUP();           \
        DISABLE_RE2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE3
#   define ENABLE_RE3_ANALOG()  (_ANSE3 = 1)
#   define DISABLE_RE3_ANALOG() (_ANSE3 = 0)
# else
#   define DISABLE_RE3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE3_AS_INPUT()  (_TRISE3 = 1)
# define CONFIG_RE3_AS_OUTPUT() (_TRISE3 = 0)

// Open-drain:
# if defined(_ODCE3)
#   define ENABLE_RE3_OPENDRAIN()  (_ODCE3 = 1)
#   define DISABLE_RE3_OPENDRAIN() (_ODCE3 = 0)
# else
#   define DISABLE_RE3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE3
#   define ENABLE_RE3_PULLUP()  (_CNPUE3 = 1)
#   define DISABLE_RE3_PULLUP() (_CNPUE3 = 0)

#   define ENABLE_RE3_PULLDOWN()  (_CNPDE3 = 1)
#   define DISABLE_RE3_PULLDOWN() (_CNPDE3 = 0)

#   define ENABLE_RE3_CN_INTERRUPT()  (_CNIEE3 = 1)
#   define DISABLE_RE3_CN_INTERRUPT() (_CNIEE3 = 0)

# else
#   define DISABLE_RE3_PULLUP() ((void) 0)
#   define DISABLE_RE3_PULLDOWN() ((void) 0)
#   define DISABLE_RE3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE3
#   define CONFIG_RE3_AS_ANALOG()       \
      do {                              \
        ENABLE_RE3_ANALOG();            \
        CONFIG_RE3_AS_INPUT();          \
        DISABLE_RE3_OPENDRAIN();        \
        DISABLE_RE3_PULLUP();           \
        DISABLE_RE3_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE4
#   define ENABLE_RE4_ANALOG()  (_ANSE4 = 1)
#   define DISABLE_RE4_ANALOG() (_ANSE4 = 0)
# else
#   define DISABLE_RE4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE4_AS_INPUT()  (_TRISE4 = 1)
# define CONFIG_RE4_AS_OUTPUT() (_TRISE4 = 0)

// Open-drain:
# if defined(_ODCE4)
#   define ENABLE_RE4_OPENDRAIN()  (_ODCE4 = 1)
#   define DISABLE_RE4_OPENDRAIN() (_ODCE4 = 0)
# else
#   define DISABLE_RE4_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE4
#   define ENABLE_RE4_PULLUP()  (_CNPUE4 = 1)
#   define DISABLE_RE4_PULLUP() (_CNPUE4 = 0)

#   define ENABLE_RE4_PULLDOWN()  (_CNPDE4 = 1)
#   define DISABLE_RE4_PULLDOWN() (_CNPDE4 = 0)

#   define ENABLE_RE4_CN_INTERRUPT()  (_CNIEE4 = 1)
#   define DISABLE_RE4_CN_INTERRUPT() (_CNIEE4 = 0)

# else
#   define DISABLE_RE4_PULLUP() ((void) 0)
#   define DISABLE_RE4_PULLDOWN() ((void) 0)
#   define DISABLE_RE4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE4
#   define CONFIG_RE4_AS_ANALOG()       \
      do {                              \
        ENABLE_RE4_ANALOG();            \
        CONFIG_RE4_AS_INPUT();          \
        DISABLE_RE4_OPENDRAIN();        \
        DISABLE_RE4_PULLUP();           \
        DISABLE_RE4_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE5
#   define ENABLE_RE5_ANALOG()  (_ANSE5 = 1)
#   define DISABLE_RE5_ANALOG() (_ANSE5 = 0)
# else
#   define DISABLE_RE5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE5_AS_INPUT()  (_TRISE5 = 1)
# define CONFIG_RE5_AS_OUTPUT() (_TRISE5 = 0)

// Open-drain:
# if defined(_ODCE5)
#   define ENABLE_RE5_OPENDRAIN()  (_ODCE5 = 1)
#   define DISABLE_RE5_OPENDRAIN() (_ODCE5 = 0)
# else
#   define DISABLE_RE5_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE5
#   define ENABLE_RE5_PULLUP()  (_CNPUE5 = 1)
#   define DISABLE_RE5_PULLUP() (_CNPUE5 = 0)

#   define ENABLE_RE5_PULLDOWN()  (_CNPDE5 = 1)
#   define DISABLE_RE5_PULLDOWN() (_CNPDE5 = 0)

#   define ENABLE_RE5_CN_INTERRUPT()  (_CNIEE5 = 1)
#   define DISABLE_RE5_CN_INTERRUPT() (_CNIEE5 = 0)

# else
#   define DISABLE_RE5_PULLUP() ((void) 0)
#   define DISABLE_RE5_PULLDOWN() ((void) 0)
#   define DISABLE_RE5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE5
#   define CONFIG_RE5_AS_ANALOG()       \
      do {                              \
        ENABLE_RE5_ANALOG();            \
        CONFIG_RE5_AS_INPUT();          \
        DISABLE_RE5_OPENDRAIN();        \
        DISABLE_RE5_PULLUP();           \
        DISABLE_RE5_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE6
#   define ENABLE_RE6_ANALOG()  (_ANSE6 = 1)
#   define DISABLE_RE6_ANALOG() (_ANSE6 = 0)
# else
#   define DISABLE_RE6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE6_AS_INPUT()  (_TRISE6 = 1)
# define CONFIG_RE6_AS_OUTPUT() (_TRISE6 = 0)

// Open-drain:
# if defined(_ODCE6)
#   define ENABLE_RE6_OPENDRAIN()  (_ODCE6 = 1)
#   define DISABLE_RE6_OPENDRAIN() (_ODCE6 = 0)
# else
#   define DISABLE_RE6_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE6
#   define ENABLE_RE6_PULLUP()  (_CNPUE6 = 1)
#   define DISABLE_RE6_PULLUP() (_CNPUE6 = 0)

#   define ENABLE_RE6_PULLDOWN()  (_CNPDE6 = 1)
#   define DISABLE_RE6_PULLDOWN() (_CNPDE6 = 0)

#   define ENABLE_RE6_CN_INTERRUPT()  (_CNIEE6 = 1)
#   define DISABLE_RE6_CN_INTERRUPT() (_CNIEE6 = 0)

# else
#   define DISABLE_RE6_PULLUP() ((void) 0)
#   define DISABLE_RE6_PULLDOWN() ((void) 0)
#   define DISABLE_RE6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE6
#   define CONFIG_RE6_AS_ANALOG()       \
      do {                              \
        ENABLE_RE6_ANALOG();            \
        CONFIG_RE6_AS_INPUT();          \
        DISABLE_RE6_OPENDRAIN();        \
        DISABLE_RE6_PULLUP();           \
        DISABLE_RE6_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE7
#   define ENABLE_RE7_ANALOG()  (_ANSE7 = 1)
#   define DISABLE_RE7_ANALOG() (_ANSE7 = 0)
# else
#   define DISABLE_RE7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE7_AS_INPUT()  (_TRISE7 = 1)
# define CONFIG_RE7_AS_OUTPUT() (_TRISE7 = 0)

// Open-drain:
# if defined(_ODCE7)
#   define ENABLE_RE7_OPENDRAIN()  (_ODCE7 = 1)
#   define DISABLE_RE7_OPENDRAIN() (_ODCE7 = 0)
# else
#   define DISABLE_RE7_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE7
#   define ENABLE_RE7_PULLUP()  (_CNPUE7 = 1)
#   define DISABLE_RE7_PULLUP() (_CNPUE7 = 0)

#   define ENABLE_RE7_PULLDOWN()  (_CNPDE7 = 1)
#   define DISABLE_RE7_PULLDOWN() (_CNPDE7 = 0)

#   define ENABLE_RE7_CN_INTERRUPT()  (_CNIEE7 = 1)
#   define DISABLE_RE7_CN_INTERRUPT() (_CNIEE7 = 0)

# else
#   define DISABLE_RE7_PULLUP() ((void) 0)
#   define DISABLE_RE7_PULLDOWN() ((void) 0)
#   define DISABLE_RE7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE7
#   define CONFIG_RE7_AS_ANALOG()       \
      do {                              \
        ENABLE_RE7_ANALOG();            \
        CONFIG_RE7_AS_INPUT();          \
        DISABLE_RE7_OPENDRAIN();        \
        DISABLE_RE7_PULLUP();           \
        DISABLE_RE7_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE8
#   define ENABLE_RE8_ANALOG()  (_ANSE8 = 1)
#   define DISABLE_RE8_ANALOG() (_ANSE8 = 0)
# else
#   define DISABLE_RE8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE8_AS_INPUT()  (_TRISE8 = 1)
# define CONFIG_RE8_AS_OUTPUT() (_TRISE8 = 0)

// Open-drain:
# if defined(_ODCE8)
#   define ENABLE_RE8_OPENDRAIN()  (_ODCE8 = 1)
#   define DISABLE_RE8_OPENDRAIN() (_ODCE8 = 0)
# else
#   define DISABLE_RE8_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE8
#   define ENABLE_RE8_PULLUP()  (_CNPUE8 = 1)
#   define DISABLE_RE8_PULLUP() (_CNPUE8 = 0)

#   define ENABLE_RE8_PULLDOWN()  (_CNPDE8 = 1)
#   define DISABLE_RE8_PULLDOWN() (_CNPDE8 = 0)

#   define ENABLE_RE8_CN_INTERRUPT()  (_CNIEE8 = 1)
#   define DISABLE_RE8_CN_INTERRUPT() (_CNIEE8 = 0)

# else
#   define DISABLE_RE8_PULLUP() ((void) 0)
#   define DISABLE_RE8_PULLDOWN() ((void) 0)
#   define DISABLE_RE8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE8
#   define CONFIG_RE8_AS_ANALOG()       \
      do {                              \
        ENABLE_RE8_ANALOG();            \
        CONFIG_RE8_AS_INPUT();          \
        DISABLE_RE8_OPENDRAIN();        \
        DISABLE_RE8_PULLUP();           \
        DISABLE_RE8_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE9
#   define ENABLE_RE9_ANALOG()  (_ANSE9 = 1)
#   define DISABLE_RE9_ANALOG() (_ANSE9 = 0)
# else
#   define DISABLE_RE9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE9_AS_INPUT()  (_TRISE9 = 1)
# define CONFIG_RE9_AS_OUTPUT() (_TRISE9 = 0)

// Open-drain:
# if defined(_ODCE9)
#   define ENABLE_RE9_OPENDRAIN()  (_ODCE9 = 1)
#   define DISABLE_RE9_OPENDRAIN() (_ODCE9 = 0)
# else
#   define DISABLE_RE9_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE9
#   define ENABLE_RE9_PULLUP()  (_CNPUE9 = 1)
#   define DISABLE_RE9_PULLUP() (_CNPUE9 = 0)

#   define ENABLE_RE9_PULLDOWN()  (_CNPDE9 = 1)
#   define DISABLE_RE9_PULLDOWN() (_CNPDE9 = 0)

#   define ENABLE_RE9_CN_INTERRUPT()  (_CNIEE9 = 1)
#   define DISABLE_RE9_CN_INTERRUPT() (_CNIEE9 = 0)

# else
#   define DISABLE_RE9_PULLUP() ((void) 0)
#   define DISABLE_RE9_PULLDOWN() ((void) 0)
#   define DISABLE_RE9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE9
#   define CONFIG_RE9_AS_ANALOG()       \
      do {                              \
        ENABLE_RE9_ANALOG();            \
        CONFIG_RE9_AS_INPUT();          \
        DISABLE_RE9_OPENDRAIN();        \
        DISABLE_RE9_PULLUP();           \
        DISABLE_RE9_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE10
#   define ENABLE_RE10_ANALOG()  (_ANSE10 = 1)
#   define DISABLE_RE10_ANALOG() (_ANSE10 = 0)
# else
#   define DISABLE_RE10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE10_AS_INPUT()  (_TRISE10 = 1)
# define CONFIG_RE10_AS_OUTPUT() (_TRISE10 = 0)

// Open-drain:
# if defined(_ODCE10)
#   define ENABLE_RE10_OPENDRAIN()  (_ODCE10 = 1)
#   define DISABLE_RE10_OPENDRAIN() (_ODCE10 = 0)
# else
#   define DISABLE_RE10_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE10
#   define ENABLE_RE10_PULLUP()  (_CNPUE10 = 1)
#   define DISABLE_RE10_PULLUP() (_CNPUE10 = 0)

#   define ENABLE_RE10_PULLDOWN()  (_CNPDE10 = 1)
#   define DISABLE_RE10_PULLDOWN() (_CNPDE10 = 0)

#   define ENABLE_RE10_CN_INTERRUPT()  (_CNIEE10 = 1)
#   define DISABLE_RE10_CN_INTERRUPT() (_CNIEE10 = 0)

# else
#   define DISABLE_RE10_PULLUP() ((void) 0)
#   define DISABLE_RE10_PULLDOWN() ((void) 0)
#   define DISABLE_RE10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE10
#   define CONFIG_RE10_AS_ANALOG()       \
      do {                              \
        ENABLE_RE10_ANALOG();            \
        CONFIG_RE10_AS_INPUT();          \
        DISABLE_RE10_OPENDRAIN();        \
        DISABLE_RE10_PULLUP();           \
        DISABLE_RE10_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE11
#   define ENABLE_RE11_ANALOG()  (_ANSE11 = 1)
#   define DISABLE_RE11_ANALOG() (_ANSE11 = 0)
# else
#   define DISABLE_RE11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE11_AS_INPUT()  (_TRISE11 = 1)
# define CONFIG_RE11_AS_OUTPUT() (_TRISE11 = 0)

// Open-drain:
# if defined(_ODCE11)
#   define ENABLE_RE11_OPENDRAIN()  (_ODCE11 = 1)
#   define DISABLE_RE11_OPENDRAIN() (_ODCE11 = 0)
# else
#   define DISABLE_RE11_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE11
#   define ENABLE_RE11_PULLUP()  (_CNPUE11 = 1)
#   define DISABLE_RE11_PULLUP() (_CNPUE11 = 0)

#   define ENABLE_RE11_PULLDOWN()  (_CNPDE11 = 1)
#   define DISABLE_RE11_PULLDOWN() (_CNPDE11 = 0)

#   define ENABLE_RE11_CN_INTERRUPT()  (_CNIEE11 = 1)
#   define DISABLE_RE11_CN_INTERRUPT() (_CNIEE11 = 0)

# else
#   define DISABLE_RE11_PULLUP() ((void) 0)
#   define DISABLE_RE11_PULLDOWN() ((void) 0)
#   define DISABLE_RE11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE11
#   define CONFIG_RE11_AS_ANALOG()       \
      do {                              \
        ENABLE_RE11_ANALOG();            \
        CONFIG_RE11_AS_INPUT();          \
        DISABLE_RE11_OPENDRAIN();        \
        DISABLE_RE11_PULLUP();           \
        DISABLE_RE11_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE12
#   define ENABLE_RE12_ANALOG()  (_ANSE12 = 1)
#   define DISABLE_RE12_ANALOG() (_ANSE12 = 0)
# else
#   define DISABLE_RE12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE12_AS_INPUT()  (_TRISE12 = 1)
# define CONFIG_RE12_AS_OUTPUT() (_TRISE12 = 0)

// Open-drain:
# if defined(_ODCE12)
#   define ENABLE_RE12_OPENDRAIN()  (_ODCE12 = 1)
#   define DISABLE_RE12_OPENDRAIN() (_ODCE12 = 0)
# else
#   define DISABLE_RE12_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE12
#   define ENABLE_RE12_PULLUP()  (_CNPUE12 = 1)
#   define DISABLE_RE12_PULLUP() (_CNPUE12 = 0)

#   define ENABLE_RE12_PULLDOWN()  (_CNPDE12 = 1)
#   define DISABLE_RE12_PULLDOWN() (_CNPDE12 = 0)

#   define ENABLE_RE12_CN_INTERRUPT()  (_CNIEE12 = 1)
#   define DISABLE_RE12_CN_INTERRUPT() (_CNIEE12 = 0)

# else
#   define DISABLE_RE12_PULLUP() ((void) 0)
#   define DISABLE_RE12_PULLDOWN() ((void) 0)
#   define DISABLE_RE12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE12
#   define CONFIG_RE12_AS_ANALOG()       \
      do {                              \
        ENABLE_RE12_ANALOG();            \
        CONFIG_RE12_AS_INPUT();          \
        DISABLE_RE12_OPENDRAIN();        \
        DISABLE_RE12_PULLUP();           \
        DISABLE_RE12_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE13
#   define ENABLE_RE13_ANALOG()  (_ANSE13 = 1)
#   define DISABLE_RE13_ANALOG() (_ANSE13 = 0)
# else
#   define DISABLE_RE13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE13_AS_INPUT()  (_TRISE13 = 1)
# define CONFIG_RE13_AS_OUTPUT() (_TRISE13 = 0)

// Open-drain:
# if defined(_ODCE13)
#   define ENABLE_RE13_OPENDRAIN()  (_ODCE13 = 1)
#   define DISABLE_RE13_OPENDRAIN() (_ODCE13 = 0)
# else
#   define DISABLE_RE13_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE13
#   define ENABLE_RE13_PULLUP()  (_CNPUE13 = 1)
#   define DISABLE_RE13_PULLUP() (_CNPUE13 = 0)

#   define ENABLE_RE13_PULLDOWN()  (_CNPDE13 = 1)
#   define DISABLE_RE13_PULLDOWN() (_CNPDE13 = 0)

#   define ENABLE_RE13_CN_INTERRUPT()  (_CNIEE13 = 1)
#   define DISABLE_RE13_CN_INTERRUPT() (_CNIEE13 = 0)

# else
#   define DISABLE_RE13_PULLUP() ((void) 0)
#   define DISABLE_RE13_PULLDOWN() ((void) 0)
#   define DISABLE_RE13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE13
#   define CONFIG_RE13_AS_ANALOG()       \
      do {                              \
        ENABLE_RE13_ANALOG();            \
        CONFIG_RE13_AS_INPUT();          \
        DISABLE_RE13_OPENDRAIN();        \
        DISABLE_RE13_PULLUP();           \
        DISABLE_RE13_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE14
#   define ENABLE_RE14_ANALOG()  (_ANSE14 = 1)
#   define DISABLE_RE14_ANALOG() (_ANSE14 = 0)
# else
#   define DISABLE_RE14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE14_AS_INPUT()  (_TRISE14 = 1)
# define CONFIG_RE14_AS_OUTPUT() (_TRISE14 = 0)

// Open-drain:
# if defined(_ODCE14)
#   define ENABLE_RE14_OPENDRAIN()  (_ODCE14 = 1)
#   define DISABLE_RE14_OPENDRAIN() (_ODCE14 = 0)
# else
#   define DISABLE_RE14_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE14
#   define ENABLE_RE14_PULLUP()  (_CNPUE14 = 1)
#   define DISABLE_RE14_PULLUP() (_CNPUE14 = 0)

#   define ENABLE_RE14_PULLDOWN()  (_CNPDE14 = 1)
#   define DISABLE_RE14_PULLDOWN() (_CNPDE14 = 0)

#   define ENABLE_RE14_CN_INTERRUPT()  (_CNIEE14 = 1)
#   define DISABLE_RE14_CN_INTERRUPT() (_CNIEE14 = 0)

# else
#   define DISABLE_RE14_PULLUP() ((void) 0)
#   define DISABLE_RE14_PULLDOWN() ((void) 0)
#   define DISABLE_RE14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE14
#   define CONFIG_RE14_AS_ANALOG()       \
      do {                              \
        ENABLE_RE14_ANALOG();            \
        CONFIG_RE14_AS_INPUT();          \
        DISABLE_RE14_OPENDRAIN();        \
        DISABLE_RE14_PULLUP();           \
        DISABLE_RE14_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSE15
#   define ENABLE_RE15_ANALOG()  (_ANSE15 = 1)
#   define DISABLE_RE15_ANALOG() (_ANSE15 = 0)
# else
#   define DISABLE_RE15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RE15_AS_INPUT()  (_TRISE15 = 1)
# define CONFIG_RE15_AS_OUTPUT() (_TRISE15 = 0)

// Open-drain:
# if defined(_ODCE15)
#   define ENABLE_RE15_OPENDRAIN()  (_ODCE15 = 1)
#   define DISABLE_RE15_OPENDRAIN() (_ODCE15 = 0)
# else
#   define DISABLE_RE15_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEE15
#   define ENABLE_RE15_PULLUP()  (_CNPUE15 = 1)
#   define DISABLE_RE15_PULLUP() (_CNPUE15 = 0)

#   define ENABLE_RE15_PULLDOWN()  (_CNPDE15 = 1)
#   define DISABLE_RE15_PULLDOWN() (_CNPDE15 = 0)

#   define ENABLE_RE15_CN_INTERRUPT()  (_CNIEE15 = 1)
#   define DISABLE_RE15_CN_INTERRUPT() (_CNIEE15 = 0)

# else
#   define DISABLE_RE15_PULLUP() ((void) 0)
#   define DISABLE_RE15_PULLDOWN() ((void) 0)
#   define DISABLE_RE15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSE15
#   define CONFIG_RE15_AS_ANALOG()       \
      do {                              \
        ENABLE_RE15_ANALOG();            \
        CONFIG_RE15_AS_INPUT();          \
        DISABLE_RE15_OPENDRAIN();        \
        DISABLE_RE15_PULLUP();           \
        DISABLE_RE15_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF0
#   define ENABLE_RF0_ANALOG()  (_ANSF0 = 1)
#   define DISABLE_RF0_ANALOG() (_ANSF0 = 0)
# else
#   define DISABLE_RF0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF0_AS_INPUT()  (_TRISF0 = 1)
# define CONFIG_RF0_AS_OUTPUT() (_TRISF0 = 0)

// Open-drain:
# if defined(_ODCF0)
#   define ENABLE_RF0_OPENDRAIN()  (_ODCF0 = 1)
#   define DISABLE_RF0_OPENDRAIN() (_ODCF0 = 0)
# else
#   define DISABLE_RF0_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF0
#   define ENABLE_RF0_PULLUP()  (_CNPUF0 = 1)
#   define DISABLE_RF0_PULLUP() (_CNPUF0 = 0)

#   define ENABLE_RF0_PULLDOWN()  (_CNPDF0 = 1)
#   define DISABLE_RF0_PULLDOWN() (_CNPDF0 = 0)

#   define ENABLE_RF0_CN_INTERRUPT()  (_CNIEF0 = 1)
#   define DISABLE_RF0_CN_INTERRUPT() (_CNIEF0 = 0)

# else
#   define DISABLE_RF0_PULLUP() ((void) 0)
#   define DISABLE_RF0_PULLDOWN() ((void) 0)
#   define DISABLE_RF0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF0
#   define CONFIG_RF0_AS_ANALOG()       \
      do {                              \
        ENABLE_RF0_ANALOG();            \
        CONFIG_RF0_AS_INPUT();          \
        DISABLE_RF0_OPENDRAIN();        \
        DISABLE_RF0_PULLUP();           \
        DISABLE_RF0_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF1
#   define ENABLE_RF1_ANALOG()  (_ANSF1 = 1)
#   define DISABLE_RF1_ANALOG() (_ANSF1 = 0)
# else
#   define DISABLE_RF1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF1_AS_INPUT()  (_TRISF1 = 1)
# define CONFIG_RF1_AS_OUTPUT() (_TRISF1 = 0)

// Open-drain:
# if defined(_ODCF1)
#   define ENABLE_RF1_OPENDRAIN()  (_ODCF1 = 1)
#   define DISABLE_RF1_OPENDRAIN() (_ODCF1 = 0)
# else
#   define DISABLE_RF1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF1
#   define ENABLE_RF1_PULLUP()  (_CNPUF1 = 1)
#   define DISABLE_RF1_PULLUP() (_CNPUF1 = 0)

#   define ENABLE_RF1_PULLDOWN()  (_CNPDF1 = 1)
#   define DISABLE_RF1_PULLDOWN() (_CNPDF1 = 0)

#   define ENABLE_RF1_CN_INTERRUPT()  (_CNIEF1 = 1)
#   define DISABLE_RF1_CN_INTERRUPT() (_CNIEF1 = 0)

# else
#   define DISABLE_RF1_PULLUP() ((void) 0)
#   define DISABLE_RF1_PULLDOWN() ((void) 0)
#   define DISABLE_RF1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF1
#   define CONFIG_RF1_AS_ANALOG()       \
      do {                              \
        ENABLE_RF1_ANALOG();            \
        CONFIG_RF1_AS_INPUT();          \
        DISABLE_RF1_OPENDRAIN();        \
        DISABLE_RF1_PULLUP();           \
        DISABLE_RF1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF2
#   define ENABLE_RF2_ANALOG()  (_ANSF2 = 1)
#   define DISABLE_RF2_ANALOG() (_ANSF2 = 0)
# else
#   define DISABLE_RF2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF2_AS_INPUT()  (_TRISF2 = 1)
# define CONFIG_RF2_AS_OUTPUT() (_TRISF2 = 0)

// Open-drain:
# if defined(_ODCF2)
#   define ENABLE_RF2_OPENDRAIN()  (_ODCF2 = 1)
#   define DISABLE_RF2_OPENDRAIN() (_ODCF2 = 0)
# else
#   define DISABLE_RF2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF2
#   define ENABLE_RF2_PULLUP()  (_CNPUF2 = 1)
#   define DISABLE_RF2_PULLUP() (_CNPUF2 = 0)

#   define ENABLE_RF2_PULLDOWN()  (_CNPDF2 = 1)
#   define DISABLE_RF2_PULLDOWN() (_CNPDF2 = 0)

#   define ENABLE_RF2_CN_INTERRUPT()  (_CNIEF2 = 1)
#   define DISABLE_RF2_CN_INTERRUPT() (_CNIEF2 = 0)

# else
#   define DISABLE_RF2_PULLUP() ((void) 0)
#   define DISABLE_RF2_PULLDOWN() ((void) 0)
#   define DISABLE_RF2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF2
#   define CONFIG_RF2_AS_ANALOG()       \
      do {                              \
        ENABLE_RF2_ANALOG();            \
        CONFIG_RF2_AS_INPUT();          \
        DISABLE_RF2_OPENDRAIN();        \
        DISABLE_RF2_PULLUP();           \
        DISABLE_RF2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF3
#   define ENABLE_RF3_ANALOG()  (_ANSF3 = 1)
#   define DISABLE_RF3_ANALOG() (_ANSF3 = 0)
# else
#   define DISABLE_RF3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF3_AS_INPUT()  (_TRISF3 = 1)
# define CONFIG_RF3_AS_OUTPUT() (_TRISF3 = 0)

// Open-drain:
# if defined(_ODCF3)
#   define ENABLE_RF3_OPENDRAIN()  (_ODCF3 = 1)
#   define DISABLE_RF3_OPENDRAIN() (_ODCF3 = 0)
# else
#   define DISABLE_RF3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF3
#   define ENABLE_RF3_PULLUP()  (_CNPUF3 = 1)
#   define DISABLE_RF3_PULLUP() (_CNPUF3 = 0)

#   define ENABLE_RF3_PULLDOWN()  (_CNPDF3 = 1)
#   define DISABLE_RF3_PULLDOWN() (_CNPDF3 = 0)

#   define ENABLE_RF3_CN_INTERRUPT()  (_CNIEF3 = 1)
#   define DISABLE_RF3_CN_INTERRUPT() (_CNIEF3 = 0)

# else
#   define DISABLE_RF3_PULLUP() ((void) 0)
#   define DISABLE_RF3_PULLDOWN() ((void) 0)
#   define DISABLE_RF3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF3
#   define CONFIG_RF3_AS_ANALOG()       \
      do {                              \
        ENABLE_RF3_ANALOG();            \
        CONFIG_RF3_AS_INPUT();          \
        DISABLE_RF3_OPENDRAIN();        \
        DISABLE_RF3_PULLUP();           \
        DISABLE_RF3_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF4
#   define ENABLE_RF4_ANALOG()  (_ANSF4 = 1)
#   define DISABLE_RF4_ANALOG() (_ANSF4 = 0)
# else
#   define DISABLE_RF4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF4_AS_INPUT()  (_TRISF4 = 1)
# define CONFIG_RF4_AS_OUTPUT() (_TRISF4 = 0)

// Open-drain:
# if defined(_ODCF4)
#   define ENABLE_RF4_OPENDRAIN()  (_ODCF4 = 1)
#   define DISABLE_RF4_OPENDRAIN() (_ODCF4 = 0)
# else
#   define DISABLE_RF4_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF4
#   define ENABLE_RF4_PULLUP()  (_CNPUF4 = 1)
#   define DISABLE_RF4_PULLUP() (_CNPUF4 = 0)

#   define ENABLE_RF4_PULLDOWN()  (_CNPDF4 = 1)
#   define DISABLE_RF4_PULLDOWN() (_CNPDF4 = 0)

#   define ENABLE_RF4_CN_INTERRUPT()  (_CNIEF4 = 1)
#   define DISABLE_RF4_CN_INTERRUPT() (_CNIEF4 = 0)

# else
#   define DISABLE_RF4_PULLUP() ((void) 0)
#   define DISABLE_RF4_PULLDOWN() ((void) 0)
#   define DISABLE_RF4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF4
#   define CONFIG_RF4_AS_ANALOG()       \
      do {                              \
        ENABLE_RF4_ANALOG();            \
        CONFIG_RF4_AS_INPUT();          \
        DISABLE_RF4_OPENDRAIN();        \
        DISABLE_RF4_PULLUP();           \
        DISABLE_RF4_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF5
#   define ENABLE_RF5_ANALOG()  (_ANSF5 = 1)
#   define DISABLE_RF5_ANALOG() (_ANSF5 = 0)
# else
#   define DISABLE_RF5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF5_AS_INPUT()  (_TRISF5 = 1)
# define CONFIG_RF5_AS_OUTPUT() (_TRISF5 = 0)

// Open-drain:
# if defined(_ODCF5)
#   define ENABLE_RF5_OPENDRAIN()  (_ODCF5 = 1)
#   define DISABLE_RF5_OPENDRAIN() (_ODCF5 = 0)
# else
#   define DISABLE_RF5_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF5
#   define ENABLE_RF5_PULLUP()  (_CNPUF5 = 1)
#   define DISABLE_RF5_PULLUP() (_CNPUF5 = 0)

#   define ENABLE_RF5_PULLDOWN()  (_CNPDF5 = 1)
#   define DISABLE_RF5_PULLDOWN() (_CNPDF5 = 0)

#   define ENABLE_RF5_CN_INTERRUPT()  (_CNIEF5 = 1)
#   define DISABLE_RF5_CN_INTERRUPT() (_CNIEF5 = 0)

# else
#   define DISABLE_RF5_PULLUP() ((void) 0)
#   define DISABLE_RF5_PULLDOWN() ((void) 0)
#   define DISABLE_RF5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF5
#   define CONFIG_RF5_AS_ANALOG()       \
      do {                              \
        ENABLE_RF5_ANALOG();            \
        CONFIG_RF5_AS_INPUT();          \
        DISABLE_RF5_OPENDRAIN();        \
        DISABLE_RF5_PULLUP();           \
        DISABLE_RF5_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF6
#   define ENABLE_RF6_ANALOG()  (_ANSF6 = 1)
#   define DISABLE_RF6_ANALOG() (_ANSF6 = 0)
# else
#   define DISABLE_RF6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF6_AS_INPUT()  (_TRISF6 = 1)
# define CONFIG_RF6_AS_OUTPUT() (_TRISF6 = 0)

// Open-drain:
# if defined(_ODCF6)
#   define ENABLE_RF6_OPENDRAIN()  (_ODCF6 = 1)
#   define DISABLE_RF6_OPENDRAIN() (_ODCF6 = 0)
# else
#   define DISABLE_RF6_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF6
#   define ENABLE_RF6_PULLUP()  (_CNPUF6 = 1)
#   define DISABLE_RF6_PULLUP() (_CNPUF6 = 0)

#   define ENABLE_RF6_PULLDOWN()  (_CNPDF6 = 1)
#   define DISABLE_RF6_PULLDOWN() (_CNPDF6 = 0)

#   define ENABLE_RF6_CN_INTERRUPT()  (_CNIEF6 = 1)
#   define DISABLE_RF6_CN_INTERRUPT() (_CNIEF6 = 0)

# else
#   define DISABLE_RF6_PULLUP() ((void) 0)
#   define DISABLE_RF6_PULLDOWN() ((void) 0)
#   define DISABLE_RF6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF6
#   define CONFIG_RF6_AS_ANALOG()       \
      do {                              \
        ENABLE_RF6_ANALOG();            \
        CONFIG_RF6_AS_INPUT();          \
        DISABLE_RF6_OPENDRAIN();        \
        DISABLE_RF6_PULLUP();           \
        DISABLE_RF6_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF7
#   define ENABLE_RF7_ANALOG()  (_ANSF7 = 1)
#   define DISABLE_RF7_ANALOG() (_ANSF7 = 0)
# else
#   define DISABLE_RF7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF7_AS_INPUT()  (_TRISF7 = 1)
# define CONFIG_RF7_AS_OUTPUT() (_TRISF7 = 0)

// Open-drain:
# if defined(_ODCF7)
#   define ENABLE_RF7_OPENDRAIN()  (_ODCF7 = 1)
#   define DISABLE_RF7_OPENDRAIN() (_ODCF7 = 0)
# else
#   define DISABLE_RF7_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF7
#   define ENABLE_RF7_PULLUP()  (_CNPUF7 = 1)
#   define DISABLE_RF7_PULLUP() (_CNPUF7 = 0)

#   define ENABLE_RF7_PULLDOWN()  (_CNPDF7 = 1)
#   define DISABLE_RF7_PULLDOWN() (_CNPDF7 = 0)

#   define ENABLE_RF7_CN_INTERRUPT()  (_CNIEF7 = 1)
#   define DISABLE_RF7_CN_INTERRUPT() (_CNIEF7 = 0)

# else
#   define DISABLE_RF7_PULLUP() ((void) 0)
#   define DISABLE_RF7_PULLDOWN() ((void) 0)
#   define DISABLE_RF7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF7
#   define CONFIG_RF7_AS_ANALOG()       \
      do {                              \
        ENABLE_RF7_ANALOG();            \
        CONFIG_RF7_AS_INPUT();          \
        DISABLE_RF7_OPENDRAIN();        \
        DISABLE_RF7_PULLUP();           \
        DISABLE_RF7_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF8
#   define ENABLE_RF8_ANALOG()  (_ANSF8 = 1)
#   define DISABLE_RF8_ANALOG() (_ANSF8 = 0)
# else
#   define DISABLE_RF8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF8_AS_INPUT()  (_TRISF8 = 1)
# define CONFIG_RF8_AS_OUTPUT() (_TRISF8 = 0)

// Open-drain:
# if defined(_ODCF8)
#   define ENABLE_RF8_OPENDRAIN()  (_ODCF8 = 1)
#   define DISABLE_RF8_OPENDRAIN() (_ODCF8 = 0)
# else
#   define DISABLE_RF8_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF8
#   define ENABLE_RF8_PULLUP()  (_CNPUF8 = 1)
#   define DISABLE_RF8_PULLUP() (_CNPUF8 = 0)

#   define ENABLE_RF8_PULLDOWN()  (_CNPDF8 = 1)
#   define DISABLE_RF8_PULLDOWN() (_CNPDF8 = 0)

#   define ENABLE_RF8_CN_INTERRUPT()  (_CNIEF8 = 1)
#   define DISABLE_RF8_CN_INTERRUPT() (_CNIEF8 = 0)

# else
#   define DISABLE_RF8_PULLUP() ((void) 0)
#   define DISABLE_RF8_PULLDOWN() ((void) 0)
#   define DISABLE_RF8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF8
#   define CONFIG_RF8_AS_ANALOG()       \
      do {                              \
        ENABLE_RF8_ANALOG();            \
        CONFIG_RF8_AS_INPUT();          \
        DISABLE_RF8_OPENDRAIN();        \
        DISABLE_RF8_PULLUP();           \
        DISABLE_RF8_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF9
#   define ENABLE_RF9_ANALOG()  (_ANSF9 = 1)
#   define DISABLE_RF9_ANALOG() (_ANSF9 = 0)
# else
#   define DISABLE_RF9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF9_AS_INPUT()  (_TRISF9 = 1)
# define CONFIG_RF9_AS_OUTPUT() (_TRISF9 = 0)

// Open-drain:
# if defined(_ODCF9)
#   define ENABLE_RF9_OPENDRAIN()  (_ODCF9 = 1)
#   define DISABLE_RF9_OPENDRAIN() (_ODCF9 = 0)
# else
#   define DISABLE_RF9_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF9
#   define ENABLE_RF9_PULLUP()  (_CNPUF9 = 1)
#   define DISABLE_RF9_PULLUP() (_CNPUF9 = 0)

#   define ENABLE_RF9_PULLDOWN()  (_CNPDF9 = 1)
#   define DISABLE_RF9_PULLDOWN() (_CNPDF9 = 0)

#   define ENABLE_RF9_CN_INTERRUPT()  (_CNIEF9 = 1)
#   define DISABLE_RF9_CN_INTERRUPT() (_CNIEF9 = 0)

# else
#   define DISABLE_RF9_PULLUP() ((void) 0)
#   define DISABLE_RF9_PULLDOWN() ((void) 0)
#   define DISABLE_RF9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF9
#   define CONFIG_RF9_AS_ANALOG()       \
      do {                              \
        ENABLE_RF9_ANALOG();            \
        CONFIG_RF9_AS_INPUT();          \
        DISABLE_RF9_OPENDRAIN();        \
        DISABLE_RF9_PULLUP();           \
        DISABLE_RF9_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF10
#   define ENABLE_RF10_ANALOG()  (_ANSF10 = 1)
#   define DISABLE_RF10_ANALOG() (_ANSF10 = 0)
# else
#   define DISABLE_RF10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF10_AS_INPUT()  (_TRISF10 = 1)
# define CONFIG_RF10_AS_OUTPUT() (_TRISF10 = 0)

// Open-drain:
# if defined(_ODCF10)
#   define ENABLE_RF10_OPENDRAIN()  (_ODCF10 = 1)
#   define DISABLE_RF10_OPENDRAIN() (_ODCF10 = 0)
# else
#   define DISABLE_RF10_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF10
#   define ENABLE_RF10_PULLUP()  (_CNPUF10 = 1)
#   define DISABLE_RF10_PULLUP() (_CNPUF10 = 0)

#   define ENABLE_RF10_PULLDOWN()  (_CNPDF10 = 1)
#   define DISABLE_RF10_PULLDOWN() (_CNPDF10 = 0)

#   define ENABLE_RF10_CN_INTERRUPT()  (_CNIEF10 = 1)
#   define DISABLE_RF10_CN_INTERRUPT() (_CNIEF10 = 0)

# else
#   define DISABLE_RF10_PULLUP() ((void) 0)
#   define DISABLE_RF10_PULLDOWN() ((void) 0)
#   define DISABLE_RF10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF10
#   define CONFIG_RF10_AS_ANALOG()       \
      do {                              \
        ENABLE_RF10_ANALOG();            \
        CONFIG_RF10_AS_INPUT();          \
        DISABLE_RF10_OPENDRAIN();        \
        DISABLE_RF10_PULLUP();           \
        DISABLE_RF10_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF11
#   define ENABLE_RF11_ANALOG()  (_ANSF11 = 1)
#   define DISABLE_RF11_ANALOG() (_ANSF11 = 0)
# else
#   define DISABLE_RF11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF11_AS_INPUT()  (_TRISF11 = 1)
# define CONFIG_RF11_AS_OUTPUT() (_TRISF11 = 0)

// Open-drain:
# if defined(_ODCF11)
#   define ENABLE_RF11_OPENDRAIN()  (_ODCF11 = 1)
#   define DISABLE_RF11_OPENDRAIN() (_ODCF11 = 0)
# else
#   define DISABLE_RF11_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF11
#   define ENABLE_RF11_PULLUP()  (_CNPUF11 = 1)
#   define DISABLE_RF11_PULLUP() (_CNPUF11 = 0)

#   define ENABLE_RF11_PULLDOWN()  (_CNPDF11 = 1)
#   define DISABLE_RF11_PULLDOWN() (_CNPDF11 = 0)

#   define ENABLE_RF11_CN_INTERRUPT()  (_CNIEF11 = 1)
#   define DISABLE_RF11_CN_INTERRUPT() (_CNIEF11 = 0)

# else
#   define DISABLE_RF11_PULLUP() ((void) 0)
#   define DISABLE_RF11_PULLDOWN() ((void) 0)
#   define DISABLE_RF11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF11
#   define CONFIG_RF11_AS_ANALOG()       \
      do {                              \
        ENABLE_RF11_ANALOG();            \
        CONFIG_RF11_AS_INPUT();          \
        DISABLE_RF11_OPENDRAIN();        \
        DISABLE_RF11_PULLUP();           \
        DISABLE_RF11_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF12
#   define ENABLE_RF12_ANALOG()  (_ANSF12 = 1)
#   define DISABLE_RF12_ANALOG() (_ANSF12 = 0)
# else
#   define DISABLE_RF12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF12_AS_INPUT()  (_TRISF12 = 1)
# define CONFIG_RF12_AS_OUTPUT() (_TRISF12 = 0)

// Open-drain:
# if defined(_ODCF12)
#   define ENABLE_RF12_OPENDRAIN()  (_ODCF12 = 1)
#   define DISABLE_RF12_OPENDRAIN() (_ODCF12 = 0)
# else
#   define DISABLE_RF12_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF12
#   define ENABLE_RF12_PULLUP()  (_CNPUF12 = 1)
#   define DISABLE_RF12_PULLUP() (_CNPUF12 = 0)

#   define ENABLE_RF12_PULLDOWN()  (_CNPDF12 = 1)
#   define DISABLE_RF12_PULLDOWN() (_CNPDF12 = 0)

#   define ENABLE_RF12_CN_INTERRUPT()  (_CNIEF12 = 1)
#   define DISABLE_RF12_CN_INTERRUPT() (_CNIEF12 = 0)

# else
#   define DISABLE_RF12_PULLUP() ((void) 0)
#   define DISABLE_RF12_PULLDOWN() ((void) 0)
#   define DISABLE_RF12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF12
#   define CONFIG_RF12_AS_ANALOG()       \
      do {                              \
        ENABLE_RF12_ANALOG();            \
        CONFIG_RF12_AS_INPUT();          \
        DISABLE_RF12_OPENDRAIN();        \
        DISABLE_RF12_PULLUP();           \
        DISABLE_RF12_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF13
#   define ENABLE_RF13_ANALOG()  (_ANSF13 = 1)
#   define DISABLE_RF13_ANALOG() (_ANSF13 = 0)
# else
#   define DISABLE_RF13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF13_AS_INPUT()  (_TRISF13 = 1)
# define CONFIG_RF13_AS_OUTPUT() (_TRISF13 = 0)

// Open-drain:
# if defined(_ODCF13)
#   define ENABLE_RF13_OPENDRAIN()  (_ODCF13 = 1)
#   define DISABLE_RF13_OPENDRAIN() (_ODCF13 = 0)
# else
#   define DISABLE_RF13_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF13
#   define ENABLE_RF13_PULLUP()  (_CNPUF13 = 1)
#   define DISABLE_RF13_PULLUP() (_CNPUF13 = 0)

#   define ENABLE_RF13_PULLDOWN()  (_CNPDF13 = 1)
#   define DISABLE_RF13_PULLDOWN() (_CNPDF13 = 0)

#   define ENABLE_RF13_CN_INTERRUPT()  (_CNIEF13 = 1)
#   define DISABLE_RF13_CN_INTERRUPT() (_CNIEF13 = 0)

# else
#   define DISABLE_RF13_PULLUP() ((void) 0)
#   define DISABLE_RF13_PULLDOWN() ((void) 0)
#   define DISABLE_RF13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF13
#   define CONFIG_RF13_AS_ANALOG()       \
      do {                              \
        ENABLE_RF13_ANALOG();            \
        CONFIG_RF13_AS_INPUT();          \
        DISABLE_RF13_OPENDRAIN();        \
        DISABLE_RF13_PULLUP();           \
        DISABLE_RF13_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF14
#   define ENABLE_RF14_ANALOG()  (_ANSF14 = 1)
#   define DISABLE_RF14_ANALOG() (_ANSF14 = 0)
# else
#   define DISABLE_RF14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF14_AS_INPUT()  (_TRISF14 = 1)
# define CONFIG_RF14_AS_OUTPUT() (_TRISF14 = 0)

// Open-drain:
# if defined(_ODCF14)
#   define ENABLE_RF14_OPENDRAIN()  (_ODCF14 = 1)
#   define DISABLE_RF14_OPENDRAIN() (_ODCF14 = 0)
# else
#   define DISABLE_RF14_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF14
#   define ENABLE_RF14_PULLUP()  (_CNPUF14 = 1)
#   define DISABLE_RF14_PULLUP() (_CNPUF14 = 0)

#   define ENABLE_RF14_PULLDOWN()  (_CNPDF14 = 1)
#   define DISABLE_RF14_PULLDOWN() (_CNPDF14 = 0)

#   define ENABLE_RF14_CN_INTERRUPT()  (_CNIEF14 = 1)
#   define DISABLE_RF14_CN_INTERRUPT() (_CNIEF14 = 0)

# else
#   define DISABLE_RF14_PULLUP() ((void) 0)
#   define DISABLE_RF14_PULLDOWN() ((void) 0)
#   define DISABLE_RF14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF14
#   define CONFIG_RF14_AS_ANALOG()       \
      do {                              \
        ENABLE_RF14_ANALOG();            \
        CONFIG_RF14_AS_INPUT();          \
        DISABLE_RF14_OPENDRAIN();        \
        DISABLE_RF14_PULLUP();           \
        DISABLE_RF14_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSF15
#   define ENABLE_RF15_ANALOG()  (_ANSF15 = 1)
#   define DISABLE_RF15_ANALOG() (_ANSF15 = 0)
# else
#   define DISABLE_RF15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RF15_AS_INPUT()  (_TRISF15 = 1)
# define CONFIG_RF15_AS_OUTPUT() (_TRISF15 = 0)

// Open-drain:
# if defined(_ODCF15)
#   define ENABLE_RF15_OPENDRAIN()  (_ODCF15 = 1)
#   define DISABLE_RF15_OPENDRAIN() (_ODCF15 = 0)
# else
#   define DISABLE_RF15_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEF15
#   define ENABLE_RF15_PULLUP()  (_CNPUF15 = 1)
#   define DISABLE_RF15_PULLUP() (_CNPUF15 = 0)

#   define ENABLE_RF15_PULLDOWN()  (_CNPDF15 = 1)
#   define DISABLE_RF15_PULLDOWN() (_CNPDF15 = 0)

#   define ENABLE_RF15_CN_INTERRUPT()  (_CNIEF15 = 1)
#   define DISABLE_RF15_CN_INTERRUPT() (_CNIEF15 = 0)

# else
#   define DISABLE_RF15_PULLUP() ((void) 0)
#   define DISABLE_RF15_PULLDOWN() ((void) 0)
#   define DISABLE_RF15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSF15
#   define CONFIG_RF15_AS_ANALOG()       \
      do {                              \
        ENABLE_RF15_ANALOG();            \
        CONFIG_RF15_AS_INPUT();          \
        DISABLE_RF15_OPENDRAIN();        \
        DISABLE_RF15_PULLUP();           \
        DISABLE_RF15_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG0
#   define ENABLE_RG0_ANALOG()  (_ANSG0 = 1)
#   define DISABLE_RG0_ANALOG() (_ANSG0 = 0)
# else
#   define DISABLE_RG0_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG0_AS_INPUT()  (_TRISG0 = 1)
# define CONFIG_RG0_AS_OUTPUT() (_TRISG0 = 0)

// Open-drain:
# if defined(_ODCG0)
#   define ENABLE_RG0_OPENDRAIN()  (_ODCG0 = 1)
#   define DISABLE_RG0_OPENDRAIN() (_ODCG0 = 0)
# else
#   define DISABLE_RG0_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG0
#   define ENABLE_RG0_PULLUP()  (_CNPUG0 = 1)
#   define DISABLE_RG0_PULLUP() (_CNPUG0 = 0)

#   define ENABLE_RG0_PULLDOWN()  (_CNPDG0 = 1)
#   define DISABLE_RG0_PULLDOWN() (_CNPDG0 = 0)

#   define ENABLE_RG0_CN_INTERRUPT()  (_CNIEG0 = 1)
#   define DISABLE_RG0_CN_INTERRUPT() (_CNIEG0 = 0)

# else
#   define DISABLE_RG0_PULLUP() ((void) 0)
#   define DISABLE_RG0_PULLDOWN() ((void) 0)
#   define DISABLE_RG0_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG0
#   define CONFIG_RG0_AS_ANALOG()       \
      do {                              \
        ENABLE_RG0_ANALOG();            \
        CONFIG_RG0_AS_INPUT();          \
        DISABLE_RG0_OPENDRAIN();        \
        DISABLE_RG0_PULLUP();           \
        DISABLE_RG0_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG1
#   define ENABLE_RG1_ANALOG()  (_ANSG1 = 1)
#   define DISABLE_RG1_ANALOG() (_ANSG1 = 0)
# else
#   define DISABLE_RG1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG1_AS_INPUT()  (_TRISG1 = 1)
# define CONFIG_RG1_AS_OUTPUT() (_TRISG1 = 0)

// Open-drain:
# if defined(_ODCG1)
#   define ENABLE_RG1_OPENDRAIN()  (_ODCG1 = 1)
#   define DISABLE_RG1_OPENDRAIN() (_ODCG1 = 0)
# else
#   define DISABLE_RG1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG1
#   define ENABLE_RG1_PULLUP()  (_CNPUG1 = 1)
#   define DISABLE_RG1_PULLUP() (_CNPUG1 = 0)

#   define ENABLE_RG1_PULLDOWN()  (_CNPDG1 = 1)
#   define DISABLE_RG1_PULLDOWN() (_CNPDG1 = 0)

#   define ENABLE_RG1_CN_INTERRUPT()  (_CNIEG1 = 1)
#   define DISABLE_RG1_CN_INTERRUPT() (_CNIEG1 = 0)

# else
#   define DISABLE_RG1_PULLUP() ((void) 0)
#   define DISABLE_RG1_PULLDOWN() ((void) 0)
#   define DISABLE_RG1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG1
#   define CONFIG_RG1_AS_ANALOG()       \
      do {                              \
        ENABLE_RG1_ANALOG();            \
        CONFIG_RG1_AS_INPUT();          \
        DISABLE_RG1_OPENDRAIN();        \
        DISABLE_RG1_PULLUP();           \
        DISABLE_RG1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG2
#   define ENABLE_RG2_ANALOG()  (_ANSG2 = 1)
#   define DISABLE_RG2_ANALOG() (_ANSG2 = 0)
# else
#   define DISABLE_RG2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG2_AS_INPUT()  (_TRISG2 = 1)
# define CONFIG_RG2_AS_OUTPUT() (_TRISG2 = 0)

// Open-drain:
# if defined(_ODCG2)
#   define ENABLE_RG2_OPENDRAIN()  (_ODCG2 = 1)
#   define DISABLE_RG2_OPENDRAIN() (_ODCG2 = 0)
# else
#   define DISABLE_RG2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG2
#   define ENABLE_RG2_PULLUP()  (_CNPUG2 = 1)
#   define DISABLE_RG2_PULLUP() (_CNPUG2 = 0)

#   define ENABLE_RG2_PULLDOWN()  (_CNPDG2 = 1)
#   define DISABLE_RG2_PULLDOWN() (_CNPDG2 = 0)

#   define ENABLE_RG2_CN_INTERRUPT()  (_CNIEG2 = 1)
#   define DISABLE_RG2_CN_INTERRUPT() (_CNIEG2 = 0)

# else
#   define DISABLE_RG2_PULLUP() ((void) 0)
#   define DISABLE_RG2_PULLDOWN() ((void) 0)
#   define DISABLE_RG2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG2
#   define CONFIG_RG2_AS_ANALOG()       \
      do {                              \
        ENABLE_RG2_ANALOG();            \
        CONFIG_RG2_AS_INPUT();          \
        DISABLE_RG2_OPENDRAIN();        \
        DISABLE_RG2_PULLUP();           \
        DISABLE_RG2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG3
#   define ENABLE_RG3_ANALOG()  (_ANSG3 = 1)
#   define DISABLE_RG3_ANALOG() (_ANSG3 = 0)
# else
#   define DISABLE_RG3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG3_AS_INPUT()  (_TRISG3 = 1)
# define CONFIG_RG3_AS_OUTPUT() (_TRISG3 = 0)

// Open-drain:
# if defined(_ODCG3)
#   define ENABLE_RG3_OPENDRAIN()  (_ODCG3 = 1)
#   define DISABLE_RG3_OPENDRAIN() (_ODCG3 = 0)
# else
#   define DISABLE_RG3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG3
#   define ENABLE_RG3_PULLUP()  (_CNPUG3 = 1)
#   define DISABLE_RG3_PULLUP() (_CNPUG3 = 0)

#   define ENABLE_RG3_PULLDOWN()  (_CNPDG3 = 1)
#   define DISABLE_RG3_PULLDOWN() (_CNPDG3 = 0)

#   define ENABLE_RG3_CN_INTERRUPT()  (_CNIEG3 = 1)
#   define DISABLE_RG3_CN_INTERRUPT() (_CNIEG3 = 0)

# else
#   define DISABLE_RG3_PULLUP() ((void) 0)
#   define DISABLE_RG3_PULLDOWN() ((void) 0)
#   define DISABLE_RG3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG3
#   define CONFIG_RG3_AS_ANALOG()       \
      do {                              \
        ENABLE_RG3_ANALOG();            \
        CONFIG_RG3_AS_INPUT();          \
        DISABLE_RG3_OPENDRAIN();        \
        DISABLE_RG3_PULLUP();           \
        DISABLE_RG3_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG4
#   define ENABLE_RG4_ANALOG()  (_ANSG4 = 1)
#   define DISABLE_RG4_ANALOG() (_ANSG4 = 0)
# else
#   define DISABLE_RG4_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG4_AS_INPUT()  (_TRISG4 = 1)
# define CONFIG_RG4_AS_OUTPUT() (_TRISG4 = 0)

// Open-drain:
# if defined(_ODCG4)
#   define ENABLE_RG4_OPENDRAIN()  (_ODCG4 = 1)
#   define DISABLE_RG4_OPENDRAIN() (_ODCG4 = 0)
# else
#   define DISABLE_RG4_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG4
#   define ENABLE_RG4_PULLUP()  (_CNPUG4 = 1)
#   define DISABLE_RG4_PULLUP() (_CNPUG4 = 0)

#   define ENABLE_RG4_PULLDOWN()  (_CNPDG4 = 1)
#   define DISABLE_RG4_PULLDOWN() (_CNPDG4 = 0)

#   define ENABLE_RG4_CN_INTERRUPT()  (_CNIEG4 = 1)
#   define DISABLE_RG4_CN_INTERRUPT() (_CNIEG4 = 0)

# else
#   define DISABLE_RG4_PULLUP() ((void) 0)
#   define DISABLE_RG4_PULLDOWN() ((void) 0)
#   define DISABLE_RG4_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG4
#   define CONFIG_RG4_AS_ANALOG()       \
      do {                              \
        ENABLE_RG4_ANALOG();            \
        CONFIG_RG4_AS_INPUT();          \
        DISABLE_RG4_OPENDRAIN();        \
        DISABLE_RG4_PULLUP();           \
        DISABLE_RG4_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG5
#   define ENABLE_RG5_ANALOG()  (_ANSG5 = 1)
#   define DISABLE_RG5_ANALOG() (_ANSG5 = 0)
# else
#   define DISABLE_RG5_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG5_AS_INPUT()  (_TRISG5 = 1)
# define CONFIG_RG5_AS_OUTPUT() (_TRISG5 = 0)

// Open-drain:
# if defined(_ODCG5)
#   define ENABLE_RG5_OPENDRAIN()  (_ODCG5 = 1)
#   define DISABLE_RG5_OPENDRAIN() (_ODCG5 = 0)
# else
#   define DISABLE_RG5_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG5
#   define ENABLE_RG5_PULLUP()  (_CNPUG5 = 1)
#   define DISABLE_RG5_PULLUP() (_CNPUG5 = 0)

#   define ENABLE_RG5_PULLDOWN()  (_CNPDG5 = 1)
#   define DISABLE_RG5_PULLDOWN() (_CNPDG5 = 0)

#   define ENABLE_RG5_CN_INTERRUPT()  (_CNIEG5 = 1)
#   define DISABLE_RG5_CN_INTERRUPT() (_CNIEG5 = 0)

# else
#   define DISABLE_RG5_PULLUP() ((void) 0)
#   define DISABLE_RG5_PULLDOWN() ((void) 0)
#   define DISABLE_RG5_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG5
#   define CONFIG_RG5_AS_ANALOG()       \
      do {                              \
        ENABLE_RG5_ANALOG();            \
        CONFIG_RG5_AS_INPUT();          \
        DISABLE_RG5_OPENDRAIN();        \
        DISABLE_RG5_PULLUP();           \
        DISABLE_RG5_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG6
#   define ENABLE_RG6_ANALOG()  (_ANSG6 = 1)
#   define DISABLE_RG6_ANALOG() (_ANSG6 = 0)
# else
#   define DISABLE_RG6_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG6_AS_INPUT()  (_TRISG6 = 1)
# define CONFIG_RG6_AS_OUTPUT() (_TRISG6 = 0)

// Open-drain:
# if defined(_ODCG6)
#   define ENABLE_RG6_OPENDRAIN()  (_ODCG6 = 1)
#   define DISABLE_RG6_OPENDRAIN() (_ODCG6 = 0)
# else
#   define DISABLE_RG6_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG6
#   define ENABLE_RG6_PULLUP()  (_CNPUG6 = 1)
#   define DISABLE_RG6_PULLUP() (_CNPUG6 = 0)

#   define ENABLE_RG6_PULLDOWN()  (_CNPDG6 = 1)
#   define DISABLE_RG6_PULLDOWN() (_CNPDG6 = 0)

#   define ENABLE_RG6_CN_INTERRUPT()  (_CNIEG6 = 1)
#   define DISABLE_RG6_CN_INTERRUPT() (_CNIEG6 = 0)

# else
#   define DISABLE_RG6_PULLUP() ((void) 0)
#   define DISABLE_RG6_PULLDOWN() ((void) 0)
#   define DISABLE_RG6_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG6
#   define CONFIG_RG6_AS_ANALOG()       \
      do {                              \
        ENABLE_RG6_ANALOG();            \
        CONFIG_RG6_AS_INPUT();          \
        DISABLE_RG6_OPENDRAIN();        \
        DISABLE_RG6_PULLUP();           \
        DISABLE_RG6_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG7
#   define ENABLE_RG7_ANALOG()  (_ANSG7 = 1)
#   define DISABLE_RG7_ANALOG() (_ANSG7 = 0)
# else
#   define DISABLE_RG7_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG7_AS_INPUT()  (_TRISG7 = 1)
# define CONFIG_RG7_AS_OUTPUT() (_TRISG7 = 0)

// Open-drain:
# if defined(_ODCG7)
#   define ENABLE_RG7_OPENDRAIN()  (_ODCG7 = 1)
#   define DISABLE_RG7_OPENDRAIN() (_ODCG7 = 0)
# else
#   define DISABLE_RG7_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG7
#   define ENABLE_RG7_PULLUP()  (_CNPUG7 = 1)
#   define DISABLE_RG7_PULLUP() (_CNPUG7 = 0)

#   define ENABLE_RG7_PULLDOWN()  (_CNPDG7 = 1)
#   define DISABLE_RG7_PULLDOWN() (_CNPDG7 = 0)

#   define ENABLE_RG7_CN_INTERRUPT()  (_CNIEG7 = 1)
#   define DISABLE_RG7_CN_INTERRUPT() (_CNIEG7 = 0)

# else
#   define DISABLE_RG7_PULLUP() ((void) 0)
#   define DISABLE_RG7_PULLDOWN() ((void) 0)
#   define DISABLE_RG7_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG7
#   define CONFIG_RG7_AS_ANALOG()       \
      do {                              \
        ENABLE_RG7_ANALOG();            \
        CONFIG_RG7_AS_INPUT();          \
        DISABLE_RG7_OPENDRAIN();        \
        DISABLE_RG7_PULLUP();           \
        DISABLE_RG7_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG8
#   define ENABLE_RG8_ANALOG()  (_ANSG8 = 1)
#   define DISABLE_RG8_ANALOG() (_ANSG8 = 0)
# else
#   define DISABLE_RG8_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG8_AS_INPUT()  (_TRISG8 = 1)
# define CONFIG_RG8_AS_OUTPUT() (_TRISG8 = 0)

// Open-drain:
# if defined(_ODCG8)
#   define ENABLE_RG8_OPENDRAIN()  (_ODCG8 = 1)
#   define DISABLE_RG8_OPENDRAIN() (_ODCG8 = 0)
# else
#   define DISABLE_RG8_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG8
#   define ENABLE_RG8_PULLUP()  (_CNPUG8 = 1)
#   define DISABLE_RG8_PULLUP() (_CNPUG8 = 0)

#   define ENABLE_RG8_PULLDOWN()  (_CNPDG8 = 1)
#   define DISABLE_RG8_PULLDOWN() (_CNPDG8 = 0)

#   define ENABLE_RG8_CN_INTERRUPT()  (_CNIEG8 = 1)
#   define DISABLE_RG8_CN_INTERRUPT() (_CNIEG8 = 0)

# else
#   define DISABLE_RG8_PULLUP() ((void) 0)
#   define DISABLE_RG8_PULLDOWN() ((void) 0)
#   define DISABLE_RG8_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG8
#   define CONFIG_RG8_AS_ANALOG()       \
      do {                              \
        ENABLE_RG8_ANALOG();            \
        CONFIG_RG8_AS_INPUT();          \
        DISABLE_RG8_OPENDRAIN();        \
        DISABLE_RG8_PULLUP();           \
        DISABLE_RG8_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG9
#   define ENABLE_RG9_ANALOG()  (_ANSG9 = 1)
#   define DISABLE_RG9_ANALOG() (_ANSG9 = 0)
# else
#   define DISABLE_RG9_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG9_AS_INPUT()  (_TRISG9 = 1)
# define CONFIG_RG9_AS_OUTPUT() (_TRISG9 = 0)

// Open-drain:
# if defined(_ODCG9)
#   define ENABLE_RG9_OPENDRAIN()  (_ODCG9 = 1)
#   define DISABLE_RG9_OPENDRAIN() (_ODCG9 = 0)
# else
#   define DISABLE_RG9_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG9
#   define ENABLE_RG9_PULLUP()  (_CNPUG9 = 1)
#   define DISABLE_RG9_PULLUP() (_CNPUG9 = 0)

#   define ENABLE_RG9_PULLDOWN()  (_CNPDG9 = 1)
#   define DISABLE_RG9_PULLDOWN() (_CNPDG9 = 0)

#   define ENABLE_RG9_CN_INTERRUPT()  (_CNIEG9 = 1)
#   define DISABLE_RG9_CN_INTERRUPT() (_CNIEG9 = 0)

# else
#   define DISABLE_RG9_PULLUP() ((void) 0)
#   define DISABLE_RG9_PULLDOWN() ((void) 0)
#   define DISABLE_RG9_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG9
#   define CONFIG_RG9_AS_ANALOG()       \
      do {                              \
        ENABLE_RG9_ANALOG();            \
        CONFIG_RG9_AS_INPUT();          \
        DISABLE_RG9_OPENDRAIN();        \
        DISABLE_RG9_PULLUP();           \
        DISABLE_RG9_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG10
#   define ENABLE_RG10_ANALOG()  (_ANSG10 = 1)
#   define DISABLE_RG10_ANALOG() (_ANSG10 = 0)
# else
#   define DISABLE_RG10_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG10_AS_INPUT()  (_TRISG10 = 1)
# define CONFIG_RG10_AS_OUTPUT() (_TRISG10 = 0)

// Open-drain:
# if defined(_ODCG10)
#   define ENABLE_RG10_OPENDRAIN()  (_ODCG10 = 1)
#   define DISABLE_RG10_OPENDRAIN() (_ODCG10 = 0)
# else
#   define DISABLE_RG10_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG10
#   define ENABLE_RG10_PULLUP()  (_CNPUG10 = 1)
#   define DISABLE_RG10_PULLUP() (_CNPUG10 = 0)

#   define ENABLE_RG10_PULLDOWN()  (_CNPDG10 = 1)
#   define DISABLE_RG10_PULLDOWN() (_CNPDG10 = 0)

#   define ENABLE_RG10_CN_INTERRUPT()  (_CNIEG10 = 1)
#   define DISABLE_RG10_CN_INTERRUPT() (_CNIEG10 = 0)

# else
#   define DISABLE_RG10_PULLUP() ((void) 0)
#   define DISABLE_RG10_PULLDOWN() ((void) 0)
#   define DISABLE_RG10_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG10
#   define CONFIG_RG10_AS_ANALOG()       \
      do {                              \
        ENABLE_RG10_ANALOG();            \
        CONFIG_RG10_AS_INPUT();          \
        DISABLE_RG10_OPENDRAIN();        \
        DISABLE_RG10_PULLUP();           \
        DISABLE_RG10_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG11
#   define ENABLE_RG11_ANALOG()  (_ANSG11 = 1)
#   define DISABLE_RG11_ANALOG() (_ANSG11 = 0)
# else
#   define DISABLE_RG11_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG11_AS_INPUT()  (_TRISG11 = 1)
# define CONFIG_RG11_AS_OUTPUT() (_TRISG11 = 0)

// Open-drain:
# if defined(_ODCG11)
#   define ENABLE_RG11_OPENDRAIN()  (_ODCG11 = 1)
#   define DISABLE_RG11_OPENDRAIN() (_ODCG11 = 0)
# else
#   define DISABLE_RG11_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG11
#   define ENABLE_RG11_PULLUP()  (_CNPUG11 = 1)
#   define DISABLE_RG11_PULLUP() (_CNPUG11 = 0)

#   define ENABLE_RG11_PULLDOWN()  (_CNPDG11 = 1)
#   define DISABLE_RG11_PULLDOWN() (_CNPDG11 = 0)

#   define ENABLE_RG11_CN_INTERRUPT()  (_CNIEG11 = 1)
#   define DISABLE_RG11_CN_INTERRUPT() (_CNIEG11 = 0)

# else
#   define DISABLE_RG11_PULLUP() ((void) 0)
#   define DISABLE_RG11_PULLDOWN() ((void) 0)
#   define DISABLE_RG11_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG11
#   define CONFIG_RG11_AS_ANALOG()       \
      do {                              \
        ENABLE_RG11_ANALOG();            \
        CONFIG_RG11_AS_INPUT();          \
        DISABLE_RG11_OPENDRAIN();        \
        DISABLE_RG11_PULLUP();           \
        DISABLE_RG11_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG12
#   define ENABLE_RG12_ANALOG()  (_ANSG12 = 1)
#   define DISABLE_RG12_ANALOG() (_ANSG12 = 0)
# else
#   define DISABLE_RG12_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG12_AS_INPUT()  (_TRISG12 = 1)
# define CONFIG_RG12_AS_OUTPUT() (_TRISG12 = 0)

// Open-drain:
# if defined(_ODCG12)
#   define ENABLE_RG12_OPENDRAIN()  (_ODCG12 = 1)
#   define DISABLE_RG12_OPENDRAIN() (_ODCG12 = 0)
# else
#   define DISABLE_RG12_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG12
#   define ENABLE_RG12_PULLUP()  (_CNPUG12 = 1)
#   define DISABLE_RG12_PULLUP() (_CNPUG12 = 0)

#   define ENABLE_RG12_PULLDOWN()  (_CNPDG12 = 1)
#   define DISABLE_RG12_PULLDOWN() (_CNPDG12 = 0)

#   define ENABLE_RG12_CN_INTERRUPT()  (_CNIEG12 = 1)
#   define DISABLE_RG12_CN_INTERRUPT() (_CNIEG12 = 0)

# else
#   define DISABLE_RG12_PULLUP() ((void) 0)
#   define DISABLE_RG12_PULLDOWN() ((void) 0)
#   define DISABLE_RG12_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG12
#   define CONFIG_RG12_AS_ANALOG()       \
      do {                              \
        ENABLE_RG12_ANALOG();            \
        CONFIG_RG12_AS_INPUT();          \
        DISABLE_RG12_OPENDRAIN();        \
        DISABLE_RG12_PULLUP();           \
        DISABLE_RG12_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG13
#   define ENABLE_RG13_ANALOG()  (_ANSG13 = 1)
#   define DISABLE_RG13_ANALOG() (_ANSG13 = 0)
# else
#   define DISABLE_RG13_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG13_AS_INPUT()  (_TRISG13 = 1)
# define CONFIG_RG13_AS_OUTPUT() (_TRISG13 = 0)

// Open-drain:
# if defined(_ODCG13)
#   define ENABLE_RG13_OPENDRAIN()  (_ODCG13 = 1)
#   define DISABLE_RG13_OPENDRAIN() (_ODCG13 = 0)
# else
#   define DISABLE_RG13_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG13
#   define ENABLE_RG13_PULLUP()  (_CNPUG13 = 1)
#   define DISABLE_RG13_PULLUP() (_CNPUG13 = 0)

#   define ENABLE_RG13_PULLDOWN()  (_CNPDG13 = 1)
#   define DISABLE_RG13_PULLDOWN() (_CNPDG13 = 0)

#   define ENABLE_RG13_CN_INTERRUPT()  (_CNIEG13 = 1)
#   define DISABLE_RG13_CN_INTERRUPT() (_CNIEG13 = 0)

# else
#   define DISABLE_RG13_PULLUP() ((void) 0)
#   define DISABLE_RG13_PULLDOWN() ((void) 0)
#   define DISABLE_RG13_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG13
#   define CONFIG_RG13_AS_ANALOG()       \
      do {                              \
        ENABLE_RG13_ANALOG();            \
        CONFIG_RG13_AS_INPUT();          \
        DISABLE_RG13_OPENDRAIN();        \
        DISABLE_RG13_PULLUP();           \
        DISABLE_RG13_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG14
#   define ENABLE_RG14_ANALOG()  (_ANSG14 = 1)
#   define DISABLE_RG14_ANALOG() (_ANSG14 = 0)
# else
#   define DISABLE_RG14_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG14_AS_INPUT()  (_TRISG14 = 1)
# define CONFIG_RG14_AS_OUTPUT() (_TRISG14 = 0)

// Open-drain:
# if defined(_ODCG14)
#   define ENABLE_RG14_OPENDRAIN()  (_ODCG14 = 1)
#   define DISABLE_RG14_OPENDRAIN() (_ODCG14 = 0)
# else
#   define DISABLE_RG14_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG14
#   define ENABLE_RG14_PULLUP()  (_CNPUG14 = 1)
#   define DISABLE_RG14_PULLUP() (_CNPUG14 = 0)

#   define ENABLE_RG14_PULLDOWN()  (_CNPDG14 = 1)
#   define DISABLE_RG14_PULLDOWN() (_CNPDG14 = 0)

#   define ENABLE_RG14_CN_INTERRUPT()  (_CNIEG14 = 1)
#   define DISABLE_RG14_CN_INTERRUPT() (_CNIEG14 = 0)

# else
#   define DISABLE_RG14_PULLUP() ((void) 0)
#   define DISABLE_RG14_PULLDOWN() ((void) 0)
#   define DISABLE_RG14_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG14
#   define CONFIG_RG14_AS_ANALOG()       \
      do {                              \
        ENABLE_RG14_ANALOG();            \
        CONFIG_RG14_AS_INPUT();          \
        DISABLE_RG14_OPENDRAIN();        \
        DISABLE_RG14_PULLUP();           \
        DISABLE_RG14_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANSG15
#   define ENABLE_RG15_ANALOG()  (_ANSG15 = 1)
#   define DISABLE_RG15_ANALOG() (_ANSG15 = 0)
# else
#   define DISABLE_RG15_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RG15_AS_INPUT()  (_TRISG15 = 1)
# define CONFIG_RG15_AS_OUTPUT() (_TRISG15 = 0)

// Open-drain:
# if defined(_ODCG15)
#   define ENABLE_RG15_OPENDRAIN()  (_ODCG15 = 1)
#   define DISABLE_RG15_OPENDRAIN() (_ODCG15 = 0)
# else
#   define DISABLE_RG15_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIEG15
#   define ENABLE_RG15_PULLUP()  (_CNPUG15 = 1)
#   define DISABLE_RG15_PULLUP() (_CNPUG15 = 0)

#   define ENABLE_RG15_PULLDOWN()  (_CNPDG15 = 1)
#   define DISABLE_RG15_PULLDOWN() (_CNPDG15 = 0)

#   define ENABLE_RG15_CN_INTERRUPT()  (_CNIEG15 = 1)
#   define DISABLE_RG15_CN_INTERRUPT() (_CNIEG15 = 0)

# else
#   define DISABLE_RG15_PULLUP() ((void) 0)
#   define DISABLE_RG15_PULLDOWN() ((void) 0)
#   define DISABLE_RG15_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANSG15
#   define CONFIG_RG15_AS_ANALOG()       \
      do {                              \
        ENABLE_RG15_ANALOG();            \
        CONFIG_RG15_AS_INPUT();          \
        DISABLE_RG15_OPENDRAIN();        \
        DISABLE_RG15_PULLUP();           \
        DISABLE_RG15_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANST1
#   define ENABLE_RT1_ANALOG()  (_ANST1 = 1)
#   define DISABLE_RT1_ANALOG() (_ANST1 = 0)
# else
#   define DISABLE_RT1_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RT1_AS_INPUT()  (_TRIST1 = 1)
# define CONFIG_RT1_AS_OUTPUT() (_TRIST1 = 0)

// Open-drain:
# if defined(_ODCT1)
#   define ENABLE_RT1_OPENDRAIN()  (_ODCT1 = 1)
#   define DISABLE_RT1_OPENDRAIN() (_ODCT1 = 0)
# else
#   define DISABLE_RT1_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIET1
#   define ENABLE_RT1_PULLUP()  (_CNPUT1 = 1)
#   define DISABLE_RT1_PULLUP() (_CNPUT1 = 0)

#   define ENABLE_RT1_PULLDOWN()  (_CNPDT1 = 1)
#   define DISABLE_RT1_PULLDOWN() (_CNPDT1 = 0)

#   define ENABLE_RT1_CN_INTERRUPT()  (_CNIET1 = 1)
#   define DISABLE_RT1_CN_INTERRUPT() (_CNIET1 = 0)

# else
#   define DISABLE_RT1_PULLUP() ((void) 0)
#   define DISABLE_RT1_PULLDOWN() ((void) 0)
#   define DISABLE_RT1_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANST1
#   define CONFIG_RT1_AS_ANALOG()       \
      do {                              \
        ENABLE_RT1_ANALOG();            \
        CONFIG_RT1_AS_INPUT();          \
        DISABLE_RT1_OPENDRAIN();        \
        DISABLE_RT1_PULLUP();           \
        DISABLE_RT1_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANST2
#   define ENABLE_RT2_ANALOG()  (_ANST2 = 1)
#   define DISABLE_RT2_ANALOG() (_ANST2 = 0)
# else
#   define DISABLE_RT2_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RT2_AS_INPUT()  (_TRIST2 = 1)
# define CONFIG_RT2_AS_OUTPUT() (_TRIST2 = 0)

// Open-drain:
# if defined(_ODCT2)
#   define ENABLE_RT2_OPENDRAIN()  (_ODCT2 = 1)
#   define DISABLE_RT2_OPENDRAIN() (_ODCT2 = 0)
# else
#   define DISABLE_RT2_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIET2
#   define ENABLE_RT2_PULLUP()  (_CNPUT2 = 1)
#   define DISABLE_RT2_PULLUP() (_CNPUT2 = 0)

#   define ENABLE_RT2_PULLDOWN()  (_CNPDT2 = 1)
#   define DISABLE_RT2_PULLDOWN() (_CNPDT2 = 0)

#   define ENABLE_RT2_CN_INTERRUPT()  (_CNIET2 = 1)
#   define DISABLE_RT2_CN_INTERRUPT() (_CNIET2 = 0)

# else
#   define DISABLE_RT2_PULLUP() ((void) 0)
#   define DISABLE_RT2_PULLDOWN() ((void) 0)
#   define DISABLE_RT2_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANST2
#   define CONFIG_RT2_AS_ANALOG()       \
      do {                              \
        ENABLE_RT2_ANALOG();            \
        CONFIG_RT2_AS_INPUT();          \
        DISABLE_RT2_OPENDRAIN();        \
        DISABLE_RT2_PULLUP();           \
        DISABLE_RT2_PULLDOWN();         \
      } while (0)
# endif

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

// Low-level config
// ----------------
// Analog:
# ifdef _ANST3
#   define ENABLE_RT3_ANALOG()  (_ANST3 = 1)
#   define DISABLE_RT3_ANALOG() (_ANST3 = 0)
# else
#   define DISABLE_RT3_ANALOG() ((void) 0)
# endif

// Input/output:
# define CONFIG_RT3_AS_INPUT()  (_TRIST3 = 1)
# define CONFIG_RT3_AS_OUTPUT() (_TRIST3 = 0)

// Open-drain:
# if defined(_ODCT3)
#   define ENABLE_RT3_OPENDRAIN()  (_ODCT3 = 1)
#   define DISABLE_RT3_OPENDRAIN() (_ODCT3 = 0)
# else
#   define DISABLE_RT3_OPENDRAIN() ((void) 0)
# endif

// Change notification, pullups and pulldowns:
# ifdef _CNIET3
#   define ENABLE_RT3_PULLUP()  (_CNPUT3 = 1)
#   define DISABLE_RT3_PULLUP() (_CNPUT3 = 0)

#   define ENABLE_RT3_PULLDOWN()  (_CNPDT3 = 1)
#   define DISABLE_RT3_PULLDOWN() (_CNPDT3 = 0)

#   define ENABLE_RT3_CN_INTERRUPT()  (_CNIET3 = 1)
#   define DISABLE_RT3_CN_INTERRUPT() (_CNIET3 = 0)

# else
#   define DISABLE_RT3_PULLUP() ((void) 0)
#   define DISABLE_RT3_PULLDOWN() ((void) 0)
#   define DISABLE_RT3_CN_INTERRUPT() ((void) 0)
# endif

// High-level config
// -----------------
# ifdef _ANST3
#   define CONFIG_RT3_AS_ANALOG()       \
      do {                              \
        ENABLE_RT3_ANALOG();            \
        CONFIG_RT3_AS_INPUT();          \
        DISABLE_RT3_OPENDRAIN();        \
        DISABLE_RT3_PULLUP();           \
        DISABLE_RT3_PULLDOWN();         \
      } while (0)
# endif

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





