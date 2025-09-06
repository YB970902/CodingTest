#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int comp(const vector<int>& lhs, const vector<int>& rhs)
{
    return lhs[1] < rhs[1];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), comp);
    int answer = 0;
    // 발사 지점
    int lastFirePos = -1;
    for(int i = 0, size = targets.size(); i < size; ++i)
    {
        // 발사 지점이 목표 지점의 시작지점보다 작거나 같으면 새로 쏜다.
        if(lastFirePos <= targets[i][0])
        {
            ++answer;
            lastFirePos = targets[i][1];
        }
    }
    
    return answer;
}