#include <iostream>
#include <vector>

using namespace std;

// 만들어야 하는 수
int N;

// 누적합을 가질 벡터
vector<int> vec;

int main()
{
    cin >> N;

    int left = 0;
    int right = 1;
    int leftVal = 0;
    int rightVal = 1;

    int result = 0;

    while (right <= N)
    {
        int val = rightVal - leftVal;
        if (val == N)
        {
            ++result;
            ++right;
            rightVal += right;
        }
        if (val < N)
        {
            ++right;
            rightVal += right;
        }
        else
        {
            ++left;
            leftVal += left;
        }
    }

    cout << result;

    return 0;
}