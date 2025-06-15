#include <iostream>
#include <vector>

using namespace std;

// 수열의 길이
int N;

// 목표값
int M;

// 나머지 값
vector<int> mod;

int main()
{
    cin >> N >> M;

    mod.resize(M);

    int long long psum = 0;
    // 누적값 0번 인덱스가 0이므로.
    ++mod[0];
    for (int i = 1; i <= N; ++i)
    {
        int val;
        cin >> val;
        psum = psum + val;
        // 나머지가 같은 개수를 저장한다.
        ++mod[psum % M];
    }

    int long long result = 0;

    for (int i = 0; i < M; ++i)
    {
        if (mod[i] < 2) continue;

        for (int j = mod[i] - 1; j >= 1; --j)
        {
            result += j;
        }
    }

    cout << result;

    return 0;
}