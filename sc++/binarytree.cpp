#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std; 


struct node
{
  int value;
  node* left;
  node* right;
};

node* newNode(int value)
{
  node* item = new node();
  item->value = value;
  item->left = NULL;
  item->right = NULL;
  return item;
}

node* search(node* root, int value)
{
  if (!root)
    return NULL;
  if (value == root->value)
    return root;
  else if ( value > root->value)
    return search (root->right, value);
  else
    return search (root->left, value);

}

node* insert(node* root, int value)
{
  if (!root)
  {
    root = newNode(value);
    return root;
  }
  if (value > root->value)
    root->right = insert( root->right, value);
  else
    root->left = insert(root->left, value);

  return root;
}

void inOrder(node* root)
{
  if(!root)
    return ;
  inOrder(root->left);
  cout << root->value << endl;
  inOrder(root->right);

}


void outOrder(node* root)
{
  if(!root)
    return ;
  outOrder(root->right);
  cout << root->value << endl;
  outOrder(root->left);

}


int main()
{

  vector<int> lt = {9,32,45,2,5,314,667,74,565,34,64,54};
  node* root = newNode(80);
  
  for( auto v: lt)
  {
      insert(root, v);
  }


  cout << "in order ---- \n";
  inOrder (root);
  cout << "out order ---- \n";
  outOrder (root);
  node* item = search (root,123);
  if (item)
    cout << "find 123" << endl;
  else
    cout << "not find 123" << endl;

    item = search (root,34);
  if (item)
    cout << "find 34" << endl;
  else
    cout << "not find 34" << endl;

    auto getd = []()
    {
      cout << "lambda" << endl;
      return 0;
    };
    int a = getd();
  
  return 0;

}