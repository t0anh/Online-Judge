#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 


using namespace std;
char code[6] = {'W', 'A', 'K', 'J', 'S', 'D'};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string bin[205];
int mp[205][205];
int H, W;

inline bool inside (int x, int y) {
	return (x >= 0 && x <= H && y >= 0 && y <= W);
}

void dfs (int x, int y) {
	mp[x][y] = -1;
	REP(i, 0, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(inside(nx, ny) && mp[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}
 
int dfs2 (int x, int y) {
	int ret = 0;
	mp[x][y] = -1;
	REP(i, 0 , 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(inside(nx, ny) && mp[nx][ny] != -1) {
			if(mp[nx][ny] == 0) {
				dfs(nx, ny);
				++ret;
				continue;
			}
			ret += dfs2(nx, ny);
		}
	}
	return ret;
}

void prepare () {
	bin['0'] = "00000";
	bin['1'] = "00001";
	bin['2'] = "00010";
	bin['3'] = "00011";
	bin['4'] = "00100";
	bin['5'] = "00101";
	bin['6'] = "00110";
	bin['7'] = "00111";
	bin['8'] = "01000";
	bin['9'] = "01001";
	bin['a'] = "01010";
	bin['b'] = "01011";
	bin['c'] = "01100";
	bin['d'] = "01101";
	bin['e'] = "01110";
	bin['f'] = "01111";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	prepare();
	for(int test = 1; ; ++test) {
		memset(mp, 0, sizeof mp);
		cin >> H >> W;
		if(H + W == 0) break;
		char c;
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				cin >> c;
				// decode
				FOR(k, 1, 4) {
					mp[i][4*(j-1) + k] = bin[(int)c][k] - '0';
				}
			}
		}
		// add border
		H = H + 2;
		W = W*4 + 2;
		vector<char> answer;
		dfs(0, 0);
		FOR(i, 1, H) {
			FOR(j, 1, W) {
				if(mp[i][j] == 1) {
					int id = dfs2(i, j);
					answer.push_back(code[id]);
				}
			}
		}
		sort(answer.begin(), answer.end());
		cout << "Case " << test << ": ";
		for(char sym: answer) cout << sym;
		newline;
	}	
   return 0;
}

