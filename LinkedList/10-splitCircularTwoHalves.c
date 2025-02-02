

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *first;
    Node *second;
} Pair;

Pair splitList(Node *head)
{
    Pair result;
    Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
    {
        fast = fast->next;
    }
    result.first = head;
    result.second = slow->next;
    fast->next = slow->next;
    slow->next = head;

    return result;
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
    if (totalNodes <= 1)
    {
        printf("List should contain atleast two nodes");
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
    tail->next=head;
    return head;
}
void printList(Node *head)
{
    printf("%d->",head->data);
    Node* tempK=head->next;
    while (tempK!=head)
    {
        printf("%d->", tempK->data);
        tempK = tempK->next;
    }
    printf("%d\n",head->data);
}
void freeList(Node *head)
{
    Node* tempK=head->next;
    while (tempK!=head)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    free(tempK);
}
int main()
{
    Node *head = takeInput();
    Pair result = splitList(head);
    printf("Lit1:");
    printList(result.first);
    printf("Lit1:");
    printList(result.second);
    freeList(head);
}