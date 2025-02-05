#include <stdio.h>
#include <stdlib.h>

// Define structure for a polynomial term
typedef struct Node
{
    int coeff;
    int pow;
    struct Node *next;
} Node;
Node *createNode(int coeff, int pow)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

Node *addPolynomials(Node *head1, Node *head2)
{
    Node *head = createNode(0, 0);
    Node *tail = head, *curr1 = head1, *curr2 = head2;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->pow < curr2->pow)
        {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
        else if (curr1->pow > curr2->pow)
        {
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        }
        else
        {
            curr1->coeff = curr1->coeff + curr2->coeff;
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
            Node *temp = curr2;
            curr2 = curr2->next;
            free(temp);
        }
    }
    if (curr1 != NULL)
    {
        tail->next = curr1;
    }
    if (curr2 != NULL)
    {
        tail->next = curr2;
    }

    return head->next;
}

Node *takeInput()
{
    int nodeCount = 2, coeff, power;
    Node *head = NULL, *tail = NULL;
    printf("Enter 1 coefficient and power(if no power enter 0):");
    scanf("%d %d", &coeff, &power);
    while (power >= 0)
    {
        Node *newNode = createNode(coeff, power);
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
        printf("Enter %d coefficient and power(if no power enter 0):", nodeCount);
        scanf("%d %d", &coeff, &power);
    }
    return head;
}
void printPolynomial(Node *head)
{
    printf("Sum: ");
    while (head)
    {
        if (head->pow)
            printf("%dx^%d", head->coeff, head->pow);
        else
            printf("%d ", head->coeff);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
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

// Driver function
int main()
{
    Node *head1 = takeInput(), *head2 = takeInput();
    Node *result = addPolynomials(head1, head2);
    printPolynomial(result);
    freeList(result);

    return 0;
}
