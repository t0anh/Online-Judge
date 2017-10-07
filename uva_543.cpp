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

const int MX = 1E6+5;

bool isPrime[MX];

void sieve () {
	memset(isPrime, true, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	FOR(i, 2, sqrt(MX)) {
		if(isPrime[i]) {
			for(int j = i*i; j < MX; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sieve();	
	int n;
 	while(cin >> n && n != 0) {
 		bool flag = false;
 		FOR(a, 3, n/2) {
 			int b = n-a;
 			if(isPrime[a] && b >= a && isPrime[b]) {
 				cout << n << " = " << a << " + " << b << endl;
 				flag = true;
 				break;
 			} 
 		}
 		if(!flag) puts("Goldbach's conjecture is wrong.");
 	}     
   return 0;
}
