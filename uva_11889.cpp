#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

#define dbi(x)	printf("%s = %d\n", #x, x)
#define dbl(x)	printf("%s = %lld\n", #x, x)
#define dbf(x) printf("%s = %f\n", #x, x)
#define dbs(x) printf("%s = %s\n", #x, x.c_str());
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 50000;

char isPrime[MX];
vector<int> primes;

void sieve () {
	memset(isPrime, 1, sizeof isPrime);
	FOR(i, 2, sqrt(MX)) {
		if(isPrime[i]) {
			for(int j = i*i; j < MX; j += i)
				isPrime[j] = 0;
		}
	}
	
	REP(i, 2, MX)
		if(isPrime[i])
			primes.push_back(i);
}

inline int pow (int a, int n) {
	int ret = 1;
	while(n) {
		if(n&1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}

int main() {
#ifndef Home
   freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	sieve();
	int tc;
 	scanf("%d", &tc);  
 	while(tc--) {
 		int A, C;
 		scanf("%d %d", &A, &C);
 		if(C%A) {
 			printf("NO SOLUTION\n");
 			continue;
 		}
 		int B = 1;
 		for(int prime: primes) {
 			if(prime > C) break;
 			if(C%prime == 0) {
 				int k1 = 0, k2 = 0;
 				while(C%prime == 0) C /= prime, k1++;
 				while(A%prime == 0) A /= prime, k2++;
 				if(k1 > k2) {
 					B *= pow(prime, k1);
 				}
 			}
 		}
 		if(C != 1 && A == 1) 
 			B *= C;
 		printf("%d\n", B);
 	}
   return 0;
}
