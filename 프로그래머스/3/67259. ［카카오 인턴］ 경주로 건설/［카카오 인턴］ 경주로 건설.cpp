#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Tile
{
    int x;
    int y;
    int cost;
    int dir;
};

int solution(vector<vector<int>> board) {
    int N = board.size();
    // 방향별 비용
    vector<vector<vector<int>>> cost =
        vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(4, 1e9)));
    
    queue<Tile> que;
    
    // 시작지에서 모든 경로를 다 추가한다.
    for(int i = 0; i < 4; ++i)
    {
        cost[0][0][i] = 0;
        que.push({0, 0, 0, i});
    }
    
    while(!que.empty())
    {
        Tile tile = que.front();
        que.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int x = tile.x + dx[i];
            int y = tile.y + dy[i];
            
            // 범위를 벗어남
            if(x < 0 || x >= N || y < 0 || y >= N) continue;
            // 벽
            if(board[x][y] == 1) continue;
            
            // 현재 비용
            int curCost = tile.cost + ((tile.dir == i) ? 100 : 600);
            
            // 기존 비용보다 더 작은 값이라면, 새롭게 탐색한다.
            if(curCost < cost[x][y][i])
            {
                cost[x][y][i] = curCost;
                que.push({x, y, curCost, i});
            }
        }
    }
    
    int minVal = 1e9;
    
    for(int i = 0; i < 4; ++i)
    {
        minVal = min(minVal, cost[N - 1][N - 1][i]);
    }
    
    return minVal;
}