#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    string enName;
    
    cin >> enName;
    
    int size = enName.size();
    
    unordered_map<char, int> chCount;
    
    for(int i = 0; i < size; ++i)
    {
        if(chCount.find(enName[i]) == chCount.end())
        {
            chCount[enName[i]] = 1;
        }
        else
        {
            ++chCount[enName[i]];
        }
    }
    
    bool isOdd = false;
    char chOdd = ' ';
    
    vector<char> result;
    
    for(auto[ch, count] : chCount)
    {
        if((count & 1) == 1)
        {
            if(isOdd)
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            else
            {
                isOdd = true;
                chOdd = ch;
            }
        }
        
        for(int i = 0; i < count / 2; ++i)
        {
            result.push_back(ch);
        }
    }
    
    sort(result.begin(), result.end());
    
    for(char ch : result)
    {
        cout << ch;
    }
    
    if(isOdd)
    {
        cout << chOdd;
    }
    
    for(int i = result.size() - 1; i >= 0; --i)
    {
        cout << result[i];
    }
    
    return 0;
}
