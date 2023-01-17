#ifndef HELLO_H
#define HELLO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LED_0_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr0/trigger"
#define LED_1_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr1/trigger"
#define LED_2_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr2/trigger"
#define LED_3_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr3/trigger"
#define LED_0_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED_1_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED_2_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED_3_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr3/brightness"
#define JS_UP_DIRECTION_PATH "/sys/class/gpio/gpio26/direction"
#define JS_DOWN_DIRECTION_PATH "/sys/class/gpio/gpio46/direction"
#define JS_RIGHT_DIRECTION_PATH "/sys/class/gpio/gpio47/direction"
#define JS_LEFT_DIRECTION_PATH "/sys/class/gpio/gpio65/direction"
#define JS_UP_VALUE_PATH "/sys/class/gpio/gpio26/value"
#define JS_DOWN_VALUE_PATH "/sys/class/gpio/gpio46/value"
#define JS_RIGHT_VALUE_PATH "/sys/class/gpio/gpio47/value"
#define JS_LEFT_VALUE_PATH "/sys/class/gpio/gpio65/value"

/*
Structure for holding the files used for controlling the LEDs.
*/
typedef struct LedGeneric {
    FILE* trigger;
    FILE* brightness;
} LedGeneric;

typedef LedGeneric LedZero;
typedef LedGeneric LedOne;
typedef LedGeneric LedTwo;
typedef LedGeneric LedThree;

/*
Structure for holding the files used for controlling the joystick.
*/
typedef struct JoystickGeneric {
    FILE* direction;
    FILE* value;
} JoystickGeneric;

typedef JoystickGeneric JsUp;
typedef JoystickGeneric JsDown;
typedef JoystickGeneric JsRight;
typedef JoystickGeneric JsLeft;

/*
Enum for direction of a joystick.
*/
typedef enum JsDirection {UP, DOWN, RIGHT, LEFT, NONE} JsDirection;

/*
Sets up LED and GPIO pins on the BeagleBoard. Returns true if all operations succeed and false otherwise.
*/
bool configureHardware(LedZero* ledZero, LedOne* ledOne, LedTwo* ledTwo, LedThree* ledThree,
    JsUp* jsUp, JsDown* jsDown, JsRight* jsRight, JsLeft* jsLeft);

void closeHardwareFiles(LedZero* ledZero, LedOne* ledOne, LedTwo* ledTwo, LedThree* ledThree,
    JsUp* jsUp, JsDown* jsDown, JsRight* jsRight, JsLeft* jsLeft);

/*
Function for continuous execution of the contents of the game.
*/
void runGame(LedZero* ledZero, LedOne* ledOne, LedTwo* ledTwo, LedThree* ledThree,
    JsUp* jsUp, JsDown* jsDown, JsRight* jsRight, JsLeft* jsLeft);

/*
Function to make program sleep from random value between 0.5 to 3 seconds
*/
void gameSleep(void);

/*
Checks whether or not the user is already pressing up or down on the joystick
when they are not supposed to. Returns true if up or down is pressed on the joystick, false otherwise.
*/
bool tooSoonCheck(JsUp* jsUp, JsDown* jsDown);

/*
Returns the direction of the joystick pressed.
If there is no user input for 5000ms, then it returns JsDirection.NONE.
*/
JsDirection getUserInput(JsUp* jsUp, JsDown* jsDown, JsRight* jsRight, JsLeft* jsLeft);

#endif