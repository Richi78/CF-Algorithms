#include <bits/stdc++.h>

using namespace std;

struct DSU{
  vector<int> parent,sz;
  int groups;
  DSU(int n){
    parent.resize(n); sz.resize(n,1);
    for(int i=0 ; i<n ; i++) parent[i]=i;
    groups=n;
  }
  int find(int node){
    if(node == parent[node]) return node;
    return parent[node] = find(parent[node]);
  }
  void unite(int a, int b){
    int A=find(a) , B=find(b);
    if(A == B) return;
    groups--;
    if(sz[A] > sz[B]){
      sz[A]+=sz[B];
      parent[B]=A;
    }else{
      sz[B]+=sz[A];
      parent[A]=B;
    }
  }
};

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert){
	int n = a.size();
	// bit-reversal permutation
	for(int i=1,j=0;i<n;i++){
		int bit = n >> 1;
		for(; j&bit; bit>>=1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(int len=2; len<=n; len<<=1){
		double ang = 2 * PI / len * (invert ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for(int i=0; i<n; i+=len){
			cd w(1);
			for(int j=0; j<len/2; j++){
				cd u = a[i+j], v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if(invert){
		for(cd& x : a) x /= n;
	}
}

vector<long long> multiplyFFT(const vector<long long>& a, const vector<long long>& b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while(n < (int)a.size() + (int)b.size()) n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for(int i=0;i<n;i++) fa[i] *= fb[i];
	fft(fa, true);
	vector<long long> res(n);
	for(int i=0;i<n;i++) res[i] = (long long)llround(fa[i].real());
	return res;
}

bool has_edge[6][6][125010];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s,t; cin >> s >> t;
  int n=s.size() , m=t.size();

  vector<vector<long long>> S(6,vector<long long>(n));
  vector<vector<long long>> T(6,vector<long long>(m));  
  for(int i=0 ; i<n ; i++) S[s[i]-'a'][i]=1;
  for(int i=0 ; i<m ; i++) T[t[i]-'a'][m-1-i]=1;

  vector<vector<long long>> C;
  for(int i=0 ; i<6 ; i++)
    for(int j=i+1 ; j<6 ; j++){
      auto r1 = multiplyFFT(S[i],T[j]);
      auto r2 = multiplyFFT(S[j],T[i]);

      for(int k=0 ; k<=n-m ; k++){
        int idx=m-1+k;
        if(r1[idx] + r2[idx] > 0){
          has_edge[i][j][k] = true;
        }
      }
    }

  for(int k = 0; k <= n - m; k++){
    DSU dsu(6);
    for(int u = 0; u < 6; u++){
        for(int v = u + 1; v < 6; v++){
            if(has_edge[u][v][k]){
                dsu.unite(u, v);
            }
        }
    }
    cout << 6 - dsu.groups << " ";
  }
  cout << "\n";
  
}