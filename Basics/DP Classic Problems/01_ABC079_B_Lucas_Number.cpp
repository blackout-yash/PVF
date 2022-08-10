// ABC079 B - Lucas Number
// Link - https://atcoder.jp/contests/abc079/tasks/abc079_b



#include <iostream>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;

	if (n == 0) cout << 2;
	else {
		ll prevTwo = 2, prev = 1;
		for (int i = 2; i <= n; i++) {
			ll curr = prevTwo + prev;
			prevTwo = prev;
			prev = curr;
		} cout << prev;
	}
}