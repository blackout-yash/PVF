// CF990D - Graph And Its Complement
// Link - https://codeforces.com/problemset/problem/990/D



#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	vector <vector<int>> ans(n + 1, vector<int> (n + 1));

	if (a == 1) {
		b = n - b;

		int req = n - a;
		if (n * (n - 1) < 2 * (req + b)) {
			cout << "NO";
			return 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (b && j == i + 1) b--;
				else ans[i][j] = ans[j][i] = 1;
			}
		}

		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) cout << ans[i][j];
			cout << "\n";
		}
	} else if (b == 1) {
		while (a--) {
			if (a == 0) {
				for (int i = 1; i < n; i++) ans[i][i + 1] = ans[i + 1][i] = 1;
			} else n--;
		}

		n = ans[0].size();
		cout << "YES\n";
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) cout << ans[i][j];
			cout << "\n";
		}
	} else cout << "NO";

	return 0;
}