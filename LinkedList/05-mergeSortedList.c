#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *merge(Node *h1, Node *h2)
{
    Node *head = NULL, *tail = NULL;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            if (head == NULL)
            {
                head = h1;
                tail = h1;
            }
            else
            {
                tail->next = h1;
                tail = h1;
            }
            h1 = h1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = h2;
                tail = h2;
            }
            else
            {
                tail->next = h2;
                tail = h2;
            }
            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        tail->next = h1;
    }
    if (h2 != NULL)
    {
        tail->next = h2;
    }
    return head;
}

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}
Node *takeInput()
{
    int nodeCount = 2, input;
    Node *head = NULL, *tail = NULL;
    printf("Enter 1 node value (enter -1 to exit):");
    scanf("%d", &input);
    while (input != -1)
    {
        Node *newNode = createNode(input);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        printf("Enter %d node value (enter -1 to exit):", nodeCount);
        scanf("%d", &input);
    }
    return head;
}
void printList(Node *head)
{
    if (!head)
    {
        printf("Empty List");
        return;
    }
    printf("Your List After merging:");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
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
    Node *head = merge(head1, head2);
    printList(head);
    freeList(head);
}