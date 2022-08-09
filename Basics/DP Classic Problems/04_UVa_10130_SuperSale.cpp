// UVa 10130 SuperSale
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1071



// Approach I
#include <iostream>

using namespace std;

int dp[1001][31];

int maxValue(int n, int w, int price[], int weight[]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= w; j++) {
			int ans1 = 0;
			if (j >= weight[i]) {
				ans1 = price[i];
				if (i) ans1 += dp[i - 1][j - weight[i]];
			}

			int ans2 = 0;
			if (i) ans2 = dp[i - 1][j];

			dp[i][j] = max(ans1, ans2);
		}
	}

	return dp[n - 1][w];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int price[n], weight[n];
		for (int i = 0; i < n; i++) cin >> price[i] >> weight[i];

		int ans = 0, m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int w;
			cin >> w;

			ans += maxValue(n, w, price, weight);
		} cout << ans << "\n";
	}

	return 0;
}



// Approach II
#include <iostream>

using namespace std;

int dp[1001][31];

int maxValue(int n, int w, int price[], int weight[]) {
	if (n == -1) return 0;
	else if (dp[n][w] != -1) return dp[n][w];

	int ans1 = 0;
	if (w >= weight[n]) ans1 = price[n] + maxValue(n - 1, w - weight[n], price, weight);

	int ans2 = maxValue(n - 1, w, price, weight);

	return dp[n][w] = max(ans1, ans2);
}

void clear(int n, int w) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= w; j++) dp[i][j] = -1;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int price[n], weight[n];
		for (int i = 0; i < n; i++) cin >> price[i] >> weight[i];

		int ans = 0, m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int w;
			cin >> w;

			clear(n, w);
			ans += maxValue(n - 1, w, price, weight);
		} cout << ans << "\n";
	}

	return 0;
}