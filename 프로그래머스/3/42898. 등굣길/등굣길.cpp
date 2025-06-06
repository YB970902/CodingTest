#include <string>
#include <vector>

using namespace std;

// 타일을 통해 지나갈 수 있는 경우의 수
vector<vector<int>> dp;

const int MOD = 1e9 + 7;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    // 벡터를 m, n 만큼 할당하고 0을 넣는다.
    dp = vector<vector<int>>(m + 2, vector<int>(n + 2, 0));
    
    for(int i = 0, size = puddles.size(); i < size; ++i)
    {
        // 물에 잠겨있으면 경우의 수는 -1이다.
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    // 시작점은 1을 넣어준다.
    dp[1][1] = 1;
    
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            // 시작점은 넘어간다.
            if(i == 1 && j == 1) continue;
            
            // 물에 잠긴 곳은 넘어간다.
            if(dp[i][j] == -1)
            {
                // -1을 그대로 두면 더할때 0이 되므로 0으로 바꾼다.
                dp[i][j] = 0;
                continue;
            }
            
            if(dp[i - 1][j] > 0) dp[i][j] += dp[i - 1][j];
            if(dp[i][j - 1] > 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    
    return dp[m][n];
}