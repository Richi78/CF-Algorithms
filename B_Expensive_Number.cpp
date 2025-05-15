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
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    string n;cin>>n;
    int cnt=0,f=1,len=n.size();
    for(int i=len-1;i>=0;i--){
        char tmp=n[i];
        if(f){
            if(tmp=='0'){cnt++;}
            else if(tmp!='0'){f=0;}
        } else{
            if(tmp!='0')cnt++;
        }
    }
    // while(n>0){
    //     int tmp=(1LL*n)%10;
    //     cout<<tmp<<endl;
    //     if(f){
    //         if(tmp==0){cnt++;}
    //         else if(tmp!=0){f=0;}
    //     } else{
    //         if(tmp!=0)cnt++;
    //     }
    //     n/=10;
    // }
    cout<<cnt<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}