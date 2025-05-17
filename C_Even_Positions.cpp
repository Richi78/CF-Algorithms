#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt=0, open=0 , closed=0;
    stack< int > a;

    for(int i=0 ; i<n ; i++){
        int c=s[i];
        if(c == '_'){
            if(open == 0){
                open++;
                a.push(i+1);
            }else if(open > 0){
                open--;
                int tmp=a.top();
                a.pop();
                cnt+=i+1-tmp;
            }
        }else if(c == '('){
            open++;
            a.push(i+1);
        }else if(c == ')'){
            open--;
            int tmp=a.top();
            a.pop();
            cnt+=i+1-tmp;
        }
    }
    cout<<cnt<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


