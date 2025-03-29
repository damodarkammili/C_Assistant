#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "working_modules.h"

// Music Playlist Functionality
  #define MAX_SONGS 100
  #define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];  // Song filename
} Song;

 Song playlist[MAX_SONGS];
 int songCount;

// Function to load songs from a file
void loadPlaylist(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open playlist file %s\n", filename);
        return;
    }

    while (fgets(playlist[songCount].name, MAX_NAME_LENGTH, file) && songCount < MAX_SONGS) {
        playlist[songCount].name[strcspn(playlist[songCount].name, "\n")] = 0; // Remove newline
        songCount++;
    }

    fclose(file);
    printf("\n\t____________________________\n");
    printf("%d\tsongs loaded successfully!  \n", songCount);
    printf("\n\t----------------------------\n");

    
}

// Function to play songs one by one
void playSongs() {
    if (songCount == 0) {
        printf("No songs in the playlist.\n");
        return;
    }
    
    for (int i = 0; i < songCount; i++) {
        printf("\t\tNow playing: %s\n", playlist[i].name);
        
        // Use system() to play the song depending on the OS
#ifdef _WIN32
        char command[MAX_NAME_LENGTH + 10];
        snprintf(command, sizeof(command), "start %s", playlist[i].name);
#else
        char command[MAX_NAME_LENGTH + 10];
        snprintf(command, sizeof(command), "afplay '%s'", playlist[i].name);
#endif
        system(command);
        
        printf("\t...Press Enter to play next song...");
        getchar();  // Wait for user input before playing the next song
        
    }
}
