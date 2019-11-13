#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 

const int Leng = 256;
char *removeDuplicate(char str[], int n) 
{ 
   // Used as index in the modified string 
   int index = 0;    
   char* res_str = new char[n];
     
   // Traverse through all characters 
   for (int i=0; i<n; i++) 
   { 
         
     // Check if str[i] is present before it   
     int j;   
     for (j=0; j<i; j++)  
        if (str[i] == str[j]) 
           break; 
       
     // If not present, then add it to 
     // result. 
     if (j == i) 
        res_str[index++] = str[i]; 
   } 
     
   return res_str; 
} 

char *removeDuplicate(char *str) 
{ 
   // Used as index in the modified string 
   int used[Leng] = {0};
   int index = 0;
   int res_index = 0;
   while( *(str+index)) 
   {
       if(used[ *(str+index)] ==0)
       {
           str[res_index++] = str[index];
          
       }
       used[ *(str+index)]++;
       index++;
   }
   str[res_index] = '\0';
   return str; 
} 

int main()
{
    char str[]= "geeksforgeeks"; 
    int n = sizeof(str) / sizeof(str[0]);
    char* after_str =  removeDuplicate(str, n); 
   cout << "After removed: " <<  after_str << endl;
   cout << "After removed 1= : " <<  removeDuplicate(str) << endl; 
   delete [] after_str;

  return 0;

}