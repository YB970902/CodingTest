#include <iostream>
#include <cstring>

using namespace std;

int N, M;

char Board[50][50];

int main()
{
    cin >> N >> M;

    for (int row = 0; row < N; ++row)
    {
        string temp;
        cin >> temp;

        for (int col = 0; col < M; ++col)
        {
            Board[row][col] = temp[col];
        }
    }

    // 결과
    int result = 65;

    for (int row = 0; row <= N - 8; ++row)
    {
        for (int col = 0; col <= M - 8; ++col)
        {
            int blackFirstPaintCount = 0;
            int whiteFirstPaintCount = 0;
            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    char ch = Board[row + i][col + j];
                    char chBlackFirst = (i + j) % 2 == 0 ? 'B' : 'W';

                    if (ch != chBlackFirst) ++blackFirstPaintCount;
                    else ++whiteFirstPaintCount;
                }
            }

            result = min(result, min(blackFirstPaintCount, whiteFirstPaintCount));
        }
    }

    cout << result;

    return 0;
}