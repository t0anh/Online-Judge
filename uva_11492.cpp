#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
const int INF = 1E9;
typedef tuple<int, int, int> iii;
int V, E;
map<string, int> ID;
vector<iii> adj[5000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int test = 0;
	while(cin >> E && E > 0) {
		string foo, bar, word;
		cin >> foo >> bar;
		V = 0;
		ID[foo] = V++;
		ID[bar] = V++;
		REP(i, 0, E) {
			cin >> foo >> bar >> word;
			if(ID.find(foo) == ID.end()) {	
				ID[foo] = V++;
			}
			if(ID.find(bar) == ID.end()) {
				ID[bar] = V++;
			}
			int u = ID[foo], v = ID[bar], w = word.length();
			adj[u].push_back(iii(v, w, word[0]));
			adj[v].push_back(iii(u, w, word[0]));
		}

		vector<vector<int>> dist(V, vector<int>(200, INF));
		vector<vector<bool>> optimized(V, vector<bool>(200, false));
		priority_queue<iii, vector<iii>, greater<iii>> que;
		FOR(c, 'a', 'z') {
			que.push(iii(0, 0, c));
			dist[0][c] = 0;
		}
		while(!que.empty()) {
			int d, u, c;
			tie(d, u, c) = que.top(); que.pop();
			if(optimized[u][c]) continue;
			optimized[u][c] = true;
			for(auto e : adj[u]) {
				int v, w, c2;
				tie(v, w, c2) = e;
				if(c != c2 && d + w < dist[v][c2]) {
					dist[v][c2] = d + w;
					que.push(iii(dist[v][c2], v, c2));
				}
			}
		}

		int answer = INF;
		FOR(c, 'a', 'z') {
			answer = min(answer, dist[1][c]);
		} 
		if(answer == INF) puts("impossivel");
		else puts(answer);

		REP(v, 0, V) adj[v].clear();
		ID.clear();
	}
	return 0;
}
