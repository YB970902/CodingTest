#include <string>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solution(vector<vector<string>> board, int h, int w) {
    const string& color = board[h][w];
    
    int answer = 0;
    
    int maxH = board.size();
    int maxW = board[0].size();
    
    for(int i = 0; i < 4; ++i)
    {
        int currH = h + dx[i];
        int currW = w + dy[i];
        
        if(currH < 0 || currH >= maxH || currW < 0 || currW >= maxW) continue;
        
        if(board[currH][currW].compare(color) == 0)
        {
            ++answer;
        }
    }
    
    return answer;
}