#include <bits/stdc++.h>
 
#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)
 
using namespace std;
 
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

const int MX = 15;

int N, T;
int a[MX];
int answer[MX];
bool used[MX];
bool none;
unordered_map<string, bool> exist;

void back (int k, int sum, string hash) {
	if(sum == T and !exist[hash]) {
		exist[hash] = true;
		none = false;
		cout << hash << endl;
	}
	if(k == N) return;
	REP(i, answer[k-1]+1, N) {
		if(!used[i] and sum + a[i] <= T ) {
			used[i] = true;
			answer[k] = i;
			back(k+1, sum + a[i], hash + "+" + to_string(a[i]));
			used[i] = false;			
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while(cin >> T >> N and N and T) {
		none = true;
		exist.clear();		
		
		REP(i, 0, N) {
			cin >> a[i];
		}
		
		cout << "Sums of " << T << ":\n";
		REP(i, 0, N) {
			if(a[i] <= T) {
				used[i] = true;
				answer[0] = i;
				back(1, a[i], to_string(a[i]));
				used[i] = false;
			}
		}
		if(none) cout << "NONE\n";
	}
   return 0;
}

