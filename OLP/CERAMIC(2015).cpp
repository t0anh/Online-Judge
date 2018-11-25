#include <bits/stdc++.h>

using namespace std;

typedef struct answer {
	int k;
	int n1, n2;
	
	answer(int _k, int _n1, int _n2) {
		k = _k;
		n1 = _n1;
		n2 = _n2;
	}
	
} Answer;

const int MAXN = 1E5 + 5;

int n, a[MAXN], sum[MAXN];
map<int, int> cnt;
vector<Answer> ans;


void prepare (int n) {
	sum[0] = a[0];
	for (int i = 1; i < n; ++i) {
		sum[i] = sum[i-1] ^ a[i];
	}
}

int getHash (int i, int j) {
	return sum[j] ^ sum[i-1];
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	prepare(n);
	
	for(int k = 1; k * 2 <= n; ++k) {
		if (n % k == 0) {
			cnt.clear();
			for (int i = 0; i < n; i += k) {
				int hash = getHash(i, i + k - 1);
				cnt[hash]++;
				if(cnt.size() > 2) {
					break;
				} 
			}
			if(cnt.size() == 2) {
				vector<int> count;
				for (auto it: cnt) {
					count.push_back(it.second);
				}
				
				ans.push_back(Answer(k, max(count[0], count[1]), min(count[0], count[1])));
			}
		}
	}
	
	cout << ans.size() << endl;
	for (auto answer: ans) {
		cout << answer.k << " " << answer.n1 << " " << answer.n2 << endl;
	}
	return 0;
}

