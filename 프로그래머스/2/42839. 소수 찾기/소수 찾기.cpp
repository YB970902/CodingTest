#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>

using namespace std;

// 소수를 보관하기 위한 수
bool arrPrime[10000000];
// 만들 수 있는 최대 값
int maxVal;

// 모든 경우의 수를 뽑기 위한 벡터. dfs를 사용한다.
vector<bool> visited;

string strNumber;

void dfs(string current, set<int>& result)
{
    if(!current.empty())
    {
        result.insert(stoi(current));
    }
    
    for(int i = 0; i < strNumber.size(); ++i)
    {
        if(visited[i]) continue;
        
        // 중복 숫자 방지
        if(i > 0 && strNumber[i] == strNumber[i - 1] && !visited[i - 1]) continue;
        
        visited[i] = true;
        dfs(current + strNumber[i], result);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    strNumber = numbers;
    
    visited = vector<bool>(numbers.size(), false);
    
    // 내림차순 정렬. 가장 큰 값이 된다.
    sort(numbers.begin(), numbers.end(), greater<char>());
    
    maxVal = stoi(numbers);
    
    // 소수를 DP로 구한다.
    fill(arrPrime, arrPrime + maxVal + 1, true);
    arrPrime[0] = false;
    arrPrime[1] = false;
    
    for(int i = 2; i <= maxVal; ++i)
    {
        if(arrPrime[i])
        {
            for(int j = 2; i * j <= maxVal; ++j)
            {
                arrPrime[i * j] = false;
            }
        }
    }
    
    // 모든 경우의 수를 계산하기 위한 벡터
    
    set<int> dfsResult = set<int>();
    dfs("", dfsResult);
    
    for(int num : dfsResult)
    {
        if(arrPrime[num]) ++answer;
    }
    
    return answer;
}