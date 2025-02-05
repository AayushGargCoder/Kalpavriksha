#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}

Node *segregateList(Node *head)
{
    Node *even = createNode(-1), *odd = createNode(-1), *tailEven = even, *tailOdd = odd;
    while (head != NULL)
    {
        if (!(head->data % 2))
        {
            tailEven->next = head;
            tailEven = head;
            head = head->next;
            tailEven->next = NULL;
        }
        else
        {
            tailOdd->next = head;
            tailOdd = head;
            head = head->next;
            tailOdd->next = NULL;
        }
    }
    tailEven->next = odd->next;
    return even->next;
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
    printf("Your List After Reordering:");
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
    Node *head = takeInput();
    head = segregateList(head);
    printList(head);
    freeList(head);
}