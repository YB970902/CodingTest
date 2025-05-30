#include <iostream>
#include <vector>

using namespace std;

int countZero;
int countOne;

struct Fibo
{
    int ZeroCount = 0;
    int OneCount = 0;
    int Value = 0;
};

int T, N;
Fibo dp[41];
bool allocated[41];

int fibonacci(int n, int& zero, int& one)
{
    if (allocated[n])
    {
        zero = dp[n].ZeroCount;
        one = dp[n].OneCount;
        return dp[n].Value;
    }

    int m1Zero;
    int m1One;
    int m1Value = fibonacci(n - 1, m1Zero, m1One);

    int m2Zero;
    int m2One;
    int m2Value = fibonacci(n - 2, m2Zero, m2One);

    allocated[n] = true;
    dp[n].ZeroCount = m1Zero + m2Zero;
    dp[n].OneCount = m1One + m2One;
    dp[n].Value = m1Value + m2Value;

    zero = dp[n].ZeroCount;
    one = dp[n].OneCount;
    return dp[n].Value;
}

int main()
{
    allocated[0] = true;
    allocated[1] = true;

    dp[0].ZeroCount = 1;
    dp[0].OneCount = 0;
    dp[0].Value = 0;

    dp[1].ZeroCount = 0;
    dp[1].OneCount = 1;
    dp[1].Value = 1;

    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        int zero;
        int one;
        fibonacci(N, zero, one);
        cout << zero << " " << one << "\n";
    }

    return 0;
}