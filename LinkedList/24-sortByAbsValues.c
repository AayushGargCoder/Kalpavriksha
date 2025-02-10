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
Node *takeInput()
{
    int nodeCount = 2, input;
    Node *head = NULL, *tail = NULL;
    printf("Enter 1 node value (enter 0 to exit):");
    scanf("%d", &input);
    while (input != 0)
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
        printf("Enter %d node value (enter 0 to exit):", nodeCount);
        scanf("%d", &input);
    }
    return head;
}
Node *mid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *merge(Node *h1, Node *h2)
{
    Node *head = NULL, *tail = NULL;

    while (h1 != NULL && h2 != NULL)
    {
        int val1 = h1->data < 0 ? -(h1->data) : h1->data, val2 = h2->data < 0 ? -(h2->data) : h2->data;
        if (val1 <= val2)
        {
            if (head == NULL)
            {
                head = h1;
                tail = h1;
            }
            else
            {
                tail->next = h1;
                tail = h1;
            }
            h1 = h1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = h2;
                tail = h2;
            }
            else
            {
                tail->next = h2;
                tail = h2;
            }
            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        tail->next = h1;
    }
    if (h2 != NULL)
    {
        tail->next = h2;
    }
    return head;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *midN = mid(head);
    Node *midNext = midN->next;
    midN->next = NULL;
    Node *first = mergeSort(head);
    Node *second = mergeSort(midNext);
    Node *res = merge(first, second);
    return res;
}
Node *sortList(Node *head)
{
    return mergeSort(head);
}
void printList(Node *head)
{
    if (!head)
    {
        printf("Empty List");
        return;
    }
    printf("Your List After sorting:");
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