#include <stdio.h>
#include <stdlib.h>
#include "personen_liste.h"
#include "mystring.h"
LIST *list_create(){
	LIST *l=malloc(1*sizeof(LIST));
	if(l==NULL){
		printf("Fehler beim Erstellen der Liste");
	}
	return l;
}

NODE *node_create(void* (*data_create)(char *input), char *input){
	NODE *n=malloc(1*sizeof(NODE));
	if(n==NULL){
		printf("FEHLER beim Erstellen eines Nodes");
		return n;
	}
	n->data=(*data_create)(input);
	return n;
}

void *create_person_data(char *input){
	PDATA *d=malloc(sizeof(PDATA));
	
	int i, j,cnt=0;
	((PDATA*)d)->vorname=malloc(101*sizeof(char));
	((PDATA*)d)->nachname=malloc(101*sizeof(char));
	for(i=0; input[i]!=' '; i++){
			d->vorname[i]=input[i];
		}
		d->vorname[i]='\0';
		i++;
		d->vorname=realloc(d->vorname,i*sizeof(char));
		j=i;
		for(;input[i]!=' ';i++){
			d->nachname[i-j]=input[i];
			cnt++;
		}
		d->nachname[i-j]='\0';
		d->nachname=realloc(d->nachname,(cnt+1)*sizeof(char));
		i++;
		d->geb=malloc(1*sizeof(GEBDATUM));
		char zahlen[5];
		
		for(j=0;input[i]!=' '; i++, j++){
			zahlen[j]=input[i];
		}
		zahlen[j]='\0';
		d->geb->tag=atoi((const char *)&zahlen);
		printf("%i. ", d->geb->tag);
		i++;
		for(j=0;input[i]!=' '; i++, j++){
			zahlen[j]=input[i];
		}
		zahlen[j]='\0';
		d->geb->monat=atoi((const char *)&zahlen);
		printf("%i. ", d->geb->monat);
		i++;
		for(j=0;input[i]!=' '; i++, j++){
			zahlen[j]=input[i];
		}
		zahlen[j]='\0';
		d->geb->jahr=atoi((const char *)&zahlen);
		printf("%i ", d->geb->jahr);
		i++;
		j=i;
		cnt=0;
		d->ort=malloc(101*sizeof(char));
		for(;input[i]!='\0';i++){
			d->ort[i-j]=input[i];
			cnt++;
		}printf("%s \n", d->ort);
		d->ort[i-j]=input[i];
		d->ort=realloc(d->ort, (cnt+1)*sizeof(char));
		return d;
}


void insert(void* (*data_create)(char *input), void* (*sort)(NODE *tmp, LIST *l), char *input, LIST *l){
	NODE *tmp=node_create((data_create), input);
	if(l->head==NULL){
		l->head=tmp;
		return;
	}
		
	(*sort)(tmp, l);
	
}

void sort_name(NODE *tmp, LIST *l){
	NODE *cursor=l->head;
	
	if(vergleich(((PDATA*)tmp->data)->vorname, ((PDATA*)tmp->data)->nachname, ((PDATA*)cursor->data)->vorname, ((PDATA*)cursor->data)->nachname)<0){
		tmp->next=cursor;
		l->head=tmp;
		return;
	}
	cursor=cursor->next;
	NODE *cursor2=l->head;
	while (cursor!=NULL){
		if(vergleich(((PDATA*)tmp->data)->vorname, ((PDATA*)tmp->data)->nachname, ((PDATA*)cursor->data)->vorname, ((PDATA*)cursor->data)->nachname)<0){
			tmp->next=cursor;
			cursor2->next=tmp;
			return;
		}
		cursor=cursor->next;
		cursor2=cursor2->next;
	}
	tmp->next=cursor;
	cursor2->next=tmp;
}
int gebvgl(GEBDATUM *tmp, GEBDATUM *cursor){
	if((tmp->jahr)<(cursor->jahr)){
		return -1;
	}
	if((tmp->jahr)>(cursor->jahr))
		return 1;
	if(tmp->monat<cursor->monat){
		return -1;
	}
	if(tmp->monat>cursor->monat)
		return 1;
	if(tmp->tag<cursor->tag){
		return -1;
	}
	return 1;
}
void sort_date(NODE *tmp, LIST *l){
	NODE *cursor=l->head;
	if(gebvgl(((PDATA*)tmp->data)->geb, ((PDATA*)cursor->data)->geb)<0){
		tmp->next=cursor;
		l->head=tmp;
		return;
	}
	cursor=cursor->next;
	NODE *cursor2=l->head;
	while(cursor!=NULL){
		if(gebvgl(((PDATA*)tmp->data)->geb, ((PDATA*)cursor->data)->geb)<0){
			tmp->next=cursor;
			cursor2->next=tmp;
			return;
		}
		cursor=cursor->next;
		cursor2=cursor2->next;
	}
	tmp->next=cursor;
	cursor2->next=tmp;
}

void sort_city(NODE *tmp, LIST *l){
	NODE *cursor=l->head;
	if(vgl(((PDATA*)tmp->data)->ort,((PDATA*)cursor->data)->ort)<0){
		tmp->next=cursor;
		l->head=tmp;
		return;
	}
	
	cursor=cursor->next;
	NODE *cursor2=l->head;
	while (cursor!=NULL){
		if(vgl(((PDATA*)tmp->data)->ort,((PDATA*)cursor->data)->ort)<0){
			tmp->next=cursor;
			cursor2->next=tmp;
			return;
		}
		cursor=cursor->next;
		cursor2=cursor2->next;
	}
	tmp->next=cursor;
	cursor2->next=tmp;
}

void ausgabe(LIST *l){
	NODE *cursor=l->head;
	while(cursor!=NULL){
		printf("%s %s %i.%i.%i ort: %s\n",((PDATA*)cursor->data)->nachname , ((PDATA*)cursor->data)->vorname, ((PDATA*)cursor->data)->geb->tag, ((PDATA*)cursor->data)->geb->monat, ((PDATA*)cursor->data)->geb->jahr, ((PDATA*)cursor->data)->ort);
		cursor=cursor->next;
	}
}

void free_list(LIST *l){
	NODE *cursor, *cursor2;
	if(l==NULL)
		return;
	cursor=l->head;
	cursor=cursor->next;
	cursor2=l->head;
	while(cursor!=NULL){
		free(((PDATA*)cursor2->data)->vorname);
		free(((PDATA*)cursor2->data)->nachname);
		free(((PDATA*)cursor2->data)->geb);
		free(((PDATA*)cursor2->data)->ort);
		free(cursor2->data);
		free(cursor2);
		cursor2=cursor;
		cursor=cursor->next;
	}
	free(l);
	
}
