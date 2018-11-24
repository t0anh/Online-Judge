#include <bits/stdc++.h>
 
using namespace std;
const long long M = 1e9 + 7;
 
long long L, n;
 
long long pow_mod (int a, int n) {
	if (n == 0) return 1;
	if (n == 1) return a;
	long long tmp = pow_mod(a, n/2);
	if (n % 2 == 0) return tmp * tmp % M;
	return (tmp * tmp % M) * a % M;
}
 
long long multiple (long long a, long long b) {
	return a * b % M;
}
 
int main() {
//	freopen("SQUARES.INP", "r", stdin);
//	freopen("SQUARES.OUT", "w", stdout);
	scanf("%d %d", &n, &L);
	// s = (L^2*4^(n+1) - L^2) x 3 ^ (M-2) % M
	long long tmp = multiple(multiple(L, L), pow_mod(4, n + 1)) - multiple(L, L) % M;
	long long s = multiple(tmp, pow_mod(3, M-2));
	printf("%lld\n", s);
}