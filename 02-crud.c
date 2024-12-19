#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILENAME "users.txt"
#define MAX_NAME_LEN 100

typedef struct
{
    char userId[20];
    char name[MAX_NAME_LEN];
    int age;
} User;

size_t strlen(const char *str1)
{
    size_t len = 0;
    while (str1[len] != '\0')
        len++;
    return len;
}

int isEqual(const char *str1, const char *str2)
{
    // actual strcmp return 0,-1,1
    //  if return 0->match, return 1->first string is lexicographical grreater,-1->first string is lexicographical smaller, but here i only want tp check string equal or not. so return 0 they are equal,else return 1
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 != len2)
        return 1;
    for (size_t i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i])
            return 1;
    }
    return 0;
}

void createUser()
{
    // r+ does not create a file if the file not exist, but allows both reading and writing
    // create a file in w+ mode.
    FILE *file = fopen(FILENAME, "r+");
    if (!file)
    {
        file = fopen(FILENAME, "w+");
        if (!file)
        {
            printf("Unable to open or create the file.\n");
            return;
        }
    }
    User user;
    printf("Enter unique ID: ");
    scanf("%s", user.userId);
    // Here we first check the user exist with that id or not.
    char userId[20];
    while (fscanf(file, "%s", userId) != EOF)
    {
        if (isEqual(userId, user.userId) == 0)
        {
            printf("User ID already exists.\n");
            fclose(file);
            return;
        }
    }
    printf("Enter FirstName: ");
    scanf("%s", user.name);
    printf("Enter age: ");
    scanf("%d", &user.age);

    fprintf(file, "%s %s %d\n", user.userId, user.name, user.age);
    fclose(file);
    printf("User added successfully!\n");
}

void readUsers()
{
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("No users found.\n");
        return;
    }
    User user;
    printf("Users:\n");
    // MACRO EOF return when we encounter with a  special character whose ASCII code 26 indicate end of file.
    int userCnt = 1;
    while (fscanf(file, "%s %s %d", user.userId, user.name, &user.age) != EOF)
    {
        printf("User: %d,ID: %s, Name: %s, Age: %d\n", userCnt++, user.userId, user.name, user.age);
    }

    fclose(file);
}

void updateFileStatus(bool found, const char *searchId, const char *msg)
{
    if (found)
    {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("%s", msg);
    }
    else
    {
        remove("temp.txt");
        printf("User with ID %s not found.\n", searchId);
    }
}
void removeNewLine(char *name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            return;
        }
    }
}
bool updateUser(FILE *file, FILE *tempFile, const char *searchId)
{
    // A tempFile is best practice , because if we directly overWrite main file and if there is any program crash we lost our data.
    User user;
    bool found = false;
    char choice = '\0';
    while (fscanf(file, "%s %s %d", user.userId, user.name, &user.age) != EOF)
    {
        if (isEqual(user.userId, searchId) == 0)
        {
            printf("Do you want to update the name? (y/n): ");
            getchar();
            choice = getchar();
            getchar();
            if (choice == 'y' || choice == 'Y')
            {
                found = true;
                printf("Enter new name (current: %s): ", user.name);
                fgets(user.name, MAX_NAME_LEN, stdin);
                // fgets also take newLine as input, so need to remove it
                removeNewLine(user.name);
            }

            // Ask if the user wants to update the age
            printf("Do you want to update the age? (y/n): ");
            choice = getchar();
            getchar();
            if (choice == 'y' || choice == 'Y')
            {
                found = true;
                printf("Enter new age (current: %d): ", user.age);
                scanf("%d", &user.age);
            }
        }
        fprintf(tempFile, "%s %s %d\n", user.userId, user.name, user.age);
    }

    return found;
}

bool deleteUser(FILE *file, FILE *tempFile, const char *searchId)
{
    User user;
    bool found = false;
    while (fscanf(file, "%s %s %d", user.userId, user.name, &user.age) != EOF)
    {
        if (isEqual(user.userId, searchId) == 0)
        {
            found = true;
            // we skip to  write this user into our file
            continue;
        }
        fprintf(tempFile, "%s %s %d\n", user.userId, user.name, user.age);
    }
    printf("%d", found);
    return found;
}

void helperModify(int choice)
{
    FILE *file = fopen(FILENAME, "r"), *tempFile = fopen("temp.txt", "w");
    if (!file)
    {
        printf("Unable to open the file.\n");
        return;
    }
    if (!tempFile)
    {
        printf("Error while creating temporary file.\n");
        fclose(file);
        return;
    }

    char searchId[20];
    printf("Enter the ID of the user to %s: ", (choice == 3) ? "update: " : "delete: ");
    scanf("%s", searchId);

    bool found = (choice == 3 ? updateUser(file, tempFile, searchId) : deleteUser(file, tempFile, searchId));

    fclose(file);
    fclose(tempFile);

    updateFileStatus(found, searchId, (choice == 3 ? "User updated successfully!\n" : "User deleted successfully!\n"));
}

int choice;
void takeChoice()
{
    printf("\nUser Management System\n");
    printf("1. Create User\n");
    printf("2. Read Users\n");
    printf("3. Update User\n");
    printf("4. Delete User\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
}
int main()
{
    do
    {
        takeChoice();
        switch (choice)
        {
        case 1:
            createUser();
            break;
        case 2:
            readUsers();
            break;
        case 3:
            helperModify(3);
            break;
        case 4:
            helperModify(4);
            break;
        case 5:
            printf("Exit...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
