#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    vector<pair<int,string>> V;
    for(int i=0;i<(1<<N);i++){
        string t = bitset<20>(i).to_string().substr(20-N);
        string r = t;
        reverse(r.begin(), r.end());
        int cnt = count(r.begin(), r.end(), '1');
        V.push_back({cnt, r});
    }

    sort(V.begin(), V.end(), [&](auto &a, auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second; // reverse 기준 오름차순
    });

    string RS = S;
    reverse(RS.begin(), RS.end());
    for(int i=0;i<V.size();i++){
        if(V[i].second == RS){
            cout << i << "\n";
            return 0;
        }
    }
}
