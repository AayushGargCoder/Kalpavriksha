#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
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
        if (h1->data < h2->data)
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
    head = mergeSort(head);
    return head;
}
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}
Node *getPivotNode(Node *head, int pivot)
{
    while (head)
    {
        if (head->data == pivot)
            return head;
        head = head->next;
    }
    return NULL;
}
void swapData(Node *node1, Node *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

void printList(Node *head)
{
    printf("Your List After sorting Nodes around pivot:");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

Node *arrangeAroundPivot(Node *head, Node *pivot)
{

    int valToCompare = pivot->data;
    Node *place = head;
    while (head)
    {
        if (head != pivot && head->data < valToCompare)
        {
            swapData(place, head);
            if (place == pivot)
                pivot = head;
            place = place->next;
        }
        head = head->next;
    }
    swapData(pivot, place);
    return place;
}
Node *sortAroundPivot(Node *head, int pivot)
{
    Node *pivotNode = getPivotNode(head, pivot);
    if (!pivotNode)
    {
        printf("Pivot is not present , no way to sort around them\n");
        exit(0);
    }
    pivotNode = arrangeAroundPivot(head, pivotNode);
    Node *pivotNext = pivotNode->next;
    pivotNode->next = NULL;
    head = sortList(head);
    pivotNext = sortList(pivotNext);
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = pivotNext;
    return head;
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
int getPivot()
{
    printf("pivot:");
    int pivot;
    scanf("%d", &pivot);
    return pivot;
}
int main()
{
    Node *head = takeInput();
    int pivot = getPivot();

    head = sortAroundPivot(head, pivot);
    printList(head);
    freeList(head);
}