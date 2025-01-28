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

Node *insertionSort(Node *head)
{
    Node *dummy = createNode(-1);
    Node *curr = head;
    while (curr != NULL)
    {
        Node *prev = dummy;
        while (prev->next != NULL && prev->next->data <= curr->data)
        {
            prev = prev->next;
        }
        Node *next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
    return dummy->next;
}

Node *sortList(Node *head)
{
    return insertionSort(head);
}

Node *takeInput()
{
    int totalNodes, track;
    printf("Total Elements you want to Enters:");
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
    head = sortList(head);
    printList(head);
    freeList(head);
}