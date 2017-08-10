#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;
const double EPS = (double)1E-12;
int q, p, r, s, t, u;

inline double fx (double x) {
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
} 


int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
		if(fx(1) > EPS || p + r + u < 0) {
			printf("No solution\n");
			continue;
		}
		double low = 0.0, high = 1.0;
		while(high - low > EPS) {
			double mid = (low + high)/2.0;
			if(fx(mid) > 0.0) low = mid;
			else high = mid;
		}
		printf("%.4f\n", low);
	}
   return 0;
}
