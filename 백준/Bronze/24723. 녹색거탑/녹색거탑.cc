#include <iostream>
using namespace std;

int n = 0;
int c = 0;

void func(int h)
{
    if(h == n)
    {
        ++c;
        return;
    }
    
    func(h + 1);
    func(h + 1);
}

int main()
{
    cin >> n;
    
    func(0);
    
    cout << c;
    
    return 0;
}