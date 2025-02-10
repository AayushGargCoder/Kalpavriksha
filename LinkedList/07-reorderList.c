#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *mid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *after = head->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = after;
        if (after != NULL)
            after = after->next;
    }
    return prev;
}
void reorderList(Node *head)
{
    Node *midNode = mid(head);
    Node *lastNode = reverseList(midNode);

    Node *temp1, *temp2;
    while (lastNode != NULL)
    {
        temp1 = head->next;
        temp2 = lastNode->next;

        head->next = lastNode;
        if (temp2 == NULL)
            break;
        lastNode->next = temp1;
        head = temp1;
        lastNode = temp2;
    }
    lastNode->next = NULL;
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
    printf("Your List After Reordering:");
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
    reorderList(head);
    printList(head);
    freeList(head);
}