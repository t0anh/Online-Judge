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

const int MX = 2E7+7;

bool isPrime[MX];
vector<ii> twins;

void sieve () {
	memset(isPrime, true, sizeof isPrime);

	FOR(i, 2, sqrt(MX)) {
		if(isPrime[i]) {
			for(int j = i*i; j < MX; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	twins.push_back(ii(0, 0)); // dummy	
	int last = 2;	
	REP(i, 2, MX) {
		if(isPrime[i]) {
			if(i - last == 2) {
				twins.push_back(ii(last, i));
			}
			last = i;
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
 	while(cin >> n) {
 		cout << "(" << twins[n].first << ", " << twins[n].second << ")\n";
 	}     
   return 0;
}
