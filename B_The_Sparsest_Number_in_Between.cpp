#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int a,b; cin >> a >> b;

    int cntA = 64 - __builtin_clzll(a) -1;
    int cntB = 64 - __builtin_clzll(b) -1;
    if( cntA != cntB ){
        int y;
        while(cntB--){
            y = 1LL << cntB;
            if(y < a || y > b){
                y <<= 1LL; break;
            }
        }
        cout<< y <<endl;
    }else{
        debug2(cntA,cntB)
        int n=0 , mn=1e18+5;
        bool f=1;
        while(cntA>=0){
            if(f) n |= (1LL << cntA);
            if(n>=a){
                f=0;
                cout<<"mayor que a: "<<n<<endl;
                mn=min(mn,n);
                int tmp=n , tmp2;
        
                // cout<<"WHILE"<<endl;
                tmp = tmp & ~(1LL << cntA);
                tmp2= tmp | (1LL << (cntA-1));
                debug2(tmp,tmp2)
                if(tmp2 >= a){
                    n=tmp2;
                }else n=tmp;

                // cntA--;
                // n = n & ~(1LL << cntA);
            }
            // debug1(n)
            debug1(n)
            cntA--;
        }
        // mn= n;
        // cntA++;
        // n = n & ~(1LL << cntA);
        // // debug1(n)
        // // n ^= (1<<cntA);
        // int tmp=cntA-1;
        // // debug1(tmp)
        // while(tmp >= 0){
        //     int x = n | (1LL << tmp);
        //     // debug1(x)
        //     if(x < mn && x >= a){
        //         mn = x;
        //     }
        //     tmp--;
        // }
        // cout<<mn<<endl;
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}