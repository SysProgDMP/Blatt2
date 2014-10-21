#ifndef _BRETT_H
#define _BRETT_H

 struct t_brett {
	int ** felder ;
	int startpos_x;
	int startpos_y;
	int n;
};

int init_brett (struct t_brett *b, int n, int x, int y);
void loesche_brett (struct t_brett *b);
void print (struct t_brett *b);
int besuchte_felder(struct t_brett *b);
int frei (struct t_brett *b, int x, int y);
int neuer_sprung(struct t_brett *b, int x , int y);
int entferne_sprung (struct t_brett *b, int x, int y);











#endif