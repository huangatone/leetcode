#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



string convert(string s, int numRows) {
	if(numRows <=1 || numRows >= s.length())
		return s;
		string n_res;
		int step = 0;
		int repeat = (numRows-1)*2;
		for(int m=0; m<numRows; m++)
		{
			int cur = m;
			int row = 0;
			step = (numRows - 1 - m)*2;
			qDebug() << m << "-------------------";

			if(m==0)
			{
				while(cur < s.length())
				{
					n_res.push_back(s.at(cur));
					qDebug() << cur;
					row++;
					cur += repeat;

				}
			}
			else if(m == numRows-1)
			{
				while(cur < s.length())
				{
					n_res.push_back(s.at(cur));
					qDebug() << cur;
					row++;
					cur += repeat;

				}
			}
			else
			{
				while(cur < s.length())
				{
					n_res.push_back(s.at(cur));
					qDebug() << cur << cur+step;
					if(cur +step< s.length())
						n_res.push_back(s.at(cur+step));
					row++;
					cur += repeat;

				}
			}
		}

		return n_res;

	}



int main(int argc, char **argv)
{
	if(argc == 1)
	{
		cout << "Please input a string" << endl;
		return -1;
	}
	cout << argv[0] << endl;
	cout << argv[1] << endl;
	auto s = convert(argv[1], atoi(argv[2]) );

	cout << s << endl;
	
	return 0;
}