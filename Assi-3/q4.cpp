#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<string,int> m;
	while(n--) {
		string name;
		int score;
		cin >> name >> score;
		m[name] += score;
	} 

	for(auto i : m) {
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}