#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

const int MOD=1e9+7;
const int N=1e6+5;
const int p=-1;
vector<int> fact(N);
vector<int> invFact(N);

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int open=0, closed=0;
    for(auto c : s){
        if(c == '(') open++;
        else closed++;
        if(closed > open){
            cout<<"0\n"; return;
        }
    }
    if(n&1 ||closed>open || open>n/2){
        cout<<"0\n"; return;
    }

    if(closed+open == n){
        cout<<"1\n"; return;
    }    

    int A1=n-s.size() , B1=(open-closed)-0;
    int x1=(A1+B1)/2;
    int w1= ( fact[A1]*invFact[x1] )%MOD * invFact[A1-x1] %MOD;

    int A2=n-s.size() , B2=2*p-B1;
    int x2=(A2+B2)/2;
    int w2= ( fact[A2]*invFact[x2] )%MOD * invFact[A2-x2] %MOD;
    if(x2<0 || x2>A2) w2=0;

    cout<< (w1 - w2 + MOD)%MOD <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    fact[0]=1;
    for(int i=1 ; i<N ; i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    for(int i=0 ; i<N ; i++){
        invFact[i]=binexp(fact[i], MOD-2);
    }
    solve();
}