#include<iostream>
using namespace std;

int main()
{
    int n = 0;
    
    cin >> n;
    
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    else if(n == 2)
    {
        cout << 2;
        return 0;
    }
    
    cout << n * (n - 1);
}