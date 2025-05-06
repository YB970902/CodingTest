#include <iostream>
#include <vector>
#include <memory.h>
#include <cstring>

using namespace std;

bool arrPossible[1000]; // 세 자리 수일 가능성이 있는 값.

int N; // 입력받을 값의 개수

int main()
{
    memset(arrPossible, true, sizeof(arrPossible));
    
    for(int i = 123; i <= 999; ++i)
    {
        // 연산을 쉽게하기 위해 문자열로 바꾼다.
        string num = to_string(i);
        // 수가 겹칠수는 없으므로, 겹친다면 가능성이 없다고 판단한다.
        if(num[0] == num[1] || num[1] == num[2] || num[0] == num[2])
        {
            arrPossible[i] = false;
            continue;
        }
        // 0이 들어갈 수 없으므로, 들어간다면 가능성이 없다고 판단한다.
        if(num[0] == '0' || num[1] == '0' || num[2] == '0')
        {
            arrPossible[i] = false;
            continue;
        }
    }
    
    cin >> N;
    for(int count = 0; count < N; ++count)
    {
        int number, strike, ball; // 숫자와 스트라이크 볼 개수
        cin >> number >> strike >> ball;
        for(int i = 123; i <= 999; ++i)
        {
            // 가능성이 없는 수라면 계산하지 않는다.
            if(arrPossible[i] == false) continue;
            
            string num = to_string(number); // 비교해야 하는 숫자
            string curr = to_string(i); // 현재 숫자
            
            int currStrike = 0; // 현재 숫자가 맞다고 가정했을 때의 스트라이크 수
            int currBall = 0; // 현재 숫자가 맞다고 가정했을 때의 볼 수
            
            if(num[0] == curr[0]) ++currStrike;
            if(num[1] == curr[1]) ++currStrike;
            if(num[2] == curr[2]) ++currStrike;
            
            if(curr[0] == num[1]) ++currBall;
            if(curr[0] == num[2]) ++currBall;
            if(curr[1] == num[0]) ++currBall;
            if(curr[1] == num[2]) ++currBall;
            if(curr[2] == num[0]) ++currBall;
            if(curr[2] == num[1]) ++currBall;
            
            // 만약 현재 숫자가 맞다고 가정했을때의 수와 실제 수가 다르다면, 현재 숫자는 가능성이 없다.
            if(currStrike != strike || currBall != ball) arrPossible[i] = false;
        }
    }
    
    // 가능성이 있는 숫자의 개수
    int possibleNum = 0;
    
    for(int i = 123; i <= 999; ++i)
    {
        if(arrPossible[i]) ++possibleNum;
    }
    
    cout << possibleNum;
    
    return 0;
}
