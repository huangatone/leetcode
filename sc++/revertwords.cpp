#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 


void revert(char str[],int n)
{
  int i=n;
    for( i=n; i>=0;i--)
    {
      if(str[i] == ' ')
        break;
    }

    cout << str[i,n] << endl;
    if(i==0)
      return;
    revert(str,i);

}


int main()
{
  
  return 0;

}