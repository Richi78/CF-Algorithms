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

const int MX=2e5+5;
string s;
vector<int> a(MX) , dp(MX,-1);

// time limit con variante recursiva
int dfs(int source, int o, int cnt){
    if(a[source] == o) 
        return dp[source]=cnt + (s[source-1] == '0');
        
    if(dp[source] != 0) return dp[source];

    int x;
    if(s[source-1] == '0')
        x=dfs(a[source] , o , cnt+1);
    else 
        x=dfs(a[source] , o , cnt);

    return dp[source]=x;
}

void solve(){
    int n; cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
        dp[i]=-1;
    }
    cin >> s;

    for(int i=1 ; i<=n ; i++){
        if(dp[i] != -1){
            cout<< dp[i] << " "; continue;
        }
        int cnt=0 , o=i , tmp=i;
        if(a[tmp] == o){
            dp[tmp] = (s[tmp-1]=='0'); 
            cout<< dp[tmp]<<" "; continue;
        }
        set<int> aux={tmp};
        while(a[tmp] != o){
            cnt+= (s[tmp-1] == '0');
            aux.insert(tmp);
            tmp=a[tmp];
            if(a[tmp]==o){
                cnt+= (s[tmp-1] == '0');
                aux.insert(tmp);
            }
        }
        for(auto x : aux) dp[x]=cnt;

        cout<< dp[i] <<" ";
    }

    cout<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}