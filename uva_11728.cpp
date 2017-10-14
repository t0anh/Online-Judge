#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 1001;

int sum[MX];

void sieve () {
	REP(i, 1, MX) {
		for(int j = i; j < MX; j += i) {
			sum[j] += i;
		}
	}
}


int main() {
#ifndef Home
   freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	sieve();
 	int n;
 	int tc = 1;
 	while(scanf("%d", &n) and n) {
 		if(n <= 0) {
 			printf("-1\n");
 			continue;
 		}
 		int ans = -1;
 		FORD(i, n, 1) {
 			if(sum[i] == n) {
 				ans = i;
 				break;
 			}
 		}
 		printf("Case %d: %d\n", tc++, ans);
 	}  
   return 0;
}
