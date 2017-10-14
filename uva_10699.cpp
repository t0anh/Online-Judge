#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 1E3;

bool isPrime[MX];
vector<int> primes;

void sieve () {
	memset(isPrime, true, sizeof isPrime);
	REP(i, 2, MX) {
		if(isPrime[i]) {
			primes.push_back(i);
			for(int j = i*i; j < MX; j += i)
				isPrime[j] = false;
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
 	while(scanf("%d", &n) and n) {
 		int cnt = 0;
 		int tmp = n;
 		for(int p: primes) {
 			if(p > n) break;
 			if(n%p == 0) cnt++, n /= p;
 			while(n%p == 0) n /= p;
 		}
 		if(n != 1) cnt++;
 		printf("%d : %d\n", tmp, cnt);
 	}  
   return 0;
}
