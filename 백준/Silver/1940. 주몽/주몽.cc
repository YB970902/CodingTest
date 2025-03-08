#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Arr;

int main()
{
    cin >> N;
    cin >> M;
    
    Arr = vector<int>(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> Arr[i];
    }
    
    sort(Arr.begin(), Arr.end());
    
    int start = 0;
    int end = Arr.size() - 1;
    
    int result = 0;
    
    while(start < end)
    {
        if(Arr[start] == 0)
        {
            ++start;
            continue;
        }
        
        if(Arr[end] == 0)
        {
            --end;
            continue;
        }
        
        int add = Arr[start] + Arr[end];
        
        if(add == M)
        {
            Arr[start] = 0;
            Arr[end] = 0;
            start = 0;
            end = Arr.size() - 1;
            ++result;
        }
        else if(add < M)
        {
            ++start;
        }
        else if(add > M)
        {
            --end;
        }
    }
    
    cout << result;
    
    return 0;
}
