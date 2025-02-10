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

int getlistLength(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
void printList(Node *head)
{
    printf("Your List After multiplication:");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
Node *multiply(Node *head1, Node *head2)
{
    if (getlistLength(head1) < getlistLength(head2))
        return multiply(head2, head1);

    Node *tempHead = head1, *result = createNode(-1), *resultTail = result;
    int carry = 0;
    while (tempHead)
    {
        int value = tempHead->data * head2->data + carry;
        resultTail->next = createNode(value % 10);
        resultTail = resultTail->next;
        carry = value / 10;
        tempHead = tempHead->next;
    }
    if (carry)
    {
        resultTail->next = createNode(carry);
        resultTail = resultTail->next;
    }

    Node *temp = result;
    result = result->next;
    free(temp);

    head2 = head2->next;
    Node *starAhead = result->next;
    tempHead = head1;
    int carry1 = 0, carry2 = 0;
    while (head2)
    {
        Node *starAheadDummy = starAhead;
        while (tempHead)
        {
            int value = tempHead->data * head2->data + carry1;
            if (!starAheadDummy)
            {
                resultTail->next = createNode(0);
                resultTail = resultTail->next;
                starAheadDummy = resultTail;
            }
            starAheadDummy->data += value % 10 + carry2;
            carry1 = value / 10;
            carry2 = starAheadDummy->data / 10;
            starAheadDummy->data %= 10;
            starAheadDummy = starAheadDummy->next;
            tempHead = tempHead->next;
        }
        if (carry1 || carry2)
        {
            resultTail->next = createNode(carry1 % 10 + carry2 % 10);
            resultTail = resultTail->next;
            carry1 /= 10;
            carry2 /= 10;
        }
        tempHead = head1;
        starAhead = starAhead->next;
        head2 = head2->next;
    }
    return reverseList(result);
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
    Node *head1 = takeInput();
    if (!head1)
    {
        printf("Not Possible Multiplication\n");
        exit(0);
    }
    Node *head2 = takeInput();
    if (!head2)
    {
        printf("Not Possible Multiplication\n");
        exit(0);
    }
    Node *head = multiply(head1, head2);
    printList(head);
    freeList(head);
    freeList(head1);
    freeList(head2);
}