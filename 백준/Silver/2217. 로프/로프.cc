#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

int main()
{
    cin >> N;

    vec = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }

    // 큰 수를 구해야하므로 내림차순으로 정렬
    sort(vec.begin(), vec.end(), greater<int>());

    // 들 수 있는 가장 큰 값.
    int maxVal = 0;

    for (int i = 0; i < N; ++i)
    {
        // 현재 값. 가장 작은 수이다.
        int currVal = vec[i];

        // 현재 들 수 있는 가장 큰 값은 가장 작은수 * 지금까지 걸려있는 로프의 수이다.
        int currMaxVal = currVal * (i + 1);
        
        maxVal = max(maxVal, currMaxVal);
    }

    cout << maxVal;

    return 0;
}