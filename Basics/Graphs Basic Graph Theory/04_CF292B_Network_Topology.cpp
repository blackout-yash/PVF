// CF292B - Network Topology
// Link - https://codeforces.com/problemset/problem/292/B



#include <iostream>
#include <vector>

using namespace std;

int n = 2 * 1e5;
vector <vector<int>> graph(n);
vector <int> vis(n);

bool isRing(int root) {
	vis[root] = 1;

	int cnt = 0;
	for (int child : graph[root]) {
		cnt++;
		if (vis[child]) continue;

		if (!isRing(child)) return false;
	}

	if (cnt != 2) return false;
	return true;
}

bool isBus(int root) {
	vis[root] = 1;

	int cnt = 0;
	for (int child : graph[root]) {
		cnt++;
		if (vis[child]) continue;

		if (!isBus(child)) return false;
	}

	if (cnt > 2) return false;
	return true;
}

bool isStar(int root, int start) {
	vis[root] = 1;

	int cnt = 0;
	for (int child : graph[root]) {
		if (vis[child]) continue;
		cnt++;
		if (!isStar(child, start)) return false;
	}

	if (root == start) return true;
	else if (cnt) return false;
	return true;
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

	fill(vis.begin(), vis.end(), 0);
	if (isRing(1)) {
		cout << "ring topology";
		return 0;
	}

	fill(vis.begin(), vis.end(), 0);
	if (isBus(1)) {
		cout << "bus topology";
		return 0;
	}

	fill(vis.begin(), vis.end(), 0);
	if (isStar(1, 1)) cout << "star topology";
	else {
		fill(vis.begin(), vis.end(), 0);
		if (isStar(graph[1][0], graph[1][0])) cout << "star topology";
		else cout << "unknown topology";
	}

	return 0;
}