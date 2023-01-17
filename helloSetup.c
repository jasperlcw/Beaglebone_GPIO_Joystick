#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Function taken from assignment 1 page 8 to run an external command.
*/
static void runCommand(char *command);

bool configureHardware(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree,
                       JsUp *jsUp, JsDown *jsDown, JsRight *jsRight, JsLeft *jsLeft)
{
    ledZero->trigger = fopen(LED_0_TRIGGER_PATH, "w");
    ledOne->trigger = fopen(LED_1_TRIGGER_PATH, "w");
    ledTwo->trigger = fopen(LED_2_TRIGGER_PATH, "w");
    ledThree->trigger = fopen(LED_3_TRIGGER_PATH, "w");

    ledZero->brightness = fopen(LED_0_BRIGHTNESS_PATH, "w");
    ledOne->brightness = fopen(LED_1_BRIGHTNESS_PATH, "w");
    ledTwo->brightness = fopen(LED_2_BRIGHTNESS_PATH, "w");
    ledThree->brightness = fopen(LED_3_BRIGHTNESS_PATH, "w");

    jsUp->direction = fopen(JS_UP_DIRECTION_PATH, "w");
    jsDown->direction = fopen(JS_DOWN_DIRECTION_PATH, "w");
    jsRight->direction = fopen(JS_RIGHT_DIRECTION_PATH, "w");
    jsLeft->direction = fopen(JS_LEFT_DIRECTION_PATH, "w");

    jsUp->value = fopen(JS_UP_VALUE_PATH, "w");
    jsDown->value = fopen(JS_DOWN_VALUE_PATH, "w");
    jsRight->value = fopen(JS_RIGHT_VALUE_PATH, "w");
    jsLeft->value = fopen(JS_LEFT_VALUE_PATH, "w");

    if (ledZero->trigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_0_TRIGGER_PATH);
        return false;
    }
    if (ledOne->trigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_1_TRIGGER_PATH);
        return false;
    }
    if (ledTwo->trigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_2_TRIGGER_PATH);
        return false;
    }
    if (ledThree->trigger == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_3_TRIGGER_PATH);
        return false;
    }

    if (fprintf(ledZero->trigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_0_TRIGGER_PATH);
        return false;
    }
    if (fprintf(ledOne->trigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_1_TRIGGER_PATH);
        return false;
    }
    if (fprintf(ledTwo->trigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_2_TRIGGER_PATH);
        return false;
    }
    if (fprintf(ledThree->trigger, "none") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_3_TRIGGER_PATH);
        return false;
    }

    if (ledZero->brightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_0_BRIGHTNESS_PATH);
        return false;
    }
    if (ledOne->brightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_1_BRIGHTNESS_PATH);
        return false;
    }
    if (ledTwo->brightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_2_BRIGHTNESS_PATH);
        return false;
    }
    if (ledThree->brightness == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", LED_3_BRIGHTNESS_PATH);
        return false;
    }

    if (fprintf(ledZero->brightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_0_BRIGHTNESS_PATH);
        return false;
    }
    if (fprintf(ledOne->brightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_1_BRIGHTNESS_PATH);
        return false;
    }
    if (fprintf(ledTwo->brightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_2_BRIGHTNESS_PATH);
        return false;
    }
    if (fprintf(ledThree->brightness, "0") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", LED_3_BRIGHTNESS_PATH);
        return false;
    }

    if (jsUp->direction == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_UP_DIRECTION_PATH);
        return false;
    }
    if (jsDown->direction == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_DOWN_DIRECTION_PATH);
        return false;
    }
    if (jsRight->direction == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_RIGHT_DIRECTION_PATH);
        return false;
    }
    if (jsLeft->direction == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_LEFT_DIRECTION_PATH);
        return false;
    }

    if (fprintf(jsUp->direction, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_UP_DIRECTION_PATH);
        return false;
    }
    if (fprintf(jsDown->direction, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_DOWN_DIRECTION_PATH);
        return false;
    }
    if (fprintf(jsRight->direction, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_RIGHT_DIRECTION_PATH);
        return false;
    }
    if (fprintf(jsLeft->direction, "in") <= 0)
    {
        fprintf(stderr, "Error writing to %s.\n", JS_LEFT_DIRECTION_PATH);
        return false;
    }

    if (jsUp->value == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_UP_VALUE_PATH);
        return false;
    }
    if (jsDown->value == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_DOWN_VALUE_PATH);
        return false;
    }
    if (jsRight->value == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_RIGHT_VALUE_PATH);
        return false;
    }
    if (jsLeft->value == NULL)
    {
        fprintf(stderr, "Error opening %s.\n", JS_LEFT_VALUE_PATH);
        return false;
    }

    runCommand("config-pin p8.14 gpio");
    runCommand("config-pin p8.15 gpio");
    runCommand("config-pin p8.16 gpio");
    runCommand("config-pin p8.18 gpio");

    return true;
}

void closeHardwareFiles(LedZero *ledZero, LedOne *ledOne, LedTwo *ledTwo, LedThree *ledThree,
                        JsUp *jsUp, JsDown *jsDown, JsRight *jsRight, JsLeft *jsLeft)
{
    fclose(ledZero->trigger);
    fclose(ledOne->trigger);
    fclose(ledTwo->trigger);
    fclose(ledThree->trigger);

    fclose(ledZero->brightness);
    fclose(ledOne->brightness);
    fclose(ledTwo->brightness);
    fclose(ledThree->brightness);

    fclose(jsUp->direction);
    fclose(jsDown->direction);
    fclose(jsRight->direction);
    fclose(jsLeft->direction);

    fclose(jsUp->value);
    fclose(jsDown->value);
    fclose(jsRight->value);
    fclose(jsLeft->value);
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
