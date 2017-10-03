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

const int MX = 200000;
int V, E;
vector<iii> edges;
int link[MX], ele[MX];

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
 	while(cin >> V >> E && (V + E)) {
 		int u, v, w;
 		REP(i, 0, E) {
 			cin >> u >> v >> w;
 			edges.push_back(iii(w, u, v));
 		}
 		sort(edges.begin(), edges.end());
 		
 		REP(i, 0, V) {
 			link[i] = i;
 			ele[i] = 1;
 		}
 		
 		int save = 0;
 		for(auto e: edges) {
 			int u, v, w;
 			tie(w, u, v) = e;
 			if(!same(u, v)) {
 				unite(u, v);
 			}
 			else {
 				save += w;
 			}
 		}
 		puts(save);
 		edges.clear();
 	}     
   return 0;
}
