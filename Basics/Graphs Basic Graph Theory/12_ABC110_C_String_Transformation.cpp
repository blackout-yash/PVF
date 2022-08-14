// ABC110 C - String Transformation
// Link - https://atcoder.jp/contests/abc110/tasks/abc110_c



#include <iostream>
#include <map>
#include <set>


using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	map <char, set <char>> m1, m2;
	int n = s1.size();
	for (int i = 0; i < n; i++) {
		m1[s1[i]].insert(s2[i]);
		m2[s2[i]].insert(s1[i]);
	}

	int _max = 0;
	for (auto x : m1) _max = max(_max, (int) x.second.size());
	for (auto x : m2) _max = max(_max, (int) x.second.size());

	if (_max > 1) cout << "No";
	else cout << "Yes";

	return 0;
}