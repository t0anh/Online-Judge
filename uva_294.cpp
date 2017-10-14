#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 32023;

vector<int> primes;
bool isPrime[MX];

void sieve () {
	memset(isPrime, true, sizeof isPrime);
	REP(i, 2, MX) {
		if(isPrime[i]) {
			primes.push_back(i);
			for(int j = i*i; j < MX; j += i) {
				isPrime[j] = false;
			}
		}
	}
}


int main() {
#ifndef Home
   freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	sieve();
 	int N;
 	scanf("%d", &N);
 	while(N--) {
 		int A, B;
 		scanf("%d %d", &A, &B);
 		int P, H = 0;
 		FOR(p, A, B) {
 			int n = p;
 			int divisors = 1;
 			for(int prime: primes) {
 				if(prime > n) break;
 				if(n%prime == 0) {
 					int cnt = 1;
 					while(n%prime == 0) n /= prime, cnt++;
 					divisors *= cnt;
 				}
 			}
 			if(H < divisors) {
 				H = divisors;
 				P = p;
 			}
 		}
 		printf("Between %d and %d, %d has a maximum of %d divisors.\n", A, B, P, H);
 	}  
   return 0;
}

//	let N = p1^(e1)*p2^(e2)*...*pn^*(en) with pi is prime numbers, and ei is exp of pi
//	=> number divisors of N is k = (e1+1)(e2+1)...(en+1)

