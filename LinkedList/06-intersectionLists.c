#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}
Node *getIntersectionNode(Node *headA, Node *headB)
{
    Node *ptr1 = headA;
    Node *ptr2 = headB;
    while (ptr1 != ptr2)
    {
        if (ptr1 == NULL)
            ptr1 = headB;
        else
            ptr1 = ptr1->next;

        if (ptr2 == NULL)
            ptr2 = headA;
        else
            ptr2 = ptr2->next;
    }
    return ptr1;
}
void freeList(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    Node *head1 = takeInput(), *head2 = takeInput();
    freeList(head1);
    freeList(head2);
}