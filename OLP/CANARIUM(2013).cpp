#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

llong k;

int main() {
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
		
	int ntest;
	
	scanf("%d", &ntest);
	
	while(ntest--) {
		scanf("%lld", &k);
		
		llong limit = sqrt(k);
		llong bestn, bestm, minDiff = k;
			
		for(llong m = 1; m < limit; ++m) {
			llong n = (2 * k - 1 - m) / (2 * m + 1);
			if (n < m) continue;
			if (2 * m * n + m + n == 2 * k - 1 && n - m < minDiff) {
				minDiff = n - m;
				bestn = n;
				bestm = m;
			}
		}
		
		if (minDiff != k) {
			printf("%d %d\n", bestm, bestn);
		}
		else {
			printf("-1 -1\n");
		}
	}

	return 0;
}

