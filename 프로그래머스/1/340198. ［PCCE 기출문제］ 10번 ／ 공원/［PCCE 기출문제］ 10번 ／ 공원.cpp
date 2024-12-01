#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 방문여부
bool isVisited[50][50] = {{false}};

// 우, 하, 우하 검사용 룩업
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

const string strEmpty = "-1";

int maxR;
int maxC;

int bfs(const vector<vector<string>>& park, int r, int c)
{
    if(park[r][c].compare(strEmpty) != 0) return 0;
    
    queue<pair<int, int>> q;
    // 방문했던 노드를 담는다. 나중에 isVisited 초기화용
    vector<pair<int, int>> vecVisited;
    int level = 0;
    
    q.push(make_pair(r, c));
    isVisited[r][c] = true;
    vecVisited.push_back(make_pair(r, c));
    while(q.size() > 0)
    {
        ++level;
        int size = q.size();
        // 깊이만큼 더하기 위해 레벨별로 구분한다.
        for(int i = 0; i < size; ++i)
        {
            auto& [r, c] = q.front();
            q.pop();
            for(int j = 0; j < 3; ++j)
            {
                int addR = r + dy[j];
                int addC = c + dx[j];
                if(addR >= maxR || addC >= maxC || park[addR][addC].compare(strEmpty) != 0)
                {
                    // 빈자리가 아니거나 맵을 벗어났다면 초기화하고 레벨을 반환한다.
                    for(auto& [tempR, tempC] : vecVisited)
                    {
                        isVisited[tempR][tempC] = false;
                    }
                    return level;
                    break;
                }
                else if(isVisited[addR][addC] == false)
                {
                    isVisited[addR][addC] = true;
                    vecVisited.push_back(make_pair(addR, addC));
                    q.push(make_pair(addR, addC));
                }
            }
        }
    }
    
    return level;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    maxR = park.size();
    maxC = park[0].size();
    
    // 가장 넓은 빈자리
    int maxMatSize = 0;
    
    for(int r = 0; r < maxR; ++r)
    {
        for(int c = 0; c < maxC; ++c)
        {
            maxMatSize = max(maxMatSize, bfs(park, r, c));
        }
    }
    
    int answer = -1;
    for(int mat : mats)
    {
        if(mat <= maxMatSize && mat > answer)
        {
            answer = mat;
        }
    }
    
    return answer;
}