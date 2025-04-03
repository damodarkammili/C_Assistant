#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "working_modules.h"

void chatbot() {
    char input[100];

    printf("Hello! I'm your chatbot. Ask me something or type 'exit' to quit.\n");

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            printf("Chatbot: Goodbye! Have a great day!\n");
            break;
        }

        if (strcmp(input, "hello") == 0 || strcmp(input, "hi") == 0) {
            printf("Chatbot: Hello! How can I assist you today?\n");
        } else if (strcmp(input, "how are you") == 0) {
            printf("Chatbot: I'm just a program, but I'm functioning as expected!\n");
        } else if (strcmp(input, "what's your name") == 0) {
            printf("Chatbot: I'm a simple C chatbot!\n");
        } else if (strcmp(input, "who created you") == 0) {
            printf("Chatbot: I was created by a C programmer like you!\n");
        } else {
            // If the bot does not recognize the input, search on Google
            printf("Chatbot: I don't know, let me search for you...\n");

            // Replace spaces in input with '+'
            for (int i = 0; i < strlen(input); i++) {
                if (input[i] == ' ') {
                    input[i] = '+';
                }
            }

            // Construct Google search URL
            char searchQuery[200];

#ifdef _WIN32
            snprintf(searchQuery, sizeof(searchQuery), "start \"\" \"https://www.google.com/search?q=%s\"", input);
#elif __APPLE__
            snprintf(searchQuery, sizeof(searchQuery), "open \"https://www.google.com/search?q=%s\"", input);
#else
            snprintf(searchQuery, sizeof(searchQuery), "xdg-open \"https://www.google.com/search?q=%s\"", input);
#endif

            printf("Executing command: %s\n", searchQuery); // Debugging: Check the command before execution
            int status = system(searchQuery);
            if (status == -1) {
                printf("Chatbot: Error opening the browser! Please check your system settings.\n");
            }
        }
    }
}


