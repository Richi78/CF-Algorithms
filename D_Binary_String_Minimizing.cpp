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
    int n,k; cin >> n >> k;
    string s; cin >> s;

    int tmp=0;
    for(int i=0 ; i<n ; i++){
        if(i>tmp)tmp=i;
        if(s[i]=='1'){
            while(tmp<n && s[tmp]=='1')tmp++;
            if(tmp==n)break;
            
            if(tmp-i <= k){
                s[tmp]='1';
                s[i]='0';
                k-=(tmp-i);
            }else{
                s[tmp]='1';
                s[tmp-k]='0';
                k=0;
                break;
            }
            // debug1(k)
            // debug1(s)
        } 
    }
    cout<< s <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}