#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> members;

vector<string> strangers;

// 듣도못한, 보도못한 수
int N, M;

int main()
{
    cin >> N >> M;

    string name;

    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        members.insert(name);
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> name;
        if (members.find(name) != members.end())
        {
            strangers.push_back(name);
        }
    }

    sort(strangers.begin(), strangers.end());

    int size = strangers.size();
    cout << size << '\n';

    for (int i = 0; i < size; ++i)
    {
        cout << strangers[i] << '\n';
    }

    return 0;
}