// SPOJ EDIST - Edit distance
// Link - https://www.spoj.com/problems/EDIST/



// Approach I
#include <iostream>
#include <algorithm>

using namespace std;

int dp[2020][2020];

int minDistance(int n, int m, string &s1, string &s2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ans1 = 0;
			if (i && j) ans1 = dp[i - 1][j - 1];

			// here, else condition is important
			// it's, (i + j) but, not ((i + 1) + (j + 1)) becoz next we are checking (s1[i] != s2[j])
			// then, logically think why (i + j) not INF
			else ans1 = i + j;
			if (s1[i] != s2[j]) ans1 += 1;

			int ans2 = 0;
			if (i) ans2 = 1 + dp[i - 1][j];
			else ans2 = 1 + (j + 1);

			int ans3 = 0;
			if (j) ans3 = 1 + dp[i][j - 1];
			else ans3 = 1 + (i + 1);

			dp[i][j] = min({ans1, ans2, ans3});
		}
	}

	return dp[n - 1][m - 1];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;

		int n = s1.size(), m = s2.size();

		cout << minDistance(n, m, s1, s2) << "\n";
	}
}




// Approach II
#include <iostream>
#include <algorithm>

using namespace std;

int dp[2020][2020];

int minDistance(int n, int m, string &s1, string &s2) {
	if (n == -1 && m == -1) return 0;
	else if (n == -1) return m + 1;
	else if (m == -1) return n + 1;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans1 = minDistance(n - 1, m - 1, s1, s2);
	if (s1[n] != s2[m]) ans1 += 1;

	int ans2 = 1 + minDistance(n - 1, m, s1, s2);
	int ans3 = 1 + minDistance(n, m - 1, s1, s2);

	return dp[n][m] = min({ans1, ans2, ans3});
}

void clear(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) dp[i][j] = -1;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;

		int n = s1.size(), m = s2.size();
		clear(n, m);

		cout << minDistance(n - 1, m - 1, s1, s2) << "\n";
	}
}