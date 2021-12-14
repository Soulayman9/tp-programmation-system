#usetest : usetest.o test.o
#	gcc -Wall -lm usetest.o test.o -o usetest
#usetest.o : usetest.c test.h
#	gcc -Wall -c usetest.c
#test.o : test.c test.h
#	gcc -Wall -c test.c


#OBJETS = usetest.o test.o

#C = gcc

#CFLAGS = -Wall -g


#usetest : $(OBJETS)
#	$(C) $(CFLAGS) $(OBJETS) -o usetest -lm
#usetest.o : usetest.c test.h
#	$(C) -c usetest.c
#test.o : test.c test.h
#	$(C) -c test.c



table= test.o 
inv = usetest.o

CC = gcc

all : $(APPLI)clean 

$(APPLI) : $(APPLI).o test.o
	gcc -Wall $(APPLI).o test.o -o $(APPLI).c

test.o : test.c test.h
	gcc -Wall -c test.o

# suppresion des fichiers objet
clean : $(APPLI)
	rm -f *.o
