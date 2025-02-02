#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *after = curr->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = after;
        if (after != NULL)
        {
            after = after->next;
        }
    }
    return prev;
}
int findDecimalEquivalent(Node *head)
{
    Node *reverseList = reverse(head);
    int decimalEquivalent = 0, base = 1;
    while (reverseList)
    {
        decimalEquivalent += (base * (reverseList->data));
        base *= 2;
        reverseList = reverseList->next;
    }
    return decimalEquivalent;
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
    printf("Decimal Equivalent of List is:%d", findDecimalEquivalent(head));
    freeList(head);
}