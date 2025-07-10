#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N, M;

unordered_map<string, int> product;
unordered_map<string, int> purchase;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        string name;
        int price;
        cin >> name >> price;
        product[name] = price + price / 20;
    }

    int result = 0;

    for (int i = 0; i < M; ++i)
    {
        string name;
        int price;
        cin >> name >> price;
        if (price > product[name]) ++result;
    }

    cout << result;

    return 0;
}