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

vector<char> vertices;
vector<char> adj[100];
vector<bool> visited;
char path[100];
bool isDAG;

bool valid (char u) {
	for(char v: adj[u]) {
		if(visited[v]) {
			return false;
		}
	}
	return true;
}

void dfs (int idx) {
	if(idx == vertices.size()) {
		// print a result
		cout << path[0];
		REP(i, 1, idx) {
			cout << " " << path[i];
		}
		newline;
		isDAG = true;
		return;
	}
	for(char u: vertices) {
		if(!visited[u] && valid(u)) {
			visited[u] = true;
			path[idx] = u;
			dfs(idx+1);
			visited[u] = false;
		}
	}
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
 	cin.ignore();
 	REP(t, 0, T) {
 		visited.assign(100, false);
 		FOR(c, 'A', 'Z') adj[c].clear();
 		vertices.clear();
 		isDAG = false; 		
		if(t != 0) newline;
		
		string line;
		cin.ignore();
 		getline(cin, line); 		
 		for(char c: line) {
 			if(c != ' ') {
 				vertices.push_back(c);
 			}
 		}

 		getline(cin, line);
 		REP(i, 0, line.length()) {
 			if(line[i] == '<') {
 				int u = line[i-1], v = line[i+1];
 				adj[u].push_back(v);
 			}
 		}
 		
 		dfs(0);
 		if(!isDAG) puts("NO");
 	}     
   return 0;
}
