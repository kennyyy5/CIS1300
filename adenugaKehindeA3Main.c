/************************adenugaKehindeA3.c************** Student Name: Adenuga Kehinde Email Id: kadenuga@uoguelph.ca
Due Date: November 24 Course Name: CIS 1300
I have exclusive control over this submission via my password. By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I have completed the Computing with Integrity Tutorial on Moodle; and 3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material that I have used, whether directly quoted or paraphrased. Furthermore, I certify that this assignment was prepared by me specifically for this course.
********************************************************/
/********************************************************* Compiling the program The program should be compiled using the following flags: -std=c99 -Wall
compiling: gcc -std=c99 -Wall adenugaKehindeA3.c adenugaKehindeA3Main.c
Running: ./a.out
OR
gcc -std=c99 -Wall adenugaKehindeA3.c adenugaKehindeA3Main.c -o assn3
Running the Program: ./assn3 *********************************************************/
#include "givenA3.h"
int main () {

   //declare all variables:
   char courseName[NUMBER_COURSES][MAX_STR]; 
   int courseID [NUMBER_COURSES];
   char profName [NUMBER_PROFS][MAX_STR];
   int coursesTaught [NUMBER_PROFS][NUMBER_COURSES];
   int fileRead1, fileRead2;
   char fileName1[100];
   char fileName2[100];
   int choice,n,nProf,searchCNum,courseNumBool,courseNameBool,profNameBool,cNumFound;
   float avgCourses;
   char searchCName[MAX_STR];
   char cNameFound[MAX_STR];
   //initialise variables:
   strcpy(fileName1,"courses.txt");
   strcpy(fileName2,"data.txt");
   //poulate courseName, courseID,profName,coursesTaught array
   fileRead1 = readCourse(fileName1,courseName, courseID);
   fileRead2 = readProfs(fileName2, courseID, profName, coursesTaught);
   //if both fileName1 and fileName2 were read with no error or warnings
   if(fileRead1 == 1 && fileRead2 == 1){
    do {
       printf ("\nHere is the menu - enter a number between 1 and 7 \n\n");
       printf ("1. Task 3 – find the total number of professors who teach n or more courses\n");
       printf ("2. Task 4 – find course name, given its course number\n");
       printf ("3. Task 5 – find course number, given its course name\n");
       printf ("4. Task 6 – find all professors teaching a given course \n");
       printf ("5. Task 7 – find the average number of courses taught by a professor \n");
       printf ("6. Task 8 – display a horizontal histogram showing the number of courses taught by each professor\n");
       printf ("7. Exit\n");
        
       printf ("Enter your choice: ");
       scanf ("%d", &choice);
        
       // validate choice here - should be a number between 1 and 7
       
        switch (choice) {
          //task 3:
            case 1:
                //asks for value of n
                printf("What is your value of n?");
                scanf("%d", &n);
                // calls task 3 function - value returned in function is assigned to nProf and printed out:
                nProf=nCourses(n, profName, coursesTaught);
                printf("%d professor(s) in total as listed above ",nProf);
                break;
          //task 4: 
            case 2:
                //asks for course ID to be found:
                printf("What is course ID to be found?");
                scanf("%d", &searchCNum);
                // call task 4 function - prints cNameFound or an error message if courseID not found
                courseNameBool = getCourseName(searchCNum,cNameFound,courseName,courseID);
                if(courseNameBool == 0){
                printf("No course found");}
                else{
                printf("Course name found: %s",cNameFound);}
                break;
           //task 5:
            case 3:
               //asks for course name to be found
                printf("What is course name to be found?");
               //removes the /n character - unless an error occurs
               getchar();
               fgets(searchCName,MAX_STR,stdin);
                if(searchCName[strlen(searchCName)-1]=='\n'){
                   searchCName[strlen(searchCName)-1] = '\0';}
                // call task 5 function - prints cNumFound or an error message if course name not found
                courseNumBool = getCourseNum(searchCName,&cNumFound,courseName,courseID);
                if(courseNumBool == 0){
                printf("No course found");}
                else{
                printf("Course ID found: %d",cNumFound);}
                break;
           //task 6:
            case 4:
             //asks for course ID to be found
             printf("What is course ID to be found?");
             scanf("%d", &searchCNum);
             //call task 6 function - prints professors teaching a given course or an error message if no course found or course not taught by any prof
             profNameBool = profsTeachingCourse(searchCNum,profName,coursesTaught);
             if(profNameBool == 0){
              printf("No course found or course not taught by any professor"); }
            break;
           //task 7:
            case 5:
             //call task 7 function - prints average number of courses taught by a profesor
             avgCourses = avgNumCourses(coursesTaught);
             printf("Average number of courses taught by a prof: %f", avgCourses);
             break;
            //task 8:
             case 6:
             //call task 8 function - display a horizontal histogram showing the number of courses taught by each professor
              printf("Histogram displayed below: \n");
              hhistogram(profName,coursesTaught);
            break;
            case 7:
              //program exit
             break;
            //checks for invalid choices
            default: printf ("That is an invalid choice\n");
        }
        
    } while (choice != 7);
    
    }
   return 0;
}
