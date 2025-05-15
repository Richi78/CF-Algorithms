#include <bits/stdc++.h>

using namespace std;

#define int long long int 
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define F first 
#define S second
#define pii pair<int,int>
#define SIZE 100000

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n;cin>>n;
    string a,b;cin>>a>>b;
    map<int,string> s={{0,a},{1,b}};
    for(int i=1;i<n;i++){
        if(s[0][i]==1){
            int j=i;
            int turn=0;
            while(j>=0){
                if(s[!turn][j-1]==0){
                    s[turn][j]='0';
                    s[!turn][j-1]='1';
                    i=0;
                    break;
                } else{
                    turn=!turn;
                    j--;
                }
            }
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;return;

}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}