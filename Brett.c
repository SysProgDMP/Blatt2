
#include <stdlib.h>
#include <stdio.h>



 struct t_brett {
	int ** felder ;
	int startpos_x;
	int startpos_y;
	int n;
	};

/*soll das Brett initialisieren und die Werte übergeben*/	
	
int init_brett (struct t_brett *b, int n, int x, int y){
	int i,j;
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
	b->n=n;
	return 0;
}

/*Freigabe vom Speicher vom Brett*/

void loesche_brett (struct t_brett *b){
	int i;
	for (i=0; i< b->n; i++){
		free (b->felder[i]);
	}
	/*hier eventuell noch Speicher von n, y und x freigebe*/

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

int main (){
	struct t_brett b;
	int n= 5;
	int x=1;
	int y=1;
	int i= init_brett (&b,n,x,y);
	print (&b);
	loesche_brett(&b);
	printf ("%i", i);
	return 0;
}














