#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 집의개수
int N;
// 집의 색상별 칠할때 드는 비용
vector<vector<int>> V;
// DP [현재 집의 인덱스][이전 집에서 고른 색상] = 가장 적은 값
vector<vector<int>> DP;

int main()
{
    cin >> N;

    V = vector<vector<int>>(N, vector<int>(3));
    DP = vector<vector<int>>(N, vector<int>(3));

    for (int i = 0; i < N; ++i)
    {
        cin >> V[i][0] >> V[i][1] >> V[i][2];
    }

    DP[0][0] = V[0][0];
    DP[0][1] = V[0][1];
    DP[0][2] = V[0][2];

    for (int i = 1; i < N; ++i)
    {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + V[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + V[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + V[i][2];
    }

    int result = DP[N - 1][0];
    result = min(result, DP[N - 1][1]);
    result = min(result, DP[N - 1][2]);

    cout << result;

    return 0;
}