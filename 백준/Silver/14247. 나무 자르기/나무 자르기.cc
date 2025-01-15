#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> treeInfo;

int compare(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return lhs.first < rhs.first;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int height;
        cin >> height;
        treeInfo.push_back({0, height});
    }
    
    for(int i = 0; i < N; ++i)
    {
        cin >> treeInfo[i].first;
    }
    
    sort(treeInfo.begin(), treeInfo.end(), compare);
    
    long long result = 0;
    
    for(int i = 0; i < N; ++i)
    {
        result += treeInfo[i].first * i + treeInfo[i].second;
    }
    
    cout << result;
    
    return 0;
}
