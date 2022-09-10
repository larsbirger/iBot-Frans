EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L schematic_components:arduino_motor_shield U1
U 1 1 631A9DD5
P 5450 3800
F 0 "U1" H 5475 5765 50  0000 C CNN
F 1 "arduino_motor_shield" H 5475 5674 50  0000 C CNN
F 2 "" H 5150 5700 50  0001 C CNN
F 3 "" H 5150 5700 50  0001 C CNN
	1    5450 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 631B3C77
P 4250 2650
F 0 "#PWR?" H 4250 2400 50  0001 C CNN
F 1 "GND" H 4255 2477 50  0000 C CNN
F 2 "" H 4250 2650 50  0001 C CNN
F 3 "" H 4250 2650 50  0001 C CNN
	1    4250 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2650 4900 2650
Wire Wire Line
	4250 2550 4900 2550
$Comp
L Motor:Motor_DC MA
U 1 1 631B4BF5
P 1900 2550
F 0 "MA" H 2058 2546 50  0000 L CNN
F 1 "Motor_DC" H 2058 2455 50  0000 L CNN
F 2 "" H 1900 2460 50  0001 C CNN
F 3 "~" H 1900 2460 50  0001 C CNN
	1    1900 2550
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC MB
U 1 1 631B5CBA
P 1900 1900
F 0 "MB" H 2058 1896 50  0000 L CNN
F 1 "Motor_DC" H 2058 1805 50  0000 L CNN
F 2 "" H 1900 1810 50  0001 C CNN
F 3 "~" H 1900 1810 50  0001 C CNN
	1    1900 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 2850 2500 2850
Wire Wire Line
	1900 2250 1900 2200
Wire Wire Line
	1900 1700 2500 1700
Wire Wire Line
	2500 1700 2500 2150
Wire Wire Line
	2500 2150 4900 2150
Text GLabel 4250 2550 0    50   Input ~ 0
Pwr
Wire Wire Line
	2500 2450 4900 2450
Wire Wire Line
	2500 2450 2500 2850
Wire Wire Line
	1900 2250 4900 2250
Wire Wire Line
	1900 2350 4900 2350
$Comp
L Device:Rotary_Encoder SWA
U 1 1 631CF6B4
P 8550 2250
F 0 "SWA" H 8780 2296 50  0000 L CNN
F 1 "Rotary_Encoder" H 8780 2205 50  0000 L CNN
F 2 "" H 8400 2410 50  0001 C CNN
F 3 "~" H 8550 2510 50  0001 C CNN
	1    8550 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:Rotary_Encoder SWB
U 1 1 631D6520
P 8550 2800
F 0 "SWB" H 8780 2846 50  0000 L CNN
F 1 "Rotary_Encoder" H 8780 2755 50  0000 L CNN
F 2 "" H 8400 2960 50  0001 C CNN
F 3 "~" H 8550 3060 50  0001 C CNN
	1    8550 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 3550 8050 3550
Wire Wire Line
	8150 3450 6050 3450
Wire Wire Line
	6050 3350 7850 3350
Wire Wire Line
	7950 3250 6050 3250
Wire Wire Line
	8150 3450 8150 2900
Wire Wire Line
	8150 2900 8250 2900
Wire Wire Line
	8050 3550 8050 2700
Wire Wire Line
	8050 2700 8250 2700
Wire Wire Line
	7950 3250 7950 2350
Wire Wire Line
	7850 3350 7850 2150
Wire Wire Line
	7950 2350 8250 2350
Wire Wire Line
	7850 2150 8250 2150
$EndSCHEMATC
