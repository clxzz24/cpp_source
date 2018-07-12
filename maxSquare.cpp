#include <iostream>
using namespace std;

int maxSquare(vector<std::vector<char> &matrix)
{
	if(matrix.empty() || matrix[0].empty())
		return 0;
	int m = matrix.size(), n = matrix[0].size(), res = 0;
	vector<vector<int>> dp(m, vector<int>(n, 0));
	for(int i = 0;i<m;i++)
	{
		if(matrix[i][0] == '1')
		{
			dp[i][0] = 1;
			res = 1;
		}
	}
	for(int j = 0;j<n;j++)
	{
		if(matrix[0][j] == '1')
		{
			dp[0][j] = 1;
			res = 1;
		}
	}
	
	for(int i = 1;i<m; i++)
	{
		for(int j = 1;j<n; j++)
		{
			if(matrix[i][j] == '1')
			{
				dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
			}
			res = max(res, dp[i][j]);
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix;
	int res = maxSquare(matrix);
	cout<<res<<' ';
}