// CF330B - Road Construction
// Link - https://codeforces.com/problemset/problem/330/B



#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	map <int, int> noRoads;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		noRoads[a] = 1;
		noRoads[b] = 1;
	}

	vector <pair<int, int>> ans;
	for (int i = 1; i <= n; i++) {
		if (!noRoads.count(i)) {
			for (int j = 1; j <= n; j++) {
				if (i != j) ans.push_back({i, j});
			} break;
		}
	}

	cout << ans.size() << "\n";
	for (auto x : ans) cout << x.first << " " << x.second << "\n";
}