#include <bits/stdc++.h>
using namespace std;

void recurse(int size, int open, int close, string op, vector<string> &ans) {
  if(op.size() == size * 2) {
    ans.push_back(op);
    return;
  }

  if(open < size)
    recurse(size, open+1, close, op+"(", ans);

  if(close < open)
    recurse(size, open, close+1, op+")", ans);
}

int main() {
  cout << "Enter input size: ";
  int size;
  cin >> size;

  int open = 0, close = 0;
  string s = "";
  vector<string> ans;

  recurse(size, open, close, s, ans);

  for(auto str : ans) {
    cout << str << endl;
  }

  return 0;
}