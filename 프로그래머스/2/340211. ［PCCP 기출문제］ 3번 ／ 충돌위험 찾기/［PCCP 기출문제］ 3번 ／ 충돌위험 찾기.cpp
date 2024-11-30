#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 이동 횟수.
// <좌표<이동한 시간대, 이동한 횟수>>
unordered_map<int, unordered_map<int, int>> moveCount;

int GetKey(int r, int c)
{
    return r * 1000 + c;
}

void AddMoveCount(int key, int& sec)
{
    if(moveCount.find(key) == moveCount.end())
    {
        moveCount[key] = unordered_map<int, int>();
        moveCount[key][sec++] = 1;
        return;
    }
    
    if(moveCount[key].find(sec) == moveCount[key].end())
    {
        moveCount[key][sec++] = 1;
        return;
    }
    
    ++moveCount[key][sec++];
}

void Walk(const vector<int>& start, const vector<int>& end, int& sec)
{   
    int startR = start[0];
    int startC = start[1];
    
    int deltaR = end[0] - start[0];
    int deltaC = end[1] - start[1];
    
    if(sec == 0)
    {
        // sec가 0이라면 시작 위치부터 움직임을 시작한다.
        AddMoveCount(GetKey(startR, startC), sec);
    }
    
    if(deltaR > 0)
    {
        for(int r = startR + 1; r <= startR + deltaR; ++r)
        {
            AddMoveCount(GetKey(r, startC), sec);
        }
    }
    else if(deltaR < 0)
    {
        for(int r = startR - 1; r >= startR + deltaR; --r)
        {
            AddMoveCount(GetKey(r, startC), sec);
        }
    }
    
    startR += deltaR;
    
    if(deltaC > 0)
    {
        for(int c = startC + 1; c <= startC + deltaC; ++c)
        {
            AddMoveCount(GetKey(startR, c), sec);
        }
    }
    else if(deltaC < 0)
    {
        for(int c = startC - 1; c >= startC + deltaC; --c)
        {
            AddMoveCount(GetKey(startR, c), sec);
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    
    for(int i = 0, sizeI = routes.size(); i < sizeI; ++i)
    {
        const vector<int>& route = routes[i];
        int sec = 0;
        for(int j = 0, sizeJ = route.size() - 1; j < sizeJ; ++j)
        {
            Walk(points[route[j] - 1], points[route[j + 1] - 1], sec);
        }
    }
    
    int answer = 0;
    
    for(auto& [pos, data] : moveCount)
    {
        for(auto& [time, count] : data)
        {
            if(count >= 2) ++answer;
        }
    }
    
    return answer;
}