CC=g++
libs=-lm
cflags=-c -Wall -O2
objs=project_main.o project_inject.o project_algorithm.o

project: $(objs)
	$(CC) $^ -o $@ $(libs)

%.o: %.cpp
	$(CC) $(cflags) $< -o $@

clean: $(objs)
	rm *.o







