#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int size) {
  for (int j=1; j<size; j++) {
    int key = arr[j];
    int i = j-1;
    while (i > -1 && arr[i] > key) {
      arr[i+1] = arr[i];
      i = i-1;
    }
    arr[i+1] = key;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i=0; i<n; i++) {
    cin >> arr[i];  
  }
  sort(arr, n);

  int ans = 0;
  int sum = 0;
  for(int i : arr) {
    sum += i;
    if(sum > k) break;
    ans++;
  }
  cout << ans << endl;
  
  return 0;
}