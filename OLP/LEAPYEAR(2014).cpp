#include <bits/stdc++.h>

using namespace std;

int a, b;

bool isLeapYear (int year) {
	int rem = year % 19;
	if (rem == 0 || rem == 3 || rem == 6 || rem == 9 || rem == 11 || rem == 14 || rem == 17) {
		return true;
	}
	return false;
}


int main() {
//	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d %d", &a, &b);
	int count = 0;
	for (int i = a; i <= b; ++i) {
		if (isLeapYear(i)) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}

