#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;
typedef pair<int, int> ii;

int R,C,M,N,K;
int answer[2];
int mp[101][101];
bool visited[101][101];
set<ii> add;

inline bool canMove(int x, int y) {
	return (x >= 0 && x < R && y >= 0 && y < C && mp[x][y] != -1);
}

void dfs(int x, int y) {
	visited[x][y] = true;
	int cnt = 0;
	for(auto it : add) {
		int nx = x + it.first;
		int ny = y + it.second;
		if(canMove(nx, ny)) {
			++cnt;
			if(!visited[nx][ny]) dfs(nx, ny);
		}
	}
	++answer[cnt & 1];
}

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int testCases;
	cin >> testCases;
	FOR(cas, 1, testCases) {
		answer[0] = answer[1] = 0;
		memset(mp, 0x00, sizeof mp);
		memset(visited, false, sizeof visited);
		add.clear();
		cin >> R >> C >> M >> N >> K;
		int r, c;
		REP(i, 0, K) {
			cin >> r >> c;
			mp[r][c] = -1;
		}
		int x[] = {-M, -M, -N, -N, N, N, M, M};
		int y[] = {-N, N, -M, M, -M, M, -N, N};		
		REP(i, 0, 8) {
			add.insert(ii(x[i], y[i]));
		}
		dfs(0, 0);
		cout << "Case " << cas << ": " << answer[0] << " " << answer[1] << endl;
	}
   return 0;
}
