// ABC054 C - One-stroke Path
// Link - https://atcoder.jp/contests/abc054/tasks/abc054_c



#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <vector<int>> graph(10);
vector <int> vis(10);

int dfs(int root, set <int> &s, int n) {
	if (s.size() == n) return 1;
	vis[root] = 1;

	int ans = 0;
	for (int child : graph[root]) {
		if (vis[child]) continue;

		s.insert(child);
		ans += dfs(child, s, n);

		s.erase(child);
	} vis[root] = 0;

	return ans;
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

	set <int> s; s.insert(1);
	cout << dfs(1, s, n);

}