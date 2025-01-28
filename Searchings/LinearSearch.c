#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

int linearSearch(Node *head, int target)
{
    while (head)
    {
        if (head->data == target)
            return 1;
        head = head->next;
    }
    return 0;
}

int isTargetPresent(Node *head, int target)
{
    return linearSearch(head, target);
}
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}
Node *takeInput(int *targetPtr)
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
    printf("Enter node value you want to find:");
    scanf("%d", targetPtr);
    return head;
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
    int target;
    Node *head = takeInput(&target);
    printf("%s", isTargetPresent(head, target) ? "Present" : "Not Present");
}