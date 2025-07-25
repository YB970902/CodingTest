#include <iostream>
#include <vector>

using namespace std;

// 큐 크기, 목표 크기
int N, M;
// 큐
vector<int> vec;
// 목표값
vector<int> target;
// 목표값 인덱스
int targetIndex = 0;
int Index = 0;

int main()
{
    cin >> N >> M;

    vec.resize(N);
    target.resize(M);

    for (int i = 0; i < N; ++i)
    {
        vec[i] = i + 1;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> target[i];
    }

    // 결과
    int result = 0;

    while (targetIndex < M)
    {
        int nextTarget = target[targetIndex];
        int nextTargetIndex = 0;
        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[i] == nextTarget)
            {
                nextTargetIndex = i;
                break;
            }
        }

        int start = Index < nextTargetIndex ? Index : nextTargetIndex;
        int end = Index < nextTargetIndex ? nextTargetIndex : Index;

        result += min(end - start, start + (N - end));

        Index = nextTargetIndex;
        vec.erase(vec.begin() + nextTargetIndex);
        --N;
        if (Index >= N) Index = 0;

        ++targetIndex;
    }

    cout << result;

    return 0;
}