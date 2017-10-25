#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 22;


struct cmp {
	bool operator () (const string & s1, const string & s2) {
		if(s1.length() != s2.length()) return s1.length() < s2.length();
		return s1 < s2;
	}
};

int N;
char board[MX][MX];
char cur[1000];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
set<string, cmp> answer;

void visit (int x, int y, int k) {
	REP(i, 0, 8) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 and nx < N and ny >= 0 and ny < N and board[nx][ny] > cur[k-1]) {
			cur[k] = board[nx][ny];
			visit(nx, ny, k+1);
		} 
	}
	if(k > 2) {
		answer.insert(string(cur, cur+k));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
   int T;
   cin >> T;
   while(T--) {
   	answer.clear();
   	cin >> N;
   	REP(i, 0, N) {
   		REP(j, 0, N) {
				cin >> board[i][j];
			}
   	}
   	
   	REP(i, 0, N) REP(j, 0, N) {
   		cur[0] = board[i][j];
   		visit(i, j, 1);
   	}
   	
   	for(string word: answer) {
   		cout << word << endl;
   	}
   	if(T) cout << endl;
   }
   return 0;
}
