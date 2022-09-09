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
L Motor:Motor_DC M1
U 1 1 631B4BF5
P 1900 2550
F 0 "M1" H 2058 2546 50  0000 L CNN
F 1 "Motor_DC" H 2058 2455 50  0000 L CNN
F 2 "" H 1900 2460 50  0001 C CNN
F 3 "~" H 1900 2460 50  0001 C CNN
	1    1900 2550
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC M2
U 1 1 631B5CBA
P 1900 1900
F 0 "M2" H 2058 1896 50  0000 L CNN
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
$EndSCHEMATC
