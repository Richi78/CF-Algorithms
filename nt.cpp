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

void test(vector<int> &a, auto l, auto r){
    vector<int> tmp(l,r);
    for(int i=0; i<tmp.size() ; i++){
        cout<<tmp[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    vector<int> a={1,2,3,4,5};
    auto l=a.begin() , r=a.end();
    test(a,l,r);
}
signed main(){
    FIO;
    int tc;cin>>tc;
    // while(tc--)
    solve();
}



#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define printv(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    // primes
    vector<int> primes;
    for(int i=2 ; i<n ; i++){
        bool isP=true;
        for(int j=2 ; j*j<=i ; j++){
            if(i % j == 0){
                isP=false;
                break;
            }
        }
        if(isP) primes.push_back(i);
    }
    vector<int> ans=a;
    for(int i=0; i<primes.size() ; i++){
        int prime = primes[i];
        vector<int> freq(prime);
        
        int cnt0=0 , cnt1=0;
        for(int j=0 ; j<n ; j++){
            int x = a[j] % prime;
            if(x == 0){
                ans[j]=1;
                cnt0++;
            }else{
                ans[j]=2;
                cnt1++;
            }
        }

        if(cnt0 > 0 && cnt1 > 0){
            cout<<"YES"<<endl;
            for(auto z : ans){
                cout<< z <<" ";
            }
            cout<<endl;
            return;
        }
       
    }
    cout<<"NO"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}