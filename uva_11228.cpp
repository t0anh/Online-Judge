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
typedef long long llong;

struct Edge {
	int u, v;
	double w;
	Edge(int u, int v, double w) : u(u), v(v), w(w) {}
};

const int MX = 1001;

int V, M;
vector<Edge> edges; 		
vector<ii> cities;
int link[MX], ele[MX];

double dist(ii A, ii B) {
	int dx = A.first - B.first;
	int dy = A.second - B.second;
	return (double)sqrt(dx*dx + dy*dy);
}

bool compare (Edge & e1, Edge & e2) {
	return e1.w < e2.w;
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
   freopen("output.txt", "w", stdout);
#endif
 	int T;
 	cin >> T;
 	FOR(case_no, 1, T) {
 		cin >> V >> M;
 		int x, y;
 		REP(i, 0, V) {
 			cin >> x >> y;
 			cities.push_back(ii(x, y));
 		}

 		REP(i, 0, V) {
 			REP(j, i+1, V) {
				edges.push_back(Edge(i, j, dist(cities[i], cities[j])));
 			}
 		}
 		sort(edges.begin(), edges.end(), compare);
 		
 		// kruskal
 		REP(i, 0, V) {
 			link[i] = i;
 			ele[i] = 1;
 		}
 		
 		vector<Edge> mst;
 		for(auto e: edges) {
 			if(!same(e.u, e.v)) {
 				unite(e.u, e.v);
 				mst.push_back(e);
 			}
 		}
 		double roadCost = 0.0, railCost = 0.0;
 		int states = 1;
 		for(auto e: mst) {
 			if(e.w > M) {
 				railCost += e.w;
 				states++;
 			}
 			else {
 				roadCost += e.w;
 			}
 		}
 		cout << "Case #" << case_no << ": " << states << " " << (int)(roadCost + 0.5) << " " << (int)(railCost + 0.5) << endl;
 		cities.clear();
 		edges.clear();
 	}     
   return 0;
}
