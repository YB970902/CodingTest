#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 계산이 가능한지 여부.
// 모든 심사관의 심사 속도를 mid를 넘기지 않고 몇개까지 가능한지 누적해서, 심사대에 기다리고 있는 사람보다 많이 가능한지 체크한다.
bool isPossible(const long long& mid, const int& n, const vector<int>& times)
{
    long long result = 0;
    
    int m = times.size();
    for(int i = 0; i < m; ++i)
    {
        result += mid / times[i];
    }
    
    return result >= n;
}

long long solution(int n, vector<int> times) {
    int m = times.size();
    
    // 최소값
    long long low = 1;
    // 최대값
    long long high = (*max_element(times.begin(), times.end())) * (long long)n;
        
    while(low < high)
    {
        long long mid = (high + low) / 2;
        
        if(isPossible(mid, n, times))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return high;
}