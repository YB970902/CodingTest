#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> nameMap = {
    {"code", 0},
    {"date", 1},
    {"maximum", 2},
    {"remain", 3}
};

int extVal;
int extIndex;
int orderIndex;

bool sortBy(const vector<int>& lhs, const vector<int>& rhs)
{
    return lhs[orderIndex] < rhs[orderIndex];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    
    extIndex = nameMap[ext];
    extVal = val_ext;
    orderIndex = nameMap[sort_by];
    
    vector<vector<int>> answer;
    for(vector<int> d : data)
    {
        if(d[extIndex] < val_ext)
        {
            answer.push_back(d);
        }
    }
    
    sort(answer.begin(), answer.end(), sortBy);
    
    return answer;
}