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
#define pc(mask)        __builtin_popcount(mask)

using namespace std;
typedef long long llong;

const int MX = 25;

llong sum[MX][MX][MX];
llong cb[MX][MX][MX];
int X, Y, Z;

inline llong get (int x1, int y1, int x2, int y2, int z) {
   return sum[x2][y2][z] - sum[x1-1][y2][z] - sum[x2][y1-1][z] + sum[x1-1][y1-1][z];
}

llong calc  (int x1, int x2, int y1, int y2) {
   llong bestCurrent = get(x1, y1, x2, y2, 1);
   llong ret = bestCurrent;
   FOR(z, 2, Z) {
        llong x = get(x1, y1, x2, y2, z) - get(x1, y1, x2, y2, z-1);
        bestCurrent = max(x, bestCurrent + x);
        ret = max(ret, bestCurrent);
   }
   return ret;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int testCases;
   cin >> testCases;
   for(int test = 0; test < testCases; ++test) {
      cin >> X >> Y >> Z;
      // read the heap
      FOR(x, 1, X) FOR(y, 1, Y) FOR(z, 1, Z) {
         cin >> cb[x][y][z];
         cb[x][y][z] += cb[x][y][z-1];
      }
      // calculate the sum table
      FOR(x, 1, X) FOR(y, 1, Y) FOR(z, 1, Z) {
         sum[x][y][z] = cb[x][y][z] + sum[x][y-1][z] + sum[x-1][y][z] - sum[x-1][y-1][z];
      }
      // find the answer
      llong answer = LLONG_MIN;
      FOR(x1, 1, X) FOR(x2, x1, X) FOR(y1, 1, Y) FOR(y2, y1, Y) {
         answer = max(answer, calc(x1, x2, y1, y2));
      }
      
      puts(answer);
      if(test != testCases - 1) puts("");
   }  
   return 0;
}
