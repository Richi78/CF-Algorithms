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

void solve(){
    int n,q; cin >> n >> q;
    string s; cin >> s;
    s.push_back('#');
    vector<array<int,4>> a;
    int ini=0;
    char type=s[0];
    for(int i=1 ; i<n+1 ; i++){
        if(s[i] != type){
            a.push_back({ini,i-1,type,i-ini});
            ini=i;
            type=s[i];
        }
    }

    
    // for(auto x : a){
        // vdebug(x)
        // }
        
    for(int rep=0 ; rep<q ; rep++){
        int x; cin >> x;
        if(a.size() == 1 && a[0][2]=='A'){
            cout<< x <<"\n"; continue;
        }
        int i=0;
        int sz=a.size();
        int ans=0;
        while(x){
            int s=a[i][0] , e=a[i][1] , cnt=a[i][3];
            char t=a[i][2];
            if(t == 'B'){
                for(int j=0 ; j<cnt && x ; j++){
                    x>>=1LL;
                    ans++;
                }
                i=(i+1)%sz;
            }else {
                if(x>cnt){
                    ans+=cnt;
                    x-=cnt;
                    i=(i+1)%sz;
                }else{
                    ans+=x;
                    break;
                }
            }
        }
        cout<< ans <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}