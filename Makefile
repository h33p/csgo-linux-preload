
CC		= gcc
CFLAGS	= -shared -Wall -Werror -fPIC -ldl

TARGET  = inject.so
SOURCES	= $(wildcard *.c)
OBJECTS	= $(SOURCES:.c=.o)


all: $(TARGET)
clean:
	rm *.o *.so

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)


