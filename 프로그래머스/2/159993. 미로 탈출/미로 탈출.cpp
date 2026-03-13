#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int r, c;

bool visited[100][100];

pair<int, int> GetPosition(vector<string>& maps, char target)
{
    for(int i = 0; i <r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            if(maps[i][j] == target) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int GetDistance(vector<string>& maps, char start, char end)
{
    // 방문정보 초기화
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            visited[i][j] = false;
        }
    }
    
    queue<pair<int, int>> que;
    que.push(GetPosition(maps, start));
    
    int queSize = que.size();
    int step = 1;
    while(queSize > 0)
    {
        for(int i = 0; i < queSize; ++i)
        {
            pair<int, int> rc = que.front();
            que.pop();
            
            for(int j = 0; j < 4; ++j)
            {
                int cy = rc.first + dy[j];
                int cx = rc.second + dx[j];
                
                // 범위 벗어남
                if(cy < 0 || cy >= r || cx < 0 || cx >= c) continue;
                // 벽
                if(maps[cy][cx] == 'X') continue;
                if(visited[cy][cx]) continue;
                
                if(maps[cy][cx] == end) return step;
                
                visited[cy][cx] = true;
                que.push(make_pair(cy, cx));
            }
        }
        
        ++step;
        queSize = que.size();
    }
    
    return -1;
}

int solution(vector<string> maps) {
    r = maps.size();
    c = maps[0].size();
    
    int answer = 0;
    int dist = GetDistance(maps, 'S', 'L');
    if(dist == -1) return -1;
    answer += dist;
    dist = GetDistance(maps, 'L', 'E');
    if(dist == -1) return -1;
    answer += dist;
    return answer;
}