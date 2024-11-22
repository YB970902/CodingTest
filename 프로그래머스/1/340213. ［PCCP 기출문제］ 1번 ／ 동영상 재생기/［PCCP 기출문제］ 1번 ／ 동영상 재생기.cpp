#include <string>
#include <vector>

using namespace std;

int videoTime;
int currentTime;
int opStartTime;
int opEndTime;

int GetTime(const string& str)
{
    int delimiter = str.find(":");
    int minutes = stoi(str.substr(0, delimiter));
    int seconds = stoi(str.substr(delimiter + 1));
    
    return minutes * 60 + seconds;
}

bool CanSkipOpenning(int time)
{
    if(time < opStartTime) return false;
    if(time > opEndTime) return false;
    return true;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    videoTime = GetTime(video_len);
    currentTime = GetTime(pos);
    opStartTime = GetTime(op_start);
    opEndTime = GetTime(op_end);
    
    if(CanSkipOpenning(currentTime)) currentTime = opEndTime;
    
    for(const string& command : commands)
    {
        switch(command[0])
        {
            case 'p':
                currentTime -= 10;
                break;
            case 'n':
                currentTime += 10;
                break;
        }
        
        if(currentTime < 0) currentTime = 0;
        else if(currentTime > videoTime) currentTime = videoTime;
        
        if(CanSkipOpenning(currentTime)) currentTime = opEndTime;
    }
    
    string answer = "";
    int minute = currentTime / 60;
    int second = currentTime % 60;
    if(minute < 10) answer.push_back('0');
    answer += to_string(minute);
    
    answer.push_back(':');
    
    if(second < 10) answer.push_back('0');
    answer += to_string(second);
    return answer;
}