#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> d(n);
    vector< pair<int,int> > obs(n);
    for(int i=0 ; i<n ; i++) cin >> d[i];
    for(int i=0 ; i<n ; i++){
        int x,y; cin >> x >> y;
        obs[i]={x,y};
    } 

    int h=0;
    vector<int> carry;
    for(int i=0 ; i<n ; i++){
        int x=obs[i].F , y=obs[i].S , p=d[i];
        if(p != -1){
            h = p + h;
            if(h >= x && h <= y)continue;
            else {
                if(h+carry.size() < x){
                    cout<<-1<<endl; 
                    return;
                }else{
                    auto it=carry.begin();
                    while(h<x){
                        h++;
                        d[*it]=1;
                        it=carry.erase(it);
                    }
                }
            }
        }else{ // p == -1
            int tmp=x-h;
            // con h actual comprobar que no baje

            if(tmp < 0){
                    if(y-h < 0){
                        cout<<-1<<endl; return;
                    }else if(y-h == 0){
                        d[i]=0;
                        continue;
                    }
            }
            if( tmp > 1){
                if(h+carry.size() == x-1){
                    auto it=carry.begin();
                    while(it!=carry.end()){
                        h++;
                        d[*it]=1;
                        it=carry.erase(it);
                    }
                    d[i]=1;
                }else if(h+carry.size() < x){
                    cout<<-1<<endl; 
                    return;
                }else{
                    auto it=carry.begin();
                    while(h<x){
                        h++;
                        d[*it]=1;
                        it=carry.erase(it);
                    }
                    d[i]=0;
                    if(h+1 <= y) carry.push_back(i); 
                }
            }else if(tmp == 0){
                d[i]=0;
                if(h+1 <= y){
                    carry.push_back(i);
                } 
            }else{
                d[i]=1;
                h++;
            } 
        }
    }
    for(auto x : d){
        cout<<x<<" ";
    }
    cout<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}