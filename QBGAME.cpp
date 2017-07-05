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

#define long            long long

#define getBit(num, i)  ((num >> (i)) & 1)
using namespace std;
const int N = 10005;

vector<int> state;
long dp[N][1024];
int m[10][N];

inline bool isOK(int mask) {
   FOR(i, 1, 7) {
      if(getBit(mask, i) && getBit(mask, i-1)) return false;
   }
   return true;
}

void prepare () {
   REP(mask, 0, 1<<8) {
      if(isOK(mask)) state.push_back(mask);
   }
}

inline int getSum (int col, int mask) {
   int res = 0;
   FOR(i, 1, 8) {
      if(getBit(mask, i-1)) res += m[i][col];
   }
   return res;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   int n;
   cin >> n;
   FOR(i, 1, 8) {
      FOR(j, 1, n) {
         cin >> m[i][j];
      }
   }
   
   bool pig = true;
   int vmax = INT_MIN;
   FOR(i, 1, 8) {
      FOR(j, 1, n) {
         if(m[i][j] >= 0) pig = false;
         vmax = max(vmax, m[i][j]);
      }
      if(!pig) break;
   }
   if(pig) {
      cout << vmax << endl;
      return 0;
   }
   
   prepare();  
   
   for(auto mask : state) {
      dp[1][mask] = max(0, getSum(1, mask));
   }
   
   FOR(c, 2, n) {
      for(int mask1 : state) {
         dp[c][mask1] = -1;
         for(int mask2: state) {
            if(mask1 & mask2) continue;
            dp[c][mask1] = max(dp[c][mask1], dp[c-1][mask2] + getSum(c, mask1));
         }
      }
   }
   long ans = 0;
   for(auto mask : state) {
      ans = max(ans, dp[n][mask]);
   }
   cout << ans << endl;
   return newline, 0;
}
