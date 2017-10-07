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
bool possible;

int bfs (int start) {
	queue<int> que;
	que.push(start);
	color[start] = 0;
	int cnt[2] = {1, 0};
	vector<int> visited(V, false);
	while(!que.empty() && possible) {
		int u = que.front(); que.pop();
		if(visited[u]) continue;
		visited[u] = true;
		for(int v: adj[u]) {
			if(color[v] == color[u]) {
				possible = false;
				break;
			}
			if(color[v] == -1) {
				color[v] = 1 - color[u];
				cnt[color[v]]++;
				que.push(v);
			}
		}
	}
	return max(1, min(cnt[0], cnt[1]));
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
 		cin >> V >> E;
 		
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
 		
 		possible = true;
 		int cnt = 0;
 		REP(v, 0, V) {
 			if(color[v] == -1) {
 				cnt += bfs(v);
 			}
 			if(!possible) {
 				cnt = -1;
 				break;
 			}
 		}
 		puts(cnt);
 	}     
   return 0;
}
