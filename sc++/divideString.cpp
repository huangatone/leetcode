#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 
#include <assert.h> 

void divideString(char str[], int n)
{
    assert(n>0);
    int len = strlen(str);
    assert( len%n==0);
    int p = len/n;

    for(int i=0; i< len; i++)
    {
        if(i%p==0 && i!=0)
            cout << endl;
        cout << str[i];  
    }
}


int main()
{
  char str[] = "a_simple_divide_string_quest"; 
  divideString(str,4);
  return 0;

}