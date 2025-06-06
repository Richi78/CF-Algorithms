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

int f(vector<int> &a, vector<int> &b, int c,int pos, int n, int last, vector<int> &dp){
    if(pos >= n-2){
        // vdebug(a)
        // vdebug(b)
        // debug2(pos,n-1)
        // debug2(a[pos],b[pos])

        if(last == 1) return dp[pos]=min(a[pos],b[pos]);
        else return dp[pos]=min(a[pos],b[pos]+c);   
    }

    if(dp[pos] != -1) return dp[pos];

    int l= a[pos] + f(a,b,c,pos+1,n,0,dp); // esc
    int r= last == 1 ? 0 : c;
    r += b[pos] + f(a,b,c,pos+1,n,1,dp); // ele
    
    // debug2(a[pos],b[pos])

    return dp[pos] = min(l,r);
}

void solve(){
    int n,c; cin >> n >> c;
    vector<int> a(n-1) , b(n-1);

    for(int i=0 ; i<n-1 ; i++) cin >> a[i];
    for(int i=0 ; i<n-1 ; i++) cin >> b[i];

    // vdebug(a)
    // vdebug(b)

    vector<int> dp(n);
    // f(a,b,c,0,n,2,dp);
    bool used=0 , last=2; // 0 pata 1 elev

    // int l= a[pos] + f(a,b,c,pos+1,n,0,dp); // esc
    // int r= last == 1 ? 0 : c;
    // r += b[pos] + f(a,b,c,pos+1,n,1,dp); // ele

    for(int i=0 ; i<n-1 ; i++){
        int tmp;
        int l=a[i]+
        if(a[i] <= b[i]+c){
            tmp=a[i]; last=0;
        }else{
            tmp=b[i];
            if(!last)tmp+=c;
            last=1;
        }

        dp[i+1]=dp[i] + tmp;
    }
    
    for(auto x : dp){
        cout<< x << " ";
    }
    cout<<endl;
}

signed main(){
    // FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}