CC = gcc
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
TARGET = lihf.exe

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $<

.PHONY:
clean:
	$(RM) *.o $(TARGET)	

