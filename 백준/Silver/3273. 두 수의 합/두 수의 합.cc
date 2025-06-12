#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 수열의 크기
int N;
// 목표 값
int M;
// 수열을 담는 벡터
vector<int> vec;

int main()
{
    cin >> N;

    vec.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    cin >> M;

    sort(vec.begin(), vec.end());

    // 최대값을 다시 잡는다. 목표값보다 크면 계산하지 않는다.
    for (int i = 0; i < N; ++i)
    {
        if (vec[i] > M)
        {
            N = i;
            break;
        }
    }

    int left = 0;
    int right = N - 1;

    int result = 0;
    while (left < right)
    {
        int val = vec[left] + vec[right];

        if (val < M)
        {
            ++left;
        }
        else if (val > M)
        {
            --right;
        }
        else
        {
            ++result;
            ++left;
            --right;
        }
    }

    cout << result;
}