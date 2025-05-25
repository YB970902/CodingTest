#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의의 수
int N;

vector<pair<int, int>> vec;

bool sortTime(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    // 먼저 끝나는게 앞으로 온다.
    if (lhs.second < rhs.second) return true;
    if (lhs.second > rhs.second) return false;

    // 먼저 시작하는게 앞으로 온다.
    if (lhs.first < rhs.first) return true;
    if (lhs.first > rhs.first) return false;
    
    // // 더 빨리 끝나는게 앞으로 온다.
    // if (lhs.second - lhs.first < rhs.second - rhs.first) return true;
    // if (lhs.second - lhs.first > rhs.second - rhs.first) return false;

    return false;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        // 회의 시작, 종료 시간
        int start, end;
        cin >> start >> end;
        vec.emplace_back(start, end);
    }

    sort(vec.begin(), vec.end(), sortTime);

    int currTime = 0;
    int count = 0;

    for (int i = 0, size = vec.size(); i < size; ++i)
    {
        // 회의 시작시간이 현재 시간보다 전이라면 넘긴다.
        if (vec[i].first < currTime) continue;

        currTime = vec[i].second;
        ++count;
    }

    cout << count;

    return 0;
}