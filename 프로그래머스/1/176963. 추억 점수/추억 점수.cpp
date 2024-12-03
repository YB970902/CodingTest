#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> score;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    for(int i = 0, size = name.size(); i < size; ++i)
    {
        score[name[i]] = yearning[i];
    }
    
    vector<int> result = vector<int>(photo.size());
    
    for(int i = 0, size = photo.size(); i < size; ++i)
    {
        for(const string& str : photo[i])
        {
            if(score.find(str) != score.end()) result[i] += score[str];
        }
    }
    
    return result;
}