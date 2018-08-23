/* An XOR linked list is a more memory efficient doublyl linked list.
Instead of each node helding next and prev fields, it holds a field
named npx, which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an insert(element) which adds the
element to the end, and a printList(index) which returns the node at 
index.
*/
#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *npx;
};
struct node * XOR(struct node *a,struct node *b)
{
  return (struct node *)((long long)(a) ^ (long long)(b));
}
void insert(struct node **head,int data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;

  new_node->npx = XOR(NULL,*head);

  if(*head != NULL)
  {
    struct node *next = XOR((*head)->npx,NULL);
    (*head)->npx = XOR(new_node,next);
  }

  *head = new_node;
}
void printList(struct node *head,int index)
{
  int count=1;
  struct node *curr = head;
  struct node *prev = NULL;
  struct node *next;

  while(count!=3)
  {
    count++;
    next = XOR(prev,curr->npx);
    prev = curr;
    curr = next;
  }
  cout<<curr->data;
}
int main()
{
  struct node *head = NULL;
  insert(&head, 10);
  insert(&head, 20);
  insert(&head, 30);
  insert(&head, 40);
  printList(head,3);
  return 0;
}
