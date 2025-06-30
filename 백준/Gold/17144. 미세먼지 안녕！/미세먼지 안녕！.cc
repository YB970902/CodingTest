#include <iostream>

using namespace std;

// 먼지 상태
int dustInfo[50][50];

// 방의 X크기, Y크기, 시간
int X, Y, T;

// 시계방향 시작 위치
int cwStart[2] = {-1, -1};
// 반시계방향 시작 위치
int ccwStart[2] = {-1, -1};

int lookup[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool IsOutOfRange(int y, int x)
{
    return x < 0 || x >= X || y < 0 || y >= Y || dustInfo[y][x] == -1;
}

// 미세먼지 퍼짐
void Spread()
{
    // 결과를 담을 변수
    int result[50][50] = {0};
    for (int i = 0; i < Y; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            // 현재 먼지
            int currDust = dustInfo[i][j];

            // 공기 청정기는 패스한다.
            if (currDust == -1)
            {
                result[i][j] = -1;
                continue;
            }

            // 퍼트릴 수 있는 먼지
            int spreadDust = currDust / 5;
            // 퍼트릴 수 없다면 넘긴다.
            if (spreadDust <= 0)
            {
                result[i][j] += currDust;
                continue;
            }

            for (int k = 0; k < 4; ++k)
            {
                int y = i + lookup[k][0];
                int x = j + lookup[k][1];
                if (IsOutOfRange(y, x)) continue;
                // 퍼진 먼지를 결과에 담는다.
                result[y][x] += spreadDust;
                // 현재 먼지에서 제거한다.
                currDust -= spreadDust;
            }

            // 퍼지고 남은 먼지를 넣는다.
            result[i][j] += currDust;
        }
    }

    for (int i = 0; i < Y; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            dustInfo[i][j] = result[i][j];
        }
    }
}

// 시계방향
void CW()
{
    int y = cwStart[0];

    // 아래로
    for (int i = y; i < Y - 1; ++i)
    {
        dustInfo[i][0] = dustInfo[i + 1][0];
    }

    // 공기청정기에서 나가는 바람은 먼지가 없으므로 0으로 변경
    dustInfo[y][0] = 0;

    // 오른쪽으로
    for (int i = 0; i < X - 1; ++i)
    {
        dustInfo[Y - 1][i] = dustInfo[Y - 1][i + 1];
    }

    // 위로
    for (int i = Y - 1; i > y; --i)
    {
        dustInfo[i][X - 1] = dustInfo[i - 1][X - 1];
    }

    // 왼쪽으로
    for (int i = X - 1; i > 0; --i)
    {
        dustInfo[y][i] = dustInfo[y][i - 1];
    }

    // 공기청정기 위치를 다시 -1로 변경
    dustInfo[y][0] = -1;
}

// 시계방향
void CCW()
{
    int y = ccwStart[0];

    // 위로
    for (int i = y; i > 0; --i)
    {
        dustInfo[i][0] = dustInfo[i - 1][0];
    }

    // 공기청정기에서 나가는 바람은 먼지가 없으므로 0으로 변경
    dustInfo[y][0] = 0;

    // 오른쪽으로
    for (int i = 0; i < X - 1; ++i)
    {
        dustInfo[0][i] = dustInfo[0][i + 1];
    }

    // 아래로
    for (int i = 0; i < y; ++i)
    {
        dustInfo[i][X - 1] = dustInfo[i + 1][X - 1];
    }

    // 왼쪽으로
    for (int i = X - 1; i > 0; --i)
    {
        dustInfo[y][i] = dustInfo[y][i - 1];
    }

    // 공기청정기 위치를 다시 -1로 변경
    dustInfo[y][0] = -1;
}

// 미세먼지 제거
void Clean()
{
    CW();
    CCW();
}

int main()
{
    cin >> Y >> X >> T;

    for (int i = 0; i < Y; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            cin >> dustInfo[i][j];
            if (dustInfo[i][j] == -1)
            {
                // 반시계방향 입력
                if (ccwStart[0] == -1)
                {
                    ccwStart[0] = i;
                    ccwStart[1] = j;
                }
                else // 시계방향 입력
                {
                    cwStart[0] = i;
                    cwStart[1] = j;
                }
            }
        }
    }

    while (T > 0)
    {
        --T;
        Spread();
        Clean();
    }

    int result = 0;

    for (int i = 0; i < Y; ++i)
    {
        for (int j = 0; j < X; ++j)
        {
            result += dustInfo[i][j] > 0 ? dustInfo[i][j] : 0;
        }
    }

    cout << result;

    return 0;
}