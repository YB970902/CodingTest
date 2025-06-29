#include <iostream>

using namespace std;

// 맵 정보 0 : 맨땅 1 : 뱀 2 : 사과, 3 : 벽
int mapInfo[102][102];

const int Ground = 0;
const int Snake = 1;
const int Apple = 2;
const int Wall = 3;

// 위 오른쪽 아래 왼쪽
int lookup[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0}};

// 머리 방향
int headDir = 1;
int tailDir = 1;

// 턴 총 길이
const int turnLen = 10001;
// 각 턴마다 하는 행동. 0 : 아무것도 안함, 1 : 우회전, -1 : 좌회전
int turn[turnLen];
int turnSize = 0;

// 머리 시간
int headTick = 0;
// 꼬리 시간
int tailTick = 0;

// 머리 위치
int head[2];
// 꼬리 위치
int tail[2];

// 맵 크기
int N;

void Simulate()
{
    while (true)
    {
        // 머리의 시간이 흐른다.
        ++headTick;

        // 머리가 이동한다.
        head[0] += lookup[headDir][0];
        head[1] += lookup[headDir][1];

        switch (mapInfo[head[0]][head[1]])
        {
            // 뱀의 머리가 맨땅에 도달한경우
            case Ground:
                ++tailTick;
                // 꼬리가 있던 위치는 땅이 된다.
                mapInfo[tail[0]][tail[1]] = Ground;
                // 꼬리가 움직인다.
                tail[0] += lookup[tailDir][0];
                tail[1] += lookup[tailDir][1];
                // 꼬리가 회전한다.
                if (tailTick < turnLen)
                {
                    tailDir += turn[tailTick];
                    if (tailDir < 0) tailDir = 3;
                    else tailDir %= 4;
                }
                break;
                // 뱀의 머리가 뱀이나 벽에 도달한경우. 게임을 끝낸다.
            case Snake:
            case Wall:
                return;
        }

        // 머리가 있는 위치가 뱀이 된다.
        mapInfo[head[0]][head[1]] = Snake;

        // 머리가 회전한다.
        if (headTick < turnLen)
        {
            headDir += turn[headTick];
            if (headDir < 0) headDir = 3;
            else headDir %= 4;
        }
    }
}

int main()
{
    int K;
    cin >> N >> K;

    // 벽 테두리 치기
    for (int i = 0; i < N + 2; ++i)
    {
        mapInfo[0][i] = Wall;
        mapInfo[N + 1][i] = Wall;
        mapInfo[i][0] = Wall;
        mapInfo[i][N + 1] = Wall;
    }

    for (int i = 0; i < K; ++i)
    {
        int row, col;
        cin >> row >> col;
        mapInfo[col][row] = Apple;
    }

    int L;
    cin >> L;

    for (int i = 0; i < L; ++i)
    {
        int t;
        char dir;
        cin >> t >> dir;
        turn[t] = dir == 'D' ? 1 : -1;
    }

    // 왼쪽위에 뱀 위치
    mapInfo[1][1] = Snake;
    head[0] = 1;
    head[1] = 1;
    tail[0] = 1;
    tail[1] = 1;

    Simulate();

    cout << headTick;

    return 0;
}