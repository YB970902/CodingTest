#include <iostream>
#include <vector>

using namespace std;

// 수의 개수
int N;
// 합을 구해야 하는 횟수
int M;

// 누적합을 더해둘 벡터
vector<int> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    vec = vector<int>(N + 1, 0);

    // 0번값은 미리 계산한다.

    int temp;
    for (int i = 1; i <= N; ++i)
    {
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }

    // 구간의 시작점과 끝점
    int start, end;
    for (int i = 0; i < M; ++i)
    {
        cin >> start >> end;
        int long long startVal = vec[start - 1];
        int long long endVal = vec[end];
        cout << endVal - startVal << '\n';
    }

    return 0;
}