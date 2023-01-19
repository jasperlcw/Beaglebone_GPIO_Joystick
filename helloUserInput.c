#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static long long getTimeInMs(void);
static char firstCharFromFile(char *filename);

JsDirection tooSoonCheck(void)
{
    // Value for pressed is 0, and 1 otherwise
    char readValue = firstCharFromFile(JS_UP_VALUE_PATH);
    if (readValue == '0')
    {
        return UP;
    }

    readValue = firstCharFromFile(JS_DOWN_VALUE_PATH);
    if (readValue == '0')
    {
        return DOWN;
    }

    readValue = firstCharFromFile(JS_RIGHT_VALUE_PATH);
    if (readValue == '0')
    {
        return RIGHT;
    }

    readValue = firstCharFromFile(JS_LEFT_VALUE_PATH);
    if (readValue == '0')
    {
        return LEFT;
    }

    return NONE;
}

JsDirection getUserInput(void)
{
    long long timeLimitInMs = 5000;
    long long initialTime = getTimeInMs();

    while (getTimeInMs() - initialTime < timeLimitInMs)
    {

        char readValue = firstCharFromFile(JS_UP_VALUE_PATH);
        if (readValue == '0')
        {
            return UP;
        }

        readValue = firstCharFromFile(JS_DOWN_VALUE_PATH);
        if (readValue == '0')
        {
            return DOWN;
        }

        readValue = firstCharFromFile(JS_RIGHT_VALUE_PATH);
        if (readValue == '0')
        {
            return RIGHT;
        }

        readValue = firstCharFromFile(JS_LEFT_VALUE_PATH);
        if (readValue == '0')
        {
            return LEFT;
        }
    }

    // Time exceeded here
    return NONE;
}

// Below functions taken from the assignment 1 pdf.
static long long getTimeInMs(void)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long long seconds = spec.tv_sec;
    long long nanoSeconds = spec.tv_nsec;
    long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;
    return milliSeconds;
}

static char firstCharFromFile(char *fileName)
{
    FILE *pFile = fopen(fileName, "r");
    if (pFile == NULL)
    {
        printf("ERROR: Unable to open file (%s) for read\n", fileName);
        exit(-1);
    }
    // Read string (line)
    const int MAX_LENGTH = 1024;
    char buff[MAX_LENGTH];
    fgets(buff, MAX_LENGTH, pFile);
    // Close
    fclose(pFile);
    // printf("Read: '%s'\n", buff);
    return buff[0];
}
