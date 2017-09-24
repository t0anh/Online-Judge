#include <bits/stdc++.h>

#define REP(i, a, b) 	for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b) 	for(int i = a, _b = b; i <= _b; ++i)
#define endl				"\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline 			cout << "\n"

using namespace std;
typedef pair<int, int> ii;
const int V = 500;
const int INF = 1E9;

int des, n;
vector<ii> adj[V];
int t[5];
bool available[5][100];

vector<int> process (string & line) {
	vector<int> ret;
	int tmp = 0;
	REP(i, 0, line.length()) {
		if(line[i] == ' ') {
			ret.push_back(tmp);
			tmp = 0;
		}
		else {
			tmp = tmp*10 + (line[i] - '0');
		}
	}
	ret.push_back(tmp);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int test = 1;
	while(cin >> n >> des) {
		REP(i, 0, n) {
			cin >> t[i];
		}
		string line;
		cin.ignore();
		REP(i, 0, n) {
			getline(cin, line);
			vector<int> numbers = process(line);
			int u = numbers[0];
			available[i][u] = true;
			REP(j, 1, numbers.size()) {
				int v = numbers[j];
				adj[100*i + u].push_back(ii(100*i + v, (v-u)*t[i]));
				adj[100*i + v].push_back(ii(100*i + u, (v-u)*t[i]));
				u = v;
				available[i][v] = true;
			}
		}

		REP(f1, 0, n) {
			REP(f2, 0, n) {
				if(f1 == f2) continue;
				REP(x, 1, 100) {
					if(available[f1][x] && available[f2][x]) {
						adj[100*f1 + x].push_back(ii(100*f2 + x, 60));
					}
				}
			}
		}

		vector<int> dist(V, INF);
		vector<bool> optimized(V, false);
		priority_queue<ii, vector<ii>, greater<ii>> que;
		REP(i, 0, n) {
			if(available[i][0]) {
				que.push(ii(0, 100*i));
				dist[i*100] = 0;
			}
		}
		while(!que.empty()) {
			int u = que.top().second; que.pop();
			if(optimized[u]) continue;
			optimized[u] = true;
			for(auto e: adj[u]) {
				int v = e.first, w = e.second;
				if(dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					que.push(ii(dist[v], v));
				}
			}
		}
		int answer = INF;
		REP(i, 0, n) {
			answer = min(answer, dist[100*i + des]);
		}
		if(answer != INF) puts(answer);
		else puts("IMPOSSIBLE");

		memset(available, false, sizeof available);
		REP(v, 0, V) adj[v].clear();
	}		
	return 0;
}
