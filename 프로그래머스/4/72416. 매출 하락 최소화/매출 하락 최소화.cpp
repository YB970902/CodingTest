#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> salesCopy;
vector<vector<int>> dp;
unordered_map<int, vector<int>> tree;

int MAX_VALUE = 1e9;

// 워크샵에 갈 멤버를 찾는다.
int SearchMember(int nodeIdx/*현재 노드의 인덱스*/, bool isCount/*현재 노드가 참석하는지 여부*/)
{
    int countIdx = isCount ? 1 : 0;
    
    // 노드에 자식이 없다면 반환한다.
    if(tree.find(nodeIdx) == tree.end())
    {
        if(dp[nodeIdx][countIdx] == MAX_VALUE)
        {
            dp[nodeIdx][countIdx] = isCount ? salesCopy[nodeIdx] : 0;
        }
        
        return dp[nodeIdx][countIdx];
    }
    
    if(dp[nodeIdx][countIdx] < MAX_VALUE)
    {
        return dp[nodeIdx][countIdx];
    }
    
    if(isCount)
    {
        int result = salesCopy[nodeIdx];
        for(int i = 0, count = tree[nodeIdx].size(); i < count; ++i)
        {
            int childIdx = tree[nodeIdx][i];
            result += min(SearchMember(childIdx, true), SearchMember(childIdx, false));
        }
        
        dp[nodeIdx][1] = result;
        
        return result;
    }
    else
    {
        int result = 0;
        bool nonCount = true; // 아무도 참석하지 않는지 여부
        
        for(int i = 0, count = tree[nodeIdx].size(); i < count; ++i)
        {
            int childIdx = tree[nodeIdx][i];
            
            int countValue = SearchMember(childIdx, true); // 참여했을때 값
            int nonCountValue = SearchMember(childIdx, false); // 참여하지 않았을때 값
            if (countValue < nonCountValue) nonCount = false;
            
            result += min(countValue, nonCountValue);
        }
        
        if(nonCount)
        {
            int minValue = MAX_VALUE;
            for(int i = 0, count = tree[nodeIdx].size(); i < count; ++i)
            {
                int childIdx = tree[nodeIdx][i];
                
                int countValue = SearchMember(childIdx, true); // 참여했을때 값
                int nonCountValue = SearchMember(childIdx, false); // 참여하지 않았을때 값
                
                minValue = min(minValue, countValue - min(countValue, nonCountValue));
            }
            result += minValue;
        }
        
        dp[nodeIdx][0] = result;
        
        return result;
    }
    
    return 0;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    salesCopy = sales;
    
    dp = vector<vector<int>>(sales.size());
    
    for(int i = 0, count = sales.size(); i < count; ++i)
    {
        dp[i] = vector<int>(2);
        dp[i][0] = MAX_VALUE;
        dp[i][1] = MAX_VALUE;
    }
    
    for(int i = 0, count = links.size(); i < count; ++i)
    {
        int parent = links[i][0] - 1;
        int child = links[i][1] - 1;
        
        if(tree.find(parent) == tree.end())
        {
            tree[parent] = vector<int>();
        }
        
        tree[parent].push_back(child);
    }
    
    int answer = min(SearchMember(0, false), SearchMember(0, true));
    
    return answer;
}