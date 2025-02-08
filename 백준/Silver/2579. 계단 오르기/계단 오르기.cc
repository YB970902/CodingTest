#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
int step[300];
int dp[300];

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; ++i)
    {
        cin >> step[i];
    }
    
    dp[0] = step[0];
    dp[1] = step[1] + step[0];
    dp[2] = step[2] + max(step[0], step[1]);
    
    for(int i = 3; i < N; ++i)
    {
        dp[i] = step[i] + max(dp[i - 2], dp[i - 3] + step[i - 1]);
    }
    
    cout << dp[N - 1];
    
    return 0;
}
