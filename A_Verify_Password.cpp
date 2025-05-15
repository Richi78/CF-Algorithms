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
    int n; cin >> n;
    string s; cin >> s;

    if(s[0] - 'a' < 0){
        bool isnum=1;
        for(int i=1; i<n ; i++){
            if(isnum){
                if(s[i] - 'a' >= 0){
                    isnum=0;
                }else if(s[i] < s[i-1]){
                    cout<<"NO"<<endl; 
                    return;
                }
            }else{
                if(s[i] < s[i-1]){
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
        cout<<"YES"<<endl;
    }else{
        for(int i=1 ; i<n ; i++){
            if(s[i] - 'a' <0){
                cout<<"NO"<<endl;
                return;
            }else if(s[i] < s[i-1]){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}