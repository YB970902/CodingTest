#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    
    int resultSize = number.size() - k;
    string answer = "";
    
    for(int i = 0; i < number.size(); ++i)
    {
        // 반환 문자열이 비어있지 않고 k가 0보다 크다면, 반환 문자열의 끝에 있는 숫자가 현재 숫자보다 작다면 지운다.
        while(!answer.empty() && answer.back() < number[i] && k > 0)
        {
            answer.pop_back();
            --k;
        }
        answer += number[i];
    }
    
    // 자르지 않은 숫자가 있다면 자른다.
    answer = answer.substr(0, resultSize);
    
    return answer;
}