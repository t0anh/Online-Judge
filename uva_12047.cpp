#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
const int MAXN = 1E4+5;
const int INF = 1E9;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<ii> adj[MAXN], radj[MAXN];
vector<iii> edges;
vector<int> sdist, tdist;
vector<bool> optimized;
int V, E, s, t, p;

void dijkstra (int src, vector<int> & dist, vector<ii> adj[]) {
	dist.assign(V+1, INF);
	optimized.assign(V+1, false);
	priority_queue<ii, vector<ii>, greater<ii>>  que;
	dist[src] = 0;
	que.push(ii(0, src));
	while(!que.empty()) {
		int u = que.top().second; que.pop();
		if(optimized[u]) continue;
		optimized[u] = true;
		for(auto e: adj[u]) {
			int v = e.first, w = e.second;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				que.push(ii(dist[v], v));
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	while(T--) {
		cin >> V >> E >> s >> t >> p;
		int u, v, c;
		REP(i, 0, E) {
			cin >> u >> v >> c;
			adj[u].push_back(ii(v, c));
			radj[v].push_back(ii(u, c));
			edges.push_back(iii(u, v, c));
		}
		
		dijkstra(s, sdist, adj);
		dijkstra(t, tdist, radj);
		
		int answer = -1;
		for(auto e : edges) {
			int u, v, c;
			tie(u, v, c) = e;
			if(sdist[u] + tdist[v] + c <= p) {
				answer = max(answer, c);
			}
		}
		
		puts(answer);
		FOR(v, 1, V) {
			adj[v].clear();
			radj[v].clear();
		}
		edges.clear();		
	}		
	return 0;
}
