#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

#define endl          "\n"
#define newline       cout << "\n"
#define puts(_xxx_)   cout << _xxx_ << "\n"
#define db1(x)        cout << #x << " = " << x << "\n"
#define db2(a, i)     cout << #a << "[" << i << "] = " << a[i] << "\n"
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 1E6+10;
vector<int> primes;
bool isPrime[MX];
vector<llong> numbers;

void getPrimes () {
	memset(isPrime, true, sizeof isPrime);
	FOR(i, 2, sqrt(MX)) {
		if(isPrime[i]) {
			for(int j = i*i; j < MX; j += i) {
				isPrime[j] = false;
			}
		}
	}
	REP(i, 2, MX) {
		if(isPrime[i]) {
			primes.push_back(i);
		}
	}	
}


int main() {
#ifndef Home
   freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
#endif
 	getPrimes();
 	llong L, R;
 	while(scanf("%lld %lld", &L, &R) == 2) {
 		numbers.clear();
 		if(R < MX) {
 			for(int prime: primes) {
 				if(prime >= L && prime <= R) {
 					numbers.push_back(prime);
 				}
 			}
 		}
 		else {
 			memset(isPrime, true, sizeof isPrime);
 			int l = 0, r = R-L;
 			for(int prime: primes) {
 				if(prime > R) break;
 				for(int i = ((L+prime-1)/prime)*prime - L; i <= r; i += prime) {
 					isPrime[i] = false;
 				}
 			}
 			FOR(i, 0, r) {
 				if(isPrime[i]) {
 					numbers.push_back(L+i);
 				}
 			}
 		}
 		
 		if(numbers.size() < 2) {
 			printf("There are no adjacent primes.\n");
 		} 	
 		else {
 			int dmin = 1, dmax = 1;
 			REP(i, 1, numbers.size()) {
 				if(numbers[i] - numbers[i-1] > numbers[dmax] - numbers[dmax-1]) {
 					dmax = i;
 				}
 				if(numbers[i] - numbers[i-1] < numbers[dmin] - numbers[dmin-1]) {
 					dmin = i;
 				}
 			}
 			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", numbers[dmin-1], numbers[dmin], numbers[dmax-1], numbers[dmax]);
 		}
 	}
   return 0;
}
