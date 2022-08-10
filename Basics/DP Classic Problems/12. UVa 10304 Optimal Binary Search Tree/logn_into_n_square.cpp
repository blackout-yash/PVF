// TLE
// UVa 10304 Optimal Binary Search Tree
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1245



#include <iostream>
#include <map>

using namespace std;

int dp[300][300], freq[300], store[300];
map <pair<int, int>, int> m;

void preCompute(int n) {
	for (int i = 1; i <= n; i++) store[i] = store[i - 1] + freq[i];
}

int sum(int start, int end) {
	return store[end] - store[start - 1];
}

int dfs(int start, int end, int level) {
	if (start == end) return level * freq[start];
	else if (start > end) return 0;
	else if (dp[start][end] != -1) {
		int cal = m[ {start, end}];
		return dp[start][end] + (sum(start, end) * (level - cal));
	}

	int ans = 1e9;
	for (int root = start; root <= end; root++) {
		int left = dfs(start, root - 1, level + 1);
		int curr = level * freq[root];
		int right = dfs(root + 1, end, level + 1);
		ans = min(ans, left + curr + right);
	}

	m[ {start, end}] = level;
	return dp[start][end] = ans;
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
		cout << dfs(1, n, 0) << "\n";
	}
}