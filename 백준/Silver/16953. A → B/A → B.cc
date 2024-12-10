#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long A, B;

long AddCount;

void Search(long num, long count)
{
    if(num == B)
    {
        AddCount = min(AddCount, count);
        return;
    }
    
    if(num > B) return;
    
    Search(num * 2, count + 1);
    Search(num * 10 + 1, count + 1);
}

int main()
{
    cin >> A >> B;
    
    AddCount = INT64_MAX;
    
    Search(A, 0);
    
    if(AddCount == INT64_MAX) AddCount = -1;
    else ++AddCount;
    
    cout << AddCount;
    return 0;
}
