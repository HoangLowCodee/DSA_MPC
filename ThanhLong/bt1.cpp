#include <iostream>
#include <string>

using namespace std;

struct SinhVien {
	string name;
	int age;
	int maSV;
	string queQuan;
};

struct Node {
	SinhVien data;
	Node *next = nullptr;
};

SinhVien taoSinhVien(int maSV, string name, int age, string queQuan) {
	SinhVien sv;
	sv.maSV = maSV;
	sv.name = name;
	sv.age = age;
	sv.queQuan = queQuan;
	return sv;
}

void xuatSinhVien(const SinhVien &sv) {
	cout << "MSV: " << sv.maSV
		<< " | Ho ten: " << sv.name
		<< " | Tuoi: " << sv.age
		<< " | Que quan: " << sv.queQuan << endl;
}

Node* createNode(const SinhVien &sv) {
	Node *newNode = new Node();
	newNode->data = sv;
	newNode->next = nullptr;
	return newNode;
}

void addHead(Node* &head, const SinhVien &sv) {
	Node *newNode = createNode(sv);
	newNode->next = head;
	head = newNode;
}

void addTail(Node* &head, const SinhVien &sv) {
	Node *newNode = createNode(sv);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node *temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void deleteHead(Node* &head) {
	if (head == nullptr) {
		cout << "Danh sach rong, khong the xoa!\n";
		return;
	}
	Node *temp = head;
	head = head->next;
	delete temp;
	cout << "Da xoa sinh vien dau danh sach.\n";
}

void deleteTail(Node* &head) {
	if (head == nullptr) {
		cout << "Danh sach rong, khong the xoa!\n";
		return;
	}
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		cout << "Da xoa sinh vien cuoi danh sach.\n";
		return;
	}
	Node *temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
	cout << "Da xoa sinh vien cuoi danh sach.\n";
}

void deleteByMaSV(Node* &head, int maSV) {
	if (head == nullptr) {
		cout << "Danh sach rong!\n";
		return;
	}

	if (head->data.maSV == maSV) {
		deleteHead(head);
		return;
	}

	Node *p = head;
	Node *prev = nullptr;

	while (p != nullptr && p->data.maSV != maSV) {
		prev = p;
		p = p->next;
	}

	if (p == nullptr) {
		cout << "Khong tim thay sinh vien co MSV: " << maSV << endl;
		return;
	}

	prev->next = p->next;
	delete p;
	cout << "Da xoa sinh vien co MSV: " << maSV << endl;
}

void printList(Node *head) {
	if (head == nullptr) {
		cout << "Danh sach dang rong.\n";
		return;
	}
	cout << "\n=== DANH SACH SINH VIEN ===\n";
	Node *temp = head;
	int stt = 1;
	while (temp != nullptr) {
		cout << stt++ << ". ";
		xuatSinhVien(temp->data);
		temp = temp->next;
	}
	cout << "===========================\n";
}

void freeList(Node* &head) {
	while (head != nullptr) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {
	Node *l = nullptr;
	addHead(l, taoSinhVien(101, "Nguyen Van A", 20, "TP.HCM"));
	addHead(l, taoSinhVien(102, "Tran Thi B", 21, "Ha Noi"));
	addHead(l, taoSinhVien(103, "Le Van C", 19, "Da Nang"));

	cout << "Sau khi addHead 3 sinh vien:\n";
	printList(l);

	addTail(l, taoSinhVien(104, "Pham Van D", 22, "Can Tho"));
	cout << "Sau khi addTail sinh vien 104:\n";
	printList(l);

	deleteHead(l);
	cout << "Sau khi deleteHead:\n";
	printList(l);

	deleteTail(l);
	cout << "Sau khi deleteTail:\n";
	printList(l);

	return 0;
}