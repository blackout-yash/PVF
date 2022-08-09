// UVa 111 History Grading
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=47



// Approach I
#include <iostream>
#include <algorithm>

using namespace std;

int dp[30][30];

int lis(int n, int student[], int order[]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int ans1 = dp[i - 1][j - 1];
			if (student[i] == order[j]) ans1++;

			int ans2 = dp[i - 1][j];
			int ans3 = dp[i][j - 1];

			dp[i][j] = max({ans1, ans2, ans3});
		}
	}

	return dp[n][n];
}

int main() {

	int n;
	cin >> n;

	int order[n + 1], student[n + 1];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		order[x] = i;
	}

	int x;
	while (cin >> x) {
		student[x] = 0;
		for (int i = 1; i < n; i++) {
			cin >> x;
			student[x] = i;
		}

		cout << lis(n, student, order) << "\n";
	}

	return 0;
}



// Approach II
#include <iostream>
#include <algorithm>

using namespace std;

int dp[30][30];

int lis(int n, int m, int student[], int order[]) {
	if (n == 0 || m == 0) return 0;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans1 = lis(n - 1, m - 1, student, order);
	if (student[n] == order[m]) ans1++;

	int ans2 = lis(n - 1, m, student, order);
	int ans3 = lis(n, m - 1, student, order);

	return dp[n][m] = max({ans1, ans2, ans3});
}

void clear(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) dp[i][j] = -1;
	}
}

int main() {

	int n;
	cin >> n;

	int order[n + 1], student[n + 1];
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		order[x] = i;
	}

	int x;
	while (cin >> x) {
		student[x] = 0;
		for (int i = 1; i < n; i++) {
			cin >> x;
			student[x] = i;
		}

		clear(n);
		cout << lis(n, n, student, order) << "\n";
	}

	return 0;
}