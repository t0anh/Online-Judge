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

vector<int> seq;
vector<int> idx;
vector<int> arr;
vector<int> trace;

void print (int idx) {
   if(idx != -1) {
      print(trace[idx]);
      cout << arr[idx] << endl;
   }
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   for(int token; cin >> token; arr.push_back(token));
   
   idx.resize(arr.size());
   trace.resize(arr.size());
   
   int last = 0;
   REP(i, 0, arr.size()) {
      auto pos = lower_bound(seq.begin(), seq.end(), arr[i]);
      int k = (int)(pos - seq.begin());                  
      if(pos == seq.end()) {
         seq.push_back(arr[i]);
         last = k;
      }
      else {
         seq[k] = arr[i];         
      }
      idx[k] = i;      
      trace[i] = (k == 0) ? -1 : idx[k-1];      
      if(k == sz(seq) - 1) last = idx[k];
   }
   cout << sz(seq) << endl << "-" << endl;
   print(last);
   return 0;
}
