#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct State {
    int x1, y1, x2, y2, cost;
};

bool isInBoard(int x, int y, int N) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int solution(vector<vector<int>> board) {
    int N = board.size();

    // visited[x1][y1][x2][y2]
    vector<vector<vector<vector<bool>>>> visited(N, vector<vector<vector<bool>>>(
        N, vector<vector<bool>>(N, vector<bool>(N, false))));

    queue<State> q;
    q.push({0, 0, 0, 1, 0});
    visited[0][0][0][1] = true;

    int dx[4] = {-1, 1, 0, 0};  // 상하좌우
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x1, y1, x2, y2, cost] = q.front();
        q.pop();

        if ((x1 == N - 1 && y1 == N - 1) || (x2 == N - 1 && y2 == N - 1)) {
            return cost;
        }

        // 1. 네 방향으로 이동
        for (int i = 0; i < 4; ++i) {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];

            if (isInBoard(nx1, ny1, N) && isInBoard(nx2, ny2, N) &&
                board[nx1][ny1] == 0 && board[nx2][ny2] == 0 &&
                !visited[nx1][ny1][nx2][ny2]) {

                visited[nx1][ny1][nx2][ny2] = true;
                q.push({nx1, ny1, nx2, ny2, cost + 1});
            }
        }

        // 2. 회전
        if (x1 == x2) { // 가로 방향
            for (int d = -1; d <= 1; d += 2) {
                if (isInBoard(x1 + d, y1, N) && isInBoard(x2 + d, y2, N) &&
                    board[x1 + d][y1] == 0 && board[x2 + d][y2] == 0) {

                    if (!visited[x1][y1][x1 + d][y1]) {
                        visited[x1][y1][x1 + d][y1] = true;
                        q.push({x1, y1, x1 + d, y1, cost + 1});
                    }
                    if (!visited[x2][y2][x2 + d][y2]) {
                        visited[x2][y2][x2 + d][y2] = true;
                        q.push({x2, y2, x2 + d, y2, cost + 1});
                    }
                }
            }
        } else if (y1 == y2) { // 세로 방향
            for (int d = -1; d <= 1; d += 2) {
                if (isInBoard(x1, y1 + d, N) && isInBoard(x2, y2 + d, N) &&
                    board[x1][y1 + d] == 0 && board[x2][y2 + d] == 0) {

                    if (!visited[x1][y1][x1][y1 + d]) {
                        visited[x1][y1][x1][y1 + d] = true;
                        q.push({x1, y1, x1, y1 + d, cost + 1});
                    }
                    if (!visited[x2][y2][x2][y2 + d]) {
                        visited[x2][y2][x2][y2 + d] = true;
                        q.push({x2, y2, x2, y2 + d, cost + 1});
                    }
                }
            }
        }
    }

    return -1; // 도달 못하는 경우
}
