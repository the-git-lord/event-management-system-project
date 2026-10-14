CC        = g++
CFLAGS     = -std=c++26 -Wall -Wextra -Werror -I ./headers
OBJ_FILES = main.o event.o ui.o user.o input.o waitlist.o
VPATH = src:headers:obj

# $< refers to the first prerequisite of a rule
# $@ refers to the target of a rule
# VPATH helps make know where to look for the needed files

build: $(OBJ_FILES)
	$(CC) -o build/app.exe ./obj/*.o -g

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

waitlist.o: waitlist.cpp waitlist.hpp
	$(CC) $(CFLAGS) -c $< -o obj/$@

.PHONY: clean
clean:
	rm obj/*.o

