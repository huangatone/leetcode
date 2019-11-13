#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 





int main()
{
 string str = "AABAACAADAABAAABAA"; 
    string pat = "AABA"; 
    int n=0;
    while( (n = str.find(pat,n)) != string::npos)
    {
        cout << "find " << n++ << endl;
    }
    
  return 0;

}