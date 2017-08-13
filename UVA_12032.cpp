#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;
const int N = 1E5 + 5;
int n, r[N];

bool can (int k) {
	int current = 0;
	FOR(i, 1, n) {
		if(r[i] - current > k) return false;
		if(r[i] - current == k) --k;
		current = r[i];
	}
	return true;
}

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int tc;
	scanf("%d", &tc);		
	FOR(cases, 1, tc) {
		scanf("%d", &n);
		FOR(i, 1, n) {
			scanf("%d", r+i);
		}
		int low = 0, high = r[n];
		while(low < high) {
			int mid = (low + high - 1)/2;
			if(can(mid)) high = mid;
			else low = mid+1;
		}
		printf("Case %d: %d\n", cases, low);
	}
   return 0;
}
