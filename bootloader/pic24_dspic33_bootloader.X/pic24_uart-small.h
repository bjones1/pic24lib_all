// ************************************************************************************
// pic24_uart-small.h - Headers for bare minimum UART functionality for the bootloader.
// ************************************************************************************

#pragma once

#include "pic24_libconfig.h"

#if DEFAULT_UART==1
# define DEFAULT_UART_FERR U1STAbits.FERR
# define DEFAULT_UART_OERR U1STAbits.OERR
# define DEFAULT_UART_RXREG U1RXREG
# define DEFAULT_UART_URXDA U1STAbits.URXDA
# define DEFAULT_UART_UTXBF U1STAbits.UTXBF
# define DEFAULT_UART_TXREG U1TXREG

#elif DEFAULT_UART==2
# define DEFAULT_UART_FERR U2STAbits.FERR
# define DEFAULT_UART_OERR U2STAbits.OERR
# define DEFAULT_UART_RXREG U2RXREG
# define DEFAULT_UART_URXDA U2STAbits.URXDA
# define DEFAULT_UART_UTXBF U2STAbits.UTXBF
# define DEFAULT_UART_TXREG U2TXREG

#elif DEFAULT_UART==3
# define DEFAULT_UART_FERR U3STAbits.FERR
# define DEFAULT_UART_OERR U3STAbits.OERR
# define DEFAULT_UART_RXREG U3RXREG
# define DEFAULT_UART_URXDA U3STAbits.URXDA
# define DEFAULT_UART_UTXBF U3STAbits.UTXBF
# define DEFAULT_UART_TXREG U3TXREG

#elif DEFAULT_UART==4
# define DEFAULT_UART_FERR U4STAbits.FERR
# define DEFAULT_UART_OERR U4STAbits.OERR
# define DEFAULT_UART_RXREG U4RXREG
# define DEFAULT_UART_URXDA U4STAbits.URXDA
# define DEFAULT_UART_UTXBF U4STAbits.UTXBF
# define DEFAULT_UART_TXREG U4TXREG

#else

# error "DEFAULT_UART value invalid."

#endif
