#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x1, y1, r1, x2, y2, r2;

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << "-1\n";
            continue;
        }

        // 거리
        double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        double sub = r1 > r2 ? r1 - r2 : r2 - r1;

        int result = 0;

        // 완전히 겹친다.
        if (dist == 0 && r1 == r2) result = -1;
        // 교점이 두 개이다.
        else if (dist < r1 + r2 && dist > sub) result = 2;
        // 교점이 한 개이다.
        else if (dist == r1 + r2 || dist == sub) result = 1;

        cout << result << '\n';
    }

    return 0;
}