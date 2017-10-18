#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b) 	for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)	for(int i = (a), _b = (b); i >= _b; --i)

#define endl 		"\n"
#define newline 	cout << "\n"
#define long 		long long

using namespace std;

const int SIZE = 1E6+7;

int a[SIZE];
long sum[SIZE];

inline long getsum(int i, int j) {
	return sum[j] - sum[i-1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
#ifdef Home
	freopen ("input.txt", "r", stdin);
#endif
	int n, t;
	cin >> n >> t;
	FOR(i, 1, n) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	long ans = 0;
	for (int i = 1; i <= n; i++) {
        if(a[i] > t) continue;
        int l = i, r = n;
        while(l < r) {
            int mid = (l + r + 1)/2;
            if(getsum(i, mid) <= t) l = mid;
            else r = mid-1; 
        }
        ans += r-i+1;
    }
    cout << ans << endl;
	return 0;
}
