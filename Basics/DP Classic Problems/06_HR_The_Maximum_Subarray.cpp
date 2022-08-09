// HR The Maximum Subarray
// Link - https://www.hackerrank.com/challenges/maxsubarray/problem



#include <iostream>
#include <vector>

using namespace std;

int subArray(vector <int> &arr) {
	int ans = arr[0], curr = 0;
	for (auto x : arr) {
		curr += x;
		ans = max(ans, curr);
		curr = max(0, curr);
	} return ans;
}

int subSequence(vector <int> &arr) {
	int ans = arr[0], curr = 0;
	for (auto x : arr) {
		if (x >= 0) {
			curr += x;
			ans = max(ans, curr);
		} else ans = max(ans, x);
	} return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector <int> arr(n);
		for (auto &xx : arr) cin >> xx;

		cout << subArray(arr) << " " << subSequence(arr) << "\n";
	}

	return 0;
}