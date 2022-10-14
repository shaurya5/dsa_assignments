#include <iostream>
#include "timer.h"
using namespace std;

bool solve(int *arr, int left, int right, int target) {
	if(left == right) return false;
	if(arr[left] + arr[right] == target) {
		return true;
	}
	if(arr[left] + arr[right] >= target) {
		return solve(arr, left, right-1, target);
	}
	return solve(arr, left+1, right, target);
}

int main() {
	Timer timer;
	timer.start();
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	cout << solve(arr, 0, n-1, 10) << "\n";
	timer.stop();
	double milliSecs = timer.getDurationInMilliSeconds();
	cout << "Execution Time: " << milliSecs << " ms." << "\n";

  return 0;
}