#include <iostream>

using namespace std;

// 수의 길이
int N;

int main()
{
    cin >> N;

    int currSum = 0;
    int maxSum = 0;

    --N;
    cin >> currSum;
    maxSum = currSum;
    
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        currSum = max(temp, currSum + temp);
        maxSum = max(maxSum, currSum);
    }

    cout << maxSum;

    return 0;
}