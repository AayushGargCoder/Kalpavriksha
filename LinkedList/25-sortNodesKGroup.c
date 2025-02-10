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
        if (h1->data >= h2->data)
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

Node *sortKGroup(Node *head, int k)
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
    Node *sorted = sortList(head);
    head->next = sortKGroup(newGroupNode, k);
    return sorted;
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
    printf("Your List After sort in k nodes  is:");
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
    head = sortKGroup(head, k);
    printList(head);
    freeList(head);
}