// CF416B - Art Union
// Link - https://codeforces.com/problemset/problem/416/B



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int arr[n + 1][m + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}

	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (!i || !j) dp[i][j] = 0;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + arr[i][j];
		} if (i) cout << dp[i][m] << " ";
	}

	return 0;
}