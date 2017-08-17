#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int N;
char grid[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
	grid[x][y] = '.';
	REP(i, 0, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < N && ny >= 0 && ny < N && (grid[nx][ny] == 'x' || grid[nx][ny] == '@')) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int TC;
	cin >> TC;
	FOR(test, 1, TC) {
		cin >> N;
		REP(i, 0, N) {
			REP(j, 0, N) {
				cin >> grid[i][j];
			}
		}
		int answer = 0;
		REP(i, 0, N) {
			REP(j, 0, N) {
				if(grid[i][j] == 'x') {
					dfs(i, j);	
					++answer;
				}
			}
		}
		cout << "Case " << test << ": " << answer << endl;
	}	
   return 0;
}
