#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 


const int Leng = 256;

bool isPalindrome(char str[])
{
   int l = 0; 
   int r = strlen(str)-1;
   while(l<r)
   {
       if( str[l] != str[r])
            return false;
        l++;
        r--;
   }
   return true;
}

int main()
{
    //isPalindrome("abba");
    cout <<"abba is " <<  (isPalindrome("abba")? "":"Not") << "Palindrome"<< endl; 
    cout <<"abbccbba is " <<  (isPalindrome("abbccbba")? "":"Not") << "Palindrome"<< endl; 
    cout <<"geeks is " <<  (isPalindrome("geeks")? "":"Not") << "Palindrome"<< endl; 

  return 0;

}