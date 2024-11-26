#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    
    int currTime = 0;
    int currHealth = health;
    
    for(vector<int> attackInfo : attacks)
    {
        int t = attackInfo[0];
        int atk = attackInfo[1];
        
        int delta = t - currTime - 1;
        currTime = t;
        
        if(delta > 0)
        {
            currHealth += delta * bandage[1];
            currHealth += delta / bandage[0] * bandage[2];
            
            if(currHealth > health) currHealth = health;
        }
        
        currHealth -= atk;
        
        if(currHealth <= 0) return -1;
    }
    return currHealth;
}