#include <iostream>
#include <vector>

using namespace std;

int cityCount;
vector<int> roadLengths;
vector<int> oilValues;

int main()
{
    int cityCount;
    cin >> cityCount;
    
    roadLengths = vector<int>(cityCount - 1);
    oilValues = vector<int>(cityCount);
    
    for(int i = 0; i < cityCount - 1; ++i)
    {
        cin >> roadLengths[i];
    }
    
    for(int i = 0; i < cityCount; ++i)
    {
        cin >> oilValues[i];
    }
    
    int currOilValue = oilValues[0];
    int result = 0;
    
    for(int i = 0; i < cityCount - 1; ++i)
    {
        if(currOilValue > oilValues[i])
        {
            currOilValue = oilValues[i];
        }
        
        result += currOilValue * roadLengths[i];
    }
    
    cout << result;
}
