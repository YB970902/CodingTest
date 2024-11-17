#include <string>
#include <vector>

using namespace std;

int arrTrade[50][50] = {{0}};
int giftScore[50] = {0};
int giftCount[50] = {0};

int FindNameIndex(const vector<string>& friends, string name)
{
    for(int i = 0, size = friends.size(); i < size; ++i)
    {
        if(friends[i] == name) return i;
    }
    
    return -1;
}

int solution(vector<string> friends, vector<string> gifts) {
    for(string gift : gifts)
    {
        int spaceIndex = gift.find(" ");
        string sender = gift.substr(0, spaceIndex);
        string receiver = gift.substr(spaceIndex + 1);
        int senderIndex = FindNameIndex(friends, sender);
        int receiverIndex = FindNameIndex(friends, receiver);
        ++arrTrade[senderIndex][receiverIndex];
        ++giftScore[senderIndex];
        --giftScore[receiverIndex];
    }
    
    for(int i = 0, size = friends.size(); i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(i == j) continue;
            
            int lhsCount = arrTrade[i][j];
            int rhsCount = arrTrade[j][i];
            if(lhsCount > rhsCount)
            {
                ++giftCount[i];
            }
            else if(lhsCount < rhsCount)
            {
                ++giftCount[j];
            }
            else
            {
                int lhsScore = giftScore[i];
                int rhsScore = giftScore[j];
                if(lhsScore > rhsScore) ++giftCount[i];
                else if(lhsScore < rhsScore) ++giftCount[j];
            }
        }
    }
    
    int answer = 0;
    for(int i = 0, size = friends.size(); i < size; ++i)
    {
        if(giftCount[i] > answer) answer = giftCount[i];
    }
    
    return answer / 2;
}