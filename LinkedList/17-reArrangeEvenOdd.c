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

Node* segregateList(Node *head)
{
    Node *even = createNode(-1), *odd = createNode(-1),*tailEven=even, *tailOdd=odd;
    while (head != NULL)
    {
        Node* newNode = createNode(head->data);
        if (!(head->data % 2))
        {
            tailEven->next = newNode;
            tailEven = newNode;
        }
        else
        {
            tailOdd->next = newNode;
            tailOdd = newNode;
        }
        head = head->next;
    }
    tailEven->next = odd->next;
    return even->next;
}

Node *takeInput()
{
    int totalNodes, track;
    printf("Total Elements you want to Enter:");
    scanf("%d", &totalNodes);
    if (totalNodes <= 0)
    {
        printf("You have a empty list:");
        exit(0);
    }
    track = totalNodes;
    Node *head = NULL, *tail = NULL;
    int input;
    while (totalNodes--)
    {
        printf("Enter %d element:", track - totalNodes);
        scanf("%d", &input);
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
    Node* newList=segregateList(head);
    printList(newList);
    freeList(head);
    freeList(newList);
}