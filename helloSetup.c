#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Function taken from assignment 1 page 8 to run an external command.
*/
static void runCommand(char *command);

bool configureHardware()
{
    runCommand("config-pin p8.14 gpio");
    runCommand("config-pin p8.15 gpio");
    runCommand("config-pin p8.16 gpio");
    runCommand("config-pin p8.18 gpio");
    
    FILE* ledZeroTrigger = fopen(LED_0_TRIGGER_PATH, "r+");
    FILE* ledOneTrigger = fopen(LED_1_TRIGGER_PATH, "r+");
    FILE* ledTwoTrigger = fopen(LED_2_TRIGGER_PATH, "r+");
    FILE* ledThreeTrigger = fopen(LED_3_TRIGGER_PATH, "r+");

    FILE* ledZeroBrightness = fopen(LED_0_BRIGHTNESS_PATH, "r+");
    FILE* ledOneBrightness = fopen(LED_1_BRIGHTNESS_PATH, "r+");
    FILE* ledTwoBrightness = fopen(LED_2_BRIGHTNESS_PATH, "r+");
    FILE* ledThreeBrightness = fopen(LED_3_BRIGHTNESS_PATH, "r+");

    FILE* jsUpDirection = fopen(JS_UP_DIRECTION_PATH, "r+");
    FILE* jsDownDirection = fopen(JS_DOWN_DIRECTION_PATH, "r+");
    FILE* jsRightDirection = fopen(JS_RIGHT_DIRECTION_PATH, "r+");
    FILE* jsLeftDirection = fopen(JS_LEFT_DIRECTION_PATH, "r+");

    FILE* jsUpValue = fopen(JS_UP_VALUE_PATH, "r+");
    FILE* jsDownValue = fopen(JS_DOWN_VALUE_PATH, "r+");
    FILE* jsRightValue = fopen(JS_RIGHT_VALUE_PATH, "r+");
    FILE* jsLeftValue = fopen(JS_LEFT_VALUE_PATH, "r+");

    if (ledZeroTrigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_0_TRIGGER_PATH);
        return false;
    }
    if (ledOneTrigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_1_TRIGGER_PATH);
        return false;
    }
    if (ledTwoTrigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_2_TRIGGER_PATH);
        return false;
    }
    if (ledThreeTrigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_3_TRIGGER_PATH);
        return false;
    }

    if (fprintf(ledZeroTrigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_0_TRIGGER_PATH);
        return false;
    }
    if (fprintf(ledOneTrigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_1_TRIGGER_PATH);
        return false;
    }
    if (fprintf(ledTwoTrigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_2_TRIGGER_PATH);
        return false;
    }
    if (fprintf(ledThreeTrigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_3_TRIGGER_PATH);
        return false;
    }

    if (ledZeroBrightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_0_BRIGHTNESS_PATH);
        return false;
    }
    if (ledOneBrightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_1_BRIGHTNESS_PATH);
        return false;
    }
    if (ledTwoBrightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_2_BRIGHTNESS_PATH);
        return false;
    }
    if (ledThreeBrightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_3_BRIGHTNESS_PATH);
        return false;
    }

    if (fprintf(ledZeroBrightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_0_BRIGHTNESS_PATH);
        return false;
    }
    if (fprintf(ledOneBrightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_1_BRIGHTNESS_PATH);
        return false;
    }
    if (fprintf(ledTwoBrightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_2_BRIGHTNESS_PATH);
        return false;
    }
    if (fprintf(ledThreeBrightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_3_BRIGHTNESS_PATH);
        return false;
    }

    if (jsUpDirection == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_UP_DIRECTION_PATH);
        return false;
    }
    if (jsDownDirection == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_DOWN_DIRECTION_PATH);
        return false;
    }
    if (jsRightDirection == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_RIGHT_DIRECTION_PATH);
        return false;
    }
    if (jsLeftDirection == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_LEFT_DIRECTION_PATH);
        return false;
    }

    if (fprintf(jsUpDirection, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_UP_DIRECTION_PATH);
        return false;
    }
    if (fprintf(jsDownDirection, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_DOWN_DIRECTION_PATH);
        return false;
    }
    if (fprintf(jsRightDirection, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_RIGHT_DIRECTION_PATH);
        return false;
    }
    if (fprintf(jsLeftDirection, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_LEFT_DIRECTION_PATH);
        return false;
    }

    if (jsUpValue == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_UP_VALUE_PATH);
        return false;
    }
    if (jsDownValue == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_DOWN_VALUE_PATH);
        return false;
    }
    if (jsRightValue == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_RIGHT_VALUE_PATH);
        return false;
    }
    if (jsLeftValue == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_LEFT_VALUE_PATH);
        return false;
    }

    fclose(ledZeroTrigger);
    fclose(ledOneTrigger);
    fclose(ledTwoTrigger);
    fclose(ledThreeTrigger);

    fclose(ledZeroBrightness);
    fclose(ledOneBrightness);
    fclose(ledTwoBrightness);
    fclose(ledThreeBrightness);

    fclose(jsUpDirection);
    fclose(jsDownDirection);
    fclose(jsRightDirection);
    fclose(jsLeftDirection);

    fclose(jsUpValue);
    fclose(jsDownValue);
    fclose(jsRightValue);
    fclose(jsLeftValue);
    
    return true;
}

static void runCommand(char *command)
{
    // Execute the shell command (output into pipe)
    FILE *pipe = popen(command, "r");
    // Ignore output of the command; but consume it
    // so we don't get an error when closing the pipe.
    char buffer[1024];
    while (!feof(pipe) && !ferror(pipe))
    {
        if (fgets(buffer, sizeof(buffer), pipe) == NULL)
            break;
        // printf("--> %s", buffer); // Uncomment for debugging
    }
    // Get the exit code from the pipe; non-zero is an error:
    int exitCode = WEXITSTATUS(pclose(pipe));
    if (exitCode != 0)
    {
        perror("Unable to execute command:");
        printf(" command: %s\n", command);
        printf(" exit code: %d\n", exitCode);
    }
}
