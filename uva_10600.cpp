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

const int MX = 12345;

int V, E;
int link[MX], ele[MX];
vector<iii> edges;

int find(int u) {
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

void init (int V) {
	FOR(v, 1, V) {
		link[v] = v;
		ele[v] = 1;
	}
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
 	int T;
 	cin >> T;
 	while(T--) {
 		edges.clear();
 		 	
 		cin >> V >> E;
 		int u, v, w;
 		REP(i, 0, E) {
 			cin >> u >> v >> w;
 			edges.push_back(iii(w, u, v));
 		}
 		sort(edges.begin(), edges.end());
 		// get all of edges in MSTóa
 		vector<bool> used(MX, false);
 		int ans1 = 0;
 		init(V);
 		REP(i, 0, E) {
 			tie(w, u, v) = edges[i];
 			if(!same(u, v)) {
 				unite(u, v);
 				used[i] = true;
 				ans1 += w;
 			}
 		}
 		// try removing any edges in MST and re-run Kruskal to take other minimum results 
 		int ans2 = INT_MAX;
 		REP(i, 0, E) {
 			if(used[i]) {
 				int cost = 0;
 				init(V);
		 		REP(j, 0, E) {
		 			if(i == j) continue;
		 			tie(w, u, v) = edges[j];
		 			if(!same(u, v)) {
		 				unite(u, v);
		 				cost += w;
		 			}
		 		}
		 		// if graph is connected then update result
		 		if(ele[find(1)] == V)
		 			ans2 = min(ans2, cost);
 			}
 		}
 		cout << ans1 << " " << ans2 << endl;
 		

 	}     
   return 0;
}
