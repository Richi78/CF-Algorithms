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

vector<int> p;

void sieve(int x){
    vector<bool> ans(x+1,1);
    // for(int i=2;i<=x;i++)ans[i]=1;
    ans[0]=0;ans[1]=0;
    for(int i=2;i*i<=x;i++)
        if(ans[i]){
            p.push_back(i);
            for(int j=i*i;j<=x;j+=i)
                ans[j]=0;
        }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    bool one=false;
    for(int i=0 ; i<n ; i++) cin >> a[i], one|=a[i]==1;

    if(one){
        cout<< "2\n"; return;
    }

    int ans=4e18;
    for(int i=0 ; i<n ; i++){
        int x=a[i];
        for(auto y : p){
            if(x%y != 0){
                ans=min(ans,y);
                break;
            }
        }
    }

    if(ans > 1e18){
        cout<<"-1\n";
    }else{
        cout<< ans <<"\n";
    }
}

signed main(){
    FIO;
    sieve(10000);
    int tc;cin>>tc;
    while(tc--)solve();
}