#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define puts(_content_)	cout << _content_ << endl;
#define endl				"\n"
#define newline			cout << "\n"

using namespace std;

int n, princes[10001];
int total;

int bsearch (int left, int right, int key) {
	while(left < right) {
		int mid = (left + right + 1)/2;
		if(princes[mid] > key) right = mid - 1;
		else left = mid;
	}
	return (princes[left] == key) ? left : -1;
}

int main() {
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(cin >> n) {
		REP(i, 0, n) {
			cin >> princes[i];
		}
		cin >> total;		
		sort(princes, princes + n);
		int minDiff = INT_MAX;
		int first, second;
		REP(i, 0, n-1) {
			int idx = bsearch(i+1, n-1, total - princes[i]);
			if(idx == -1) continue;
			if(princes[idx] - princes[i] < minDiff) {
				first = princes[i];
				second = princes[idx];
				minDiff= second - first;
			}
		}
		puts("Peter should buy books whose prices are " << first << " and " << second << "." << endl);
	}		
   return 0;
}
