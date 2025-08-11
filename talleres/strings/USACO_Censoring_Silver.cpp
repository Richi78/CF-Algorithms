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
    vector<int> lps(n+1);

    int prevLPS=0 , i=1;
    while(i<n){
        if(needle[i] == needle[prevLPS]){
            lps[i]=++prevLPS; i++;
        }else if(prevLPS == 0){
            lps[i]=0; i++;
        }else{
            prevLPS=lps[prevLPS-1];
        }
    }
    return lps;
}

void solve(){
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);

    string t,p; cin >> t >> p;

    int sz_text=(int)t.size() , sz_pattern=(int)p.size();
    vector<int> lps=create_lps(p);
    int i=0; // ptr text
    int j=0; // ptr pattern
    vector<int> before(sz_text+1);
    string ans="";
    bool flag=true;
    while(i<sz_text){
        if(flag) ans.push_back(t[i]);
        int n=(int)ans.size();
        if(ans.back() == p[j]){
            before[n-1]=j+1;
            i++; j++; flag=true;
        }else if(j == 0){
            before[n-1]=0;
            i++; flag=true;
        }else{
            j=lps[j-1];
            flag=false;
        }
        if(j == sz_pattern){
            ans.resize(n-sz_pattern);
            if(n-sz_pattern-1>=0) j=before[n-sz_pattern-1];
            else j=0;
            flag=true;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}