#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int MaxW;

pair<int/* 가치 */, int/* 무게 */> Items[100];
int dp[100000];

// 가치있는 순서대로 하고, 가치가 동일하면 더 가벼운걸로
bool compare(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return (float)lhs.first / lhs.second > (float)rhs.first / rhs.second;
}

int calc(int index, int value, int weight)
{
    if(index >= N) return value;
    if(weight == MaxW)
    {
        return value;
    }
    
    if(weight + Items[index].second <= MaxW)
    {
        int newValue = value + Items[index].first;
        int newWeight = weight + Items[index].second;
        
        if(dp[newValue] > newWeight)
        {
            dp[newValue] = newWeight;
            return max(calc(index + 1, value + Items[index].first, weight + Items[index].second), calc(index + 1, value, weight));
        }
        else
        {
            return value;
        }
    }
    
    return calc(index + 1, value, weight);
}

int main()
{
    cin >> N >> MaxW;
    
    fill_n(dp, 100000, 10e9);
    
    for(int i = 0; i < N; ++i)
    {
        cin >> Items[i].second >> Items[i].first;
    }
    
    sort(Items, Items + N, compare);
    
    int result = 0;
    for(int i = 0; i < N; ++i)
    {
        result = max(result, calc(i, 0, 0));
    }
    
    cout << result;
    
    return 0;
}
