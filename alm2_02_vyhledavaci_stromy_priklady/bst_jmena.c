
#include <stdio.h>
#include <stdlib.h>

#include "bst_string.h"

int main() {
	Node *r=NULL;
	Insert(&r,6);
	Insert(&r,5);
	Insert(&r,7);
	Insert(&r,4);
	Insert(&r,8);
	Insert(&r,3);
	Insert(&r,9);
	Insert(&r,2);
	Insert(&r,10);
	Insert(&r,1);
	Print(r);
	printf("\n");
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
	system("PAUSE");
	return 0;
}

