#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 귤 크기별 개수 <귤 크기, 귤 개수>
unordered_map<int, int> tangerineSize;

vector<int> tangerineCount;

int solution(int k, vector<int> tangerine) {
    for(int i = 0, size = tangerine.size(); i < size; ++i)
    {
        int sz = tangerine[i];
        if(tangerineSize.find(sz) == tangerineSize.end())
        {
            tangerineSize[sz] = 1;
        }
        else
        {
            ++tangerineSize[sz];
        }
    }
    
    for(auto it = tangerineSize.begin(); it != tangerineSize.end(); ++it)
    {
        tangerineCount.push_back(it->second);
    }
    
    sort(tangerineCount.begin(), tangerineCount.end(), greater<int>());
    
    int answer = 0;
    for(int i = 0, size = tangerineCount.size(); i < size; ++i)
    {
        k -= tangerineCount[i];
        ++answer;
        if(k <= 0) break;
    }
    
    
    return answer;
}