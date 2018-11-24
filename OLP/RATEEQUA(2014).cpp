#include <bits/stdc++.h>

using namespace std;

typedef long long llong;
typedef struct m22 {
	llong a, b;
	llong c, d;
	
	m22 (llong _a, llong _b, llong _c, llong _d) {
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}	
	
	void print () {
		printf("[%d, %d]\n", a, b);
		printf("[%d, %d]\n", c, d);
	}
	
} M22;

M22 ONE = M22(1, 1, 1, 1);
M22 BASE = M22(1, 1, 1, 0);
llong MOD = 1E9 + 7;

M22 mult (M22 m1, M22 m2) {
	llong a = (m1.a * m2.a + m1.b * m2.c) % MOD;
	llong b = (m1.a * m2.b + m1.b * m2.d) % MOD;
	llong c = (m1.c * m2.a + m1.d * m2.c) % MOD;
	llong d = (m1.c * m2.b + m1.d * m2.d) % MOD;
	return M22(a, b, c, d);	
}

M22 base_power (llong n) {
	if (n == 0) return ONE;
	if (n == 1) return BASE;
	M22 tmp = base_power(n / 2);
	if (n % 2 == 0) {
		return mult(tmp, tmp);
	}
	return mult(BASE, mult(tmp, tmp));
}



int main() {
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	llong a1, n;
	scanf("%d %d", &a1, &n);
//	a1 = 1e15, n = 1e15;
	// answer = a1 * (fib(n+2) - 1)
	llong answer = (a1 % MOD) * (base_power(n+2).b - 1) % MOD;
	printf("%lld\n", answer);
	return 0;
}

