#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 


using namespace std;
const int MAXV = 50001;
int V;
int adj[MAXV], cnt[MAXV];
bool was[MAXV];

int dfs(int u) {
	int ret = 1;
	was[u] = true;
	if(!was[adj[u]]) {
		ret += dfs(adj[u]);
	}
	was[u] = false;
	return cnt[u] = ret;
}

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	FOR(t, 1, T) {
		scanf("%d", &V);
		int u, v;
		REP(i, 0, V) {
			scanf("%d %d", &u, &v);
			adj[u] = v;
		}
		memset(cnt, 0, (V+1)*sizeof(int));
		int answer, best = 0;
		FOR(v, 1, V) {
			if(cnt[v] == 0) dfs(v);
			if(cnt[v] > best) {
				best = cnt[v];
				answer = v;
			}
		}
		printf("Case %d: %d\n", t, answer);
	}	
   return 0;
}
