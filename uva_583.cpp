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
const int MX = 1E5+7;

bool isPrime[MX];
vector<int> primes;

void sieve () {
	memset(isPrime, true, sizeof isPrime);
	FOR(i, 2, sqrt(MX)) {
		if(isPrime[i]) {
			for(int j =  i*i; j < MX; j += i) {
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
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
	sieve();
 	int n;
 	while(cin >> n and n) {
 		int n1 = abs(n);
 		vector<ii> ans;
 		for(int prime: primes) {
 			if(prime > n1) break;
 			if(n1%prime == 0) {
 				int cnt = 1;
 				for(n1 /= prime; n1 % prime == 0; n1 /= prime, cnt++);
 				ans.push_back(ii(prime, cnt));
 			}
 			if(n1 == 1) break;
 		}
 		if(n1 != 1) {
 			ans.push_back(ii(n1, 1));
 		}
 		
 		if(ans.size() == 0) {
 			cout << n << " = " << n << endl;
 			continue;
 		}
 		
 		if (n < 0) {
 			cout << n << " = -1 x ";
 		}
 		else {
 			cout << n << " = ";
 		}
	 	cout << ans[0].first;
 		ans[0].second--;
 		REP(i, 0, ans.size()) {
 			REP(j, 0, ans[i].second) {
 				cout << " x " << ans[i].first;
 			}
 		}
 		newline;
 	}     
   return 0;
}
