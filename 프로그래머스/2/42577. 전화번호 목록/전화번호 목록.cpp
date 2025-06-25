#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> numberCount;

bool solution(vector<string> phone_book) {
    
    for(int i = 0, size = phone_book.size(); i < size; ++i)
    {
        const string& phoneNumber = phone_book[i];
        
        string currStr = "";
        for(int j = 0, len = phoneNumber.size(); j < len; ++j)
        {
            currStr += phoneNumber[j];
            if(numberCount.find(currStr) == numberCount.end())
            {
                // 없으면 0
                numberCount[currStr] = 0;
            }
            else
            {
                // 이미 있으면 추가한다.
                ++numberCount[currStr];
            }
        }
    }
    
    for(int i = 0, size = phone_book.size(); i < size; ++i)
    {
        if(numberCount[phone_book[i]] > 0) return false;
    }
    
    return true;
}