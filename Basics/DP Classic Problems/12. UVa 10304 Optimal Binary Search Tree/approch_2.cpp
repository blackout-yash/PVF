// UVa 10304 Optimal Binary Search Tree
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1245



#include <iostream>
#include <vector>

using namespace std;

int dp[300][300], freq[300], store[300];

void preCompute(int n) {
	for (int i = 1; i <= n; i++) store[i] = store[i - 1] + freq[i];
}

int sum(int start, int end) {
	return store[end] - store[start - 1];
}

int minCost(int i, int j) {
	if (i >= j) return 0;
	else if (dp[i][j] != -1) return dp[i][j];

	int ans = 1e9;
	for (int k = i; k <= j; k++) {
		int left = minCost(i, k - 1) + sum(i, k - 1);
		int right = minCost(k + 1, j) + sum(k + 1, j);
		ans = min(ans, left + right);
	}

	return dp[i][j] = ans;
}

void clear(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) dp[i][j] = -1;
	}
}

int main() {
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) cin >> freq[i];
		preCompute(n);
		clear(n);
		cout << minCost(1, n) << "\n";
	}
}