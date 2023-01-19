#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static long long getTimeInMs(void);
static void sleepForMs(long long delayInMs);

void gameSleep(void)
{
    // 0.5 to 3 seconds = 500 to 3000 ms
    long long milliseconds = ((long long)(rand() % 2501 + 500));
    sleepForMs(milliseconds);
}

void runGame(void)
{
    srand(time(NULL));
    printf("\nWhen the LEDs light up, press the joystick in that direction!\n(Press left or right to exit)\n");
    bool isRunning = true;
    long long bestTime = 9223372036854775807; // LONG_MAX
    while (isRunning)
    {
        printf("Get ready...\n");
        getReadyLights();
        gameSleep();
        // bool tooSoon = tooSoonCheck();
        // if (tooSoon)
        // {
        //     printf("Too soon!\n");
        //     ledsOff();
        //     sleepForMs(1000);
        // }
        JsDirection tooSoonVal = tooSoonCheck();
        if (tooSoonVal == UP || tooSoonVal == DOWN)
        {
            printf("Too soon!\n");
            ledsOff();
            sleepForMs(1000);
        }
        else if (tooSoonVal == RIGHT || tooSoonVal == LEFT)
        {
            printf("User selected to quit.\n");
            isRunning = false;
        }
        else
        {
            JsDirection dir;
            ledsOff();
            if (rand() % 2 == 0)
            {
                dir = UP;
                printf("Press UP now!\n");
                jsUpLights();
            }
            else
            {
                dir = DOWN;
                printf("Press DOWN now!\n");
                jsDownLights();
            }

            long long startTime = getTimeInMs();
            JsDirection userInput = getUserInput();
            if (userInput == NONE)
            {
                printf("No input within 5000ms; quitting!\n");
                isRunning = false;
            }
            else if (userInput == RIGHT || userInput == LEFT)
            {
                printf("User selected to quit.\n");
                isRunning = false;
            }
            else if (userInput == dir)
            {
                long long attemptTime = getTimeInMs() - startTime;
                if (attemptTime < bestTime)
                {
                    bestTime = attemptTime;
                    printf("New best time!\n");
                }
                printf("Your reaction time was %lldms; best so far in game is %lldms.\n", attemptTime, bestTime);
                correctFlashLight();
                sleepForMs(1000);
            }
            else
            {
                printf("Incorrect.\n");
                incorrectFlashLight();
                sleepForMs(1000);
            }

        }
        ledsOff();
    }
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
