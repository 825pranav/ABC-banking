#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for ID and password
#define MAX_ID_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// Define the structure for staff members
struct Staff {
    char id[MAX_ID_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Function to read staff data from file
int readStaffData(struct Staff staff[], int maxStaff) {
    FILE *file = fopen("staff_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %s", staff[count].id, staff[count].password) == 2) {
        count++;
        if (count >= maxStaff) break; // Prevent buffer overflow
    }

    fclose(file);
    return count;
}

// Function to validate login credentials
int validateLogin(char *id, char *password, struct Staff staff[], int numStaff) {
    for (int i = 0; i < numStaff; i++) {
        if (strcmp(id, staff[i].id) == 0 && strcmp(password, staff[i].password) == 0) {
            return 1; // Login successful
        }
    }
    return 0; // Login failed
}

int main() {
    struct Staff staff[100]; 
    int numStaff = readStaffData(staff, 100);

    if (numStaff == -1) {
        printf("Exiting program.\n");
        return 1;
    }

    char id[MAX_ID_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the login module.\n");

    // Input ID and password
    printf("Enter your ID: ");
    scanf("%s", id);
    printf("Enter your password: ");
    scanf("%s", password);

    // Validate login credentials
    int loggedIn = validateLogin(id, password, staff, numStaff);

    if (loggedIn) {
        printf("Login successful!\n");

        // Prompt user to choose identity
        printf("Choose your identity:\n");
        printf("1. Manager\n");
        printf("2. Staff member\n");
        printf("3. Customer\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Welcome, Manager!\n");
                break;
            case 2:
                printf("Welcome, Staff member!\n");
                break;
            case 3:
                printf("Welcome, Customer!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } else {
        printf("Login failed. Please check your ID and password.\n");
    }

    return 0;
}
