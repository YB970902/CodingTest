#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int long long R;

int coin[101];
int dp[10001];

int main()
{
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> coin[i];
    }

    sort(coin, coin + N);

    for (int i = 0; i < N; ++i)
    {
        if (coin[i] > K)
        {
            N = i;
            break;
        }
    }

    for (int i = 0; coin[0] * i <= K; ++i)
    {
        ++dp[coin[0] * i];
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            if (dp[j] == 0) continue;
            int currCoin = j + coin[i];
            if (currCoin > K) break;

            dp[currCoin] += dp[j];
        }
    }

    cout << dp[K];

    return 0;
}