#include <iostream>
#include <cmath>

using namespace std;

void Test()
{
    // 시작지와 도착지
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    // 행성 개수
    int N;

    cin >> N;

    // 진입, 이탈하는 행성계 개수
    int result = 0;

    for (int i = 0; i < N; ++i)
    {
        int x, y, r;
        cin >> x >> y >> r;
        r = pow(r, 2);
        double distToStart = pow(abs(x1 - x), 2) + pow(abs(y1 - y), 2);
        double distToEnd = pow(abs(x2 - x),2 ) + pow(abs(y2 - y), 2);

        // 행성계가 두 지점을 모두 포함한다면, 이탈과 진입을 하지 않는다.
        if (r >= distToStart && r >= distToEnd) continue;

        // 행성계가 두 지점중 하나를 감싸고 있다면, 진입과 이탈중 하나를 해야한다.
        if (r >= distToStart || r >= distToEnd)
        {
            ++result;
        }
    }

    cout << result << '\n';
}

int main()
{
    int T;

    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        Test();
    }

    return 0;
}