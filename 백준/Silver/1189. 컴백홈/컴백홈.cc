#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int R, C, K;

bool isVisited[6][6];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int Count;

void dfs(int r, int c, int depth)
{
    if(K == depth && r == 0 && c == C - 1)
    {
        ++Count;
        return;
    }
    
    for(int i = 0; i < 4; ++i)
    {
        int tempR = r + dy[i];
        int tempC = c + dx[i];
        
        if(tempR < 0 || tempR >= R || tempC < 0 || tempC >= C) continue;
        if(isVisited[tempR][tempC]) continue;
        
        isVisited[tempR][tempC] = true;
        dfs(tempR, tempC, depth + 1);
        isVisited[tempR][tempC] = false;
    }
}

int main()
{
    cin >> R >> C >> K;
    
    for(int i = 0; i < R; ++i)
    {
        for(int j = 0; j < C; ++j)
        {
            char temp;
            cin >> temp;
            if(temp == 'T') isVisited[i][j] = true;
        }
    }
    
    Count = 0;
    isVisited[R - 1][0] = true;
    dfs(R - 1, 0, 1);
    
    cout << Count << '\n';
    
    return 0;
}
