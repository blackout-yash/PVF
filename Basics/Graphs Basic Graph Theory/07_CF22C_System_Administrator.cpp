// CF22C - System Administrator
// Link - https://codeforces.com/contest/22/problem/C



#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, index;
	cin >> n >> m >> index;

	vector <pair<int, int>> ans;
	vector <int> graph;
	for (int i = 1; i < n; i++) {
		if (i != index) graph.push_back(i);
	}

	graph.push_back(index);
	if (index != n) graph.push_back(n);
	else swap(graph[n - 1], graph[n - 2]);

	for (int i = 1; i < n; i++) {
		ans.push_back({graph[i - 1], graph[i]});
		m--;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 2; j < n - 1; j++) {
			if (m > 0) {
				ans.push_back({graph[i], graph[j]});
				m--;
			} else break;
		}
	}

	if (m != 0) cout << -1;
	else {
		for (auto x : ans) cout << x.first << " " << x.second << endl;
	}

	return 0;
}