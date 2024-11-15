#include<iostream>
#include<vector>
using namespace std;

int main()
{
    char str[51];
    
    cin >> str;
    
    // 이전에 마이너스가 있었는지 여부.
    bool isMinus = false;
    
    // 총 결과
    int result = 0;
    // 빼기 이후의 덧셈을 모을 값.
    int addNum = 0;
    
    int index = 0;
    char strForNum[51];
    int indexForNum = 0;
    
    while(str[index] != '\0')
    {
        char c = str[index++];
        switch(c)
        {
            case '-':
                strForNum[indexForNum] = '\0';
                addNum += atoi(strForNum);
                indexForNum = 0;
                if(isMinus)
                {
                    result -= addNum;
                }
                else
                {
                    isMinus = true;
                    result += addNum;
                }
                addNum = 0;
                break;
            case '+':
                strForNum[indexForNum] = '\0';
                addNum += atoi(strForNum);
                indexForNum = 0;
                break;
            default:
                strForNum[indexForNum++] = c;
                break;
        }
    }
    
    strForNum[indexForNum] = '\0';
    addNum += atoi(strForNum);
    
    if(isMinus)
    {
        result -= addNum;
    }
    else
    {
        result += addNum;
    }
    
    cout << result;
}
