#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void dfs(string &node, string &begin, map<string,vector<string>> &adj, vector<string> &tmp, set<vector<string>> &ans){
    tmp.push_back(node);
    if(node == begin){
        ans.insert(tmp);
    }
    for(auto adjN : adj[node]){
        dfs(adjN, begin, adj, tmp, ans);
    }
    tmp.pop_back();
}

void solve(){
    string beginWord,endWord; cin >> beginWord >> endWord;
    int n; cin >> n;
    vector<string> wordList(n);
    for(int i=0 ; i<n ; i++) cin >> wordList[i];

    set<string> st(wordList.begin() , wordList.end());
    st.erase(beginWord);

    map<string , vector<string>> adj;
    queue<pair<string,int>> q;
    q.push({beginWord,0});
    set<string> to_erase;
    while(!q.empty()){
        string tmp=q.front().first;
        int level=q.front().second;
        string s=tmp;
        q.pop();
        if(s==endWord) continue;
        for(int i=0 ; i<(int)s.size() ; i++){
            char c=s[i];
            for(int j=0 ; j<26 ; j++){
                s[i]=j+'a';
                if(st.count(s) != 0){
                    q.push({s,level+1});
                    to_erase.insert(s);
                    adj[s].push_back(tmp);
                }
            }
            s[i]=c;
        }
        if(!q.empty() && q.front().second != level){
            for(auto x : to_erase) st.erase(x);
            to_erase.clear();
        }
    }

    set<vector<string>> ans;
    vector<string> tmp;
    dfs(endWord, beginWord, adj, tmp, ans);
    vector<vector<string>> ans2;
    for(auto &x : ans){
        tmp=x;
        reverse(tmp.begin() , tmp.end());
        ans2.push_back(tmp);
    }
    // return ans;
    for(auto x : ans2){
        vdebug(x)
    }
    // no es tan optimo xd, modificar
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}