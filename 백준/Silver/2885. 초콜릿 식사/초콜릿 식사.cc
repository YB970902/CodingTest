#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> lookup;

int main()
{
    int K;
    cin >> K;
    
    long long maxChocoLen = 1;
    while(maxChocoLen < K)
    {
        maxChocoLen *= 2;
    }
    
    int divCount = 0;
    long long currChocoLen = maxChocoLen;
    
    while(K > 0)
    {
        if(currChocoLen > K)
        {
            currChocoLen /= 2;
            ++divCount;
        }
        else
        {
            K -= currChocoLen;
        }
    }
    
    cout << maxChocoLen << " " << divCount;
    
    return 0;
}
