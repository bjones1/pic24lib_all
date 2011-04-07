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

#include "pic24_all.h"
#include <stdio.h>

/** \file
 * Test the ASEE board
 *
 *
*/

#define VREF 3.3  //assume Vref = 3.3 volts

/// LED1
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1  _LATB14     //led1 state


/// LED2
#define CONFIG_LED2() CONFIG_RB0_AS_DIG_OUTPUT()
#define LED2  _LATB0     //led2 state

/// LED3
#define CONFIG_LED3() CONFIG_RB1_AS_DIG_OUTPUT()
#define LED3  _LATB1     //led3 state

/// Switch1 configuration
inline void CONFIG_SW1()  {
  CONFIG_RB13_AS_DIG_INPUT();     //use RB13 for switch input
  ENABLE_RB13_PULLUP();           //enable the pullup
}
#define SW1              _RB13  //switch state
#define SW1_PRESSED()   SW1==0  //switch test
#define SW1_RELEASED()  SW1==1  //switch test

/// Switch2 configuration
inline void CONFIG_SW2()  {
  CONFIG_RB12_AS_DIG_INPUT();     //use RB13 for switch input
  ENABLE_RB12_PULLUP();           //enable the pullup
}
#define SW2              _RB12  //switch state
#define SW2_PRESSED()   SW2==0  //switch test
#define SW2_RELEASED()  SW2==1  //switch test

void getSW1PR(void) {
  while(SW1_RELEASED()) {
    doHeartbeat();
  }
  while(SW1_PRESSED()) {
    doHeartbeat();
  }
}

void ledSWtest(void) {

  outString("Connect LED3 to RB1 with a wire jumper, any key continues.\n");
  inChar();
  CONFIG_SW1();
  CONFIG_SW2();
  CONFIG_LED1();
  CONFIG_LED2();
  CONFIG_LED3();
  outString("LED1 is blinking, press SW1 to stop\n");
  while(SW1_RELEASED()) {
    LED1 = !LED1;
    DELAY_MS(100);
    doHeartbeat();
  }
  LED1 = 0;
  while(SW1_PRESSED()) doHeartbeat();
  outString("LED2 is blinking, press SW2 to stop\n");
  while(SW2_RELEASED()) {
    LED2 = !LED2;
    DELAY_MS(100);
    doHeartbeat();
  }
  while(SW2_PRESSED()) doHeartbeat();
  LED2 = 0;

  outString("LED3 is blinking, press SW1 to stop\n");
  while(SW1_RELEASED()) {
    LED3 = !LED3;
    DELAY_MS(100);
    doHeartbeat();
  }
  LED3 = 1;
  outString("LED/Switch Test completed\n");
}

void lm60Test(void) {
  uint16_t u16_adcVal,f_tempC,f_tempF;
  float f_adcVal;
  CONFIG_AN0_AS_ANALOG();
  // Configure A/D to sample AN0 for 31 Tad periods in 12-bit mode
  // then perform a single conversion.
  configADC1_ManualCH0(ADC_CH0_POS_SAMPLEA_AN0, 31, 1);
  outString("Jumper LM60 to AN0, any key continues. Once test starts, any key exits\n");
  inChar();
  while(!IS_CHAR_READY_UART1()) {
    u16_adcVal = convertADC1();   //get ADC value
    f_adcVal = u16_adcVal;
    f_adcVal = f_adcVal/4096.0 * VREF;  //convert to float in range 0.0 to VREF
    f_tempC = (f_adcVal - 0.424)/0.00625;
    f_tempF = f_tempC*9/5 + 32;
    printf("ADC input: %4.3f V, Temp: %4.4f (C), %4.4f (F) \n", (double) f_adcVal,
           (double)f_tempC, (double) f_tempF);
    DELAY_MS(300);   //delay so that we do not flood the UART.
    doHeartbeat();
  }
  inChar();
  outString("LM60 test completed\n");
}




void anaPotTest(void) {
  uint16_t u16_adcVal;
  float f_adcVal;
  CONFIG_AN0_AS_ANALOG();
  // Configure A/D to sample AN0 for 31 Tad periods in 12-bit mode
  // then perform a single conversion.
  configADC1_ManualCH0(ADC_CH0_POS_SAMPLEA_AN0, 31, 1);
  outString("Jumper analog Pot to AN0, any key continues. Once test starts, any key exits\n");
  inChar();
  while(!IS_CHAR_READY_UART1()) {
    u16_adcVal = convertADC1();   //get ADC value
    f_adcVal = u16_adcVal;
    f_adcVal = f_adcVal/4096.0 * VREF;  //convert to float in range 0.0 to VREF
    printf("ADC input: %4.2f V (0x%04x)\n", (double) f_adcVal, u16_adcVal);
    DELAY_MS(300);   //delay so that we do not flood the UART.
    doHeartbeat();
  }
  inChar();
  outString("Analog Potentiometer test completed\n");
}

#define CONFIG_POT_ENABLE()  CONFIG_RB1_AS_DIG_OUTPUT()
#define POT_ENABLE()        _LATB1 = 0  //low true assertion
#define POT_DISABLE()       _LATB1 = 1

void configSPI1(void) {
  //spi clock = 40MHz/1*4 = 40MHz/4 = 10MHz
  SPI1CON1 = SEC_PRESCAL_1_1 |     //1:1 secondary prescale
             PRI_PRESCAL_4_1 |     //4:1 primary prescale
             CLK_POL_ACTIVE_HIGH | //clock active high (CKP = 0)
             SPI_CKE_ON          | //out changes active to inactive (CKE=1)
             SPI_MODE8_ON        | //8-bit mode
             MASTER_ENABLE_ON;     //master mode
  SPI1STATbits.SPIEN = 1;  //enable SPI mode
  //configure pins. Only need SDO, SCLK since POT is output only
  CONFIG_SDO1_TO_RP(6);      //use RP6 for SDO
  CONFIG_RP6_AS_DIG_PIN();   //ensure that analog is disabled
  CONFIG_SCK1OUT_TO_RP(7);   //use RP7 for SCLK
  CONFIG_RP7_AS_DIG_PIN();   //ensure that analog is disabled
  CONFIG_SDI1_TO_RP(5);      //use RP5 for SDI
  CONFIG_RP5_AS_DIG_PIN();   //Ensure that analog is disabled
}

#define POT_STEPS 256

uint8_t testPotVoltage (uint8_t u8_i) {
  uint16_t u16_adcVal;
  float f_adcVal;
  float f_potVal;
  float f_err, f_tol;
  uint8_t rval;

  rval = 0;
  //set POT wiper
  POT_ENABLE();         //assert MCP41xxx chipselect
  ioMasterSPI1(0x11);   //command byte to select wiper register
  ioMasterSPI1(u8_i);
  POT_DISABLE();        //negate MCP41xxx chipselect

  DELAY_MS(1); //settle
  u16_adcVal = convertADC1();   //get ADC value
  f_adcVal = u16_adcVal;
  f_adcVal = f_adcVal/4096.0 * VREF;
  f_potVal = VREF*u8_i/POT_STEPS;
  f_err = f_adcVal - f_potVal;
  f_tol = VREF/(POT_STEPS/2); //make this loose, not using a stable voltage reference
  if (f_err < 0) f_err = 0 - f_err;
  if (f_err > f_tol) {
    printf("Digital pot test failed, Setting: %u, Expected: %4.2f V, Actual: %4.2f V, Diff; %4.4f V\n",
           (uint16_t) u8_i,(double) f_potVal, (double) f_adcVal,(double) f_err);
    rval = 1;
  }
  return(rval);
}

#define POT_STEP_TEST 50
void digPotTest(void) {

  uint16_t u16_setting;
  uint8_t u8_rval;

  CONFIG_POT_ENABLE();       //chip select for MCP41xxx
  POT_DISABLE();             //disable the chip select
  CONFIG_AN1_AS_ANALOG();
  // Configure A/D to sample AN0 for 31 Tad periods in 12-bit mode
  // then perform a single conversion.
  configADC1_ManualCH0(ADC_CH0_POS_SAMPLEA_AN1, 31, 1);
  outString("Jumper digital Pot to AN1, any key continues. Once test starts, any key exits\n");
  inChar();
  u16_setting = POT_STEP_TEST;
  u8_rval = 0;
  while (u16_setting < POT_STEPS) {
    u8_rval |= testPotVoltage(u16_setting);
    u16_setting += POT_STEP_TEST;
  }
  if (!u8_rval) outString("Digital pot test passed!\n");
}


#define CONFIG_DAC_ENABLE() CONFIG_RB3_AS_DIG_OUTPUT()
#define DAC_ENABLE()        _LATB3 = 0  //low true assertion
#define DAC_DISABLE()       _LATB3 = 1

#define DAC_STEPS 256

uint8_t testDACVoltage (uint8_t u8_i) {
  uint16_t u16_adcVal;
  float f_adcVal;
  float f_dacVal;
  float f_err, f_tol;
  uint8_t rval;

  rval = 0;
  //set DAC value
  DAC_ENABLE();         //assert MAX548 chipselect
  ioMasterSPI1(0b00001001);      //control byte that enables DAC A
  ioMasterSPI1(u8_i);          //write DAC value
  DAC_DISABLE();        //negate MAX548 chipselect

  DELAY_MS(1); //settle
  u16_adcVal = convertADC1();   //get ADC value
  f_adcVal = u16_adcVal;
  f_adcVal = f_adcVal/1024.0 * VREF;
  f_dacVal = VREF*u8_i/DAC_STEPS;
  f_err = f_adcVal - f_dacVal;
  f_tol = (VREF/(DAC_STEPS))*4;  //make this loose, not using a stable voltage reference
  if (f_err < 0) f_err = 0 - f_err;
  if (f_err > f_tol) {
    printf("SPI DAC test failed, Setting: %u, Expected: %4.2f V, Actual: %4.2f V, Diff; %4.4f V\n",
           (uint16_t) u8_i,(double) f_dacVal, (double) f_adcVal,(double) f_err);
    rval = 1;
  }
  return(rval);
}




#define DAC_STEP_TEST 50
void spiDACTest(void) {

  uint16_t u16_setting;
  uint8_t u8_rval;

  CONFIG_DAC_ENABLE();       //chip select for MAX548
  DAC_DISABLE();             //disable the chip select
  CONFIG_AN1_AS_ANALOG();
  // Configure A/D to sample AN0 for 31 Tad periods in 12-bit mode
  // then perform a single conversion.
  configADC1_ManualCH0(ADC_CH0_POS_SAMPLEA_AN1, 31, 0);
  outString("Jumper DAC output to AN1, any key continues. Once test starts, any key exits\n");
  inChar();
  u16_setting = POT_STEP_TEST;
  u8_rval = 0;
  while (u16_setting < POT_STEPS) {
    u8_rval |= testDACVoltage(u16_setting);
    u16_setting += POT_STEP_TEST;
  }
  if (!u8_rval) outString("SPI DAC test passed!\n");
}

#define EEPROM 0xA0   //LC515 address assuming both address pins tied low.
#define BLKSIZE 64

//Assumes WDT is configured for longer than EEPROM write time
void waitForWriteCompletion(uint8_t u8_i2cAddr) {
  uint8_t u8_ack, u8_savedSWDTEN;
  u8_savedSWDTEN = _SWDTEN;
  _SWDTEN = 1; //enable WDT so that do not get stuck in infinite loop!
  u8_i2cAddr = I2C_WADDR(u8_i2cAddr);  //write operation, R/W# = 0;
  do {
    startI2C1();
    u8_ack = putNoAckCheckI2C1(u8_i2cAddr);
    stopI2C1();
  } while (u8_ack == I2C_NAK);
  _SWDTEN = u8_savedSWDTEN;  //restore WDT to original state
}

void memWriteLC515(uint8_t u8_i2cAddr,  uint16_t u16_MemAddr, uint8_t *pu8_buf) {
  uint8_t u8_AddrLo, u8_AddrHi;

  u8_AddrLo = u16_MemAddr & 0x00FF;
  u8_AddrHi = (u16_MemAddr >> 8);
  pu8_buf[0] = u8_AddrHi;   //place address into buffer
  pu8_buf[1] = u8_AddrLo;

  if (u16_MemAddr & 0x8000) {
    // if MSB set , set block select bit
    u8_i2cAddr = u8_i2cAddr | 0x08;
  }
  waitForWriteCompletion(u8_i2cAddr);
  writeNI2C1(u8_i2cAddr,pu8_buf,BLKSIZE+2);
}

void memReadLC515(uint8_t u8_i2cAddr,  uint16_t u16_MemAddr, uint8_t *pu8_buf) {

  uint8_t u8_AddrLo, u8_AddrHi;

  u8_AddrLo = u16_MemAddr & 0x00FF;
  u8_AddrHi = (u16_MemAddr >> 8);

  if (u16_MemAddr & 0x8000) {
    // if MSB set , set block select bit
    u8_i2cAddr = u8_i2cAddr | 0x08;
  }
  waitForWriteCompletion(u8_i2cAddr);
  //set address counter
  write2I2C1(u8_i2cAddr,u8_AddrHi, u8_AddrLo);
  //read data
  readNI2C1(u8_i2cAddr,pu8_buf, BLKSIZE);
}

uint8_t au8_buf[64+2];  //2 extra bytes for address
uint8_t au8_rbuf[64+2];  //2 extra bytes for address

uint8_t checkEEPROMBlock(uint16_t u16_address) {
  uint8_t u8_i, u8_rval;
  memWriteLC515(EEPROM,u16_address, au8_buf);  //write
  memReadLC515(EEPROM,u16_address,au8_rbuf); //read
//compare
  u8_rval = 0;
  for (u8_i=0; u8_i<64; u8_i++) {
    if (au8_buf[u8_i+2] != au8_rbuf[u8_i]) {
      u8_rval = 1;
      break;
    }
  }
  return(u8_rval);
}

void testEEPROM() {
  uint8_t u8_i;

  //first write zeros to first two blocks in memory
  for (u8_i=2; u8_i<66; u8_i++) au8_buf[u8_i] = 0;
  if (checkEEPROMBlock(0)) goto EEPROM_FAIL;
  if (checkEEPROMBlock(64)) goto EEPROM_FAIL;
  //now try non-zero data
  for (u8_i=2; u8_i<66; u8_i++) au8_buf[u8_i] = u8_i;
  if (checkEEPROMBlock(0)) goto EEPROM_FAIL;
  if (checkEEPROMBlock(64)) goto EEPROM_FAIL;
  outString("I2C EEPROM test passed!\n");
  return;

EEPROM_FAIL:
  outString("I2C EEPROM test failed\n");
  return;
}

#define CONFIG_DS1722_ENABLE() CONFIG_RB2_AS_DIG_OUTPUT()
#define DS1722_ENABLE()        _LATB2 = 1  //high true assertion
#define DS1722_DISABLE()       _LATB2 = 0

void writeConfigDS1722(uint8_t u8_i) {
  DS1722_ENABLE();       //assert chipselect
  ioMasterSPI1(0x80);   //config address
  ioMasterSPI1(u8_i);   //config value
  DS1722_DISABLE();
}

int16_t readTempDS1722() {
  uint16_t u16_lo, u16_hi;

  DS1722_ENABLE();       //assert chipselect
  ioMasterSPI1(0x01);   //LSB address
  u16_lo = ioMasterSPI1(0x00); //read LSByte
  u16_hi = ioMasterSPI1(0x00); //read MSByte
  DS1722_DISABLE();
  return((u16_hi<<8) | u16_lo);
}

void testDS1722 (void) {
  int16_t i16_temp;
  float  f_tempC,f_tempF;

  SPI1STATbits.SPIEN = 0;  //enable SPI mode
  SPI1CON1 = SEC_PRESCAL_1_1 |     //1:1 secondary prescale
             PRI_PRESCAL_4_1 |     //4:1 primary prescale
             CLK_POL_ACTIVE_HIGH   | //clock active high (CKP = 0)
             SPI_CKE_OFF          | //out changes inactive to active (CKE=0)
             SPI_MODE8_ON        | //8-bit mode
             MASTER_ENABLE_ON;     //master mode
  SPI1STATbits.SPIEN = 1;
  CONFIG_DS1722_ENABLE();
  DS1722_DISABLE();
  outString("Any key exits\n");
  writeConfigDS1722(0xE8); //12-bit mode
  while(!IS_CHAR_READY_UART1()) {
    DELAY_MS(1500);
    i16_temp = readTempDS1722();
    f_tempC = i16_temp;  //convert to floating point
    f_tempC = f_tempC/256;  //divide by precision
    f_tempF = f_tempC*9/5 + 32;
    printf("Temp is: 0x%0X, %4.4f (C), %4.4f (F)\n", i16_temp,
           (double) f_tempC, (double) f_tempF);
  }
  inChar();
}

#define DS1631ADDR 0x90   //DS1631 address with all pins tied low
#define ACCESS_CONFIG 0xAC
#define START_CONVERT 0x51
#define STOP_CONVERT 0x22
#define READ_TEMP 0xAA
#define TH_REG 0xA1
#define TL_REG 0xA2

void startConversionDS1631() {
  write1I2C1(DS1631ADDR, START_CONVERT);
}

void writeConfigDS1631(uint8_t u8_i) {
  write2I2C1(DS1631ADDR, ACCESS_CONFIG, u8_i);
}

int16_t readTempDS1631() {
  uint8_t u8_lo, u8_hi;
  int16_t i16_temp;
  write1I2C1(DS1631ADDR, READ_TEMP);
  read2I2C1 (DS1631ADDR, &u8_hi, &u8_lo);
  i16_temp = u8_hi;
  return ((i16_temp<<8)|u8_lo);
}

void testDS1631 (void) {
  int16_t i16_temp;
  float  f_tempC,f_tempF;

  startConversionDS1631();
  writeConfigDS1631(0x0C);    //continuous conversion, 12-bit mode
  while(!IS_CHAR_READY_UART1()) {
    DELAY_MS(750);
    i16_temp = readTempDS1631();
    f_tempC = i16_temp;  //convert to floating point
    f_tempC = f_tempC/256;  //divide by precision
    f_tempF = f_tempC*9/5 + 32;
    printf("Temp is: 0x%0X, %4.4f (C), %4.4f (F)\n", i16_temp, (double) f_tempC, (double) f_tempF);
  }
  inChar();
}

volatile uint16_t u16_seconds = 0;

//Interrupt Service Routine for Timer1
void _ISRFAST _T1Interrupt (void) {
  u16_seconds++;
  _T1IF = 0;     //clear the timer interrupt bit
}

void  configTimer1(void) {
  T1CON = T1_OFF | T1_IDLE_CON | T1_GATE_OFF
          | T1_SYNC_EXT_OFF
          | T1_SOURCE_EXT
          | T1_PS_1_1 ;  //
  PR1 = 0x7FFF;                    //period is 1 second
  _T1IF = 0;                       //clear interrupt flag
  _T1IP = 1;                       //choose a priority
  _T1IE = 1;                       //enable the interrupt
  T1CONbits.TON = 1;               //turn on the timer
}

void testSosc(void) {
  __builtin_write_OSCCONL(OSCCON | 0x02);    //    OSCCON.SOSCEN=1;
  configTimer1();
  outString("Press RESET to exit\n");
  writeConfigDS1722(0xE8); //12-bit mode
  while(1) {
    outString("Seconds: ");
    outUint16Decimal(u16_seconds);
    outString("\n");
    while (!IS_TRANSMIT_COMPLETE_UART1());
    SLEEP();
  }
}


void testAll(void) {
  ledSWtest();
  anaPotTest();
  digPotTest();
  spiDACTest();
  testEEPROM();
  lm60Test();
  testDS1722();
  testDS1631();
  testSosc();
}

uint8_t printMenuGetChoice(void) {
  uint8_t u8_c;
  outString("0. Test all\n");
  outString("1. Test LEDs/Switches\n");
  outString("2. Test Analog Potentiometer\n");
  outString("3. Test SPI Potentiometer (MCP41010)\n");
  outString("4. Test SPI DAC (MAX548)\n");
  outString("5. Test I2C EEPROM (24LC515)\n");
  outString("6. Test LM60 Temperature Sensor\n");
  outString("7. Test DS1722 Temperature Sensor\n");
  outString("8. Test DS1631 Temperature Sensor\n");
  outString("9. Test secondary oscillator\n");
  outString("Enter choice: ");
  u8_c = inCharEcho();
  outChar('\n');
  return(u8_c);
}


int main (void) {
  uint8_t u8_c;

  configBasic(HELLO_MSG);
  configSPI1();
  configI2C1(400);            //configure I2C for 400 KHz

  outString("ASEE Education board test program.\n");


  while (1) {
    u8_c = printMenuGetChoice();
    switch (u8_c) {
      case '0':
        testAll();
        break;
      case '1':
        ledSWtest();
        break;
      case '2':
        anaPotTest();
        break;
      case '3':
        digPotTest();
        break;
      case '4':
        spiDACTest();
        break;
      case '5':
        testEEPROM();
        break;
      case '6':
        lm60Test();
        break;
      case '7':
        testDS1722();
        break;
      case '8':
        testDS1631();
        break;
      case '9':
        testSosc();
        break;
      default:
        break;
    }
    doHeartbeat();
  }

}
