#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)    for(int i = a, _b = b; i <= _b; ++i)
#define endl            "\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline         cout << "\n"

using namespace std;
typedef tuple<int, int, int> iii;
const int MX = 1010;

bool visited[MX][MX];
char grid[MX][MX];
int R, C;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs (int Sx, int Sy, int Dx, int Dy) {
		queue<iii> que;
		que.push(iii(Sx, Sy, 0));
		while(!que.empty()) {
			int x, y, d;
			tie(x, y, d) = que.front();
			que.pop();
			if(x == Dx && y == Dy) {
				return d;
			}
			if(visited[x][y]) continue;
			visited[x][y] = true;
			REP(i, 0, 4) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != 'x' && !visited[nx][ny]) {
					que.push(iii(nx, ny, d+1));
				}
			}
		}
		return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
#endif
	while(cin >> R >> C && R + C) {
		memset(visited, 0, sizeof visited);
		memset(grid, 0, sizeof grid);
		int bombs;
		cin >> bombs;
		REP(i, 0, bombs) {
			int r, c, n;
			cin >> r >> n;
			REP(i, 0, n) {
				cin >> c;
				grid[r][c] = 'x';
			}
		}
		int Sx, Sy, Dx, Dy;
		cin >> Sx >> Sy >> Dx >> Dy;
		int answer = bfs(Sx, Sy, Dx, Dy);
		puts(answer);
	}		
	return 0;
}
