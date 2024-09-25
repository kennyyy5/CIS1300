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
//function poulate arrays courseName and courseID with filename given in function prototype
int readCourse (
char filename [MAX_STR],
char courseName [NUMBER_COURSES][MAX_STR],
int courseID [NUMBER_COURSES]){
  FILE * fptr;
  fptr = fopen(filename,"r");
  if(fptr == NULL){
   printf("Could not open required file - %s \n", filename);
   return -1;
  }
  for(int i = 0; i<NUMBER_COURSES;i++){
    fgets(courseName[i], MAX_STR, fptr);
    int lenOfStr = strlen(courseName[i]);
    if(courseName[i][lenOfStr-1]=='\n'){
      courseName[i][lenOfStr-1] = '\0';
    } 
  }
  for(int i = 0; i<NUMBER_COURSES;i++){
    fscanf(fptr, "%d",&courseID[i]);
  }
 return 1;
}
//function poulate arrays profName and coursesTaught with filename given in function prototype
int readProfs (char filename [MAX_STR],
int courseID [NUMBER_COURSES],
char profName [NUMBER_PROFS][MAX_STR],
int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]){
 FILE * fptr;
 fptr = fopen(filename,"r");
 if(fptr == NULL){
   printf("Could not open required file - %s", filename);
   return -1;
  }
 for(int i = 0; i<NUMBER_PROFS;i++){
    fgets(profName[i], MAX_STR, fptr);
    int lenOfStr = strlen(profName[i]);
    if(profName[i][lenOfStr-1]=='\n'){
      profName[i][lenOfStr-1] = '\0';
    }
  }
 for(int i=0;i<NUMBER_PROFS;i++){
  for(int j=0; j<NUMBER_COURSES;j++){
   fscanf(fptr,"%d",&coursesTaught[i][j]);
   if(coursesTaught[i][j]==1){
     coursesTaught[i][j] = courseID[j];

  }}
 }
 return 1;
}
//function returns the number of professors and prints the names of these professors taking more than n courses, n specified in prototype
int nCourses (
int n,
char profName [NUMBER_PROFS][MAX_STR],
int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]){
 int counter = 0;
 int profCounter = 0;
  for(int i=0;i<NUMBER_PROFS;i++){
   for(int j=0; j<NUMBER_COURSES;j++){
    if(coursesTaught[i][j]!=0){
     counter++;}
 } 
   if(counter >= n){
   profCounter ++;
   printf("%s \n", profName[i]);
  }
 counter = 0;
 }
return profCounter;
}
/*function looks for courseNum in courseID array. if found, function copies course name corresponding to course Num given, copies string to cNameFound and returns 1
if not, cNameFound becomes an empty string and 0 is returned */
int getCourseName (
int courseNum,
char cNameFound [MAX_STR],
char courseName [NUMBER_COURSES][MAX_STR],
int courseID [NUMBER_COURSES]){
 for(int i =0;i<NUMBER_COURSES;i++){
  if(courseNum==courseID[i]){
   strcpy(cNameFound,courseName[i]);
   return 1;}
  }
strcpy(cNameFound,"");
 return 0;
}
/*function looks for cName in courseName array. if found, function assigns course number corresponding to cName give to cNumFound
if not, 0 is assigned to cNumFound and 0 is returned */
int getCourseNum (
char cName [MAX_STR],
int * cNumFound,
char courseName [NUMBER_COURSES][MAX_STR],
int courseID [NUMBER_COURSES]){
 for(int i =0;i<NUMBER_COURSES;i++){
  if(strcmp(cName,courseName[i])==0){
   * cNumFound = courseID[i];
   return 1;}
  }
 *cNumFound = 0;
 return 0;
}
//function returns the number of professors and prints the names of these professors taking courseNum, courseNum specified in prototype
int profsTeachingCourse (
int courseNum,
char profName [NUMBER_PROFS][MAX_STR],
int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]){
 int profAcc=0;
 for(int i =0;i<NUMBER_PROFS;i++){
 for(int j=0;j<NUMBER_COURSES;j++){
  if(courseNum==coursesTaught[i][j]){
   printf("%s  ",profName[i]);
   profAcc++;
   }}
  }
 return profAcc;
}
//function returns the average number of courses taught by a professor
float avgNumCourses (int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]){
 float sumCourses =0;
 float avgCourses;
 for(int i =0;i<NUMBER_PROFS;i++){
 for(int j=0;j<NUMBER_COURSES;j++){
 if(coursesTaught[i][j] != 0){ 
   sumCourses++;            }}}
 avgCourses = sumCourses / NUMBER_PROFS;
 return avgCourses;
}
//function displays a horizontal histogram showing the number of courses taught by each professor, where each course is represents by one star
void hhistogram (char profName [NUMBER_PROFS][MAX_STR],
int coursesTaught [NUMBER_PROFS][NUMBER_COURSES]){
 int sumCourses = 0;
 for(int i =0;i<NUMBER_PROFS;i++){
 for(int j=0;j<NUMBER_COURSES;j++){
  if(coursesTaught[i][j] != 0){
    sumCourses++;}
   }
  printf("%-8s\t",profName[i]);
  for(int i=0;i<sumCourses;i++){
   printf("*");}
  printf("(%d)\n",sumCourses);
  sumCourses = 0;
}

}
