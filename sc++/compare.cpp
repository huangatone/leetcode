#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
// Defining comparator function as per the requirement 
static int myCompare(const void* a, const void* b) 
{ 
  
    // setting up rules for comparison 
    return strcmp(*(const char**)a, *(const char**)b); 
} 
// Function to sort the array 
void sort(const char* arr[], int n) 
{ 
    // calling qsort function to sort the array 
    // with the help of Comparator 
    qsort(arr, n, sizeof(const char*), myCompare); 
} 
int values[] = { 40, 10, 100, 90, 20, 25 };



int main()
{
    int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);


    const char* arr[] 
        = { "geeksforgeeks", "geeksquiz", "clanguage" }; 
  
    n = sizeof(arr) / sizeof(arr[0]); 
    int i; 
  
    // Print the given names 
    printf("Given array is\n"); 
    for (i = 0; i < n; i++) 
        printf("%d: %s \n", i, arr[i]); 
  
    // Sort the given names 
   sort(arr, n); 
  
    // Print the sorted names 
    printf("\nSorted array is\n"); 
    for (i = 0; i < n; i++) 
        printf("%d: %s \n", i, arr[i]); 


  return 0;

}