#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b) 	for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)	for(int i = (a), _b = (b); i >= _b; --i)
#define FILL(a, v, n)	for(int i = 0, _n = (n); i < _n; ++i) a[i] = v

#define pr(x) 		cout << #x << " = " << x << endl
#define pra(a, n)	REP(i, 0, n) cout << #a << "[" << i << "] = " << a[i] << " "; cout << "\n"
#define sz(x)		(int)(x.size())
#define endl 		"\n"
#define newline 	cout << "\n"

#define getBit(num, ith) 		((num >> (ith)) & 1)
#define toggleBit(num, ith)	(num ^ (1>>(ith)))
#define OffBit(num, ith)		(num & (~(1<<(ith))))
#define OnBit(num, ith)			(num | (1<<(ith)))

using namespace std;
const int N = 10005;
const int INF = 1E9;

int state[8] = {0, 1, 2, 4, 8, 5, 9, 10};
int dp[N][20];
int m[5][N];

inline int getSum(int c, int mask) {
	int res = 0;
	FOR(i, 1, 4) {
		if(getBit(mask, i-1)) res += m[i][c];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
	freopen ("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	bool pig = true;
	int vmax = INT_MIN;
	FOR(i, 1, 4) {
		FOR(j, 1, n) {
			cin >> m[i][j];	
			if(m[i][j] > 0) pig = false;
			vmax = max(vmax, m[i][j]);
		}
	}
	if(pig) {
		cout << vmax << endl;
		return 0;
	}
	REP(i, 0, 8) {
		dp[1][state[i]] = max(0, getSum(1, state[i]));
	}
	
	FOR(c, 2, n) {
		REP(i, 0, 8) {
			dp[c][state[i]] = 0;
			REP(j, 0, 8) {
				if(state[i] & state[j]) continue;
				dp[c][state[i]] = max(dp[c][state[i]], dp[c-1][state[j]] + getSum(c, state[i])); 	
			}
		}
	}
	int ans = 0;
	REP(i, 0, 8) {
		ans = max(ans, dp[n][state[i]]);
	}	
	cout << ans << endl;
	return newline, 0;
}
