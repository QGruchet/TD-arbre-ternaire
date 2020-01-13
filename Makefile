run: compile
	./main

compile: arbre_ter.o main.o
	gcc arbre_ter.o main.o -o main

main.o: main.c
	gcc -Wall -c main.c -g

arbre.o: arbre_ter.c
	gcc -Wall -c arbre_ter.c -g


leaks: compile
	valgrind --leak-check=full --show-leak-kinds=all ./main

clean:
	rm *.o