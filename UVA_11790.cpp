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

vector<int> h, w, lis, lds, llis, llds;
int n;

void calc_lis () {
   lis[0] = 1;
   llis[0] = w[0];
   REP(i, 1, n) {
      int idx = i;
      llis[idx] = 0;
      FORD(j, i-1, 0) {
         if(h[j] < h[i] && llis[idx] < llis[j]) {
            idx = j;
         }
      }
      lis[i] = lis[idx] + 1;
      llis[i] = llis[idx] + w[i];
   }
}

void calc_lds () {
   lds[0] = 1;
   llds[0] = w[0];
   REP(i, 1, n) {
      int idx = i;
      llds[idx] = 0;
      FORD(j, i-1, 0) {
         if(h[j] > h[i] && llds[idx] < llds[j]) {
            idx = j;
         }
      }
      lds[i] = lds[idx] + 1;
      llds[i] = llds[idx] + w[i];
   }
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int ts;
   cin >> ts;
   FOR(test, 1, ts) {
      cin >> n;
      
      h.assign(n, 0);
      w.assign(n, 0);
      lis.assign(n, 0);
      lds.assign(n, 0);      
      llis.assign(n, 0);
      llds.assign(n, 0);
      
      REP(i, 0, n) cin >> h[i];
      REP(i, 0, n) cin >> w[i];
      
      calc_lis();
      calc_lds();
      
      int lis_lmax = 0, lds_lmax = 0;
      REP(i, 0, n) {
         lis_lmax = max(lis_lmax, llis[i]);
         lds_lmax = max(lds_lmax, llds[i]);
      }
      
      if(lis_lmax >= lds_lmax) {
         printf("Case %d. Increasing (%d). Decreasing (%d).\n", test, lis_lmax, lds_lmax);
      }
      else {
         printf("Case %d. Decreasing (%d). Increasing (%d).\n", test, lds_lmax, lis_lmax);
      }
   }
   return 0;
}
