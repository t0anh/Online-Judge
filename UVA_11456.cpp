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
const int MX = 2018;

int w[MX], LIS[MX], LDS[MX];
int n;

int lis (int i) {
   if(LIS[i]) return LIS[i];
   int ret = 1;
   REP(j, i+1, n) {
      if(w[i] < w[j]) {
         ret = max(ret, 1 + lis(j));
      }
   }
   return LIS[i] = ret;
}

int lds (int i) {
   if(LDS[i]) return LDS[i];
   int ret = 1;
   REP(j, i+1, n) {
      if(w[i] > w[j]) {
         ret = max(ret, 1 + lds(j));
      }
   }
   return LDS[i] = ret;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int ts;
   cin >> ts;
   while(ts--) {
      cin >> n;
      REP(i, 0, n) cin >> w[i];
      
      memset(LIS, 0, sizeof LIS);
      memset(LDS, 0, sizeof LDS);
      
      int answer = 0;
      REP(i, 0, n) {
         answer = max(answer, lis(i) + lds(i) - 1);
      }
      puts(answer);
   }
   return 0;
}
