#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortInfo(const vector<int>& lhs, const vector<int>& rhs)
{
    if(lhs[0] - lhs[1] == rhs[0] - rhs[1])
        return lhs[0] / lhs[1] > rhs[0] / rhs[1];
    return lhs[0] - lhs[1] > rhs[0] - rhs[1];
}

int solution(vector<vector<int>> info, int n, int m) {
    sort(info.begin(), info.end(), sortInfo);
    
    int size = info.size();
    int traceA = 0;
    int traceB = 0;
    
    for(int i = 0; i < size; ++i)
    {
        int lhs = info[i][0];
        int rhs = info[i][1];
        if(traceB + rhs < m)
            traceB += rhs;
        else if(traceA + lhs < n)
            traceA += lhs;
        else return -1;
    }
    
    return traceA;
}