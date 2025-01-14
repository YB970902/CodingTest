#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());
    
    int answer = 0;
    int start = 0;
    int end = people.size() - 1;
    
    while(start <= end)
    {
        int sum = people[start] + people[end];
        if(sum > limit)
        {
            --end;
        }
        else
        {
            ++start;
            --end;
        }
        
        ++answer;
    }
    
    return answer;
}