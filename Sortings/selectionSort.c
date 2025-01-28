#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void swapData(Node *node1, Node *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}
Node *findNodeMinValue(Node *head)
{
    Node *nodeWithMinValue = head;
    while (head)
    {
        if (head->data < nodeWithMinValue->data)
            nodeWithMinValue = head;
        head = head->next;
    }
    return nodeWithMinValue;
}
void seletionSort(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        Node *nodeWithMinValue = findNodeMinValue(temp);
        swapData(temp, nodeWithMinValue);
        temp = temp->next;
    }
}
void sortList(Node *head)
{
    seletionSort(head);
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
    printf("Your List After Sorting:");
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
    sortList(head);
    printList(head);
    freeList(head);
}