#include <iostream>

using namespace std;

const int MAX_EXP = 38;

long long acc[40];
long long power3[40];
int cnt[40];

void init () {
    acc[0] = 1;
    power3[0] = 1;
    for (int i = 1; i <= MAX_EXP; ++i) {
        power3[i] = power3[i-1] * 3;
        acc[i] = acc[i-1] + power3[i];
    }
} 

int main() {
	
    init();

    long long m;

    cin >> m;

    for (int i = 0; i <= MAX_EXP; ++i) {
        cnt[i]++;
    }

    long long rem = acc[MAX_EXP] - m;
    while (rem != 0) {
        for (int i = MAX_EXP; i >= 0; --i) {
            if (power3[i] <= rem) {
                rem -= power3[i];
                cnt[i]--;
                break;
            }
        }
    }
    
    bool empty = true;
    for (int i = 0; i <= MAX_EXP; ++i) {
        if (cnt[i] < 0) {
            cout << i << " ";
            empty = false;
        }
    }
    puts(empty ? "-1" : "");
    for (int i = 0; i <= MAX_EXP; ++i) {
        if (cnt[i] > 0) {
            cout << i << " ";
        }
    }
	return 0;
}
