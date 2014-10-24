#include "Brett.h"
#include <stdlib.h>
#include <stdio.h>


/*soll das Brett initialisieren und die Werte übergeben*/	
	
int init_brett (struct t_brett *b, int n, int x, int y){
	int i,j;
	b->felder= malloc (n*sizeof(int*));
	for (i=0;i<n; i++){
		b->felder[i] = malloc(n*sizeof(int));  /* hier wird der Platz für das n*n Feld allokiert*/ 
	}
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			b->felder[i][j]=0;			/*hier wird jedem Feld die 0 übergeben als Zeichen,dass dort*/ 
		}								/* noch kein Springer war*/
	}
	b->startpos_x=x;					/*übergabe x,y und n*/
	b->startpos_y=y;
	b->felder[x-1][y-1] = 1;
	b->n=n;
	
	return 0;
}

/*Freigabe vom Speicher vom Brett*/

void loesche_brett (struct t_brett *b){
	int i;
	for (i=0; i< b->n; i++){
		free (b->felder[i]);
	}
	free (b->felder);
}

void print (struct t_brett *b){
	int i,j,k,l;
	k=0;
	l=0;
	for (i=0; i<= (2*b->n); i++){
		l=0;
		for (j=0; j<(b->n); j++){
			if (i%2!= 1){
				printf ("+---");
			}
			else{
				printf("+ %i ", b->felder[k][l]);
				l++;
			}	
		}
		printf ("+\n");
		if (i%2==1)k++;
	}
}


int besuchte_felder(struct t_brett *b){
	int i,j,erg=0;
	for (i=0; i<b->n ; i++){
		for(j=0; j<b->n; j++){
			if (b->felder[i][j] != 0) erg+=1;
		}
	}
	return erg;
}

int frei (struct t_brett *b, int x, int y){
	if ((b->startpos_x+x)<=0 || (b->startpos_y+y)<=0 || (b->startpos_y+y)>b->n || (b->startpos_x+x)>b->n || b->felder [b->startpos_x+x-1][b->startpos_y+y-1] != 0) return 0;
	else return 1;
}

void neuer_sprung(struct t_brett *b, int x , int y){
	b->startpos_x +=x;
	b->startpos_y +=y;
	b->felder [b->startpos_x-1][b->startpos_y-1] = besuchte_felder(b)+1;
}

void entferne_sprung (struct t_brett *b, int x, int y){
	b->felder [b->startpos_x-1][b->startpos_y-1]= 0;
	b->startpos_x -=x;
	b->startpos_y -=y;
}
