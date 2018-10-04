#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

	vector<int> nums_tmp = nums;

	std::sort(nums.begin(),nums.end());
	int half = target /2;
	bool bOK = false;
	vector<int>  res;
	for(int n=0; n< nums.size() , nums[n] < half+1; n++ )
	{
		for(int m= nums.size()-1; m >0, nums[m]> half-1; m--)
		{
			if( nums[n] + nums[m] == target)
			{
				res.push_back(nums[n]);
				res.push_back(nums[m]);
				bOK = true;
			}
			else if(nums[n] + nums[m] < target )
				break;

		}
		if(bOK)
			break;
	}

	if(bOK)
	{
		vector<int>  res1;
		for(int n=0; n< nums_tmp.size(); n++ )
		{
			if( nums_tmp[n] == res[0] || nums_tmp[n] == res[1])
			{
				res1.push_back(n);
				if(res1.size() == 2)
					return res1;
			}

		}
	}
	return vector<int>();
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

	vector<int> numbs;
	for(int n =1; n< argc-1; n++)
	{
		numbs.push_back( atoi( argv[n]));
		cout << argv[n] << endl;
	}
	cout << "result = " << argv[argc-1] << endl;
	

	auto res_nums = twoSum(numbs, atoi(argv[argc-1]) );
	for(auto num = res_nums.begin(); num != res_nums.end(); num++)
		cout << *num << endl;
	return 0;
}