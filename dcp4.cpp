/* Given the root to a binary tree,implement
serialize(root),which serializes the tree
into a string , and deserialize(s) which
deserializes the string back into the tree*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct node
{
  int val;
  struct node* left;
  struct node* right;
};
struct node *newnode(int val)
{
  struct node* temp = (struct node *)malloc(sizeof(struct node));
  temp->val = val;
  temp->left = temp->right = NULL;
  return temp;
}
void serialize(struct node *root,string& str)
{
  if(root==NULL)
    return;
  str+=root->val+'0';
  if(!root->left && !root->right)
    return;
  str+="(";
  serialize(root->left,str);
  str+=")";
  if(root->right)
  {
    str+="(";
    serialize(root->right,str);
    str+=")";
  }
}
int findIndex(string str,int si,int ei)
{
  if(si>ei)
    return -1;
  stack<char> s;
  int i;
  for(i=si;i<=ei;i++)
  {
      if(str[i]=='(')
        s.push(str[i]);

      else if(str[i]==')')
      {
        if(s.top()=='(')
        {
          s.pop();
          if(s.empty())
            return i;
        }
      }
  }
  return -1;
}
struct node * deserialize(string str,int si,int ei)
{
  if(si>ei)
    return NULL;
  struct node *root = newnode(str[si]-'0');
  int index = -1;
  if(si+1<=ei && str[si+1]=='(')
  {
    index = findIndex(str,si+1,ei);
  }
  if(index!=-1)
  {
    root->left = deserialize(str,si+2,index);
    root->right = deserialize(str,index+2,ei);
  }
  return root;
}
void preorder(struct node* root)
{
  if(root)
  {
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}
int main()
{
  struct node *root = NULL;
  root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  string str="";
  serialize(root,str);
  cout<<"After Serializing: "<<endl;
  cout<<str<<endl;
  struct node *root2 = NULL;
  root2 = deserialize(str,0,str.length());
  cout<<"After deserializing: "<<endl;
  preorder(root2);
  return 0;
}
