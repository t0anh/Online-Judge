#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define puts(_content_)	cout << _content_ << endl;
#define endl				"\n"
#define newline			cout << "\n"

using namespace std;
typedef long long llong;
int N, K, M;
llong dp[55][55];

int main() {
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(cin >> N >> K >> M) {
		fill(&dp[0][0], &dp[K+1][N+1], 0);
		dp[0][0] = 1;
		FOR(k, 1, K) {
			FOR(n, 1, N) {
				FOR(m, 1, min(M, n)) {
					dp[k][n] += dp[k-1][n-m];
				}
			}
		} 
		puts(dp[K][N]);	
	}
   return 0;
}
