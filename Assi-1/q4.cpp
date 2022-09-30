#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;

	Node(int val) {
		next = NULL;
		data = val;
	}
};

Node* createLL() {
	Node *head = new Node(0);
	Node *first = new Node(1);
	Node *second = new Node(2);
	Node *third = new Node(3);
	Node *fourth = new Node(4);
	Node *fifth = new Node(5);
	Node *sixth = new Node(6);
	head->next = first;
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = sixth;
	sixth->next = second;
	
	return head;
}

int main() {
	Node *head = createLL();
	Node *fast = head;
	Node *slow = head;

	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast) {
			while(slow != head) {
				slow = slow->next;
				head = head->next;
			}
			cout << slow->data << endl;
			break;
		}
	}
	return 0;
}