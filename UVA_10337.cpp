#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define puts(_content_)	cout << _content_ << endl;
#define endl				"\n"
#define newline			cout << "\n"

using namespace std;
const int INF = 1E9;
int dp[10][1005];
int w[10][1005];
int X, Y;

int calc (int x, int y) {
	if(x < 0 || x > 9) return INF;
	if(y == Y) return (x == 9) ? 0 : INF;
	int & ret = dp[x][y];
	if(ret != -1) return ret;
	return ret = min(30 + calc(x, y+1), min(20 + calc(x+1, y+1), 60 + calc(x-1, y+1))) - w[x][y];
}

int main() { 
	ios::sync_with_stdio(false);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int testCases;
	cin >> testCases;
	while(testCases--) {
		cin >> X;
		Y = X/100;
		REP(x, 0, 10) {
			REP(y, 0, Y) {
				cin >> w[x][y];
			}
		}
		memset(dp, -1, sizeof dp);
		puts(calc(9, 0));
		newline;
	}	
   return 0;
}
