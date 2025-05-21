#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    if(n&1){
        vector<int> a(n);
        int x=n/2 , mex=2;
        bool turn=1;
        a[x]=1;
        for(int i=1 ; i<=n-1 ; i++){
            if(turn){
                x=x+i;
                a[x]=mex;
            }else{
                x=x-i;
                a[x]=mex;
            }
            mex++; turn=!turn;
        }
        for(auto y : a) cout<< y << " ";
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

