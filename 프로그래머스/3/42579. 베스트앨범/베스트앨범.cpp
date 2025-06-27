#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 장르별 플레이 횟수 <장르, 재생 횟수>
unordered_map<string, long long> genrePlayCount;
// 노래 정보 <장르, 아이디>
unordered_map<string, vector<int>> songInfo; 

// 결과
vector<int> answer;

// 플레이수가 많은게 앞에 선다.
bool compGenreOrder(const string& lhs, const string& rhs)
{
    return genrePlayCount[lhs] > genrePlayCount[rhs];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    for(int i = 0, size = genres.size(); i < size; ++i)
    {
        int id = i;
        string genre = genres[i];
        int play = plays[i];
        
        // 없으면 추가한다.
        if(genrePlayCount.find(genre) == genrePlayCount.end())
        {
            genrePlayCount[genre] = 0;
            songInfo[genre] = vector<int>();
        }
        
        // 장르별 재생 횟수를 더한다
        genrePlayCount[genre] += (long long)play;
        // 장르별 곡의 아이디를 넣는다.
        songInfo[genre].push_back(id);
    }
    
    // 먼저 수록될 장르를 가리기 위한 장르별 순서
    vector<string> genreOrder;
    
    for(auto it = genrePlayCount.begin(); it != genrePlayCount.end(); ++it)
    {
        genreOrder.push_back(it->first);
    }
    
    sort(genreOrder.begin(), genreOrder.end(), compGenreOrder);
    
    // 재생된 곡이 많은 장르부터 계산한다.
    for(int i = 0, size = genreOrder.size(); i < size; ++i)
    {
        const string& genre = genreOrder[i];
        
        int firstID = 0;
        int secondID = 0;
        int firstPlay = -1;
        int secondPlay = -1;
        
        vector<int> songs = songInfo[genre];
        
        sort(songs.begin(), songs.end(), greater<int>());
        
        for(int j = 0, songSize = songs.size(); j < songSize; ++j)
        {
            int songID = songs[j];
            int play = plays[songID];
            
            if(play >= firstPlay)
            {
                secondID = firstID;
                secondPlay = firstPlay;
                firstID = songID;
                firstPlay = play;
            }
            else if(play >= secondPlay)
            {
                secondID = songID;
                secondPlay = play;
            }
        }
        
        answer.push_back(firstID);
        if(secondPlay > -1)answer.push_back(secondID);
    }
    
    return answer;
}