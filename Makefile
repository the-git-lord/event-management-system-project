CC = g++
FLAGS = -std=c++26 -Wall -Wextra -Werror -I ./headers
OBJS = obj/main.o obj/events.o # ui.o user.o

build/app.exe: $(OBJS)
	$(CC) -o app.exe $(OBJS) -g

obj/events.o: src/events.cpp
	$(CC) $(FLAGS) src/events.cpp

# obj/ui.o: ui.cpp ui.hpp
# 	$(CC) $(FLAGS) ui.cpp

# obj/user.o: user.cpp user.hpp
# 	$(CC) $(FLAGS) user.cpp

obj/main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp

clean:
	rm obj/*.o \ rm build/app.exe

