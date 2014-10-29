OBJECTS=Haupt.o personen_liste.o mystring.o
CPPFLAGS=-Wall -g


test.exe: Haupt.o personen_liste.o mystring.o
	gcc $(CPPFLAGS) -o test.exe $(OBJECTS)
personen_liste.o: personen_liste.c personen_liste.h
	gcc $(CPPFLAGS) -c personen_liste.c
mystring.o: mystring.c mystring.h
	gcc $(CPPFLAGS) -c mystring.c
Haupt.o: Haupt.c
	gcc $(CPPFLAGS) -c Haupt.c

