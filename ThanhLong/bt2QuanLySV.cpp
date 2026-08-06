#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct SinhVien {
	int mssv;
	string name;
	double GPA;
};

struct Node {
	SinhVien data;
	Node *next = nullptr;
};

double lamTronGPA(double gpa) {
	return round(gpa * 100.0) / 100.0;
}

SinhVien taoSinhVien(int mssv, string name, double gpa) {
	SinhVien sv;
	sv.mssv = mssv;
	sv.name = name;
	sv.GPA = lamTronGPA(gpa);
	return sv;
}

Node* createNode(const SinhVien &sv) {
	Node *p = new Node();
	p->data = sv;
	p->next = nullptr;
	return p;
}

void xuatSV(const SinhVien &sv) {
	cout << "MSSV: " << sv.mssv
		<< " | Ho ten: " << left << setw(20) << sv.name
		<< " | GPA: " << fixed << setprecision(2) << sv.GPA << endl;
}


void addHead(Node* &head, const SinhVien &sv) {
	Node *p = createNode(sv);
	p->next = head;
	head = p;
}

void addTail(Node* &head, const SinhVien &sv) {
	Node *p = createNode(sv);
	if (head == nullptr) {
		head = p;
		return;
	}
	Node *temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = p;
}

void insertAt(Node* &head, const SinhVien &sv, int pos) {
	if (pos <= 0 || head == nullptr) {
		addHead(head, sv);
		return;
	}
	Node *temp = head;
	for (int i = 0; temp->next != nullptr && i < pos - 1; i++) {
		temp = temp->next;
	}
	Node *p = createNode(sv);
	p->next = temp->next;
	temp->next = p;
}

void insertAfterMSSV(Node *head, const SinhVien &sv, int afterMSSV) {
	Node *temp = head;
	while (temp != nullptr && temp->data.mssv != afterMSSV) {
		temp = temp->next;
	}
	if (temp != nullptr) {
		Node *p = createNode(sv);
		p->next = temp->next;
		temp->next = p;
	}
	else {
		cout << "Khong tim thay MSSV " << afterMSSV << " de chen them!\n";
	}
}

void deleteHead(Node* &head) {
	if (head == nullptr) return;
	Node *p = head;
	head = head->next;
	delete p;
}

void deleteTail(Node* &head) {
	if (head == nullptr) return;
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	Node *temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
}

void deleteByMaSV(Node* &head, int maSV) {
	if (head == nullptr) {
		cout << "Danh sach rong!\n";
		return;
	}

	if (head->data.mssv == maSV) {
		deleteHead(head);
		return;
	}

	Node *p = head;
	Node *prev = nullptr;

	while (p != nullptr && p->data.mssv != maSV) {
		prev = p;
		p = p->next;
	}

	if (p == nullptr) {
		cout << "Khong tim thay sinh vien co MSSV: " << maSV << endl;
		return;
	}

	prev->next = p->next;
	delete p;
	cout << "Da xoa sinh vien co MSSV: " << maSV << endl;
}

Node* findByMSSV(Node *head, int mssv) {
	Node *p = head;
	while (p != nullptr) {
		if (p->data.mssv == mssv) return p;
		p = p->next;
	}
	return nullptr;
}

void findByName(Node *head, string name) {
	cout << "--- KET QUA TIM KIEM THEO TEN: " << name << " ---\n";
	Node *p = head;
	bool found = false;
	while (p != nullptr) {
		if (p->data.name.find(name) != string::npos) {
			xuatSV(p->data);
			found = true;
		}
		p = p->next;
	}
	if (!found) cout << "Khong tim thay sinh vien phu hop.\n";
}

double getMaxGPA(Node *head) {
	if (head == nullptr) return -1;
	double maxGPA = head->data.GPA;
	Node *p = head->next;
	while (p != nullptr) {
		if (p->data.GPA > maxGPA) maxGPA = p->data.GPA;
		p = p->next;
	}
	return maxGPA;
}

double getMinGPA(Node *head) {
	if (head == nullptr) return -1;
	double minGPA = head->data.GPA;
	Node *p = head->next;
	while (p != nullptr) {
		if (p->data.GPA < minGPA) minGPA = p->data.GPA;
		p = p->next;
	}
	return minGPA;
}

void printList(Node *head) {
	if (head == nullptr) {
		cout << "Danh sach rong.\n";
		return;
	}
	cout << "--- DANH SACH SINH VIEN ---\n";
	Node *p = head;
	while (p != nullptr) {
		xuatSV(p->data);
		p = p->next;
	}
	cout << "---------------------------\n";
}

void printListGPA3(Node *head) {
	cout << "--- DANH SACH SINH VIEN GPA >= 3.0 ---\n";
	Node *p = head;
	while (p != nullptr) {
		if (p->data.GPA >= 3.0) xuatSV(p->data);
		p = p->next;
	}
	cout << "--------------------------------------\n";
}

int countGPA3(Node *head) {
	int count = 0;
	Node *p = head;
	while (p != nullptr) {
		if (p->data.GPA >= 3.0) count++;
		p = p->next;
	}
	return count;
}

void printMaxGPASudents(Node *head) {
	double maxGPA = getMaxGPA(head);
	if (maxGPA == -1) return;
	cout << "--- SINH VIEN CO GPA CAO NHAT (" << maxGPA << ") ---\n";
	Node *p = head;
	while (p != nullptr) {
		if (p->data.GPA == maxGPA) xuatSV(p->data);
		p = p->next;
	}
	cout << "---------------------------------------------\n";
}

void updateNameByMSSV(Node *head, int mssv, string newName) {
	Node *p = findByMSSV(head, mssv);
	if (p != nullptr) {
		p->data.name = newName;
		cout << "Da cap nhat ten cho MSSV " << mssv << endl;
	}
	else {
		cout << "Khong tim thay MSSV " << mssv << endl;
	}
}

void updateGPAByMSSV(Node *head, int mssv, double newGPA) {
	Node *p = findByMSSV(head, mssv);
	if (p != nullptr) {
		p->data.GPA = lamTronGPA(newGPA);
		cout << "Da cap nhat GPA cho MSSV " << mssv << endl;
	}
	else {
		cout << "Khong tim thay MSSV " << mssv << endl;
	}
}

void bonusGPAAll(Node *head) {
	Node *p = head;
	while (p != nullptr) {
		p->data.GPA = lamTronGPA(p->data.GPA + 0.1);
		if (p->data.GPA > 4.0) p->data.GPA = 4.0;
		p = p->next;
	}
	cout << "Da cong 0.1 GPA cho tat ca sinh vien.\n";
}

int main() {
	Node *l = nullptr;

	addHead(l, taoSinhVien(101, "Nguyen Van A", 3.2));
	addTail(l, taoSinhVien(102, "Tran Thi B", 2.8));
	addTail(l, taoSinhVien(103, "Le Van C", 3.9));
	insertAt(l, taoSinhVien(104, "Pham Van D", 3.9), 2);
	insertAfterMSSV(l, taoSinhVien(105, "Hoang Van E", 2.5), 102);

	printList(l);

	// 2. Test Delete
	deleteByMaSV(l, 104);
	printList(l);

	// 3. Test Search
	findByName(l, "Van");
	printListGPA3(l);

	// 4. Test Thong ke
	cout << "So sinh vien GPA >= 3.0: " << countGPA3(l) << endl;
	printMaxGPASudents(l);

	// 5. Test Update
	updateNameByMSSV(l, 102, "Tran Thi B (Da Doi)");
	updateGPAByMSSV(l, 102, 3.15);
	bonusGPAAll(l);

	cout << "\nDanh sach sau khi cap nhat:\n";
	printList(l);

	return 0;
}