#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> q;
		while(n--){
			int x;
			cin >> x;
			q.push(x);
		}

		int timeTaken = 0;
		while(q.size() > 1) {
			int time1 = q.top();
			q.pop();
			int time2 = q.top();
			q.pop();
			timeTaken += (time1 + time2);
			q.push(time1+time2);
		}

		cout << timeTaken << endl;
	}
	return 0;
}