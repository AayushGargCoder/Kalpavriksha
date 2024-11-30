#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME "users.txt"
#define MAX_NAME_LEN 100

typedef struct
{
    char userId[20];
    char name[MAX_NAME_LEN];
    int age;
} User;

void createUser()
{
    // a+->allow both reading and appending.
    FILE *file = fopen(FILENAME, "a+");
    if (!file)
    {
        printf("Unable to open or create the file.\n");
        return;
    }
    User user;
    printf("Enter unique ID: ");
    scanf("%s", user.userId);
    // set file to intial position
    rewind(file);

    // Here we first check the user exist with that id or not.
    char userId[20];
    while (fscanf(file, "%s", userId) != EOF)
    {
        if (strcmp(userId, user.userId) == 0)
        {
            printf("User ID already exists.\n");
            return;
        }
    }
    fclose(file);
    file = fopen(FILENAME, "a");

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
    int i = 1;
    while (fscanf(file, "%s %s %d", user.userId, user.name, &user.age) != EOF)
    {
        printf("User: %d,ID: %s, Name: %s, Age: %d\n", i++, user.userId, user.name, user.age);
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
bool updateUser(FILE *file, FILE *tempFile, const char *searchId)
{
    // A tempFile is best practice , because if we directly overWrite main file and if there is any program crash we lost our data.
    User user;
    bool found = false;
    char choice = '\0';
    while (fscanf(file, "%s %s %d", user.userId, user.name, &user.age) != EOF)
    {
        if (strcmp(user.userId, searchId) == 0)
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
                user.name[strcspn(user.name, "\n")] = '\0';
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
        if (strcmp(user.userId, searchId) == 0)
        {
            found = true;
            // we skip to  write this user into our file
            continue;
        }
        fprintf(tempFile, "%s %s %d\n", user.userId, user.name, user.age);
    }
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

int main()
{
    int choice;
    do
    {
        printf("\nUser Management System\n");
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
