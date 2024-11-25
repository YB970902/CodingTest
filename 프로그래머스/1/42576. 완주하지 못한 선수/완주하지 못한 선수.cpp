#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> playerList;

string solution(vector<string> participant, vector<string> completion) {
    for(string player : participant)
    {
        if(playerList.find(player) == playerList.end())
        {
            playerList[player] = 1;
        }
        else
        {
            ++playerList[player];
        }
    }
    
    for(string player : completion)
    {
        --playerList[player];
    }
    
    for(string player : participant)
    {
        if(playerList[player] == 1)
        {
            return player;
        }
    }
    
    return "";
}