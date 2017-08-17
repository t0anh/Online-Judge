#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 				"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int M, N;
char mp[25][25];
char land;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int mod (int y) 
{
	if(y < 0) return N-1;
	return y % N;
}

int dfs (int x, int y) {
	int ret = 1;
	mp[x][y] = ' ';
	REP(i, 0, 4) {
		int nx = x + dx[i];
		int ny = mod(y + dy[i]);
		if(nx >= 0 && nx < M && mp[nx][ny] == land) {
			ret += dfs(nx, ny);
		}
	} 
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	while(cin >> M >> N) {
		REP(i, 0, M) {	
			REP(j, 0, N) {
				cin >> mp[i][j];
			}
		}
		int x0, y0;
		cin >> x0 >> y0;
		land = mp[x0][y0];
		dfs(x0, y0);
		int answer = 0;
		REP(i, 0, M) {
			REP(j, 0, N) {
				if(mp[i][j] == land) {
					answer = max(answer, dfs(i, j));
				}
			}
		}
		puts(answer);
	}	
   return 0;
}
