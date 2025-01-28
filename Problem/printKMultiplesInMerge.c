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
Node *mergeLists(Node **list, int s, int e)
{
    if (s > e)
        return NULL;
    if (s == e)
        return list[s];
    int mid = (s + e) / 2;
    Node *first = mergeLists(list, 0, mid);
    Node *second = mergeLists(list, mid + 1, e);
    Node *res = merge(first, second);
    return res;
}
Node *mergeKList(Node **list, int k)
{
    Node *head = mergeLists(list, 0, k - 1);
    return head;
}
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}
Node *inputList(int listNo)
{
    int totalNodes, track;
    printf("Total Elements you want to Enter for %d list:", listNo + 1);
    scanf("%d", &totalNodes);
    track = totalNodes;
    Node *head = NULL, *tail = NULL;
    int input;
    while (totalNodes--)
    {
        printf("Enter %d element for %d list:", track - totalNodes, listNo + 1);
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
Node **takeInput(int *k)
{
    printf("Enter No of List:");
    scanf("%d", k);
    Node **list = (Node **)calloc(*k, sizeof(Node *));
    for (int i = 0; i < *k; i++)
    {
        list[i] = inputList(i);
    }
    return list;
}
void printList(Node *head, int k)
{
    if (k == 0)
    {
        printf("Empty List\n");
        return;
    }
    printf("Your List After merging Lists:");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void printMultipleOfKNodes(Node *head, int k)
{
    if (k == 0)
        return;
    printf("Elements which are at multiple of Kth Position:");
    int track = 1;
    while (head)
    {
        if (!(track % k))
            printf("%d ", head->data);
        head = head->next;
        track++;
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
    int k;
    Node **list = takeInput(&k);
    Node *head = mergeKList(list, k);
    printList(head, k);
    printMultipleOfKNodes(head, k);
    freeList(head);
    free(list);
}