#include <iostream>
using namespace std;

int findMax(int x, int y)
{
	return x>=y?x:y;
}

int findMin(int x, int y)
{
	return x<=y?x:y;
}

int maxProduct(int array[], int n)
{
	int res = array[0];
	int Max = array[0];
	int Min = array[0];
	for(int i = 1; i<n; i++)
	{
		int tmp1 = Max * array[i];
		int tmp2 = Min * array[i];   //一定要用tmp
		Max = findMax(findMax(tmp1, tmp2), array[i]);
		//Max = findMax(Max, array[i]);
		Min = findMin(findMin(tmp1, tmp2), array[i]);
		//Min = findMin(Min * array[i], array[i]);
		res = findMax(Max, res);
	}
	return res;
}

int main()
{
	int a[3] = {-4,-3,-2};
	int n = sizeof(a) / sizeof(int);
	int res = maxProduct(a, n);
	cout<<res<<' ';
	return 0;
}