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

const int MX = 2017;

int n, m;
char mp[MX][MX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
#ifndef Home
   freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
   while(cin >> n && n) {
      queue<iii> que;   
      int x, y;
      REP(i, 0, n) {
         cin >> x >> y;
         que.push(iii(x, y, 0));
      }
      
      cin >> m;
      REP(i, 0, m) {
         cin >> x >> y;
         mp[x][y] = '2';
      }
      
      while(!que.empty()) {
         int x, y, dist;
         tie(x, y, dist) = que.front();
         que.pop();
         if(mp[x][y] == '2') {
            puts(dist);
            break;
         }
         if(mp[x][y] == 'x') continue;
         mp[x][y] = 'x';
         REP(i, 0, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx <= 2000 && ny >= 0 && ny <= 2000 && mp[nx][ny] != 'x') {
               que.push(iii(nx, ny, dist+1));
            }
         }
      }
      memset(mp, 0, sizeof mp);
   }   
   return 0;
}
