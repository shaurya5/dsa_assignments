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
	int arr[] = {1,2,3,4,5,6,7,8,9};
	cout << solve(arr, 0, 8, 10) << "\n";
	timer.stop();
	double milliSecs = timer.getDurationInMilliSeconds();
	cout << "Execution Time: " << milliSecs << " ms." << "\n";

  return 0;
}