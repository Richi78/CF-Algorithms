#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<bool> valid(26);
    for(int i=0 ; i<k ; i++){
        char x; cin >> x;
        valid[x-'a']=true;
    }    

    int ans=0;
    int cnt=0;
    for(int i=0 ; i<n ; i++){
        if(valid[s[i]-'a']) cnt++;
        else{
            ans+=cnt*(cnt+1)/2;
            cnt=0;
        }
    }
    ans+=cnt*(cnt+1)/2;
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}