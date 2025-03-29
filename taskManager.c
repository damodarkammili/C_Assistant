#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "task_manager.h"  // Include the header file

#define MAX_TASKS 10
#define TASK_LENGTH 100

char tasks[MAX_TASKS][TASK_LENGTH]; // Array to store tasks
int taskCount = 0; // Number of tasks

#ifdef _WIN32
    #define CLEAR "cls"  // Windows
#else
    #define CLEAR "clear" // Linux/macOS
#endif

int choice;

//            ******************
 //           |  Task Manager  |
//            ******************



void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter the task: ");
        getchar(); 
        fgets(tasks[taskCount], TASK_LENGTH, stdin);
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0; 
        taskCount++;
        printf("Task added successfully!\n");

        sleep(1);  // Let the message display for 1 second
        system(CLEAR);  // Clears only this output
    } else {
        printf("Task list is full!\n");
    }
}

/*
void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter the task: ");
        getchar(); 
        fgets(tasks[taskCount], TASK_LENGTH, stdin);
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0; 
        taskCount++;
        printf("Task added successfully!\n");

        sleep(1);  // Display message for 1 second

        //Clear only the last two lines
        printf("\033[A\33[2K");  // Move cursor up & clear line
        printf("\033[A\33[2K");  // Move cursor up & clear line
        printf("\033[A\33[2K");  // Move cursor up & clear line
        printf("\033[A\33[2K");  // Move cursor up & clear line
        printf("\033[A\33[2K");  // Move cursor up & clear line
        printf("\033[A\33[2K");  // Move cursor up & clear line
        printf("\033[A\33[2K");  // Move cursor up & clear line
        printf("\033[A\33[2K");  // Move cursor up & clear line again
    } else {
        printf("Task list is full!\n");
    }
}

*/

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
    } else {
        printf("\t--- Task List ---\n");
        for (int i = 0; i < taskCount; i++) {
            printf("\t%d. %s\n", i + 1, tasks[i]);
        }
    }
}

void removeTask() {
    if (taskCount == 0) {
        printf("No tasks to remove.\n");
        return;
    }

    int index;
    printf("Enter task number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    // Shift tasks to remove the selected one
    for (int i = index - 1; i < taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    taskCount--;
    printf("Task removed successfully!\n");
}


void taskManager() {

    while (1) {
        printf("\n--- Task Manager ---\n");
        printf("1. \tAdd Task\n");
        printf("2. \tView Tasks\n");
        printf("3. \tRemove Task\n");
        printf("4. \tExit Task Manager\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                printf("Exiting Task Manager...\n");
                return; // Return to main menu
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

//            *****************
 //           |   CALCULATOR  |
//            *****************


void calculator() {
    double num1, num2;
    //double result;

    while (1) {
        printf("\n--- Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit Calculator\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting Calculator...\n");
            return;
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (choice) {
            case 1:
                //result = num1 + num2;
                printf("Result: %.2lf\n", num1 + num2);
                break;
            case 2:
                //result = num1 - num2;
                printf("Result: %.2lf\n", num1-num2);// 'result' variable can also be used
                break;
            case 3:
                //result = num1 * num2;
                printf("Result: %.2lf\n",num1 * num2 );
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    //result = num1 / num2;
                    printf("Result: %.2lf\n", num1 / num2);
                }
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
