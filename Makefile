OUTFILE = hello
OUTDIR = $(HOME)/Documents/CMPT_433/public/myApps
CROSS_COMPILE = arm-linux-gnueabihf-
CC_C = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -g -std=c99 -D _POSIX_C_SOURCE=200809L -Werror -Wshadow

app:
	$(CC_C) $(CFLAGS) helloMain.c helloSetup.c helloLoop.c helloUserInput.c hello.h -o $(OUTDIR)/$(OUTFILE)

clean:
	rm $(OUTDIR)/$(OUTFILE)
