#include <iostream>
#include <string>
using namespace std;
struct SinhVien
{
	string name;
	int age = 0;
	int mssv = 0;
	string queQuan;
	void nhapthongtin()
	{
		cout << "Nhap ten sinh vien: ";
		getline(cin, name);
		cout << "Nhap tuoi sinh vien: ";
		cin >> age;
		cout << "Nhap mssv sinh vien: ";
		cin >> mssv;
		cin.ignore();
		cout << "Nhap que quan sinh vien: ";
		getline(cin, queQuan);
	}
	void xuatthongtin()
	{
		cout << "Ten: " << name << endl;
		cout << "Tuoi: " << age << endl;
		cout << "MSSV: " << mssv << endl;
		cout << "Que quan: " << queQuan << endl;
	}
};

struct Node
{
	SinhVien data;
	Node *next = nullptr;
};

void khoitao(Node *&head)
{
	head = nullptr;
}

// newNode
Node *create(SinhVien data)
{
	Node *node = new Node();
	node->data = data;
	node->next = nullptr;
	return node;
}

// addHead
void addH(Node *&head, SinhVien data)
{
	Node *p = create(data);
	p->next = head;
	head = p;
}

// addTail
void addT(Node *&head, SinhVien data)
{
	Node *p = create(data);
	if (head == nullptr)
	{
		head = p;
		return;
	}
	Node *q = head;
	while (q->next != nullptr)
	{
		q = q->next;
	}
	q->next = p;
}

// addAfterValue (theo gia tri)
void addAfterVal(Node *&head, int x, SinhVien data)
{
	Node *q = head;
	while (q != nullptr && q->data.mssv != x)
	{
		q = q->next;
	}
	if (q != nullptr)
	{
		Node *p = create(data);
		p->next = q->next;
		q->next = p;
	}
}

// addPosition (theo vi tri)
void addPos(Node *&head, int x, SinhVien data)
{
	Node *q = head;
	int idx = 0;
	while (q != NULL && idx < x)
	{
		q = q->next;
		idx++;
	}
	if (q == NULL)
	{
		cout << "Khong hop le\n";
		return;
	}
	Node *newNode = create(data);
	newNode->next = q->next;
	q->next = newNode;
}

// deleteHead
void delH(Node *&head)
{
	if (head == nullptr)
	{
		return;
	}
	Node *p = head;
	head = p->next;
	delete p;
}

// deleteTail
void delT(Node *&head)
{
	if (head == nullptr)
	{
		return;
	}
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	Node *prev = nullptr;
	Node *p = head;
	while (p->next != nullptr)
	{
		prev = p;
		p = p->next;
	}
	prev->next = nullptr;
	delete p;
}

// deleteValue (xoa theo gia tri)
void delVal(Node *&head, int x)
{
	Node *p = head;
	Node *prev = nullptr;
	while (p->next != nullptr && p->data.mssv != x)
	{
		prev = p;
		p = p->next;
	}
	if (p != nullptr)
	{
		if (prev == nullptr)
		{
			head = p->next;
		}
		else
		{
			prev->next = p->next;
		}
		delete p;
	}
}

// deletePosition (xoa theo vi tri)
void delPos(Node *&head, int x)
{
	Node *p = head;
	Node *prev = nullptr;
	int pos = 0;
	while (p != nullptr && pos < x)
	{
		prev = p;
		p = p->next;
		pos++;
	}
	if (p != nullptr)
	{
		if (prev == nullptr)
		{
			delete head;
			return;
		}
		else
		{
			prev->next = p->next;
			delete p;
		}
	}
}

// xoatoands
void clean(Node *&head)
{
	while (head != nullptr)
	{
		head = head->next;
	}
	delete head;
}

// printList
void outp(Node *&head)
{
	Node *p = head;
	while (p != nullptr)
	{
		p->data.xuatthongtin();
		cout << endl;
		p = p->next;
	}
}
int main()
{
	Node *head;
	khoitao(head);
	int n, m;
	int mssvTim;
	int mssvXoa;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap sinh vien thu " << i + 1 << ":\n";
		SinhVien sv;
		sv.nhapthongtin();
		addT(head, sv);
	}
	cout << "==============Thong tin sinh vien===================\n";
	outp(head);
	cout << "--- THEM SINH VIEN ---\n";
	cout << "Nhap so luong sinh vien can them: ";
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cout << "\nNhap MSSV can them sau: ";
		cin >> mssvTim;
		cin.ignore();
		SinhVien svMoi1;
		cout << "Nhap thong tin sinh vien moi:\n";
		svMoi1.nhapthongtin();
		addAfterVal(head, mssvTim, svMoi1);
	}
	cout << "\n================ DANH SACH SAU KHI THEM ================\n";
	outp(head);
	cout << "\n--- XOA DAU, XOA CUOI ---\n";
	delH(head);
	delT(head);
	outp(head);
	cout << "\nNhap MSSV cua sinh vien can xoa: ";
	cin >> mssvXoa;
	delVal(head, mssvXoa);
	cout << "\n================ DANH SACH CON LAI ================\n";
	outp(head);
	clean(head);
	return 0;
}

// outp in danh sách còn lại Lỗi
