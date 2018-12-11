#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> n;
	
	int x, y;
	
	for(int i = 0; i < n; ++i) {
		cin >> x >> y;
		t.push_back(make_pair(max(abs(x), abs(y)), i+1));
	}
	
	sort(t.begin(), t.end());
	
	vector<int> prior;
	bool fail = false;
	
	for (int i = 0; i < n; ++i) {
		if (t[i].first <= i) {
			fail = true;
			break;		
		}
		prior.push_back(t[i].second);
	}
	
	if(fail) {
		cout << "-1" << endl;
	}
	else {
		for (int x: prior) {
			cout << x << " ";
		}
	}
	return 0;
}

