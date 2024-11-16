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
    int count = 0;
    cin >> count;
    for(int i = 0; i < count; ++i)
    {
        int N, K;
        cin >> K >> N;
        
        if(N == K)
        {
            cout << 1 << endl;
            continue;
        }
        
        if(K == 1)
        {
            cout << N << endl;
            continue;
        }
        
        if(K == 0)
        {
            cout << 1 << endl;
            continue;
        }
        
        if(K >= N - K)
        {
            unsigned long long n1 = 1;
            for(unsigned long long j = K + 1; j <= N; ++j)
            {
                n1 *= j;
            }
            
            cout << n1 / fact(N - K) << endl;
        }
        else
        {
            unsigned long long n1 = 1;
            for(unsigned long long j = N - K + 1; j <= N; ++j)
            {
                n1 *= j;
            }
            
            cout << n1 / fact(K) << endl;
        }
    }
}
