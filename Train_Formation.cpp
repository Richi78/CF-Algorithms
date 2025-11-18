#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

//    pos  aa  ab  ba  bb last
int dp[41][41][41][41][41][2]={};

void solve(){
    int n,k; cin >> n >> k;
    string loc; cin >> loc;
    int AA=0 , AB=0 , BA=0 , BB=0;
    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        if(s=="AA") AA++;
        else if(s=="AB") AB++;
        else if(s=="BA") BA++;
        else BB++;
    }
    {
        int last= (loc[1]=='A'?0:1);
        dp[0][0][0][0][0][last]=1;
    }
        
    for(int pos=0 ; pos<k ; pos++)
    for(int aa=0 ; aa<=AA ; aa++)
    for(int ab=0 ; ab<=AB ; ab++)
    for(int ba=0 ; ba<=BA ; ba++)
    for(int bb=0 ; bb<=BB ; bb++)
    for(int last=0 ; last<=1 ; last++){
        int me=dp[pos][aa][ab][ba][bb][last];
        if(last == 0){ // A
            if(aa<AA)
                dp[pos+1][aa+1][ab][ba][bb][0]+=me;
            if(ab<AB)
                dp[pos+1][aa][ab+1][ba][bb][1]+=me;
        }else{ // B
            if(ba<BA)
                dp[pos+1][aa][ab][ba+1][bb][0]+=me;
            if(bb<BB)
                dp[pos+1][aa][ab][ba][bb+1][1]+=me;
        }
    }

    int target= (loc[0]=='A'?0:1);
    int ans=0;
    for(int aa=0 ; aa<=AA ; aa++)
    for(int ab=0 ; ab<=AB ; ab++)
    for(int ba=0 ; ba<=BA ; ba++)
    for(int bb=0 ; bb<=BB ; bb++){
        ans+=dp[k][aa][ab][ba][bb][target];
    }
    if(ans == 0){
        cout<< "NO\n";
    }else{
        cout<< "YES\n" << ans <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}