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

string multiplyBigInt(const string& num1, const string& num2){
	if(num1 == "0" || num2 == "0" || num1 == "-0" || num2 == "-0") 
		return "0";
	bool neg = (num1[0] == '-') ^ (num2[0] == '-');
	int s1 = (num1[0] == '-' || num1[0] == '+') ? 1 : 0;
	int s2 = (num2[0] == '-' || num2[0] == '+') ? 1 : 0;

	vector<long long> a, b;
	for(int i = (int)num1.size() - 1; i >= s1; i--) 
		a.push_back(num1[i]-'0');
	for(int i = (int)num2.size() - 1; i >= s2; i--) 
		b.push_back(num2[i]-'0');

	vector<long long> c = multiply(a, b);

	long long carry = 0;
	string res = "";
	for(size_t i = 0; i < c.size() || carry > 0; i++){
		long long cur = carry + (i < c.size() ? c[i] : 0);
		res.push_back((char)('0' + (cur % 10)));
		carry = cur / 10;
	}
	while(res.size() > 1 && res.back() == '0') res.pop_back();
	if(neg && res != "0") res.push_back('-');
	reverse(res.begin(), res.end());
	return res;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc; cin >> tc;
  while(tc--){
    string s1,s2; cin >> s1 >> s2;
    cout<< multiplyBigInt(s1,s2) <<"\n";
  }
}