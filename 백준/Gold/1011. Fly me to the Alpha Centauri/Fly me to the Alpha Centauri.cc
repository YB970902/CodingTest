#include <iostream>
#include <cmath>

using namespace std;

void Test()
{
    long long x, y;
    cin >> x >> y;

    long long dist = y - x;
    long long n = sqrt(dist);

    // 최고 속도에서 딱 1번만 이동한다.
    if (n * n == dist) cout << 2 * n - 1 << '\n';
    // 최고속도에서 딱 1번만 이동하고, 중간에 속도를 유지해야 하는 구간이 생긴 경우
    else if (n * n < dist && dist <= n * n + n) cout << 2 * n << '\n';
    // 최고 속도보다 1더 높은 곳까지 올려야 하는 경우
    else cout << 2 * n + 1 << '\n';
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        Test();
    }
}