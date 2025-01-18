#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N;

int dp[12][12][12];

int go(int val1, int val2, int val3, int count)
{
    int value = dp[val1][val2][val3];
    if(value == -1)
    {
        dp[val1][val2][val3] = 1 * val1 + 2 * val2 + 3 * val3;
        value = dp[val1][val2][val3];
    }
    
    if(value > N) return count;
    else if(value == N) return count + 1;
    
    count = max(count, go(val1 + 1, val2, val3, count));
    count = max(count, go(val1, val2 + 1, val3, count));
    count = max(count, go(val1, val2, val3 + 1, count));
    
    return count;
}

int main()
{
    fill(&dp[0][0][0], &dp[11][11][11], -1);
    
    cin >> T;
    
    for(int i = 0; i < T; ++i)
    {
        cin >> N;
        
        cout << go(0, 0, 0, 0) << '\n';
    }
    
    return 0;
}
