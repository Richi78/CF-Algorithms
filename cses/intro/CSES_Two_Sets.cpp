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

void solve(){
    int n; cin >> n;
    int sum=n*(n+1)/2;
    if(sum&1){
        cout<< "NO\n"; return;
    }
    int acc1=0 , acc2=0;
    vector<int> a , b;
    int i=n;
    while(acc1 + acc2 != sum){
        if(acc1+i <= sum/2){
            a.push_back(i); 
            acc1+=i;
            i--;
        }else{
            b.push_back(i);
            acc2+=i;
            i--;
        }
    }

    cout<< "YES\n";
    cout<< a.size() <<"\n";
    for(int i=0 ; i<(int)a.size() ; i++){
        cout<< a[i] <<" ";
    }
    cout<< "\n" << b.size() << "\n";
    for(int i=0 ; i<(int)b.size() ; i++){
        cout<< b[i] <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}