#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 배열의 개수
int N;

// 가장 낮은 값(알칼리)과 가장 높은 값(산성)
long long low = -1e18, high = 1e18;

// 가장 높은값과 낮은값의 차이
long long offset = 1e18;

// 용액이 들어있는 배열
vector<int> vec;

int main()
{
    cin >> N;

    vec.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    // 투포인터를 위한 왼쪽, 오른쪽 변수.
    int left = 0;
    int right = N - 1;

    // 왼쪽과 오른쪽 변수의 차이
    long long currOffset = 1e18;

    // 모든 리스트를 검색했다면 멈춘다.
    while (left < right)
    {
        currOffset = vec[left] + vec[right];
        long long absOffset = abs(currOffset);

        if (absOffset < offset)
        {
            offset = absOffset;
            low = vec[left];
            high = vec[right];
        }

        // currOffset이 음수라면 왼쪽 포인터를 이동시킨다.
        if (currOffset < 0)
        {
            ++left;
        }
        // currOffset이 양수라면 오른쪽 포인터를 이동시킨다.
        else if (currOffset > 0)
        {
            --right;
        }
        // 합이 0인 결과를 찾은경우 멈춘다.
        else break;
    }

    cout << low << ' ' << high;

    return 0;
}