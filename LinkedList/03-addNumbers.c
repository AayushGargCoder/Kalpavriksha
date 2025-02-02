
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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    if (!head1 && !head2)
        return NULL;
    int carry = 0;
    Node *newHead = createNode(-1);
    Node *tail = newHead;
    while (head1 || head2 || carry != 0)
    {
        int head1Data = head1 ? head1->data : 0;
        int head2Data = head2 ? head2->data : 0;
        int finaldDta = head1Data + head2Data + carry;
        tail->next = createNode(finaldDta % 10);
        tail = tail->next;
        carry = finaldDta / 10;
        head1 = head1 ? head1->next : NULL;
        head2 = head2 ? head2->next : NULL;
    }
    Node *head = newHead->next;
    newHead->next = NULL;
    free(newHead);
    return reverseList(head);
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
void printList(Node *head)
{
    printf("Your List After Addition:");
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
    Node *head = addTwoNumbers(head1, head2);
    printList(head);
    freeList(head);
    freeList(head1);
    freeList(head2);
}