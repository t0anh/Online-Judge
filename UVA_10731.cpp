#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

vector<int> adj[100], low, num;
stack<int> stk;
bool inStack[100];
int cnt;
vector< set<char> > answers;

void tarjan (int u) {
	low[u] = num[u] = cnt++;
	inStack[u] = true;
	stk.push(u);
	for(int v : adj[u]) {
		if(num[v] == -1) 
			tarjan(v);
		if(inStack[v])
			low[u] = min(low[u], low[v]);
	}
	if(low[u] == num[u]) {
		set<char> s;
		while(1) {
			int v = stk.top(); stk.pop();
			inStack[v] = false;
			s.insert((char)v);
			if(v == u) break;
		}
		answers.push_back(s);
	}
}

bool compare (set<char> & s1, set<char> & s2) {
	return *s1.begin() < *s2.begin();
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
	int lines;
	int firstTest = 0;
	while(cin >> lines) {
		if(lines == 0) break;
		low.assign(100, 100);
		num.assign(100, -1);
		REP(v, 0, 100) adj[v].clear();
		answers.clear();
		cnt = 0;
		char a[5], choice;
		REP(i, 0, lines) {
			cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> choice;
			REP(i, 0, 5) {
				if(a[i] != choice) {
					adj[(size_t)choice].push_back(a[i]);
				}
			}
		}
		FOR(v, 'A', 'Z') {
			if(adj[v].size() && num[v] == -1) {
				tarjan(v);
			}
		}
		sort(answers.begin(), answers.end(), compare);
		if(firstTest++) newline;		
		for(auto st : answers) {
			auto it = st.begin();
			cout << *it++;
			while(it != st.end()) {
				cout << " " << *it++;
			}
			newline;
		}
	}		
   return 0;
}
