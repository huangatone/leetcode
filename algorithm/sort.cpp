#include <stdio.h>
#include <iostream>
using namespace std;
#include <map>
#include <memory>
#include <list>
#include <algorithm>
#include <functional>
#include <vector>


void QuickSort()
{
    int numLt[] = {5,2,7,1,8,4,9,3,6,10};
    int len = sizeof(numLt)/ sizeof(int);
    for (int n=0; n<len; n++)
    {
        int index = n;
         for (int m = n; m<len; m++)
         {
             if (numLt[m] < numLt[index])
                index = m;
         }
         swap(numLt[index],numLt[n] );
    }
     cout << __FUNCTION__ << endl;
    for (auto i: numLt)
        cout << i << " ";
    cout << endl;
}
void insertSort()
{
    int numLt[] = {10,8,5,7,3,12,9,7,10};
    int len = sizeof(numLt)/ sizeof(int);
    for (int n=0; n<len; n++)
    {
        for (int m = 0; m<n; m++)
        {
            if(numLt[m] > numLt[n])
                swap(numLt[m] , numLt[n]);
        }
    }
    cout << __FUNCTION__ << endl;
    for (auto i: numLt)
        cout << i << " ";
    cout << endl;
}
void SelectSort()
{
    int numLt[] = {10,8,5,7,3,12,9,7,10};
    int len = sizeof(numLt)/ sizeof(int);
    for (int n=0; n<len; n++)
    {
        int index = n;
         for (int m = n; m<len; m++)
         {
             if (numLt[m] < numLt[index])
                index = m;
         }
         swap(numLt[index],numLt[n] );
    }
     cout << __FUNCTION__ << endl;
    for (auto i: numLt)
        cout << i << " ";
    cout << endl;
}
int partion(int lt[], int l, int r, int value)
{
    if(l>=r)//如果左右下标不对，直接返回 。 
        return -1;
   
    value = lt[l];

    int i =l;
    int j = r;
   
    while (i!=j)
    {
        while ( j>i && lt[j]>= value)
            j--;
        if (j>i)
            lt[i] = lt[j];
        while(j>i&&lt[i] <= value)
            i++;
        if (j>i)
            lt[j] = lt[i];
    }
    lt[i] = value;
    return i;
}
void quick(int lt[], int l, int r, int value)
{
    if(l<r)
    {
        int index = partion(lt,l,r,value);
        if (index == -1)
            return;
        quick(lt,l,index-1,lt[index]);
        quick(lt, index+1, r,lt[index]);
    }
}


void QuickSort2()
{
    int numLt[] = {5,2,7,1,8,4,9,3,6,10};
    int len = sizeof(numLt)/ sizeof(int);
    quick(numLt,0,len,0);
     cout << __FUNCTION__ << endl;
    for (auto i: numLt)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int numLt[] = {10,8,5,7,3,12,9,7,10};
    insertSort();
    SelectSort();
    QuickSort();  //from net
    QuickSort2(); 
}