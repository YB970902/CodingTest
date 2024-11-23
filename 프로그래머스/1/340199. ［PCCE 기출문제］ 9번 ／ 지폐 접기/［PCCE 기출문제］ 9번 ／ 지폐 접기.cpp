#include <string>
#include <vector>

using namespace std;

int walletMin;
int walletMax;

int billMin;
int billMax;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    if(wallet[0] < wallet[1])
    {
        walletMin = wallet[0];
        walletMax = wallet[1];
    }
    else
    {
        walletMin = wallet[1];
        walletMax = wallet[0];
    }
    
    if(bill[0] < bill[1])
    {
        billMin = bill[0];
        billMax = bill[1];
    }
    else
    {
        billMin = bill[1];
        billMax = bill[0];
    }
    
    while(billMin > walletMin || billMax > walletMax)
    {
        ++answer;
        billMax = billMax / 2;
        
        if(billMax < billMin)
        {
            swap(billMax, billMin);
        }
    }
    
    return answer;
}