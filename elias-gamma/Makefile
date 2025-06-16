# Makefile for Huffman Algorithm project
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2 -lm
LDFLAGS = 
TARGET = elias
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
