#include <iostream>
#include <sstream>
#include <vector>

using namespace std;



int reverse(int x) {
		int sign = x>0?1:-1;
		x = abs(x);
		string s =to_string(x);
		std::reverse(s.begin(),s.end());
		qDebug() << QString::fromStdString(s);
		x = atoi(s.data());
		long l = atol(s.data());
		if(l > std::numeric_limits<int>::max())
			return 0;
		qDebug() << x << sign;
		x *=sign;
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

	cout << reverse( atoi(argv[1])) << endl;
	return 0;
}