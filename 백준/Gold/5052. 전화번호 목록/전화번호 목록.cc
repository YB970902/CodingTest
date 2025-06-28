#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> map;
vector<string> numbers;

int T, N;

int main()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N;

        string number;

        for (int j = 0; j < N; ++j)
        {
            cin >> number;
            numbers.push_back(number);
            string temp = "";
            for (int k = 0, size = number.size(); k < size; ++k)
            {
                temp += number[k];
                if (map.find(temp) == map.end())
                {
                    map[temp] = 0;
                }
                else
                {
                    ++map[temp];
                }
            }
        }

        bool sameNumber = false;
        for (int j = 0; j < N; ++j)
        {
            if (map[numbers[j]] > 0)
            {
                sameNumber = true;
                break;
            }
        }
        if (sameNumber) cout << "NO" << '\n';
        else cout << "YES" << '\n';

        map.clear();
        numbers.clear();
    }
}