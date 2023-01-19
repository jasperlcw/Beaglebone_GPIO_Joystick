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
Enum for direction of a joystick.
*/
typedef enum JsDirection
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    NONE
} JsDirection;

/*
Sets up LED and GPIO pins on the BeagleBoard for the game to run.
Returns true if all operations succeed and false otherwise.
*/
bool configureHardware();;

/*
Function for continuous execution of the contents of the game.
*/
void runGame(void);

/*
Function to make program sleep from random value between 0.5 to 3 seconds
*/
void gameSleep(void);

/*
A variant of getUserInput that gets the status of the joystick inputs once.
Returns the direction of the joystick pressed.
*/
JsDirection tooSoonCheck(void);

/*
Returns the direction of the joystick pressed.
If there is no user input for 5000ms, then it returns JsDirection.NONE.
*/
JsDirection getUserInput(void);

/*
Displays the LED animation sequence when the player presses the correct direction.
*/
void correctFlashLight(void);

/*
Displays the LED animation sequence when the player presses the wrong direction.
*/
void incorrectFlashLight(void);

/*
Turns off all four LEDs on the BeagleBoard.
*/
void ledsOff(void);

/*
Turns on all four LEDs on the BeagleBoard.
*/
void ledsOn(void);

/*
Turns on the lights in the pattern as defined for when the player is supposed to get ready.
*/
void getReadyLights(void);

/*
Turns on the lights for moving the joystick up.
*/
void jsUpLights(void);

/*
Turns on the lights for moving the joystick down.
*/
void jsDownLights(void);

#endif