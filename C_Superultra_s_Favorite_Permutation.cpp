#include <bits/stdc++.h>

using namespace std;

#define int long long
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

bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return x>=2;
}

void solve(){
    int n;cin>>n;
    stack<int> s;
    queue<int> ans;
    int last;
    for(int i=1;i<=n;i=i+2){
        ans.push(i);last=i;
    }
    // cout<<"las"<<endl;
    // cout<<last<<endl;
    int f=0, last_even;
    for(int i=2;i<=n;i=i+2){
        if(isPrime(last+i))s.push(i);
        else {last_even=i;f=1;break;}
    }
    if(f){
        for(int i=last_even;i<=n;i=i+2)ans.push(i);
        while(!s.empty()){
            ans.push(s.top());
            s.pop();
        }
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }else cout<<-1;
    cout<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}