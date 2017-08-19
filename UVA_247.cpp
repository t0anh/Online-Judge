#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int V, E, cnt;
string name[30];
bool visited[30];
vector<int> adj[30], num, low, S;
set<pair<string, string>> EdgesList;
set<string> Vertices;
unordered_map<string, int> number;

void tarjan (int u) {
	num[u] = low[u] = cnt++;
	visited[u] = true;
	S.push_back(u);
	for(int v: adj[u]) {
		if(num[v] == -1) {
			tarjan(v);
		}
		if(visited[v]) {
			low[u] = min(low[u], low[v]);
		}
	}
	
	if(num[u] == low[u]) {
		while(true) {
			int v = S.back(); S.pop_back();
			visited[v] = false;			
			cout << name[v];
			if(v != u) cout << ", ";
			else break;
		}
		newline;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	for(int test = 1; ; ++test) {
		cin >> V >> E;
		if(V == 0) break;
		// initialize
		EdgesList.clear();
		Vertices.clear();
		REP(v, 0, V) adj[v].clear();
		num.assign(V, -1);
		low.assign(V, V);
		cnt = 0;
		S.clear();
		number.clear();
		// get the edges
		string src, des;
		REP(i, 0, E) {
			cin >> src >> des;
			Vertices.insert(src);
			Vertices.insert(des);
			EdgesList.insert(make_pair(src, des));
		}
		// numbering vertices
		int index = 0;
		for(string nickname : Vertices) {
			number[nickname] = index;
			name[index] = nickname;
			++index;
		}
		// build graph
		for(auto p: EdgesList) {
			adj[number[p.first]].push_back(number[p.second]);
		}
		// find SCCs
		cout << "Calling circles for data set " << test << ":\n";		
		REP(v, 0, V) {
			if(num[v] == -1) {
				tarjan(v);
			}
		}
	}	
   return 0;
}

