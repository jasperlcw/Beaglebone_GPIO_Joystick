#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MILI_TO_NANO_SECOND 1000000L

void gameSleep()
{
    // 0.5 to 3 seconds = 500 to 3000 ms
    long nanoseconds = ((long)(rand() % 2501 + 500)) * MILI_TO_NANO_SECOND;
    struct timespec reqDelay = {0, nanoseconds};
    nanosleep(&reqDelay, (struct timespec*)NULL);
}

bool tooSoonCheck()
{
    
    return true;
}

void runGame(LedZero* ledZero, LedOne* ledOne, LedTwo* ledTwo, LedThree* ledThree,
    JsUp* jsUp, JsDown* jsDown, JsRight* jsRight, JsLeft* jsLeft)
{
    srand(time(NULL));
    printf("\nWhen the LEDs light up, press the joystick in that direction!\n(Press left or right to exit)\n");
    bool isRunning = true;
    while (isRunning) {
        printf("Get ready...\n");
        gameSleep();
        bool tooSoon = tooSoonCheck();
        if (tooSoon) {

        }
        else {

        }
    }
}