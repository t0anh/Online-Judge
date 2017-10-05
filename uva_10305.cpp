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

const int MX = 105;

int N, M;
int pre[MX], ans[MX];
bool was[MX];
bool done;

void doit (int k) {
	if(done) return;
	if(k == N) {
		// done
		cout << ans[0];
		REP(i, 1, N) cout << " " << ans[i];
		newline;
		done = true;
		return;
	}
	FOR(i, 1, N) {
		if(!was[i] && was[pre[i]]) {
			ans[k] = i;
			was[i] = true;
			doit(k+1);
			was[i] = false;
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
   while(cin >> N >> M && (N+M) != 0) {
   	memset(was, false, sizeof was);
   	memset(pre, 0, sizeof pre);
   	was[0] = true;
   	
   	int u, v;
		REP(i, 0, M) {
			cin >> u >> v;
			pre[v] = u;
		}
		
		done = false;
		doit(0);   	
   }
   
   
   return 0;
}

