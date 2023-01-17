#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static long long getTimeInMs(void);
static void sleepForMs(long long delayInMs);
static void correctFlashLight(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree);
static void incorrectFlashLight(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree);
static void ledOff(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree);

void gameSleep(void)
{
    // 0.5 to 3 seconds = 500 to 3000 ms
    long long milliseconds = ((long long)(rand() % 2501 + 500));
    sleepForMs(milliseconds);
}

bool tooSoonCheck(JsUp *jsUp, JsDown *jsDown)
{
    // Value for pressed is 0, and 1 otherwise
    const int MAX_LENGTH = 1024;
    char buf[MAX_LENGTH];
    fgets(buf, MAX_LENGTH, jsUp->value);
    if (buf[0] == '0')
    {
        return true;
    }
    fgets(buf, MAX_LENGTH, jsDown->value);
    if (buf[0] == '0')
    {
        return true;
    }
    return false;
}

void runGame(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree,
             JsUp *jsUp, JsDown *jsDown, JsRight *jsRight, JsLeft *jsLeft)
{
    srand(time(NULL));
    printf("\nWhen the LEDs light up, press the joystick in that direction!\n(Press left or right to exit)\n");
    bool isRunning = true;
    long long bestTime = 9223372036854775807; // LONG_MAX
    while (isRunning)
    {
        printf("Get ready...\n");
        fprintf(ledOne->brightness, "1");
        fprintf(ledTwo->brightness, "1");
        gameSleep();
        bool tooSoon = tooSoonCheck(jsUp, jsDown);
        if (tooSoon)
        {
            printf("Too soon!\n");
        }
        else
        {
            JsDirection dir;
            ledOff(ledZero, ledOne, ledTwo, ledThree);
            if (rand() % 2 == 0)
            {
                dir = UP;
                printf("Press UP now!\n");
                fprintf(ledZero->brightness, "1");
            }
            else
            {
                dir = DOWN;
                printf("Press DOWN now!\n");
                fprintf(ledThree->brightness, "1");
            }

            long long startTime = getTimeInMs();
            JsDirection userInput = getUserInput(jsUp, jsDown, jsRight, jsLeft);
            if (userInput == NONE)
            {
                printf("No input within 5000ms; quitting!\n");
                isRunning = false;
            }
            else if (userInput == RIGHT || userInput == LEFT)
            {
                printf("User selected to quit.");
                isRunning = false;
            }
            else if (userInput == dir)
            {
                long long attemptTime = getTimeInMs() - startTime;
                if (attemptTime < bestTime) {
                    bestTime = attemptTime;
                    printf("New best time!\n");
                }
                printf("Your reaction time was %lld; best so far in game is %lld.\n", attemptTime, bestTime);
                correctFlashLight(ledZero, ledOne, ledTwo, ledThree);
                sleepForMs(1000);
            }
            else
            {
                printf("Incorrect.\n");
                incorrectFlashLight(ledZero, ledOne, ledTwo, ledThree);
                sleepForMs(1000);
            }

            ledOff(ledZero, ledOne, ledTwo, ledThree);
        }
    }
}

static void correctFlashLight(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree)
{
    for (int i = 0; i < 2; ++i)
    {
        fprintf(ledZero->brightness, "1");
        fprintf(ledOne->brightness, "1");
        fprintf(ledTwo->brightness, "1");
        fprintf(ledThree->brightness, "1");
        sleepForMs(125);
        fprintf(ledZero->brightness, "0");
        fprintf(ledOne->brightness, "0");
        fprintf(ledTwo->brightness, "0");
        fprintf(ledThree->brightness, "0");
        sleepForMs(125);
    }
}

static void incorrectFlashLight(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree)
{
    for (int i = 0; i < 10; ++i)
    {
        fprintf(ledZero->brightness, "1");
        fprintf(ledOne->brightness, "1");
        fprintf(ledTwo->brightness, "1");
        fprintf(ledThree->brightness, "1");
        sleepForMs(50);
        fprintf(ledZero->brightness, "0");
        fprintf(ledOne->brightness, "0");
        fprintf(ledTwo->brightness, "0");
        fprintf(ledThree->brightness, "0");
        sleepForMs(50);
    }
}

static void ledOff(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree)
{
    fprintf(ledZero->brightness, "0");
    fprintf(ledOne->brightness, "0");
    fprintf(ledTwo->brightness, "0");
    fprintf(ledThree->brightness, "0");
}

// Below functions taken from page 7 of the assignment 1 pdf.
static long long getTimeInMs(void)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long long seconds = spec.tv_sec;
    long long nanoSeconds = spec.tv_nsec;
    long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;
    return milliSeconds;
}

static void sleepForMs(long long delayInMs)
{
    const long long NS_PER_MS = 1000 * 1000;
    const long long NS_PER_SECOND = 1000000000;
    long long delayNs = delayInMs * NS_PER_MS;
    int seconds = delayNs / NS_PER_SECOND;
    int nanoseconds = delayNs % NS_PER_SECOND;
    struct timespec reqDelay = {seconds, nanoseconds};
    nanosleep(&reqDelay, (struct timespec *)NULL);
}
