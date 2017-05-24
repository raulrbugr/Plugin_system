CC = gcc
CFLAGS = -Wall -ggdb -fPIC
LDFLAGS = -fPIC -shared

TARGET = liba.so.1.0.0

all: $(TARGET)

$(TARGET): a.o a2.o
	$(CC) -Wl,-soname,liba.so.1.0.0 $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *~ *.a $(TARGET)
