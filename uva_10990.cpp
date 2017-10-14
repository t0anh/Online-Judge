#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 2000001;

int phi[MX], DF[MX], SODF[MX];

void init () {
	REP(i, 2, MX) phi[i] = i;
	REP(i, 2, MX) {
		if(phi[i] == i) {
			for(int j = i; j < MX; j += i) {
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
	REP(i, 2, MX) {
		DF[i] = DF[phi[i]] + 1;
		SODF[i] = SODF[i-1] + DF[i];
	}	
}

int main() {
#ifndef Home
   freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
 	init();
 	int tc;
 	scanf("%d", &tc);
 	while(tc--) {
 		int l, r;
 		scanf("%d %d", &l, &r);
 		printf("%d\n", SODF[r] - SODF[l-1]);
 	}
 		  
   return 0;
}
