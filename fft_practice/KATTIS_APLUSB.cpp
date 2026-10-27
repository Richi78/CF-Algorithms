#include <bits/stdc++.h>

using namespace std;

const long long N=100'010;
const long long K=50'000;

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

  int n; cin >> n;
  vector<int> a(n);
  vector<long long> freq(N);
  for(int i=0 ; i<n ; i++){
    cin >> a[i]; freq[a[i]+K]++;
  }

  vector<long long> C = multiplyFFT(freq,freq);
  for(int i=0 ; i<n ; i++) C[2*a[i]+2*K]--;
  int zeros=freq[K];
  long long ans=0;
  for(int k=0 ; k<n ; k++){
    long long tmp = C[a[k]+2*K];
    if(a[k] == 0){
      tmp-=2LL*(zeros-1);
    }else{
      tmp-=2LL*zeros;
    }
    ans+=tmp;
  }
  cout<< ans <<"\n";
}