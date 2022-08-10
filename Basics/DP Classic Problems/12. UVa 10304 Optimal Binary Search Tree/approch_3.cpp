// UVa 10304 Optimal Binary Search Tree
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1245



#include <iostream>
#include <vector>

using namespace std;

int freq[300], store[300];

void preCompute(int n) {
	for (int i = 1; i <= n; i++) store[i] = store[i - 1] + freq[i];
}

int sum(int start, int end) {
	return store[end] - store[start - 1];
}

int minCost(int n) {
	vector <vector<int>> dp(n + 5, vector<int> (n + 5));

	for (int i = n; i > 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			int ans = 1e9;

			// here, consider only for substring from i to j, i.e. 234 if i == 2 && j == 4
			// for 234, there will be 3 case:

			// Case 1: root = 2, left = NULL, right = 34
			// Case 2: root = 3, left = 2, right = 4
			// Case 3: root = 4, left = 23, right = NULL

			// k is for checking all possible roots

			for (int k = i; k <= j; k++) {
				int left = dp[i][k - 1] + sum(i, k - 1);
				int right = dp[k + 1][j] + sum(k + 1, j);

				ans = min(ans, left + right);
			} dp[i][j] = ans;
		}
	}
	return dp[1][n];
}

int main() {

	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) cin >> freq[i];
		preCompute(n);
		cout << minCost(n) << "\n";
	}
}