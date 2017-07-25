#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)
#define FILL(a, v, n)   for(int i = 0, _n = (n); i <= _n; ++i) a[i] = v

#define endl            "\n"
#define newline         cout << "\n"
#define sz(x)           (int)(x.d())
#define debug(x)        cout << #x << " = " << x << endl
#define debug2(a, i)    cout << #a << "[" << i << "] = " << a[i] << endl
#define puts(x)         cout << x << endl

#define two(n)          (1 << (n))
#define pc(n)        __builtin_popcount(n)

using namespace std;
typedef long long llong;

const int MX = 105;

int a[MX][MX];
llong sum[MX][MX];
int n, m, k;

inline llong get(int r1, int c1, int r2, int c2) {
   return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

int bsearch (int r1, int c1, int c2) {
   int low = r1, high = n;
   while(low < high) {
      int mid = (low + high + 1) / 2;
      if(get(r1, c1, mid, c2) > k) high = mid-1;
      else low = mid;
   }
   return low;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int ts;
   cin >> ts;  
   FOR(test, 1, ts) {
      cin >> n >> m >> k;
      FOR(i, 1, n) FOR(j, 1, m) {
         cin >> a[i][j];
      }
      
      FOR(x, 1, n) FOR(y, 1, m) {
         sum[x][y] = a[x][y] + sum[x][y-1] + sum[x-1][y] - sum[x-1][y-1];
      }
      
      llong largest = 0, cheapest = 0;
      FOR(c1, 1, m) FOR(c2, c1, m) {
         FOR(r1, 1, n) {
            int r2 = bsearch(r1, c1, c2);
            llong total = get(r1, c1, r2, c2);
            if(r2 < r1 || total > k) continue;            
            int s = (c2-c1+1)*(r2-r1+1);
            if(s > largest) {
               largest = s;
               cheapest = total;
            }
            else if(s == largest) {
               cheapest = min(cheapest, total);
            }
         }
      }
      cout << "Case #" << test << ": " << largest << " " << cheapest << endl;
   }
   return 0;
}
