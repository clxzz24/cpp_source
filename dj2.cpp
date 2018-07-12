#include <iostream>
using namespace std;

int main()
{
    int array[10] = {1,1,1,1,1,2,2,2,2,2};
    int sum = 0;
    int square_sum = 0;
    int length = sizeof(array) / sizeof(int);
    int left_var[10], right_var[10];
    for (int i = 0; i<length; i++)
    {
        sum += array[i];
        square_sum += array[i] * array[i];
        left_var[i] = square_sum / (i+1) - (sum / (i+1)) * (sum / (i+1));
    }
    sum = 0;
    square_sum = 0;
    for (int i = length - 1; i>=0; i--)
    {
        sum += array[i];
        square_sum += array[i] * array[i];
        right_var[i] = square_sum / (length - i) - (sum / (length - i)) * (sum / (length - i));
    }

    int res;
    int max_var = 0;
    for (int i = 0;i<length; i++)
    {
        if (max_var < left_var[i] + right_var[length - 1 - i])
        {
            max_var = left_var[i] + right_var[length - 1 - i];
            res = i;
        }
    }
    cout<<res<<endl;
    return 0;
}
