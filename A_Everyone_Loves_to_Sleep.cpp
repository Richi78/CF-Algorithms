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
    int n,h,m;cin>>n>>h>>m;
    
    map<pii,pii> mp;
    forn(i,n){
        int H,M,nH=0,nM=0;cin>>H>>M;
        int tmph=h,tmpm=m;
        if(M>tmpm){
            nM=M-tmpm;
        }else if(M<tmpm){
            nM=60-tmpm+M;
            tmph=(tmph+1)==24?0:tmph+1;
            // h++;
        } 
        if(H>tmph){
            nH=H-tmph;
        }else if(H<tmph){
            nH=24-tmph+H;
        }
        mp[{nH,nM}]={H,M};
    }
    for(auto [x,y]:mp){
        cout<<x.F<<" "<<x.S<<endl;
        return;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}
