#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 1E6+1;

bool isSF[MX], isPrime[MX];
int cnt[MX], M[MX], mu[MX];

void sieve () {
	memset(isSF, true, sizeof isSF);
	memset(isPrime, true, sizeof isPrime);
	REP(i, 2, MX) {
		if(isPrime[i]) {
			for(int j = i; j < MX; j += i) {
				isPrime[j] = false;
				cnt[j]++;
			}
			llong sqr = (llong)i*i;
			if(sqr > MX) continue;
			for(int j = sqr; j < MX; j += sqr) {
				isSF[j] = false;
			}
		}
	}	
}

void calc () {
	sieve();
	mu[1] = 1;
	M[1] = 1;
	REP(i, 2, MX) {
		if(isSF[i]) {
			mu[i] = (cnt[i]%2 == 0) ? 1 : -1;
		}
		else{
			mu[i] = 0;
		}
		M[i] = M[i-1] + mu[i];
	}
}


int main() {
#ifndef Home
   freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	calc();
	int n;
	while(scanf("%d", &n) and n) {
		printf("%8d%8d%8d\n", n, mu[n], M[n]);
	}
   return 0;
}
