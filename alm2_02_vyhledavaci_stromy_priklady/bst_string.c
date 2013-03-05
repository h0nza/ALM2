// alm2_02_vyhledavaci_stromy.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

#include "bst_string.h"



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

bool Insert(Node **root, Item x) { 
     Node **u=root;
     while (*u != NULL) {
       if (x < (*u)->item) {
          u=&(*u)->left;
       }
       else if (x > (*u)->item) {
          u=&(*u)->right;
       }
       else
          return false;
     }
     { Node *v= (Node *)malloc(sizeof(Node));
       v->item = x;
       v->left = v->right = NULL;
       *u = v;     }  
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
