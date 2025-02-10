#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rev = reverse(head->next);
    Node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return rev;
}

Node *reverseKGroup(Node *head, int k)
{
    if (!head)
        return head;
    int tempK = k - 1;
    Node *temp = head;
    while (tempK--)
    {
        temp = temp->next;
        if (temp == NULL)
            return head;
    }

    Node *newGroupNode = temp->next;
    temp->next = NULL;
    Node *rev = reverse(head);
    head->next = reverseKGroup(newGroupNode, k);
    return rev;
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
int getK()
{
    int k;
    printf("Enter value of k:");
    scanf("%d", &k);
    return k;
}
void printList(Node *head)
{

    printf("Your List After reverse in k nodes  is:");
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
    if (!head)
        exit(0);
    int k = getK();
    if (k <= 0)
        exit(0);
    head = reverseKGroup(head, k);
    printList(head);
    freeList(head);
}