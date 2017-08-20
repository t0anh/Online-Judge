#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;
const int MAXV = 2017;
int V, E;
vector<int> adj[MAXV], low, num;
bool visited[MAXV];
int SCCs, cnt;
stack<int> S;

void tarjan (int u) {
	low[u] = num[u] = cnt++;
	S.push(u);	
	visited[u] = true;
	for(int v : adj[u]) {
		if(num[v] == -1) {
			tarjan(v);
		}
		if(visited[v]) 
			low[u] = min(low[u], low[v]);
	}

	if(num[u] == low[u]) {
		++SCCs;
		while(true) {
			int v = S.top(); S.pop();
			visited[v] = false;
			if(v == u) break;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(cin >> V >> E) {
		if(V == 0) break;
		FOR(i, 1, V) adj[i].clear();
		low.assign(V+1, MAXV);
		num.assign(V+1, -1);
		SCCs = cnt = 0;
		int u, v, op;
		REP(i, 0, E) {
			cin >> u >> v >> op;
			adj[u].push_back(v);
			if(op == 2) adj[v].push_back(u);
		}
		FOR(v, 1, V) 
			if(num[v] == -1)
				tarjan(v);
		if(SCCs == 1) puts("1");
		else puts("0");
	}	
   return 0;
}
