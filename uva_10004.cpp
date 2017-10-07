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
const int MX = 202;


int V, E;
vector<int> adj[MX];
int color[MX];

bool checkIt (int u) {
	for(int v: adj[u]) {
		if(color[v] == color[u]) {
			return false;
		}
		else if(color[v] == -1){
			color[v] = 1 - color[u];
			return checkIt(v);
		}
	}
	return true;
}


int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
 	while(cin >> V >> E) {

 		REP(v, 0, V) {
 			adj[v].clear();
 			color[v] = -1;
 		}
 		
 		int u, v; 	
 		REP(i, 0, E) {
 			cin >> u >> v;
 			adj[u].push_back(v);
 			adj[v].push_back(u);
 		}
 		color[0] = 0;
 		if(checkIt(0)) {
 			puts("BICOLORABLE.");
 		}
 		else puts("NOT BICOLORABLE.");
 		
 	}     
   return 0;
}
