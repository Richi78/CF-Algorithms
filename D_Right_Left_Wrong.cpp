#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> pref(n+1);
    for(int i=1 ; i<=n ; i++){
        int x; cin >> x;
        pref[i] = pref[i-1] + x;
    } 

    string s; cin >> s;
    int i=0 , j=n-1 , cnt=0;
    bool end=false;
    while(i<j){
        // debug1(s[i])
        if(s[i] == 'L'){
            while(i<j){
                if(s[j] == 'R'){
                    cnt+=pref[j+1]-pref[i];
                    i++; j--;
                    break;
                }else{
                    j--;
                }
            }
        }else{
            i++;
        }
    }
    cout<<cnt<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

