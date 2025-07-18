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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

vector<int> create_lps(string &needle){
    int n=(int)needle.size();
    vector<int> lps(n);

    int prevLPS=0 , i=1;
    while(i<n){
        if(needle[i] == needle[prevLPS]){
            lps[i]=prevLPS+1;
            prevLPS++; i++;
        }else if(prevLPS == 0){
            lps[i]=0; i++;
        }else{
            prevLPS=lps[prevLPS-1];
        }
    }
    return lps;
}

void solve(){
    string s="AAACAAAAA";

    vector<int> lps=create_lps(s);
    vdebug(lps)
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}