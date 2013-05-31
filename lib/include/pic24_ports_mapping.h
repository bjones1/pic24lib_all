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

#elif defined(__PIC24EP32MC503__) || \
      defined(__dsPIC33EP32MC503__) || \
      defined(__dsPIC33EP64MC503__) || \
      defined(__dsPIC33EP64MC203__) || \
      defined(__dsPIC33EP32GP503__) || \
      defined(__PIC24EP64MC503__) || \
      defined(__PIC24EP32GP203__) || \
      defined(__dsPIC33EP64GP503__) || \
      defined(__PIC24EP64MC203__) || \
      defined(__PIC24EP64GP203__) || \
      defined(__dsPIC33EP32MC203__) || \
      defined(__PIC24EP32MC203__)
# define RA0_AN 0
# define RA1_AN 1
# define RB0_AN 2
# define RB1_AN 3
# define RB2_AN 4
# define RB3_AN 5
# define RC0_AN 6
# define RC1_AN 7

#elif defined(__dsPIC33EP512GP504__) || \
      defined(__dsPIC33EP256GP504__) || \
      defined(__dsPIC33EP64GP504__) || \
      defined(__dsPIC33EP256MC504__) || \
      defined(__dsPIC33EP32MC204__) || \
      defined(__dsPIC33EP256MC204__) || \
      defined(__PIC24EP256MC204__) || \
      defined(__dsPIC33EP512MC504__) || \
      defined(__PIC24EP64GP204__) || \
      defined(__dsPIC33EP128MC504__) || \
      defined(__PIC24EP128MC204__) || \
      defined(__PIC24EP512GP204__) || \
      defined(__dsPIC33EP128GP504__) || \
      defined(__dsPIC33EP128MC204__) || \
      defined(__PIC24EP32GP204__) || \
      defined(__dsPIC33EP512MC204__) || \
      defined(__dsPIC33EP64MC504__) || \
      defined(__dsPIC33EP64MC204__) || \
      defined(__PIC24EP128GP204__) || \
      defined(__PIC24EP512MC204__) || \
      defined(__PIC24EP32MC204__) || \
      defined(__dsPIC33EP32MC504__) || \
      defined(__PIC24EP256GP204__) || \
      defined(__dsPIC33EP32GP504__) || \
      defined(__PIC24EP64MC204__)
# define RA0_AN 0
# define RA1_AN 1
# define RB0_AN 2
# define RB1_AN 3
# define RB2_AN 4
# define RB3_AN 5
# define RC0_AN 6
# define RC1_AN 7
# define RC2_AN 8

#elif defined(__PIC24EP64GP202__) || \
      defined(__dsPIC33EP64MC502__) || \
      defined(__PIC24EP64MC202__) || \
      defined(__dsPIC33EP64MC202__) || \
      defined(__dsPIC33EP64GP502__)
# define RA0_AN 0
# define RA1_AN 1
# define RB0_AN 2
# define RB1_AN 3
# define RB2_AN 4
# define RB3_AN 5

#elif defined(__PIC24EP256GP206__) || \
      defined(__dsPIC33EP128GP506__) || \
      defined(__dsPIC33EP128MC506__) || \
      defined(__dsPIC33EP256GP506__) || \
      defined(__dsPIC33EP512GP506__) || \
      defined(__dsPIC33EP256MC206__) || \
      defined(__dsPIC33EP64GP506__) || \
      defined(__PIC24EP256MC206__) || \
      defined(__dsPIC33EP64MC506__) || \
      defined(__dsPIC33EP256MC506__) || \
      defined(__PIC24EP128GP206__) || \
      defined(__dsPIC33EP64MC206__) || \
      defined(__dsPIC33EP512MC506__) || \
      defined(__dsPIC33EP512MC206__) || \
      defined(__PIC24EP512MC206__) || \
      defined(__PIC24EP64MC206__) || \
      defined(__dsPIC33EP128MC206__) || \
      defined(__PIC24EP128MC206__) || \
      defined(__PIC24EP64GP206__) || \
      defined(__PIC24EP512GP206__)
# define RA0_AN 0
# define RA1_AN 1
# define RA11_AN 9
# define RA12_AN 10
# define RB0_AN 2
# define RB1_AN 3
# define RB2_AN 4
# define RB3_AN 5
# define RC0_AN 6
# define RC1_AN 7
# define RC2_AN 8
# define RC11_AN 11
# define RE12_AN 12
# define RE13_AN 13
# define RE14_AN 14
# define RE15_AN 15

#elif defined(__PIC24F16KA102__)
# define RA0_AN 0
# define RA0_CN 2
# define RA1_AN 1
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_AN 2
# define RB0_CN 4
# define RB1_AN 3
# define RB1_CN 5
# define RB2_AN 4
# define RB2_CN 6
# define RB3_AN 5
# define RB3_CN 7
# define RB4_CN 1
# define RB5_CN 27
# define RB6_CN 24
# define RB7_CN 23
# define RB8_CN 22
# define RB9_CN 21
# define RB10_CN 16
# define RB11_CN 15
# define RB12_AN 12
# define RB12_CN 14
# define RB13_AN 11
# define RB13_CN 13
# define RB14_AN 10
# define RB14_CN 12
# define RB15_CN 11

#elif defined(__PIC24FJ192GA106__) || \
      defined(__PIC24FJ128GA106__) || \
      defined(__PIC24FJ256GA106__)
# define RB0_RP 0
# define RB0_AN 0
# define RB0_CN 2
# define RB1_RP 1
# define RB1_AN 1
# define RB1_CN 3
# define RB2_RP 13
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_RP 28
# define RB4_AN 4
# define RB4_CN 6
# define RB5_RP 18
# define RB5_AN 5
# define RB5_CN 7
# define RB6_RP 6
# define RB6_AN 6
# define RB6_CN 24
# define RB7_RP 7
# define RB7_AN 7
# define RB7_CN 25
# define RB8_RP 8
# define RB8_AN 8
# define RB8_CN 26
# define RB9_RP 9
# define RB9_AN 9
# define RB9_CN 27
# define RB10_AN 10
# define RB10_CN 28
# define RB11_AN 11
# define RB11_CN 29
# define RB12_AN 12
# define RB12_CN 30
# define RB13_AN 13
# define RB13_CN 31
# define RB14_RP 14
# define RB14_AN 14
# define RB14_CN 32
# define RB15_RP 29
# define RB15_AN 15
# define RB15_CN 12
# define RC12_CN 23
# define RC13_CN 1
# define RC14_CN 0
# define RC15_CN 22
# define RD0_CN 49
# define RD1_CN 50
# define RD2_CN 51
# define RD3_CN 52
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD8_CN 53
# define RD9_CN 54
# define RD10_CN 55
# define RD11_CN 56
# define RE0_CN 58
# define RE1_CN 59
# define RE2_CN 60
# define RE3_CN 61
# define RE4_CN 62
# define RE5_CN 63
# define RE6_CN 64
# define RE7_CN 65
# define RF0_CN 68
# define RF1_CN 69
# define RF2_CN 70
# define RF3_CN 71
# define RF4_CN 17
# define RF5_CN 18
# define RF6_CN 72
# define RG2_CN 83
# define RG3_CN 84
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__PIC24FJ192GA108__) || \
      defined(__PIC24FJ128GA108__) || \
      defined(__PIC24FJ256GA108__)
# define RA9_CN 41
# define RA10_CN 42
# define RA14_CN 43
# define RA15_CN 44
# define RB0_RP 0
# define RB0_AN 0
# define RB0_CN 2
# define RB1_RP 1
# define RB1_AN 1
# define RB1_CN 3
# define RB2_RP 13
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_RP 28
# define RB4_AN 4
# define RB4_CN 6
# define RB5_RP 18
# define RB5_AN 5
# define RB5_CN 7
# define RB6_RP 6
# define RB6_AN 6
# define RB6_CN 24
# define RB7_RP 7
# define RB7_AN 7
# define RB7_CN 25
# define RB8_RP 8
# define RB8_AN 8
# define RB8_CN 26
# define RB9_RP 9
# define RB9_AN 9
# define RB9_CN 27
# define RB10_AN 10
# define RB10_CN 28
# define RB11_AN 11
# define RB11_CN 29
# define RB12_AN 12
# define RB12_CN 30
# define RB13_AN 13
# define RB13_CN 31
# define RB14_RP 14
# define RB14_AN 14
# define RB14_CN 32
# define RB15_RP 29
# define RB15_AN 15
# define RB15_CN 12
# define RC1_CN 45
# define RC3_CN 47
# define RC12_CN 23
# define RC13_CN 1
# define RC14_CN 0
# define RC15_CN 22
# define RD0_CN 49
# define RD1_CN 50
# define RD2_CN 51
# define RD3_CN 52
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD8_CN 53
# define RD9_CN 54
# define RD10_CN 55
# define RD11_CN 56
# define RD12_CN 57
# define RD13_CN 19
# define RD14_CN 20
# define RD15_CN 21
# define RE0_CN 58
# define RE1_CN 59
# define RE2_CN 60
# define RE3_CN 61
# define RE4_CN 62
# define RE5_CN 63
# define RE6_CN 64
# define RE7_CN 65
# define RE8_CN 66
# define RE9_CN 67
# define RF0_CN 68
# define RF1_CN 69
# define RF2_CN 70
# define RF3_CN 71
# define RF4_CN 17
# define RF5_CN 18
# define RF6_CN 72
# define RF7_CN 73
# define RF8_CN 74
# define RG2_CN 83
# define RG3_CN 84
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__PIC24FJ128GA110__) || \
      defined(__PIC24FJ256GA110__) || \
      defined(__PIC24FJ192GA110__)
# define RA0_CN 33
# define RA1_CN 34
# define RA2_CN 35
# define RA3_CN 36
# define RA4_CN 37
# define RA5_CN 38
# define RA6_CN 39
# define RA7_CN 40
# define RA9_CN 41
# define RA10_CN 42
# define RA14_CN 43
# define RA15_CN 44
# define RB0_RP 0
# define RB0_AN 0
# define RB0_CN 2
# define RB1_RP 1
# define RB1_AN 1
# define RB1_CN 3
# define RB2_RP 13
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_RP 28
# define RB4_AN 4
# define RB4_CN 6
# define RB5_RP 18
# define RB5_AN 5
# define RB5_CN 7
# define RB6_RP 6
# define RB6_AN 6
# define RB6_CN 24
# define RB7_RP 7
# define RB7_AN 7
# define RB7_CN 25
# define RB8_RP 8
# define RB8_AN 8
# define RB8_CN 26
# define RB9_RP 9
# define RB9_AN 9
# define RB9_CN 27
# define RB10_AN 10
# define RB10_CN 28
# define RB11_AN 11
# define RB11_CN 29
# define RB12_AN 12
# define RB12_CN 30
# define RB13_AN 13
# define RB13_CN 31
# define RB14_RP 14
# define RB14_AN 14
# define RB14_CN 32
# define RB15_RP 29
# define RB15_AN 15
# define RB15_CN 12
# define RC1_CN 45
# define RC2_CN 46
# define RC3_CN 47
# define RC4_CN 48
# define RC12_CN 23
# define RC13_CN 1
# define RC14_CN 0
# define RC15_CN 22
# define RD0_CN 49
# define RD1_CN 50
# define RD2_CN 51
# define RD3_CN 52
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD8_CN 53
# define RD9_CN 54
# define RD10_CN 55
# define RD11_CN 56
# define RD12_CN 57
# define RD13_CN 19
# define RD14_CN 20
# define RD15_CN 21
# define RE0_CN 58
# define RE1_CN 59
# define RE2_CN 60
# define RE3_CN 61
# define RE4_CN 62
# define RE5_CN 63
# define RE6_CN 64
# define RE7_CN 65
# define RE8_CN 66
# define RE9_CN 67
# define RF0_CN 68
# define RF1_CN 69
# define RF2_CN 70
# define RF3_CN 71
# define RF4_CN 17
# define RF5_CN 18
# define RF6_CN 72
# define RF7_CN 73
# define RF8_CN 74
# define RF12_CN 75
# define RF13_CN 76
# define RG0_CN 77
# define RG1_CN 78
# define RG2_CN 83
# define RG3_CN 84
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11
# define RG12_CN 79
# define RG13_CN 80
# define RG14_CN 81
# define RG15_CN 82

#elif defined(__PIC24FJ32GB002__) || \
      defined(__PIC24FJ64GB002__)
# define RA0_RP 5
# define RA0_AN 0
# define RA0_CN 2
# define RA1_RP 6
# define RA1_AN 1
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_RP 0
# define RB0_AN 2
# define RB0_CN 4
# define RB1_RP 1
# define RB1_AN 3
# define RB1_CN 5
# define RB2_RP 2
# define RB2_AN 4
# define RB2_CN 6
# define RB3_RP 3
# define RB3_AN 5
# define RB3_CN 7
# define RB4_CN 1
# define RB5_CN 27
# define RB7_CN 23
# define RB8_CN 22
# define RB9_CN 21
# define RB10_CN 16
# define RB11_CN 15
# define RB13_RP 13
# define RB13_AN 11
# define RB13_CN 13
# define RB14_RP 14
# define RB14_AN 10
# define RB14_CN 12
# define RB15_RP 15
# define RB15_AN 9
# define RB15_CN 11

#elif defined(__PIC24FJ64GB004__) || \
      defined(__PIC24FJ32GB004__)
# define RA0_CN 2
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_CN 4
# define RB1_CN 5
# define RB2_CN 6
# define RB3_CN 7
# define RB4_CN 1
# define RB5_CN 27
# define RB7_CN 23
# define RB8_CN 18
# define RB9_CN 22
# define RB10_CN 16
# define RB11_CN 15
# define RB13_CN 13
# define RB14_CN 12
# define RB15_CN 11
# define RC0_CN 8
# define RC1_CN 9
# define RC2_CN 10
# define RC3_CN 28
# define RC4_CN 25
# define RC5_CN 26
# define RC6_CN 18
# define RC7_CN 17
# define RC8_CN 20
# define RC9_CN 19

#elif defined(__PIC24FJ64GA006__) || \
      defined(__PIC24FJ96GA006__) || \
      defined(__PIC24FJ128GA006__)
# define RB0_AN 0
# define RB0_CN 2
# define RB1_AN 1
# define RB1_CN 3
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_AN 4
# define RB4_CN 6
# define RB5_AN 5
# define RB5_CN 7
# define RB6_AN 6
# define RB7_AN 7
# define RB8_AN 8
# define RB9_AN 9
# define RB10_AN 10
# define RB11_AN 11
# define RB12_AN 12
# define RB13_AN 13
# define RB14_AN 14
# define RB15_AN 15
# define RB15_CN 12
# define RC13_CN 1
# define RC14_CN 0
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RF4_CN 17
# define RF5_CN 18
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__PIC24FJ96GA010__) || \
      defined(__PIC24FJ128GA010__) || \
      defined(__PIC24FJ64GA008__) || \
      defined(__PIC24FJ96GA008__) || \
      defined(__PIC24FJ128GA008__) || \
      defined(__PIC24FJ64GA010__)
# define RB0_AN 0
# define RB0_CN 2
# define RB1_AN 1
# define RB1_CN 3
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_AN 4
# define RB4_CN 6
# define RB5_AN 5
# define RB5_CN 7
# define RB6_AN 6
# define RB7_AN 7
# define RB8_AN 8
# define RB9_AN 9
# define RB10_AN 10
# define RB11_AN 11
# define RB12_AN 12
# define RB13_AN 13
# define RB14_AN 14
# define RB15_AN 15
# define RB15_CN 12
# define RC13_CN 1
# define RC14_CN 0
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD13_CN 19
# define RD14_CN 20
# define RD15_CN 21
# define RF4_CN 17
# define RF5_CN 18
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__PIC24FJ64GB106__) || \
      defined(__PIC24FJ256GB106__) || \
      defined(__PIC24FJ128GB106__) || \
      defined(__PIC24FJ192GB106__)
# define RB0_RP 0
# define RB0_AN 0
# define RB0_CN 2
# define RB1_RP 1
# define RB1_AN 1
# define RB1_CN 3
# define RB2_RP 13
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_RP 28
# define RB4_AN 4
# define RB4_CN 6
# define RB5_RP 18
# define RB5_AN 5
# define RB5_CN 7
# define RB6_RP 6
# define RB6_AN 6
# define RB6_CN 24
# define RB7_RP 7
# define RB7_AN 7
# define RB7_CN 25
# define RB8_RP 8
# define RB8_AN 8
# define RB8_CN 26
# define RB9_RP 9
# define RB9_AN 9
# define RB9_CN 27
# define RB10_AN 10
# define RB10_CN 28
# define RB11_AN 11
# define RB11_CN 29
# define RB12_AN 12
# define RB12_CN 30
# define RB13_AN 13
# define RB13_CN 31
# define RB14_RP 14
# define RB14_AN 14
# define RB14_CN 32
# define RB15_RP 29
# define RB15_AN 15
# define RB15_CN 12
# define RC12_CN 23
# define RC13_CN 1
# define RC14_CN 0
# define RC15_CN 22
# define RD0_CN 49
# define RD1_CN 50
# define RD2_CN 51
# define RD3_CN 52
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD8_CN 53
# define RD9_CN 54
# define RD10_CN 55
# define RD11_CN 56
# define RE0_CN 58
# define RE1_CN 59
# define RE2_CN 60
# define RE3_CN 61
# define RE4_CN 62
# define RE5_CN 63
# define RE6_CN 64
# define RE7_CN 65
# define RF0_CN 68
# define RF1_CN 69
# define RF3_CN 71
# define RF4_CN 17
# define RF5_CN 18
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__PIC24FJ128GB108__) || \
      defined(__PIC24FJ192GB108__) || \
      defined(__PIC24FJ64GB108__) || \
      defined(__PIC24FJ256GB108__)
# define RA9_CN 41
# define RA10_CN 42
# define RA14_CN 43
# define RA15_CN 44
# define RB0_RP 0
# define RB0_AN 0
# define RB0_CN 2
# define RB1_RP 1
# define RB1_AN 1
# define RB1_CN 3
# define RB2_RP 13
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_RP 28
# define RB4_AN 4
# define RB4_CN 6
# define RB5_RP 18
# define RB5_AN 5
# define RB5_CN 7
# define RB6_RP 6
# define RB6_AN 6
# define RB6_CN 24
# define RB7_RP 7
# define RB7_AN 7
# define RB7_CN 25
# define RB8_RP 8
# define RB8_AN 8
# define RB8_CN 26
# define RB9_RP 9
# define RB9_AN 9
# define RB9_CN 27
# define RB10_AN 10
# define RB10_CN 28
# define RB11_AN 11
# define RB11_CN 29
# define RB12_AN 12
# define RB12_CN 30
# define RB13_AN 13
# define RB13_CN 31
# define RB14_RP 14
# define RB14_AN 14
# define RB14_CN 32
# define RB15_RP 29
# define RB15_AN 15
# define RB15_CN 12
# define RC1_CN 45
# define RC3_CN 47
# define RC12_CN 23
# define RC13_CN 1
# define RC14_CN 0
# define RC15_CN 22
# define RD0_CN 49
# define RD1_CN 50
# define RD2_CN 51
# define RD3_CN 52
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD8_CN 53
# define RD9_CN 54
# define RD10_CN 55
# define RD11_CN 56
# define RD12_CN 57
# define RD13_CN 19
# define RD14_CN 20
# define RD15_CN 21
# define RE0_CN 58
# define RE1_CN 59
# define RE2_CN 60
# define RE3_CN 61
# define RE4_CN 62
# define RE5_CN 63
# define RE6_CN 64
# define RE7_CN 65
# define RE8_CN 66
# define RE9_CN 67
# define RF0_CN 68
# define RF1_CN 69
# define RF2_CN 70
# define RF3_CN 71
# define RF4_CN 17
# define RF5_CN 18
# define RF8_CN 74
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__PIC24FJ256GB110__) || \
      defined(__PIC24FJ128GB110__) || \
      defined(__PIC24FJ64GB110__) || \
      defined(__PIC24FJ192GB110__)
# define RA0_CN 33
# define RA1_CN 34
# define RA2_CN 35
# define RA3_CN 36
# define RA4_CN 37
# define RA5_CN 38
# define RA6_CN 39
# define RA7_CN 40
# define RA9_CN 41
# define RA10_CN 42
# define RA14_CN 43
# define RA15_CN 44
# define RB0_RP 0
# define RB0_AN 0
# define RB0_CN 2
# define RB1_RP 1
# define RB1_AN 1
# define RB1_CN 3
# define RB2_RP 13
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_RP 28
# define RB4_AN 4
# define RB4_CN 6
# define RB5_RP 18
# define RB5_AN 5
# define RB5_CN 7
# define RB6_RP 6
# define RB6_AN 6
# define RB6_CN 24
# define RB7_RP 7
# define RB7_AN 7
# define RB7_CN 25
# define RB8_RP 8
# define RB8_AN 8
# define RB8_CN 26
# define RB9_RP 9
# define RB9_AN 9
# define RB9_CN 27
# define RB10_AN 10
# define RB10_CN 28
# define RB11_AN 11
# define RB11_CN 29
# define RB12_AN 12
# define RB12_CN 30
# define RB13_AN 13
# define RB13_CN 31
# define RB14_RP 14
# define RB14_AN 14
# define RB14_CN 32
# define RB15_RP 29
# define RB15_AN 15
# define RB15_CN 12
# define RC1_CN 45
# define RC2_CN 46
# define RC3_CN 47
# define RC4_CN 48
# define RC12_CN 23
# define RC13_CN 1
# define RC14_CN 0
# define RC15_CN 22
# define RD0_CN 49
# define RD1_CN 50
# define RD2_CN 51
# define RD3_CN 52
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD8_CN 53
# define RD9_CN 54
# define RD10_CN 55
# define RD11_CN 56
# define RD12_CN 57
# define RD13_CN 19
# define RD14_CN 20
# define RD15_CN 21
# define RE0_CN 58
# define RE1_CN 59
# define RE2_CN 60
# define RE3_CN 61
# define RE4_CN 62
# define RE5_CN 63
# define RE6_CN 64
# define RE7_CN 65
# define RE8_CN 66
# define RE9_CN 67
# define RF0_CN 68
# define RF1_CN 69
# define RF2_CN 70
# define RF3_CN 71
# define RF4_CN 17
# define RF5_CN 18
# define RF8_CN 74
# define RF12_CN 75
# define RF13_CN 76
# define RG0_CN 77
# define RG1_CN 78
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11
# define RG12_CN 79
# define RG13_CN 80
# define RG14_CN 81
# define RG15_CN 82

#elif defined(__PIC24HJ32GP202__)
# define RA0_AN 0
# define RA0_CN 2
# define RA1_AN 1
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_RP 0
# define RB0_AN 2
# define RB0_CN 4
# define RB1_RP 1
# define RB1_AN 3
# define RB1_CN 5
# define RB2_RP 2
# define RB2_AN 4
# define RB2_CN 6
# define RB3_RP 3
# define RB3_AN 5
# define RB3_CN 7
# define RB4_RP 4
# define RB4_CN 1
# define RB5_RP 5
# define RB5_CN 27
# define RB6_RP 6
# define RB6_CN 24
# define RB7_RP 7
# define RB7_CN 23
# define RB8_RP 8
# define RB8_CN 22
# define RB9_RP 9
# define RB9_CN 21
# define RB10_RP 10
# define RB10_CN 16
# define RB11_RP 11
# define RB11_CN 15
# define RB12_RP 12
# define RB12_AN 12
# define RB12_CN 14
# define RB13_RP 13
# define RB13_AN 11
# define RB13_CN 13
# define RB14_RP 14
# define RB14_AN 10
# define RB14_CN 12
# define RB15_RP 15
# define RB15_AN 9
# define RB15_CN 11

#elif defined(__PIC24HJ64GP206A__) || \
      defined(__PIC24HJ64GP506__) || \
      defined(__PIC24HJ128GP306__) || \
      defined(__PIC24HJ128GP506A__) || \
      defined(__PIC24HJ128GP206__) || \
      defined(__PIC24HJ64GP206__) || \
      defined(__PIC24HJ128GP306A__) || \
      defined(__PIC24HJ256GP206__) || \
      defined(__PIC24HJ128GP506__) || \
      defined(__PIC24HJ64GP506A__) || \
      defined(__PIC24HJ128GP206A__)
# define RB0_AN 0
# define RB0_CN 2
# define RB1_AN 1
# define RB1_CN 3
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_AN 4
# define RB4_CN 6
# define RB5_AN 5
# define RB5_CN 7
# define RB6_AN 6
# define RB7_AN 7
# define RB8_AN 8
# define RB9_AN 9
# define RB10_AN 10
# define RB11_AN 11
# define RB12_AN 12
# define RB13_AN 13
# define RB14_AN 14
# define RB15_AN 15
# define RB15_CN 12
# define RC1_AN 16
# define RC2_AN 17
# define RC13_CN 1
# define RC14_CN 0
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RF4_CN 17
# define RF5_CN 18
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__PIC24HJ128GP510A__) || \
      defined(__PIC24HJ64GP510A__) || \
      defined(__PIC24HJ128GP210A__) || \
      defined(__PIC24HJ128GP310__) || \
      defined(__PIC24HJ64GP510__) || \
      defined(__PIC24HJ128GP210__) || \
      defined(__PIC24HJ64GP210__) || \
      defined(__PIC24HJ128GP310A__) || \
      defined(__PIC24HJ256GP610__) || \
      defined(__PIC24HJ64GP210A__) || \
      defined(__PIC24HJ256GP210__) || \
      defined(__PIC24HJ128GP510__)
# define RA6_AN 22
# define RA6_CN 22
# define RA7_AN 23
# define RA7_CN 23
# define RA12_AN 20
# define RA13_AN 21
# define RB0_AN 0
# define RB0_CN 2
# define RB1_AN 1
# define RB1_CN 3
# define RB2_AN 2
# define RB2_CN 4
# define RB3_AN 3
# define RB3_CN 5
# define RB4_AN 4
# define RB4_CN 6
# define RB5_AN 5
# define RB5_CN 7
# define RB6_AN 6
# define RB7_AN 7
# define RB8_AN 8
# define RB9_AN 9
# define RB10_AN 10
# define RB11_AN 11
# define RB12_AN 12
# define RB13_AN 13
# define RB14_AN 14
# define RB15_AN 15
# define RB15_CN 12
# define RC1_AN 16
# define RC2_AN 17
# define RC3_AN 18
# define RC4_AN 19
# define RC13_CN 1
# define RC14_CN 0
# define RD4_CN 13
# define RD5_CN 14
# define RD6_CN 15
# define RD7_CN 16
# define RD13_CN 19
# define RD14_CN 20
# define RD15_CN 21
# define RE0_AN 24
# define RE1_AN 25
# define RE2_AN 26
# define RE3_AN 27
# define RE4_AN 28
# define RE5_AN 29
# define RE6_AN 30
# define RE7_AN 31
# define RF4_CN 17
# define RF5_CN 18
# define RG6_CN 8
# define RG7_CN 9
# define RG8_CN 10
# define RG9_CN 11

#elif defined(__dsPIC33EP512GP806__) || \
      defined(__dsPIC33EP512MC806__) || \
      defined(__dsPIC33EP256MU806__) || \
      defined(__dsPIC33EP512MU806__) || \
      defined(__PIC24EP512GP806__)
# define RB0_AN 0
# define RB1_AN 1
# define RB2_AN 2
# define RB3_AN 3
# define RB4_AN 4
# define RB5_AN 5
# define RB6_AN 6
# define RB7_AN 7
# define RB8_AN 8
# define RB9_AN 9
# define RB10_AN 10
# define RB11_AN 11
# define RB12_AN 12
# define RB13_AN 13
# define RB14_AN 14
# define RB15_AN 15
# define RE0_AN 24
# define RE1_AN 25
# define RE2_AN 26
# define RE3_AN 27
# define RE4_AN 28
# define RE5_AN 29
# define RE6_AN 30
# define RE7_AN 31

#elif defined(__PIC24EP256GU810__) || \
      defined(__PIC24EP256GU814__) || \
      defined(__dsPIC33EP256MU814__) || \
      defined(__PIC24EP512GU814__) || \
      defined(__dsPIC33EP512MU814__) || \
      defined(__dsPIC33EP256MU810__) || \
      defined(__dsPIC33EP512MU810__) || \
      defined(__PIC24EP512GU810__)
# define RA6_AN 22
# define RA7_AN 23
# define RB0_AN 0
# define RB1_AN 1
# define RB2_AN 2
# define RB3_AN 3
# define RB4_AN 4
# define RB5_AN 5
# define RB6_AN 6
# define RB7_AN 7
# define RB8_AN 8
# define RB9_AN 9
# define RB10_AN 10
# define RB11_AN 11
# define RB12_AN 12
# define RB13_AN 13
# define RB14_AN 14
# define RB15_AN 15
# define RC1_AN 16
# define RC2_AN 17
# define RC3_AN 18
# define RC4_AN 19
# define RE0_AN 24
# define RE1_AN 25
# define RE2_AN 26
# define RE3_AN 27
# define RE4_AN 28
# define RE5_AN 29
# define RE6_AN 30
# define RE7_AN 31
# define RE8_AN 20
# define RE9_AN 21

#elif defined(__PIC24HJ12GP201__) || \
      defined(__dsPIC33FJ12GP201__)
# define RA0_AN 0
# define RA0_CN 2
# define RA1_AN 1
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_RP 0
# define RB0_AN 2
# define RB0_CN 4
# define RB1_RP 1
# define RB1_AN 3
# define RB1_CN 5
# define RB4_CN 1
# define RB7_CN 23
# define RB8_CN 22
# define RB9_CN 21
# define RB14_RP 14
# define RB14_AN 7
# define RB14_CN 12
# define RB15_RP 15
# define RB15_AN 6
# define RB15_CN 11

#elif defined(__PIC24HJ12GP202__) || \
      defined(__dsPIC33FJ12GP202__)
# define RA0_AN 0
# define RA0_CN 2
# define RA1_AN 1
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_RP 0
# define RB0_AN 2
# define RB0_CN 4
# define RB1_RP 1
# define RB1_AN 3
# define RB1_CN 5
# define RB2_RP 2
# define RB2_AN 4
# define RB2_CN 6
# define RB3_RP 3
# define RB3_AN 5
# define RB3_CN 7
# define RB4_CN 1
# define RB5_CN 27
# define RB6_CN 24
# define RB7_CN 23
# define RB8_CN 22
# define RB9_CN 21
# define RB10_CN 16
# define RB11_CN 15
# define RB12_RP 12
# define RB12_AN 9
# define RB12_CN 14
# define RB13_RP 13
# define RB13_AN 8
# define RB13_CN 13
# define RB14_RP 14
# define RB14_AN 7
# define RB14_CN 12
# define RB15_RP 15
# define RB15_AN 6
# define RB15_CN 11

#elif defined(__PIC24FJ32GA004__) || \
      defined(__PIC24FJ16GA004__) || \
      defined(__dsPIC33FJ64GP804__) || \
      defined(__PIC24HJ32GP204__) || \
      defined(__PIC24FJ64GA104__) || \
      defined(__PIC24FJ32GA104__) || \
      defined(__PIC24HJ64GP204__) || \
      defined(__PIC24HJ64GP504__) || \
      defined(__PIC24FJ48GA004__) || \
      defined(__dsPIC33FJ32GP304__) || \
      defined(__PIC24HJ16GP304__) || \
      defined(__dsPIC33FJ16GP304__) || \
      defined(__dsPIC33FJ128GP804__) || \
      defined(__dsPIC33FJ64GP204__) || \
      defined(__PIC24HJ128GP204__) || \
      defined(__PIC24HJ128GP504__) || \
      defined(__dsPIC33FJ32GP204__) || \
      defined(__PIC24FJ64GA004__) || \
      defined(__dsPIC33FJ128GP204__) || \
      defined(__PIC24HJ32GP304__)
# define RA0_AN 0
# define RA0_CN 2
# define RA1_AN 1
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_RP 0
# define RB0_AN 2
# define RB0_CN 4
# define RB1_RP 1
# define RB1_AN 3
# define RB1_CN 5
# define RB2_RP 2
# define RB2_AN 4
# define RB2_CN 6
# define RB3_RP 3
# define RB3_AN 5
# define RB3_CN 7
# define RB4_CN 1
# define RB5_CN 27
# define RB6_CN 24
# define RB7_CN 23
# define RB8_CN 22
# define RB9_CN 21
# define RB10_CN 16
# define RB11_CN 15
# define RB12_CN 14
# define RB13_RP 13
# define RB13_AN 11
# define RB13_CN 13
# define RB14_RP 14
# define RB14_AN 10
# define RB14_CN 12
# define RB15_RP 15
# define RB15_AN 9
# define RB15_CN 11
# define RC0_RP 16
# define RC0_AN 6
# define RC0_CN 8
# define RC1_RP 17
# define RC1_AN 7
# define RC1_CN 9
# define RC2_RP 18
# define RC2_AN 8
# define RC2_CN 10
# define RC3_CN 28
# define RC4_CN 25
# define RC5_CN 26
# define RC6_CN 18
# define RC7_CN 17
# define RC8_CN 20
# define RC9_CN 19

#elif defined(__dsPIC33FJ64GP802__) || \
      defined(__PIC24FJ16GA002__) || \
      defined(__PIC24HJ128GP202__) || \
      defined(__PIC24FJ32GA002__) || \
      defined(__PIC24HJ64GP502__) || \
      defined(__PIC24FJ32GA102__) || \
      defined(__PIC24FJ64GA102__) || \
      defined(__dsPIC33FJ128GP202__) || \
      defined(__dsPIC33FJ128GP802__) || \
      defined(__PIC24HJ64GP202__) || \
      defined(__PIC24FJ48GA002__) || \
      defined(__dsPIC33FJ32GP302__) || \
      defined(__dsPIC33FJ64GP202__) || \
      defined(__PIC24HJ32GP302__) || \
      defined(__PIC24FJ64GA002__) || \
      defined(__PIC24HJ128GP502__) || \
      defined(__dsPIC33FJ32GP202__)
# define RA0_AN 0
# define RA0_CN 2
# define RA1_AN 1
# define RA1_CN 3
# define RA2_CN 30
# define RA3_CN 29
# define RA4_CN 0
# define RB0_RP 0
# define RB0_AN 2
# define RB0_CN 4
# define RB1_RP 1
# define RB1_AN 3
# define RB1_CN 5
# define RB2_RP 2
# define RB2_AN 4
# define RB2_CN 6
# define RB3_RP 3
# define RB3_AN 5
# define RB3_CN 7
# define RB4_CN 1
# define RB5_CN 27
# define RB6_CN 24
# define RB7_CN 23
# define RB8_CN 22
# define RB9_CN 21
# define RB10_CN 16
# define RB11_CN 15
# define RB12_RP 12
# define RB12_AN 12
# define RB12_CN 14
# define RB13_RP 13
# define RB13_AN 11
# define RB13_CN 13
# define RB14_RP 14
# define RB14_AN 10
# define RB14_CN 12
# define RB15_RP 15
# define RB15_AN 9
# define RB15_CN 11
#else
# error "Port information not defined."
#endif
