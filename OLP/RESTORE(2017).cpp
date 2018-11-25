#include <bits/stdc++.h>

using namespace std;

typedef long long llong;
const int MAXN = 1E6 + 5;

int n, a[MAXN], cnt[MAXN];
vector<int> good;

bool check (int pos) {
	int num = 1;
	for (int i = pos; i < n; ++i) {
		if (abs(a[i] - num) > 1) return false;
		num++;
	}
	num = n;
	for (int i = pos - 1; i >= 0; --i) {
		if (abs(a[i] - num) > 1) return false;
		num--;
	}
	return true;
}

int solve () {
	llong total = 0;
	for (int i = 0; i < n; ++i) {
		total += a[i];
		cnt[a[i]]++;
		
		if (cnt[a[i]] > 3) {
			return -1;
		}
		
		if(a[i] < 3) {
			good.push_back(i);
		}
	}
	
	if (total < n*(n-1)/2 || total > n*(n+3)/2) {
		return -1;
	}

	// O(8*n) === O(n)
	for (int i: good) {
		if (check(i)) {
			return i;
		}
	}
	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int result = solve();
	if(result != -1) {
		cout << "YES" << endl << result + 1 << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}

