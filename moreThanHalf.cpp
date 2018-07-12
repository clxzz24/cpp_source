#include <iostream>
using namespace std;

int moreThanHalf(int array[], int n)
{

	int res = array[0];
	int count = 1;
	for(int i = 1; i<n; i++)
	{
		if(count == 0){
			res = array[i];
			continue;
		}
		if(array[i] == res)
		{
			count++;
		}
		else
			count--;
	//cout<<count<<endl;
	}
	return res;
}

int main()
{
	int array[9] = {1,2,1,1,3,1,1,1,1};
	int n = sizeof(array) / sizeof(int);
	int res = moreThanHalf(array, n);
	cout<<res<<endl<<n<<endl;
	return 0;
}