/*     LOGIN FORM , CSEd, 
       PAGE-1
      
       "Predefined"username, password
  
*/

//#include "data_analysis_students.h"
#include "working_modules.h" // Include task manager
#
#include <stdio.h>
// #include<conio.h> // it will not work ther than Turbo C compiler.
#include <string.h>
#include <unistd.h> // For usleep() (Linux/macOS). Use <windows.h> for Sleep() on Windows.


// Define a simple function to simulate a login system
int login(){
    
int i,op; 
char student_name[50];
char student_roll_number[50];
char name[5][20]={"jaswanth","ravi","durga","saleem","purna"};
char roll_number[5][20]={"24h71a0572","24h71a05b8","24h71a05b1","24h71a05c3","24h71a0582"};

//user will enter his credentials here:
printf("Enter your Beautiful name please:");
scanf("%s",student_name);
printf("Enter your Toughtest roll number please:");
scanf("%s",student_roll_number);
for(i=0;i<=5;i++){

     if((strcmp(student_name,name[i])==0)&&(strcmp(student_roll_number,roll_number[i])==0))
       return 1; // Successful login
    } 

     return 0; // Failed login, since no match found.
    
   

}




void printAnimated(const char *line) {
    while (*line) {
        printf("%c", *line);  // Print each character
        fflush(stdout);       // Ensure immediate output
        usleep(5000);        // Delay (50 milliseconds)
        line++;
    }
    printf("\n");
}

void Welcome()
    { 
        int choice;
        printf("\n"); // Just for spacing

    printAnimated("\t             ***\n");
    printAnimated("\t***     ***  ***");
    printAnimated("\t***     ***  ***");
    printAnimated("\t***     ***  ***"); 
    printAnimated("\t***********  ***");
    printAnimated("\t***********  ***");
    printAnimated("\t***     ***  ***");
    printAnimated("\t***     ***  ***");
    printAnimated("\t***     ***  ***");
    printAnimated("\t***     ***  ***");
    
        printf("\n"); // Just for spacing

// printf("\t Hey! , Welcome to an exciting day of learning\n");


// printf("                                                 \n");
// printf(" \tIn which language you would like to talk with me \n");
// printf("\t\t1.C\n");
// printf("\t\t2.Python\n");

// scanf("%d",&choice);
// if(choice==1)

//    printf("Lets GO! man....\n");

// else
//     printf("OOPS! there is problem with my throught, could you please ");
}






int main() {
    int x;
    void Welcome();
    int loginResult,choice;
    loginResult = login();
   

    if (loginResult) {
        printf(" \n");                                              
        printf(" \n");                                                
        printf("\t _______________________________________________________\n");
        printf("\t*| Login successful! You are verified as a CSE student *.\n");
        printf(" \t-------------------------------------------------------\n");
        printf(" \n");                                                   
        printf("\n");
        
        Welcome();
    } else 
        printf("Login failed. \n \t Incorrect username or password.\n");
    
    while(choice!=0)
    {   printf("\n\t ------------------------------------------------|\n");
        printf("\t  |          0. To Exit this screen              |\n ");
        printf("\t  |                                              |\n");
        printf("\t ----------------------------------------------|\n");
        printf("\t1.| Task Manager     |  2. Student MID Analysis  | \n");
        printf("\t  |                                              |\n");
        printf("\t ----------------------------------------------\n");
        printf("\t3.|  Calculator      |  4.  Bank Account Manager |\n");
        printf("\t  |                                              |\n");
        printf("\t ----------------------------------------------\n");
        printf("\t5.|  Play Games      |  6.  Play_Music           |\n");  
        printf("\n\t ______________________________________________\n");
        printf("\t ----------------------------------------------\n");
        printf("\t7.|  Search_AI_gemini      |  8.  Open_image |  \n");  
        printf("\n\t ______________________________________________\n");
    


        scanf("%d",&choice);

        switch(choice){

            case 1:  taskManager();
                     break;

            case 2:  student_mid_analysis("students_mid_marks.txt");
                     break;      

            case 3:  calculator();
                     break;

            case 4:  //bankAccountOperations();
                     printf(" yet to make the functionality");
                     break;

            case 5:  printf(" yet to make the functionality");
 
                    //play_games();
                     break;

            case 6:  loadPlaylist("songs.txt");
                     playSongs();
                     break;
            case 7:  chatbot();
                     break;  

            case 8:  open_image("republic_day.jpg"); // Update path correctly
               

            default: printf(" Thank you !!");
        }  
    }
    
    return 0;

}