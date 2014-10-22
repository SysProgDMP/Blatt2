OBJECTS=springerproblem.o Brett.o
CPPFLAGS=-Wall -g


test.exe: springerproblem.o Brett.o
	gcc $(CPPFLAGS) -o test.exe $(OBJECTS)
springerproblem.o: springerproblem.c
	gcc $(CPPFLAGS) -c springerproblem.c
Brett.o: Brett.c Brett.h
	gcc $(CPPFLAGS) -c Brett.c


