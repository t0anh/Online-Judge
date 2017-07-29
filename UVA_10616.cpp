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

#define two(n)          (1 << (n))
#define pc(n)        __builtin_popcount(n)

using namespace std;
typedef long long llong;

int N, Q;
int a[205], dp[205][15][25];

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int setNumber = 1;
   while(true) {
      scanf("%d %d", &N, &Q);
      if(N + Q == 0) break;
      FOR(i, 1, N) {
         scanf("%d", a + i);
      }
      printf("SET %d:\n", setNumber++);
      int D, M;
      FOR(q, 1, Q) {
         scanf("%d %d", &D, &M);
         dp[0][0][0] = 1;
         FOR(i, 1, N) {
            FOR(m, 0, M) {
               FOR(d, 0, D) {
                  dp[i][m][d] = dp[i-1][m][d];               
                  int rem = ((llong)d + a[i]) % D;
                  if(rem < 0) rem += D;
                  if(m > 0) {
                     dp[i][m][d] += dp[i-1][m-1][rem];
                  }
               }
            }
         } 
         printf("QUERY %d: %d\n", q, dp[N][M][0]);
      }
   }
   return 0;
}
