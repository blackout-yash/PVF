// TLE
// UVa 10304 Optimal Binary Search Tree
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1245



#include <iostream>

using namespace std;

int dp[300][300][300], freq[300];

int dfs(int start, int end, int level) {
	if (start == end) return level * freq[start];
	else if (start > end) return 0;
	else if (dp[start][end][level] != -1) return dp[start][end][level];

	int ans = 1e9;
	for (int root = start; root <= end; root++) {
		int left = dfs(start, root - 1, level + 1);
		int curr = level * freq[root];
		int right = dfs(root + 1, end, level + 1);
		ans = min(ans, left + curr + right);
	}

	return dp[start][end][level] = ans;
}

void clear(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) dp[i][j][k] = -1;
		}
	}
}

int main() {

	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) cin >> freq[i];

		clear(n);
		cout << dfs(1, n, 0) << "\n";
	}
}