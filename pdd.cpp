#include <iostream>
using namespace std;

int binarySearch(int array[], int n, int k)
{
	int start = 0, end = n - 1;
	int mid;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(array[mid] == k)
		{
			return mid;
		}
		else if (array[mid] > k)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return 0;
}

int jumpStep(int n)
{
	int f = 2;
	int g = 1;
	int res;
	if(n <= 0)
		return 0;
	if(n == 1 || n == 2)
		return n;

	for(int i = 2;i<n;i++)
	{
		res = f + g;
		g = f;
		f = res;
	}
	return res;
}

int main()
{
	int array[6] = {1,2,3,4,5,6};
	int n = sizeof(array) / sizeof(int);
	int k = 6;
	int res = binarySearch(array, n, k);
	cout<<res<<endl;
	res = jumpStep(k);
	cout<<res<<endl;
}