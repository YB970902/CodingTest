#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

vector<int> vec;

int main()
{
    cin >> N;
    cin >> K;
    
    vec = vector<int>(N);
    
    for(int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    
    int coinCount = 0;
    
    for(int i = N - 1; i >= 0; --i)
    {
        if(vec[i] > K) continue;
        coinCount += K / vec[i];
        K %= vec[i];
        if(K == 0) break;
    }
    
    cout << coinCount;
    
    return 0;
}
