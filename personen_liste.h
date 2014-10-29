#ifndef _PERSONEN_LIST_H
#define _PERSONEN_LISTE_H

//definiert die Struktur eines Geburtsdatums
typedef struct GEBDATUM{
	int tag;
	int monat;
	int jahr;
}GEBDATUM;
// definiert die Struktur von Personendaten
typedef struct PDATA{
	char *vorname;
	char *nachname;
	GEBDATUM *geb;
	char *ort;
}PDATA;

//definiert die Struktur eines Nodes
typedef struct NODE{
	struct NODE* next;
	void *data;
}NODE;
// definiert die Struktur einer Liste
typedef struct LIST{
	NODE *head;
}LIST;

LIST *list_create();
NODE *node_create(void* (*data_create)(char *input), char *input);
void insert(void* (*data_create)(char *input), void (*sort)(NODE *tmp, LIST *l),char *input, LIST* l);
void ausgabe(LIST *l);
void free_list(LIST *l);
int gebvgl(GEBDATUM *tmp, GEBDATUM *cursor);
void sort_name(NODE *tmp, LIST *l);
void sort_date(NODE *tmp, LIST *l);
void sort_city(NODE *tmp, LIST *l);
void *create_person_data(char *input);
#endif
