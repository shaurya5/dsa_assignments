#include <iostream>
#include <time.h>
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
	clock_t startTime = clock();
	int arr[] = {1,2,3,4,5,6,7,8,9};
	cout << solve(arr, 0, 8, 10) << "\n";
	cout << "Time taken: " << (double)(clock()-startTime)/CLOCKS_PER_SEC << " seconds";
  	return 0;
}