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

using namespace std;
const int N = 20;
const int INF = 1e9;

int dp[1<<17][N];
int cty[N], cost[N][N];
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
	freopen ("input.txt", "r", stdin);
#endif
	cin >> n;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cin >> cost[i][j];
		}
	}	
	
	#define getBit(num, ith) 		((num >> (ith)) & 1)
	#define toggleBit(num, ith) 	(num ^ (1 << (ith)))
	
	FOR(cur, 1, 1<<n) {
		int k = 0;
		FOR(i, 1, n) {
			if(getBit(cur, i-1)) cty[++k] = i;
		}
		if(k == 1) continue;
		FOR(i, 1, k) {
			int pre = toggleBit(cur, cty[i]-1);
			dp[cur][cty[i]] = INF;
			FOR(j, 1, k) {
				if(j == i) continue;
				dp[cur][cty[i]] = min(dp[cur][cty[i]], dp[pre][cty[j]] + cost[cty[i]][cty[j]]);
			}
		}
	}
	int ans = INF;
	int all = (1<<n)-1;
	FOR(i, 1, n) {
		ans = min(ans, dp[all][i]);
	}
	cout << ans << endl;
	return newline, 0;
}
