#include <bits/stdc++.h>

#define getbit(mask, idx) ((mask >> (idx)) & 1)

using namespace std;

const int INF = 1E9;
int dist[55][55];
int dp[55][1 << 15];
int amazonDiff[15];
int shops[15];
int N, M, k;
int finalState;

int TSP (int here, int state) {
	if(state == finalState) return dist[here][0];
	int & ret = dp[here][state];
	if(ret != -1) return ret;
	ret = INF;
	for(int i = 0; i < k; ++i) {
		if(getbit(state, i)) continue;
		int nextState = state | (1 << i);
		ret = min(ret, min(amazonDiff[i] + TSP(here, nextState), dist[here][shops[i]] + TSP(shops[i], nextState)));
	}
	return ret;
}

int main() {
#ifndef Home
   freopen ("input.txt", "r", stdin);
#endif
	int testCases;
	scanf("%d", &testCases);
	while(testCases--) {
		scanf("%d %d", &N, &M);
		
		memset(dp, -1, sizeof dp);		
		for(int i = 0; i <= N; ++i)
			for(int j = 0; j <= N; ++j)
				dist[i][j] = (i == j) ? 0 : INF;
				
		int from, to, dollars, cents;
		char dot;
		for(int i = 0; i < M; ++i) {
			scanf("%d %d %d %c %d", &from, &to, &dollars, &dot, &cents);
			dist[to][from] = dist[from][to] = min(dist[from][to], dollars*100 + cents);

		}
		
		for(int i = 0; i <= N; ++i) {
			for(int u = 0; u <= N; ++u) {
				for(int v = 0; v <= N; ++v) {
					dist[u][v] = min(dist[u][v], dist[u][i] + dist[i][v]);
 				}
			}
		}
		
		scanf("%d", &k);
		int amazonTotal = 0;
		for(int i = 0; i < k; ++i) {
			scanf("%d %d %c %d", &shops[i], &dollars, &dot, &cents);
			amazonDiff[i] = dollars*100 + cents;
			amazonTotal += amazonDiff[i];			
		}
		
		finalState = (1 << k) - 1;		
		int answer = amazonTotal - TSP(0, 0);
		if(answer > 0) printf("Daniel can save $%d.%02d\n", answer/100, answer%100);
		else printf("Don't leave the house\n");
	}
   return 0;
}
