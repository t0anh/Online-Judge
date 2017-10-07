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

const int MX = 303;

vector<int> adj[MX];
int color[MX];
int V, E;

bool bfs (int start) {
	queue<int> que;
	que.push(start);
	color[start] = 0;
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(int v :adj[u]) {
			if(color[v] == color[u]) {
				return false;
			}
			else if(color[v] == -1) {
				color[v] = 1 - color[u];
				que.push(v);
			}
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
 	while(cin >> V) {
 		if(V == 0) break;
 		
 		FOR(v, 1, V) {
 			adj[v].clear();
 			color[v] = -1;
 		}
 		
 		int u, v;
 		while(cin >> u >> v) {
 			if(u+v == 0) break;
 			adj[u].push_back(v);
 			adj[v].push_back(u);
  		}
  		bool isClaws = true;
  		
  		FOR(v, 1, V) {
  			if(color[v] == -1) {
  				isClaws &= bfs(v);
  			}
  		}
  		
  		if(isClaws) {
  			puts("YES");
  		}
  		else puts("NO");
  		
 	}     
   return 0;
}
