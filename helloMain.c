#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool setupStatus = configureHardware();
    if (setupStatus == false) { exit(1); }

    printf("Hello embedded world, from Jasper Wong!\n");
    runGame();

    return 0;
}
