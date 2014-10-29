#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

int  umwandeln (char buchstabe){
	switch (buchstabe){
		case 'a' : return 1; break;
		case 'A' : return 1; break;
		case 'b' : return 2; break;
		case 'B' : return 2; break;
		case 'c' : return 3; break;
		case 'C' : return 3; break;
		case 'd' : return 4; break;
		case 'D' : return 4; break;
		case 'e' : return 5; break;
		case 'E' : return 5; break;
		case 'f' : return 6; break;
		case 'F' : return 6; break;
		case 'g' : return 7; break;
		case 'G' : return 7; break;
		case 'h' : return 8; break;
		case 'H' : return 8; break;
		case 'i' : return 9; break;
		case 'I' : return 9; break;
		case 'j' : return 10; break;
		case 'J' : return 10; break;
		case 'k' : return 11; break;
		case 'K' : return 11; break;
		case 'l' : return 12; break;
		case 'L' : return 12; break;
		case 'm' : return 13; break;
		case 'M' : return 13; break;
		case 'n' : return 14; break;
		case 'N' : return 14; break;
		case 'o' : return 15; break;
		case 'O' : return 15; break;
		case 'p' : return 16; break;
		case 'P' : return 16; break;
		case 'q' : return 17; break;
		case 'Q' : return 17; break;
		case 'r' : return 18; break;
		case 'R' : return 18; break;
		case 's' : return 19; break;
		case 'S' : return 19; break;
		case 't' : return 20; break;
		case 'T' : return 20; break;
		case 'u' : return 21; break;
		case 'U' : return 21; break;
		case 'v' : return 22; break;
		case 'V' : return 22; break;
		case 'w' : return 23; break;
		case 'W' : return 23; break;
		case 'x' : return 24; break;
		case 'X' : return 24; break;
		case 'y' : return 25; break;
		case 'Y' : return 25; break;
		case 'z' : return 26; break;
		case 'Z' : return 26; break;
		case '-' : return 27; break;
		default: return 28;
		}
	}
	
	//gibt die Länge eines Char-Arrays zurück
	
int size(char *ptr){
    int offset = 0;
    int count = 0;
    while (*(ptr + offset) != '\0'){
        count++;
        offset++;
    }
    return count;
}

	// gibt 1 , 0 oder -1 zurück : 	Bei 1 ist der erste Name der, der weiter oben in der Liste stehen soll 
	//								Bei 0 sind beide Namen gleich
	//								Bei -1 ist der zweite Name der der weiter oben in der Liste stehen soll
	
int vergleich (char* vorname, char* nachname, char* vorname1, char* nachname1){
	int i ;
	for (i=0; i<101; i++){
		if (i>= size(nachname)&& i>=size (nachname1)) break;
		if (i>= size(nachname))return 1;
		if (i>=size(nachname1)) return -1;
		int Intvor = umwandeln (nachname [i]);
		int Intvor1 = umwandeln (nachname1 [i]);
		if (Intvor <Intvor1) return 1;
		if (Intvor > Intvor1) return -1;
	}	
	for (i=0; i<101; i++){
		if (i>= size(vorname)&& i>=size(vorname1)) return 0;  
		if (i>= size(vorname)) return 1;
		if (i>=size(vorname1)) return -1;
		int Intvor = umwandeln (vorname [i]);
		int Intvor1 = umwandeln (vorname1 [i]);
		if (Intvor <Intvor1) return 1;
		if (Intvor > Intvor1) return -1;
	}
	return 0;
}

int vgl(char *ort,char *ort2){
	int i, into, into2;
	
	for(i=0; i<101; i++){
		if(i>= size(ort) && i>= size(ort2))
			return 0;
		if(i>= size(ort))
			return 1;
		if(i>= size(ort2))
			return -1;
		into= umwandeln(ort[i]);
		into2= umwandeln(ort2[i]);
		if (into< into2) return 1;
		if (into> into2) return -1;
	}
	return 0;
}

