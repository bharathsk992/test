
ABC.exe:main.o bigthree.o biggnt.o
	gcc -o ABC.exe main.o bigthree.o biggnt.o

main.o:main.c
	gcc -c main.c
bigthree.o:bigthree.c
	gcc -c bigthree.c
biggnt.o:biggnt.c
	gcc -c biggnt.
