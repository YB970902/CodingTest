#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 사람 수
int N;
// 관계 수
int M;

// 친구관계 그래프
vector<int> graph[2001];
// 방문 여부
bool visited[2001];

bool dfs(int currIndex, int currDepth)
{
    if (currDepth == 4) return true;

    for (int i = 0, size = graph[currIndex].size(); i< size; ++i)
    {
        int index = graph[currIndex][i];
        if (visited[index]) continue;

        visited[index] = true;
        if (dfs(index, currDepth + 1)) return true;
        visited[index] = false;
    }
    return false;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        graph[i] = vector<int>();
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < N; ++i)
    {
        visited[i] = true;
        if (dfs(i, 0))
        {
            cout << 1;
            return 0;
        }
        visited[i] = false;
    }

    cout << 0;

    return 0;
}