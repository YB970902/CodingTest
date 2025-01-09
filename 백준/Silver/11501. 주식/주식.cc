#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        
        vector<int> price = vector<int>(N);
        for(int j = 0; j < N; ++j)
        {
            cin >> price[j];
        }
        
        int idx = N - 1;
        long long value = 0;
        
        for(int j = N - 2; j >= 0; --j)
        {
            if(price[j] < price[idx])
            {
                value += price[idx] - price[j];
            }
            else
            {
                idx = j;
            }
        }
        
        cout << value << '\n';
    }
    return 0;
}
