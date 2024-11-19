#include<iostream>
using namespace std;

long long int lhs;
long long int rhs;

long long int currLhs;
long long int currRhs;

int main()
{
    cin >> lhs >> rhs;
    
    if(lhs == rhs)
    {
        cout << lhs << endl;
        return 0;
    }
    
    currLhs = lhs;
    currRhs = rhs;
    
    while(currLhs != currRhs)
    {
        if(currLhs < currRhs)
        {
            currLhs += lhs;
        }
        else if(currLhs > currRhs)
        {
            currRhs += rhs;
        }
    }
    
    cout << currLhs << endl;
}
