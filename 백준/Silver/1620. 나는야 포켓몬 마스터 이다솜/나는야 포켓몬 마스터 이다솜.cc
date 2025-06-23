#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// 도감에 있는 포켓몬 수, 맞춰야 하는 문제 수
int N, M;

unordered_map<string, int> nameToNum;
unordered_map<int, string> numToName;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;

    string name;

    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        nameToNum[name] = i + 1;
        numToName[i + 1] = name;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> name;

        // 이름이 아니라 숫자인경우
        if (name[0] >= '0' && name[0] <= '9')
        {
            int num = stoi(name);
            cout << numToName[num] << '\n';
        }
        else
        {
            cout << nameToNum[name] << '\n';
        }
    }

    return 0;
}