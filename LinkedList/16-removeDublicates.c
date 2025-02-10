#include <stdio.h>
#include <stdlib.h>
#define MAX_ACTIONS 101

typedef struct Node
{
    char *fileName;
    struct Node *next;
} Node;

Node *createNode(char *input)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->fileName = input;
    return newNode;
}

Node *hashTable[MAX_ACTIONS];

int hash(char *str)
{
    int hash = 0;
    while (*str)
    {
        hash = (hash + *str) % MAX_ACTIONS;
        str++;
    }
    return hash;
}
void strCpy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++, src++;
    }
    *dest = '\0';
}
int strCmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');
}
int insertAndSearch(char *str)
{
    int index = hash(str);
    printf("Index:%d\n", index);
    char *file = (char *)malloc(10 * sizeof(char));
    strCpy(file, str);
    if (hashTable[index] == NULL)
    {
        hashTable[index] = createNode(file);
    }
    else
    {
        Node *curr = hashTable[index], *prev = NULL;
        while (curr)
        {
            if (strCmp(curr->fileName, file))
            {
                free(file);
                return 1;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            prev->next = createNode(str);
        }
    }
    return 0;
}
Node *distinctList(Node *head)
{
    if (!head)
        return head;
    Node *prev = head, *curr = head->next;
    insertAndSearch(head->fileName);
    while (curr)
    {
        if (!insertAndSearch(curr->fileName))
        {
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            Node *temp = curr;
            curr = curr->next;
            prev->next = curr;
            free(temp->fileName);
            free(temp);
        }
    }
    return head;
}

Node *takeInput()
{
    int nodeCount = 2;
    char *input = (char *)calloc(10, 1);
    Node *head = NULL, *tail = NULL;
    printf("Enter 1 file name (enter  to exit):");
    scanf("%[^\n]", input);
    while (input[0] != '\0')
    {
        getchar();
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
        printf("Enter %d file name (enter to exit):", nodeCount);

        input = (char *)calloc(10, 1);
        scanf("%[^\n]", input);
    }
    return head;
}
void printList(Node *head)
{
    if (!head)
    {
        printf("Empty List");
        return;
    }
    printf("Your List After Reordering:");
    while (head)
    {
        printf("%s ", head->fileName);
        head = head->next;
    }
}
void freeList(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        free(temp->fileName);
        free(temp);
    }
}
void freeTable()
{
    for (int i = 0; i < MAX_ACTIONS; i++)
    {
        Node *head = hashTable[i];
        while (head)
        {
            Node *temp = head;
            head = head->next;
            free(temp->fileName);
            free(temp);
        }
    }
}
int main()
{
    Node *head = takeInput();
    head = distinctList(head);
    printList(head);
    freeList(head);
    freeTable();
}