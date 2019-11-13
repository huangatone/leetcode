#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 
#include <vector>

const int Totle = 256;

void firstNoRepeat(char str[])
{
  int num[Totle] = {0};
  for(int i=0; i< strlen(str); i++)
  {
      num[ str[i] ]++;
  }

  bool isNoRepeat = true;
  for(int i=0; i< strlen(str); i++)
  {
      if( num[ str[i] ] ==1)
      {
        cout << "first = " << str[i] << endl;
        isNoRepeat = false;
        break;
      }
  }

  if(isNoRepeat)
    cout << "No found! \n";
}

int main()
{
  char str[] = "geeksforgeeks"; 
  firstNoRepeat(str);
  return 0;

}