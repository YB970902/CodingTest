#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 강의의 수, 블루레이의 수
long long N, M;

// 강의의 길이
vector<int> videoTimes;

// mid길이만큼 강의를 나눴을 때 M개보다 더 작거나 동일한 개수의 블루레이가 만들어지는지 여부
bool isPossible(const long long& mid)
{
    long long videoCount = 1;
    long long times = 0;
    for (int i = 0; i < N; ++i)
    {
        // 블루레이의 길이를 초과해버리면 블루레이가 늘어난다.
        if (times + videoTimes[i] > mid)
        {
            ++videoCount;
            times = 0;
        }

        times += videoTimes[i];
    }

    return videoCount <= M;
}

int main()
{
    cin >> N >> M;
    videoTimes.resize(N);

    // 강의의 길이를 넣는다.
    for (int i = 0; i < N; ++i)
    {
        cin >> videoTimes[i];
    }

    long long low = (*max_element(videoTimes.begin(), videoTimes.end()));
    long long high = 1e18;

    while (low < high)
    {
        long long mid = (low + high) >> 1;

        if (isPossible(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << high;

    return 0;
}