CC = g++
FLAGS = -Wall -Wextra -Werror
OBJS = main.o events.o ui.o

build/events: $(OBJS)
	$(CC) -o $(OBJS) -g

obj/events.o: events.cpp events.hpp
	$(CC) $(FLAGS) events.cpp

obj/ui.o: ui.cpp ui.hpp
	$(CC) $(FLAGS) ui.cpp

obj/main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

clean:
	rm *.o

