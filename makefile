ABC.exe:main.o big.o fact.o 
	gcc -o ABC.exe main.o big.o fact.o 
main.o:main.c
	gcc -c main.c
big.o:big.c
	gcc -c big.c
fact.o:fact.c
	gcc -c fact.c
