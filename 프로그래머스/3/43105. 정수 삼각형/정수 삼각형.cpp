#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i = 0, count = triangle.size() - 1; i < count; ++i)
    {
        vector<int> currLine = triangle[i];
        vector<int> nextLine = triangle[i + 1];
        for(int j = 0, count = currLine.size(); j < count; ++j)
        {
            nextLine[j] = max(nextLine[j], triangle[i + 1][j] + currLine[j]);
            nextLine[j + 1] = max(nextLine[j + 1], triangle[i + 1][j + 1] + currLine[j]);
        }
        
        triangle[i + 1] = nextLine;
    }
    
    int triangleLastIndex = triangle.size() - 1;
    for(int i = 0, count = triangle[triangleLastIndex].size(); i < count; ++i)
    {
        answer = max(answer, triangle[triangleLastIndex][i]);
    }
    
    return answer;
}