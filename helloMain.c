#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    LedZero ledZero;
    LedOne ledOne;
    LedTwo ledTwo;
    LedThree ledThree;

    JsUp jsUp;
    JsDown jsDown;
    JsRight jsRight;
    JsLeft jsLeft;

    bool setupStatus = configureHardware(&ledZero, &ledOne, &ledTwo, &ledThree, &jsUp, &jsDown, &jsRight, &jsLeft);
    if (setupStatus == false)
    {
        closeHardwareFiles(&ledZero, &ledOne, &ledTwo, &ledThree, &jsUp, &jsDown, &jsRight, &jsLeft);
        exit(1);
    }

    printf("Hello embedded world, from Jasper Wong!\n");
    // runGame(&ledZero, &ledOne, &ledTwo, &ledThree, &jsUp, &jsDown, &jsRight, &jsLeft);

    closeHardwareFiles(&ledZero, &ledOne, &ledTwo, &ledThree, &jsUp, &jsDown, &jsRight, &jsLeft);
    return 0;
}
