#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    // 사람 수
    int n = schedules.size();
    
    // 토요일인 날
    int saturday = 6 - startday;
    // 일요일부터 시작했다면, 토요일은 6이다.
    if(saturday < 0) saturday = 6;
    // 일요일인 날
    int sunday = 7 - startday;
    
    for(int i = 0; i < n; ++i)
    {
        // 정상 출근으로 인정하는 시간
        int maxTime = schedules[i] + 10;
        // 10분을 더했을 때 한 시간이 지났다면 시간에 1을 더한다.
        if (maxTime % 100 >= 60) maxTime += 40;
        // 지각했는지 여부
        bool isLate = false;
        // 일 주일을 계산한다.
        for(int j = 0; j < 7; ++j)
        {
            // 토요일이나 일요일이면 계산하지 않는다.
            if(j == saturday || j == sunday) continue;
            
            // 지각
            if(timelogs[i][j] > maxTime)
            {
                isLate = true;
                break;
            }
        }
        // 지각을 한번도 안했다면 결과에 1을 더한다.
        if(isLate == false) ++answer;
    }
    
    return answer;
}