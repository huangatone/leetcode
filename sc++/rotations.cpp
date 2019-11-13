//#include <stdlib.h>
//#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;


bool isRotations(string &str1, string &str2)
{
    if (str1.size() != str2.size())
        return false;
    string str = str1 + str1;
    if(str.find(str2) != string::npos) //string::npos;
        return true;
    return false;
}

int main() {
	string str1 = "ABCD", str2 = "ACBD"; 
   if (isRotations(str1, str2)) 
     printf("Strings are rotations of each other \n"); 
   else
      printf("Strings are not rotations of each other\n"); 
   return 0; 
}
