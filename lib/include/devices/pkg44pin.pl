###package data

## 44 pin package data, variant 1
## PIC24HJ16GP304
## PIC24HJ32GP204
## PIC24HJ32GP304
## PIC24HJ64GP204
## PIC24HJ64GP504
## PIC24HJ128GP204
## PIC24HJ128GP504
## dsPIC33FJ32GP204
## dsPIC33FJ16GP304



@digio_44pin_1 = (
"RA0",
"RA1",
"RA2",
"RA3",
"RA4",
"RA7",
"RA8",
"RA9",
"RA10",
"RB0",
"RB1",
"RB2",
"RB3",
"RB4",
"RB5",
"RB6",
"RB7",
"RB8",
"RB9",
"RB10",
"RB11",
"RB12",
"RB13",
"RB14",
"RB15",
"RC0",
"RC1",
"RC2",
"RC3",
"RC4",
"RC5",
"RC6",
"RC7",
"RC8",
"RC9"
);


@digio_44pin_24E_1 = (
"RA0",
"RA1",
"RA2",
"RA3",
"RA8",
"RB0",
"RB1",
"RB2",
"RB3",
"RB4",
"RB5",
"RB6",
"RB7",
"RB8",
"RB9",
"RB10",
"RB11",
"RB12",
"RB13",
"RB14",
"RB15",
"RC0",
"RC1",
"RC2",
"RC3",
"RC4",
"RC5",
"RC6",
"RC7",
"RC8",
"RC9"
);



%pullups_44pin_1 = (
"RA0" => "_CN2",
"RA1" => "_CN3",
"RA2" => "_CN30",
"RA3" => "_CN29",
"RA4" => "_CN0",
"RB0" => "_CN4",
"RB1" => "_CN5",
"RB2" => "_CN6",
"RB3" => "_CN7",
"RB4" => "_CN1",
"RB5" => "_CN27",
"RB6" => "_CN24",
"RB7" => "_CN23",
"RB8" => "_CN22",
"RB9" => "_CN21",
"RB10" => "_CN16",
"RB11" => "_CN15",
"RB12" => "_CN14",
"RB13" => "_CN13",
"RB14" => "_CN12",
"RB15" => "_CN11",
"RC0" => "_CN8",
"RC1" => "_CN9",
"RC2" => "_CN10",
"RC3" => "_CN28",
"RC4" => "_CN25",
"RC5" => "_CN26",
"RC6" => "_CN18",
"RC7" => "_CN17",
"RC8" => "_CN20",
"RC9" => "_CN19",
   );
   
%pullups_44pin_24E_1 = (
"RA0" => "",
"RA1" => "",
"RA2" => "",
"RA3" => "",
"RA8" => "",
"RB0" => "",
"RB1" => "",
"RB2" => "",
"RB3" => "",
"RB4" => "",
"RB5" => "",
"RB6" => "",
"RB7" => "",
"RB8" => "",
"RB9" => "",
"RB10" => "",
"RB11" => "",
"RB12" => "",
"RB13" => "",
"RB14" => "",
"RB15" => "",
"RC0" => "",
"RC1" => "",
"RC2" => "",
"RC3" => "",
"RC4" => "",
"RC5" => "",
"RC6" => "",
"RC7" => "",
"RC8" => "",
"RC9" => "",
   );
 
 
 %opendrain_44pin_24H_1 = (
   "RA0" => "_ODCA0",
"RA1" => "_ODCA1",
"RA2" => "_ODCA2",
"RA3" => "_ODCA3",
"RA4" => "_ODCA4",
"RA7" => "_ODCA7",
"RA8" => "_ODCA8",
"RA9" => "_ODCA9",
"RA10" => "_ODCA10",
"RB0" => "_ODCB0",
   "RB1" => "_ODCB1",
   "RB2" => "_ODCB2",
   "RB3" => "_ODCB3",
   "RB4" => "_ODCB4",
   "RB5" => "_ODCB5",
   "RB6" => "_ODCB6",
   "RB7" => "_ODCB7",
   "RB8" => "_ODCB8",
   "RB9" => "_ODCB9",
   "RB10" => "_ODCB10",
   "RB11" => "_ODCB11",
   "RB12" => "_ODCB12",
   "RB13" => "_ODCB13",
   "RB14" => "_ODCB14",
   "RB15" => "_ODCB15",   
"RC0" => "_ODCC0",
"RC1" => "_ODCC1",
"RC2" => "_ODCC2",
"RC3" => "_ODCC3",
"RC4" => "_ODCC4",
"RC5" => "_ODCC5",
"RC6" => "_ODCC6",
"RC7" => "_ODCC7",
"RC8" => "_ODCC8",
"RC9" => "_ODCC9",
   );

%opendrain_44pin_24E_1 = (
   "RA0" => "_ODCA0",
"RA1" => "_ODCA1",
"RA2" => "_ODCA2",
"RA3" => "_ODCA3",
"RA4" => "_ODCA4",
"RA8" => "_ODCA8",
"RB0" => "_ODCB0",
   "RB1" => "_ODCB1",
   "RB2" => "_ODCB2",
   "RB3" => "_ODCB3",
   "RB4" => "_ODCB4",
   "RB5" => "_ODCB5",
   "RB6" => "_ODCB6",
   "RB7" => "_ODCB7",
   "RB8" => "_ODCB8",
   "RB9" => "_ODCB9",
   "RB10" => "_ODCB10",
   "RB11" => "_ODCB11",
   "RB12" => "_ODCB12",
   "RB13" => "_ODCB13",
   "RB14" => "_ODCB14",
   "RB15" => "_ODCB15",   
"RC0" => "_ODCC0",
"RC1" => "_ODCC1",
"RC2" => "_ODCC2",
"RC3" => "_ODCC3",
"RC4" => "_ODCC4",
"RC5" => "_ODCC5",
"RC6" => "_ODCC6",
"RC7" => "_ODCC7",
"RC8" => "_ODCC8",
"RC9" => "_ODCC9",
   );   
   
   
   
   
   %opendrain_44pin_24F_1 = (
   "RA0" => "_ODA0",
"RA1" => "_ODA1",
"RA2" => "_ODA2",
"RA3" => "_ODA3",
"RA4" => "_ODA4",
"RA7" => "_ODA7",
"RA8" => "_ODA8",
"RA9" => "_ODA9",
"RA10" => "_ODA10",
"RB0" => "_ODB0",
   "RB1" => "_ODB1",
   "RB2" => "_ODB2",
   "RB3" => "_ODB3",
   "RB4" => "_ODB4",
   "RB5" => "_ODB5",
   "RB6" => "_ODB6",
   "RB7" => "_ODB7",
   "RB8" => "_ODB8",
   "RB9" => "_ODB9",
   "RB10" => "_ODB10",
   "RB11" => "_ODB11",
   "RB12" => "_ODB12",
   "RB13" => "_ODB13",
   "RB14" => "_ODB14",
   "RB15" => "_ODB15",   
"RC0" => "_ODC0",
"RC1" => "_ODC1",
"RC2" => "_ODC2",
"RC3" => "_ODC3",
"RC4" => "_ODC4",
"RC5" => "_ODC5",
"RC6" => "_ODC6",
"RC7" => "_ODC7",
"RC8" => "_ODC8",
"RC9" => "_ODC9",
   );

   
  %analog_44pin_1 = (
 "RA0" => "_PCFG0",
   "RA1" => "_PCFG1",
"RB0" => "_PCFG2",
"RB1" => "_PCFG3",
"RB2" => "_PCFG4",
"RB3" => "_PCFG5",
"RB12" => "_PCFG12",
"RB13" => "_PCFG11",
"RB14" => "_PCFG10",
"RB15" => "_PCFG9",
"RC0" => "_PCFG6",
"RC1" => "_PCFG7",
"RC2" => "_PCFG8",
   );
   
    %analog_44pin_24E_1 = (
   "RA0" => "AN0",
   "RA1" => "AN1",
   "RB0" => "AN2",
   "RB1" => "AN3",
   "RB2" => "AN4",
   "RB3" => "AN5",
   "RC0" => "AN6",
   "RC1" => "AN7",
   "RC2" => "AN8",
   );
   
  %RPanalog_44pin_1 = (
   0 => "_PCFG2",
   1 => "_PCFG3",
   2 => "_PCFG4",
   3 => "_PCFG5",
   12 => "_PCFG12",
   13 => "_PCFG11",
   14 => "_PCFG10",
   15 => "_PCFG9",   
   16 => "_PCFG6",
   17 => "_PCFG7",
   18 => "_PCFG8",
   );
   
    %RPanalog_44pin_24E_1 = (
   32 => "_ANSB0",
   33 => "_ANSB1",
   34 => "_ANSB2",
   35 => "_ANSB3"
   );
 
## 24FB devices  

@digio_44pin_FB = (
"RA0",
"RA1",
"RA2",
"RA3",
"RA4",
"RA7",
"RA8",
"RA9",
"RA10",
"RB0",
"RB1",
"RB2",
"RB3",
"RB4",
"RB5",
"RB7",
"RB8",
"RB9",
"RB10",
"RB11",
"RB13",
"RB14",
"RB15",
"RC0",
"RC1",
"RC2",
"RC3",
"RC4",
"RC5",
"RC6",
"RC7",
"RC8",
"RC9"
);

%pullups_44pin_FB = (
"RA0" => "_CN2",
"RA1" => "_CN3",
"RA2" => "_CN30",
"RA3" => "_CN29",
"RA4" => "_CN0",
"RB0" => "_CN4",
"RB1" => "_CN5",
"RB2" => "_CN6",
"RB3" => "_CN7",
"RB4" => "_CN1",
"RB5" => "_CN27",
"RB7" => "_CN23",
"RB8" => "_CN18",
"RB9" => "_CN22",
"RB10" => "_CN16",
"RB11" => "_CN15",
"RB13" => "_CN13",
"RB14" => "_CN12",
"RB15" => "_CN11",
"RC0" => "_CN8",
"RC1" => "_CN9",
"RC2" => "_CN10",
"RC3" => "_CN28",
"RC4" => "_CN25",
"RC5" => "_CN26",
"RC6" => "_CN18",
"RC7" => "_CN17",
"RC8" => "_CN20",
"RC9" => "_CN19",
   );
   
   
      
   %opendrain_44pin_FB = (
   "RA0" => "_ODA0",
"RA1" => "_ODA1",
"RA2" => "_ODA2",
"RA3" => "_ODA3",
"RA4" => "_ODA4",
"RA7" => "_ODA7",
"RA8" => "_ODA8",
"RA9" => "_ODA9",
"RA10" => "_ODA10",
"RB0" => "_ODB0",
   "RB1" => "_ODB1",
   "RB2" => "_ODB2",
   "RB3" => "_ODB3",
   "RB4" => "_ODB4",
   "RB5" => "_ODB5",
   "RB7" => "_ODB7",
   "RB8" => "_ODB8",
   "RB9" => "_ODB9",
   "RB10" => "_ODB10",
   "RB11" => "_ODB11",
   "RB13" => "_ODB13",
   "RB14" => "_ODB14",
   "RB15" => "_ODB15",   
"RC0" => "_ODC0",
"RC1" => "_ODC1",
"RC2" => "_ODC2",
"RC3" => "_ODC3",
"RC4" => "_ODC4",
"RC5" => "_ODC5",
"RC6" => "_ODC6",
"RC7" => "_ODC7",
"RC8" => "_ODC8",
"RC9" => "_ODC9",
   );
   
   
    %analog_44pin_1 = (
 "RA0" => "_PCFG0",
   "RA1" => "_PCFG1",
"RB0" => "_PCFG2",
"RB1" => "_PCFG3",
"RB2" => "_PCFG4",
"RB3" => "_PCFG5",
"RB13" => "_PCFG11",
"RB14" => "_PCFG10",
"RB15" => "_PCFG9",
"RC0" => "_PCFG6",
"RC1" => "_PCFG7",
"RC2" => "_PCFG8",
   );
   
  %RPanalog_44pin_1 = (
   0 => "_PCFG2",
   1 => "_PCFG3",
   2 => "_PCFG4",
   3 => "_PCFG5",
   13 => "_PCFG11",
   14 => "_PCFG10",
   15 => "_PCFG9",   
   16 => "_PCFG6",
   17 => "_PCFG7",
   18 => "_PCFG8",
   );
 