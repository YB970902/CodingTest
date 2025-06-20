#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 배열의 개수와 목표 인덱스.
long long N, K;

int main()
{
    cin >> N >> K;

    long long low = 1;
    long long high = K;
    long long result = 0;

    while (low <= high)
    {
        long long mid = (low + high) >> 1;

        long long count = 0;
        for (int i = 1; i <= N; ++i)
        {
            count += min(mid / i, N);
        }

        if (count < K)
        {
            low = mid + 1;
        }
        else
        {
            result = mid;
            high = mid - 1;
        }
    }

    cout << result;

    return 0;
}