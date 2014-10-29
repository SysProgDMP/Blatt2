#include <stdio.h>
#include <stdlib.h>
#include "personen_liste.h"
#include "mystring.h"


int main(){
	char *buffer=malloc(320*sizeof(char));
	char filename;
	int sortieren;
	printf("Bitte Dateipfad des einzulesenden Files eingeben:");
	scanf("%s", &filename);
	printf("Wonach soll sortiert werden? 1=name, 2=date, 3=city");
	scanf("%i", &sortieren);
	FILE* f=fopen(&filename, "rb");		//erstellt Filepointer und öffnet Textdatei zum lesen(im Binärmodus, da sonst Unix, Windows etc untersch. Erg.)
	if(f==NULL){					//falls Datei nicht existiert Fehlermeldung + Programmende mit Fehler
		printf("Datei existiert nicht, Programm wird beendet");
		return 1;
	}
	LIST* list=malloc(1*sizeof(LIST));//Listpointer + zuweisen eines Listentyps
	while (fgets(buffer, 320, f)){
		printf("%s ", buffer);
		switch (sortieren){
			case 1: insert(&create_person_data, &sort_name, buffer, list);break;
			case 2: insert(&create_person_data, &sort_date, buffer, list);break;
			case 3: insert(&create_person_data, &sort_city, buffer, list);break;
			default: insert(&create_person_data, &sort_name, buffer, list);
		}
		
	}
	printf("\n Hier die Ausgabe\n");
	fclose(f);
	ausgabe(list);
	free(buffer);
	free_list(list);
	return 0;

}
