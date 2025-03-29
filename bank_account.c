#include <stdio.h>
#include <stdlib.h>
#include "working_modules.h"

// Global variable to store account balance
double accountBalance = 1000.0; // Default balance

// Function to check balance
void checkBalance() {
    printf("\nYour current account balance is: $%.2f\n", accountBalance);
}

// Function to deposit money
void depositMoney(double amount) {
    if (amount > 0) {
        accountBalance += amount;
        printf("\nSuccessfully deposited $%.2f\n", amount);
        checkBalance();
    } else {
        printf("\nInvalid deposit amount!\n");
    }
}

// Function to withdraw money
void withdrawMoney(double amount) {
    if (amount > 0 && amount <= accountBalance) {
        accountBalance -= amount;
        printf("\nSuccessfully withdrew $%.2f\n", amount);
        checkBalance();
    } else {
        printf("\nInsufficient balance or invalid amount!\n");
    }
}

// Function to handle banking operations
void bankAccountOperations() {
    int choice;
    double amount;
    
    while (1) {
        printf("\n--- Bank Account Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                depositMoney(amount);
                break;
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                withdrawMoney(amount);
                break;
            case 4:
                printf("Exiting Bank Account Menu...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
