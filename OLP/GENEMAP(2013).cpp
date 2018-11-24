#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

map<string, int> m1, m2;
llong MOD = 1E9 + 7;

llong sub (llong a, llong b) {
	if (a >= b) return a - b;
	return a - b + MOD;
}

llong add (llong a, llong b) {
	return a + b % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n, k, ls;
	cin >> n >> k;
	
	string s;	
	for(int i = 0; i < n; ++i) {
		cin >> s;
		ls = s.length();
		if (ls >= k) {
			m1[s.substr(0, k) + s.substr(ls - k)]++;
		}
		if (ls > k) {
			m2[s.substr(0, k + 1) + s.substr(ls - k - 1)]++;
		}
	}
	
	llong total = 0;
	for (auto it = m1.begin(); it != m1.end(); ++it) {
//		cout << it->first << ":" << it->second << endl;
		llong count = it->second;
		if (count >= 2) {
			total = add(total, count * (count - 1) / 2 % MOD);
		}
	}
	for (auto it = m2.begin(); it != m2.end(); ++it) {
//		cout << it->first << ":" << it->second << endl;
		int count = it->second;
		if (count >= 2) {
			total = sub(total, count * (count - 1) / 2 % MOD);
		}
	}
	cout << total << endl;
	return 0;
}

