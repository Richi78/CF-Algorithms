// #include <bits/stdc++.h>

// using namespace std;

// #define debug1(x) cout << #x << " = " << x << "\n";
// #define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
// #define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
// #define int long long
// #define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define all(v) v.begin(),v.end()
// // const int MOD=998244353;

// template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
// template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

// void solve(){
    
// }

// signed main(){
//     FIO;
//     // freopen("censor.in", "r", stdin);
//     // freopen("censor.out", "w", stdout);
//     // int tc;cin>>tc;
//     // while(tc--)solve();
//     solve();
// }
#include<iostream>
#include<cassert>
using namespace std;
int N,M;
int A[2<<17],B[2<<17];
int L[2<<17],R[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<M;i++)cin>>B[i];
		L[0]=-1;
		for(int i=0;i<M;i++)
		{
			L[i+1]=L[i]+1;
			while(L[i+1]<N&&A[L[i+1]]<B[i])L[i+1]++;
		}
		R[M]=N;
		for(int i=M;i--;)
		{
            cout<<"i: "<<i<<"\n";
			R[i]=R[i+1]-1;
			while(R[i]>=0&&A[R[i]]<B[i])R[i]--;
		}
        for(int i=0 ; i<=M ; i++){
            cout<< L[i] <<" ";
        }
        cout<<"\n";
        for(int i=0 ; i<=M ; i++){
            cout<< R[i] <<" ";
        }
        cout<<"\n";
		int ans=2e9;
		if(L[M]<N)ans=0;
		for(int i=0;i<M;i++)
		{
			if(L[i]+1<=R[i+1])ans=min(ans,B[i]);
		}
		if(ans==(int)2e9)ans=-1;
		cout<<ans<<"\n";
	}
}
