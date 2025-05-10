#include <iostream>
#include <vector>

using namespace std;


// Sji 그래프
int S[20][20];
int N;
int HalfN;
int People[20];
// 두 팀 사이의 힘 차이 일단 최대값으로 설정.
int Result = 20001;

int TeamScore(const vector<int>& team)
{
    int score = 0;
    for (int i = 0; i < HalfN; ++i)
    {
        for (int j = 0; j < HalfN; ++j)
        {
            score += S[team[i]][team[j]];
        }
    }

    return score;
}

void CalcGap(const vector<int>& teamA)
{
    vector<int> teamB = vector<int>();


    int currTeamAIndex = 0;
    for (int i = 0; i < N; ++i)
    {
        if (teamA[currTeamAIndex] == i)
        {
            ++currTeamAIndex;
        }
        else
        {
            teamB.push_back(i);
        }
    }

    const int teamAScore = TeamScore(teamA);
    const int teamBScore = TeamScore(teamB);

    // 더 갭이 적은 값을 체크한다.
    Result = min(Result, abs(teamAScore - teamBScore));
}

void MatchPeople(vector<int>& vec, int currNum)
{
    // N 범위를 넘을 수는 없다.
    if (currNum >= N) return;

    // 계산이 가능한 수치라면 계산하고 반환한다.
    if (vec.size() == HalfN)
    {
        CalcGap(vec);
        return;
    }

    for (int i = currNum; i < N; ++i)
    {
        vec.push_back(i);
        MatchPeople(vec, i + 1);
        vec.pop_back();
    }
}

int main()
{
    cin >> N;

    HalfN = N / 2;

    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < N; ++col)
        {
            cin >> S[row][col];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        People[i] = i;
    }

    vector<int> vec = vector<int>();
    MatchPeople(vec, 0);

    cout << Result;

    return 0;
}