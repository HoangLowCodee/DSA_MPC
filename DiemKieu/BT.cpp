#include <iostream>

using namespace std;

struct Node {
	int info;
	Node* next;
};


struct LinkedList {
	Node* head = nullptr;
};

Node* createNode(int val) {
	Node* p = new Node();
	p->info = val;
	p->next = nullptr;
	return p;
}

void addHead(LinkedList& L, const int x) {
	Node* p = createNode(x);
	p->next = L.head;
	L.head = p;
}

void addTail(LinkedList& L, const int x) {
	Node* p = createNode(x);
	if (L.head == nullptr)
		L.head = p;
	else {
		Node* tail = L.head;
		while (tail->next != nullptr)
			tail = tail->next;
		tail->next = p;
	}
}
//Theo giá trị
void addFirst(LinkedList& L, const int x, const int y) {
	Node* q = L.head;
	while (q->next != nullptr && q->next->info != y)
		q = q->next;
	if (q != nullptr) {
		Node* p = createNode(x);
		p->next = q->next;
		q->next = p;
	}
}

void addAfter(LinkedList& L, const int x, const int y) {
	Node* q = L.head;
	while (q != nullptr && q->info != y)
		q = q->next;
	if (q != nullptr) {
		Node* p = createNode(x);
		p->next = q->next;
		q->next = p;
	}
}

int main() {
	return 0;
}