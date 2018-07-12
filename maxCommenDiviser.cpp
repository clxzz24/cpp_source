#include <iostream>
using namespace std;

int maxCommenDiviser(int a, int b) // 辗转相除法
{
	if(a == b)
	{
		return a;
	}
	int max = a>b?a:b;
	int min = a<b?a:b;
	//int res;
	while(max % min != 0)
	{
		int tmp = min;
		min = max % min;
		max = tmp;
	}
	return min;
}

int main()
{
	//int a = 12, b = 18;
	int res = maxCommenDiviser(12,18);
	cout<<res<<endl;
}