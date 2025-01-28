#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *findMid(Node *head, Node *end)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *findMidPrevious(Node *head, Node *mid)
{
    if (head == mid)
        return NULL;
    while (head->next != mid)
    {
        head = head->next;
    }
    return head;
}
int binarySearch(Node *head, int target)
{
    Node *end = NULL;
    while (head && end)
    {
        Node *mid = findMid(head, end);
        if (mid->data == target)
            return 1;
        else if (mid->data < target)
            head = mid->next;
        else
            end = findMidPrevious(head, mid);
    }
    return 0;
}

int isTargetPresent(Node *head, int target)
{
    return binarySearch(head, target);
}
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}
Node *takeInput(int *targetPtr)
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
    printf("Enter node value you want to find:");
    scanf("%d", targetPtr);
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
    int target;
    Node *head = takeInput(&target);
    printf("%s", isTargetPresent(head, target) ? "Present" : "Not Present");
}