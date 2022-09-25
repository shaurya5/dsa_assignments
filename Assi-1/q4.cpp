#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;

	Node(int val) {
		next = NULL;
		data = val;
	}
};

Node* createLL(int size) {
	vector<int> nos;
	while(size--) {
		cout << "Enter an integer: ";
		int inp;
		cin >> inp;
		nos.push_back(inp);
	}

	
}

int main() {
	cout << "Enter size: ";
	int size;
	cin >> size;

	Node *head = createLL(size);
	Node *fast = head;
	Node *slow = head;

	while(fast != slow) {
		fast = fast->next->next;
		slow = slow->next;
	}

	cout << fast->data;

	return 0;
}