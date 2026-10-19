#include <bits/stdc++.h>

using namespace std;

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

vector<long long> multiply(const vector<long long>& a, const vector<long long>& b){
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

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s,p; cin >> s >> p;
  long long n=s.size() , m=p.size();
  vector<long long>  a(n) , c(n) , t(n) , g(n);
  vector<long long>  pa(m) , pc(m) , pt(m) , pg(m);
  for(int i=0 ; i<n ; i++){
    if(s[i] == 'A') a[i]=1;
    if(s[i] == 'C') c[i]=1;
    if(s[i] == 'T') t[i]=1;
    if(s[i] == 'G') g[i]=1;
  }
  for(int i=0 ; i<m ; i++){
    if(p[i] == 'A') pa[i]=1;
    if(p[i] == 'C') pc[i]=1;
    if(p[i] == 'T') pt[i]=1;
    if(p[i] == 'G') pg[i]=1;
  }
  vector<long long> PA(pa.rbegin() , pa.rend());
  vector<long long> PC(pc.rbegin() , pc.rend());
  vector<long long> PT(pt.rbegin() , pt.rend());
  vector<long long> PG(pg.rbegin() , pg.rend());

  vector<long long> fa = multiply(a,PA);
  vector<long long> fc = multiply(c,PC);
  vector<long long> ft = multiply(t,PT);
  vector<long long> fg = multiply(g,PG);

  long long mx=0;
  for(int k=0 ; k<=(n-m) ; k++){
    int idx = m-1+k;
    long long tmp=fa[idx]+fc[idx]+ft[idx]+fg[idx];
    mx=max(mx,tmp);
  }
  cout<< m-mx <<"\n";
}