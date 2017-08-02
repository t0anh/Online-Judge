#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

llong dp[30001];
int type[5] = {5, 10, 25, 50};

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	fill(dp, dp + 30001, 1);
	for(int i = 1; i < 5; ++i) {
		for(int cents = type[i]; cents < 30001; ++cents) {
			dp[cents] += dp[cents - type[i]];
		}
	}
	
	int money;
	while(scanf("%d", &money) == 1) {
		llong answer = dp[money];
		if(answer == 1) printf("There is only 1 way to produce %d cents change.\n", money);
		else printf("There are %lld ways to produce %d cents change.\n", answer, money);
	}	
   return 0;
}
