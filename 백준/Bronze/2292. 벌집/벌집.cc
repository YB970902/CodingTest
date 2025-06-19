#include <iostream>

using namespace std;

// 찾으려는 방 아이디
int N;

int main()
{
    cin >> N;

    long long count = 1;
    long long increase = 6;
    long long pSum = 1;

    while (N > pSum)
    {
        pSum += increase;
        increase += 6;
        ++count;
    }

    cout << count;

    return 0;
}