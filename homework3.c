#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

typedef enum {checker, first, second, turnOn} button_fsm;

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;
    bool buttonVal = false;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        changeBoosterpackLED(count1);

        // If Timer0 has expired, increment count0.
        if(timer0Expired())
            count0++;

        // If Timer1 has expired, update the button history from the pushbutton value.
        if(timer1Expired())
            buttonVal = checkStatus_BoosterpackS1();

        // If a completed, debounced button press has occurred, increment count1.
        if (fsmBoosterpackButtonS1(buttonVal))
            count1++;
    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    // ********************************************************************************
    // In my solution, I only demonstrated Red, Green, and Blue LEDs
    // Since these are the main three colors, they are sufficient to show
    // the debouncing and timing of the lights. In order to keep the code clean
    // and readable, the rest of the Case structure will not be loaded as it
    // is simply an extension of what is shown below.

    // If more colors are to be added, simply change the DEFINED NUM_LIGHTS
    // to the number of colors, and add a case with the appropriate LED turnOn/turnOff
    // function.

    // The solution below still shows the functionality of the code I wrote meeting
    // the requirements of the assignment.
    // ********************************************************************************

    int changer = count%NUM_LIGHTS;
    switch(changer)
    {
    case 0:
        // Turn off all LEDs
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;

    case 1:
        // Turn on ONLY LED2 Red
        turnOn_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;

    case 2:
        // Turn on ONLY LED2 Green
        turnOff_LaunchpadLED2Red();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Blue();
        break;

    case 3:
        // Turn on ONLY LED2 Blue
        turnOff_LaunchpadLED2Red();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Blue();
        break;

    default:
    }
}

// Map the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    // ********************************************************************************
    // In my solution, I only demonstrated Red, Green, and Blue LEDs
    // Since these are the main three colors, they are sufficient to show
    // the debouncing and timing of the lights. In order to keep the code clean
    // and readable, the rest of the Case structure will not be loaded as it
    // is simply an extension of what is shown below.

    // If more colors are to be added, simply change the DEFINED NUM_LIGHTS
    // to the number of colors, and add a case with the appropriate LED turnOn/turnOff
    // function.

    // The solution below still shows the functionality of the code I wrote meeting
    // the requirements of the assignment.
    // ********************************************************************************

    int changer = count%NUM_LIGHTS;
    switch(changer)
    {
    case 0:
        // Turn off all LEDs
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;

    case 1:
        // Turn on ONLY BOOST_LED Red
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;

    case 2:
        // Turn on ONLY LED2 Green
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;

    case 3:
        // Turn on ONLY LED2 Blue
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;

    default:
    }
}

// Button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    bool returner = false;
    static button_fsm currentVal = checker;
    switch(currentVal)
    {
        case checker:
            returner = false;
            if(buttonhistory)
                currentVal = first;
            else
                currentVal = second;
            break;

        // Button was pressed. Check for bouncing.
        case first:
            if(buttonhistory)
            {
               currentVal = turnOn;
            }
            else
                currentVal = second;
            break;

        // Button not pressed. Checking for bouncing
        case second:
            if(buttonhistory)
            {
                currentVal = first;
            }
            else
            {
                returner = false;
            }
            break;

        case turnOn:
            // Wait for button to be let go.
            if (!buttonhistory)
            {
                returner = true;
                currentVal = checker;
            }
            break;
    }

    return (returner);
}
