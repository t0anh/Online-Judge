#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= _b; --i)

#define endl "\n"
#define newline	cout << "\n"
#define puts(x)	cout << x << "\n"

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

vector<vector<int>> adj;
queue<int> que;
int V, E;
vector<int> indeg;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while(cin >> V >> E and (V | E)) {
	
		adj.assign(V+1, vector<int>(0));
		indeg.assign(V+1, 0);
		
		int u, v;
		REP(i, 0, E) {
			cin >> u >> v;
			adj[u].push_back(v);
			indeg[v]++;
		}
		
		FOR(v, 1, V) {
			if(indeg[v] == 0) {
				que.push(v);
			}
		}
		
		vector<int> tp;
		while(!que.empty()) {
			int u = que.front(); que.pop();
			tp.push_back(u);
			for(int v: adj[u]) {
				indeg[v]--;
				if(indeg[v] == 0) {
					que.push(v);
				}
			}
		}
		
		cout << tp[0];
		REP(i, 1, tp.size()) {
			cout << " " << tp[i];
		}
		newline;
	}	
   return 0;
}
