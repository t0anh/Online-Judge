#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;
const int MAXV = 1E4+5;
int V, E;
vector<int> adj[MAXV];
bool inStack[MAXV];
stack<int> stk;

void dfs1 (int u) {
	inStack[u] = true;
	for(int v : adj[u]) {
		if(!inStack[v]) {
			dfs1(v);
		}
	}
	stk.push(u);
}

void dfs2(int u) {
	inStack[u] = true;
	for(int v : adj[u]) {
		if(inStack[v]) continue;
		dfs2(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int TC;
	cin >> TC;
	FOR(test, 1, TC) {
		cin >> V >> E;
			
		REP(v, 0, V) adj[v].clear();
		memset(inStack, 0, V);
		
		int from, to;
		REP(i, 0, E) {
			cin >> from >> to;
			adj[from-1].push_back(to-1);
		}
		REP(v, 0, V) {
			if(!inStack[v]) {
				dfs1(v);
			}
		}
		memset(inStack, 0, V);
		int answer = 0;
		while(!stk.empty()) {
			int v = stk.top(); stk.pop();
			if(inStack[v]) continue;
			++answer;
			dfs2(v);
		}
		cout << "Case " << test << ": " << answer << endl;
	}	
   return 0;
}
