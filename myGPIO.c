/*
 * GPIO.c
 *
 *  Created on: 3/2/2020
 *      Author: Adrian Ruvalcaba
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// Function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR &= ~LAUNCH_S1;
    P1REN |= LAUNCH_S1;
    P1OUT |= LAUNCH_S1;

    // Launchpad S2
    P1DIR &= ~LAUNCH_S2;
    P1REN |= LAUNCH_S2;
    P1OUT |= LAUNCH_S2;

    // Boosterpack S1
    P5DIR &= ~BOOST_S1;
    P5REN |= BOOST_S1;
    P5OUT |= BOOST_S1;

    // Boosterpack S2
    P3DIR &= ~BOOST_S2;
    P3REN |= BOOST_S2;
    P3OUT |= BOOST_S2;

    // Launchpad LED1
    P1DIR |= LAUNCH_LED1;

    // Launchpad LED2 Red
    P2DIR |= LAUNCH_LED2R;

    // Launchpad LED2 Green
    P2DIR |= LAUNCH_LED2G;

    // Launchpad LED2 Blue
    P2DIR |= LAUNCH_LED2B;

    // Boosterpack LED Red
    P2DIR |= BOOST_LEDR;

    // Boosterpack LED Green
    P2DIR |= BOOST_LEDG;

    // Boosterpack LED Blue
    P5DIR |= BOOST_LEDB;

    // Turn off all LEDs at the start.
    P1OUT &= ~LAUNCH_LED1;
    P2OUT &= ~LAUNCH_LED2R;
    P2OUT &= ~LAUNCH_LED2G;
    P2OUT &= ~LAUNCH_LED2B;
    P2OUT &= ~BOOST_LEDR;
    P2OUT &= ~BOOST_LEDG;
    P5OUT &= ~BOOST_LEDB;
}

// Function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LAUNCH_S1) == PRESSED);
}

// Function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LAUNCH_S2) == PRESSED);
}

// Function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BOOST_S1) == PRESSED);
}

// Function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOOST_S2) == PRESSED);
}

// Function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT |= LAUNCH_LED1;
}

// Function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT &= ~LAUNCH_LED1;
}

// Function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT |= LAUNCH_LED2R;
}

// Function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT &= ~LAUNCH_LED2R;
}

// Function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT |= LAUNCH_LED2G;
}

// Function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT &= ~LAUNCH_LED2G;
}

// Function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT |= LAUNCH_LED2B;
}

// Function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT &= ~LAUNCH_LED2B;
}

// Function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT |= BOOST_LEDR;
}

// Function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT &= ~BOOST_LEDR;
}

// Function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT |= BOOST_LEDG;
}

// Function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT &= ~BOOST_LEDG;
}

// Function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT |= BOOST_LEDB;
}

// Function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT &= ~BOOST_LEDB;
}
