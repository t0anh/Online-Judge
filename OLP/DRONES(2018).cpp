#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n, x, y, t;
	bool fail = false;
	vector<pair<int, int>> drones;
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		t = max(abs(x), abs(y));
		if (t > n) {
			fail = true;
			break;
		}
		drones.push_back(make_pair(t, i+1));
	}
	
	sort(drones.begin(), drones.end());
	
	if (fail) {
		puts("-1");
	}
	else {
		for (auto & d: drones) {
			printf("%d ", d.second);
		}
	}
	return 0;
}
