#include <iostream>
using namespace std;

class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

void print(Node* head) {
	Node* temp = head;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* input() {
	int data;
	cin >> data;
	Node* temp = NULL;
	Node* head = NULL;
	while(data != -1) {
		Node* n = new Node(data);
		if(head == NULL) {
			head = n;
			temp = n;
		}
		else {			
			temp->next = n;
			temp = temp->next;
		}
		cin >> data;
	}
	return head;
}


int main() {
	Node* head = input();
	print(head);	
}
