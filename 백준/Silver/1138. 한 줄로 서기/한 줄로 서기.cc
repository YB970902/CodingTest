#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

void insertAt(int index, int value)
{
    int curIdx = 0;
    for(int i = 0; i < N; ++i)
    {
        if(vec[i] == 0)
        {
            if(curIdx == index)
            {
                vec[i] = value;
                return;
            }
            else
            {
                ++curIdx;
            }
        }
    }
}

int main()
{
    cin >> N;
    
    vec = vector<int>(N);
    
    for(int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        insertAt(temp, i + 1);
    }
    
    for(int i = 0; i < N; ++i)
    {
        cout << vec[i] << " ";
    }
    
    return 0;
}
