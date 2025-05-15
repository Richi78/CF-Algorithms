#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define input(x) cin >> x
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ilz(x) 64-__builtin__clzll(x)-1   //usar -1 para shifts, solo index quitar -1


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; char t; cin >> n >> t;
    map<char, set<int> > mp;
    map<char, int> sum;
    for(int i=0 ; i<2*n ; i++){
        string s; cin >> s;
        mp[s[1]].insert(s[0]);
        sum[s[1]]++;
    }
    for(auto [k,v] : sum){
        if(k!=t){
            if(v & 1){
                if(sum[t])sum[t]--;
                else {cout<<"IMPOSSIBLE"<<endl; return;}
            }
        }
    }
    if(sum[t]&1){cout<<"IMPOSSIBLE"<<endl; return;
    }
    vector< pair<char, set<int>> > a;
    for(auto [k,v] : mp) {
        if(k != t) a.push_back({k,v});
    }
    a.push_back({t,mp[t]});

    vector< pair<string,string> > ans;

    for(auto [k,v] : a){
        if(v.size() & 1){
            if(k == t){
                cout<<"IMPOSSIBLE"<<endl; return;
            }else{
                if(mp[t].size() == 0){
                    cout<<"IMPOSSIBLE"<<endl; return;
                }else{
                    auto it1=v.begin() , it2=a.back().second.begin();
                    string tmp1=string(1,*it1)+k , tmp2=string(1,*it2)+t;
                    ans.push_back({tmp1,tmp2});
                    v.erase(it1); a.back().second.erase(it2);
                }
            }
        }
        auto it1=v.begin() , it2=v.begin();
        string tmp1="" , tmp2="";
        while(v.size() != 0){
            it1=v.begin(); it2=next(v.begin());
            tmp1=string(1,*it1)+k; tmp2=string(1,*it2)+k;
            v.erase(v.begin()); v.erase(v.begin());
            ans.push_back({tmp1,tmp2});
        }
    }
    for(auto [x,y] : ans){
        cout<<x<<" "<<y<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}