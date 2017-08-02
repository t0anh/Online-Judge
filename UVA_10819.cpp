#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;
const int INF = 123456789;
int m, n;
int dp[105][10205], p[105], f[105];

int calc (int idx, int remain) {
	if(idx == n) {
		int spent = m + 200 - remain;
		if(spent > m && spent <= 2000) return -INF;
		return 0;
	}
	if(dp[idx][remain] != -1) return dp[idx][remain];
	if(remain >= p[idx]) {
		return dp[idx][remain] = max(calc(idx+1, remain), calc(idx+1, remain - p[idx]) + f[idx]);
	}
	else {
		return dp[idx][remain] = calc(idx+1, remain);
	}
}

int main() {
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
 	while(cin >> m >> n) {
 		REP(i, 0, n) {
 			cin >> p[i] >> f[i];
 		}
		memset(dp, -1, sizeof dp);
 		cout << calc(0, m + 200) << endl;
	}     
   return 0;
}
