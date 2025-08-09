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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    vector<int> a={4,8,15,16,23,42};
    vector<int> ans(6);
    int pos1=1 , pos2=2 ,pos3=3;
    
    for(int rep=0 ; rep<2 ; rep++){
        cout<< "? "<< pos1 <<" "<< pos2 <<endl;
        int x; cin >> x;
        cout<< "? "<< pos1 <<" "<< pos3 <<endl;
        int y; cin >> y;
        bool ok=true;
        int A,B;
        for(int i=0 ; i<6 && ok ; i++){
            for(int j=0 ; j<6 && ok ; j++){
                if(i!=j && a[i]*a[j] == x){
                    A=a[i]; B=a[j];
                    ok=false;
                }
            }
        }
        for(int i=0 ; i<6 ; i++){
            if(a[i]!=A && A*a[i] == y){
                ans[pos1-1]=A;
                ans[pos2-1]=B;
                ans[pos3-1]=a[i];
                break;
            }
            if(a[i]!=B && B*a[i] == y){
                ans[pos1-1]=B;
                ans[pos2-1]=A;
                ans[pos3-1]=a[i];
                break;
            }
        }
        pos1=4; pos2=5; pos3=6;
    }
    cout<< "! ";
    for(auto x : ans) cout<< x <<" ";
    cout<<endl;
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}