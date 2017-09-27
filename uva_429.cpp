#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)    for(int i = a, _b = b; i <= _b; ++i)
#define endl            "\n"
#define puts(_content_) cout << (_content_) << "\n"
#define newline         cout << "\n"

using namespace std;
typedef pair<int, int> ii;
const int MAXV = 205;

map<string, int> num;
vector<int> adj[MAXV];
int V;

int bfs (int src, int des) {
	queue<ii> que;
	vector<bool> visited(V, false);
	que.push(ii(src, 0));
	while(!que.empty()) {
		int u, dept;
		tie(u, dept) = que.front();
		que.pop();
		if(u == des) return dept;
		if(visited[u]) continue;
		visited[u] = true;
		for(int v: adj[u]) {
			if(!visited[v]) {
				que.push(ii(v, dept+1));
			}
		}
	}
	return -1;
}

void parse (string & foo, string & bar, string & line) {
	REP(i, 0, line.length()) {
		if(line[i] == ' ') {
			foo = line.substr(0, i);
			bar = line.substr(i+1);
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home 
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int N;
	cin >> N;
	string line;
	while(N--) {
		string word;
		V = 0;
		while(1) {
			cin >> word;
			if(word[0] == '*') break;
			num[word] = V++;
		}

		for(auto p: num) {
			string word = p.first;
			int id = p.second;
			REP(i, 0, word.length()) {
				char tmp = word[i];
				FOR(c, 'a', 'z') {
					if(c == word[i]) continue;
					word[i] = c;
					if(num.find(word) != num.end()) {
						adj[id].push_back(num[word]);
					}
					word[i] = tmp;
				}
			}
		}
		
		string foo, bar;
		cin.ignore();
		while(getline(cin, line)) {
			if(line.length() == 0) break;
			parse(foo, bar, line);
			int answer = bfs(num[foo], num[bar]);
			cout << foo << " " << bar << " " << answer << endl;
		}
		if(N != 0) newline;
		num.clear();
		REP(v, 0, V) adj[v].clear();
	}		
	return 0;
}
