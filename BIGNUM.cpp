#include <bits/stdc++.h>
#include "boost/multiprecision/cpp_int.hpp" 

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
#define two(n)          (1 << (n))

using namespace std;
typedef boost::multiprecision::cpp_int Bigint;
 
int main() {
   ios::sync_with_stdio(false); cin.tie(0);
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
   Bigint A, B;
   cin >> A >> B;
   puts(A + B);
   puts(A - B);
   puts(A * B);
   return newline, 0;
}  
