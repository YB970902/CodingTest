#include <iostream>

using namespace std;

int V, A, B;

int main()
{
    cin >> A >> B >> V;

    int delta = A - B;

    V -= A;

    int day = 1 + V / delta + (V % delta == 0 ? 0 : 1);
    cout << day;

    return 0;
}