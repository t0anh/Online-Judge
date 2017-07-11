#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)
#define FILL(a, v, n)   for(int i = 0, _n = (n); i <= _n; ++i) a[i] = v

#define endl            "\n"
#define newline         cout << "\n"
#define sz(x)           (int)(x.size())
#define debug(x)        cout << #x << " = " << x << endl
#define debug2(a, i)    cout << #a << "[" << i << "] = " << a[i] << endl
#define puts(x)         cout << x << endl

#define getbit(n, i)    ((n >> (i)) & 1)
#define two(n)          (1 << n)

using namespace std;

typedef long long llong;

vector<int> s[16];
int a[20];
llong dp[20][20][two(16)];

int abs (int x) {
   return (x < 0) ? -x : x;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int n, k;
   cin >> n >> k;
   
   REP(i, 0, n) {
      cin >> a[i];
   }
   
   REP(i, 0, 16) {
      REP(j, 0, 16) {
         if(abs(a[i] - a[j]) > k) s[i].push_back(j);
      }
   }
   
   REP(i, 0, n) {
      dp[1][i][two(i)] = 1;
   }   
   
   FOR(i, 2, n) {
      REP(cur, 0, n) {
         for(auto pre : s[cur]) {
            REP(mask, 0, two(n)) {
               if(getbit(mask, cur)) continue;
               dp[i][cur][mask | two(cur)] += dp[i-1][pre][mask];
            }
         }
      }
   }
   
   llong ans = 0;
   int all = two(n)-1;
   REP(i, 0, n) {
      ans += dp[n][i][all];
   }
   puts(ans);
   return newline, 0;
}
