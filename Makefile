CC        = g++
FLAGS     = -std=c++26 -Wall -Wextra -Werror -I ./headers
OBJ_FILES = main.o event.o user.o

build: $(OBJ_FILES)
	$(CC) -o build/app.exe obj/main.o obj/event.o obj/user.o -g

main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp -o obj/main.o

event.o: src/event.cpp headers/event.hpp
	$(CC) $(FLAGS) -c src/event.cpp -o obj/event.o

# ui.o: src/ui.cpp headers/ui.hpp
# 	$(CC) $(FLAGS) -c src/ui.cpp

user.o: src/user.cpp headers/user.hpp
	$(CC) $(FLAGS) -c src/user.cpp -o obj/user.o

clean:
	rm obj/*.o

