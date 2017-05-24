CC = gcc
CFLAGS = -Wall -ggdb -fPIC
LDFLAGS = -fPIC -shared

TARGET = libb.so

all: $(TARGET)

$(TARGET): b.o b2.o
	$(CC) -Wl,-soname,libb.so $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *~ *.a $(TARGET)
