#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int money;
    
    cin >> money;
    
    int coin5 = money / 5;
    money %= 5;
    int coin2 = 0;
    
    bool canReturn = false;
    
    for(int i = 0; i <= coin5; ++i)
    {
        int curCoin5 = coin5 - i;
        if(money % 2 == 0)
        {
            coin2 = money / 2;
            coin5 = curCoin5;
            canReturn = true;
            break;
        }
        
        money += 5;
    }
    
    if(canReturn)
    {
        cout << coin5 + coin2;
    }
    else
    {
        cout << -1;
    }
    
    return 0;
}
