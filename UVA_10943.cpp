#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define puts(_content_)	cout << _content_ << endl;
#define endl				"\n"
#define newline			cout << "\n"

using namespace std;
const int MOD = 1E6;
int dp[105][105];
int n, k;

int main() {
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	dp[0][0] = 1;
	FOR(i, 1, 100) {
		FOR(s, 0, 100) {
			FOR(x, 0, s) {
				dp[i][s] += dp[i-1][s-x];
				dp[i][s] %= MOD;
			}
		}
	}
	while(cin >> n >> k) {
		if(n + k == 0) break;
		puts(dp[k][n]);
	}
   return 0;
}
