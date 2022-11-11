#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int arr[n+1];
		for(int i=1; i<=n; i++) {
			cin >> arr[i];
		}
		for(auto i : arr) cout << i << endl;
	}

	return 0;
}