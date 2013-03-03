// alm2_02_vyhledavaci_stromy.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include<stdlib.h>

typedef int Item;
typedef struct Nod
{
	Item item;
	Nod*left;
	Nod*right;
}Node;

Node *Search(Node *root, Item x);
bool Insert(Node **root, Item x);
bool Delete(Node **root, Item x);
bool Print(Node *root);

int main()
{
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

Node *Search(Node *root, Item x)
   { 
     Node *u=root;
     while (u != NULL)
     { if (x < u->item) u=u->left;
       else if (x > u->item) u=u->right;
       else return u;
     }
     return NULL;
   }

bool Insert(Node **root, Item x)
   { 
     Node **u=root;
     while (*u != NULL)
     { if (x < (*u)->item) u=&(*u)->left;
       else if (x > (*u)->item) u=&(*u)->right;
       else return false;
     }
     { Node *v= new Node;
       v->item = x;
       v->left = v->right = NULL;
       *u = v;     }  
     return true;
   }

bool Delete(Node **root, Item x)
  { 
    Node **u=root;
    while (*u != NULL)
    { if (x < (*u)->item) { u=&(*u)->left; continue; }
      if (x == (*u)->item) break;
      u=&(*u)->right;
    }
    if (*u==NULL) return false;
    if ((*u)->left!=NULL && (*u)->right!=NULL)
    { Node **v=&(*u)->right;
      while ((*v)->left!=NULL) v=&(*v)->left; 
      (*u)->item=(*v)->item;
      u=v;
    }
    { Node *v=*u; 
      *u= v->left ? v->left : v->right;
      delete v;
    } 
  }

bool Print(Node *root)
{
	if(root!=NULL) 
	{
		Print(root->left);
		printf("%d ",root->item);
		Print(root->right);
	}
	return true;
}

