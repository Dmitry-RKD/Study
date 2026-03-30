all: area_calc

area_calc: main.o 
	gcc -o area_calc main.o
	
main.o: main.c
	gcc -c main.c

clean: 
	del *.o 
	del area_calc.exe
