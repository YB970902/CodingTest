#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 나무의 수
int N;
// 집으로 가져가려는 나무의 길이
int M;
// 절단기의 높이
int H;

// 나무
vector<int> tree;

int main()
{
    cin >> N >> M;

    tree.resize(N + 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> tree[i];
    }

    // 내림차순 정렬
    sort(tree.begin(), tree.end(), greater<int>());

    // 높이는 나무의 가장 높은 부분이다.
    H = tree[0];

    if (N == 1)
    {
        H = tree[0] - M;
        cout << H;
        return 0;
    }
    
    // 결과
    int long long result = 0;
    
    for (int i = 1; i <= N; ++i)
    {
        // 절단기의 높이가 현재 나무의 높이와 같아질때까지 낮춘다.
        while (tree[i] < H)
        {
            --H;
            result += i;
            // 목표치만큼 베었다면 종료한다.
            if (result >= M) break;
        }
        // 목표치만큼 베었다면 종료한다.
        if (result >= M) break;
    }

    cout << H;

    return 0;
}