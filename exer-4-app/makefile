
CC = gcc
CFLAGS = -Wno-deprecated-declarations -Wno-format-security -O2 `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

PROGNAME = test

.PHONY: all clean

all: $(PROGNAME)

$(PROGNAME): main.c interface.glade
	$(CC) -o $@ main.c $(CFLAGS)


clean:
	rm $(PROGNAME)
