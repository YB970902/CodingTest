#include <string>
#include <vector>

using namespace std;

// 각 회전별 키의 정보
vector<vector<int>> keyInfo[4];

// 키와 자물쇠의 크기
int K, L;

// 회전별 키 정보 만들기
void MakeKeyInfo(const vector<vector<int>>& key)
{
    // 크기 설정
    for(int i = 0; i < 4; ++i)
    {
        keyInfo[i].resize(K);
        for(int j = 0; j < K; ++j)
        {
            keyInfo[i][j].resize(K);
        }
    }
    
    for(int i = 0; i < K; ++i)
    {
        for(int j = 0; j < K; ++j)
        {
            // 그대로
            keyInfo[0][i][j] = key[i][j];
            // 시계방향 회전
            keyInfo[1][i][j] = key[j][K - i - 1];
            // 반시계방향 회전
            keyInfo[2][i][j] = key[K - j - 1][i];
            // 180도 회전
            keyInfo[3][i][j] = key[K - i - 1][K - j - 1];
        }
    }
}

// 자물쇠가 다 맞았는지 여부를 반환한다.
bool Search(const vector<vector<int>> lock)
{
    for(int i = 0; i < L; ++i)
    {
        for(int j = 0; j < L; ++j)
        {
            // 홈이 비어있는게 있거나, 돌기끼리 닿음.
            if(lock[i][j] != 1) return false;
        }
    }
    
    return true;
}

// 자물쇠 정보를 씌운다.
void ClearLock(vector<vector<int>>& temp, const vector<vector<int>>& lock)
{
    for(int i = 0; i < L; ++i)
    {
        for(int j = 0; j < L; ++j)
        {
            temp[i][j] = lock[i][j];
        }
    }
}

// 키와 좌물쇠를 매치시킨다. 매칭된게 있는지 여부를 반환한다.
bool Matching(const vector<vector<int>>& lock)
{
    vector<vector<int>> temp;
    temp.resize(L);
    for(int i = 0; i < L; ++i)
    {
        temp[i].resize(L);
    }
    
    for(int offsetX = -K + 1; offsetX < L + K; ++offsetX)
    {
        for(int offsetY = -K + 1; offsetY < L + K; ++offsetY)
        {
            for(int k = 0; k < 4; ++k)
            {
                ClearLock(temp, lock);
                for(int i = 0; i < K; ++i)
                {
                    int x = offsetX + i;
                    // 범위를 벗어났다면 넘어간다.
                    if(x < 0 || x >= L) continue;
                    for(int j = 0; j < K; ++j)
                    {
                        int y = offsetY + j;
                        // 범위를 벗어났다면 넘어간다.
                        if(y < 0 || y >= L) continue;

                        temp[x][y] += keyInfo[k][i][j];
                    }
                }
                if(Search(temp)) return true;
            }
        }
    }
    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    K = key.size();
    L = lock.size();
    
    MakeKeyInfo(key);
    
    return Matching(lock);
}