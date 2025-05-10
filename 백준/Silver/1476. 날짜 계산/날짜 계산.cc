#include <iostream>

using namespace std;

int E, S, M;

int main()
{
    cin >> E >> S >> M;

    --E;
    --S;
    --M;
    
    int currYear = 1;
    int currE = 0;
    int currS = 0;
    int currM = 0;
    while (true)
    {
        if (currE == E && currS == S && currM == M) break;
        ++currYear;
        currE = ++currE % 15;
        currS = ++currS % 28;
        currM = ++currM % 19;
    }

    cout << currYear;

    return 0;
}