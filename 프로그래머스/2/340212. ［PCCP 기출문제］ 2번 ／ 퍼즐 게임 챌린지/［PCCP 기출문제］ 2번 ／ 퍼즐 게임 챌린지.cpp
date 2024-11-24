#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetTime(const vector<int>& diffs, const vector<int>& times, int level, int index)
{
    int diff = diffs[index];
    int prevTime = index == 0 ? 0 : times[index - 1];
    int currTime = times[index];
    
    if(level >= diff) return currTime;
    return (prevTime + currTime) * (diff - level) + currTime;
}

bool CanSolve(const vector<int>& diffs, const vector<int>& times, const long long& limit, int level)
{
    long long time = 0;
    for(int i = 0, size = diffs.size(); i < size; ++i)
    {
        time += GetTime(diffs, times, level, i);
        if(time > limit) return false;
    }
    
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    int minLevel = 1;
    int maxLevel = 1;
    for(int diff : diffs)
    {
        maxLevel = max(diff, maxLevel);
    }
    
    while(minLevel != maxLevel)
    {
        int currLevel = minLevel + (maxLevel - minLevel) / 2;
        
        if(CanSolve(diffs, times, limit, currLevel))
        {
            maxLevel = currLevel;
        }
        else
        {
            minLevel = currLevel;
        }
        
        if(maxLevel - minLevel == 1)
        {
            if(CanSolve(diffs, times, limit, minLevel))
            {
                return minLevel;
            }
            else
            {
                return maxLevel;
            }
        }
    }
    
    return minLevel;
}