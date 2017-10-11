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

const int MX = 234567;

bool isPrime[MX];
vector<int> primes;

void sieve () {
	memset(isPrime, true, sizeof isPrime);
	FOR(i, 2, sqrt(MX)) {
		if(isPrime[i]) {
			for(int j = i*i; j < MX; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	REP(i, 2, MX) {
		if(isPrime[i])
			primes.push_back(i);
	}
}

int count (llong n, int d) {
	llong pow = d;
	int ret = 0;
	while(pow <= n) {
		ret += n/pow;
		pow *= d;
	}
	return ret;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sieve();
 	llong n, m;
 	while(cin >> n >> m) {
 		vector<ii> dm;
 		llong m1 = m;
 		for(int prime: primes) {
 			if(prime > m1) break;
 			if(m1%prime == 0) {
				int cnt = 0;
				while(m1%prime == 0) m1 /= prime, cnt++;
				dm.push_back(ii(prime, cnt));
 			}
 		}
 		if(m1 != 1) {
 			dm.push_back(ii(m1, 1));
 		}
 		bool can = true;
 		for(ii d : dm) {
 			if(d.second > count(n, d.first)) {
 				can = false;
 				break;
 			}
 		}
 		if(can) cout << m << " divides " << n << "!\n";
 		else cout << m << " does not divide " << n << "!\n";
 	}     
   return 0;
}
