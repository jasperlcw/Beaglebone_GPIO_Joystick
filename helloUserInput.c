#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static long long getTimeInMs(void);

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

JsDirection getUserInput(JsUp *jsUp, JsDown *jsDown, JsRight *jsRight, JsLeft *jsLeft)
{
    long long timeLimitInMs = 5000;
    long long initialTime = getTimeInMs();
    const int MAX_LENGTH = 1024;
    char buf[MAX_LENGTH];

    while (getTimeInMs() - initialTime < timeLimitInMs)
    {
        fgets(buf, MAX_LENGTH, jsUp->value);
        if (buf[0] == '0')
        {
            return UP;
        }
        fgets(buf, MAX_LENGTH, jsDown->value);
        if (buf[0] == '0')
        {
            return DOWN;
        }
        fgets(buf, MAX_LENGTH, jsRight->value);
        if (buf[0] == '0')
        {
            return RIGHT;
        }
        fgets(buf, MAX_LENGTH, jsLeft->value);
        if (buf[0] == '0')
        {
            return LEFT;
        }
    }

    // Time exceeded here
    return NONE;
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
