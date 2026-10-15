CC        = g++
CFLAGS     = -std=c++26 -Wall -Wextra -Werror -I ./headers
OBJ_FILES = main.o event.o ui.o user.o input.o
VPATH = src:headers:obj

build: $(OBJ_FILES)
	$(CC) -o build/app.exe obj/main.o obj/event.o obj/user.o -g

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o obj/$@

event.o: event.cpp event.hpp
	$(CC) $(CFLAGS) -c $< -o obj/$@

ui.o: ui.cpp ui.hpp
	$(CC) $(CFLAGS) -c $< -o obj/$@

user.o: user.cpp user.hpp
	$(CC) $(CFLAGS) -c $< -o obj/$@

input.o: input.cpp input.hpp
	$(CC) $(CFLAGS) -c $< -o obj/$@

.PHONY: clean
clean:
	rm obj/*.o

