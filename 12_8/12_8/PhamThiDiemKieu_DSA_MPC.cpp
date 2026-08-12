#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct Khoa {
	int maK = 0;
	string tenK = "";
};

struct SinhVien {
	int mssv;
	string name;
	double GPA;
	Khoa maKhoa;
};

struct Node {
	SinhVien data;
	Node* next;
};

struct LinkedList {
	Node* head = nullptr;
	Node* tail = nullptr;
};

struct NodeKhoa {
	Khoa data;
	NodeKhoa* next;
};

struct ListKhoa {
	NodeKhoa* head = nullptr;
};

void lamTronGPA(double& gpa) {
	gpa = round(gpa * 100.0) / 100.0;
}

Node* createNode(SinhVien sv) {
	lamTronGPA(sv.GPA);
	Node* newNode = new Node();
	newNode->data = sv;
	newNode->next = nullptr;
	return newNode;
}

void inThongTinSV(SinhVien sv) {
	cout << left << setw(10) << sv.mssv
		<< setw(25) << sv.name
		<< setw(8) << fixed << setprecision(2) << sv.GPA;
	if (sv.maKhoa.maK != 0) {
		cout << setw(10) << sv.maKhoa.maK << setw(20) << sv.maKhoa.tenK;
	} cout << endl;
}

void inTieuDe() {
	cout << left << setw(10) << "MSSV"
		<< setw(25) << "Ho Va Ten"
		<< setw(8) << "GPA"
		<< setw(10) << "Ma Khoa"
		<< setw(20) << "Ten Khoa" << endl;
	cout << string(73, '-') << endl;
}

string extractToken(string& str, char delim) {
	size_t pos = str.find(delim);
	string token;
	if (pos != string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + 1); // Xóa bớt
	}
	else {
		token = str;
		str = "";
	}
	return token;
}

void addFirst(LinkedList& list, SinhVien sv) {
	Node* newNode = createNode(sv);
	if (!list.head) list.head = list.tail = newNode;
	else { newNode->next = list.head; list.head = newNode; }
}

void addLast(LinkedList& list, SinhVien sv) {
	Node* newNode = createNode(sv);
	if (!list.head) list.head = list.tail = newNode;
	else { list.tail->next = newNode; list.tail = newNode; }
}

void addAtPosition(LinkedList& list, SinhVien sv, int pos) {
	if (pos <= 0) { addFirst(list, sv); return; }
	Node* temp = list.head;
	for (int i = 0; temp && i < pos - 1; i++) temp = temp->next;
	if (!temp || temp == list.tail) addLast(list, sv);
	else {
		Node* newNode = createNode(sv);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void addAfterMSSV(LinkedList& list, SinhVien sv, int targetMSSV) {
	Node* temp = list.head;
	while (temp && temp->data.mssv != targetMSSV) temp = temp->next;
	if (temp) {
		Node* newNode = createNode(sv);
		newNode->next = temp->next;
		temp->next = newNode;
		if (temp == list.tail) list.tail = newNode;
	}
	else cout << "Khong tim thay MSSV: " << targetMSSV << endl;
}

SinhVien nhapSinhVien() {
	SinhVien sv;
	cout << "Nhap MSSV: "; cin >> sv.mssv;
	cin.ignore();
	cout << "Nhap Ho va Ten: "; getline(cin, sv.name);
	cout << "Nhap GPA: "; cin >> sv.GPA;
	cout << "Nhap Ma Khoa (0 neu chua co): "; cin >> sv.maKhoa.maK;
	cin.ignore();
	if (sv.maKhoa.maK != 0) {
		cout << "Nhap Ten Khoa: "; getline(cin, sv.maKhoa.tenK);
	}
	return sv;
}

void deleteFirst(LinkedList& list) {
	if (!list.head) return;
	Node* temp = list.head;
	list.head = list.head->next;
	if (!list.head) list.tail = nullptr;
	delete temp;
}


int main() {

	return 0;
}