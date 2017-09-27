#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)    for(int i = a, _b = b; i <= _b; ++i)
#define endl            "\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline         cout << "\n"

using namespace std;
typedef pair<int, int> ii;
const int MAXV = 2525;
int V;
vector<int> adj[MAXV];
vector<int> dept;
vector<bool> visited;

void bfs (int src) {
	queue<ii> que;
	visited.assign(V, false);
	dept.assign(V, 0);
	que.push(ii(src, 0));	
	while(!que.empty()) {
		int u, d;
		tie(u, d) = que.front(); que.pop();
		if(visited[u]) continue;
		visited[u] = true;
		dept[u] = d;
		for(int v: adj[u]) {
			if(!visited[v]) {
				que.push(ii(v, d+1));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
#endif
	cin >> V;
	REP(u, 0, V) {
		int v, n;
		cin >> n;
		REP(i, 0, n) {
			cin >> v;
			adj[u].push_back(v);
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int src;
		cin >> src;
		bfs(src);
		vector<int> cnt(V, 0);
		REP(v, 0, V) {
			cnt[dept[v]]++;
		}
		int ans1 = 0, ans2 = 0;
		REP(i, 1, V) {
			if(cnt[i] > ans1) {
				ans1 = cnt[i];
				ans2 = i;
			}
		}
		if(ans1 == 0) cout << "0\n";
		else cout << ans1 << " " << ans2 << endl;
	}		
	return 0;
}
