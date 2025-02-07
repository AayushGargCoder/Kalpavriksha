#include <stdio.h>
#include <stdlib.h>
#define MAX 101
typedef struct Node
{
    int value, key;
    struct Node *next;
} Node;
typedef struct hashmap
{
    Node **bucket;
} hashmap;
void initializeHashmap(hashmap *map)
{
    map->bucket = (Node **)malloc(sizeof(Node *) * MAX);
}
Node *createNode(int key, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->key = key;
    newNode->value = value;
    return newNode;
}
int hash(int key)
{
    return key % MAX;
}
void insert(int key, int value, hashmap *map)
{
    int hashValue = hash(key);
    Node *head = map->bucket[hashValue];
    Node *newNode = createNode(key, value);
    if (!head)
    {
        map->bucket[hashValue] = newNode;
        return;
    }
    Node *prev = NULL;
    while (head)
    {
        if (head->key == key)
        {
            head->value = value;
            break;
        }
        prev = head;
        head = head->next;
    }
    if (head == NULL)
        prev->next = newNode;
}
void insertHelper(hashmap *map)
{
    int key, value;
    printf("Enter key:");
    scanf("%d", &key);
    printf("Enter value:");
    scanf("%d", &value);
    insert(key, value, map);
}
int search(int key, hashmap *map)
{
    int hashValue = hash(key);
    Node *head = map->bucket[hashValue];
    while (head)
    {
        if (head->key == key)
            return head->value;
        head = head->next;
    }
    return -1;
}
void searchHelper(hashmap *map)
{
    int key;
    printf("Enter key:");
    scanf("%d", &key);
    int value = search(key, map);
    if (value == -1)
        printf("key Not Found\n");
    else
        printf("Value:%d\n", value);
}
int delete(int key, hashmap *map)
{
    int hashValue = hash(key);
    Node *head = map->bucket[hashValue];
    Node *prev = NULL;
    while (head)
    {
        if (head->key == key)
        {
            if (prev == NULL)
            {
                map->bucket[hashValue] = head->next;
                free(head);
            }
            else
            {
                prev->next = head->next;
                free(head);
            }
            return 1;
        }
        prev = head;
        head = head->next;
    }
    return -1;
}
void deleteHelper(hashmap *map)
{
    int key;
    printf("Enter key:");
    scanf("%d", &key);
    int possibleDelete = delete (key, map);
    if (possibleDelete == -1)
        printf("Key Not Found\n");
    else
        printf("key %d deleted\n", key);
}
void display(hashmap *map)
{
    int hashFlag = 0;
    for (int i = 0; i < MAX; i++)
    {
        Node *head = map->bucket[i];
        if (head)
        {
            if (!hashFlag)
            {
                printf("Hash Table:\n");
                hashFlag = 1;
            }
            printf("index %d:", i);
            int flag = 0;
            while (head)
            {
                if (!flag)
                {
                    printf("(%d,%d)", head->key, head->value);
                    flag = 0;
                }
                else
                    printf("->(%d,%d)", head->key, head->value);
                head = head->next;
            }
            printf("\n");
        }
    }
    if (!hashFlag)
        printf("Empty HashTable\n");
}
void performOperations(hashmap *map)
{
    int operationNumber;
    do
    {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &operationNumber);
        switch (operationNumber)
        {
        case 1:
            insertHelper(map);
            break;
        case 2:
            searchHelper(map);
            break;
        case 3:
            deleteHelper(map);
            break;
        case 4:
            display(map);
            break;
        case 5:
            printf("Exit...");
            break;
        default:
            printf("Invalid Choice");
            break;
        }

    } while (operationNumber != 5);
}
void freeTable(hashmap *map)
{
    for (int i = 0; i < MAX; i++)
    {
        Node *head = map->bucket[i];

        while (head)
        {
            Node *temp = head;
            head = head->next;
            free(temp);
        }
    }
}
int main()
{
    hashmap map;
    initializeHashmap(&map);
    performOperations(&map);
    freeTable(&map);
}
