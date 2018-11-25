#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

const int MAXN = 1E6 + 5;
int n, l[MAXN], a[MAXN];
llong dp[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	dp[1] = a[1];
	l[1] = 1;
	int best = 1;
	
	for (int i = 2; i <= n; ++i) {
		if (dp[i-1] < 0) {
			dp[i] = a[i];
			l[i] = 1;
		}
		else {
			dp[i] = dp[i-1] + a[i];
			l[i] = l[i-1] + 1;
		}
		
		if (dp[best] < dp[i]) {
			best = i;
		}
	}
	
	cout << best - l[best] + 1 << " " << best << " " << dp[best] << endl;	
	return 0;
}

