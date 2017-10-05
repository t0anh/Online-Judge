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

const int MX = 123;

map<string, int> num;
string name[MX];
vector<int> adj[MX];
int V, E;
int indeg[MX];

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
	int case_no = 1;
 	while(cin >> V) {
 		memset(indeg, 0, sizeof indeg);
 		num.clear();
 		REP(v, 0, V) adj[v].clear();
		cout << "Case #" << case_no++ << ": Dilbert should drink beverages in this order:";
		 		
 		string foo, bar;
 		REP(i, 0, V) {
 			cin >> foo;
 			num[foo] = i;
 			name[i] = foo;
 		}
 		cin >> E;
 		REP(i, 0, E) {
 			cin >> foo >> bar;
 			int u = num[foo], v = num[bar];
 			adj[u].push_back(v);
 			indeg[v]++;
 		}
 		
		// Kahn's Algorithm (Topological sort)
		priority_queue<int, vector<int>, greater<int>> que;		
		REP(v, 0, V) {
			if(indeg[v] == 0) {
				que.push(v);
			}
		}
		while(!que.empty()) {
			int u = que.top(); que.pop();
			cout << " " << name[u];
			for(int v: adj[u]) {
				indeg[v]--;			
				if(indeg[v] == 0) {
					que.push(v);
				}
			}
		}
		
		puts(".\n");
 	}     
   return 0;
}
