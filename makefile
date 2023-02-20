TARGET = snake

CC := gcc
CCFLAGS := -std=gnu99 -lncurses -lpthread

SOURCES := $(wildcard ./src/*.c)
HEADERS := ./include

$(TARGET):
	$(CC) $(CCFLAGS) -I$(HEADERS) $(SOURCES) main.c -o $(TARGET)
