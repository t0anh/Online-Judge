#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 
using namespace std;

int n, m, k;
char mp[101][101];
int rx, ry, ori;

inline bool canMove(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#');
}

int mod (int x, int m) {
	if(x < 0) return x + m;
	return x % m;
}

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(cin >> n >> m >> k) {
		if((n|m|k) == 0) break;
		REP(x, 0, n) REP(y, 0, m) {
			cin >> mp[x][y];
			if(mp[x][y] > 64) {
				rx = x, ry = y;
				switch(mp[x][y]) {
					case 'N': ori = 0; break;
					case 'S': ori = 2; break;
					case 'L': ori = 1; break;
					case 'O': ori = 3; break;
				}
			}
		}
		int answer = 0;
		string ins;
		cin >> ins;
		REP(i, 0, ins.length()) {
			if(ins[i] == 'D') {
				ori = mod(ori+1, 4);
			}
			else if(ins[i] == 'E') {
				ori = mod(ori-1, 4);
			}
			else {
				int dx, dy;
				switch(ori) {
					case 0: dx = -1, dy = 0; break;
					case 1: dx = 0, dy = 1; break;
					case 2: dx = 1, dy = 0; break;
					case 3: dx = 0, dy = -1; break;
				}
				if(canMove(rx+dx, ry+dy)) {
					rx += dx, ry += dy;
					if(mp[rx][ry] == '*') {
						++answer;
					}
					mp[rx][ry] = '+';
				}
			}
		}
		puts(answer);
	}		
   return 0;
}
