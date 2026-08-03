#include <iostream>
#include <fstream>
using namespace std;
struct Svien
{
    string name;
    int id;
    char DoB = {11}, countrySide = {100};
};
struct Node
{
    Node *next;
    int inf;
};
struct List
{
    Node *head;
};
void init(List l)
{
    l.head = nullptr;
}
bool isEmpty(List &l)
{
    return l.head == nullptr;
}
Node *createNode(int x)
{
    Node *p = new Node();
    p->inf = x;
    p->next = nullptr;
    return p;
};
// con trỏ p bằng đầu danh sách, nếu p k rỗng thì nếu
Node *search(List l, int value)
{
    Node *p = l.head;
    while (p != nullptr)
    {
        if (p->inf == value)

            return p;
        p = p->next;
    }
    return p;
};
void input1sv(Svien sv)
{
    cout << "Nhap ten: ";
    cin >> sv.name;
    cout << "\nNhap MSSV: ";
    cin >> sv.id;
    cout << "\nQue quan: ";
    cout << "\nNgay sinh: ";
    cin >> sv.DoB;
    cin >> sv.countrySide;
}
void output1sv(Svien sv)
{
    cout << "Ho ten: " << sv.name;
    cout << "\nMa so: " << sv.id;
    cout << "\nNgay sinh: " << sv.DoB;
    cout << "\nQue quan: " << sv.countrySide;
}
void printList(List l, Svien x)
{
    if (isEmpty(l))
    {
        cout << "Danh sach rong";
        return;
        Node *p = l.head;
        while (p != nullptr)
        {
            output1sv(x);
        }
    }
};
void clear(List &l)
{
    Node *p = l.head;
    while (p != nullptr)
    {
    }
}

void addHead(List &l, int x)
{
    Node *p = createNode(x);
    while (p != nullptr)
    {
        p->next = l.head;
        l.head = p;
    }
}
void addTail(List &l, int x)
{
    Node *p = createNode(x);
    if (isEmpty(l))
    {
        l.head = p;
    }
    Node *q = l.head;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    q->next = p;
}
void delHead(List &l)
{
    Node *q = l.head;
    Node *prev = nullptr;
    while (q->next != nullptr)
    {
        prev = q;
        q = q->next;
    }
    if (prev != nullptr)
    {
        prev->next = nullptr;
    }
}
//
void delTail(List &l)
{

    if (isEmpty(l))
    {
        return;
    }
    Node *q = l.head;
    Node *prev = nullptr;
    while (q->next != nullptr)
    {
        prev = q;
        q = q->next;
    }
    if (prev != nullptr)
    {
        prev->next = nullptr;
    }
    else
    {
        l.head = nullptr;
        delete q;
    }
}
void insertOrdered(List &l, int x)
{

    if (isEmpty(l) || x < l.head->inf)
    {
        addHead(l, x);
        return;
    }
    Node *q = l.head;
    while (q->next != nullptr && x > q->next->inf)
    {
        q = q->next;
    }
}
// them vao sau phan tu gia tri
void insertAfter(List &l, int x)
{

    if (isEmpty(l) || x < l.head->inf)
    {
        addHead(l, x);
    }
    Node *q = search(l, x);
    Node *p = l.head;
    while (p->next != nullptr && x > p->next->inf)
    {
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
}
void countElement(List l)
{
    if (isEmpty(l))
    {
        cout << "So sinh vien trong danh sach: rong!";
        return;
    }
    Node *p = l.head;
    int i = 0;
    while (p != nullptr)
    {
        i++;
        p = p->next;
    }
    cout << "So sinh vien trong danh sach: " << i << endl;
}
int cmpAsc(Node *a, Node *b)
{
    return a->inf - b->inf;
}

void sortList(List l,int func(Node*,Node*))
{
    for(Node*i=l.head;i->next!=nullptr;i++){
        for(Node*j=i->next;j=nullptr;j++){
            if(func(j,i)>0){
                swap(i->inf,j->inf);
            }
        }
    }
}
void nhapdsTuFile() {}
int main()
{

    return 0;
}
