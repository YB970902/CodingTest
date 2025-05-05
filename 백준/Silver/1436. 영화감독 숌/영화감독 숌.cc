#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;
    
    // 666의 개수를 카운트하기 위한 수
    int count = 0;
    while(true)
    {
        int temp = count;
        int sixCount = 0;
        while(temp > 0)
        {
            sixCount = temp % 10 == 6 ? sixCount + 1 : 0;
            if(sixCount == 3)
            {
                --N;
                break;
            }
            temp /= 10;
        }
        
        if(N == 0)
        {
            cout << count;
            break;
        }
        
        ++count;
    }
    
    return 0;
}
