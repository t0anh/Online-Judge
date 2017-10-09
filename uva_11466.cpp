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

const int MX = 1E7;

bool isPrime[MX];
vector<int> primes;

void getPrimes () {
	memset(isPrime, true, sizeof isPrime);
	REP(i, 2, sqrt(MX)) {
		if(isPrime[i]) {
			for(int j = i*i; j < MX; j += i) 
				isPrime[j] = false;
		}
	}
	
	REP(i, 2, MX) 
		if(isPrime[i])
			primes.push_back(i);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
#endif
   getPrimes();
   llong n;
   while(cin >> n && n) {
   	if(n < 0) n = -n;
   	int cnt = 0;
   	int lastPrime;
		for(int prime: primes) {
			if(prime > n) break;
			if(n%prime == 0) {
				cnt++;			
				for(n /= prime; n%prime == 0; n /= prime);
				lastPrime = prime;
			}
		}
		if((cnt == 1 && n != 1) || cnt >= 2) puts(max(lastPrime, n));
		else puts(-1);
   }   
   return 0;
}
