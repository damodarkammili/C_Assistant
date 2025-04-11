#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int aliens = 5;
    int health[5];
    int moves = 10, attack;

    srand(time(0));

    for (int i = 0; i < aliens; i++) {
        health[i] = rand() % 20 + 10; // Random health between 10 and 30
    }

    printf("Alien Invaders Attack!\n");
    printf("You have %d moves to defeat %d aliens!\n", moves, aliens);

    while (moves > 0 && aliens > 0) {
        printf("\nAttack an alien (1-%d): ", aliens);
        int choice;
        scanf("%d", &choice);
        choice--; // Adjust for array index

        if (choice < 0 || choice >= aliens) {
            printf("Invalid alien number!\n");
            continue;
        }

        attack = rand() % 10 + 1; // Random attack power between 1 and 10
        health[choice] -= attack;
        printf("You hit Alien %d for %d damage!\n", choice + 1, attack);

        if (health[choice] <= 0) {
            printf("Alien %d defeated!\n", choice + 1);
            
            // Play sound when an alien is defeated
            system("afplay -t 5 kgf.mp3");

            aliens--;
            for (int i = choice; i < aliens; i++) {
                health[i] = health[i + 1];
            }
        } else {
            printf("Alien %d has %d health left.\n", choice + 1, health[choice]);
        }

        moves--;
        printf("Moves remaining: %d\n", moves);
    }

    if (aliens == 0) {
        printf("Congratulations! All aliens defeated!\n");
    } else {
        printf("Out of moves! Earth has been invaded...\n");
    }

    return 0;
}
