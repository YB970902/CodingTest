#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main()
{
    cin >> N;
    
    int result = 5000;
    
    for(int i = 0; i < 5000; ++i)
    {
        int num = N - i * 5;
        if(num < 0) break;
        if(num % 3 == 0)
        {
            result = min(result, i + num / 3);
        }
    }
    
    if(result == 5000) result = -1;
    
    cout << result;
    
    return 0;
}
