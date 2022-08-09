// SPOJ FARIDA - Princess Farida
// Link - https://www.spoj.com/problems/FARIDA/



// Approach I
#include <iostream>

using namespace std;
#define ll long long

ll dp[(int)1e4 + 1][2];

ll maxCoins(int n, int coins[]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (j) {
				ll ans1 = coins[i], ans2 = 0;
				if (i) {
					ans1 += dp[i - 1][0];
					ans2 += dp[i - 1][1];
				}
				dp[i][j] = max(ans1, ans2);
			} else {
				ll ans = 0;
				if (i) ans = dp[i - 1][1];
				dp[i][j] = ans;
			}
		}
	}

	return dp[n - 1][1];
}

int main() {
	int t1, t2 = 0;
	cin >> t1;

	while (t1-- && ++t2) {
		cout << "Case " << t2 << ": ";

		int n;
		cin >> n;

		int coins[n];
		for (auto &x : coins) cin >> x;

		cout << maxCoins(n, coins) << "\n";
	}
}




// Approach II
#include <iostream>

using namespace std;
#define ll long long

ll dp[(int)1e4 + 1][2];

ll maxCoins(int n, int take, int coins[]) {
	if (n == -1) return 0;
	else if (dp[n][take] != -1) return dp[n][take];
	else if (!take) return dp[n][take] = maxCoins(n - 1, 1, coins);

	ll ans1 = coins[n] + maxCoins(n - 1, 0, coins);
	ll ans2 = maxCoins(n - 1, 1, coins);

	return dp[n][take] = max(ans1, ans2);
}

void clear(int n) {
	for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = -1;
}

int main() {
	int t1, t2 = 0;
	cin >> t1;

	while (t1-- && ++t2) {
		cout << "Case " << t2 << ": ";

		int n;
		cin >> n;

		int coins[n];
		for (auto &x : coins) cin >> x;
		clear(n);

		cout << maxCoins(n - 1, 1, coins) << "\n";
	}
}