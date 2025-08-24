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
    cout << setprecision(8) <<fixed;
    double P,R,Y; cin >> P >> R >> Y;
    vector<vector<double>> a(3, vector<double>(4));
    double c=(P+R+Y)/2;
    // n == e
    a[0][0]=a[0][1]=c/2;
    a[0][2]=a[0][0]-R;
    a[0][3]=a[0][1]-P;

    // e == 0
    a[1][0]=c;
    a[1][1]=0;
    a[1][2]=a[1][0]-R;
    a[1][3]=a[1][1]-P;

    // n == 0
    a[2][0]=0;
    a[2][1]=c;
    a[2][2]=a[2][0]-R;
    a[2][3]=a[2][1]-P;


    // for(auto x : a){
        // vdebug(x)
    // }
    vector<double> b(3);
    for(int i=0 ; i<3 ; i++){
        double tmp=-10;
        for(auto x : a[i]){
            uax(tmp,abs(x));
        }
        b[i]=tmp;
    }

    int idx=min_element(all(b)) - b.begin();

    cout<< a[idx][0] <<" "<< a[idx][1] <<" "<< a[idx][2] <<" "<< a[idx][3]<<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}

