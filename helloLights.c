#include "hello.h"

#include <stdio.h>
#include <time.h>

static void turnOnLight(char *filename);
static void turnOffLight(char *filename);
static void sleepForMs(long long delayInMs);

void correctFlashLight(void)
{
    for (int i = 0; i < 2; ++i)
    {
        ledsOn();
        sleepForMs(125);
        ledsOff();
        sleepForMs(125);
    }
}

void incorrectFlashLight(void)
{
    for (int i = 0; i < 10; ++i)
    {
        ledsOn();
        sleepForMs(50);
        ledsOff();
        sleepForMs(50);
    }
}

void ledsOff(void)
{
    turnOffLight(LED_0_BRIGHTNESS_PATH);
    turnOffLight(LED_1_BRIGHTNESS_PATH);
    turnOffLight(LED_2_BRIGHTNESS_PATH);
    turnOffLight(LED_3_BRIGHTNESS_PATH);
}

void ledsOn(void)
{
    turnOnLight(LED_0_BRIGHTNESS_PATH);
    turnOnLight(LED_1_BRIGHTNESS_PATH);
    turnOnLight(LED_2_BRIGHTNESS_PATH);
    turnOnLight(LED_3_BRIGHTNESS_PATH);
}

void getReadyLights(void)
{
    turnOffLight(LED_0_BRIGHTNESS_PATH);
    turnOnLight(LED_1_BRIGHTNESS_PATH);
    turnOnLight(LED_2_BRIGHTNESS_PATH);
    turnOffLight(LED_3_BRIGHTNESS_PATH);
}

void jsUpLights(void)
{
    ledsOff();
    turnOnLight(LED_0_BRIGHTNESS_PATH);
}

void jsDownLights(void)
{
    ledsOff();
    turnOnLight(LED_3_BRIGHTNESS_PATH);
}

static void turnOnLight(char *filename)
{
    FILE *brightnessFile = fopen(filename, "w");
    if (brightnessFile == NULL)
    {
        fprintf(stderr, "Error opening %s. Exiting.\n", filename);
        exit(1);
    }
    if (fprintf(brightnessFile, "1") < 0)
    {
        fprintf(stderr, "Error turning on the light. Exiting.\n");
        exit(1);
    }
    fclose(brightnessFile);
}

static void turnOffLight(char *filename)
{
    FILE *brightnessFile = fopen(filename, "w");
    if (brightnessFile == NULL)
    {
        fprintf(stderr, "Error opening %s. Exiting.\n", filename);
        exit(1);
    }
    if (fprintf(brightnessFile, "0") < 0)
    {
        fprintf(stderr, "Error turning on the light. Exiting.\n");
        exit(1);
    }
    fclose(brightnessFile);
}

// Below functions taken from page 7 of the assignment 1 pdf.
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
