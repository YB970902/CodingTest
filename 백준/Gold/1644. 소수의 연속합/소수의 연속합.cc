#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 구해야하는 자연수
int N;

// 소수
vector<int> primeNum;

vector<int> psum;

int main()
{
    cin >> N;

    primeNum.push_back(2);
    primeNum.push_back(3);

    for (int i = 4; i <= N; ++i)
    {
        bool isPrime = true;
        int num = sqrt(i);

        for (int j = 0, size = primeNum.size(); j < size; ++j)
        {
            int prime = primeNum[j];
            if (prime > num) break;
            if (i % prime == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime) primeNum.push_back(i);
    }

    psum.resize(primeNum.size() + 1);

    psum[1] = primeNum[0];
    for (int i = 2, size = psum.size(); i < size; ++i)
    {
        psum[i] = psum[i - 1] + primeNum[i - 1];
    }

    int left = 0;
    int right = 1;
    int result = 0;
    while (right < psum.size())
    {
        int currNum = psum[right] - psum[left];
        if (currNum < N)
        {
            ++right;
        }
        else if (currNum > N)
        {
            ++left;
            if (left == right) ++right;
        }
        else
        {
            ++result;
            ++right;
        }
    }

    cout << result;

    return 0;
}