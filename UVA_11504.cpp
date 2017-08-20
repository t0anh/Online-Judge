#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;
const int MAXV = 1E5+5;
int V, E;
vector<int> adj[MAXV];
vector<bool> visited;
stack<int> S;

void dfs (int u) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(visited[v]) continue;
		dfs(v);
	}
	S.push(u);
}

void dfs2(int u) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(visited[v]) continue;
		dfs2(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int tc;
	cin >> tc;
	while(tc--) {
		cin >> V >> E;
		int u, v;
		REP(i, 0, V) adj[i].clear();
		visited.assign(V, false);
		REP(i, 0, E) {
			cin >> u >> v;
			adj[u-1].push_back(v-1);
		}
		REP(v, 0, V) {
			if(!visited[v]) {
				dfs(v);
			}
		}
		int answer = 0;
		visited.assign(V, false);
		while(!S.empty()) {
			int v = S.top(); S.pop();
			if(visited[v]) continue;
			++answer;
			dfs2(v);
		}
		puts(answer);
	}	
   return 0;
}
