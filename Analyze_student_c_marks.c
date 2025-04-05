#include <stdio.h>
#include <stdlib.h>
#include "working_modules.h"  // Include the header file


#define MAX_STUDENTS 100

// Function to analyze student marks from a file
void student_mid_analysis(const char *filename) {
    int sem;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    int marks[MAX_STUDENTS], count = 0;
    int sum = 0, highest = 0, lowest = 100;
    float average;
    
    printf("\n\t____________________________\n");
    printf("\n\t|*    Student Marks:      *|\n");
    printf("\n\t----------------------------\n");
    while (fscanf(file, "%d", &marks[count]) == 1 && count < MAX_STUDENTS) {
        printf("\tStudent %d: %d\n", count + 1, marks[count]);
        
        sum += marks[count];
        if (marks[count] > highest) highest = marks[count];
        if (marks[count] < lowest) lowest = marks[count];
        
        count++;
    }
    
    fclose(file);
    
    if (count == 0) {
        printf("No marks found in the file.\n");

        return;
    }
    
    average = (float)sum / count;
    
    printf("\n\t--- Statistics ---\n");
    printf("\tTotal Students: %d\n", count);
    printf("\tAverage Marks: %.2f\n", average);
    printf("\tHighest Marks: %d\n", highest);
    printf("\tLowest Marks: %d\n", lowest);
    printf("\n");
    printf("\n");

    //**** OPENING WEBSITE *******
  
   printf(" Want to check your Sem result? 0-cancel/ 1-check\n");
   scanf("%d",&sem);
   if(sem){
    
    #ifdef _WIN32
       system("start \"http://exams.mictech.ac.in/Login.aspx\"");
#elif __APPLE__
       system("open \"http://exams.mictech.ac.in/Login.aspx\"");
#else
       system("open \"http://exams.mictech.ac.in/Login.aspx\"");
#endif

      // system("open \"http://exams.mictech.ac.in/Login.aspx\"");
      }

      else
      printf(" website Opening Cancelled..");

}
