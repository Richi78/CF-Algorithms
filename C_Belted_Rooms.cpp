#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int N = 300e3 + 7;
// vector<int> g[N];

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<char,int> mp;
    for(int i=0 ; i<s.size() ; i++){
        mp[s[i]]++;
    }
    if(mp['>'] == 0 || mp['<'] == 0) cout<<n<<endl;
    else if(mp['-'] == 0) cout<<0<<endl;
    else{
        vector<bool> ret(n,0);
        for(int i=0 ; i<n ; i++){
            if(s[i] == '-'){
                ret[i]=1;
                ret[(i+1)%n]=1;
            }
        }
        cout<<count(all(ret),1)<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}