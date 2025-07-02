#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 나라 정보
int Arr[50][50];

// 인접 리스트
vector<int> Adj[50][50];

bool visited[50][50];

int N, L, R;

int Lookup[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

// 해당 위치의 차이. 만약 범위를 벗어났다면 0 반환
// 현재 인구, x, y
int GetGap(int currCount, int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N) return 0;

    return abs(Arr[x][y] - currCount);
}

// 국경을 연다. 연 국경이 있는지 여부 반환
bool OpenEdge()
{
    bool isOpenEdge = false;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            Adj[i][j].clear();
            visited[i][j] = false;
            int currCount = Arr[i][j];

            for (int k = 0; k < 4; ++k)
            {
                int x = i + Lookup[k][0];
                int y = j + Lookup[k][1];
                int gap = GetGap(currCount, x, y);
                if (gap >= L && gap <= R)
                {
                    Adj[i][j].push_back(k);
                    isOpenEdge = true;
                }
            }
        }
    }

    return isOpenEdge;
}

// 땅 수, 사람 수 구하기
void GetGroundPeopleCount(int x, int y, int& groundCount, int& peopleCount)
{
    visited[x][y] = true;
    for (int i = 0, size = Adj[x][y].size(); i < size; ++i)
    {
        int k = Adj[x][y][i];
        int curX = x + Lookup[k][0];
        int curY = y + Lookup[k][1];

        if (visited[curX][curY]) continue;

        // 땅 개수
        ++groundCount;
        // 사람 수
        peopleCount += Arr[curX][curY];

        GetGroundPeopleCount(curX, curY, groundCount, peopleCount);
    }
}

// 경로를 지워가며 사람 수를 맞춘다.
void SetPeopleCount(int x, int y, int count)
{
    Arr[x][y] = count;
    vector<int> vec = vector<int>(Adj[x][y]);
    Adj[x][y].clear();
    for (int i = 0, size = vec.size(); i < size; ++i)
    {
        int k = vec[i];
        int curX = x + Lookup[k][0];
        int curY = y + Lookup[k][1];

        // 경로가 없다면 패스
        if (Adj[curX][curY].size() == 0) continue;

        SetPeopleCount(curX, curY, count);
    }
}

// 국경 계산
void CalcEdge()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // 방문한 적이 있음.
            if (visited[i][j]) continue;
            // 열린 국경이 없음.
            if (Adj[i][j].size() == 0) continue;

            int groundCount = 1;
            int peopleCount = Arr[i][j];
            // 땅, 사람 수 계산
            GetGroundPeopleCount(i, j, groundCount, peopleCount);

            SetPeopleCount(i, j, peopleCount / groundCount);
        }
    }
}

int main()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Arr[i][j];
        }
    }

    // 국경이 열린날이 없을때까지 연다.
    int result = 0;
    while (OpenEdge())
    {
        ++result;
        CalcEdge();
    }

    cout << result;

    return 0;
}