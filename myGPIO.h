/*
 * myGPIO.h
 *
 *  Created on: 3/2/2
 *      Author: Adrian Ruvalcaba
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_
// LaunchPad Define
#define LAUNCH_S1 BIT1
#define LAUNCH_S2 BIT4
#define LAUNCH_LED1 BIT0
#define LAUNCH_LED2R BIT0
#define LAUNCH_LED2G BIT1
#define LAUNCH_LED2B BIT2
// Boosterpack Define
#define BOOST_S1 BIT1
#define BOOST_S2 BIT5
#define BOOST_LEDR BIT6
#define BOOST_LEDG BIT4
#define BOOST_LEDB BIT6

#define PRESSED 0

// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();

#endif /* MYGPIO_H_ */
