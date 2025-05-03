#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

int N, M; // 행, 열
char board[50][50]; // 체스판 데이터

int main()
{
    cin >> N >> M;
    
    int minChangedCount = 50 * 50;
    
    for(int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for(int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
        }
    }
    
    for(int row = 0; row <= N - 8; ++row)
    {
        for(int col = 0; col <= M - 8; ++col)
        {
            int blackFirstCount = 0;
            int whiteFirstCount = 0;
            
            for(int i = 0; i < 8; ++i)
            {
                for(int j = 0; j < 8; ++j)
                {
                    char current = board[row + j][col + i];
                    char blackFirst = ((i + j) % 2 == 0) ? 'B' : 'W';
                    char whiteFirst = ((i + j) % 2 == 0) ? 'W' : 'B';
                    
                    if(current != blackFirst) ++blackFirstCount;
                    if(current != whiteFirst) ++whiteFirstCount;
                }
            }
            
            minChangedCount = min(minChangedCount, min(whiteFirstCount, blackFirstCount));
        }
    }
    
    cout << minChangedCount;
    
    return 0;
}
