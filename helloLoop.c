#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MILI_TO_NANO_SECOND 1000000L

void gameSleep()
{
    // 0.5 to 3 seconds = 500 to 3000 ms
    long nanoseconds = ((long)(rand() % 2501 + 500)) * MILI_TO_NANO_SECOND;
    struct timespec reqDelay = {0, nanoseconds};
    nanosleep(&reqDelay, (struct timespec*)NULL);
}

bool tooSoonCheck(JsUp* jsUp, JsDown* jsDown)
{
    // Value for pressed is 0, and 1 otherwise
    const int MAX_LENGTH = 1024;
    char buf[MAX_LENGTH];
    fgets(buf, MAX_LENGTH, jsUp->value);
    if (buf[0] == '0') {
        return true;
    }
    fgets(buf, MAX_LENGTH, jsDown->value);
    if (buf[0] == '0') {
        return true;
    }
    return false;
}

void runGame(LedZero* ledZero, LedOne* ledOne, LedTwo* ledTwo, LedThree* ledThree,
    JsUp* jsUp, JsDown* jsDown, JsRight* jsRight, JsLeft* jsLeft)
{
    srand(time(NULL));
    printf("\nWhen the LEDs light up, press the joystick in that direction!\n(Press left or right to exit)\n");
    bool isRunning = true;
    while (isRunning) {
        printf("Get ready...\n");
        fprintf(ledOne->brightness, "1");
        fprintf(ledTwo->brightness, "1");
        gameSleep();
        bool tooSoon = tooSoonCheck(jsUp, jsDown);
        if (tooSoon) {
            printf("Too soon!\n");
        }
        else {
            JsDirection dir;
            if (rand() % 2 == 0) {
                dir = UP;
                printf("Press UP now!\n");
            }
            else {
                dir = DOWN;
                printf("Press DOWN now!\n");
            }

            JsDirection userInput = getUserInput(jsUp, jsDown, jsRight, jsLeft);
            if (userInput == NONE) {
                printf("No input within 5000ms; quitting!\n");
                isRunning = false;
            }
            else if (userInput == RIGHT || userInput == LEFT) {
                printf("User selected to quit.");
                isRunning = false;
            }
            else if (userInput == dir) {
                // Check reaction time
                sleep(1);
            }
            else {
                printf("Incorrect.\n");
                sleep(1);
            }
        }
    }
}