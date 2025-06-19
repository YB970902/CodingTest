#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 랜선의 개수
int K;
// 필요한 랜선의수
int N;
// 랜선의 개수별 길이
vector<long long> V;

bool isPossible(const long long& len)
{
    long long result = 0;
    for (int i = 0; i < K; ++i)
    {
        result += V[i] / len;
    }

    return result >= N;
}

int main()
{
    cin >> K >> N;

    V.resize(K);

    for (int i = 0; i < K; ++i)
    {
        cin >> V[i];
    }

    // 자를 수 있는 가장 큰 길이
    long long high = *max_element(V.begin(), V.end());
    // 자를 수 있는 가장 작은 길이
    long long low = 1;

    while (low < high)
    {
        // 중심값
        long long mid = (low + high) / 2 + 1;

        if (isPossible(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << low;

    return 0;
}