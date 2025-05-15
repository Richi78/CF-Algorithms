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
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n ; i++){
        int x; cin >> x;
        if(x) a[i]=1;
        else a[i]=0;
    }
    int idx=-1; bool hasZero=false , othZero=false;
    for(int i=n-2 ; i>=0 ; i--){
        if(a[i] != 0){
            if(idx == -1) idx=i;
        }else{
            if(idx != -1) hasZero=true;
        }
    }
    if(a.back() == 0){
        if(idx == 0){
            cout<<"2\n";
            cout<<"2 "<<n<<"\n";
            cout<<"1 2"<<endl;
        }else if(idx == -1){
            cout<<"3\n";
            cout<<3<<" "<<n<<"\n";
            cout<<"1 2\n";
            cout<<"1 2"<<endl;
        }else if(idx && hasZero){
            cout<<"3\n";
            if(idx+1 == n-1){
                cout<<idx+1<<" "<<n<<"\n";
                cout<<"1 "<<idx<<"\n";
            }else{
                cout<<idx+2<<" "<<n<<"\n";
                cout<<"1 "<<idx+1<<"\n";
            }
            cout<<"1 2"<<endl;
        }else if(idx && !hasZero){
            cout<<"2\n";
            cout<<"2 "<<n<<"\n";
            cout<<"1 2"<<endl;
        }
    }else{
        if(idx == 0){
            cout<<"2\n";
            cout<<"2 "<<n<<"\n";
            cout<<"1 2"<<endl;
        }else if(idx == -1){
            cout<<"2\n";
            cout<<"1 "<<n-1<<"\n";
            cout<<"1 2"<<endl;
        }else if(idx+1<n-1 || hasZero){
            cout<<"2\n";
            cout<<"1 "<<n-1<<"\n";
            cout<<"1 2"<<endl;
        }else if(idx && !hasZero){
            cout<<"1\n"<<"1 "<<n<<endl;
        }
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}