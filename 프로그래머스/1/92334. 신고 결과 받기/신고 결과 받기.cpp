#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_set<string> setReport;
unordered_map<string, int> reportedCount;
unordered_map<string, vector<string>> reportCount;

void Report(const string& report)
{
    if(setReport.find(report) != setReport.end()) return;
    
    int delimiter = report.find(" ");
    string reporter = report.substr(0, delimiter);
    string target = report.substr(delimiter + 1);
    
    setReport.insert(report);
    
    reportCount[reporter].emplace_back(target);
    
    if(reportedCount.find(target) == reportedCount.end())
    {
        reportedCount[target] = 1;
    }
    else
    {
        ++reportedCount[target];
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    
    for(string str : report)
    {
        Report(str);
    }
    
    for(int i = 0, id_len = id_list.size(); i < id_len; ++i)
    {
        const string& id = id_list[i];
        if(reportCount.find(id) == reportCount.end()) continue;
        
        const vector<string>& reportList = reportCount[id];
        for(int j = 0, size = reportList.size(); j < size; ++j)
        {
            if(reportedCount.find(reportList[j]) == reportedCount.end()) continue;
            
            if(reportedCount[reportList[j]] >= k)
            {
                ++answer[i];
            }
        }
    }
    
    return answer;
}