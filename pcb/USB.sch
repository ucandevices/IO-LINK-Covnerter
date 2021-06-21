EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
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
L IO_LINK_LIB:USB_B_Mini J?
U 1 1 604BC110
P 2500 1900
F 0 "J?" H 2557 2367 50  0000 C CNN
F 1 "USB_B_Mini" H 2557 2276 50  0000 C CNN
F 2 "IO_LINK_LIB:USB_Mini-B_Horizontal" H 2500 2750 50  0001 C CNN
F 3 "~" H 2650 1850 50  0001 C CNN
F 4 "10033526-N3222MLF" H 2500 3000 200 0001 C CNN "MPN"
F 5 "N/A" H 2500 2500 200 0001 C CNN "LCSC"
	1    2500 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 2100 3000 2100
Wire Wire Line
	3000 2100 3000 2300
$Comp
L IO_LINK_LIB:100R_1%_0.1W_0603 R?
U 1 1 604BEA6C
P 3000 2450
F 0 "R?" H 3068 2632 50  0000 L CNN
F 1 "100R_1%_0.1W_0603" V 2460 2570 50  0001 C CNN
F 2 "IO_LINK_LIB:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 2690 2940 50  0001 C CNN
F 3 "~" H 3000 2450 50  0001 C CNN
F 4 "0603WAF1000T5E" V 2540 2580 50  0001 C CNN "MPN"
F 5 "C22775" V 2610 2600 50  0001 C CNN "LCSC"
F 6 "100R" H 3068 2541 50  0000 L CNN "Resistane"
F 7 "1%" H 3068 2450 50  0000 L CNN "Tolerance"
F 8 "0.1W" H 3068 2359 50  0000 L CNN "Power"
F 9 "0603" H 3068 2268 50  0000 L CNN "Package"
	1    3000 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2600 3000 2800
Wire Wire Line
	2800 1700 3000 1700
Wire Wire Line
	3000 1700 3000 1500
$Comp
L power:GND #PWR?
U 1 1 604C9165
P 2450 2800
AR Path="/602BD2FF/604C9165" Ref="#PWR?"  Part="1" 
AR Path="/602BD7B3/604C9165" Ref="#PWR?"  Part="1" 
AR Path="/602BD8C8/604C9165" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2450 2550 50  0001 C CNN
F 1 "GND" H 2455 2627 50  0000 C CNN
F 2 "" H 2450 2800 50  0001 C CNN
F 3 "" H 2450 2800 50  0001 C CNN
	1    2450 2800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 604C95A8
P 3000 2800
AR Path="/602BD2FF/604C95A8" Ref="#PWR?"  Part="1" 
AR Path="/602BD7B3/604C95A8" Ref="#PWR?"  Part="1" 
AR Path="/602BD8C8/604C95A8" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 3000 2550 50  0001 C CNN
F 1 "GND" H 3005 2627 50  0000 C CNN
F 2 "" H 3000 2800 50  0001 C CNN
F 3 "" H 3000 2800 50  0001 C CNN
	1    3000 2800
	1    0    0    -1  
$EndComp
$Comp
L IO_LINK_LIB:5V #PWR?
U 1 1 604CADE7
P 3000 1500
F 0 "#PWR?" H 3000 1250 50  0001 C CNN
F 1 "5V" H 3000 1600 50  0000 C CNN
F 2 "" H 3060 1450 50  0001 C CNN
F 3 "" H 3060 1450 50  0001 C CNN
	1    3000 1500
	1    0    0    -1  
$EndComp
$Comp
L IO_LINK_LIB:USBLC6-2SC6Y D?
U 1 1 604CBBE5
P 3950 1850
F 0 "D?" H 4900 2337 60  0000 C CNN
F 1 "USBLC6-2SC6Y" H 4900 2231 60  0000 C CNN
F 2 "IO_LINK_LIB:SOT-23-6L" H 4805 2370 60  0001 C CNN
F 3 "" H 3950 1850 60  0001 C CNN
F 4 "USBLC6-2SC6Y" H 4860 2440 50  0001 C CNN "MPN"
F 5 "C435848" H 4885 2510 50  0001 C CNN "LCSC"
F 6 "SOT-23-6L" H 4945 2370 50  0001 C CNN "Package"
	1    3950 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1700 6150 1700
Wire Wire Line
	5650 2200 6150 2200
Wire Wire Line
	5650 1950 5850 1950
Wire Wire Line
	5850 1950 5850 1500
$Comp
L IO_LINK_LIB:5V #PWR?
U 1 1 604DD27F
P 5850 1500
F 0 "#PWR?" H 5850 1250 50  0001 C CNN
F 1 "5V" H 5850 1600 50  0000 C CNN
F 2 "" H 5910 1450 50  0001 C CNN
F 3 "" H 5910 1450 50  0001 C CNN
	1    5850 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 1950 4050 1950
$Comp
L power:GND #PWR?
U 1 1 604DDDC4
P 4050 2800
AR Path="/602BD2FF/604DDDC4" Ref="#PWR?"  Part="1" 
AR Path="/602BD7B3/604DDDC4" Ref="#PWR?"  Part="1" 
AR Path="/602BD8C8/604DDDC4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 4050 2550 50  0001 C CNN
F 1 "GND" H 4055 2627 50  0000 C CNN
F 2 "" H 4050 2800 50  0001 C CNN
F 3 "" H 4050 2800 50  0001 C CNN
	1    4050 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 2000 3450 2000
Wire Wire Line
	3450 2000 3450 2200
Wire Wire Line
	2800 1900 3450 1900
Wire Wire Line
	3450 1900 3450 1700
Text GLabel 6150 2200 2    50   BiDi Italic 0
USB_DM
Text GLabel 6150 1700 2    50   BiDi Italic 0
USB_DP
Wire Notes Line width 20
	2000 1000 7000 1000
Text Notes 2100 1200 0    100  ~ 20
USB INTERFACE
Text Notes 7350 7500 0    50   Italic 0
IO-LINK MASTER board / USB interface 
Text Notes 8100 7650 0    50   Italic 0
19.02.2021
Text Notes 9250 7650 0    50   Italic 0
szymon.folmer@gmail.com
Wire Notes Line width 20
	2000 3250 7000 3250
Wire Notes Line width 20
	7000 1000 7000 3250
Wire Notes Line width 20
	2000 1000 2000 3250
Wire Wire Line
	4150 1700 3450 1700
Wire Wire Line
	4150 2200 3450 2200
Wire Wire Line
	2400 2300 2400 2400
Wire Wire Line
	2400 2700 2400 2750
Wire Wire Line
	2400 2750 2450 2750
Wire Wire Line
	2450 2750 2450 2800
Wire Wire Line
	2450 2750 2500 2750
Wire Wire Line
	2500 2750 2500 2300
Connection ~ 2450 2750
$Comp
L IO_LINK_LIB:FB_30R@100MHz L?
U 1 1 61C2E409
P 2400 2550
F 0 "L?" V 2600 2600 50  0000 R CNN
F 1 "FB_30R@100MHz" V 2025 2550 50  0001 C CNN
F 2 "IO_LINK_LIB:Ferrite_bead_0603" V 2250 2490 50  0001 C CNN
F 3 "~" H 2400 2550 50  0001 C CNN
F 4 "BLM18SP300SZ1D" V 2180 2535 50  0001 C CNN "MPN"
F 5 "N/A" V 2100 2550 50  0001 C CNN "LCSC"
F 6 "30R @ 100MHz" V 2500 2900 50  0000 R CNN "Impedance"
	1    2400 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	4050 1950 4050 2800
$EndSCHEMATC