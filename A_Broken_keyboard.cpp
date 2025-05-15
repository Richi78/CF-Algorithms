#include <bits/stdc++.h>

using namespace std;

#define int long long int 
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define F first 
#define S second
#define pii pair<int,int>
#define SIZE 100000

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

#define MX 131073

int t, n;
int l, r, h;
int st[MX<<2], dt[MX<<2], overlaps;

void renew( int p ){
	st[p] = max( st[p], dt[p] );
	int next = p << 1;
	dt[next] = max( dt[next], dt[p] );
	dt[next+1] = max( dt[next+1], dt[p] );
	dt[p] = -1;
}

void modify( int p, int L, int R ){
	if( r < L || l > R ) return;
	int M = (L + R) >> 1;
	int next = p << 1;
	if( l <= L && R <= r ){
		dt[p] = max( dt[p], h );
		if( max( dt[p], st[p] ) <= h ){
			renew( p );
			if( L == R ){
				++overlaps;
				return;
			}
			modify( next, L, M );
			modify( next+1, M+1, R );
		}
		return;
	}
	renew( p );
	modify( next, L, M );
	modify( next+1, M+1, R );
	st[p] = min( max( st[next], dt[next] ), max( st[next+1], dt[next+1] ) );
}

signed main(){
    scanf( "%d", &t );
	while(t--){
		scanf( "%d", &n );
		overlaps = 0;
		memset( st, 0, sizeof st );
		memset( dt, -1, sizeof dt );
		for( int i=0; i<n; ++i ){
			scanf( "%d %d %d", &l, &r, &h );
			--r;
			modify( 1, 1, MX-1 );
		}
		printf( "%d\n", overlaps );
	}
}