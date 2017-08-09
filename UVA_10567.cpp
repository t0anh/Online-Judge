#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define puts(_content_)	cout << _content_ << endl;
#define endl				"\n"
#define newline			cout << "\n"

using namespace std;

vector<int> exist[200];

int search(int key, vector<int> & vi) {
	int left = 0, right = vi.size() - 1;
	while(left < right) {
		int mid = (left + right - 1)/2;
		if(vi[mid] > key) right = mid;
		else left = mid + 1;
	}
	return (vi[left] > key) ? vi[left] : -1;
}

int main() {
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	string text, pattern;
	int queries;

	cin >> text >> queries;
	REP(i, 0, text.length()) {
		exist[(int)text[i]].push_back(i);
	}

	while(queries--) {
		cin >> pattern;
		bool matched = true;
		int cur = -1;
		REP(i, 0, pattern.length()) {
			cur = search(cur, exist[(int)pattern[i]]);
			if(cur == -1) {			
				matched = false;
				break;
			}
		}
		if(matched) {
			cout << "Matched " << search(-1, exist[(int)pattern[0]]) << " " << cur << endl;
		}
		else puts("Not matched");
	}	
   return 0;
}
