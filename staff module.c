#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_ID_LENGTH 20
#define MAX_NAME_LENGTH 50

struct Customer {
    char id[20];
    char name[50];
    float balance;
};

void addCustomer(struct Customer customers[], int *numCustomers) {
    printf("Enter customer ID and name: ");
    scanf("%s %s", customers[*numCustomers].id, customers[*numCustomers].name);
    customers[*numCustomers].balance = 0.0;
    (*numCustomers)++;
    printf("Customer added successfully!\n");
}

int findCustomerIndex(char *id, struct Customer customers[], int numCustomers) {
    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(id, customers[i].id) == 0) {
            return i;
        }
    }
    return -1;
}

void addAccount(struct Customer customers[], int numCustomers) {
    char id[20];
    printf("Enter customer ID to add account: ");
    scanf("%s", id);
    int index = findCustomerIndex(id, customers, numCustomers);
    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }
    printf("Account added successfully for customer %s!\n", customers[index].name);
}

void deposit(struct Customer customers[], int numCustomers) {
    char id[20];
    printf("Enter customer ID to deposit amount: ");
    scanf("%s", id);
    int index = findCustomerIndex(id, customers, numCustomers);
    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    customers[index].balance += amount;
    printf("Amount deposited successfully to customer %s's account.\n", customers[index].name);
}


///3444444444
void withdrawal(struct Customer customers[], int numCustomers) {
    char id[20];
    printf("Enter customer ID to withdraw amount: ");
    scanf("%s", id);
    int index = findCustomerIndex(id, customers, numCustomers);
    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (customers[index].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }
    customers[index].balance -= amount;
    printf("Amount withdrawn successfully from customer %s's account.\n", customers[index].name);
}

void balanceEnquiry(struct Customer customers[], int numCustomers) {
    char id[20];
    printf("Enter customer ID for balance enquiry: ");
    scanf("%s", id);
    int index = findCustomerIndex(id, customers, numCustomers);
    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }
    printf("Customer %s's balance: %.2f\n", customers[index].name, customers[index].balance);
}

void loanApproval() {
    printf("Loan approved!\n");
}

int main() {
    struct Customer customers[100];
    int numCustomers = 0;
    int choice;
    do {
        printf("\nStaff Module\n");
        printf("1. Add Customer\n2. Add Account\n3. Deposit\n4. Withdrawal\n");
        printf("5. Balance Enquiry\n6. Loan Approval\n7. Logoff\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addCustomer(customers, &numCustomers); break;
            case 2: addAccount(customers, numCustomers); break;
            case 3: deposit(customers, numCustomers); break;
            case 4: withdrawal(customers, numCustomers); break;
            case 5: balanceEnquiry(customers, numCustomers); break;
            case 6: loanApproval(); break;
            case 7: printf("Logging off...\n"); break;
            default: printf("Invalid choice.\n"); break;
        }
    } while (choice != 7);
    return 0;
}
