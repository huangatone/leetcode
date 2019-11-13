#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#include <sstream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <ctime>

int total = 10000000;
bool com1(int a_min, int a_max, int b_min, int b_max)
{
    if (!( a_min > b_max || a_max < b_min))
		return true;
    
	//if (!(b_min > a_max || b_max < a_min))
	//	return true;

	return false;
			
   
}
bool com2(int a_min, int a_max, int b_min, int b_max)
{ 
		int a =1,b=2,c=3,d=4;
        {
            int a =1,b=2,c=3,d=4;
        }	
        {
            int a =1,b=2,c=3,d=4;
        }
        {
            int a =1,b=2,c=3,d=4;
        }
    if ((a_min >= b_min && a_min <= b_max) ||
        (a_max >= b_min && a_max <= b_max) ||
        (b_min >= a_min && b_min <= a_max) ||
        (b_max >= a_min && b_max <= a_max)) 
        {
        return true;
        }

    return false;
}


void m1()
{
    int a = 10;
    int b = 50;

    auto start = std::chrono::system_clock::now();
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll a 6-sided die 20 times
    int x,y;
    for (int n=0; n != total; ++n) {
        x = 1 + std::rand()/((RAND_MAX + 1u)/100);  // Note: 1+rand()%6 is biased
        y = x + 1 + std::rand()/((RAND_MAX + 1u)/30);  // Note: 1+rand()%6 is biased
        com1(a,b,x,y);
       //cout << a << " " << b << " "<< x<< " " << y<< " "<<  (com1(a,b,x,y)?"In" : "no in") << endl;
       
    }
    auto end = std::chrono::system_clock::now();

     std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void m2()
{
    int a = 10;
    int b = 50;

    auto start = std::chrono::system_clock::now();
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll a 6-sided die 20 times
    int x,y;
    for (int n=0; n != total; ++n) {
        x = 1 + std::rand()/((RAND_MAX + 1u)/100);  // Note: 1+rand()%6 is biased
        y = x + 1 + std::rand()/((RAND_MAX + 1u)/30);  // Note: 1+rand()%6 is biased
        com2(a,b,x,y);
       //cout << a << " " << b << " "<< x<< " " << y<< " "<<  (com2(a,b,x,y)?"In" : "no in") << endl;
       
    }
    auto end = std::chrono::system_clock::now();

     std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}


void m3()
{
    int a = 10;
    int b = 50;

    auto start = std::chrono::system_clock::now();
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
    // roll a 6-sided die 20 times
    int x,y;
    for (int n=0; n != total; ++n) {
        x = 1 + std::rand()/((RAND_MAX + 1u)/100);  // Note: 1+rand()%6 is biased
        y = x + 1 + std::rand()/((RAND_MAX + 1u)/30);  // Note: 1+rand()%6 is biased
        if ( com2(a,b,x,y) != com1(a,b,x,y))
            cout << "diff" << a << " " << b << " " << x << " " << y << endl;

       //cout << a << " " << b << " "<< x<< " " << y<< " "<<  (com2(a,b,x,y)?"In" : "no in") << endl;
       
    }
    auto end = std::chrono::system_clock::now();

     std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

int main()
{
    cout << "M1 --------------" << endl;
    m1();
    cout << "M2-------------" << endl;
    m2();
    cout << "M3-------------" << endl;
    m3();
    return 0;
}