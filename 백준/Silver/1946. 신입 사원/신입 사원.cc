#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 테스트 케이스, 면접자 수
int T, N;
// 성적
vector<pair<int, int>> vec;

int main()
{
    cin >> T;
    
    for(int i = 0; i < T; ++i)
    {
        // 신입사원 수
        int result = 0;
        
        cin >> N;
        
        // 면접자 수 만큼 미리 설정
        vec = vector<pair<int, int>>(N);
        
        for(int j = 0; j < N; ++j)
        {
            // 서류, 면접 성적
            pair<int, int>& p = vec[j];
            cin >> p.first >> p.second;
        }
        
        // 서류 성적순으로 오름차순 정렬
        sort(vec.begin(), vec.end());
        
        // 면접 성적 최소 순위.
        int minRank = 1e9;
        
        for(int j = 0; j < N; ++j)
        {
            if(vec[j].second < minRank)
            {
                // 자신의 면접 순위가 최소 면접 순위보다 높다면, 갱신한다.
                ++result;
                minRank = vec[j].second;
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}
