#include <string>
#include <vector>

using namespace std;

int pSum[10];

int solution(int n, int w, int num) {
    for(int i = 0; i < n; ++i)
    {
        int height = i / w;
        int index = (height % 2 == 0) ? i % w : w - i % w - 1;
        ++pSum[index];
    }
    
    // 0부터 시작한다고 가정
    --num;
    
    int height = num / w;
    int offset = (height % 2 == 0) ? num % w : w - num % w - 1;
    return pSum[offset] - height;
}