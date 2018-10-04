#include <iostream>
#include <sstream>
#include <vector>

using namespace std;





string longestPalindrome(string s ,int left,int right)
{
	if(left <0 || right >= s.length())
		return string();
	int res_left = left;
	int res_right = left;
	while( left >= 0  &&  right < s.length() && s.at(left) == s.at(right))
	{
		res_left = left;
		res_right = right;
	   left--;
	   right++;
	}
	int r1 = res_right - res_left+1;

	return  s.substr(res_left,r1);

}


string longestPalindrome(string s) {

	string res;

	for(int n= 0; n<s.length(); n++)
	{
		string tmp1 =longestPalindrome(s,n,n);
		string tmp2 =longestPalindrome(s,n-1,n);
		string tmp3 =longestPalindrome(s,n,n+1);
		if(res.length() < tmp1.length())
			res = tmp1;
		if(res.length() < tmp2.length())
			res = tmp2;
		if(res.length() < tmp3.length())
			res = tmp3;
		if(res.length() > (s.length() - n)*2)
			break;
	}
	return res;
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
	auto s = longestPalindrome(argv[1]);

	cout << s << endl;
	
	return 0;
}