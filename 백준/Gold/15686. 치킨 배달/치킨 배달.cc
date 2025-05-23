#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 마을의 크기
int N;
// 남아있어야 하는 치킨집 수
int M;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int GetDist(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

int calc(const vector<int>& vecChickenIndex)
{
    int result = 0;
    for (int i = 0, size = house.size(); i < size; ++i)
    {
        int chickenDist = 10e8;
        for (int j = 0, jSize = vecChickenIndex.size(); j < jSize; ++j)
        {
            if (vecChickenIndex[j] == 0) continue;
            chickenDist = min(chickenDist, GetDist(house[i], chicken[j]));
        }

        result += chickenDist;
    }

    return result;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int info;
            cin >> info;

            // 집
            if (info == 1)
            {
                house.push_back(make_pair(i, j));
            }
            // 치킨집
            else if (info == 2)
            {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    // 총 치킨집 수에서 M만큼은 1을, 나머지는 0으로 넣도록 한다.
    vector<int> vec;
    for (int i = 0, size = chicken.size(); i < size; ++i)
    {
        vec.push_back(i < size - M ? 0 : 1);
    }

    int result = 10e8;
    do
    {
        result = min(result, calc(vec));
    } while (next_permutation(vec.begin(), vec.end()));

    cout << result;

    return 0;
}