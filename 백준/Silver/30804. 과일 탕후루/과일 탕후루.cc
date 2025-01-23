#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> fruits;

int fruitType[10];

int main()
{
    cin >> N;
    
    fruits = vector<int>(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> fruits[i];
    }
    
    int fruitTypeCount = 0;
    int currFruitCount = 0;
    int maxFruitCount = 0;
    int startIdx = 0;
    
    for(int endIdx = 0; endIdx < N; ++endIdx)
    {
        int fruit = fruits[endIdx];
        
        if(fruitTypeCount < 2)
        {
            // 가지고 있는 타입의 개수가 2개 미만이면, 무조건 더한다.
            // 0개라면 새로운 타입을 획득한것이다.
            if(fruitType[fruit] == 0) ++fruitTypeCount;
            ++fruitType[fruit];
            ++currFruitCount;
        }
        else
        {
            // 이미 2개의 종류를 가지고 있는데, 새로운 종류를 발견했다면, 종류가 1개가 될때까지 startIdx를 올린다.
            if(fruitType[fruit] == 0)
            {
                while(startIdx < endIdx)
                {
                    int startFruit = fruits[startIdx];
                    ++startIdx;
                    --currFruitCount;
                    --fruitType[startFruit];
                    if(fruitType[startFruit] == 0)
                    {
                        --fruitTypeCount;
                        break;
                    }
                }
                
                ++fruitTypeCount;
                ++fruitType[fruit];
                ++currFruitCount;
            }
            else
            {
                ++fruitType[fruit];
                ++currFruitCount;
            }
        }
        
        maxFruitCount = max(maxFruitCount, currFruitCount);
    }
    
    cout << maxFruitCount;
    
    return 0;
}
