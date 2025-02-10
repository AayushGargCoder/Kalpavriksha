#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int id;
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
    newNode->id = val;
    return newNode;
}
Node *takeInput()
{
    int nodeCount = 2, input;
    Node *head = NULL, *tail = NULL;
    printf("Enter 1 emoployee Id(enter -1 to exit):");
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
        printf("Enter %d emoployee Id(enter -1 to exit):", nodeCount);
        scanf("%d", &input);
    }
    return head;
}
void printId(int val)
{
    char str[20];
    sprintf(str, "%d", val);

    char idEmp[30];
    strcpy(idEmp, "ITT/");
    strcat(idEmp, str);
    printf("%s ", idEmp);
}
void printListInvolvedBoth(Node *foosball, Node **tTennis)
{
    printf("Both Sports Involved:");
    for (Node *ptr1 = foosball; ptr1 != NULL; ptr1 = ptr1->next)
    {
        Node *prev = NULL;
        for (Node *ptr2 = *tTennis; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (ptr1->id == ptr2->id)
            {
                printId(ptr1->id);
                if (prev == NULL)
                {
                    *tTennis = ptr2->next;
                    free(ptr2);
                }
                else
                {
                    prev->next = ptr2->next;
                    free(ptr2);
                }
                break;
            }
            prev = ptr2;
        }
    }
}
void printListIndividual(Node *foosball, Node *tTennis)
{
    printf("\nIndividual Games:");
    while (foosball)
    {
        printId(foosball->id);
        foosball = foosball->next;
    }
    while (tTennis)
    {
        printId(tTennis->id);
        tTennis = tTennis->next;
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
    Node *foosball = takeInput(), *tTennis = takeInput();
    if (!foosball && !tTennis)
    {
        printf("No One is playing any sport");
        exit(0);
    }
    printListInvolvedBoth(foosball, &tTennis);
    printListIndividual(foosball, tTennis);
    freeList(foosball);
    freeList(tTennis);
}