// UVa 10003 Cutting Sticks
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944




// Approach I
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[100][100];

int minCost(int i, int j, vector <int> &cut) {
	if (i == j) return 0;
	else if (dp[i][j] != -1) return dp[i][j];


	int ans = 1e9;
	for (int k = i; k < j; k++) {
		if (cut[i] < cut[k] && cut[k] < cut[j]) {

			int left = minCost(i, k, cut);
			int curr = (cut[j] - cut[i]);
			int right = minCost(k, j, cut);

			ans = min(ans, left + curr + right);
		}
	} if (ans == 1e9) ans = 0;

	return dp[i][j] = ans;
}

void clear(int n) {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) dp[i][j] = -1;
	}
}

int main() {
	while (1) {
		int l;
		cin >> l;

		if (!l) break;

		int n;
		cin >> n;

		vector <int> cut(n);
		for (auto &xx : cut) cin >> xx;

		cut.insert(cut.begin(), 0);
		cut.push_back(l);
		clear(n);

		cout << "The minimum cutting is " << minCost(0, n + 1, cut) << ".\n";
	}

	return 0;
}




// Approach II
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[100][100];

int minCost(int n, vector <int> &cut) {
	for (int i = n + 1; i >= 0; i--) {
		for (int j = 0; j <= n + 1; j++) {
			if (i >= j) {
				dp[i][j] = 0;
				continue;
			}

			int ans = 1e9;
			for (int k = i; k < j; k++) {
				if (cut[i] < cut[k] && cut[k] < cut[j]) {

					int left = dp[i][k];
					int curr = (cut[j] - cut[i]);
					int right = dp[k][j];

					ans = min(ans, left + curr + right);
				}
			} if (ans == 1e9) ans = 0;
			dp[i][j] = ans;
		}
	}

	return dp[0][n + 1];
}

int main() {
	while (1) {
		int l;
		cin >> l;

		if (!l) break;

		int n;
		cin >> n;

		vector <int> cut(n);
		for (auto &xx : cut) cin >> xx;

		cut.insert(cut.begin(), 0);
		cut.push_back(l);

		cout << "The minimum cutting is " << minCost(n, cut) << ".\n";
	}

	return 0;
}