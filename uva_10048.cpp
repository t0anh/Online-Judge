#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

#define endl          "\n"
#define newline       cout << "\n"
#define puts(_xxx_)   cout << _xxx_ << "\n"
#define db1(x)        cout << #x << " = " << x << "\n"
#define db2(a, i)     cout << #a << "[" << i << "] = " << a[i] << "\n"
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 105;

int V, E, Q;
vector<iii> edges;
int link[MX], ele[MX];
int ans[MX][MX];
vector<ii> adj[MX];
bool visited[MX];

void dfs (int start, int cur) {
	visited[cur] = true;
	for(auto e: adj[cur]) {
		if(!visited[e.first]) {
			ans[start][e.first] = max(ans[start][cur], e.second);
			dfs(start, e.first);
		}
	}
}

int find (int u) {
	while(u != link[u]) u = link[u];
	return u;
}

bool same (int u, int v) {
	return find(u) == find(v);
}

void unite (int u, int v) {
	u = find(u);
	v = find(v);
	if(ele[u] < ele[v]) swap(u, v);
	ele[u] += ele[v];
	link[v] = u;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
 	for(int case_no = 1; ; ++case_no) {
 		cin >> V >> E >> Q;
 		if(V+E+Q == 0) break;
 		if(case_no != 1) puts("");
 		cout << "Case #" << case_no << endl;
 		 		
 		edges.clear();
 		memset(ans, 0, sizeof ans);
 		FOR(v, 1, V) adj[v].clear();
 		
		int u, v, w; 		
 		REP(i, 0, E) {
 			cin >> u >> v >> w;
 			edges.push_back(iii(w, u, v));
 		}
 		sort(edges.begin(), edges.end());
 		
 		
 		// Kruskal
 		FOR(v, 1, V) {
 			link[v] = v;
 			ele[v] = 1;
 		}
 		
 		for(auto e: edges) {
 			tie(w, u, v) = e;
 			if(!same(u, v)) {
 				unite(u, v);
				adj[u].push_back(ii(v, w));
				adj[v].push_back(ii(u, w));
 			} 
 		}
	
 		REP(i, 0, Q) {
 			cin >> u >> v;
 			if(ans[u][v] == 0) ans[u][v] = ans[v][u];
 			if(ans[u][v] == 0) {
	 	 		memset(visited, 0, sizeof visited);
	 	 		dfs(u, u);			
 			}
 			if(ans[u][v] == 0) cout << "no path" << endl;
 			else cout << ans[u][v] << endl;
 		}
 	}     
   return 0;
}
