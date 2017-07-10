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
#define two(n)          (1 << (n))
using namespace std;



int dp[two(20)][10];
int cache[20][20];

inline bool check1 (int mask, int n) {
   REP(i, 1, n) {
      if(getbit(mask, i) && getbit(mask, i-1)) return false;
   }
   return true;
}

inline bool check2 (int mask, int n) {
   REP(i, 1, n) {
      if(!(getbit(mask, i) || getbit(mask, i-1))) return false;
   }
   return true;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int ts;
   cin >> ts;
   while(ts--) {
      int n, m;
      cin >> n >> m;
      
      if(n == 1 || m == 1) {
         puts(two(n + m - 1));
         continue;
      }
      
      if(n > m) {
         int tmp  = n;
         n = m;
         m = tmp;
      }
      
      if(cache[n][m]) {
         puts(cache[n][m]);
         continue;
      }
      
      REP(mask, 0, two(n)) {
         dp[mask][1] = 1;
      }
      
      FOR(i, 2, m) {
         REP(m1, 0, two(n)) {
            dp[m1][i] = 0;
            REP(m2, 0, two(n)) {
               if(check1(m1 & m2, n) && check2(m1 | m2, n)) {
                  dp[m1][i] += dp[m2][i-1];
               }
            }
         }
      }
      
      int ans = 0;
      REP(mask, 0, two(n)) {
         ans += dp[mask][m];
      }
      puts(ans);
      cache[n][m] = ans;
   }
   return newline, 0;
}
