#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
typedef pair<int, int> ii;
const int MAXV = 20005;
const int INF = 1E9;
int V, E, s, f;
vector<ii> adj[MAXV];
vector<bool> optimized;
vector<int> dist;
priority_queue<ii, vector<ii>, greater<ii>> que;

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
		cin >> V >> E >> s >> f;
		REP(v, 0, V) adj[v].clear();
		int u, v, w;
		REP(i, 0, E) {
			cin >> u >> v >> w;
			adj[u].push_back(ii(v, w));
			adj[v].push_back(ii(u, w));
		}
		// dijkstra
		dist.assign(V, INF);
		optimized.assign(V, false);
		dist[s] = 0;
		que.push(ii(0, s));
		while(!que.empty()) {
			u = que.top().second; que.pop();
			if(optimized[u]) continue;
			optimized[u] = true;
			for(auto e: adj[u]) {
				v = e.first, w = e.second;
				if(dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					que.push(ii(dist[v], v));
				}
			}
		}
		
		cout <<  "Case #" << t << ": ";
		if(dist[f] != INF) puts(dist[f]);
		else puts("unreachable");
	}		
	return 0;
}
