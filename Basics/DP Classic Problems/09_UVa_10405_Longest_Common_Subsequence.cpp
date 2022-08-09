// UVa 10405 Longest Common Subsequence
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346




// Approach I
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1010][1010];

int lis(int n, int m, string &s1, string &s2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ans1 = 0;
			if (s1[i] == s2[j]) ans1 = 1;
			if (i && j) ans1 += dp[i - 1][j - 1];

			int ans2 = 0;
			if (i) ans2 = dp[i - 1][j];

			int ans3 = 0;
			if (j) ans3 = dp[i][j - 1];

			dp[i][j] = max({ans1, ans2, ans3});
		}
	}
	return dp[n - 1][m - 1];
}

int main() {

	while (1) {

		string s1, s2;
		getline (cin, s1);
		getline (cin, s2);

		if (s1.empty() && s2.empty()) break;
		int n = s1.size(), m = s2.size();

		cout << lis(n, m, s1, s2) << "\n";
	}

	return 0;
}




// Approach II
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1010][1010];

int lis(int n, int m, string &s1, string &s2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ans1 = 0;
			if (s1[i] == s2[j]) ans1 = 1;
			if (i && j) ans1 += dp[i - 1][j - 1];

			int ans2 = 0;
			if (i) ans2 = dp[i - 1][j];

			int ans3 = 0;
			if (j) ans3 = dp[i][j - 1];

			dp[i][j] = max({ans1, ans2, ans3});
		}
	}
	return dp[n - 1][m - 1];
}

int main() {

	while (1) {

		string s1, s2;
		getline (cin, s1);
		getline (cin, s2);

		if (s1.empty() && s2.empty()) break;
		int n = s1.size(), m = s2.size();

		cout << lis(n, m, s1, s2) << "\n";
	}

	return 0;
}