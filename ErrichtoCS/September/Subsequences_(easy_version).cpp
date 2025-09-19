#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    string s; cin >> s;

    map<int,int> mp;
    set<string> st;
    st.insert(s);
    mp[s.size()]++;
    queue<string> q;
    q.push(s);
    while(!q.empty()){
        string node=q.front();
        q.pop();
        if(st.size() >= k) break;
        for(int i=0 ; i<node.size() ; i++){
            string tmp=node;
            tmp.erase(i,1);
            if(st.count(tmp) == 0){
                q.push(tmp);
                st.insert(tmp);
                mp[tmp.size()]++;
            }
        }
    }
    if(st.size() < k){
        cout<<"-1\n"; return;
    }
    int ans=0;
    for(auto it=mp.rbegin() ; it!=mp.rend() && k ; it++){
        if(k>=it->second){
            ans+=it->second*(n-it->first);
            k-=it->second;
        }else {
            ans+=k*(n-it->first);
            k=0;
        } 
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}