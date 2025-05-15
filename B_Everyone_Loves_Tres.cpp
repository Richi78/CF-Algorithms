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

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

int digits(int x){
    int cnt=0;
    while(x>0){
        int tmp=x%10;
        if(tmp!=3 && tmp!=6)return 0;
        x/=10;
        cnt++;
    }
    return cnt;
}

void solve(){
    int n;cin>>n;
    vector<string> a={"66","36366"};
    string s;
    if(n==1||n==3){cout<<-1<<endl;return;}
    else{
        if(n&1){
            s.resize(n-5,'3');
            s+=a[1];
        }else{
            s.resize(n-2,'3');
            s+=a[0];
        }
    }
    cout<<s<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    // vi a(12);
    // int cnt=1;
    // while(cnt<100000){
    //     int tmp=66*cnt;
    //     int idx=digits(tmp);
    //     if(idx!=0&&tmp%33==0&&tmp%66==0){a[idx]=(tmp);cnt*=10;}
    //     cnt++;
    // }
    // printv(a);
    while(tc--)solve();
}
