
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string T;

vector<string> vec;

bool comp(const string& lhs, const string& rhs)
{
    int lhsCount = 0;
    int rhsCount = 0;

    for (int i = 0; i < N; ++i)
    {
        lhsCount += lhs[i] == '1';
        rhsCount += rhs[i] == '1';
    }

    if (lhsCount != rhsCount) return lhsCount < rhsCount;
    return lhs < rhs;
}

int main()
{
    cin >> N >> T;

    reverse(T.begin(), T.end());

    int max = 1 << N;
    for (int i = 0; i < max; ++i)
    {
        string str = bitset<11>(i).to_string().substr(11 - N);
        reverse(str.begin(), str.end());
        // 문자열, 크기
        vec.push_back(str);
    }

    sort(vec.begin(), vec.end(), comp);

    for (int i = 0; i < max; ++i)
    {
        if (T == vec[i])
        {
            cout << i;
            break;
        }
    }

    return 0;
}