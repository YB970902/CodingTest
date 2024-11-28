#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    bool isOpen = false;
    
    int currCount = 0;
    int totalCount = 0;
    
    cin >> str;
    for(char chCurr : str)
    {
        if(chCurr == '(')
        {
            ++currCount;
            isOpen = true;
        }
        else
        {
            --currCount;
            
            if(isOpen)
            {
                totalCount += currCount;
            }
            else
            {
                ++totalCount;
            }
            isOpen = false;
        }
    }
    
    cout << totalCount << endl;
}
