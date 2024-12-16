#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> dir;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int currR;
int currC;

int maxR;
int maxC;

bool IsOutOfMap(char op, int dist)
{
    int dirC = dx[dir[op]];
    int dirR = dy[dir[op]];
    
    int tempR = currR + dirR * dist;
    int tempC = currC + dirC * dist;
    
    return tempR < 0 || tempC < 0 || tempR >= maxR || tempC >= maxC;
}

void SetStartPoint(const vector<string>& park)
{
    for(int r = 0; r < maxR; ++r)
    {
        for(int c = 0; c < maxC; ++c)
        {
            if(park[r][c] == 'S')
            {
                currR = r;
                currC = c;
                return;
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    dir['N'] = 2;
    dir['S'] = 3;
    dir['W'] = 0;
    dir['E'] = 1;
    
    maxR = park.size();
    maxC = park[0].size();
    
    SetStartPoint(park);
    
    for(const string& route : routes)
    {
        char op = route[0];
        int dist = stoi(route.substr(2));
        
        if(IsOutOfMap(op, dist)) continue;
        
        int dirR = dy[dir[op]];
        int dirC = dx[dir[op]];
        
        bool isBlocked = false;
        for(int i = 1; i <= dist; ++i)
        {
            if(park[currR + dirR * i][currC + dirC * i] == 'X')
            {
                isBlocked = true;
                break;
            }
        }
        
        if(isBlocked) continue;
        
        currR += dirR * dist;
        currC += dirC * dist;
    }
    
    answer.push_back(currR);
    answer.push_back(currC);
    
    return answer;
}