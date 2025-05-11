#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <set>

using namespace std;

// 나올 수 있는 가장 큰 수
int MaxNumber = 0;

// 소수가 들어있는 배열
vector<bool> PrimeNumbers;

// 숫자 카운트를 위한 셋
set<int> setNumbers;

void CalcPrimeNumber()
{
    for(int i = 2, size = PrimeNumbers.size(); i < size; ++i)
    {
        PrimeNumbers[i] = true;
    }
    
    for(int i = 2, size = PrimeNumbers.size(); i < size; ++i)
    {
        if(PrimeNumbers[i])
        {
            for(int j = i * 2; j < size; j += i)
            {
                PrimeNumbers[j] = false;
            }
        }
    }
}

void MakeRandomNumbers(vector<bool>& isVisited, const string& numbers, string& currNumber)
{
    for(int i = 0, size = numbers.size(); i < size; ++i)
    {
        if(isVisited[i]) continue;
        
        currNumber += numbers[i];
        isVisited[i] = true;
        
        int num = stoi(currNumber);
        if (PrimeNumbers[num]) setNumbers.insert(num);
        MakeRandomNumbers(isVisited, numbers, currNumber);
        
        currNumber.pop_back();
        isVisited[i] = false;
    }
}

int solution(string numbers) {
    // 가장 큰 수를 만들기 위해 내림차순 정렬
    sort(numbers.begin(), numbers.end(), greater<char>());
    // 가장 큰 수
    MaxNumber = stoi(numbers);
    
    // 소수 만들기.
    PrimeNumbers = vector<bool>(MaxNumber + 1);
    
    // 소수를 계산한다.
    CalcPrimeNumber();
    
    vector<bool> isVisited = vector<bool>(numbers.size());
    string strEmpty = "";
    setNumbers = set<int>();
    MakeRandomNumbers(isVisited, numbers, strEmpty);
    
    return setNumbers.size();
}