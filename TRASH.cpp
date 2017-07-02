#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b) 	for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)	for(int i = (a), _b = (b); i >= _b; --i)

#define endl 		"\n"
#define newline 	cout << "\n"
#define long 		long long

using namespace std;

const int SIZE = 1E6+7;

int a[SIZE], sum[SIZE];

inline int getsum(int i, int j) {
	return sum[j] - sum[i-1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
	freopen ("input.txt", "r", stdin);
#endif
	int n, t;
	cin >> n >> t;
	FOR(i, 1, n) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	long ans = 0;
	FOR(i, 1, n) {
		if(a[i] > t) continue;
		int l = min(i+1, n), r = n;
		while(l < r) {
			int m = (l+r)>>1;
			if(getsum(i, m) == t) break;
			if(getsum(i, m) < t) l = m+1;
			else r = m-1;
		}
		ans += r - i + 1;
	}
	cout << ans << endl;
	return 0;
}
