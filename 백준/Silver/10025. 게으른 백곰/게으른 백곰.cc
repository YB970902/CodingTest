#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

vector<pair<int, int>> vec;

int main()
{
    cin >> N >> K;
    
    K *= 2;
    
    vec = vector<pair<int, int>>(N);
    
    for(int i = 0; i < N; ++i)
    {
        cin >> vec[i].second >> vec[i].first;
    }
    
    sort(vec.begin(), vec.end());
    
    long long currIceCount = 0;
    long long maxIceCount = 0;
    
    int startPoint = 0;
    
    for(int endPoint = 0, size = (int)vec.size(); endPoint < size; ++endPoint)
    {
        currIceCount += vec[endPoint].second;
        
        while(vec[endPoint].first - vec[startPoint].first > K)
        {
            currIceCount -= vec[startPoint].second;
            ++startPoint;
        }
        
        if(currIceCount > maxIceCount) maxIceCount = currIceCount;
    }
    
    cout << maxIceCount;
    
    return 0;
}
