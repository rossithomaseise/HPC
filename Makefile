projet: aleatoire.o ecosys.o principal.o
	gcc aleatoire.o ecosys.o  principal.o -o projet
	
principal.o: principal.c aleatoire.h ecosys.h
	gcc -c principal.c
	
ecosys.o:	ecosys.h ecosys.c
	gcc -c ecosys.c

aleatoire.o: aleatoire.h aleatoire.c
	gcc -c aleatoire.c
	
clean:
	rm *.o