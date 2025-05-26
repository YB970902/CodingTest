#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    // 수업 참여 가능 여부
    bool canStudy[32];

    // 옷을 가지고 있는 사람 리스트
    bool hasClothes[32];
    
    fill(canStudy, canStudy + 32, true);
    fill(hasClothes, hasClothes + 32, false);
    
    for(int i = 0, size = reserve.size(); i < size; ++i)
    {
        hasClothes[reserve[i]] = true;
    }
    
    for(int i = 0, size = lost.size(); i < size; ++i)
    {
        int loster = lost[i];
        
        // 옷을 가지고 있다면 자신의 옷을 입는다.
        if(hasClothes[loster])
        {
            hasClothes[loster] = false;
            ++answer;
            continue;
        }
        
        canStudy[loster] = false;
    }
    
    for(int i = 1; i <= n; ++i)
    {
        // 빌려줄 옷이 없다면 패스
        if(hasClothes[i] == false) continue;
        
        // 한 치수 작은 사람에게 빌려줄 수 있다면 빌려준다.
        if(!canStudy[i - 1])
        {
            hasClothes[i] = false;
            canStudy[i - 1] = true;
            ++answer;
        }
        // 한 치수 큰 사람에게 빌려줄 수 있다면 빌려준다.
        else if(!canStudy[i + 1])
        {
            hasClothes[i] = false;
            canStudy[i + 1] = true;
            ++answer;
        }
    }
    
    return answer;
}