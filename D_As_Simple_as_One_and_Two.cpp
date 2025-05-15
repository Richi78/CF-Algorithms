#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    string s; cin >> s;
    int sz=s.size();
    vector<int> ans;
    for(int i=1 ; i+1<sz ; i++){
        if(s[i-1] == 'o' && s[i] == 'n' && s[i+1] == 'e'){
            ans.push_back(i+1);
        }else if(s[i-1] == 't' && s[i] == 'w' && s[i+1] == 'o'){
            if( (i+3) < sz && s[i+2] == 'n' && s[i+3] == 'e' ){
                ans.push_back(i+1+1);
                i+=2;
            }else{
                ans.push_back(i+1);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x : ans){
        cout<< x << " ";
    }
    cout<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}