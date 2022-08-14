// CF402C - Searching for Graph
// Link - https://codeforces.com/problemset/problem/402/C



#include <iostream>
#include <map>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {

		int n, p;
		cin >> n >> p;

		int total = n + p;
		map <pair<int, int>, int> ans;
		ans[ {n, 1}] = 1;
		for (int i = 1; i < n; i++) ans[ {i, i + 1}] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (total) {
					if (i != j && !ans.count({i, j}) && !ans.count({j, i})) {
						ans[ {i, j}] = 1;
						total--;
					}
				} else break;
			}
		}

		for (auto x : ans) {
			cout << x.first.first << " " << x.first.second << endl;
		}

	}
	return 0;
}