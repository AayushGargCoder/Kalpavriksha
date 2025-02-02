
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
void printTriplet(Node* head1,Node*head2,Node* head3,int target){
    for (Node* ptr1 = head1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (Node* ptr2 = head2; ptr2 != NULL; ptr2 = ptr2->next) {
            for (Node* ptr3 = head3; ptr3 != NULL; ptr3 = ptr3->next) {
                if (ptr1->data + ptr2->data + ptr3->data == target) {
                    printf("Triplet found: (%d, %d, %d)\n", ptr1->data, ptr2->data, ptr3->data);
                    return;
                }
            }
        }
    }
    printf("No Triplet\n");
}
int getTarget()
{
    int target;
    printf("Enter value of target:");
    scanf("%d", &target);
    return target;
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
    Node *head1 = takeInput(), *head2 = takeInput(),*head3=takeInput();
    int target=getTarget();
    printTriplet(head1,head2,head3,target);

    freeList(head1);
    freeList(head2);
    freeList(head3);
}