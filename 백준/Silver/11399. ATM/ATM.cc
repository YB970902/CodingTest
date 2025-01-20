#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> vec;

int main()
{
    cin >> N;
    
    vec = vector<int>(N);
    
    for(int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end());
    
    long long result = 0;
    long long add = 0;
    
    for(int i = 0; i < N; ++i)
    {
        add += vec[i];
        result += add;
    }
    
    cout << result;
    
    return 0;
}
