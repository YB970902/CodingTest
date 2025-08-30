#include <string>
#include <vector>

using namespace std;

bool check(const vector<int>& result, const vector<vector<int>>& q, const vector<int>& ans)
{
    for(int i = 0, size = q.size(); i < size; ++i)
    {
        int answer = 0;
        for(int j = 0; j < 5; ++j)
        {
            for(int k = 0; k < 5; ++k)
            {
                if(q[i][j] == result[k])
                {
                    ++answer;
                    break;
                }
            }
        }
        if(ans[i] != answer) return false;
    }
    
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> result = vector<int>(5, 0);
    for(int i1 = 1; i1 <= n - 4; ++i1)
    {
        for(int i2 = i1 + 1; i2 <= n - 3; ++i2)
        {
            for(int i3 = i2 + 1; i3 <= n - 2; ++i3)
            {
                for(int i4 = i3 + 1; i4 <= n - 1; ++i4)
                {
                    for(int i5 = i4 + 1; i5 <= n; ++i5)
                    {
                        result[0] = i1;
                        result[1] = i2;
                        result[2] = i3;
                        result[3] = i4;
                        result[4] = i5;
                        
                        if(check(result, q, ans)) ++answer;
                    }
                }
            }
        }
    }
    return answer;
}