#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> subSets1(vector<int> nums)
{
	int n = nums.size();
	int m = pow(2, n);
	vector<vector<int>> res(m);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if((j>>i) & 1)
			{
				res[j].push_back(nums[i]);
			}
		}
	}
	return res;

}



int main()
{
	vector<int> nums(3);
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	vector<vector<int>> res = subSets(nums);
	for (int i = 0; i < nums.size();i++)
	{
		cout<<res[i]<<endl;
	}
}