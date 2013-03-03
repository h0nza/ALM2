// alm2_01_vyhledavani.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<string.h>

int* hledej(char*kde, char co[],int pocet);


int main()
{
	char *v="In the C++ programming language, the string class is a standard representation for a class of text. The class provides some typical string operations like comparison, concatenation, find and replace.";
	char s[]={ 's','c' };
	int *p=hledej(v,s,2);
	for (int i=0;i<2;i++)
		printf("Znak %c se v retezci vyskytuje %dx.\n", s[i],p[i]);
	system("PAUSE");
	return 0;
}

int* hledej(char*kde, char co[],int pocet)
{

}



