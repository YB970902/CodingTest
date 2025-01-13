#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <cstring>

using namespace std;

// 1. 모든 quack의 수는 동일해야한다.
// 2. quack을 카운트 하는 과정에서, 앞에 있는 수는 뒤에 있는 수보다 크거나 같아야 한다.
// 3. q와 k의 순서만 체크한다.

string quack;
vector<int> quackCount = vector<int>(5);
list<int> quackPair;
int quackSize;

bool IsUnordered(int idx)
{
    if(idx == 0)
    {
        return quackCount[idx] < quackCount[idx + 1];
    }
    else if(idx == 4)
    {
        return quackCount[idx - 1] < quackCount[idx];
    }
    
    return quackCount[idx - 1] < quackCount[idx] || quackCount[idx] < quackCount[idx + 1];
}

void RemoveQuackPair()
{
    bool isStart = false;
    for(auto it = quackPair.begin(); it != quackPair.end();)
    {
        if(isStart == false && (*it) == 1)
        {
            isStart = true;
            it = quackPair.erase(it);
        }
        else if(isStart && (*it) == 2)
        {
            isStart = false;
            it = quackPair.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    unordered_map<char, int> quackToIdx;
    
    quackToIdx['q'] = 0;
    quackToIdx['u'] = 1;
    quackToIdx['a'] = 2;
    quackToIdx['c'] = 3;
    quackToIdx['k'] = 4;
    
    cin >> quack;
    
    quackSize = quack.size();
    
    for(int i = 0; i < quackSize; ++i)
    {
        int idx = quackToIdx[quack[i]];
        ++quackCount[idx];
        if(IsUnordered(idx))
        {
            cout << "-1";
            return 0;
        }
        
        if(quack[i] == 'q')
        {
            quackPair.push_back(1);
        }
        else if(quack[i] == 'k')
        {
            quackPair.push_back(2);
        }
    }
    
    int sameValue = quackCount[0];
    
    for(int i = 1; i < 5; ++i)
    {
        if(quackCount[i] != sameValue)
        {
            cout << "-1";
            return 0;
        }
    }
    
    int result = 0;
    
    while(quackPair.empty() == false)
    {
        RemoveQuackPair();
        ++result;
    }
    
    cout << result;
    
    return 0;
}
