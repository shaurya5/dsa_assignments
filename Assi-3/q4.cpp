#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_map<string, vector<pair<int,int>>> m; // name: [{index, value}]

  // creating an unordered map with name, {index, value}
	for(int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		m[s].push_back({i,x});
	}

    // finding max score
	int maxScore = -1;
	for(auto it : m) { 
		int sum = 0;
		for(auto p : it.second) {
			sum += p.second;
    }
    m[it.first].push_back({-1, sum});
		maxScore = max(sum, maxScore);
	}

	// cout << "Max Score: " << maxScore << endl;

	// for(auto i : m) {
	// 	cout << i.first << " ";
	// 	for(auto g : i.second) {
	// 		cout << g.first << "," << g.second << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<pair<int,string>> v;
	int minIndex = INT_MAX;

    // finding mini index of max score
	for(auto it : m) {
		int sum = 0;
		for(auto p : it.second) {
			sum += p.second;
			int vSize = it.second.size();
			int lastValue = it.second[vSize - 1].second;
			if(sum >= maxScore && lastValue >= maxScore) {
				minIndex = min(minIndex, p.first);
				v.push_back({p.first, it.first});  // p.first -> index , it.first -> name
				break;
			}
		}
	}

    // printing name with max score and least index
	for(auto i : v) {
		if(i.first == minIndex) {
			cout << i.second << endl;
			break;
		}
	}
	// pair<int, string> minPair;
	// int minIndex = INT_MAX;
	// for(auto i : v) {
	// 	if(i.first < minIndex) {
	// 		minIndex = i.first;
	// 		minPair = {minIndex, i.second};
	// 	}
	// }

	// cout << minPair.second << endl;

	return 0;
}