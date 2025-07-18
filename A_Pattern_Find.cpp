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
    string s,p; cin >> s >> p;

    vector<int> lps=create_lps(p);
    // vdebug(lps)
    int sz_text=(int)s.size() , sz_pattern=(int)p.size();
    vector<int> ans;
    int i=0; // ptr text 
    int j=0; // ptr pattern
    while(i < sz_text){
        if(s[i] == p[j]){
            i++; j++;
        }else{
            if(j == 0){
                i++;
            }else{
                j=lps[j-1];
            }
        }
        if(j == sz_pattern){
            ans.push_back(i-sz_pattern);
            j=lps[j-1];
        }
    }
    // vdebug(ans)
    if(ans.empty()){
        cout<< "Not Found\n";
    }else{
        cout<< ans.size() <<"\n";
        for(auto x : ans){
            cout<< x+1 <<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}