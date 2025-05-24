#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[1000000001];

// 탐색 성공 여부를 반환하는 DFS
bool dfs(const string& airport, const vector<vector<string>>& tickets, int count)
{
    // 탐색 성공
    if(count == tickets.size()) return true;
    
    for(int i = 0, size = tickets.size(); i < size; ++i)
    {
        // 사용하지 않았고, 출발하려는 공항과 일치한다면 티켓을 사용한다.
        if(!visited[i] && tickets[i][0] == airport)
        {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            if(dfs(tickets[i][1], tickets, count + 1)) return true;
            answer.pop_back();
            visited[i] = false;
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 오름차순으로 정렬
    sort(tickets.begin(), tickets.end());
    
    string startAirport = "ICN";
    
    answer.push_back("ICN");
    dfs(startAirport, tickets, 0);
    
    return answer;
}