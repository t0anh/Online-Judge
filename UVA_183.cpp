#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define newline 			cout << "\n"
#define endl				"\n"
#define puts(_content_)	cout << _content_ << "\n"

using namespace std;

int v[202][202];
int sum[202][202];
int rows, cols;
string code;

inline int getsum(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
}

string B_to_D (int x, int y, int r, int c) {
	if(r == 0 || c == 0) return "";
	int total = getsum(x, y, x-1+r, y-1+c);
	if(total == r*c) return "1";
	if(total == 0) return "0";
	int dx = (r+1)/2;
	int dy = (c+1)/2;
	return "D" + B_to_D(x, y, dx, dy) + B_to_D(x, y+dy, dx, c-dy) + B_to_D(x+dx, y, r-dx, dy) + B_to_D(x+dx, y+dy, r-dx, c-dy);
}


int D_to_B(int x, int y, int r, int c, int idx) {
	if(r == 0 || c == 0) return idx;
	if(code[idx] < '2') {
		int value = code[idx] - '0';
		REP(i, x, x+r) REP(j, y, y+c) {
			v[i][j] = value;
		}
		return idx+1;
	}
	// code[idx] is 'D'
	int dx = (r+1)/2;
	int dy = (c+1)/2;
	// I-quarter
	idx = D_to_B(x, y, dx, dy, idx+1);
	// II-quarter
	idx = D_to_B(x, y+dy, dx, c-dy, idx);
	// III-quarter
	idx = D_to_B(x+dx, y, r-dx, dy, idx);
	// IV-quarter
	idx = D_to_B(x+dx, y+dy, r-dx, c-dy, idx);
	return idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	char type;
	while(cin >> type >> rows >> cols) {
		cout << (type == 'D' ? "B":"D") << right << setw(4) << rows << right << setw(4) << cols << endl;
		if(type == 'B') {
			char ch;
			FOR(r, 1, rows) FOR(c, 1, cols) {
				cin >> ch;
				v[r][c] = ch - '0';
			}
			
			FOR(r, 1, rows) {
				FOR(c, 1, cols) {
					sum[r][c] = v[r][c] + sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1];
				}
			}
			puts(B_to_D(1, 1, rows, cols));
		}
		else {
			cin >> code;
			D_to_B(1, 1, rows, cols, 0);
			FOR(r, 1, rows) {
				FOR(c, 1, cols) {
					cout << v[r][c];
				}
			}
			newline;
		}
	}	
   return 0;
}
