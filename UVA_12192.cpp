#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define puts(_content_)	cout << _content_ << endl;
#define endl				"\n"
#define newline			cout << "\n"

using namespace std;

int n, m;
int vmin, vmax;
vector<int> dia[1005];

int upper_bound (int val, vector<int> & vi) {
	int left = 0, right = vi.size() - 1;
	while(left < right) {
		int mid = (left + right - 1)/2;
		if(vi[mid] < val) left = mid + 1;
		else right = mid;
	}
	return (vi[left] >= val) ? left : -1;
}

int lower_bound (int val, vector<int> & vi) {
	int left = 0, right = vi.size() - 1;
	while(left < right) {
		int mid = (left + right + 1)/2;
		if(vi[mid] > val) right = mid - 1;
		else left = mid;
	}
	return (vi[left] <= val) ? left : -1;
}

int main() {
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(cin >> n >> m) {
		if(n + m == 0) return 0;
		FOR(i, 500 - m, 500 + n) dia[i].clear(); 
		int x;
		REP(i, 0, n) REP(j, 0, m) {
			cin >> x;
			dia[500 + i - j].push_back(x);
		}
		
		int queries;
		cin >> queries;
		while(queries--) {
			cin >> vmin >> vmax;
			int answer = 0;
			FOR(i, 500 - m, 500 + n) {
				if((int)dia[i].size() > answer) {
					int p1 = upper_bound(vmin, dia[i]);
					if(p1 == -1) continue;
					int p2 = lower_bound(vmax, dia[i]);
					if(p2 == -1) continue;
					answer = max(answer, (p2 - p1 + 1));
				}
			}
			puts(answer);
		}
		puts("-");
	}	

   return 0;
}
