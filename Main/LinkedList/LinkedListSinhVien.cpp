// SinhVien, MonHoc, Khoa
// Tìm kiếm SinhVien theo mã sinh viên
// Tìm kiếm MonHoc theo mã môn học
// Tìm kiếm Khoa theo mã khoa
// in danh sách SinhVien theo Khoa
// in danh sách MonHoc theo Khoa

// sort danh sách SinhVien theo mssv
#include <iostream>

using namespace std;

struct SinhVien
{
    int maSV;
    string tenSV;
    // string queQuan;
    // string ngaySinh;

    void input()
    {
        cout << "Nhap ma so sinh vien: ";
        cin >> maSV;
        cin.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(cin, tenSV);
        // cout << "Nhap que quan: ";
        // getline(cin, queQuan);
        // cout << "Nhap ngay sinh: ";
        // cin >> ngaySinh;
    }

    void output()
    {
        cout << "Ma so sinh vien: " << maSV << endl;
        cout << "Ma so ten sinh vien: " << tenSV << endl;
        // cout << "Ma so que quan: " << queQuan << endl;
        // cout << "Ma so ngay sinh: " << ngaySinh << endl;
    }
};

struct Node
{
    SinhVien data;
    Node *next;
    Node *prev;
};

// khởi tạo
void init(Node *&head)
{
    head = nullptr;
}
// Tạo node
Node *createNode(SinhVien data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

// thêm đầu
void addHead(Node *&head, SinhVien data)
{
    Node *p = createNode(data);
    p->next = head;
    head->prev = p;
    head = p;
}

// tính đóng gói, trừu tượng, kếthừa, đa hình

void output(string tensv, int masv)
{
    cout << "Ma so sinh vien: " << masv << endl;
    cout << "Ten sinh vien: " << tensv << endl;
}

void output(SinhVien sv)
{
    cout << "Ma so sinh vien: " << sv.maSV << endl;
    cout << "Ten sinh vien: " << sv.tenSV << endl;
}

void output(string tensv, int masv, string quequan, string ngaysinh)
{
    cout << "Ma so sinh vien: " << masv << endl;
    cout << "Ten sinh vien: " << tensv << endl
         << "Que quan: " << quequan << endl
         << "Ngay sinh: " << ngaysinh << endl;
}

// thêm cuối
void addTail(Node *&head, SinhVien data)
{
    Node *p = createNode(data);
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
// đếm số lượng phần tử
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

// thêm sau giá trị x
// void addAfter(Node *&head, int x, int data)
// {
//     Node *q = head;
//     // Tìm giá trị
//     while (q->next != nullptr && q->data != x)
//         q = q->next;

//     if (q != nullptr)
//     {
//         Node *p = createNode(data);
//         p->next = q->next;
//         q->next = p;
//     }
// }

// thêm vào vị trí x
void addIdx(Node *&head, int x, SinhVien data)
{
    Node *q = head;
    int idx = 0;
    // Tìm vị trí
    while (q->next != nullptr && idx != x)
    {
        idx++;
        q = q->next;
    }

    if (q != nullptr)
    {
        Node *p = createNode(data);
        p->next = q->next;
        q->next = p;
    }
}

// xóa đầu
void delHead(Node *&head)
{
    if (head->next == nullptr)
    {
        delete head;
    }

    Node *p = head;
    head = head->next;
    p->next = nullptr;
    delete p;
}

// xóa cuối
void delTail(Node *&head)
{
    if (head->next == nullptr)
        delete head;
    Node *p = head;
    Node *q = nullptr;

    while (p->next != nullptr)
    {
        q = p;
        p = p->next;
    }

    q->next = nullptr;
    p->next = nullptr;
    delete p;
}

// xóa tại vị trí idx
void delX(Node *&head, int idx)
{
    int length = lenghtList(head);
    if (idx > length)
        cout << "Vi Tri Khong Hop Le";
    else
    {
        Node *p = head;
        Node *q = nullptr;
        int index = 0;

        while (p->next != nullptr && index != idx)
        {
            q = p;
            index++;
            p = p->next;
        }

        q->next = p->next;
        p->next = nullptr;
        delete p;
    }
}

// xóa List
void clear(Node *&head)
{
    while (head != nullptr)
        head = head->next;
    delete head;
}

// in danh sách liên kết
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << endl;
        head->data.output();
        head = head->next;
    }

    cout << endl;
}

// Sinh Vien

Node *timKiemSV(Node *head, int maSV)
{
    if (head == nullptr)
        return nullptr;
    while (head->next != nullptr && head->data.maSV != maSV)
    {
        head = head->next;
    }

    if (head == nullptr)
        return nullptr;

    head->next = nullptr;
    return head;
}

void swap(SinhVien &sva, SinhVien &svb)
{
    SinhVien svc = sva;
    sva = svb;
    svb = svc;
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
                cout << "hello";
        }
    }
}

void sortList(Node *&head)
{
    for (Node *p = head; p != nullptr; p = p->next)
    {
        for (Node *q = p->next; q != nullptr; q = q->next)
        {
            if (p->data.maSV <= q->data.maSV)
            {
                swap(p->data, q->data);
            }
        }
    }
}


// int cmpAsc(Node* a, Node* b) {
// 	return a->info.mssv - b->info.mssv;
// }



// void sortList(LinkedList l, int func(Node*, Node*)) {
// 	if (!isEmpty(l)) {
// 		for (Node* i = l.head; i->next != nullptr; i = i->next) {
// 			for (Node* j = i->next; j != nullptr; j = j->next) {
// 				if (func(node1, node3) < 0)
// 					swap(i->info, j->info);
// 			}
// 		}
// 	}
// }



int main()
{
    Node *head;
    init(head);

    SinhVien sv1;
    sv1.input();
    SinhVien sv2;
    sv2.input();
    SinhVien sv3;
    sv3.input();
    SinhVien sv4;
    sv4.input();

    head = createNode(sv1);
    addTail(head, sv2);
    addTail(head, sv3);
    addTail(head, sv4);

    printList(head);

    cout << "Tim Kiem : " << endl;

    printList(timKiemSV(head, 2));

    sortList(head);

    printList(head);


    // sortList(head, cmpAsc);


    return 0;
}

// khác biệt của danh sách liên kết đơn với danh sách liên kết đôi