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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

bool f(string &ans, deque<int> &a, vector<int> &tmp){
    bool flag=false;
    while(a.size() != 0){
        int l=a.front() , r=a.back();
        if(a.size() == 1){
            if(l>tmp.back()){
                ans.push_back('L');
                tmp.push_back(l);
                a.pop_front();
                continue;
            }
        }

        if(l<r){
            if(l>tmp.back()){
                ans.push_back('L');
                tmp.push_back(l);
                a.pop_front();
                continue;
            }else if(r>tmp.back()){
                ans.push_back('R');
                tmp.push_back(r);
                a.pop_back();
                continue;
            }else break;
        } 

        if(r<l){
            if(r>tmp.back()){
                ans.push_back('R');
                tmp.push_back(r);
                a.pop_back();
                continue;
            }else if(l>tmp.back()){
                ans.push_back('L');
                tmp.push_back(l);
                a.pop_front();
                continue;
            }else break;
        }

        if(r == l){
            flag=true; break;
        }
    }
    return flag;
}

void solve(){
    int n; cin >> n;
    deque<int> a;
    for(int i=0 ; i<n ; i++){
        int x; cin >> x;
        a.push_back(x);
    } 

    string ans="";
    vector<int> tmp={0};
    bool flag=f(ans,a,tmp);
    if(flag && a.front()>tmp.back()){
        deque<int> copy_a=a;
        int left=1 , last=a.front();
        a.pop_front();
        while(true){
            if(a.front() > last){
                left++;
                last=a.front();
                a.pop_front();
            }else break;
        }
        int right=1;
        last=copy_a.back();
        copy_a.pop_back();
        while(true){
            if(copy_a.back() > last){
                right++;
                last=copy_a.back();
                copy_a.pop_back();
            }else break;
        }
        if(left >= right){
            ans+=string(left,'L');
        }else{
            ans+=string(right,'R');
        }
    }
    cout<< ans.size() <<"\n"<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}