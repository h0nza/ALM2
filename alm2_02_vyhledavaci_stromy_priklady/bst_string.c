// alm2_02_vyhledavaci_stromy.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

#include "bst_string.h"

#include <string.h> //pokud je typedef char* Item; potrebuje strcmp() pro CompareItem()



Node *Search(Node *root, Item x) { 
     Node *u=root;
     while (u != NULL) {
       if (x < u->item) {
          u=u->left;
       }
       else if (x > u->item) {
          u=u->right;
       }
       else return u;
     }
     return NULL;
}

//Item je ted char* retezec
static int CompareItem(Item a, Item b) {//TODO void* ala compate_fn_t pro qsort() apod!
  return strcmp(a, b);
}

bool Insert(Node **root, Item x) { 
     Node *pnode = *root;//current node, zacnem na rootu
     Node *parent;
     int compare;//potrebujeme compare() funkci pro Item()!!!

   //obejdeme se bez dvojitych pointeru!
     parent = pnode;
     while (pnode != NULL) {
       parent = pnode;
       compare = CompareItem(x, pnode->item);
       if (compare < 0) {
          pnode = pnode->left;
       }
       else if (compare > 0) {
          pnode = pnode->right;
       }
       else
          return false;// ==0 uz tam je, nevkladame duplicity
     }
   //alokujeme a inicializuje novy Node pro Item x:
     pnode = (Node *)malloc(sizeof(Node));
     pnode->item = x;
     pnode->left = pnode->right = NULL;
     if (parent == NULL) {//inicializace, meli jsem prazdny strom
        *root = pnode;
     }
     else if (compare < 0) {
             parent->left = pnode;
	  }
	  else {
	     parent->right = pnode;
	  }
     return true;
}

bool Delete(Node **root, Item x) { 
    Node **u=root;
    while (*u != NULL) {
      if (x < (*u)->item) {
         u=&(*u)->left;
         continue;
      }
      if (x == (*u)->item)
         break;
      u=&(*u)->right;
    }
    if (*u==NULL)
       return false;
    if ((*u)->left != NULL && (*u)->right != NULL) {
      Node **v=&(*u)->right;
      while ((*v)->left!=NULL) {
        v=&(*v)->left;
      }
      (*u)->item=(*v)->item;
      u=v;
    }
    { Node *v=*u; 
      *u= v->left ? v->left : v->right;
      free(v);//delete v;
    } 
}

bool Print(Node *root) {
  if (root != NULL) {
     Print(root->left);
     printf("%s ",root->item);
     Print(root->right);
  }
  return true;
}
