#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> solve(int n, int *arr) {
	stack<int> s;
	s.push(arr[0]);
	vector<int> ans(n);
	for(int i = 1; i < n; i++) {
		while(!s.empty() && arr[s.top()] <= arr[i]) {
			ans[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}

	while(!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		vector<int> ans = solve(n, arr);
		for(int i : ans)
			cout << i << " ";
		cout << "\n";
	}
}