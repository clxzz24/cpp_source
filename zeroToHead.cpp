#include <iostream>
using namespace std;

void zeroToHead(int array[], int n)
{
	int zero_idx = n - 1;
	int nonzero_idx = n - 1;
	for(nonzero_idx = n - 1; nonzero_idx>=0; nonzero_idx--)
	{
		if(array[nonzero_idx] != 0)
		{
			int tmp = array[nonzero_idx];
			array[nonzero_idx] = array[zero_idx];
			array[zero_idx] = tmp;
			zero_idx--;
		}
	}
}

int main()
{
	int p[4] = {1,2,3,4};
	int n = sizeof(p) / sizeof(int);
	zeroToHead(p, n);
	for (int i = 0; i<n; i++)
	{
		cout<<p[i]<<' ';
	}
	return 0;
}