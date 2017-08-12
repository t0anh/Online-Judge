#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;
const int MAXN = 1E6 + 5;
int n, m, a[MAXN], sum[MAXN];

inline int getsum(int i, int j) {
	return sum[j] - sum[i-1];
}

int lower_bound (int low, int high, int s) {
	int start = low;
	while(low < high) {
		int mid = (low + high + 1)/2;
		if(getsum(start, mid) <= s) low = mid;
		else high = mid-1;
	}
	return getsum(start, high) <= s ? high : -1;
}

int check (int s) {
	int current = 0;
	REP(segNo, 0, m) {
		if(current >= n || current < 0) {
			break;
		}
		current = lower_bound(current+1, n, s);
	}
	return current - n;
}

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(scanf("%d %d", &n, &m) == 2) {
		FOR(i, 1, n) {
			scanf("%d", a+i);
			sum[i] = sum[i-1] + a[i];
		}
		if(m == 1) {
			printf("%d\n", sum[n]);
			continue;
		}
		int low = 0, high = sum[n];
		while(low < high) {
			int mid = (low + high - 1)/2;
			if(check(mid) >= 0) high = mid;
			else low = mid+1;
		}
		printf("%d\n", low);
	}
		
   return 0;
}
