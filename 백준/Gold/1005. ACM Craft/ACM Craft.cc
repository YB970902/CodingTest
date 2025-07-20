#include <iostream>
#include <vector>

using namespace std;

// 건물을 짓는 시간
vector<int> delay;

// 건물의 연결관계
vector<int> graph[1001];

// DP
int dp[1001];

// 건물 개수, 건설 순서 규칙 수, 목표 값
int N, K, W;

int CalcDP(int index)
{
    // 비어있는 경우, 이전 노드를 가져온다.
    if (dp[index] == -1)
    {
        int maxVal = 0;
        // 이 노드에 도달할 수 있는 모든 노드의 딜레이 시간을 가져온다.
        for (int i = 0, size = graph[index].size(); i < size; ++i)
        {
            maxVal = max(maxVal, CalcDP(graph[index][i]));
        }

        // 그 딜레이 시간에 이 건물을 완성하는데 걸리는 시간을 더한다.
        dp[index] = maxVal + delay[index];
        return dp[index];
    }

    return dp[index];
}

void Test()
{
    cin >> N >> K;

    delay.clear();
    delay.resize(N);

    for (int i = 0; i < N; ++i)
    {
        int time;
        cin >> time;
        delay[i] = time;
        graph[i].clear();
        dp[i] = -1;
    }

    for (int i = 0; i < K; ++i)
    {
        // 시작지 도착지
        int start, end;
        cin >> start >> end;
        // 인덱싱해야하므로 아이디에서 1을 뺀다.
        --start;
        --end;

        // 이 노드에 도달하기 위해 필요한 노드를 넣는다.
        graph[end].push_back(start);
    }

    cin >> W;

    cout << CalcDP(W - 1) << '\n';
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        Test();
    }

    return 0;
}