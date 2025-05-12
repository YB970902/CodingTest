#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dungeonSize;

int solution(int k, vector<vector<int>> dungeons) {
    dungeonSize = dungeons.size();
    
    // 인덱스가 담겨있는 벡터.
    vector<int> setIndex = vector<int>(dungeonSize);
    
    // 던전의 인덱스를 집어넣는다.
    for(int i = 0; i < dungeonSize; ++i)
    {
        setIndex[i] = i;
    }
    
    int answer = -1;
    do
    {
        // 모든 경우의 수를 뽑는다
        int currK = k;
        // 던전 클리어 수
        int clearCount = 0;
        for(int i = 0; i < dungeonSize; ++i)
        {
            int dungeonIndex = setIndex[i];
            int needK = dungeons[dungeonIndex][0];
            
            // 피로도가 부족하면 뺀다.
            if(currK < needK) continue;
            
            // 클리어 수 증가
            ++clearCount;
            // 피로도 소모
            currK -= dungeons[dungeonIndex][1];
        }
        
        answer = max(answer, clearCount);
        
        // 최대 개수와 동일하다면 더이상 계산하지 않는다.
        if(answer == dungeonSize) break;
    }
    while(next_permutation(setIndex.begin(), setIndex.end()));
    
    return answer;
}