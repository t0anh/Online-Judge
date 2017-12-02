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

vector<int> num, low, cuts, dad;
vector<vector<int>> adj;
vector<bool> art;
vector<ii> bridges;
int V, E, children, cnt, root;

void dfs (int u) {
	num[u] = low[u] = cnt++;
	for(int v: adj[u]) {
		if(num[v] == -1) {
			dad[v] = u;
			if(u == root) {
				children++;
			}
			dfs(v);
			low[u] = min(low[u], low[v]);
			if(low[v] >= num[v]) {
				bridges.push_back(ii(u, v));
			}
			if(low[v] >= num[u]) {
				art[u] = true;
			}
		}
		else if(v != dad[u]) {
			low[u] = min(low[u], num[v]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cin >> V >> E;
	// initialize
	num.assign(V+1, -1);
	low.assign(V+1, V+1);
	adj.assign(V+1, vector<int>(0));
	art.assign(V+1, false);
	dad.assign(V+1, -1);
	// load graph
	int u, v;
	REP(i, 0, E) {
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	
	FOR(v, 1, V) {
		if(num[v] == -1) {
			root = v;
			children = 0;
			dfs(v);
			art[v] = (children > 1);
		}
	}	
	
	for(ii p: bridges) {
		cout << "(" << p.first << "," << p.second << ")" << endl;
	}
	
	FOR(v, 1, V) {
		if(art[v]) {
			puts(v);
		}
	}
   return 0;
}
