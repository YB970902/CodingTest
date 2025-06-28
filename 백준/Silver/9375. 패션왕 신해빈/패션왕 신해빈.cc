#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;

int T, N;

int main()
{
    cin >> T;

    for (int i = 0 ;i < T; ++i)
    {
        cin >> N;

        string type;
        for (int j = 0; j < N; ++j)
        {
            cin >> type;
            cin >> type;

            if (map.find(type) == map.end())
            {
                map[type] = 2;
            }
            else
            {
                ++map[type];
            }
        }

        int result = 1;
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            result *= it->second;
        }

        --result;

        cout << result << '\n';

        map.clear();
    }
    return 0;
}