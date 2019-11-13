#include <stdio.h>
#include <iostream>
using namespace std;

//Linear Search: from 0-n, check one by one
//Binary Search: check n/2->n/4-->n/8... or n/2-> n/2+n/4 ->  n/2+n/4... 
//Jump Search check m,2m ,3m,...m=n^2 then 2m-3m, m1 = m^2 , 
//Interpolation Search, Exponential Search, Ternary Search
bool totalDigit(int n )
{
    n = abs(n);
    if(n==0 || n==3 || n==6 || n==9)
    {
        //cout << n << endl;
        return true;
    }    
    if(n<10)
    {
        //cout << n << endl;
        return false;
    }   
    int total = 0;
    while(n>=10)
    {
        total+= n%10;
        n = n/10;
    }
    total+=n;
    return totalDigit(total);
}
int main()
{
    std::cout << "num 24 is *3 "  << totalDigit(24) << std::endl;
    std::cout << "num 25 is *3 "  << totalDigit(25) << std::endl;
    std::cout << "num 35 is *3 "  << totalDigit(35) << std::endl;
    std::cout << "num 214 is *3 "  << totalDigit(214) << std::endl;
    std::cout << "num 2432 is *3 "  << totalDigit(2432) << std::endl;
    std::cout << "num 24343254 is *3 "  << totalDigit(24343254)<< std::endl;
}