#include <iostream>
#include <string>

using namespace std;

// 0 : 그냥 땅, 1 : 뒷다리, 2 : 앞다리
int legType[50002];

// 뒷다리 개수
int backLeg = 0;
// 앞다리 개수
int frontLeg = 0;

int main()
{
    string str;

    cin >> str;

    int isOpen = str[0] == '(';
    for (int i = 1, size = str.size(); i < size; ++i)
    {
        char ch = str[i];
        if (isOpen && ch == '(')
        {
            legType[i] = 1;
            ++backLeg;
        }
        else if (!isOpen && ch == ')')
        {
            legType[i] = 2;
            ++frontLeg;
        }
        isOpen = ch == '(';
    }

    int pair = 0;

    for (int i = 0, size = str.size(); i < size; ++i)
    {
        if (legType[i] == 2)
        {
            --frontLeg;
            if (frontLeg == 0) break;
        }
        else if (legType[i] == 1)
        {
            pair += frontLeg;
        }
    }

    cout << pair << endl;

    return 0;
}