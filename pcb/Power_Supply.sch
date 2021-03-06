EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 602BE430
P 900 1600
F 0 "J1" H 818 1367 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 980 1501 50  0001 L CNN
F 2 "IO_LINK_LIB:TerminalBlock_Altech_AK300-2_P5.00mm" H 900 1600 50  0001 C CNN
F 3 "~" H 900 1600 50  0001 C CNN
F 4 "1729128" H 900 1600 50  0001 C CNN "MPN"
F 5 "N/A" H 900 1600 50  0001 C CNN "LCSC"
	1    900  1600
	-1   0    0    1   
$EndComp
Wire Notes Line width 20
	650  800  650  2300
Wire Notes Line width 20
	5150 800  650  800 
Text Notes 700  1000 0    100  ~ 20
POWER SUPPLY CONNECTOR AND PROTECTION CIRCUIT
$Comp
L IO_LINK_LIB:SM15T33CAY D1
U 1 1 603F2BFA
P 1900 1650
F 0 "D1" H 2028 1796 50  0000 L CNN
F 1 "SM15T33CAY" V 1500 1650 50  0001 C CNN
F 2 "IO_LINK_LIB:SMC_BI_TVS" V 1600 1650 50  0001 C CNN
F 3 "~" V 1900 1640 50  0001 C CNN
F 4 "SM15T33CAY" H 2028 1705 50  0000 L CNN "MPN"
F 5 "N/A" V 1300 1650 50  0001 C CNN "LCSC"
F 6 "SMC" V 1400 1600 50  0001 L CNN "Package"
	1    1900 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1500 1250 1500
Wire Wire Line
	1250 1500 1250 1200
Wire Wire Line
	1250 1200 1900 1200
Wire Wire Line
	1100 1600 1250 1600
Wire Wire Line
	1250 1600 1250 1900
Wire Wire Line
	1250 1900 1900 1900
Connection ~ 1900 1900
Connection ~ 1900 1200
$Comp
L power:GND #PWR0101
U 1 1 603FABE0
P 3400 2050
F 0 "#PWR0101" H 3400 1800 50  0001 C CNN
F 1 "GND" H 3405 1877 50  0000 C CNN
F 2 "" H 3400 2050 50  0001 C CNN
F 3 "" H 3400 2050 50  0001 C CNN
	1    3400 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2050 3400 1900
Wire Notes Line width 20
	5150 2300 5150 800 
Wire Notes Line width 20
	650  2300 5150 2300
$Comp
L IO_LINK_LIB:VCC #PWR0102
U 1 1 604029F6
P 3300 1150
F 0 "#PWR0102" H 3300 900 50  0001 C CNN
F 1 "VCC" H 3300 1250 50  0000 C CNN
F 2 "" H 3360 1100 50  0001 C CNN
F 3 "" H 3360 1100 50  0001 C CNN
	1    3300 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1150 3300 1200
$Comp
L IO_LINK_LIB:VCC #PWR0103
U 1 1 60404173
P 1050 3050
F 0 "#PWR0103" H 1050 2800 50  0001 C CNN
F 1 "VCC" H 1050 3150 50  0000 C CNN
F 2 "" H 1110 3000 50  0001 C CNN
F 3 "" H 1110 3000 50  0001 C CNN
	1    1050 3050
	1    0    0    -1  
$EndComp
$Comp
L IO_LINK-rescue:0R_1%_0.1W_0805-IO_LINK_LIB JP?
U 1 1 6045CB1F
P 4400 3150
AR Path="/6045CB1F" Ref="JP?"  Part="1" 
AR Path="/602BD2FF/6045CB1F" Ref="JP2"  Part="1" 
F 0 "JP2" H 4400 3239 50  0000 C CNN
F 1 "0R_1%_0.1W_0805" V 3260 3170 50  0001 C CNN
F 2 "IO_LINK_LIB:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3490 3540 50  0001 C CNN
F 3 "~" V 4400 3150 50  0001 C CNN
F 4 "0805W8F0000T5E" V 3340 3180 50  0001 C CNN "MPN"
F 5 "C17477" V 3410 3200 50  0001 C CNN "LCSC"
F 6 "0R" H 4305 3605 50  0001 L CNN "Resistane"
F 7 "1%" H 4305 3535 50  0001 L CNN "Tolerance"
F 8 "0.1W" H 4305 3465 50  0001 L CNN "Power"
F 9 "0805" H 4305 3380 50  0001 L CNN "Package"
	1    4400 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3150 4650 3150
$Comp
L IO_LINK_LIB:TestPoint TP2
U 1 1 60467095
P 4650 3050
F 0 "TP2" H 4600 3250 50  0000 L CNN
F 1 "TestPoint" H 4660 3315 50  0001 C CNN
F 2 "IO_LINK_LIB:TestPoint_Pad_D2.0mm" H 4655 3385 50  0001 C CNN
F 3 "~" H 4850 3050 50  0001 C CNN
	1    4650 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3050 4650 3150
Connection ~ 4650 3150
$Comp
L IO_LINK_LIB:TestPoint TP1
U 1 1 60468B85
P 4150 3050
F 0 "TP1" H 4100 3250 50  0000 L CNN
F 1 "TestPoint" H 4160 3315 50  0001 C CNN
F 2 "IO_LINK_LIB:TestPoint_Pad_D2.0mm" H 4155 3385 50  0001 C CNN
F 3 "~" H 4350 3050 50  0001 C CNN
	1    4150 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3050 4150 3150
Wire Wire Line
	4150 3150 4250 3150
Wire Wire Line
	4850 3150 4850 3100
Wire Wire Line
	4650 3150 4850 3150
$Comp
L IO_LINK_LIB:8V #PWR0147
U 1 1 6046D08A
P 4850 3100
F 0 "#PWR0147" H 4850 2850 50  0001 C CNN
F 1 "8V" H 4850 3200 50  0000 C CNN
F 2 "" H 4910 3050 50  0001 C CNN
F 3 "" H 4910 3050 50  0001 C CNN
	1    4850 3100
	1    0    0    -1  
$EndComp
Text Notes 7400 7500 0    50   Italic 0
IO-LINK MASTER board / power supply and protection circuit
Text Notes 8100 7650 0    50   Italic 0
19.02.2021
Wire Wire Line
	3000 1900 3400 1900
Wire Wire Line
	2700 1900 1900 1900
Wire Wire Line
	1900 1200 3300 1200
$Comp
L IO_LINK_LIB:STPS1H100A D2
U 1 1 603F8E2A
P 2850 1900
F 0 "D2" V 2633 1900 50  0000 C CNN
F 1 "STPS1H100A" V 2450 1900 50  0001 C CNN
F 2 "IO_LINK_LIB:SMA" V 2550 1900 50  0001 C CNN
F 3 "~" V 2850 1890 50  0001 C CNN
F 4 "STPS1H100A" V 2724 1900 50  0000 C CNN "MPN"
F 5 "N/A" V 2250 1900 50  0001 C CNN "LCSC"
F 6 "SMA" V 2350 1850 50  0001 L CNN "Package"
	1    2850 1900
	0    1    1    0   
$EndComp
Text Notes 700  2700 0    100  ~ 20
DC-DC SMPS POWER SUPPLY SECTION
$Comp
L IO_LINK_LIB:DC_DC_CONVERTER_LM2596_PCB_MODULE M2
U 1 1 61B8D6D6
P 1700 3250
F 0 "M2" H 1950 3575 50  0000 C CNN
F 1 "DC_DC_CONVERTER_LM2596_PCB_MODULE" H 1500 3600 50  0001 L CNN
F 2 "IO_LINK_LIB:DC_DC_CONVERTER_LM2596_PCB_MODULE" H 1700 4100 50  0001 C CNN
F 3 "~" H 1880 3135 50  0001 C CNN
F 4 "N/A" H 1700 4350 50  0001 C CNN "MPN"
F 5 "N/A" H 1700 3850 50  0001 C CNN "LCSC"
	1    1700 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3900 1050 3900
Wire Wire Line
	2650 3900 2850 3900
Wire Wire Line
	2650 3150 3550 3150
Wire Wire Line
	3550 3350 3550 3150
Connection ~ 3550 3150
Wire Wire Line
	3550 3150 4150 3150
Connection ~ 4150 3150
$Comp
L IO_LINK_LIB:15uF_16V_0805 C18
U 1 1 60423361
P 3550 3500
F 0 "C18" H 3665 3637 50  0000 L CNN
F 1 "15uF_16V_0805" H 3745 3935 50  0001 L CNN
F 2 "IO_LINK_LIB:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 4310 4200 50  0001 C CNN
F 3 "~" H 3550 3500 50  0001 C CNN
F 4 "16V" H 3665 3546 50  0000 L CNN "Voltage"
F 5 "0805" H 3665 3455 50  0000 L CNN "Package"
F 6 "C2012JB1C156M125AC" H 4100 4100 50  0001 C CNN "MPN"
F 7 "N/A" H 3850 4000 50  0001 C CNN "LCSC"
F 8 "15uF" H 3665 3364 50  0000 L CNN "Capacitance"
	1    3550 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3150 1050 3150
Wire Wire Line
	1050 3150 1050 3050
Wire Notes Line width 20
	5150 2450 5150 4400
Wire Notes Line width 20
	5150 4400 650  4400
Wire Notes Line width 20
	650  4400 650  2450
Wire Notes Line width 20
	650  2450 5150 2450
$Comp
L IO_LINK_LIB:3V3_T0 #PWR?
U 1 1 61ECC7D2
P 1200 5200
AR Path="/602CF7CD/61ECC7D2" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/61ECC7D2" Ref="#PWR0151"  Part="1" 
F 0 "#PWR0151" H 1200 4950 50  0001 C CNN
F 1 "3V3_T0" H 1200 5300 50  0000 C CNN
F 2 "" H 1260 5150 50  0001 C CNN
F 3 "" H 1260 5150 50  0001 C CNN
	1    1200 5200
	1    0    0    -1  
$EndComp
$Comp
L IO_LINK_LIB:3V3_T1 #PWR?
U 1 1 61ECC7D8
P 1200 5600
AR Path="/602CF7CD/61ECC7D8" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/61ECC7D8" Ref="#PWR0152"  Part="1" 
F 0 "#PWR0152" H 1200 5350 50  0001 C CNN
F 1 "3V3_T1" H 1200 5700 50  0000 C CNN
F 2 "" H 1260 5550 50  0001 C CNN
F 3 "" H 1260 5550 50  0001 C CNN
	1    1200 5600
	1    0    0    -1  
$EndComp
$Comp
L IO_LINK_LIB:3V3_T2 #PWR?
U 1 1 61ECC7DE
P 1200 6000
AR Path="/602CF7CD/61ECC7DE" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/61ECC7DE" Ref="#PWR0153"  Part="1" 
F 0 "#PWR0153" H 1200 5750 50  0001 C CNN
F 1 "3V3_T2" H 1200 6100 50  0000 C CNN
F 2 "" H 1260 5950 50  0001 C CNN
F 3 "" H 1260 5950 50  0001 C CNN
	1    1200 6000
	1    0    0    -1  
$EndComp
$Comp
L IO_LINK_LIB:3V3_T3 #PWR?
U 1 1 61ECC7E4
P 1200 6400
AR Path="/602CF7CD/61ECC7E4" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/61ECC7E4" Ref="#PWR0154"  Part="1" 
F 0 "#PWR0154" H 1200 6150 50  0001 C CNN
F 1 "3V3_T3" H 1200 6500 50  0000 C CNN
F 2 "" H 1260 6350 50  0001 C CNN
F 3 "" H 1260 6350 50  0001 C CNN
	1    1200 6400
	1    0    0    -1  
$EndComp
$Comp
L IO_LINK_LIB:1R_1%_0.1W_0603 R?
U 1 1 61ECC7F0
P 1750 6500
AR Path="/602CF7CD/61ECC7F0" Ref="R?"  Part="1" 
AR Path="/602BD2FF/61ECC7F0" Ref="R8"  Part="1" 
F 0 "R8" V 1850 6450 50  0000 L CNN
F 1 "1R_1%_0.1W_0603" V 1210 6620 50  0001 C CNN
F 2 "IO_LINK_LIB:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1440 6990 50  0001 C CNN
F 3 "~" H 1750 6500 50  0001 C CNN
F 4 "0603WAF100KT5E" V 1290 6630 50  0001 C CNN "MPN"
F 5 "C22936" V 1360 6650 50  0001 C CNN "LCSC"
F 6 "1R" V 1800 6650 50  0000 L CNN "Resistane"
F 7 "1%" V 1800 6250 50  0000 L CNN "Tolerance"
F 8 "0.1W" V 1700 6650 50  0000 L CNN "Power"
F 9 "0603" V 1700 6150 50  0000 L CNN "Package"
	1    1750 6500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1600 5300 1200 5300
Wire Wire Line
	1200 5300 1200 5200
Wire Wire Line
	1600 5700 1200 5700
Wire Wire Line
	1200 5700 1200 5600
Wire Wire Line
	1600 6100 1200 6100
Wire Wire Line
	1200 6100 1200 6000
Wire Wire Line
	1600 6500 1200 6500
Wire Wire Line
	1200 6500 1200 6400
Wire Wire Line
	1900 5300 2300 5300
Wire Wire Line
	1900 5700 2300 5700
Wire Wire Line
	1900 6100 2300 6100
Wire Wire Line
	1900 6500 2300 6500
Wire Wire Line
	2300 5700 2300 5300
$Comp
L IO_LINK_LIB:1R_1%_0.1W_0603 R?
U 1 1 61ECC809
P 1750 5300
AR Path="/602CF7CD/61ECC809" Ref="R?"  Part="1" 
AR Path="/602BD2FF/61ECC809" Ref="R5"  Part="1" 
F 0 "R5" V 1850 5250 50  0000 L CNN
F 1 "1R_1%_0.1W_0603" V 1210 5420 50  0001 C CNN
F 2 "IO_LINK_LIB:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1440 5790 50  0001 C CNN
F 3 "~" H 1750 5300 50  0001 C CNN
F 4 "0603WAF100KT5E" V 1290 5430 50  0001 C CNN "MPN"
F 5 "C22936" V 1360 5450 50  0001 C CNN "LCSC"
F 6 "1R" V 1800 5450 50  0000 L CNN "Resistane"
F 7 "1%" V 1800 5050 50  0000 L CNN "Tolerance"
F 8 "0.1W" V 1700 5450 50  0000 L CNN "Power"
F 9 "0603" V 1700 4950 50  0000 L CNN "Package"
	1    1750 5300
	0    -1   -1   0   
$EndComp
$Comp
L IO_LINK_LIB:1R_1%_0.1W_0603 R?
U 1 1 61ECC815
P 1750 5700
AR Path="/602CF7CD/61ECC815" Ref="R?"  Part="1" 
AR Path="/602BD2FF/61ECC815" Ref="R6"  Part="1" 
F 0 "R6" V 1850 5650 50  0000 L CNN
F 1 "1R_1%_0.1W_0603" V 1210 5820 50  0001 C CNN
F 2 "IO_LINK_LIB:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1440 6190 50  0001 C CNN
F 3 "~" H 1750 5700 50  0001 C CNN
F 4 "0603WAF100KT5E" V 1290 5830 50  0001 C CNN "MPN"
F 5 "C22936" V 1360 5850 50  0001 C CNN "LCSC"
F 6 "1R" V 1800 5850 50  0000 L CNN "Resistane"
F 7 "1%" V 1800 5450 50  0000 L CNN "Tolerance"
F 8 "0.1W" V 1700 5850 50  0000 L CNN "Power"
F 9 "0603" V 1700 5350 50  0000 L CNN "Package"
	1    1750 5700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 5700 2300 5900
Connection ~ 2300 5700
Connection ~ 2300 5900
Wire Wire Line
	2300 5900 2300 6100
$Comp
L IO_LINK_LIB:1R_1%_0.1W_0603 R?
U 1 1 61ECC825
P 1750 6100
AR Path="/602CF7CD/61ECC825" Ref="R?"  Part="1" 
AR Path="/602BD2FF/61ECC825" Ref="R7"  Part="1" 
F 0 "R7" V 1850 6050 50  0000 L CNN
F 1 "1R_1%_0.1W_0603" V 1210 6220 50  0001 C CNN
F 2 "IO_LINK_LIB:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1440 6590 50  0001 C CNN
F 3 "~" H 1750 6100 50  0001 C CNN
F 4 "0603WAF100KT5E" V 1290 6230 50  0001 C CNN "MPN"
F 5 "C22936" V 1360 6250 50  0001 C CNN "LCSC"
F 6 "1R" V 1800 6250 50  0000 L CNN "Resistane"
F 7 "1%" V 1800 5850 50  0000 L CNN "Tolerance"
F 8 "0.1W" V 1700 6250 50  0000 L CNN "Power"
F 9 "0603" V 1700 5750 50  0000 L CNN "Package"
	1    1750 6100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 6100 2300 6500
Connection ~ 2300 6100
Wire Wire Line
	2700 5900 2700 5800
Wire Wire Line
	2300 5900 2700 5900
$Comp
L IO_LINK_LIB:3V3 #PWR?
U 1 1 61ECC82F
P 2700 5800
AR Path="/602CF7CD/61ECC82F" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/61ECC82F" Ref="#PWR0155"  Part="1" 
F 0 "#PWR0155" H 2700 5550 50  0001 C CNN
F 1 "3V3" H 2700 5900 50  0000 C CNN
F 2 "" H 2760 5750 50  0001 C CNN
F 3 "" H 2760 5750 50  0001 C CNN
	1    2700 5800
	1    0    0    -1  
$EndComp
Wire Notes Line width 20
	3150 7050 650  7050
Wire Notes Line width 20
	650  4600 3150 4600
Text Notes 750  4850 0    50   Italic 0
Each IO_Link transceiver contain its own LDO \nand their outputs are parallelized:
Wire Notes Line width 20
	3150 4600 3150 7050
Wire Notes Line width 20
	650  4600 650  7050
$Comp
L IO_LINK_LIB:JUMPER_0805 JP3
U 1 1 62B45572
P 3700 1900
F 0 "JP3" H 3700 1989 50  0000 C CNN
F 1 "JUMPER_0805" V 2560 1920 50  0001 C CNN
F 2 "IO_LINK_LIB:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 2790 2290 50  0001 C CNN
F 3 "~" V 3700 1900 50  0001 C CNN
F 4 "0805W8F0000T5E" V 2640 1930 50  0001 C CNN "MPN"
F 5 "C17477" V 2710 1950 50  0001 C CNN "LCSC"
F 6 "0R" H 3605 2355 50  0001 L CNN "Resistane"
F 7 "1%" H 3605 2285 50  0001 L CNN "Tolerance"
F 8 "0.1W" H 3605 2215 50  0001 L CNN "Power"
F 9 "0805" H 3605 2130 50  0001 L CNN "Package"
	1    3700 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 1900 3400 1900
Connection ~ 3400 1900
Wire Wire Line
	3850 1900 3950 1900
Wire Wire Line
	4050 1900 4050 2050
$Comp
L IO_LINK_LIB:G #PWR?
U 1 1 62B49D15
P 2850 4150
AR Path="/602CF7CD/62B49D15" Ref="#PWR?"  Part="1" 
AR Path="/61D13B0C/62B49D15" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/62B49D15" Ref="#PWR0148"  Part="1" 
F 0 "#PWR0148" H 2850 3900 50  0001 C CNN
F 1 "G" H 2855 3977 50  0000 C CNN
F 2 "" H 2850 4150 50  0001 C CNN
F 3 "" H 2850 4150 50  0001 C CNN
	1    2850 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3900 2850 4150
$Comp
L IO_LINK_LIB:G #PWR?
U 1 1 62B4AEFC
P 3550 4150
AR Path="/602CF7CD/62B4AEFC" Ref="#PWR?"  Part="1" 
AR Path="/61D13B0C/62B4AEFC" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/62B4AEFC" Ref="#PWR0149"  Part="1" 
F 0 "#PWR0149" H 3550 3900 50  0001 C CNN
F 1 "G" H 3555 3977 50  0000 C CNN
F 2 "" H 3550 4150 50  0001 C CNN
F 3 "" H 3550 4150 50  0001 C CNN
	1    3550 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3650 3550 4150
$Comp
L IO_LINK_LIB:G #PWR?
U 1 1 62B4C6C8
P 1050 4150
AR Path="/602CF7CD/62B4C6C8" Ref="#PWR?"  Part="1" 
AR Path="/61D13B0C/62B4C6C8" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/62B4C6C8" Ref="#PWR0150"  Part="1" 
F 0 "#PWR0150" H 1050 3900 50  0001 C CNN
F 1 "G" H 1055 3977 50  0000 C CNN
F 2 "" H 1050 4150 50  0001 C CNN
F 3 "" H 1050 4150 50  0001 C CNN
	1    1050 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3900 1050 4150
$Comp
L IO_LINK_LIB:G #PWR?
U 1 1 62B4E619
P 4050 2050
AR Path="/602CF7CD/62B4E619" Ref="#PWR?"  Part="1" 
AR Path="/61D13B0C/62B4E619" Ref="#PWR?"  Part="1" 
AR Path="/602BD2FF/62B4E619" Ref="#PWR0156"  Part="1" 
F 0 "#PWR0156" H 4050 1800 50  0001 C CNN
F 1 "G" H 4055 1877 50  0000 C CNN
F 2 "" H 4050 2050 50  0001 C CNN
F 3 "" H 4050 2050 50  0001 C CNN
	1    4050 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1900 3400 1700
Wire Wire Line
	3950 1700 3950 1900
Connection ~ 3950 1900
Wire Wire Line
	3950 1900 4050 1900
$EndSCHEMATC