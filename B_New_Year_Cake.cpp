#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    int a,b; cin >> a >> b;
    int ans=0;
    
    int A=a , B=b;
    for(int rep=0 ; rep<2 ; rep++){
        bool turn=1; // A
        int cur=0;
        int tmpA=0 , addA=1;
        int tmpB=0 , addB=2;
        while(true){
            if(turn){ // A
                if(tmpA+addA <= A){
                    tmpA+=addA; cur++; addA*=4;
                }else break;
            }else{
                if(tmpB+addB <= B){
                    tmpB+=addB; cur++; addB*=4;
                }else break;
            }
            turn=!turn;
            ans=max(ans,cur);
        }
        A=b; B=a;
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}