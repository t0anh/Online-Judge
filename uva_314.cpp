#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)    for(int i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b)   for(int i = a, _b = b; i >= _b; --i)
#define endl            "\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline         cout << "\n"

using namespace std;
typedef tuple<int, int, char> state;

int N, M;
char grid[55][55];
bool visited[55][55][100];
unordered_map<string, char> directions;

state go (state & original, int step) {
	int x, y;
	char dir;
	tie(x, y, dir) = original;
	switch(dir) {
		case 'N': x -= step; break;
		case 'S': x += step; break;
		case 'W': y -= step; break;
		case 'E': y += step; break;
	}
	return state(x, y, dir);
}

state turn (state & original, int side) {
	char a[100];	
	a['N'] = 0; a['E'] = 1; a['S'] = 2; a['W'] = 3;
	a[0] = 'N'; a[1] = 'E'; a[2] = 'S'; a[3] = 'W';
	int x, y, dir;
	tie(x, y, dir) = original;
	int k = (a[dir] + side + 4) % 4;
	return state(x, y, a[k]);
}

inline bool okay (state & s) {
	int x, y;
	tie(x, y, ignore) = s;
	if(x > 0 && x < N && y > 0 && y < M && grid[x][y] != '1' && grid[x+1][y] != '1' && grid[x][y+1] != '1' && grid[x+1][y+1] != '1') return true;
	return false;
}

inline bool Visited(state & s) {
	int x, y, dir;
	tie(x, y, dir) = s;
	return visited[x][y][dir];
}

int solve (int Sx, int Sy, int Dx, int Dy, char dir) {
	queue<pair<state, int>> que;
	que.push(make_pair(state(Sx, Sy, dir), 0)); 
	while(!que.empty()) {
		state cur = que.front().first;
		int dept = que.front().second;		
		int x, y, dir;
		tie(x, y, dir) = cur;
		if(x == Dx && y == Dy) {
			return dept;
		}
		que.pop();
		if(visited[x][y][dir]) continue;
		visited[x][y][dir] = true;
		// turn (left: -1, riht: +1)
		state nxt = turn(cur, -1);
		if(!Visited(nxt)) {
			que.push(make_pair(nxt, dept+1));
		}
		nxt = turn(cur, 1);
		if(!Visited(nxt)) {
			que.push(make_pair(nxt, dept+1));		
		}
		// go forward (1, 2, 3) steps
		state go1 = go(cur, 1);
		state go2 = go(cur, 2);
		state go3 = go(cur, 3);
		if(okay(go1) && !Visited(go1)) {
				que.push(make_pair(go1, dept+1));
				if(okay(go2) && !Visited(go2)) {
					que.push(make_pair(go2, dept+1));
					if(okay(go3) && !Visited(go3)) {
							que.push(make_pair(go3, dept+1));
					}				
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
	directions["north"] = 'N';
	directions["east"] = 'E';
	directions["south"] = 'S';
	directions["west"] = 'W';
	while(cin >> N >> M) {
		if(N+M == 0) break;
		memset(visited, false, sizeof visited);
		FOR(r, 1, N) {
			FOR(c, 1, M) {
				cin >> grid[r][c];
			}
		}
		int Dx, Dy, Sx, Sy;
		string dir;
		cin >> Sx >> Sy >> Dx >> Dy >> dir;
		puts(solve(Sx, Sy, Dx, Dy, directions[dir]));
	}		
	return 0;
}
