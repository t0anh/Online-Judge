#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

#define dbi(x)	printf("%s = %d\n", #x, x)
#define dbl(x)	printf("%s = %lld\n", #x, x)
#define dbf(x) printf("%s = %f\n", #x, x)
#define dbs(x) printf("%s = %s\n", #x, &x[0]);
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 1E6;

bool isPrime[MX];
vector<int> primes;

void sieve () {
	memset(isPrime, true, sizeof isPrime);
	for(int i = 2; i*i < MX; ++i) {
		if(isPrime[i]) {
			for(int j = i*i; j < MX; j += i)
				isPrime[j] = false;
		}
	}
	REP(i, 2, MX) {
		if(isPrime[i]) {
			primes.push_back(i);
		}
	}
}

llong pow (int a, int n) {
	llong ret = 1;
	while (n) {
		if(n & 1) ret = ret*a;
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
	int n;
	while(scanf("%d", &n) && n) {
		
		int cnt2 = 0, cnt5 = 0;
		for(int x = 2; x <= n; x <<= 1) cnt2++;
		for(int x = 5; x <= n; x *= 5) cnt5++;
		llong ans;
		if(cnt2 > cnt5) ans = pow(2, cnt2-cnt5);
		else ans = pow(5, cnt5-cnt2);
		
		for(int prime: primes) {
			if(prime == 2 || prime == 5) continue;
			if(prime > n) break;
			for(llong power = prime; power <= n; power *= prime) {
				ans = (ans*prime)%10;
			}
		}
		printf("%lld\n", ans);
	}
   return 0;
}
