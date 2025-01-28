#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next, *prev;
} Node;

Node *findEnd(Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

int twoPointer(Node *head, int target)
{
    Node *end = findEnd(head);
    while (head != end && head->next != end)
    {

        if (head->data + end->data == target)
            return 1;
        else if (head->data + end->data < target)
            head = head->next;
        else
            end = end->prev;
    }
    if (head == end)
        return 0;
    return head->data + end->data == target;
}

int isTargetSumPresent(Node *head, int target)
{
    return twoPointer(head, target);
}
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    newNode->prev = NULL;
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
            newNode->prev = tail;
            tail = newNode;
        }
    }
    printf("Enter target sum you want to find:");
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
    printf("%s", isTargetSumPresent(head, target) ? "Present" : "Not Present");
}