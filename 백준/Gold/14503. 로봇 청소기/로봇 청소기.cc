#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

int N, M; // 행, 열

int field[50][50]; // 청소할 영역 필드

int robotRow, robotCol; // 로봇이 위치한 행 열
int robotDir; // 로봇이 바라보는 방향. 북 : 0, 동 : 1, 남 : 2, 서 : 3

int lookUpRow[4] = {-1, 0, 1, 0}; // 행의 룩업테이블
int lookUpCol[4] = {0, 1, 0, -1}; // 열의 룩업테이블

const int IsDirty = 0;
const int IsWall = 1;
const int IsClean = 2;

// 현재 위치가 더러운지 여부
bool IsCurrentFieldDirty()
{
    return field[robotRow][robotCol] == IsDirty;
}

// 로봇 청소기 근처에 더러운 영역이 있는지 여부
bool IsDirtyFieldNearByRobot()
{
    for(int i = 0; i < 4; ++i)
    {
        if(field[lookUpRow[i] + robotRow][lookUpCol[i] + robotCol] == IsDirty) return true;
    }
    
    return false;
}

// 반시계 방향으로 회전한다.
void RotateCCW()
{
    robotDir = --robotDir;
    if(robotDir == -1) robotDir = 3;
}

// 앞으로 전진한다.
void MoveForward()
{
    robotRow += lookUpRow[robotDir];
    robotCol += lookUpCol[robotDir];
}

bool IsForwardFieldDirty()
{
    return field[lookUpRow[robotDir] + robotRow][lookUpCol[robotDir] + robotCol] == IsDirty;
}

// 뒤로 이동 가능 여부
bool CanMoveBack()
{
    return field[robotRow - lookUpRow[robotDir]][robotCol - lookUpCol[robotDir]] != IsWall;
}

// 뒤로 이동한다.
void MoveBack()
{
    robotRow -= lookUpRow[robotDir];
    robotCol -= lookUpCol[robotDir];
}

int main()
{
    cin >> N >> M;
    
    cin >> robotRow >> robotCol >> robotDir;
    
    // 1부터 시작한다.
    for(int row = 0; row < N; ++row)
    {
        for(int col = 0; col < M; ++col)
        {
            // 값을 넣는다. 0 : 청소되지 않음, 1 : 벽, 2 : 청소됨
            cin >> field[row][col];
        }
    }
    
    int cleanCount = 0;
    
    while(true)
    {
        // 현재 칸이 더럽다면 청소한다.
        if(IsCurrentFieldDirty())
        {
            field[robotRow][robotCol] = IsClean;
            ++cleanCount;
        }
        // 주변에 더러운 영역이 없다면 뒤로 이동한다.
        else if(IsDirtyFieldNearByRobot() == false)
        {
            if(CanMoveBack())
            {
                // 뒤로 이동 가능하다면 이동
                MoveBack();
            }
            else
            {
                // 뒤로 이동이 불가능하다면 작동 정지
                break;
            }
        }
        // 주변에 더러운 칸이 있다면 반시계 방향으로 회전한다.
        else
        {
            // 더러운 영역이 앞에 있을때까지 회전한다.
            for(int i = 0; i < 4; ++i)
            {
                RotateCCW();
                
                // 지금 앞칸이 더럽다면 앞으로 이동한다.
                if(IsForwardFieldDirty())
                {
                    MoveForward();
                    break;
                }
            }
        }
    }
    
    cout << cleanCount;
    
    return 0;
}
