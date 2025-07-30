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

void solve(){
    string ini,end; cin >> ini >> end;
    int m; cin >> m;
    vector<string> a(m);
    for(int i=0 ; i<m ; i++) cin >> a[i];

    set<string> st(all(a));
    queue<pair<string,int>> q;
    q.push({ini,1});
    while(!q.empty()){
        string s=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(s==end){
            cout<< dist <<"\n"; return;
        }
        for(int i=0 ; i<(int)s.size() ; i++){
            int c=s[i];
            for(int j=0 ; j<26 ; j++){
                s[i]=j+'a';
                if(st.find(s) != st.end()){
                    q.push({s,dist+1});
                    st.erase(s);
                }
            }
            s[i]=c;
        }
    }
    cout<< "-1\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}