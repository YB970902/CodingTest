#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;

int truckCount = 0;
int totalWeight = 0;

int solution(int bridge_length/*다리 트럭 수*/, int weight/*다리 최대 무게*/, vector<int> truck_weights/*트럭별 무게*/) {
    for(int i = 0; i < bridge_length; ++i)
    {
        q.push(0);
    }
    
    int answer = 0;
    
    for(int i = 0, size = truck_weights.size(); i < size; ++i)
    {
        int currWeight = truck_weights[i];
        
        if(totalWeight + currWeight <= weight && truckCount < bridge_length)
        {
            int val = q.front();
            q.pop();
            if(val > 0)
            {
                totalWeight -= val;
                --truckCount;
            }
            q.push(currWeight);
            totalWeight += currWeight;
            ++truckCount;
            ++answer;
        }
        else
        {
            while(true)
            {
                int val = q.front();
                q.pop();
                
                if(val > 0)
                {
                    totalWeight -= val;
                    --truckCount;
                    if(totalWeight + currWeight <= weight && truckCount < bridge_length)
                    {
                        q.push(currWeight);
                        totalWeight += currWeight;
                        ++truckCount;
                        ++answer;
                        break;
                    }
                }
                q.push(0);
                ++answer;
            }
        }
    }
    
    while(truckCount > 0)
    {
        int val = q.front();
        q.pop();
        if(val > 0) --truckCount;
        ++answer;
    }
    
    return answer;
}