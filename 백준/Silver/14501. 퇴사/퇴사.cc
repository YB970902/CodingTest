#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> vecTime;
vector<int> vecPay;
int dp[16];

int main()
{
    fill_n(dp, 16, 0);
    
    cin >> N;
    
    vecTime = vector<int>(N);
    vecPay = vector<int>(N);
    
    for(int i = 0; i < N; ++i)
    {
        cin >> vecTime[i];
        cin >> vecPay[i];
    }
    
    int max_pay = 0; // 최댓값을 저장하는 변수
    
    for(int i = 0; i <= N; i++) {
        
        dp[i] = max(max_pay, dp[i]);
        
        // 잘못된 메모리 참조를 하지 않기 위한 조건
        if (vecTime[i] + i <= N) {
            dp[vecTime[i] + i] = max(dp[vecTime[i] + i], vecPay[i] + dp[i]);
        }
        
        max_pay = max(max_pay, dp[i]);
    }
    
    cout << max_pay;
    
    return 0;
}
