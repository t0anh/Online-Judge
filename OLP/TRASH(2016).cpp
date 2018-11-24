#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1E6+5;
 
int a[MAXN];
long long sum[MAXN];
int N, t;
 
inline long long getSum (int i, int j) {
	if (i == 0) return sum[j];
	return sum[j] - sum[i-1];
}
 
int find (int i) {
	int start = i;
	int end = N - 1;
	while(start < end) {
		int mid = (start + end + 1) / 2;
		long long s = getSum(i, mid);
		if (s > t) {
			end = mid - 1;
		}
		else {
			start = mid;
		}
	}
	return start;
}
 
int main() {
	freopen("TRASH.INP", "r", stdin);
	freopen("TRASH.OUT", "w", stdout);
 
	scanf("%d %d", &N, &t);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a[i]);
	}
 
	sum[0] = a[0];
	for(int i = 1; i < N; ++i) {
		sum[i] = sum[i-1] + a[i];
	}
 
 
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] <= t) {
			int j = find(i);
			ans += j - i + 1;
		}
	}
	printf("%d\n", ans);
}