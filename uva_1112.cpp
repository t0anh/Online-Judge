#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
const int MAXV = 105;
const int INF = 1E9;
typedef pair<int, int> ii;
vector<ii> adj[MAXV];
vector<int> dist;
vector<bool> optimized;
int V, E, des, atMost;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	FOR(t, 1, T) {
		cin >> V >> des >> atMost >> E;
		FOR(v, 1, V) adj[v].clear();
		int u, v, c;		
		REP(i, 0, E) {
			cin >> u >> v >> c;
			adj[v].push_back(ii(u, c));
		}
		// dijkstra
		dist.assign(V+1, INF);
		optimized.assign(V+1, false);
		dist[des] = 0;
		priority_queue<ii, vector<ii>, greater<ii>> que;
		que.push(ii(0, des));
		while(!que.empty()) {
			int u = que.top().second; que.pop();
			if(optimized[u]) continue;
			optimized[u] = true;
			for(auto p: adj[u]) {
				int v = p.first, c = p.second;
				if(dist[v] > dist[u] + c) {
					dist[v] = dist[u] + c;
					que.push(ii(dist[v], v));
				}
			}
		}
		int answer = 0;
		FOR(v, 1, V) {
			if(dist[v] <= atMost) {
				answer++;
			}
		}
		if(t == 1) cout << answer << endl;
		else cout << endl << answer << endl;
	}
	return 0;
}
