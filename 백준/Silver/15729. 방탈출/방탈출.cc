#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<bool> target;
vector<bool> currButtons;

void PressButton(int index)
{
    for(int i = 0; i < 3; ++i)
    {
        if(index + i >= N) break;
        currButtons[index + i] = !currButtons[index + i];
    }
}

int main()
{
    cin >> N;
    
    currButtons = vector<bool>(N);
    target = vector<bool>(N);
    
    bool isFindMinOpenButtonIndex = false;
    int openButtonIndex = 0;
    
    for(int i = 0; i < N; ++i)
    {
        int isOn;
        cin >> isOn;
        target[i] = (bool)isOn;
        if(isFindMinOpenButtonIndex == false && target[i])
        {
            isFindMinOpenButtonIndex = true;
            openButtonIndex = i;
        }
    }
    
    if(isFindMinOpenButtonIndex == false)
    {
        cout << 0;
        return 0;
    }
    
    int pressCount = 0;
    
    for(int i = openButtonIndex; i < N; ++i)
    {
        if(target[i] != currButtons[i])
        {
            PressButton(i);
            ++pressCount;
        }
    }
    
    cout << pressCount;
    
    return 0;
}
