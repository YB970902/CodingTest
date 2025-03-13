#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int index;
    int x, y;
    Node* pLeft = nullptr;
    Node* pRight = nullptr;
};

vector<Node> nodeList;

Node* pRoot;

bool compareNode(const Node& lhs, const Node& rhs)
{
    if(lhs.y > rhs.y) return true;
    if(lhs.y < rhs.y) return false;
    
    if(lhs.x < rhs.x) return true;
    if(lhs.x > rhs.x) return false;
    
    return true;
}

void SearchFirst(Node* pParent, vector<int>& result)
{
    if(pParent == nullptr) return;
    
    result.push_back(pParent->index);
    SearchFirst(pParent->pLeft, result);
    SearchFirst(pParent->pRight, result);
}

void SearchLast(Node* pParent, vector<int>& result)
{
    if(pParent == nullptr) return;
    
    SearchLast(pParent->pLeft, result);
    SearchLast(pParent->pRight, result);
    result.push_back(pParent->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    nodeList = vector<Node>(nodeinfo.size());
    
    for(int i = 0; i < nodeinfo.size(); ++i)
    {
        nodeList[i].index = i + 1;
        nodeList[i].x = nodeinfo[i][0];
        nodeList[i].y = nodeinfo[i][1];
    }
    
    sort(nodeList.begin(), nodeList.end(), compareNode);
    
    pRoot = &nodeList[0];
    
    Node* pParentNode = nullptr;
    Node* pCurrNode = nullptr;
    
    for(int i = 1; i < nodeList.size(); ++i)
    {
        pParentNode = pRoot;
        pCurrNode = &nodeList[i];
        
        while(true)
        {
            // x가 작다면 왼쪽에 넣는다.
            if(pCurrNode->x < pParentNode->x)
            {
                // 왼쪽에 노드가 없다면 삽입한다.
                if(pParentNode->pLeft == nullptr)
                {
                    pParentNode->pLeft = pCurrNode;
                    break;
                }
                else // 노드가 있다면 그 노드에 넣을 수 있는지 확인해본다.
                {
                    pParentNode = pParentNode->pLeft;
                }
            }
            else // x가 크다면 오른쪽에 넣는다.
            {
                // 오른쪽에 노드가 없다면 삽입한다.
                if(pParentNode->pRight == nullptr)
                {
                    pParentNode->pRight = pCurrNode;
                    break;
                }
                else // 노드가 있다면 그 노드에 넣을 수 있는지 확인해본다.
                {
                    pParentNode = pParentNode->pRight;
                }
            }
        }
    }
    
    vector<int> result;
    
    SearchFirst(pRoot, result);
    answer.push_back(result);
    result.clear();
    SearchLast(pRoot, result);
    answer.push_back(result);
    
    return answer;
}