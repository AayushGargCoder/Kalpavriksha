#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
} Node;
Node* createNode(int coeff, int pow) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

Node* addPolynomials(Node* head1, Node* head2) {
    Node* head = createNode(0, 0);
     Node* tail = head,*curr1 = head1, *curr2 = head2;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->pow < curr2->pow) {
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
        else if (curr1->pow > curr2->pow) {
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        }
        else {
            curr1->coeff = curr1->coeff + curr2->coeff;
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
            Node* temp=curr2;
            curr2 = curr2->next;
            free(temp);
        }
    }
    if (curr1 != NULL) {
        tail->next = curr1;
    }
    if (curr2 != NULL) {
        tail->next = curr2;
    }

    return head->next;
}
void printPolynomial(Node* head) {
    printf("Result of Multiplication: ");
    while (head) {
        if(head->pow) printf("%dx^%d", head->coeff, head->pow);
        else printf("%d ", head->coeff);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}
Node* multiplyPolynomials(Node* head1, Node* head2) {
    Node* result = NULL;
    for (Node* ptr1 = head1; ptr1 != NULL; ptr1 = ptr1->next) {
        Node* head = createNode(0,0),*tail=head;
        for (Node* ptr2 =head2; ptr2 != NULL; ptr2 = ptr2->next) {
            Node* newNode = createNode(ptr1->coeff * ptr2->coeff, ptr1->pow+ptr2->pow);
            tail->next=newNode;
            tail=newNode;
        }
        result = addPolynomials(result,head->next);
    }

    return result;
}
Node *takeInput()
{
    int totalNodes, track;
    printf("Total Elements you want to Enter in polynomial:");
    scanf("%d", &totalNodes);
    if (totalNodes <= 0)
    {
        printf("You have a empty list:");
        exit(0);
    }
    track = totalNodes;
    Node *head = NULL, *tail = NULL;
    int coeff,pow;
    while (totalNodes--)
    {
        printf("Enter %d coefficient and power(if no power enter 0):", track - totalNodes);
        scanf("%d %d", &coeff,&pow);
        Node *newNode = createNode(coeff,pow);
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
int main() {
    Node* head1=takeInput(),*head2=takeInput();
    Node* result = multiplyPolynomials(head1, head2);
    printPolynomial(result);
    freeList(result);
    freeList(head1);
    freeList(head2);

    return 0;
}
