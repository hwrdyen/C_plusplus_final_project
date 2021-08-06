/* Method Madness
Howard Yen
May 28, 2018
  Write a program that lets you enter a word,
  such as: Canada,
  the program should use functions
  to print out the word in the following ways:
  
Canada  Canada  Canada  C-a-n-a-d-a  adanaCCadanada
Canad   anada    anada   C-a-n-a-d     danaCCanad
Cana    nada      nada    C-a-n-a       anaCCana
Can     ada        ada     C-a-n         naCCna
Ca      da          da      C-a           aCCa
C       a            a       a             CC */

#include<iostream> //include header iostream
using namespace std; //using namespace std to avoid typing std::

char word[1000]; //declare functions 
void errorcheck(char[],int); 
int length(char[]); 

void a(int); 
void b(int); 
void d(int); 
void e(int); 
void f(int); 

int main(){ 
  
 int count; //output message and recieve data 
 cout<<"Enter the word you wish to enter: "; 
 gets(word); //use gets so it gets whitespace for errorcheck 
 
 count=length(word); //gets the length of the word 

 errorcheck(word,count); //errorcheck 

 count=length(word); //recalculate the length  
 cout<<"\n";
 a(count); //call a function
 cout<<"\n"; 
 b(count); //call b function 
 cout<<"\n"; 
 d(count); //call d function
 cout<<"\n"; 
 e(count); //call e function 
 cout<<"\n"; 
 f(count); //call f function
} 

int length (char word[1000]) { 
  int count=0; //declare variable 
  for(int c=1;c<10000;c++){ 
      if(word[c]=='\0'){ 
      break; 
      } 
  
      else { 
      count++; 
      } //else keep track how many alphabet 
  } //set forloop to check each space 
 
 return(count); //return answer to main function 
} //create length function
 
void a(int count){  
 for(int i=count;i>=0;i--){  
  for(int j=0;j<=i;j++){ 
   cout<<word[j]; 
  } //set loop for the characters outputed in each row
  cout<<"\n"; 
 } //set for loop for rows (the length = the number of rows) 
} //a function
 
void b(int count){ 

 for(int i=count;i>=0;i--){  
  for(int j=i;j>=0;j--){ 
   cout<<word[count-j]; 
  } //set loop for the characters outputed in each row
  cout<<"\n"; 
 } //set for loop for rows (the length = the number of rows) 
} //b function

void d(int count){ 
 for(int i=count;i>=0;i--){  
  for(int s=0;s<count-i;s++){ 
   cout<<" "; 
  } 
  for(int j=i;j>=0;j--){ 
   cout<<word[count-j]; 
  } //set loop so it will add one more space to each row
  cout<<"\n"; 
 } //set for loop for rows (the length = the number of rows) 
} //d funtion
 
void e(int count){ 
 //set for loop for rows (the length = the number of rows) 
 for(int i=count;i>=0;i--){ 
  //set loop so it will add one more space to each row 
  for(int s=0;s<count-i;s++){ 
   cout<<" "; 
  } 
  //same as a function 
  for(int j=0;j<=i;j++){ 
   cout<<word[j]; 
   //add - after each alphabet except after the last alphabet in each row 
   if(j!=i){ 
    cout<<"-"; 
   } 
  } 
  cout<<"\n"; 
 } 
} //e function

void f(int count){ 
 //set for loop for rows (the length = the number of rows) 
 for(int i=count;i>=0;i--) 
 { 
  //set loop so it will add one more space to each row 
  for(int s=0;s<count-i;s++){ 
   cout<<" "; 
  } 
  //same as d function but add one so the it will skip the first alphabet 
  for(int j=i;j>0;j--){ 
   cout<<word[count+1-j]; 
  } 
  cout<<word[0]; //cout the first alphabet 
  for(int j=0;j<=i;j++){ 
   cout<<word[j]; 
  } 
  cout<<"\n"; 
 } 
} //f function
 
void errorcheck(char word[1000],int count){ 
 //set flag to -1 
 int flag=-1; 
 //loop while flag does not equal to 0 
 while(flag!=0){ 
  //set if statement so the message won't output the first time entering this function 
  if(flag!=-1){ 
   cout<<"please enter only one word\n"; 
   gets(word); 
   //recalculate the length so later on the errorcheck would be accurate 
   count=length(word); 
  } 
  //set flag to 0 
  flag=0; 
  //set loop to check space in the array 
  for(int c=1;c<count;c++){ 
   //if equals to space add one to flag 
   if(word[c]==' '){ 
    flag++; 
   } 
  } 
 } 
} //errorcheck so the user won't type in a sentence