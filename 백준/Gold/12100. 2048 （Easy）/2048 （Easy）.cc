#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 판의 크기
int N;

// 판
vector<vector<int>> Board;

int GetMaxValue(const vector<vector<int>>& board)
{
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            result = max(result, board[i][j]);
        }
    }

    return result;
}

vector<vector<int>> MoveLeft(vector<vector<int>> board)
{
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            for (int nx = x + 1; nx < N; ++nx)
            {
                // 0이면 다음 것을 탐색한다.
                if (board[y][nx] == 0) continue;

                // 0이 아닐때 다음것과 합칠 수 있으면 합친다.
                if (board[y][x] == board[y][nx])
                {
                    board[y][x] *= 2;
                    board[y][nx] = 0;
                }
                else
                {
                    if (board[y][x] == 0)
                    {
                        // 현재 위치가 비어있으면 현재 위치로 옮긴다.
                        board[y][x] = board[y][nx];
                        board[y][nx] = 0;
                        // 다음 nx를 탐색한다.
                        continue;
                    }
                    else
                    {
                        // 현재 위치에 값이 있으면 다음 위치로 옮긴다.
                        int temp = board[y][nx];
                        board[y][nx] = 0;
                        board[y][x + 1] = temp;
                    }
                }
                break;
            }
        }
    }

    return board;
}

vector<vector<int>> MoveRight(vector<vector<int>> board)
{
    for (int y = 0; y < N; ++y)
    {
        for (int x = N - 1; x >= 0; --x)
        {
            for (int nx = x - 1; nx >= 0; --nx)
            {
                // 0이면 다음 것을 탐색한다.
                if (board[y][nx] == 0) continue;

                // 0이 아닐때 다음것과 합칠 수 있으면 합친다.
                if (board[y][x] == board[y][nx])
                {
                    board[y][x] *= 2;
                    board[y][nx] = 0;
                }
                else
                {
                    if (board[y][x] == 0)
                    {
                        // 현재 위치가 비어있으면 현재 위치로 옮긴다.
                        board[y][x] = board[y][nx];
                        board[y][nx] = 0;
                        // 다음 nx를 탐색한다.
                        continue;
                    }
                    else
                    {
                        // 현재 위치에 값이 있으면 다음 위치로 옮긴다.
                        int temp = board[y][nx];
                        board[y][nx] = 0;
                        board[y][x - 1] = temp;
                    }
                }
                break;
            }
        }
    }

    return board;
}

vector<vector<int>> MoveUp(vector<vector<int>> board)
{
    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < N; ++y)
        {
            for (int ny = y + 1; ny < N; ++ny)
            {
                // 0이면 다음 것을 탐색한다.
                if (board[ny][x] == 0) continue;

                // 0이 아닐때 다음것과 합칠 수 있으면 합친다.
                if (board[y][x] == board[ny][x])
                {
                    board[y][x] *= 2;
                    board[ny][x] = 0;
                }
                else
                {
                    if (board[y][x] == 0)
                    {
                        // 현재 위치가 비어있으면 현재 위치로 옮긴다.
                        board[y][x] = board[ny][x];
                        board[ny][x] = 0;
                        // 다음 ny를 탐색한다.
                        continue;
                    }
                    else
                    {
                        // 현재 위치에 값이 있으면 다음 위치로 옮긴다.
                        int temp = board[ny][x];
                        board[ny][x] = 0;
                        board[y + 1][x] = temp;
                    }
                }
                break;
            }
        }
    }

    return board;
}

vector<vector<int>> MoveDown(vector<vector<int>> board)
{
    for (int x = 0; x < N; ++x)
    {
        for (int y = N - 1; y >= 0; --y)
        {
            for (int ny = y - 1; ny >= 0; --ny)
            {
                // 0이면 다음 것을 탐색한다.
                if (board[ny][x] == 0) continue;

                // 0이 아닐때 다음것과 합칠 수 있으면 합친다.
                if (board[y][x] == board[ny][x])
                {
                    board[y][x] *= 2;
                    board[ny][x] = 0;
                }
                else
                {
                    if (board[y][x] == 0)
                    {
                        // 현재 위치가 비어있으면 현재 위치로 옮긴다.
                        board[y][x] = board[ny][x];
                        board[ny][x] = 0;
                        // 다음 ny를 탐색한다.
                        continue;
                    }
                    else
                    {
                        // 현재 위치에 값이 있으면 다음 위치로 옮긴다.
                        int temp = board[ny][x];
                        board[ny][x] = 0;
                        board[y - 1][x] = temp;
                    }
                }
                break;
            }
        }
    }

    return board;
}

int Search(const vector<vector<int>>& board, int depth)
{
    if (depth == 5)
    {
        return GetMaxValue(board);
    }

    int result = Search(MoveLeft(vector(board)), depth + 1);
    result = max(result, Search(MoveRight(vector(board)), depth + 1));
    result = max(result, Search(MoveUp(vector(board)), depth + 1));
    result = max(result, Search(MoveDown(vector(board)), depth + 1));

    return result;
}

int main()
{
    cin >> N;
    Board = vector<vector<int>>(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Board[i][j];
        }
    }

    cout << Search(Board, 0);
}