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
    int n; cin >> n;
    string s; cin >> s;
    int cnt=count(all(s), '1');
    if(cnt == 0){
        cout<<"YES\n";
        for(int i=n ; i>=1 ; i--) cout<< i <<" ";
        cout<<"\n"; return;
    }
    s+='1';
    vector<int> a(n+2);
    for(int i=1 ; i<=n+1 ; i++){
        a[i]=i;
    }
    int i=1;
    while(i<=n+1){
        if(s[i-1] == '0'){
            int tmp=i , last=-1;
            while(i+1<=n+1 && s[i-1] == '0' && s[i] == '0'){
                last=a[i+1]; a[i+1]=i; i++;
            }
            if(last == -1){
                cout<<"NO\n"; return;
            }else a[tmp]=last;
        }else{
            a[i]=i;
        }
        i++;
    }
    cout<<"YES\n";
    for(int i=1 ; i<=n ; i++) cout<< a[i] <<" ";
    cout<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}