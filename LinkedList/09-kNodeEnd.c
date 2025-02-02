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
int getNthFromLast(Node *head, int k)
{
    Node *reverseList = reverse(head);
    for (int i = 1; i < k; i++)
    {
        reverseList = reverseList->next;
        if (reverseList == NULL)
            return -1;
    }
    return reverseList->data;
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
int getK()
{
    int k;
    printf("Enter value of k:");
    scanf("%d", &k);
    return k;
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
    int k = getK();
    printf("Kth Node from end is:%d", getKNode(head, k));
    freeList(head);
}