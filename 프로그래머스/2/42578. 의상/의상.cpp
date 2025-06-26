#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 옷 종류. <옷 종류, 개수>
unordered_map<string, int> clothesType;

int solution(vector<vector<string>> clothes) {
    for(int i = 0, size = clothes.size(); i < size; ++i)
    {
        if(clothesType.find(clothes[i][1]) == clothesType.end())
        {
            // 아예 벗은것도 상태로 치므로 2개로 시작한다.
            clothesType[clothes[i][1]] = 2;
        }
        else
        {
            ++clothesType[clothes[i][1]];
        }
    }
    
    int answer = 1;
    
    for(auto kv = clothesType.begin(); kv != clothesType.end(); ++kv)
    {
        answer *= kv->second;
    }
    
    --answer;
    
    return answer;
}