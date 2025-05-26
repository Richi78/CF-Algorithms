#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD=1e9+7;

int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a;
        a = (a*a); //% MOD; // si hay un MOD
        b >>= 1;
    }
    return ans;
}

int inv(int a, int m){ // si a y m son coprimos
    int x=binexp(a, m-2);
    return (x+m)%m;
}

signed main(){
    int a=3 , b=5; // 6^4
    int x=binexp(a,b);
    // int x=inv(a,b);
    cout<<x<<endl;
}