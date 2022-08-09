// UVa 562 Dividing coins
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503



// Approach I
#include <iostream>

using namespace std;

int dp[101][60000];

bool isPossible(int n, int sum, int coins[]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j == 0) {
				dp[i][j] = 1;
				continue;
			}

			if (i) {
				bool take = 0;
				if (j >= coins[i]) take = dp[i - 1][j - coins[i]];

				bool notTake = dp[i - 1][j];

				dp[i][j] = (take | notTake);
			} else dp[i][j] = (j == coins[i]);
		}
	}

	return dp[n - 1][sum];
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		if (!n) {
			cout << 0 << "\n";
			continue;
		}

		int coins[n], sum = 0;
		for (auto &xx : coins) cin >> xx, sum += xx;

		int mid = sum / 2;
		while (mid > -1) {
			if (isPossible(n, mid, coins)) {
				cout << sum - (2 * mid) << "\n";
				break;
			} mid--;
		}
	}
	return 0;
}



// Approach II
#include <iostream>

using namespace std;

int dp[101][60000];

bool isPossible(int n, int sum, int coins[]) {
	if (sum == 0) return true;
	else if (n == -1 || sum < 0) return false;
	else if (dp[n][sum] != -1) return dp[n][sum];

	bool take = isPossible(n - 1, sum - coins[n], coins);
	bool notTake = isPossible(n - 1, sum, coins);

	return dp[n][sum] = (take | notTake);
}

void clear(int n, int sum) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= sum; j++) dp[i][j] = -1;
	}
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int coins[n], sum = 0;
		for (auto &xx : coins) cin >> xx, sum += xx;

		clear(n, sum);
		int mid = sum / 2;
		while (mid > -1) {
			if (isPossible(n - 1, mid, coins)) {
				cout << sum - (2 * mid) << "\n";
				break;
			} mid--;
		}
	}
	return 0;
}