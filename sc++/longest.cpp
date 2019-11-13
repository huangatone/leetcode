#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 
const int Max_Len = 256;
#define a 10

void longestStr(char str[])
{
  int num[Max_Len] = {-1};
  int len = strlen(str);
  int max = 0;
  int pre_cur = 0;
  int max_len = 0;
  int cur_len = 0;

  for(int n=0; n< len; n++)
  {
    pre_cur = num[ str[n]];
    if( pre_cur == -1 )
    {
      cur_len++;
      //...
    }
    else
    {
        if(cur_len > max_len)
          max_len = cur_len;
        cur_len = n - pre_cur;
    }

    num[ str[n]] = n;
  }

  if (cur_len > max_len) 
        max_len = cur_len; 
}


int main()
{
  
  return 0;

}