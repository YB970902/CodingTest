#include <string>
#include <vector>

using namespace std;

int server[49] = {0};

void AddServer(int index, int k, int count)
{
    for(int i = 0; i < k; ++i)
    {
        server[index + i] += count;
    }
}

int solution(vector<int> players, int m, int k) {
    
    int answer = 0;
    
    for(int i = 0; i < 24; ++i)
    {
        // 현 시간대의 서버 수
        int player = players[i];
        // 현 시간대에 운영되어야 하는 서버의 수
        int serverCount = player / m;
        // 운영되어야 하는 서버보다 실제 서버가 더 작게 돌아가고 있다면, 증설한다.
        if(serverCount > server[i])
        {
            // 증설되어야 하는 서버의 수
            int count = serverCount - server[i];
            // 결과에 더한다.
            answer += count;
            AddServer(i, k, count);
        }
    }
    return answer;
}