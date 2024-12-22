#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
vector<string> tile;

int main()
{
    cin >> R >> C;
    
    tile = vector<string>(R);
    
    for(int i = 0; i < R; ++i)
    {
        cin >> tile[i];
    }
    
    int count = 0;
    
    for(int i = 0; i < R; ++i)
    {
        bool isStart = false;
        
        for(int j = 0; j < C; ++j)
        {
            if(isStart == false && tile[i][j] == '-')
            {
                ++count;
                isStart = true;
            }
            else if(isStart && tile[i][j] == '|')
            {
                isStart = false;
            }
        }
    }
    
    for(int j = 0; j < C; ++j)
    {
        bool isStart = false;
        for(int i = 0; i < R; ++i)
        {
            if(isStart == false && tile[i][j] == '|')
            {
                ++count;
                isStart = true;
            }
            else if(isStart && tile[i][j] == '-')
            {
                isStart = false;
            }
        }
    }
    
    cout << count << '\n';
    
    return 0;
}
