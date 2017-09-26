#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
const int MAXV = 1005;
const int INF = (1<<30);

struct Edge {
	int u, v, w;
	Edge (int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
};

int V, E;
vector<Edge> edges;
int dist[MAXV];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> V >> E;

		REP(v, 0, V) {
			dist[v] = INF;
		}
		dist[0] = 0;
		edges.clear();
		
		int u, v, w;
		REP(i, 0, E) {
			cin >> u >> v >> w;
			edges.push_back(Edge(u,v,w));
		}
		bool possible;
		REP(step, 0, V) {
			possible = false;
			for(Edge e: edges) {
				u = e.u, v = e.v, w = e.w;
				if(dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					possible = true;
				}
			}
		}
		if(possible) puts("possible");
		else puts("not possible");
	}		
	return 0;
}
