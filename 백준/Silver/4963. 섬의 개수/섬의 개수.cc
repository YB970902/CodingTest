#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <string>

using namespace std;

int R, C, Count;

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

int isVisited[50][50] = {{0}};

void bfs(int r, int c)
{
    if(isVisited[r][c]) return;
    isVisited[r][c] = true;
    
    ++Count;
    
    queue<pair<int, int>> q;
    
    q.push(make_pair(r, c));
    
    while(q.size() > 0)
    {
        auto [curR, curC] = q.front();
        q.pop();
        
        for(int i = 0; i < 8; ++i)
        {
            int tr = curR + dy[i];
            int tc = curC + dx[i];
            
            if(tr < 0 || tc < 0 || tr >= R || tc >= C) continue;
            if(isVisited[tr][tc]) continue;
            
            isVisited[tr][tc] = true;
            q.push(make_pair(tr, tc));
        }
    }
}

int main()
{
    while(true)
    {
        cin >> C >> R;
        
        if(R == 0 && C == 0) break;
        
        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                cin >> isVisited[i][j];
                isVisited[i][j] = !isVisited[i][j];
            }
        }
        
        Count = 0;
        
        for(int i = 0; i < R; ++i)
        {
            for(int j = 0; j < C; ++j)
            {
                bfs(i, j);
            }
        }
        
        memset(isVisited, 0, sizeof(bool) * 50 * 50);
        
        cout << Count << '\n';
        
    }
    
    return 0;
}
