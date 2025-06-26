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
    vector<int> a(n) , b(n);
    for(int i=0 ; i<n ; i++){
        double x; cin >> x;
        int y=x*1000;
        a[i]=(y/100)*10; 
        int tmp=(y%100)/10;
        if(tmp>=0 && tmp<=2)tmp=0;
        else if(tmp>=5 && tmp<=7)tmp=5;
        b[i]=tmp;
    }
    
    int ans=accumulate(all(a), 0LL);
    // vdebug(a)
    // vdebug(b)
    vector<int> rest(4);
    for(int i=0 ; i<n ; i++){
        if(b[i]%5 == 0)ans+=b[i]; 
        else{
            if(b[i]==3)rest[0]++;
            else if(b[i]==4)rest[1]++;
            else if(b[i]==8)rest[2]++;
            else if(b[i]==9)rest[3]++;
        }
    }

    // vdebug(rest)
    if(rest[0] && rest[1]){
        int tmp=min(rest[0],rest[1]);
        ans+=5*tmp;
        rest[0]-=tmp; rest[1]-=tmp;
    }

    if(rest[0] && rest[3]){
        int tmp=min(rest[0],rest[3]);
        ans+=10*tmp;
        rest[0]-=tmp; rest[3]-=tmp;
    }

    if(rest[1] && rest[2]){
        int tmp=min(rest[1],rest[2]);
        ans+=10*tmp;
        rest[1]-=tmp; rest[2]-=tmp;
    }

    if(rest[2] && rest[3]){
        int tmp=min(rest[2],rest[3]);
        ans+=15*tmp;
        rest[2]-=tmp; rest[3]-=tmp;
    }

    if(rest[0]>0){
        int x=rest[0]/2 , y=rest[0]%2;
        ans+=5*x; ans+=3*y;
    }

    if(rest[1]>0){
        ans+=4*rest[1];
    }

    if(rest[2]>0){
        int x=rest[2]/2 , y=rest[2]%2;
        ans+=15*x; ans+=8*y;
    }
    
    if(rest[3]>0){
        ans+=9*rest[3];
    }

    // vdebug(rest)
    string res=to_string(ans);
    
    if(res.size()==2){
        cout<<"0."<<res;
    }else{
        for(int i=0 ; i<res.size()-2 ; i++){
            cout<< res[i];
        }
        cout<<"."<<res[res.size()-2]<<res[res.size()-1];
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}