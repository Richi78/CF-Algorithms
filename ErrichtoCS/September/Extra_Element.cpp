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
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        a[i-1]={x,i};
    } 
    sort(all(a));

    if(n == 2){
        cout<< "1\n"; return;
    }

    int j=1;
    for(int rep=0 ; rep<2 ; rep++){
        int pos_r=a[2].first - a[j].first;
        int factor=1;
        bool ok=true;
        for(int i=2 ; i<n ; i++){
            int x=a[j].first+(pos_r*factor);
            if(x == a[i].first) factor++;
            else{
                ok=false;
                break;
            }
        }
        if(ok){
            cout<< a[j^1].second <<"\n"; return;
        }
        j--;
    }

    int pos_r=a[1].first - a[0].first;
    int factor=2;
    int ans=-1;
    for(int i=2 ; i<n ; i++){
        int x=a[0].first + (pos_r*factor);
        if(x == a[i].first) factor++;
        else if(ans == -1) ans=a[i].second;
        else {
            cout<<"-1\n"; return;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}