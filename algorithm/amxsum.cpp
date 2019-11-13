#include <stdio.h>
#include <iostream>
using namespace std;
int gcd(int m, int n)
{
    while (n!=0)
    {
        int rem = m%n;
        m = n;
        n = rem;
        cout << n << endl;;
    }
    cout << m << endl;
    return m;
}
int maxsum( int v[], int n)
{
    cout << "size= " << n << endl;
    int max_sum =-INT_MAX;
    int start = 0;
    int end = 0;
    for (int i=0; i<n; i++)
    {
        int sum = 0;
        for (int j=i; j<n; j++)
        {
            sum += v[j];
            if(sum > max_sum)
            {
                max_sum = sum;
                start = i;
                end = j;
            }
        }
    }

    cout << start << " - " << end << " = " << max_sum << endl;
    return max_sum;
}

int main()
{
    int valuse[] = { 4,-3,5,-2,-1,2,6,-2};
    maxsum(valuse, sizeof( valuse)/sizeof(int));
    gcd(1989,1590);
    return 0;
}