#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define input(x) cin >> x
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ilz(x) 64-__builtin__clzll(x)-1   //usar -1 para shifts, solo index quitar -1


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){

}

signed main(){
    FIO;
    string s;cin>>s;
    int len=s.size();
    vector<int> dp={0,0};
    // dp[0] -> means "AB" substring
    // dp[1] -> means "BA" substring
    // first search for "AB" then "BA" pattern 
    for(int i=1;i<len;i++){
        if(dp[0]==0 && s[i]=='B' && s[i-1]=='A'){
            dp[0]=1; i++; 
        }
        else if(dp[0]==1 && s[i]=='A' && s[i-1]=='B'){
            dp[1]=1; i++;
        }
        if(dp[0] && dp[1]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    dp={0,0};
    // now first search for "BA" and then "AB" patter
    // a nice case the last loop doesnt work on its own is ABAXXXAB
    // it finds AB first then doesnt find BA and return NO while
    // the correct answer is YES because of the first BA
    for(int i=1;i<len;i++){
        if(dp[0]==0 && s[i]=='A' && s[i-1]=='B'){
            dp[0]=1; i++;
        }else if(dp[0]==1 && s[i]=='B' && s[i-1]=='A'){
            dp[1]=1; i++;
        }
        if(dp[0] && dp[1]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}