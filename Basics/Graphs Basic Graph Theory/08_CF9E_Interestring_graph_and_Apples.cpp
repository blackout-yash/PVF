// CF9E - Interestring graph and Apples
// Link - https://codeforces.com/problemset/problem/9/E



#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector <vector<int>> graph(100);
vector <int> vis(100), path;
int isCycle = 0, ans = 1;

void dfs(int root, int par = -1) {
	vis[root] = 1;
	path.push_back(root);

	int cnt = 0;
	for (int child : graph[root]) {
		cnt++;
		if (vis[child]) {
			if (child == root) isCycle++;
			else {
				if (child == par) {}
				else if (vis[child]) isCycle++;
			}
			continue;
		} dfs(child, root);
	}

	if (cnt > 2) ans = 0;
}

bool isConnected(int root, int v) {
	if (root == v) return true;
	vis[root] = 1;

	for (int child : graph[root]) {
		if (vis[child]) continue;

		if (isConnected(child, v)) return true;
	}

	return false;
}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector <set <int>> alpha;
	for (auto x : graph) {
		set <int> temp;
		for (auto y : x) temp.insert(y);
		alpha.push_back(temp);
	}

	vector <pair<int, int>> store;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && alpha[i].size() <= 1 || (i == n && !cnt)) {
			path.clear();
			dfs(i);
			cnt++;
			store.push_back({path[0], path.back()});
		}
	}

	if (ans) {
		if (isCycle) {
			if (store.size() == 1) cout << "YES\n0";
			else cout << "NO";
		} else {
			int n = store.size();
			cout << "YES\n" << n << "\n";

			if (n == 1) {
				cout << store[0].first << " " << store[0].second;
				return 0;
			}

			vector <int> temp;
			temp.push_back({store[0].first});
			for (int i = 1; i < n; i++) {
				temp.push_back({store[i].first});
				temp.push_back({store[i].second});
			} temp.push_back({store[0].second});
			sort(temp.begin(), temp.end());

			for (int i = 0; i < size(temp); i++) {
				if (temp[i] != -1) {
					for (int j = i + 1; j < size(temp); j++) {
						if (temp[j] != -1) {
							vis.clear(); vis.resize(100);
							if (!isConnected(temp[i], temp[j])) {
								cout << temp[i] << " " << temp[j] << "\n";
								graph[temp[i]].push_back(temp[j]);
								graph[temp[j]].push_back(temp[i]);
								temp[i] = temp[j] = -1;
								break;
							}
						}
					}
				}
			}

			int _min = 1e9, _max = -1e9;
			for (int i = 0; i < 100; i++) {
				if (graph[i].size() == 1) {
					_min = min(_min, i);
					_max = max(_max, i);
				}
			} cout << _min << " " << _max;;
		}
	} else cout << "NO";

	return 0;
}