#include <string>
#include <vector>
#include <queue>

using namespace std;
int n, m;
vector<vector<int>> lookup = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

const char Empty = ' ';

vector<vector<bool>> visited;

// 범위를 벗어났는지
bool IsOutOfRange(int i, int j)
{
    return i < 0 || i >= n || j < 0 || j >= m;
}

void bfs(vector<string>& storage, char ch)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            visited[i][j] = false;
        }
    }
    
    queue<pair<int, int>> que;
    
    for(int i = 0; i < n; ++i)
    {
        que.push(make_pair(i, 0));
        que.push(make_pair(i, m - 1));
    }
    
    for(int i = 0; i < m; ++i)
    {
        que.push(make_pair(0, i));
        que.push(make_pair(n - 1, i));
    }
    
    while(!que.empty())
    {
        const pair<int, int> curr = que.front();
        que.pop();
        
        // 방문했다면 뺀다.
        if(visited[curr.first][curr.second]) continue;
        // 방문 체크
        visited[curr.first][curr.second] = true;
        
        // 빈 공간이라면, 주변을 탐색한다.
        if(storage[curr.first][curr.second] == Empty)
        {
            for(int i = 0; i < 4; ++i)
            {
                int x = curr.first + lookup[i][0];
                int y = curr.second + lookup[i][1];
                
                // 범위를 벗어났다면, 넘어간다.
                if(IsOutOfRange(x, y)) continue;
                // 방문했다면 넘어간다.
                if(visited[x][y]) continue;
                // 큐에 추가
                que.push(make_pair(x, y));
            }
        }
        // 찾아야 하는 값이라면, 지운다.
        else if(storage[curr.first][curr.second] == ch)
        {
            storage[curr.first][curr.second] = Empty;
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    
    for(int i = 0, size = requests.size(); i < size; ++i)
    {
        char ch = requests[i][0];
        if(requests[i].size() == 1)
        {
            // 테두리부터 하나하나 찾는다.
            bfs(storage, ch);
        }
        else
        {
            // 그냥 다 뺀다.
            for(int j = 0; j < n; ++j)
            {
                for(int k = 0; k < m; ++k)
                {
                    // 빈건 넘어간다.
                    if(storage[j][k] == Empty) continue;
                    // 찾았다면 비운다.
                    if(storage[j][k] == ch) storage[j][k] = Empty;
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(storage[i][j] != Empty) ++answer;
        }
    }
    
    return answer;
}