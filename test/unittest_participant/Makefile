
CC = g++
CFLAGS = -std=c++26 -Wall -Wextra -Werror -I../../headers

TARGET = ../../build/test_participant

build:
	mkdir -p ../../build
	$(CC) $(CFLAGS) ut_participant.cpp ../../src/event.cpp ../../src/user.cpp -o $(TARGET)

test: build
	$(TARGET)

clean:
	rm -f $(TARGET)
