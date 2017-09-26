#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << _content_ << "\n"
#define newline 			cout << "\n"

using namespace std;
typedef tuple<int, int, int> iii;

const int MAXV = 205;
const int INF = 1E9;

int V, E, busyness[MAXV], cost[MAXV];
vector<iii> edges;

int main() {
#ifndef Home 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int test_no = 1;
	while(scanf("%d", &V) == 1) {
		FOR(v, 1, V) {
			scanf("%d", &busyness[v]);
		}
		cin >> E;
		int u, v, w;
		REP(i, 0, E) {
			scanf("%d %d", &u, &v);
			w = pow(busyness[v] - busyness[u], 3);
			edges.push_back(iii(u, v, w));
		}
		// bellman-ford
		FOR(v, 1, V) {
			cost[v] = INF;
		}
		cost[1] = 0;
		bool done;
		REP(step, 1, V) {
			done = true;
			for(auto e : edges) {
				tie(u, v, w) = e;
				if(cost[u] != INF && cost[u] + w < cost[v]) {
					cost[v] = cost[u] + w;
					done = false;
				}
			}
			if(done) break;
		}
		// check negative cycle
		if(!done) {
			for(auto e: edges) {
				tie(u, v, w) = e;
				if(cost[u] != INF && cost[u] + w < cost[v]) {
					cost[v] = -INF;
				}
			}
		}
		printf("Set #%d\n", test_no++);
		int q;
		cin >> q;
		while(q--) {
			cin >> v;
			if(v <= V && cost[v] >= 3 && cost[v] != INF) printf("%d\n", cost[v]);
			else printf("?\n");
		}
		
		edges.clear();
	}
	return 0;
}
