
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int id;
    struct node *next;
} Node;

typedef struct
{
    Node *first;
    Node *second;
} Pair;

void printId(int val)
{
    char str[20];
    sprintf(str, "%d", val);

    char idEmp[30];
    strcpy(idEmp, "ITT/");
    strcat(idEmp, str);
    printf("%s ", idEmp);
}

void eliminateAndPrint(Node *head, int k)
{
    if (k == 1)
    {
        printId(head->id);
        Node *temp = head->next;
        while (temp != head)
        {
            printId(temp->id);
            Node *temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
        free(head);
        return;
    }
    int tempK = k;
    Node *prev = NULL, *curr = head;
    while (head->next != head)
    {
        tempK--;
        if (!tempK)
        {
            printId(curr->id);
            prev->next = curr->next;
            free(curr);
            curr = prev;
            tempK = k;
        }
        prev = curr;
        curr = curr->next;
    }
    printId(head->id);
    free(head);
}

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->id = val;
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
    tail->next = head;
    return head;
}

int getK()
{
    printf("Enter k:");
    int k;
    scanf("%d", &k);
    return k;
}
int main()
{
    Node *head = takeInput();
    int k = getK();
    if (k <= 0)
        exit(0);
    eliminateAndPrint(head, k);
}