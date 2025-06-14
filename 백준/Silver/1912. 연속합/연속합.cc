#include <iostream>
#include <cmath>

using namespace std;

// 수열의 길이
int N;

int main()
{
    cin >> N;

    int currVal = 0;
    int pSum = 0;
    int maxVal = -1e9;
    for (int i = 0; i < N; ++i)
    {
        cin >> currVal;
        pSum = max(currVal, pSum + currVal);
        maxVal = max(maxVal, pSum);
    }

    cout << maxVal;

    return 0;
}