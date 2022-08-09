// UVa 357 Let Me Count The Ways
// Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=293



// Approch I
#include <iostream>

using namespace std;
#define ll long long

ll dp[30001][5];
int coins[] = {1, 5, 10, 25, 50};

ll diffComb(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			if (!i) {
				dp[i][j] = 1;
				continue;
			}

			ll ans1 = 0;
			if (i >= coins[j]) ans1 = dp[i - coins[j]][j];

			ll ans2 = 0;
			if (j) ans2 = dp[i][j - 1];

			dp[i][j] = ans1 + ans2;
		}
	}

	return dp[n][4];
}

int main() {
	while (1) {
		string s;
		cin >> s;

		if (s.empty()) break;

		ll n = stoi(s);

		ll ans = diffComb(n);
		if (ans == 1) cout << "There is only 1 way to produce " << n << " cents change.";
		else cout << "There are " << ans << " ways to produce " << n << " cents change.";
		cout << "\n";
	}

	return 0;
}



// Approch II
#include <iostream>

using namespace std;
#define ll long long

ll dp[30001][5];
int coins[] = {1, 5, 10, 25, 50};

ll diffComb(int i, int n) {
	if (n == 0) return 1;
	if (n < 0 || i == -1) return 0;
	else if (dp[n][i] != -1) return dp[n][i];

	ll ans1 = diffComb(i, n - coins[i]);
	ll ans2 = diffComb(i - 1, n);

	return dp[n][i] = ans1 + ans2;
}

void clear(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 5; j++) dp[i][j] = -1;
	}
}

int main() {
	while (1) {
		string s;
		cin >> s;

		if (s.empty()) break;

		ll n = stoi(s);
		clear(n);

		ll ans = diffComb(4, n);
		if (ans == 1) cout << "There is only 1 way to produce " << n << " cents change.";
		else cout << "There are " << ans << " ways to produce " << n << " cents change.";
		cout << "\n";
	}

	return 0;
}