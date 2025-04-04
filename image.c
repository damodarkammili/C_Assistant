/*   WINDOWS

#include <stdio.h>
#include <stdlib.h>

void open_image(const char *image_path) {
    char command[256];
    snprintf(command, sizeof(command), "start %s", image_path);
    system(command);
}

int main() {
    open_image("C:\\path\\to\\your\\image.jpg"); // Replace with the actual path
    return 0;
}

*/

// MAC - single image
  
#include <stdio.h>
#include <stdlib.h>
#include "working_modules.h"  // Include the header file 

void open_image(const char *image_path) {
    char command[256];
    snprintf(command, sizeof(command), "open \"%s\"", image_path);
    system(command);
    //system("open republic_day.jpg");

}

// int main() {
//     open_image("republic_day.jpg"); // Update path correctly
//     return 0;
// }



// ***  MAC for multiple images  ***

/*

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void open_images_in_folder(const char *folder_path) {
    struct dirent *entry;
    DIR *dir = opendir(folder_path);  // Open the folder

    if (dir == NULL) {
        printf("Error: Could not open folder %s\n", folder_path);
        return;
    }

    char file_path[512];

    while ((entry = readdir(dir)) != NULL) {  // Read each file in the folder
        if (strstr(entry->d_name, ".jpg") || strstr(entry->d_name, ".png") || strstr(entry->d_name, ".jpeg")) {
            snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, entry->d_name);
            
            // Open image using system command
            #ifdef _WIN32
                snprintf(file_path, sizeof(file_path), "start \"%s\"", file_path);
            #else
                snprintf(file_path, sizeof(file_path), "open \"%s\"", file_path);
            #endif

            system(file_path); // Execute the command to open the image
            getchar();  // Wait for user input before opening the next image
        }
    }

    closedir(dir); // Close the folder
}

int main() {
    open_images_in_folder("images"); // Replace "images" with your folder name
    return 0;
}


// What Happens in the Program?
// opendir("images") opens the images/ folder.

// readdir(dir) reads each file name inside the folder.

// entry->d_name gets the file name.

// strstr(entry->d_name, ".jpg") checks if it's an image.

// snprintf(file_path, "%s/%s", folder_path, entry->d_name) builds the full path.

// system("open file_path") (on macOS/Linux) or system("start file_path") (on Windows) opens the image.

// closedir(dir) closes the folder when done.

// 5. Key Takeaways
// entry->d_name gives the name of each file in a directory.

// <dirent.h> provides directory handling functions (opendir(), readdir(), closedir()).

// Only images are selected using strstr().

// Images open one by one, waiting for the user before opening the next.


*/


/* for all systems

#include <stdio.h>
#include <stdlib.h>

void open_image(const char *image_path) {
    FILE *file = fopen(image_path, "r");
    if (file) {
        fclose(file);
        char command[256];
    #ifdef _WIN32
        snprintf(command, sizeof(command), "start \"%s\"", image_path);
    #else
        snprintf(command, sizeof(command), "open \"%s\"", image_path);
    #endif
        system(command);
    } else {
        printf("Error: File \"%s\" not found!\n", image_path);
    }
}

int main() {
    open_image("republic_day.jpg"); // Update path correctly
    return 0;
}

*/


