#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN], n;

/*
	check a[0...m-1] < b[n-1-m...n-1]
*/
bool check (int m) {
	for (int i = 0; i < m; ++i) {
		if (a[m-1-i] > b[n-1-i]) return false;
	}
	return true;
}

/*
	O(nlog(n))
*/
int binary_solve () {
	if (b[n-1] <= a[0]) return 0;
	int left = 0, right = n - 1;
	while(left < right) {
		int mid = (left + right + 1) / 2;
		if (check(mid)) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}

/*
	O(2n)
*/
int solve () {
	int pos = n-1;
	int score = 0;
	
	for (int i = n-1; i >= 0; --i) {
		while(pos >= 0 && a[pos] >= b[i]) {
			--pos;
		}
		if (pos >= 0) {
			score++;
			--pos;
		}	
		else {
			break;
		}	
	}
	
	return score;
}

int main() {
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
	}
	
	sort(a, a + n);
	sort(b, b + n);	
	
//	solve() or binary_solve()
	printf("%d\n", solve());	
	return 0;
}

