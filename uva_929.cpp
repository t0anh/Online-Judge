#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
typedef pair<int, int> ii;
const int MX = 1000;
const int INF = 1E9;

int R, C;
int a[MX][MX];
vector<ii> adj[MX*MX];
vector<int> dist;
vector<bool> optimized;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> R >> C;
		REP(r, 0, R) {
			REP(c, 0, C) {
				cin >> a[r][c];
			}
		}
		// build graph
		REP(v, 0, R*C) adj[v].clear();
		REP(x, 0, R) { 
			REP(y, 0, C) {
				REP(i, 0, 4) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
						adj[x*C + y].push_back(ii(nx*C + ny, a[nx][ny]));
					}
				}
			}
		}
		// dijkstra
		dist.assign(R*C, INF);
		optimized.assign(R*C, false);
		dist[0] = a[0][0];
		
		priority_queue<ii, vector<ii>, greater<ii>> que;
		que.push(ii(dist[0], 0));
		int des = R*C-1;
		while(!que.empty()) {
			int u = que.top().second; que.pop();
			if(optimized[u]) continue;
			optimized[u] = true;
			if(u == des) break;
			for(auto p: adj[u]) {
				int w = p.second, v = p.first; 
				if(dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					que.push(ii(dist[v], v));
				}
			}
		}
		cout << dist[des] << endl;
	}		
	return 0;
}
