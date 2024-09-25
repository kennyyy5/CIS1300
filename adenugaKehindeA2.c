/************************adenugaKehindeA2.c**************
Student Name: Adenuga Kehinde Email Id: kadenuga@uoguelph.ca
Due Date: November 3rd Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/
/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall adenugaKehindeA2.c main.c
Running: ./a.out
OR
gcc -std=c99 -Wall adenugaKehindeA2.c main.c -o assn2
Running the Program: ./assn2
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100
#define NUMPROTEINS 64
bool isBasePair (char neu1, char neu2);
bool isItaDnaSequence (char strand1[SIZE], char strand2[SIZE]);
void reverse (char aStrand[SIZE]);
void complementIt (char aStrand [SIZE]);
char  getCode(char protein[3]);
bool isItPalindrome (char aStrand [SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char aStrand [SIZE], char neu);
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins (char aSeq [SIZE]);

char getCode (char protein [3]) {

    // array allProteins has a list of all 3-triplet amino acids required for this assignment
    
    char allProteins[NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA","AGG", "CGA", "CGC","CGG","CGU","GAC", "GAU","AAC","AAU","UGC","UGU","GAA","GAG","CAA","CAG", "GGA", "GGC","GGG","GGU","CAC", "CAU","AUA","AUC","AUU", "UUA", "UUG","CUA","CUC", "CUG", "CUU", "AAA", "AAG","AUG", "UUC","UUU", "CCA", "CCC", "CCG", "CCU", "AGC","AGU","UCA","UCC","UCG", "UCU","ACA","ACC","ACG", "ACU", "UGG","UAC","UAU", "GUA","GUC","GUG", "GUU"};
    
    // array allCodes stores the single-letter code of each triplet given in the above array
    
    char allCodes[NUMPROTEINS] = {'A','A','A','A','R','R','R','R','R','R','D','D','N','N','C','C','E','E','Q','Q', 'G','G','G','G','H','H','I','I','I', 'L','L','L','L','L','L','K','K','M','F','F','P','P','P','P','S','S','S','S','S','S','T','T','T','T', 'W','Y','Y','V','V','V','V'};
    
    for (int i = 0; i < NUMPROTEINS; i++) {
        
       if  (strncmp (protein, allProteins[i], 3) == 0){
            return allCodes [i];
        }
    }
    
    return 'Z';   // to indicate an incorrect code - code that doesn't exist in array allCodes
}

bool isBasePair (char neu1, char neu2){
  if((neu1=='A'&&neu2=='T')||(neu1=='T'&&neu2=='A')||(neu1=='C'&&neu2=='G')||(neu1=='G'&&neu2=='C')){
    return true;}
  else{
    return false;}
}

bool isItaDnaSequence (char strand1[SIZE], char strand2[SIZE]){
  int counter = 0;
  int i;
  for(i=0;i<strlen(strand1);i++){
    bool forCheck = isBasePair(strand1[i], strand2[i]);
    if(forCheck == false){
      counter +=1;}}
  if(counter > 0){
    return false;}
  else{
    return true;}}

void reverse(char aStrand[SIZE]){
  int i;
  int aStrandLength = strlen(aStrand);
  for(i=0;i<(aStrandLength/2);i++){
    char c = aStrand[i];
    aStrand[i]=aStrand[aStrandLength-i-1];
    aStrand[aStrandLength-i-1]=c;}}

void complementIt(char aStrand[SIZE]){
  int i;
  for(i=0;i<strlen(aStrand);i++){
    if(aStrand[i]=='A'){
      aStrand[i]='T';}
    else if(aStrand[i]=='T'){
      aStrand[i]='A';}
    else if(aStrand[i]=='C'){
      aStrand[i]='G';}
    else if(aStrand[i]=='G'){
      aStrand[i]='C';}}}

bool isItPalindrome (char aStrand[SIZE]){
  char originalStrand[SIZE], compareStrand[SIZE];
  int i;
  strcpy(originalStrand,aStrand);
  reverse(aStrand);
  strcpy(compareStrand,aStrand);
  i = strcmp(compareStrand, originalStrand);
  if(i == 0){
    return true;}
  else{
    return false;}}

bool isStrandDnaPalindrome (char aStrand [SIZE]){
  char originalStrand[SIZE], compareStrand[SIZE];
  int i;
  strcpy(originalStrand,aStrand);
  reverse(originalStrand);
  complementIt(aStrand);
  strcpy(compareStrand,aStrand);
  i = strcmp(compareStrand, originalStrand);
  if(i == 0){
    return true;}
  else{
    return false;}
}

int howMany (char aStrand[SIZE], char neu){
  int i;
  int neuCount = 0;
  int strandLength = strlen(aStrand);
  for(i=0;i<strandLength;i++){
    if(aStrand[i]==neu){
      neuCount +=1;}}
  return neuCount;}

void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]){
  int i;
  for(i=0;i<strlen(aSeq);i++){
    if(aSeq[i]=='A'){
      mRNA[i]='U';}
    else if(aSeq[i]=='T'){
      mRNA[i]='A';}
    else if(aSeq[i]=='C'){
      mRNA[i]='G';}
    else if(aSeq[i]=='G'){
      mRNA[i]='C';}
    else{
      mRNA[i]=aSeq[i];}}}

void translateDnaToMrnaProteins (char aSeq [SIZE]){
  char aSeqMrna[SIZE], checkStrand[SIZE][SIZE],getCodeOutput;
  int i,j,k,counter,strandLength;
  k=0;
  counter = 0;
  strandLength = strlen(aSeq);
  dnaToMrna(aSeq,aSeqMrna);
  printf("\nDNA: %s \n", aSeq); 
  printf("MRNA: %s\n", aSeqMrna);
  for(i=0;i<strandLength;i++){
    for(j=0;j<3 && k<strandLength;j++){
      checkStrand[i][j]=aSeqMrna[k];
      k++;}
  checkStrand[i][j+1]= '\0';}
  for(i=0;i<(strandLength/3);i++){
    getCodeOutput =  getCode(checkStrand[i]);
    printf("%s:%c \n", checkStrand[i], getCodeOutput);
    if(getCodeOutput == 'Z'){
      counter+=1; }}
   if(counter !=0){
     printf("The input sequence has an incorrect base \n");}}
