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