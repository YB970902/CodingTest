#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> name2score;
unordered_map<int, string> score2name;

vector<string> solution(vector<string> players, vector<string> callings) {
    for(int i = 0, size = players.size(); i < size; ++i)
    {
        name2score[players[i]] = i;
        score2name[i] = players[i];
    }
    
    for(string call : callings)
    {
        int callScore = name2score[call];
        int forwardScore = callScore - 1;
        string forwardName = score2name[forwardScore];
        
        name2score[call] = forwardScore;
        ++name2score[forwardName];
        
        score2name[forwardScore] = call;
        score2name[callScore] = forwardName;
    }
    
    vector<string> answer;
    
    for(int i = 0, size = players.size(); i < size; ++i)
    {
        answer.emplace_back(score2name[i]);
    }
    
    return answer;
}