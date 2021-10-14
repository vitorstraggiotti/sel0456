
# Info de arquivos para compilação
SRC_FILES = thread.c
OUT_NAME = test


CC = gcc
CFLAGS = -Wall -pedantic -O2
LIBS = -lpthread

.PHONY: all clean

all: $(OUT_NAME)

$(OUT_NAME): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


clean:
	rm *.o *.s $(OUT_NAME)
