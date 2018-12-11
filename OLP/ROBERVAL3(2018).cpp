#include <bits/stdc++.h>

using namespace std;
typedef long long llong;

llong power[40];
int cnt[40];

int main() {
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	power[0] = 1;
	for (int i = 1; i < 40; ++i) {
		power[i] = power[i-1] * 3;
	}
	
	llong M;
	
	cin >> M;
	
	llong sum = 0;
	int e = 0;
	while(sum < M) {
		sum += power[e];
		cnt[e]++; 
		++e;
	}
	
	llong rem = sum - M;
	e = 39;
	while(rem > 0) {
		while(power[e] > rem) {
			--e;
		}
		int x = rem / power[e];
		cnt[e] -= x;
		rem -= x * power[e];
	}
	bool empty = true;
	for (int i = 0; i < 40; ++i) {
		if (cnt[i] == -1) {
			empty = false;
			cout << i << " ";
		}
	}
	if (empty) {
		cout << "-1";
	}
	cout << endl;
	for (int i = 0; i < 40; ++i) {
		if (cnt[i] == 1) {
			cout << i << " ";
		}
	}
	return 0;
}

