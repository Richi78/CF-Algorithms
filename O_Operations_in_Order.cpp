#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD=1e9+7;
const int SUM=1;
const int MUL=2;
const int INI=3;

void add_self(int &a, int b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

void mul_self(int &a, int b){
    a=a*b%MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int m=1 , s=0;
    for(int i=0 ; i<n ; i++){
        char type; int val; cin >> type >> val; 
        if(type == '+'){
            add_self(s,val);
        }else if(type == '*'){
            mul_self(m,val);
            mul_self(s,val);
        }else{
            cout<< (m*val%MOD + s)%MOD <<"\n";
        }
    }
    return 0;
}