// ABC061 B - Counting Roads
// Link - https://atcoder.jp/contests/abc061/tasks/abc061_b



#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector <int> deg(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		deg[u]++; deg[v]++;
	}

	for (int i = 1; i <= n; i++) cout << deg[i] << endl;
}