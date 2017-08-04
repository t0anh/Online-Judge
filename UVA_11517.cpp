#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define puts(_content_)	cout << _content_ << endl;
#define endl				"\n"
#define newline			cout << "\n"

using namespace std;
const int INF = 0x3F3F3F3F;

int c[101];
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int testCases;
	cin >> testCases;
	while(testCases--) {
		int n, require;
		cin >> require >> n;
		int total = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> c[i];
			total += c[i];
		}
		dp.assign(n+1, vector<int>(total+1, INF));
		dp[0][0] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int m = 0; m <= total; ++m) {
				if(m >= c[i]) {
					dp[i][m] = min(dp[i-1][m], dp[i-1][m-c[i]] + 1);
				}
				else dp[i][m] = dp[i-1][m];
			}
		}
		for(int m = require; m <= total; ++m) {
			if(dp[n][m] != INF) {
			 	cout << m << " " << dp[n][m] << endl;
			 	break;
			}
		}
	}	
   return 0;
}
