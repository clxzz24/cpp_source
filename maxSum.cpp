#include <iostream>
using namespace std;

int maxSum(int array[], int n)
{
	int res = array[0];
	int resi = array[0];
	for(int i = 1; i<n; i++)
	{
		resi = resi + array[i] > array[i] ? resi + array[i]:array[i];
		res = resi>res?resi:res;
	}
	return res;
}

int main()
{
	int a[5] = {1,2,-7,3,4};
	int n = sizeof(a) / sizeof(int);
	int res = maxSum(a, n);
	cout<<res<<' ';
	return 0;
}