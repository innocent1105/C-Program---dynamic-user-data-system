#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

int main() {
    int ids[MAX_USERS];          // array for the user ids
    char names[MAX_USERS][NAME_LENGTH]; // user names
    int ages[MAX_USERS];         //  store user ages
    int userCount = 0;           // number of userss

    int choice;                  // Menu choice

    while (1) {
        // Display Menu
        printf("\n--- Dynamic User Information System ---\n");
        printf("1. Add New User\n");
        printf("2. Display All Users\n");
        printf("3. Search User by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // different menu option
        if (choice == 1) {
            // addibg a user
            if (userCount >= MAX_USERS) {
                printf("Cannot add more users! Maximum limit reached.\n");
                continue;
            }

            printf("Enter a user ID: ");
            scanf("%d", &ids[userCount]);

            printf("Enter User Name: ");
            getchar();
            fgets(names[userCount], NAME_LENGTH, stdin);
            names[userCount][strcspn(names[userCount], "\n")] = '\0';

            printf("Enter user Age: ");
            scanf("%d", &ages[userCount]);

            userCount++;
            printf("User added successfully!\n");

        } else if (choice == 2) {
            // show all users
            if (userCount == 0) {
                printf("No users to display.\n");
            } else {
                printf("\n--- User List ---\n");
                for (int i = 0; i < userCount; i++) {
                    printf("ID: %d | Name: %s | Age: %d\n", ids[i], names[i], ages[i]);
                }
            }

        } else if (choice == 3) {
            // search for a user by id
            if (userCount == 0) {
                printf("No users available.\n");
                continue;
            }

            int searchID;
            printf("Enter ID to search: ");
            scanf("%d", &searchID);

            int found = 0;
            for (int i = 0; i < userCount; i++) {
                if (ids[i] == searchID) {
                    printf("User Found:\n");
                    printf("ID: %d | Name: %s | Age: %d\n", ids[i], names[i], ages[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("User not found.\n");
            }

        } else if (choice == 4) {
            // Exit
            printf("Exiting program.\n");
            break;

        } else {
            // if the input is not valid
            printf("Invalid choice! Please enter a valid option (1-4).\n");
        }
    }

    return 0;
}
