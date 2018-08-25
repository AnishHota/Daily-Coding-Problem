/* This problem was asked by Google.

A unival tree(which stands for "universal tree") is
a tree where all nodes under it have the same value.

Given the root to a binary tree,count the number of
unival subtrees.
*/
#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *newNode(int data)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node *));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}
bool countUnival(struct node *root,int &count)
{
  if(root==NULL)
    return true;

  bool left = countUnival(root->left,count);
  bool right = countUnival(root->right,count);

  if(left==false || right==false)
    return false;

  if(root->left && (root->data!=root->left->data))
    return false;

  if(root->right && (root->data!=root->right->data))
    return false;

  count++;
  return true;
}
int main()
{
  /* Let us construct the below tree
            0
          /   \
        1      0
              /  \
            1     0
          /  \
        1     1
      */
  node *root = newNode(0);
  root->left = newNode(1);
  root->right = newNode(0);
  root->right->left = newNode(1);
  root->right->right = newNode(1);
  root->right->left->left = newNode(1);
  root->right->left->right = newNode(1);
  int count=0;
  countUnival(root,count);
  cout<<"No. of Unival subtrees are: "<<count<<endl;
  return 0;
}
