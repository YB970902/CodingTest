#include <string>
#include <vector>

using namespace std;

// 시간을 초로 변환한다.
int TotalSeconds(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

// 현재 시간에서의 초 각도
int SecondAngle(int time)
{
    return time * 720 % 43200;
}

// 현재 시간에서의 분 각도
int MinuteAngle(int time)
{
    return time * 12 % 43200;
}

// 현재 시간에서의 시 각도
int HourAngle(int time)
{
    return time % 43200;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    // 시간을 초로 변환한다.
    int startTime = TotalSeconds(h1, m1, s1);
    int endTime = TotalSeconds(h2, m2, s2);
    
    // 0시 0분이나 12시 0분이면 처음부터 겹쳐있으므로 1을 더한다.
    if(startTime == 0 || startTime == 43200) ++answer;
    
    // 시작 시간부터 끝 시간까지 검사
    for(int time = startTime; time < endTime; ++time)
    {
        int beforeH = HourAngle(time);
        int beforeM = MinuteAngle(time);
        int beforeS = SecondAngle(time);
        int afterH = HourAngle(time + 1);
        int afterM = MinuteAngle(time + 1);
        int afterS = SecondAngle(time + 1);
        
        // 이후 각도가 0이면 강제로 43200으로 보정한다.
        if(afterH == 0) afterH = 43200;
        if(afterM == 0) afterM = 43200;
        if(afterS == 0) afterS = 43200;
        
        // 분침을 넘겼는지
        bool isPassM = (beforeS < beforeM && afterS >= afterM);
        // 시침을 넘겼는지
        bool isPassH = (beforeS < beforeH && afterS >= afterH);
        
        if(isPassM) ++answer;
        if(isPassH) ++answer;
        
        if(isPassM && isPassH && afterM == afterH) --answer;
    }
    
    return answer;
}