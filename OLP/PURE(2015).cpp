#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

const int BASE = 31;
const llong MOD = 1E9 + 7;
const int MAXN = 1E6 + 7;

llong power[MAXN], h[MAXN];
int m, n;
string s;

llong getHash (int i, int j) {
	return (h[j] - h[i-1] * power[j-i+1] + MOD * MOD) % MOD;
}

bool check (int i, int j, int k) {
	int length = j - i + 1;
	int cnt = length / k;
	if(cnt == 1) {
		return true;
	}
	if(cnt % 2 == 1) {
		if (getHash(i, i + k - 1) != getHash(j - k + 1, j)) {
			return false;
		}
		length -= k;
	}
	if (getHash(i, i + length/2 - 1) != getHash(i + length/2, i + length - 1)) {
		return false;
	}
	return check(i, i + length/2 - 1, k);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> m >> s;
	
	h[0] = s[0]- 'A';
	power[0] = 1;	
	n = s.length();
	
	for (int i = 1; i < n; ++i) {
		power[i] = power[i-1] * BASE % MOD;
		h[i] = (h[i-1] * BASE + s[i] - 'A') % MOD;
	}
	
	bool found = false;
	
	for (int k = 1; k <= m; ++k) {
		int rem = n % k;
		bool ok = true;
		for (int i = 0; i < rem; ++i) {
			if (s[i] != s[n-rem+i]) {
				ok = false;
				break;
			}
		}
		if(!ok) continue;
		if(check(0, n-1-rem, k)) {
			cout << s.substr(0, k) << endl;
			found = true;
			break;
		}		
	}
	if(!found) {
		cout << "-1" << endl;
	}
	return 0;
}

