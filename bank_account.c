
/*
implementing this program in a linked representation to accept user input and stores the users

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i, j, amt = 0;

struct bank 
{
    char account_holder[20];
    char account_password[20];
    char account_branch[20];
    int total_amount;
    struct bank *next;
} *head = NULL, *temp, *new_node, *current_ptr;

void create_node()
{
    int n = 1;
    printf("\nThanks For choosing 'SBI':");

    while (n)
    {
        new_node = (struct bank *)malloc(sizeof(struct bank));
        printf("\nEnter your full name: ");
        scanf("%s", new_node->account_holder);
        printf("\nCreate your account Password: ");
        scanf("%s", new_node->account_password);
        printf("\nEnter branch name to Join: ");
        scanf("%s", new_node->account_branch);
        new_node->total_amount = 0;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }

        printf("\nIF YOU WANT TO CREATE ANOTHER ACCOUNT IN 'SBI'  then press'1' OR ELSE '0' : ");
        scanf("%d", &n);
    }

    // Return after account creation, don't proceed with any user automatically
}

void bank_account_details()
{
    printf("\nNAME OF THE ACCOUNT HOLDER: %s", current_ptr->account_holder);
    printf("\nNAME OF THE ACCOUNT BRANCH: %s", current_ptr->account_branch);
    printf("\nACCOUNT PASSWORD: %s", current_ptr->account_password);
    printf("\nBANK BALANCE: %d", current_ptr->total_amount);
}

void balance_enquiry()
{
    printf("\nYour current balance is: %d", current_ptr->total_amount);
}

void cash_deposit()
{
    printf("\nEnter the amount for deposit: ");
    scanf("%d", &amt);
    current_ptr->total_amount += amt;
    printf("Your amount is deposited successfully...");
    balance_enquiry();
}

void cash_withdraw()
{
    printf("\nEnter the amount for withdraw: ");
    scanf("%d", &amt);
    if (amt > current_ptr->total_amount)
    {
        printf("Insufficient balance!");
    }
    else
    {
        current_ptr->total_amount -= amt;
        printf("Your amount is withdrawn successfully...");
        balance_enquiry();
    }
}

void bankAccountOperations()
{
    int op, flag;
    create_node();  // Create accounts first

    while (1)  // Infinite loop to allow multiple logins
    {
        char name[20], password[20];
        flag = 0; // Reset flag before login check

        printf("\n\nWelcome to SBI");
        printf("\nEnter your name: ");
        scanf("%s", name);
        printf("\nEnter your account password: ");
        scanf("%s", password);

        for (temp = head; temp != NULL; temp = temp->next)
        {
            if ((strcmp(name, temp->account_holder) == 0 && strcmp(password, temp->account_password) == 0))
            {
                current_ptr = temp;
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            printf("\nHi %s", name);
            while (1)  // Infinite loop to allow multiple operations
            {
                printf("\n\nBank operations:");
                printf("\n1) Create a new account in 'SBI'");
                printf("\n2) My bank account details");
                printf("\n3) Cash deposit");
                printf("\n4) Cash withdraw");
                printf("\n5) My savings");
                printf("\n6) To check another account");
                printf("\n7) To exit from the site...");
                printf("\nEnter the option of bank operation: ");

                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    create_node();
                    break;
                case 2:
                    bank_account_details();
                    break;
                case 3:
                    cash_deposit();
                    break;
                case 4:
                    cash_withdraw();
                    break;
                case 5:
                    balance_enquiry();
                    break;
                case 6:
                    goto login_again; // Go back to login
                case 7:
                    exit(0);
                default:
                    printf("\nInvalid option! Try again.");
                }
            }
        }
        else
        {
            printf("\nInvalid password... Please try again.");
        }

    login_again:
        continue; // Loop back to login
    }


}
