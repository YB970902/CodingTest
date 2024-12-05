#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

bool v[100][100];

bool findPath(int start, int end)
{
    bool visited[100] = {false};
    queue<int> q;
    q.push(start);
    
    if(start == end && v[start][end]) return false;
    
    while(q.size() > 0)
    {
        int index = q.front();
        q.pop();
        
        for(int i = 0; i < N; ++i)
        {
            if(v[index][i] == false) continue;
            if(visited[i]) continue;
            visited[i] = true;
            
            if(i == end) return true;
            
            q.push(i);
        }
    }
    
    return false;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> v[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i)
    {
        cout << (findPath(i, 0) ? "1" : "0");
        
        for(int j = 1; j < N; ++j)
        {
            cout << (findPath(i, j) ? " 1" : " 0");
        }
        cout << '\n';
    }
    
    return 0;
}
