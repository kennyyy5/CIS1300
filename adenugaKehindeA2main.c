/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall ww7Q2.c ww7Q1.c
Running: ./a.out
OR
gcc -std=c99 -Wall ww7Q2.c ww7Q1.c -o assn2
Running the Program: ./assn2
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100
#define NUMPROTEINS 64
bool isBasePair(char neu1, char neu2);
bool isItaDnaSequence(char strand1[SIZE], char strand2[SIZE]);
void reverse(char aStrand[SIZE]);
void complementIt(char aStrand[SIZE]);
char  getCode(char protein[3]);
bool isItPalindrome (char aStrand [SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char aStrand [SIZE], char neu);
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins (char aSeq [SIZE]);
int main(){
char neuA='A';
char neuT='T';
char neuC='C';
char neuG='G';
char strandA[SIZE],strandB[SIZE];
char strandMRNA[SIZE];
/*
bool testIsBasePair1 =  isBasePair(neuA, neuT);
bool testIsBasePair2 =  isBasePair(neuA, neuG);
bool testIsBasePair3 =  isBasePair(neuC, neuT);
bool testIsBasePair4 =  isBasePair(neuC, neuG);
printf("%d %d %d %d ",testIsBasePair1, testIsBasePair2, testIsBasePair3, testIsBasePair4 );
strcpy(strandA,"ATCG");
strcpy(strandB,"CATG");
bool testIsItaDnaSequence1 = isItaDnaSequence(strandA, strandB);
strcpy(strandA,"GATC");
strcpy(strandB,"TCAG");
bool testIsItaDnaSequence2 = isItaDnaSequence(strandA, strandB);
strcpy(strandA,"AGGC");
strcpy(strandB,"TCCG");
bool testIsItaDnaSequence3 = isItaDnaSequence(strandA, strandB);
printf("%d %d %d", testIsItaDnaSequence1, testIsItaDnaSequence2, testIsItaDnaSequence3);
strcpy(strandA,"GATC");
complementIt(strandA);
printf("%s ",strandA);
strcpy(strandA,"TCAG");
complementIt(strandA);
printf("%s ",strandA);
strcpy(strandA,"TCCG");
complementIt(strandA);
printf("%s ",strandA);
strcpy(strandA,"GATC");
reverse(strandA);
printf("%s ",strandA);
strcpy(strandA,"TCAG");
reverse(strandA);
printf("%s ",strandA);
strcpy(strandA,"TCCG");
reverse(strandA);
printf("%s ",strandA);
strcpy(strandB, "MADAM");
bool testIsItPalindrome1 = isItPalindrome(strandB);
strcpy(strandB, "SOCKS");
bool testIsItPalindrome2 = isItPalindrome(strandB);
strcpy(strandB, "SHOW");
bool testIsItPalindrome3 = isItPalindrome(strandB);
printf("%d %d %d", testIsItPalindrome1, testIsItPalindrome2, testIsItPalindrome3);
*/
strcpy(strandB, "AT");
bool testIsStrandDnaPalindrome1 = isStrandDnaPalindrome(strandB);
strcpy(strandB, "C");
bool testIsStrandDnaPalindrome2 = isStrandDnaPalindrome(strandB);
strcpy(strandB, "GGGGGG");
bool testIsStrandDnaPalindrome3 = isStrandDnaPalindrome(strandB);
printf("%d %d %d", testIsStrandDnaPalindrome1, testIsStrandDnaPalindrome2, testIsStrandDnaPalindrome3);
/*
strcpy(strandA, "GCCAGTCAT");
int testHowMany1 = howMany(strandA, neuA);
int testHowMany2 = howMany(strandA, neuT);
int testHowMany3 = howMany(strandA, neuC);
int testHowMany4 = howMany(strandA, neuG);
printf("%d %d %d %d   ", testHowMany1, testHowMany2, testHowMany3,testHowMany4);
strcpy(strandA, "GCCA");
dnaToMrna(strandA, strandMRNA);
printf("%s %s  ", strandA, strandMRNA);
strcpy(strandA, "CTAG");
dnaToMrna(strandA, strandMRNA);
printf("%s %s  ", strandA, strandMRNA);
strcpy(strandA, "ATAG");
dnaToMrna(strandA, strandMRNA);
printf("%s %s  ", strandA, strandMRNA);
strcpy(strandB, "GCCATG");
char testGetCode;
testGetCode=getCode(strandB);
printf(" %c", testGetCode);
strcpy(strandB, "GTACCA");
translateDnaToMrnaProteins(strandB);
strcpy(strandB, "TATCGG");
translateDnaToMrnaProteins(strandB);
strcpy(strandB, "TAXCBB");
translateDnaToMrnaProteins(strandB);
strcpy(strandB, "TAGCAGGT");
translateDnaToMrnaProteins(strandB);
*/
 return 0;
}
