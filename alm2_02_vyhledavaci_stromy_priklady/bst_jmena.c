
#include <stdio.h>
#include <stdlib.h>

#include "bst_string.h"

//misto jmena.h:
extern char *Jmena[];
extern const int Pocet;

int main() {
  int i;
	Node *r=NULL;
//plneni stromu pomoci char *Jmena[Pocet]; viz jmena.c
        for (i=0; i<Pocet; i++) {
	  Insert(&r, Jmena[i]);
        }
	Print(r);
	printf("\n");
#if 0
	Node *s=Search(r,4);
	if(s==NULL) printf("Uzel nenalezen.\n"); else printf("Uzel nalezen.\n");
	s=Search(r,12);
	if(s==NULL) printf("Uzel nenalezen.\n"); else printf("Uzel nalezen.\n");
	Delete(&r,4);
	Print(r);
	printf("\n");
	Delete(&r,1);
	Print(r);
	printf("\n");
	Delete(&r,6);
	Print(r);
	printf("\n");
#endif
//	system("PAUSE");//8-O
	return 0;
}

