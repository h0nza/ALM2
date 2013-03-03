// alm2_01_vyhledavani.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tisk(int v, int n);
int SequentialSearch(int A[], int n, int x);
int SequentialSearchSentinel(int A[], int n, int x);
int BinarySearchRek(int A[], int k, int l, int x);
int BinarySearchIte(int A[], int n, int x);

int main()
{
	int pole_nes[11]={8,5,11,17,6,24,9,63,14,1};
	int pole_set[10]={1,2,3,4,5,6,7,8,9,10};
	//tisk(SequentialSearch(pole_nes, 10, 17),10);
	//tisk(SequentialSearch(pole_nes, 10, 3),10);
	//tisk(SequentialSearchSentinel(pole_nes, 10, 17),10);
	//tisk(SequentialSearchSentinel(pole_nes, 10, 3),10);
	//tisk(BinarySearchRek(pole_set,0, 9, 9),10);
	//tisk(BinarySearchRek(pole_set, 0,9, 15),10);
	tisk(BinarySearchIte(pole_set, 10, 9),10);
	tisk(BinarySearchIte(pole_set, 10, 15),10);
	system("PAUSE");
	return 0;
}

void tisk(int v, int n)
{
	if(v==n) printf("Hledany prvek se v poli nenachazi.\n"); else printf("Hledany prvek je na pozici %d.\n", v);
}



