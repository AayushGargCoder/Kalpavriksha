
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}
int getLength(Node *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}
void padList(Node **head, int padding)
{
    for (int i = 0; i < padding; i++)
    {
        Node *newNode = createNode(0);
        newNode->next = *head;
        *head = newNode;
    }
}
Node *addListsHelper(Node *first, Node *second, int *carry)
{
    if (!first)
        return NULL;

    Node *result = createNode(0);
    result->next = addListsHelper(first->next, second->next, carry);

    int sum = first->data + second->data + *carry;
    result->data = sum % 10;
    *carry = sum / 10;

    return result;
}

Node *addLists(Node *first, Node *second)
{
    int len1 = getLength(first);
    int len2 = getLength(second);
    if (len1 < len2)
        padList(&first, len2 - len1);
    else if (len2 < len1)
        padList(&second, len1 - len2);

    int carry = 0;
    Node *result = addListsHelper(first, second, &carry);
    if (carry)
    {
        Node *newNode = createNode(carry);
        newNode->next = result;
        result = newNode;
    }
    return result;
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
    if (!head)
    {
        printf("Empty List");
        return;
    }

    printf("Your List After adding:");
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
    Node *head1 = takeInput(), *head2 = takeInput();
    Node *result = addLists(head1, head2);
    printList(result);
    freeList(result);
    freeList(head1);
    freeList(head2);
}