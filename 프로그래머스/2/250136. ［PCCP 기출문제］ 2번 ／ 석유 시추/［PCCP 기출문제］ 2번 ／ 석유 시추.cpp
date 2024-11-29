#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isVisited[500][500] { false };


int maxR;
int maxC;

int result;
int minX;
int maxX;

int landSum[500] = {0};

void dfs(const vector<vector<int>>& vec, int r, int c)
{
    if(isVisited[r][c]) return;
    
    if(r < 0 || c < 0 || r >= maxR || c >= maxC) return;
    
    if(vec[r][c] == 0) return;
    
    isVisited[r][c] = true;
    ++result;
    
    if(c < minX) minX = c;
    if(c > maxX) maxX = c;
    
    for(int i = 0; i < 4; ++i)
    {
        dfs(vec, r + dx[i], c + dy[i]);
    }
}

int solution(vector<vector<int>> land) {
    maxR = land.size();
    maxC = land[0].size();
    
    for(int r = 0; r < maxR; ++r)
    {
        for(int c = 0; c < maxC; ++c)
        {
            if(isVisited[r][c]) continue;
            
            result = 0;
            minX = 500;
            maxX = 0;
            dfs(land, r, c);
            
            if(result > 0)
            {
                for(int i = minX; i <= maxX; ++i)
                {
                    landSum[i] += result;
                }
            }
        }
    }
    
    int maxValue = 0;
    int maxIndex = 0;
    for(int i = 0; i < maxC; ++i)
    {
        if(landSum[i] > maxValue)
        {
            maxValue = landSum[i];
            maxIndex = i;
        }
    }
    
    return maxValue;
}