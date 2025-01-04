#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int main()
{
    cin >> N >> M;
    
    int minSetValue = 1e9;
    int minOneValue = 1e9;

    for(int i = 0; i < M; ++i)
    {
        int one, set;
        
        cin >> set >> one;
        
        if(set < minSetValue) minSetValue = set;
        if(one < minOneValue) minOneValue = one;
    }
    
    
    // 끊어진 기타줄이 없다면, 기타줄을 안산다.
    if(N == 0)
    {
        cout << 0;
    }
    // 6개의 낱개 줄값이 세트 보다 싸거나 동일하다면 끊어진 기타줄수만큼 산다.
    else if(minOneValue * 6 <= minSetValue)
    {
        cout <<  minOneValue * N;
    }
    else
    {
        int result = N / 6 * minSetValue;
        int remain = N % 6;
        
        // 세트를 사고 남은 기타줄(6미만)을 낱개로 사는게 더 싼지, 세트로 사는게 더 싼지 알아본다.
        if(remain * minOneValue < minSetValue)
        {
            result += remain * minOneValue;
        }
        else
        {
            result += minSetValue;
        }
        
        cout << result;
    }
    
    return 0;
}
