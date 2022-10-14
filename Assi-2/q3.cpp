#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void solve(int *arr,int n){
	vector<int> ans(n,-1);
	stack<int> s;
	s.push(arr[n-1]);
	
	for(int i=n-2; i>=0; i--){
		while(!s.empty() && arr[i]>=s.top()){
			s.pop();
		}
		if(!s.empty()){
			ans[i] = s.top();
		}
		s.push(arr[i]);
	}
 
	for(int val : ans){
		cout << val << " ";
	}
}
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i=0;i<n;i++)
		cin >> arr[i];
		solve(arr,n);
		cout << endl;
	}
}