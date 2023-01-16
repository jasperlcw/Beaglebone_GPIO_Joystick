#include <stdio.h>
#include <stdlib.h>

#define LED_0_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr0/trigger"
#define LED_1_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr1/trigger"
#define LED_2_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr2/trigger"
#define LED_3_TRIGGER_PATH "/sys/class/leds/beaglebone:green:usr3/trigger"
#define LED_0_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED_1_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED_2_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED_3_BRIGHTNESS_PATH "/sys/class/leds/beaglebone:green:usr3/brightness"

int main() {
    printf("Hello embedded world, from Jasper Wong!\n");

    FILE* ledZeroTrigger = fopen(LED_0_TRIGGER_PATH, "w");
    FILE* ledOneTrigger = fopen(LED_1_TRIGGER_PATH, "w");
    FILE* ledTwoTrigger = fopen(LED_2_TRIGGER_PATH, "w");
    FILE* ledThreeTrigger = fopen(LED_3_TRIGGER_PATH, "w");

    if (ledZeroTrigger == NULL) {
        fprintf(stderr, "Error opening %s.\n", LED_0_TRIGGER_PATH);
        exit(1);
    }
    if (ledOneTrigger == NULL) {
        fprintf(stderr, "Error opening %s.\n", LED_1_TRIGGER_PATH);
        exit(1);
    }
    if (ledTwoTrigger == NULL) {
        fprintf(stderr, "Error opening %s.\n", LED_2_TRIGGER_PATH);
        exit(1);
    }
    if (ledThreeTrigger == NULL) {
        fprintf(stderr, "Error opening %s.\n", LED_3_TRIGGER_PATH);
        exit(1);
    }

    if (fprintf(ledZeroTrigger, "none") <= 0) {
        printf("Error writing data. Exiting.");
        exit(1);
    }

    printf("All LED trigger files successfully opened.\n");

    FILE* ledZeroBrightness = fopen(LED_0_BRIGHTNESS_PATH, "w");
    if (ledZeroBrightness == NULL) {
        fprintf(stderr, "Error opening %s.\n", LED_0_BRIGHTNESS_PATH);
        exit(1);
    }

    if (fprintf(ledZeroBrightness, "0") <= 0) {
        printf("Error writing data. Exiting.");
        exit(1);
    }

    fclose(ledZeroTrigger);
    fclose(ledOneTrigger);
    fclose(ledTwoTrigger);
    fclose(ledThreeTrigger);

    return 0;
}
