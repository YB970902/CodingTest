#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

// N, 4열 -> 여기에 가장 점수가 높은 땅의 인덱스를 넣는다.
int arr[100000][4];

int landSize;

void go(const vector<vector<int>>& land, int n)
{   
    // 끝에 다다름.
    if(n == 0)
    {
        int maxValue = 0;
        for(int i = 0; i < 4; ++i)
        {
            arr[n][i] = land[n][i];
            maxValue = arr[n][i];
        }
        
        return;
    }
    
    go(land, n - 1);
    
    int maxValue = 0;
    
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(i == j) continue;
            
            arr[n][i] = max(arr[n][i], arr[n - 1][j] + land[n][i]);
        }
    }
}

int solution(vector<vector<int>> land)
{
    landSize = land.size();
    // -1으로 초기화
    memset(arr, -1, sizeof(arr));
    
    go(land, landSize - 1);
    
    int answer = 0;
    for(int i = 0; i < 4; ++i)
    {
        answer = max(answer, arr[landSize - 1][i]);
    }

    return answer;
}