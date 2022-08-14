// CF574B - Bear and Three Musketeers
// Link - https://codeforces.com/contest/574/problem/B



#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector <int> deg(n + 1);
	map <pair<int, int>, int> store;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		store[ {u, v}] = 1;
		deg[u]++; deg[v]++;
	}

	int ans = 1e9;
	for (auto x : store) {
		int u = x.first.first, v = x.first.second;
		for (int i = 1; i <= n; i++) {
			if (u != i && v != i && (store.count({u, i}) || store.count({i, u})) && (store.count({v, i}) || store.count({i, v}))) {
				ans = min(ans, deg[i] + deg[u] + deg[v] - 6);
			}
		}
	}

	(ans == 1e9) ? cout << -1 : cout << ans;

	return 0;
}