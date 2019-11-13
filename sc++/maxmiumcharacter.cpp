#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 


const int Leng = 256;
char maxmiumCh(char* str)
{
    int max = 0;
    char ch ;
    int used[Leng] = {0};

    int index = 0;
    while( *(str+index))
    {
        used[ *(str+index) ]++;
        if(max < used[ *(str+index) ])
            {
                max = used[ *(str+index) ];
                ch = str[index];
            }
        index++;
    }

    return ch;

}

int main()
{
    char str1[] = "Cancelingboththelastbroadcastandthelastloginwhennewbroadcastrequestismade"; 
   std::cout << maxmiumCh(str1) << endl;


   char str[] = "sample string"; 
    cout << "Max occurring character is "
         << maxmiumCh(str)<<endl; 
  return 0;

}