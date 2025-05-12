#include <string>
#include <vector>

using namespace std;

// 노란색으로 모든 직사각형을 만든다. 가로 한 줄, 두 줄 .. 점점 늘린다.
// 만약에 가로가 두 줄인데, 노란색으로2로 나눴을 때 나머지가 0보다 크다면, 직사각형이 아니므로 패스한다.
// 직사각형을 만들면, 테두리를 두른다. 테두리는 가로 * 2 + 세로 * 2 + 4(꼭짓점) 로 계산할 수 있다.

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 1개는 계산하지 못하므로 따로 예외처리한다.
    if(yellow == 1)
    {
        answer.push_back(3);
        answer.push_back(3);
        return answer;
    }
    
    // 노란색 칸으로 직사각형을 만든다.
    for(int i = 1; i < yellow; ++i)
    {
        // 직사각형이 만들어지지 않는다면 패스
        if(yellow % i > 0) continue;
        
        // 가로줄 수
        int row = i;
        // 세로줄 수
        int col = yellow / i;
        
        // 테두리 개수를 구한다.
        int edge = row * 2 + col * 2 + 4;
        
        // 결과가 동일하다면 가로 세로 크기를 넣고 반복문을 종료한다.
        if(brown == edge)
        {
            answer.push_back(col + 2);
            answer.push_back(row + 2);
            break;
        }
    }
    return answer;
}