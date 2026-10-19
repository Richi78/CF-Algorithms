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

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;
  int n=s.size();
  vector<long long> a(n) , b(n) , c(n);
  for(int i=0 ; i<n ; i++){
    if(s[i] == 'a') a[i]=1;
    else if(s[i] == 'b') b[i]=1;
    else if(s[i] == 'c') c[i]=1;
  }

  vector<long long> invA(a.rbegin() , a.rend());
  vector<long long> invB(b.rbegin() , b.rend());
  vector<long long> invC(c.rbegin() , c.rend());

  vector<long long> fa = multiplyFFT(a,invA);
  vector<long long> fb = multiplyFFT(b,invB);
  vector<long long> fc = multiplyFFT(c,invC);

  long long mx=0;
  int sz=fa.size();
  for(int k=1 ; k<n ; k++){
    int idx = (n-1)+k;
    mx = max(mx , fa[idx] + fb[idx] + fc[idx]);
  }
  cout<< mx <<"\n";
  for(int k=1 ; k<n ; k++){
    int idx = (n-1)+k;
    int tmp = fa[idx] + fb[idx] + fc[idx];
    if(mx == tmp) cout<< k <<" ";
  }
  cout<<"\n";
}