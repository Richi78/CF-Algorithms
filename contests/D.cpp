#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const string OK="All OK";
const string One="1 Point(s) Deducted";
const string Two="2 Point(s) Deducted";
const string Three="3 Point(s) Deducted";
const string Issue="Issue Show Cause Letter";
map<int,string> mp={
    {0,OK} , {1,One} , {2,Two} , {3,Three}
};

struct Hour{
    int s;
    Hour(int x=0,int y=0, int z=0){
        s=x*3600+y*60+z; 
    }

    void show(){
        cout<< "S: "<< s <<"\n";
    }

    void cut(){
        if(s<30'600){ // 8h 30m
            s=30'600;
        }
    }

    bool operator <(const Hour &b) const {
        return s<b.s;
    }

    bool operator >(const Hour &b) const {
        return s>b.s;
    }

    Hour operator-(const Hour &b) const {
        int diff=s-b.s;

        if (diff < 0) diff = -diff; // abs

        return Hour(0,0,diff);
    }
};

struct Desc{
    char type;
    Hour ini;
    Hour fin;
    vector<int> a;
    void read(string &s){
        string tmp="";
        for(int i=2 ; i<(int)s.size() ; i++){
            if(s[i] == ':'){
                a.push_back(stoll(tmp));
                tmp="";
            }else{
                tmp+=s[i];
            }
        }
        a.push_back(stoll(tmp));

        type=s[0];
        ini=Hour(a[0],a[1],a[2]);
        fin=Hour(a[3],a[4],a[5]);
    }

    void show(){
        cout<< "Type: "<<type<<"\n";
        ini.show();
        fin.show();
    }
};

const Hour inD(9,30,0);
const Hour inE(12,30,0);

const Hour minD(8,0,0);

const Hour minE(9,0,0);

void solve(int n){
    vector<Desc> a;
    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        Desc x;
        x.read(s);
        a.push_back(x);
    }
    // for(auto x : a){
        // x.show();
    // }
    int cnt=0;
    for(Desc x : a){
        x.ini.cut();
        if(x.type == 'D'){
            if(x.ini > inD){
                cnt++;
            }else if((x.fin-x.ini) < minD){
                cnt++;
            }
        }else{
            if(x.ini > inE){
                cnt++;
            }else if((x.fin-x.ini) < minE){
                cnt++;
            }
        }
    }
    if(cnt > 3) cout<< Issue <<"\n";
    else cout<< mp[cnt] <<"\n";

}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int x;
    while(true){
        cin >> x;
        if(x == 0) break;
        solve(x);
    }
}