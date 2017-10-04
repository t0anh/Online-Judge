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
typedef tuple<double, int, int> dii;
typedef long long llong;


const int MX = 505;

vector<ii> outports;
vector<dii> edges, mst;
int N, M;
int link[MX], ele[MX];

double dist (ii & A, ii & B) {
	int dx = A.first - B.first;
	int dy = A.second - B.second;
	return (double)sqrt(dx*dx + dy*dy);
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
	if(ele[u] > ele[v]) swap(u, v);
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
 	int T;
 	cin >> T;
 	while(T--) {
 		cin >> M >> N;
 		int x, y;
 		REP(i, 0, N) {
 			cin >> x >> y;
 			outports.push_back(ii(x, y)); 
 		}
 		
 		REP(i, 0, N) {
 			REP(j, i+1, N) {	
 				edges.push_back(dii(dist(outports[i], outports[j]), i, j));
 			}
 		}
 		
 		sort(edges.begin(), edges.end());
 		
 		// Kruskal
 		REP(i, 0, N) {
 			link[i] = i;
 			ele[i] = 1;
 		}
 		int u, v;
 		double w;
 		for(auto e: edges) {
 			tie(w, u, v) = e;
 			if(!same(u, v)) {
 				unite(u, v);
 				mst.push_back(e);
 			}
 		}
 		tie(w, ignore, ignore) = mst[mst.size() - M];
 		cout << fixed << setprecision(2) << w << endl;
 		
 		outports.clear();
 		edges.clear();
 		mst.clear();
 	}     
   return 0;
}
