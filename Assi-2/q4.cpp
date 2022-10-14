#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSort(int n, queue<int> q) {
	stack<int> s;
	int result = 1;
	int frontElem;

	while(!q.empty()) {
		frontElem = q.front();
		q.pop();

		if(frontElem == result) {
			result++;
		}
		else {
			if(s.empty()) 
				s.push(frontElem);
			else if(!s.empty() && s.top() < frontElem) 
				return false;
			else
				s.push(frontElem);
		}
	}

	while(!s.empty() && s.top() == result) {
		s.pop();
		result++;
	}

	if(result == n + 1 && s.empty()) 
		return true;

	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		queue<int> q;
		int x;
		for(int i = 0; i < n; i++) {
			cin >> x;
			q.push(x);
		}
		
		checkSort(n, q) ? cout << "YES\n" : cout << "NO\n";
	}
	
}