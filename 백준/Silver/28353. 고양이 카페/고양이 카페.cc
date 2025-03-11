#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> arr;

int main()
{
    cin >> N >> K;
    
    arr = vector<int>(N);
    
    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int result = 0;
    
    int startIndex = 0;
    int endIndex = arr.size() - 1;
    
    while(startIndex < endIndex)
    {
        int start = arr[startIndex];
        int end = arr[endIndex];
        
        if(start == 0)
        {
            ++startIndex;
            continue;
        }
        
        if(end == 0)
        {
            --endIndex;
            continue;
        }
        
        if(start + end > K)
        {
            --endIndex;
            continue;
        }
        
        ++result;
        arr[startIndex] = 0;
        arr[endIndex] = 0;
        
        startIndex = 0;
        endIndex = arr.size() - 1;
    }
    
    cout << result;
    
    return 0;
}
