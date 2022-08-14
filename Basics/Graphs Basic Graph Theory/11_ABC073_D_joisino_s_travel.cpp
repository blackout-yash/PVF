// ABC073 D - joisino's travel
// Link - https://atcoder.jp/contests/abc073/tasks/abc073_d



#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n = 300;
vector <vector<int>> dis(n, vector<int> (n, 1e9));
vector <vector<pair<int, int>>> graph(n);
vector <int> vis(n);

void dijkstra(int source) {
	set <pair<int, int>> s;

	s.insert({0, source});
	dis[source][source] = 0;

	while (!s.empty()) {
		auto node = *s.begin();
		int root = node.second;
		s.erase(s.begin());

		if (vis[root]) continue;
		else vis[root] = 1;

		for (auto x : graph[root]) {
			int child = x.first,
			    weightChild = x.second;

			if (dis[source][root] + weightChild < dis[source][child]) {
				dis[source][child] = dis[source][root] + weightChild;
				s.insert({dis[source][child], child});
			}
		}
	}
}


int main() {

	int n, m, r;
	cin >> n >> m >> r;

	vector <int> arr(r);
	for (auto &xx : arr) cin >> xx;

	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;

		graph[u].push_back({v, wt});
		graph[v].push_back({u, wt});
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		fill(vis.begin(), vis.end(), 0);
	}

	int ans = 1e9;
	sort(arr.begin(), arr.end());
	do {
		int curr = 0;
		for (int i = 1; i < r; i++) curr += dis[arr[i]][arr[i - 1]];
		ans = min(ans, curr);
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ans;

	return 0;
}