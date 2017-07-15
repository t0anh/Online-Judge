#include <bits/stdc++.h>
 
#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)
#define FILL(a, v, n)   for(int i = 0, _n = (n); i <= _n; ++i) a[i] = v
 
#define endl            "\n"
#define newline         cout << "\n"
#define sz(x)           (int)(x.size())
#define debug(x)        cerr << #x << " = " << x << endl
#define debug2(a, i)    cerr << #a << "[" << i << "] = " << a[i] << endl
#define puts(x)         cout << x << endl
#define two(n)               (1 << (n))

using namespace std;
const int N = 2018;

int dp[N][N];
 
int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   string s;
   cin >> s;

   // if a[i] == a[j] then dp[i][j] = dp[i-1][j+1] + 2
   // else  dp[i][j] = max(dp[i+1][j], dp[i][j-1])

   REP(i, 0, sz(s)) {
      dp[i][i] = 1;
   }

   FORD(i, sz(s)-2, 0) {
      REP(j, i+1, sz(s)) {
         if(s[i] == s[j]) {
            if(i == j-1) dp[i][j] = 2;
            else dp[i][j] = dp[i+1][j-1] + 2;
         }
         else 
            dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
      }
   }

   string pre = "";
   string mid = "";
   int i = 0, j = sz(s) - 1;
   while(i <= j) {
      if(dp[i][j] == 1) {
         mid = s.substr(i, 1);
         break;
      }
      if(s[i] == s[j]) {
         pre += s.substr(i, 1);
         ++i;
         --j;
         continue;
      }
      if(dp[i][j] == dp[i+1][j]) ++i;
      else --j;
   }

   string suf = pre; reverse(suf.begin(), suf.end());
   cout << pre << mid << suf << endl;
   return newline, 0;
}  
