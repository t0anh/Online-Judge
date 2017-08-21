#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;
const int MV = 1005;
int V, E, SCCs, cnt;
bool inStack[MV];
stack<int> S;
vector<int> adj[MV], low, num;
unordered_map<string, int> number;

inline void Upper(string & s) {
	REP(i, 0, s.length()) {
		if(s[i] > 'Z') {
			s[i] -= 32;
		}
	}
}

void tarjan (int u) {
	low[u] = num[u] = cnt++;
	S.push(u);
	inStack[u] = true;
	for(int v : adj[u]) {
		if(num[v] == -1) {
			tarjan(v);
		}
		if(inStack[v])
			low[u] = min(low[u], low[v]);
	}
	if(low[u] == num[u]) {
		++SCCs;
		while(1) {
			int v = S.top(); S.pop();
			inStack[v] = false;
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
	while(cin >> V >> E)	{
		if(V + E == 0) break;
		REP(i, 0, V) adj[i].clear();
		low.assign(V, MV);
		num.assign(V, -1);
		number.clear();
		SCCs = cnt = 0;
		
		string name;
		cin.ignore();		
		REP(v, 0, V) {
			getline(cin, name);
			Upper(name);
			number[name] = v;
		}
		string from, to;
		REP(i, 0, E) {
			getline(cin, from);
			getline(cin, to);
			Upper(from); Upper(to);
			adj[number[from]].push_back(number[to]);
		}
		REP(v, 0, V) {
			if(num[v] == -1) {
				tarjan(v);
			}
		}
		puts(SCCs);
	}
   return 0;
}
