#include <iostream>
#include <unordered_map>

using namespace std;

// 가지고 있는 숫자카드, 숫자카드인지 구해야할 카드
int N, M;

// [카드 번호][보유수]
unordered_map<int, int> cards;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    cin >> N;

    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        // 보유한게 없다면 1설정
        if (cards.find(num) == cards.end())
        {
            cards[num] = 1;
        }
        else
        {
            // 보유량 올리기
            ++cards[num];
        }
    }

    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> num;
        if (cards.find(num) == cards.end())
        {
            cout << 0 << ' ';
        }
        else
        {
            cout << cards[num] << ' ';
        }
    }

    return 0;
}