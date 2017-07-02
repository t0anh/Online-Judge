#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int Pow(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = (1LL* res * a) % MOD;
		a = (1LL * a * a) % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	int n, L;
	cin >> n >> L;	
	int ans = 1LL * L * L % MOD;
	ans = 1LL*ans*(Pow(4, n+1) - 1) % MOD;
	ans = 1LL*ans*Pow(3, MOD - 2) % MOD;
	cout << ans << endl;
	return 0;
}
