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



#if 0

#elif defined(__PIC24F16KA102__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO -1, 2, 4
# define RB1_GPIO -1, 3, 5
# define RB2_GPIO -1, 4, 6
# define RB3_GPIO -1, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, 12, 14
# define RB13_GPIO -1, 11, 13
# define RB14_GPIO -1, 10, 12
# define RB15_GPIO -1, -1, 11

#elif defined(__dsPIC33FJ12GP201__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB4_GPIO -1, -1, 1
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB14_GPIO 14, 7, 12
# define RB15_GPIO 15, 6, 11

#elif defined(__dsPIC33FJ32GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__dsPIC33FJ32GP302__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__dsPIC33FJ64GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__dsPIC33FJ64GP802__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__dsPIC33FJ128GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__dsPIC33FJ128GP802__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__dsPIC33FJ12GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 9, 14
# define RB13_GPIO 13, 8, 13
# define RB14_GPIO 14, 7, 12
# define RB15_GPIO 15, 6, 11

#elif defined(__dsPIC33FJ16GP304__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__dsPIC33FJ32GP204__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__dsPIC33FJ32GP304__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__dsPIC33FJ64GP204__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__dsPIC33FJ64GP804__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__dsPIC33FJ128GP204__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__dsPIC33FJ128GP804__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24EP64GP202__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5

#elif defined(__dsPIC33EP64GP502__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5

#elif defined(__PIC24EP64MC202__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5

#elif defined(__dsPIC33EP64MC202__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5

#elif defined(__dsPIC33EP64MC502__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5

#elif defined(__PIC24EP32GP203__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__PIC24EP64GP203__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__dsPIC33EP32GP503__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__dsPIC33EP64GP503__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__PIC24EP32MC203__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__PIC24EP64MC203__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__PIC24EP32MC503__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__PIC24EP64MC503__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__dsPIC33EP32MC503__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__dsPIC33EP64MC503__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__dsPIC33EP32MC203__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__dsPIC33EP64MC203__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7

#elif defined(__PIC24EP32GP204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP64GP204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP128GP204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP256GP204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP512GP204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP32GP504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP64GP504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP128GP504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP256GP504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP512GP504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP32MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP64MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP128MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP256MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP512MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP32MC504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP64MC504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP128MC504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP256MC504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP512MC504__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP32MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP64MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP128MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP256MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__dsPIC33EP512MC204__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8

#elif defined(__PIC24EP64GP206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__PIC24EP128GP206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__PIC24EP256GP206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__PIC24EP512GP206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP64GP506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP128GP506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP256GP506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP512GP506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__PIC24EP64MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__PIC24EP128MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__PIC24EP256MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__PIC24EP512MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP64MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP128MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP256MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP512MC206__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP64MC506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP128MC506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP256MC506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP512MC506__)
# define RA0_AN_PORT 0
# define RA1_AN_PORT 1
# define RA11_AN_PORT 9
# define RA12_AN_PORT 10
# define RB0_AN_PORT 2
# define RB1_AN_PORT 3
# define RB2_AN_PORT 4
# define RB3_AN_PORT 5
# define RC0_AN_PORT 6
# define RC1_AN_PORT 7
# define RC2_AN_PORT 8
# define RC11_AN_PORT 11
# define RE12_AN_PORT 12
# define RE13_AN_PORT 13
# define RE14_AN_PORT 14
# define RE15_AN_PORT 15

#elif defined(__dsPIC33EP256MU806__)
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31

#elif defined(__dsPIC33EP512MU806__)
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31

#elif defined(__dsPIC33EP512GP806__)
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31

#elif defined(__PIC24EP512GP806__)
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31

#elif defined(__dsPIC33EP512MC806__)
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31

#elif defined(__dsPIC33EP512MU810__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__dsPIC33EP256MU810__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__PIC24EP512GU810__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__PIC24EP256GU810__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__dsPIC33EP512MU814__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__dsPIC33EP256MU814__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__PIC24EP512GU814__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__PIC24EP256GU814__)
# define RA6_AN_PORT 22
# define RA7_AN_PORT 23
# define RB0_AN_PORT 0
# define RB1_AN_PORT 1
# define RB2_AN_PORT 2
# define RB3_AN_PORT 3
# define RB4_AN_PORT 4
# define RB5_AN_PORT 5
# define RB6_AN_PORT 6
# define RB7_AN_PORT 7
# define RB8_AN_PORT 8
# define RB9_AN_PORT 9
# define RB10_AN_PORT 10
# define RB11_AN_PORT 11
# define RB12_AN_PORT 12
# define RB13_AN_PORT 13
# define RB14_AN_PORT 14
# define RB15_AN_PORT 15
# define RC1_AN_PORT 16
# define RC2_AN_PORT 17
# define RC3_AN_PORT 18
# define RC4_AN_PORT 19
# define RE0_AN_PORT 24
# define RE1_AN_PORT 25
# define RE2_AN_PORT 26
# define RE3_AN_PORT 27
# define RE4_AN_PORT 28
# define RE5_AN_PORT 29
# define RE6_AN_PORT 30
# define RE7_AN_PORT 31
# define RE8_AN_PORT 20
# define RE9_AN_PORT 21

#elif defined(__PIC24HJ12GP201__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB4_GPIO -1, -1, 1
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB14_GPIO 14, 7, 12
# define RB15_GPIO 15, 6, 11

#elif defined(__PIC24HJ32GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO 4, -1, 1
# define RB5_GPIO 5, -1, 27
# define RB6_GPIO 6, -1, 24
# define RB7_GPIO 7, -1, 23
# define RB8_GPIO 8, -1, 22
# define RB9_GPIO 9, -1, 21
# define RB10_GPIO 10, -1, 16
# define RB11_GPIO 11, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24HJ32GP302__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24HJ64GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24HJ64GP502__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24HJ128GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24HJ128GP502__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24HJ12GP202__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 9, 14
# define RB13_GPIO 13, 8, 13
# define RB14_GPIO 14, 7, 12
# define RB15_GPIO 15, 6, 11

#elif defined(__PIC24HJ16GP304__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24HJ32GP204__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24HJ32GP304__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24HJ64GP204__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24HJ64GP504__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24HJ128GP204__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24HJ128GP504__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24HJ64GP206__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ64GP206a__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP206__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP206a__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ256GP206__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP306__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP306a__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ64GP506__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP506__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ64GP506a__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP506a__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ64GP210__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ64GP210a__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP210__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP210a__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP310__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP310a__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ256GP210__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ64GP510__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP510__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ64GP510a__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ128GP510a__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24HJ256GP610__)
# define RA6_GPIO -1, 22, 22
# define RA7_GPIO -1, 23, 23
# define RA12_GPIO -1, 20, -1
# define RA13_GPIO -1, 21, -1
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC1_GPIO -1, 16, -1
# define RC2_GPIO -1, 17, -1
# define RC3_GPIO -1, 18, -1
# define RC4_GPIO -1, 19, -1
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, 24, -1
# define RE1_GPIO -1, 25, -1
# define RE2_GPIO -1, 26, -1
# define RE3_GPIO -1, 27, -1
# define RE4_GPIO -1, 28, -1
# define RE5_GPIO -1, 29, -1
# define RE6_GPIO -1, 30, -1
# define RE7_GPIO -1, 31, -1
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ16ga002__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ32ga002__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ48ga002__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ64ga002__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ32ga102__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ64ga102__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO 12, 12, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ32gb002__)
# define RA0_GPIO 5, 0, 2
# define RA1_GPIO 6, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ64gb002__)
# define RA0_GPIO 5, 0, 2
# define RA1_GPIO 6, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11

#elif defined(__PIC24FJ16ga004__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ32ga004__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ48ga004__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ64ga004__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ32ga104__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ64ga104__)
# define RA0_GPIO -1, 0, 2
# define RA1_GPIO -1, 1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO 0, 2, 4
# define RB1_GPIO 1, 3, 5
# define RB2_GPIO 2, 4, 6
# define RB3_GPIO 3, 5, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB6_GPIO -1, -1, 24
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 22
# define RB9_GPIO -1, -1, 21
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB12_GPIO -1, -1, 14
# define RB13_GPIO 13, 11, 13
# define RB14_GPIO 14, 10, 12
# define RB15_GPIO 15, 9, 11
# define RC0_GPIO 16, 6, 8
# define RC1_GPIO 17, 7, 9
# define RC2_GPIO 18, 8, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ32gb004__)
# define RA0_GPIO -1, -1, 2
# define RA1_GPIO -1, -1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO -1, -1, 4
# define RB1_GPIO -1, -1, 5
# define RB2_GPIO -1, -1, 6
# define RB3_GPIO -1, -1, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 18
# define RB9_GPIO -1, -1, 22
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB13_GPIO -1, -1, 13
# define RB14_GPIO -1, -1, 12
# define RB15_GPIO -1, -1, 11
# define RC0_GPIO -1, -1, 8
# define RC1_GPIO -1, -1, 9
# define RC2_GPIO -1, -1, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ64gb004__)
# define RA0_GPIO -1, -1, 2
# define RA1_GPIO -1, -1, 3
# define RA2_GPIO -1, -1, 30
# define RA3_GPIO -1, -1, 29
# define RA4_GPIO -1, -1, 0
# define RB0_GPIO -1, -1, 4
# define RB1_GPIO -1, -1, 5
# define RB2_GPIO -1, -1, 6
# define RB3_GPIO -1, -1, 7
# define RB4_GPIO -1, -1, 1
# define RB5_GPIO -1, -1, 27
# define RB7_GPIO -1, -1, 23
# define RB8_GPIO -1, -1, 18
# define RB9_GPIO -1, -1, 22
# define RB10_GPIO -1, -1, 16
# define RB11_GPIO -1, -1, 15
# define RB13_GPIO -1, -1, 13
# define RB14_GPIO -1, -1, 12
# define RB15_GPIO -1, -1, 11
# define RC0_GPIO -1, -1, 8
# define RC1_GPIO -1, -1, 9
# define RC2_GPIO -1, -1, 10
# define RC3_GPIO -1, -1, 28
# define RC4_GPIO -1, -1, 25
# define RC5_GPIO -1, -1, 26
# define RC6_GPIO -1, -1, 18
# define RC7_GPIO -1, -1, 17
# define RC8_GPIO -1, -1, 20
# define RC9_GPIO -1, -1, 19

#elif defined(__PIC24FJ128ga106__)
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ192ga106__)
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ256ga106__)
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ64ga006__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ96ga006__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ128ga006__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ64gb106__)
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ128gb106__)
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ192gb106__)
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ256gb106__)
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ128ga110__)
# define RA0_GPIO -1, -1, 33
# define RA1_GPIO -1, -1, 34
# define RA2_GPIO -1, -1, 35
# define RA3_GPIO -1, -1, 36
# define RA4_GPIO -1, -1, 37
# define RA5_GPIO -1, -1, 38
# define RA6_GPIO -1, -1, 39
# define RA7_GPIO -1, -1, 40
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC2_GPIO -1, -1, 46
# define RC3_GPIO -1, -1, 47
# define RC4_GPIO -1, -1, 48
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RF7_GPIO -1, -1, 73
# define RF8_GPIO -1, -1, 74
# define RF12_GPIO -1, -1, 75
# define RF13_GPIO -1, -1, 76
# define RG0_GPIO -1, -1, 77
# define RG1_GPIO -1, -1, 78
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
# define RG12_GPIO -1, -1, 79
# define RG13_GPIO -1, -1, 80
# define RG14_GPIO -1, -1, 81
# define RG15_GPIO -1, -1, 82

#elif defined(__PIC24FJ192ga110__)
# define RA0_GPIO -1, -1, 33
# define RA1_GPIO -1, -1, 34
# define RA2_GPIO -1, -1, 35
# define RA3_GPIO -1, -1, 36
# define RA4_GPIO -1, -1, 37
# define RA5_GPIO -1, -1, 38
# define RA6_GPIO -1, -1, 39
# define RA7_GPIO -1, -1, 40
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC2_GPIO -1, -1, 46
# define RC3_GPIO -1, -1, 47
# define RC4_GPIO -1, -1, 48
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RF7_GPIO -1, -1, 73
# define RF8_GPIO -1, -1, 74
# define RF12_GPIO -1, -1, 75
# define RF13_GPIO -1, -1, 76
# define RG0_GPIO -1, -1, 77
# define RG1_GPIO -1, -1, 78
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
# define RG12_GPIO -1, -1, 79
# define RG13_GPIO -1, -1, 80
# define RG14_GPIO -1, -1, 81
# define RG15_GPIO -1, -1, 82

#elif defined(__PIC24FJ256ga110__)
# define RA0_GPIO -1, -1, 33
# define RA1_GPIO -1, -1, 34
# define RA2_GPIO -1, -1, 35
# define RA3_GPIO -1, -1, 36
# define RA4_GPIO -1, -1, 37
# define RA5_GPIO -1, -1, 38
# define RA6_GPIO -1, -1, 39
# define RA7_GPIO -1, -1, 40
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC2_GPIO -1, -1, 46
# define RC3_GPIO -1, -1, 47
# define RC4_GPIO -1, -1, 48
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RF7_GPIO -1, -1, 73
# define RF8_GPIO -1, -1, 74
# define RF12_GPIO -1, -1, 75
# define RF13_GPIO -1, -1, 76
# define RG0_GPIO -1, -1, 77
# define RG1_GPIO -1, -1, 78
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
# define RG12_GPIO -1, -1, 79
# define RG13_GPIO -1, -1, 80
# define RG14_GPIO -1, -1, 81
# define RG15_GPIO -1, -1, 82

#elif defined(__PIC24FJ64ga010__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ96ga010__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ128ga010__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ64gb110__)
# define RA0_GPIO -1, -1, 33
# define RA1_GPIO -1, -1, 34
# define RA2_GPIO -1, -1, 35
# define RA3_GPIO -1, -1, 36
# define RA4_GPIO -1, -1, 37
# define RA5_GPIO -1, -1, 38
# define RA6_GPIO -1, -1, 39
# define RA7_GPIO -1, -1, 40
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC2_GPIO -1, -1, 46
# define RC3_GPIO -1, -1, 47
# define RC4_GPIO -1, -1, 48
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RF12_GPIO -1, -1, 75
# define RF13_GPIO -1, -1, 76
# define RG0_GPIO -1, -1, 77
# define RG1_GPIO -1, -1, 78
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
# define RG12_GPIO -1, -1, 79
# define RG13_GPIO -1, -1, 80
# define RG14_GPIO -1, -1, 81
# define RG15_GPIO -1, -1, 82

#elif defined(__PIC24FJ128gb110__)
# define RA0_GPIO -1, -1, 33
# define RA1_GPIO -1, -1, 34
# define RA2_GPIO -1, -1, 35
# define RA3_GPIO -1, -1, 36
# define RA4_GPIO -1, -1, 37
# define RA5_GPIO -1, -1, 38
# define RA6_GPIO -1, -1, 39
# define RA7_GPIO -1, -1, 40
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC2_GPIO -1, -1, 46
# define RC3_GPIO -1, -1, 47
# define RC4_GPIO -1, -1, 48
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RF12_GPIO -1, -1, 75
# define RF13_GPIO -1, -1, 76
# define RG0_GPIO -1, -1, 77
# define RG1_GPIO -1, -1, 78
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
# define RG12_GPIO -1, -1, 79
# define RG13_GPIO -1, -1, 80
# define RG14_GPIO -1, -1, 81
# define RG15_GPIO -1, -1, 82

#elif defined(__PIC24FJ192gb110__)
# define RA0_GPIO -1, -1, 33
# define RA1_GPIO -1, -1, 34
# define RA2_GPIO -1, -1, 35
# define RA3_GPIO -1, -1, 36
# define RA4_GPIO -1, -1, 37
# define RA5_GPIO -1, -1, 38
# define RA6_GPIO -1, -1, 39
# define RA7_GPIO -1, -1, 40
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC2_GPIO -1, -1, 46
# define RC3_GPIO -1, -1, 47
# define RC4_GPIO -1, -1, 48
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RF12_GPIO -1, -1, 75
# define RF13_GPIO -1, -1, 76
# define RG0_GPIO -1, -1, 77
# define RG1_GPIO -1, -1, 78
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
# define RG12_GPIO -1, -1, 79
# define RG13_GPIO -1, -1, 80
# define RG14_GPIO -1, -1, 81
# define RG15_GPIO -1, -1, 82

#elif defined(__PIC24FJ256gb110__)
# define RA0_GPIO -1, -1, 33
# define RA1_GPIO -1, -1, 34
# define RA2_GPIO -1, -1, 35
# define RA3_GPIO -1, -1, 36
# define RA4_GPIO -1, -1, 37
# define RA5_GPIO -1, -1, 38
# define RA6_GPIO -1, -1, 39
# define RA7_GPIO -1, -1, 40
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC2_GPIO -1, -1, 46
# define RC3_GPIO -1, -1, 47
# define RC4_GPIO -1, -1, 48
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RF12_GPIO -1, -1, 75
# define RF13_GPIO -1, -1, 76
# define RG0_GPIO -1, -1, 77
# define RG1_GPIO -1, -1, 78
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
# define RG12_GPIO -1, -1, 79
# define RG13_GPIO -1, -1, 80
# define RG14_GPIO -1, -1, 81
# define RG15_GPIO -1, -1, 82

#elif defined(__PIC24FJ128ga108__)
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC3_GPIO -1, -1, 47
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RF7_GPIO -1, -1, 73
# define RF8_GPIO -1, -1, 74
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ192ga108__)
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC3_GPIO -1, -1, 47
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RF7_GPIO -1, -1, 73
# define RF8_GPIO -1, -1, 74
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ256ga108__)
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC3_GPIO -1, -1, 47
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF6_GPIO -1, -1, 72
# define RF7_GPIO -1, -1, 73
# define RF8_GPIO -1, -1, 74
# define RG2_GPIO -1, -1, 83
# define RG3_GPIO -1, -1, 84
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ64ga008__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ96ga008__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ128ga008__)
# define RB0_GPIO -1, 0, 2
# define RB1_GPIO -1, 1, 3
# define RB2_GPIO -1, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO -1, 4, 6
# define RB5_GPIO -1, 5, 7
# define RB6_GPIO -1, 6, -1
# define RB7_GPIO -1, 7, -1
# define RB8_GPIO -1, 8, -1
# define RB9_GPIO -1, 9, -1
# define RB10_GPIO -1, 10, -1
# define RB11_GPIO -1, 11, -1
# define RB12_GPIO -1, 12, -1
# define RB13_GPIO -1, 13, -1
# define RB14_GPIO -1, 14, -1
# define RB15_GPIO -1, 15, 12
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ64gb108__)
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC3_GPIO -1, -1, 47
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ128gb108__)
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC3_GPIO -1, -1, 47
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ192gb108__)
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC3_GPIO -1, -1, 47
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11

#elif defined(__PIC24FJ256gb108__)
# define RA9_GPIO -1, -1, 41
# define RA10_GPIO -1, -1, 42
# define RA14_GPIO -1, -1, 43
# define RA15_GPIO -1, -1, 44
# define RB0_GPIO 0, 0, 2
# define RB1_GPIO 1, 1, 3
# define RB2_GPIO 13, 2, 4
# define RB3_GPIO -1, 3, 5
# define RB4_GPIO 28, 4, 6
# define RB5_GPIO 18, 5, 7
# define RB6_GPIO 6, 6, 24
# define RB7_GPIO 7, 7, 25
# define RB8_GPIO 8, 8, 26
# define RB9_GPIO 9, 9, 27
# define RB10_GPIO -1, 10, 28
# define RB11_GPIO -1, 11, 29
# define RB12_GPIO -1, 12, 30
# define RB13_GPIO -1, 13, 31
# define RB14_GPIO 14, 14, 32
# define RB15_GPIO 29, 15, 12
# define RC1_GPIO -1, -1, 45
# define RC3_GPIO -1, -1, 47
# define RC12_GPIO -1, -1, 23
# define RC13_GPIO -1, -1, 1
# define RC14_GPIO -1, -1, 0
# define RC15_GPIO -1, -1, 22
# define RD0_GPIO -1, -1, 49
# define RD1_GPIO -1, -1, 50
# define RD2_GPIO -1, -1, 51
# define RD3_GPIO -1, -1, 52
# define RD4_GPIO -1, -1, 13
# define RD5_GPIO -1, -1, 14
# define RD6_GPIO -1, -1, 15
# define RD7_GPIO -1, -1, 16
# define RD8_GPIO -1, -1, 53
# define RD9_GPIO -1, -1, 54
# define RD10_GPIO -1, -1, 55
# define RD11_GPIO -1, -1, 56
# define RD12_GPIO -1, -1, 57
# define RD13_GPIO -1, -1, 19
# define RD14_GPIO -1, -1, 20
# define RD15_GPIO -1, -1, 21
# define RE0_GPIO -1, -1, 58
# define RE1_GPIO -1, -1, 59
# define RE2_GPIO -1, -1, 60
# define RE3_GPIO -1, -1, 61
# define RE4_GPIO -1, -1, 62
# define RE5_GPIO -1, -1, 63
# define RE6_GPIO -1, -1, 64
# define RE7_GPIO -1, -1, 65
# define RE8_GPIO -1, -1, 66
# define RE9_GPIO -1, -1, 67
# define RF0_GPIO -1, -1, 68
# define RF1_GPIO -1, -1, 69
# define RF2_GPIO -1, -1, 70
# define RF3_GPIO -1, -1, 71
# define RF4_GPIO -1, -1, 17
# define RF5_GPIO -1, -1, 18
# define RF8_GPIO -1, -1, 74
# define RG6_GPIO -1, -1, 8
# define RG7_GPIO -1, -1, 9
# define RG8_GPIO -1, -1, 10
# define RG9_GPIO -1, -1, 11
#else
# error "Port information not defined."
#endif
