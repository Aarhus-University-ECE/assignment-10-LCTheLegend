#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
  tree_node *new_node = malloc(sizeof(tree_node));
  if(t == NULL)
  {
    t = new_node;
    t -> item = x;
    t -> left = NULL;
    t -> right = NULL;
  }
  else
  {
    if(x > t -> item)
    {
      t->right = Insert(x, t -> right);
    }
    else
    {
      t->left = Insert(x, t -> left);
    }
  }
  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
  if(Contains(x,t) == 0)
  {
    return t;
  }
  
  tree_node *temp = t;
  int count = 0;
  tree_node *temp1;
  while(temp -> item != x)
  {
    temp1 = temp;
    if(x > (temp -> item))
    {
      temp = temp->right;
      count = 1;
    }
    if((temp -> item) > x)
    {
      temp = temp->left;
      count = 0;
    }
  }
  

  if(temp -> left == NULL && temp -> right == NULL)
  {
    if(count == 1){
      temp1 -> right = NULL;
      free(temp);
    }
    else {
      temp1 -> left = NULL;
      free(temp);
    }
    return t;
  }

  tree_node *temp2 = temp;
  tree_node *temp3;
  if(x < t -> item) {
    temp2 = temp2 ->right;
    while(temp2 -> left != NULL)
    {
      temp3 = temp2;
      temp2 = temp2 ->left;
    }
    temp3 -> left = NULL;
  }
  else {
    temp2 = temp2 -> left;
    while(temp2 -> right != NULL)
    {
      temp3 = temp2;
      temp2 = temp2 -> right;
    }
    temp3 -> right = NULL;
  }
  temp -> item = temp2 -> item;
  free(temp2);
  return t;
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
  if(t == NULL)
    return 0;
  if(t -> item == x)
    return 1;
  else if(x > t -> item)
    Contains(x, t -> right);
  else if(x < t -> item)
    Contains(x, t -> left);
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  t = NULL;  
  return t;
}

int Empty(struct tree_node *t) {
  // Test if empty
  if(t == NULL)
    return 1;
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
