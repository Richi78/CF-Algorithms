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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector< array<int,2> > a;
    for(int i=0 ; i<n ; i++){
        int x; string s; cin >> x >> s;
        int tmp= s[1]-'0' + 2*(s[0]-'0');
        a.push_back({tmp,x});
    }
    // sort(all(a));
    int cnt1=1e9 , cnt2=1e9 , cnt3=1e9 ;
    for(auto [x,y] : a){
        if(x==3){
            cnt3=min(cnt3,y);
        }
        if(x==2){
            cnt1=min(cnt1,y);
        }
        if(x==1){
            cnt2=min(cnt2,y);
        }
    }
    // if(cnt3 != 1e9) {cout<<cnt3<<endl; return;}
    if(cnt3 == 1e9 && (cnt1==1e9 || cnt2==1e9)) cout<<-1<<endl;
    else cout<< min(cnt3,cnt1+cnt2) <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}