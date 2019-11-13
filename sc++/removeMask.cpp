#include <iostream>
#include <string.h>
using namespace std;

const int CharNum = 256;

string removeMask(string &str, string &mask)
{
    int n = mask.size();
    int usedNum[CharNum] = {0};
    string res;
    for(int i=0; i< n; i++)
    {
        usedNum[ mask[i]] ++;
    }
    n = str.size();
    for(int i=0; i < n; i++)
    {
        if( usedNum[ str[i] ]==0)
            res.push_back( str[i]);
    }
    return res;
}

char* removeMask(char* str, char* mask)
{
    int usedNum[CharNum] = {0};
    int index = 0;
    while( *(mask+index))
    {
        usedNum[ *(mask+index)] ++;
        index++;
    }

    int curIndex = 0;
    index = 0;
    while( *(str+index))
    {
        if( usedNum[ *(str+index)] ==0)
        {
            str[curIndex] = str[index];
            curIndex++;

        }
        index++;
    }
     *(str+curIndex) = '\0'; 
    return str;
}
int main()
{
    string str   = "geeksforgeeks"; 
    string mask  = "mask"; 
    std::cout << removeMask(str, mask) << endl; 



    char str1[]         = "geeksforgeeks"; 
    char mask_str[]  = "mask"; 
    printf("%s", removeMask(str1, mask_str));
    return 0;
}