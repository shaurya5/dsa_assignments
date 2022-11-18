#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		unordered_map<int,int> m;
		for(int i=0; i<n; i++) {
			int a;
			cin >> a;
			m[a - 2*(i+1)]++;
		}

		int count = 0;
		for(auto i=m.begin(); i!=m.end(); i++) {
			if((*i).second > 1) {
				count += ((*i).second) * ((*i).second - 1) / 2;
			}
		}
		cout << count << endl;
	}
	return 0;
}