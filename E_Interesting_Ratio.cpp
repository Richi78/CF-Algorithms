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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

vector<int> sieve(int x){
    vector<int> ans(x+1,1);
    ans[0]=0;ans[1]=0;
    for(int i=2;i*i<=x;i++)
        if(ans[i]){   
            for(int j=i*i;j<=x;j+=i)
                ans[j]=0;
        }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> s=sieve(n);

    int cnt=0;
    // vector<int> ans(x+1,1);
    // ans[0]=0;ans[1]=0;
    // for(int i=2;i*i<=x;i++)
    //     if(ans[i]){   
    //         for(int j=i*i;j<=x;j+=i)
    //             ans[j]=0;
    //     }

    for(int i=1 ; i<=n ; i++){
        for(int j=i+i ; j<=n ; j+=i){
            int x=gcd(i,j);
            if(s[ (i*j)/(x*x) ]) cnt++;
        }
    }
    cout<< cnt <<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}