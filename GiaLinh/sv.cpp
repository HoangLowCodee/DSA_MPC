#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
    string name;
    int age;
    string maSV;
    string queQuan;
};

struct Node
{
    SinhVien data;
    Node *next = nullptr;
};

void nhapdulieu(SinhVien &sv)
{
    cout << "Nhap ten: ";
    getline(cin, sv.name);
    cout << "Nhap tuoi: ";
    cin >> sv.age;
    cin.ignore();
    cout << "Nhap ma sinh vien: ";
    getline(cin, sv.maSV);
    cout << "Nhap que quan: ";
    getline(cin, sv.queQuan);
    cout << endl;
}

void init(Node *&head)
{
    head = nullptr;
}

Node *createNode(SinhVien sv)
{
    Node *p = new Node();
    p->data = sv;
    p->next = nullptr;
    return p;
}

void addHead(Node *&head, SinhVien sv)
{
    Node *p = createNode(sv);
    p->next = head;
    head = p;
}

void addTail(Node *&head, SinhVien sv)
{
    Node *p = createNode(sv);
    if (head == nullptr)
    {
        head = p;
        return;
    }
    else
    {
        Node *q = head;
        while (q->next != nullptr)

        {
            q = q->next;
        }
        q->next = p;
    }
}

int lenghtList(Node *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}

void addAfter(Node *&head, int x, SinhVien sv)
{
    Node *q = head;
    while (q != nullptr && q->data.age != x)
        q = q->next;
    if (q != nullptr)
    {
        Node *p = createNode(sv);
        p->next = q->next;
        q->next = p;
    }
}

void addIdx(Node *&head, int x, SinhVien sv)
{
    Node *q = head;
    int idx = 0;
    while (q != nullptr && idx != x)
    {
        idx++; //
        q = q->next;
    }
    if (q != nullptr)
    {
        Node *p = createNode(sv);
        p->next = q->next;
        q->next = p;
    }
}

void delHead(Node *&head)
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
    Node *p = head;
    head = head->next;
    p->next = nullptr;
    delete p;
}

void delTail(Node *&head)
{
    if (head == nullptr)
    { // danh sach rong
        return;
    }
    if (head->next == nullptr)
    { // danh sach chi co 1 phan tu
        delete head;
        head = nullptr;
        return;
    }
    Node *p = head;
    Node *q = nullptr;
    while (p->next != nullptr)
    {
        q = p; // q tro den nut truoc p
        p = p->next;
    }
    q->next = nullptr; // q cat bo lien ket voi p, q tro thanh tail moi -> nullptr
    p->next = nullptr; // p cat bo lien ket voi danh sach
    delete p;
}

// xóa tại vị trí idx
void delIdx(Node *&head, int idx)
{
    if (idx < 0)
        return;
    if (idx == 0)
    {
        delHead(head);
        return;
    }
    Node *p = head;
    Node *q = nullptr;
    int index = 0;
    while (p != nullptr && index != idx)
    {
        q = p;       // q tro den nut truoc p
        p = p->next; // p tro den nut tiep theo
        index++;
    }
    q->next = p->next; // q cat bo lien ket voi p, q tro den nut tiep theo cua p
    p->next = nullptr; // p cat bo lien ket voi danh sach
    delete p;
}

void clear(Node *&head)
{
    while (head != nullptr)
    {
        head = head->next;
        delete head;
    }
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << "Ten: " << head->data.name << " - Tuoi: " << head->data.age << " - Ma SV: " << head->data.maSV << " - Que Quan: " << head->data.queQuan << endl;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    init(head);

    SinhVien sv1, sv2, sv3;
    nhapdulieu(sv1);
    nhapdulieu(sv2);
    nhapdulieu(sv3);

    addHead(head, sv3);
    addTail(head, sv1);
    addAfter(head, sv1.age, sv3);
    printList(head);

    // delHead(head);
    // delTail(head);
    // delIdx(head, 0);
    // printList(head);

    // clear(head);

    return 0;
}