#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 


const int Leng = 256;

void countRepeat(char* str, int n)
{
    int num[Leng] = {0};
    for(int i=0; i< n; i++)
    {
        num[ (int)str[i]] ++;
    }

std::cout << "Start num \n";
    for(int i =0; i< Leng; i++ )
    {
        if(num[i] > 0)
        {
            //std::cout << "i = " << i <<endl;
            printf("%c, count = %d  index= %d\n", i, num[i],i); 
        }
    }
}

int main()
{
    char str1[] = "Canceling both the last broadcast and the last login when a new broadcast request is made"; 
   countRepeat(str1, strlen(str1));
  return 0;

}