CC=gcc
libs=-lm
objs=random_array.o main.o

monty: $(objs)
	$(CC) $^ -o $@ $(libs)

main.o: main.c
	$(CC) -c $^ -o $@

random_array.o: random_array.c
	$(CC) -c $^ -o $@

clean: $(objs)
	rm $^

