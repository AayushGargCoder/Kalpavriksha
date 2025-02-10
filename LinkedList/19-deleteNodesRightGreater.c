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
Node *removeNodesRight(Node *head)
{
    // your code goes here
    Node *rev = reverse(head);
    Node *ans = rev;
    while (rev)
    {
        while (rev && rev->next && rev->data > rev->next->data)
        {
            Node *temp = rev->next;
            rev->next = rev->next->next;
            free(temp);
        }
        if (rev)
            rev = rev->next;
    }
    return reverse(ans);
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
    printf("Your List After removing Nodes with greater in right:");
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
    head = removeNodesRight(head);
    printList(head);
    freeList(head);
}