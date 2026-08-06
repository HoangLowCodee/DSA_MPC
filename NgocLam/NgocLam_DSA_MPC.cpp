#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct SinhVien
{
    int mssv;          
    string name;       
    double GPA;        
};

struct Node
{
    SinhVien data; 
    Node *next = nullptr;
};

void init(Node *&head)
{
    head = nullptr;
}

Node *createNode(SinhVien sv)
{
    Node *node = new Node();
    node->data = sv;
    node->next = nullptr;
    return node;
}
SinhVien nhapSinhVien()
{
    SinhVien sv;
    cout << "  Nhap MSSV: ";
    cin >> sv.mssv;
    cin.ignore(); 
    cout << "  Nhap ho ten: ";
    getline(cin, sv.name);
    cout << "  Nhap GPA: ";
    cin >> sv.GPA;
    sv.GPA = round(sv.GPA * 100) / 100;

    return sv;
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

    Node *q = head;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    q->next = p;
}

void addIdx(Node *&head, int x, SinhVien sv)
{
    if (x <= 0 || head == nullptr)
    {
        addHead(head, sv);
        return;
    }

    Node *q = head;
    int idx = 0;
    while (q->next != nullptr && idx < x - 1)
    {
        idx++;
        q = q->next;
    }

    Node *p = createNode(sv);
    p->next = q->next;
    q->next = p;
}

void addAfter(Node *head, int x, SinhVien sv)
{
    Node *q = head;
    while (q != nullptr && q->data.mssv != x)
    {
        q = q->next;
    }
    if (q != nullptr)
    {
        Node *p = createNode(sv);
        p->next = q->next;
        q->next = p;
    }
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << "MSSV: " << head->data.mssv 
             << "Ten: " << head->data.name 
             << "GPA: " << head->data.GPA << endl;
        head = head->next;
    }
}
//Câu 2
// 1. Xóa phần tử đầu danh sách
void delHead(Node *&head)
{
    if (head == nullptr) 
    return; 
    Node *p = head;
    head = head->next; 
    delete p;          
}

// 2. Xóa phần tử cuối danh sách
void delTail(Node *&head)
{
    if (head == nullptr)
     return; 
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *p = head;
    Node *q = nullptr; 

    while (p->next != nullptr)
    {
        q = p;
        p = p->next;
    }
    q->next = nullptr; 
    delete p;          
}

// 3. Xóa phần tử tại vị trí idx (bắt đầu từ 0)
void delX(Node *&head, int idx)
{
    if (head == nullptr || idx < 0)
    {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    if (idx == 0)
    {
        delHead(head);
        return;
    }

    Node *p = head;
    Node *q = nullptr; 
    int index = 0;

    while (p != nullptr && index < idx)
    {
        q = p;
        p = p->next;
        index++;
    }

    if (p == nullptr)
    {
        cout << "Vi tri khong hop le!\n";
        return;
    }

    q->next = p->next;
    delete p;
}
int main()
    {
    Node *head;
    init(head);
    int luachon;
    do
    {
        cout << "\n================ MENU THUC HANH ================\n";
        cout << "1. Them vao dau (addHead)\n";
        cout << "2. Them vao cuoi (addTail)\n";
        cout << "3. Them vao vi tri bat ky (addIdx)\n";
        cout << "4. Them sau mot MSSV (addAfter)\n";
        cout << "5. Hien thi danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "=================================================\n";
        cout << "Lua chon cua ban: ";
        cin >> luachon;
        switch (luachon)
        {
        case 1:
        {
            cout << "\n THEM VAO DAU DANH SACH \n";
            SinhVien sv = nhapSinhVien();
            addHead(head, sv);
            cout << " Da them thanh cong!\n";
            break;
        }
        case 2:
        {
            cout << "\n THEM VAO CUOI DANH SACH \n";
            SinhVien sv = nhapSinhVien();
            addTail(head, sv);
            cout << " Da them thanh cong!\n";
            break;
        }
        case 3:
        {
            cout << "\n THEM VAO VI TRI INDEX \n";
            int idx;
            cout << "Nhap vi tri index (bat dau tu 0): ";
            cin >> idx;
            SinhVien sv = nhapSinhVien();
            addIdx(head, idx, sv);
            cout << " Da them thanh cong!\n";
            break;
        }
        case 4:
        {
            cout << "\n THEM SAU MOT MSSV \n";
            if (head == nullptr)
            {
                cout << " Danh sach rong, khong the tim MSSV!\n";
                break;
            }
            int MSSV;
            cout << "Nhap MSSV dung truoc: ";
            cin >> MSSV;
            SinhVien sv = nhapSinhVien();
            addAfter(head,MSSV, sv);
            break;
        }
        case 5:
            printList(head);
            break;
        case 0:
            cout << "Da thoat chuong trinh.\n";
            break;
        default:
            cout << " Lua chon khong hop le, vui long chon lai!\n";
        }
    } while (luachon != 0);

    return 0;
}