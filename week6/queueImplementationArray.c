#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *queueArray;
    int rear, front, size;
} Queue;
void initializeQueue(Queue *queue)
{
    int size;
    printf("Enter size of queue:");
    scanf("%d", &size);
    if (size <= 0)
        exit(0);
    (*queue).rear = -1;
    (*queue).front = -1;
    (*queue).size = size;
    (*queue).queueArray = (int *)calloc(size, sizeof(int));
}
void push(Queue *queue, int data)
{
    if ((*queue).rear == (*queue).size - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    (*queue).queueArray[++(*queue).rear] = data;
    if ((*queue).front == -1)
        (*queue).front++;
}
int isEmpty(Queue *queue)
{
    return (*queue).rear == -1;
}
void pop(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return;
    }
    (*queue).front++;
    if ((*queue).front > (*queue).rear)
    {
        (*queue).front = -1;
        (*queue).rear = -1;
    }
}

int front(Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    return (*queue).queueArray[(*queue).front];
}
void printQueue(Queue *queue)
{
    if (isEmpty(queue) || (*queue).front > (*queue).rear)
        return;
    printf("%d ", front(queue));
    (*queue).front++;
    printQueue(queue);
    (*queue).front--;
}
void pushData(Queue *queue)
{
    int data;
    printf("Enter value to be Added:");
    scanf("%d", &data);
    push(queue, data);
    printf("New Value Added in queue\n");
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
        printf("Front element:%d", front(queue));
}
void performOperations(Queue *queue, int *operationNumber)
{
    printf("Enter Operation Number:");
    scanf("%d", operationNumber);
    switch (*operationNumber)
    {
    case 1:
        pushData(queue);
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
        printf("Total Elements In queue:%d\n", isEmpty(queue) ? 0 : (*queue).rear - (*queue).front + 1);
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
        printf("Press5:Total Elements In queue:\n");
        printf("Press6:Print queue\n");
        printf("Press7:Exit\n\n");
        performOperations(&queue, &operationNumber);
    } while (operationNumber != 7);
    free(queue.queueArray);
}