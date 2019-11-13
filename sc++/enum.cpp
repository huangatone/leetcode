#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std; 

void Permutations(string str,int l,int r)
{
    if(l ==r)
      cout << str[l];
    else
    {
      for(int i = l; i<r; i++)
      {
        swap(str[l],str[i]);
        Permutations(str, l+1,r);
        swap(str[i],str[l]);
      }
    }
}
void enumC(int n)
{
    

}


int main()
{
  string str = "abcdefghijklmnopqrstuvwxyz1234567890";
  return 0;

}