#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *head, *tail;
    int size;
} Queue;
Node *createNode()
{
    int data;
    printf("Enter value to be Added:");
    scanf("%d", &data);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void initializeQueue(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}
void push(Queue *queue, Node *newNode)
{
    if (queue->head == NULL)
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}
int isEmpty(Queue *queue)
{
    return queue->head == NULL;
}
void pop(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return;
    }
    Node *tempNode = queue->head;
    queue->head = queue->head->next;
    queue->size--;
    if (queue->head == NULL)
        queue->tail = NULL;
    free(tempNode);
}

int front(Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->head->data;
}
void printQueue(Queue *queue)
{
    if (isEmpty(queue))
        return;
    printf("%d ", front(queue));
    Node *tempHead = queue->head;
    queue->head = queue->head->next;
    printQueue(queue);
    queue->head = tempHead;
}

void printQueueHelper(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Empty Queue\n");
        return;
    }
    printf("Your current queue status is:");
    printQueue(queue);
    printf("\n");
}
void printFrontHelper(Queue *queue)
{
    if (isEmpty(queue))
        printf("Empty queue\n");
    else
        printf("front element:%d", front(queue));
}
void performOperations(Queue *queue, int *operationNumber)
{
    printf("Enter Operation Number:");
    scanf("%d", operationNumber);
    switch (*operationNumber)
    {
    case 1:
        push(queue, createNode());
        break;
    case 2:
        pop(queue);
        break;
    case 3:
        printFrontHelper(queue);
        break;
    case 4:
        printf(isEmpty(queue) ? "Empty Queue\n" : "Having some elements\n");
        break;
    case 5:
        printf("Total Elements In queue:%d\n", queue->size);
        break;
    case 6:
        printQueueHelper(queue);
        break;
    case 7:
        return;
    default:
        printf("Invalid Choice\n");
    }
}
void freeQueue(Queue *queue)
{
    while (queue->head)
    {
        Node *tempHead = queue->head;
        queue->head = queue->head->next;
        free(tempHead);
    }
}
int main()
{
    Queue queue;
    initializeQueue(&queue);
    int operationNumber;
    do
    {
        printf("\nPress1:Push\n");
        printf("Press2:Pop\n");
        printf("Press3:Get Front element\n");
        printf("Press4:check for empty\n");
        printf("Press5:Get Total Elements in Queue\n");
        printf("Press6:Print queue\n");
        printf("Press7:Exit\n\n");
        performOperations(&queue, &operationNumber);
    } while (operationNumber != 7);
    freeQueue(&queue);
}