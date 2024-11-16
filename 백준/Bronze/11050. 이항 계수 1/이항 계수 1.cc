#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

unsigned long long fact(unsigned long long val)
{
    if(val == 1) return 1;
    
    return val * fact(val - 1);
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    if(N == K)
    {
        cout << 1;
        return 0;
    }
    
    if(K == 1)
    {
        cout << N;
        return 0;
    }
    
    if(K == 0)
    {
        cout << 1;
        return 0;
    }
    
    if(K >= N - K)
    {
        unsigned long long n1 = 1;
        for(unsigned long long j = K + 1; j <= N; ++j)
        {
            n1 *= j;
        }
        
        cout << n1 / fact(N - K);
    }
    else
    {
        unsigned long long n1 = 1;
        for(unsigned long long j = N - K + 1; j <= N; ++j)
        {
            n1 *= j;
        }
        
        cout << n1 / fact(K);
    }
}
