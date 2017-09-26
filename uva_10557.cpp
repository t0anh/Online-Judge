#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
typedef pair<int, int> ii;

const int INF = 1E9;
const int MAXV = 105;

int V, ene[MAXV];
vector<ii> edges;

int main() {
#ifndef Home 
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	while(scanf("%d", &V) && V != -1) {
		FOR(u, 1 , V) {
			int n;
			scanf("%d %d", &ene[u], &n);
			int v;
			REP(i, 0, n) {
				scanf("%d", &v);
				edges.push_back(ii(u, v));
			}
		}
		// run ford-bellman algorithm V-1 times
		vector<int> dist(V+1, INF);
		dist[1] = -100;
		bool flag;
		REP(step, 1, V) {
			int u, v;
			flag = true;
			for(auto e: edges) {
				tie(u, v) = e;
				if(dist[u] != INF && dist[u] - ene[v] < dist[v] && dist[u] - ene[v] < 0) {
					dist[v] = dist[u] - ene[v];
					flag = false;
				}
			}
			if(flag) break;
		}
		if(!flag) {
			// the graph have negative cycles => set all of vertices v in the negative cycles to dist[v] = -INF
			int u, v, w;
			for(auto e: edges) {
				tie(u, v) = e;
				if(dist[u] != INF && dist[u] - ene[v] < dist[v] && dist[u] - ene[v] < 0) {
					dist[v] = -INF;
				}
			}
			// re-update dist[]
			REP(step, 1, V) {
				int u, v;
				flag = true;
				for(auto e: edges) {
					tie(u, v) = e;
					if(dist[u] != INF && dist[u] - ene[v] < dist[v] && dist[u] - ene[v] < 0) {
						dist[v] = dist[u] - ene[v];
						flag = false;
					}
				}
				if(flag) break;
			}
		}
//		FOR(v, 1, V) {
//			printf("dist[%d] = %d\n", v, dist[v]);
//		}
		if(dist[V] <= 0) printf("winnable\n");
		else printf("hopeless\n");
		edges.clear();
	}
	return 0;
}
