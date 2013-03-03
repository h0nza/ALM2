
#include <stdbool.h>

//typedef int Item;
  typedef char * Item;

typedef struct Node
{
	Item item;
	struct Node *left;
	struct Node *right;
} Node;

Node *Search(Node *root, Item x);
bool Insert(Node **root, Item x);
bool Delete(Node **root, Item x);
bool Print(Node *root);
