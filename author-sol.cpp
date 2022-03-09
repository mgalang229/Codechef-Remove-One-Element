#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_set<int> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	vector<int> b(n - 1);
	for(int i = 0; i < n - 1; i++) {
		cin >> b[i];
	}
	// sort the sequences in non-decreasing order
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	// since only 1 element will be removed, we can only start the sequence either in 
	// i = 0 or i = 1 (0 <= i <= n - 1) and if we start at i = 1, then we just need to check if
	// all the differences (b[0] - diff, b[1] - diff, ..., b[n-1] - diff) is composed of the remaining
	// elements in the original array, if not, then it means that the sequence started at i = 0
	// x = b[0] - a[1]
	// a[1] = b[0] - diff
	int ans = b[0] - a[1];
	for(int x : b) {
		if(s.count(x - ans) == 0) {
			ans = b[0] - a[0];
			break;
		}
	}
	if(ans <= 0) { // edge-case
		ans = b[0] - a[0];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		TestCase();
	}
	return 0;
}

