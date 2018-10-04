#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



int mmatoi(string str)
{
	long x = 0;
	   auto c  =str.begin();
		   for(; c != str.end(); c++)
	   {
		   if(*c != ' ')
			   break;
	   }

	   int sign = 1;
	   if(*c == '-')
	   {
		   c++;
		   sign = -1;
	   }
		   else if( *c == '+')
			   c++;
	   for(; c != str.end(); c++)
	   {

		   if(*c < '0' || *c > '9')
			   break;
		   x = x*10 + (int)(*c) - '0';
		   if (x >  std::numeric_limits<int>::max())
			  break;
	   }
		  x =  x*sign;
		if (x >  std::numeric_limits<int>::max())
			  x =  std::numeric_limits<int>::max();
	   if (x <  std::numeric_limits<int>::min())
		   x =  std::numeric_limits<int>::min();
	   return x;
}



int main(int argc, char **argv)
{
	if(argc == 1)
	{
		cout << "Please input a list of number" << endl;
		cout << "1 5 8 6 11" << " - sample" << endl;
		return -1;
	}
	//cout << argv[1] << endl;

	cout << mmatoi( argv[1]) << endl;
	return 0;
}