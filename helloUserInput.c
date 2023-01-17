#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static long long getTimeInMs(void);

JsDirection getUserInput(JsUp* jsUp, JsDown* jsDown, JsRight* jsRight, JsLeft* jsLeft)
{
    long long timeLimitInMs = 5000;
    long long initialTime = getTimeInMs();
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
