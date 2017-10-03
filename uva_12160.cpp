#include <bits/stdc++.h>

#define REP(i, a, b)  for(int i = a, _b = b; i < _b; ++i)
#define FOR(i, a, b)  for(int i = a, _b = b; i <= b; ++i)
#define FORD(i, a, b) for(int i = a, _b = b; i >= b; --i)

#define endl          "\n"
#define newline       cout << "\n"
#define puts(_xxx_)   cout << _xxx_ << "\n"
#define db1(x)        cout << #x << " = " << x << "\n"
#define db2(a, i)     cout << #a << "[" << i << "] = " << a[i] << "\n"
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long llong;

int src, des, n;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
   for(int case_no = 1; ; ++case_no) {
      cin >> src >> des >> n;
      if(src + des + n == 0) break;
      cout << "Case " << case_no << ": ";      
      vector<int> buttons(n);
      REP(i, 0, n) {
         cin >> buttons[i];
      }
      int answer = -1;
      vector<bool> was(10000, false);      
      queue<ii> que;
      que.push(ii(src, 0));
      while(!que.empty()) {
         int cur = que.front().first;
         int steps = que.front().second;
         que.pop();
         if(cur == des) {
            answer = steps;
            break;
         }
         if(was[cur]) continue;
         was[cur] = true;
         for(int v: buttons) {
            que.push(ii((cur + v) % 10000, steps+1));
         }
      }
      if(answer == -1) puts("Permanently Locked");
      else puts(answer);
   }     
   return 0;
}
