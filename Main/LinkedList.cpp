

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next = nullptr;
};

// khởi tạo
void init(Node *&head)
{
    head = nullptr;
}
// Tạo node
Node *createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

// thêm đầu
void addHead(Node *&head, int data)
{
    Node *p = createNode(data);
    p->next = head;
    head = p;
}
// thêm cuối
void addTail(Node *&head, int data)
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
void addAfter(Node *&head, int x, int data)
{
    Node *q = head;
    // Tìm giá trị
    while (q->next != nullptr && q->data != x)
        q = q->next;

    if (q != nullptr)
    {
        Node *p = createNode(data);
        p->next = q->next;
        q->next = p;
    }
}

// thêm vào vị trí x
void addIdx(Node *&head, int x, int data)
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
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    cout << "Danh sach lien ket: ";
    Node *head = new Node();
    init(head);

    // addHead(head, 1);
    // addHead(head, 2);
    // addHead(head, 3);

    addTail(head, 1);
    addTail(head, 2);
    addTail(head, 3);
    addTail(head, 4);
    addTail(head, 5);
    // addAfter(head, 2, 4);
    // addAfter(head, 3, 5);
    // printList(head);

    cout << "So Luong Phan Tu: " << lenghtList(head) << endl;

    // // addIdx(head, 3, 10);
    // cout << "Danh sach lien ket: ";
    // printList(head);

    // cout << "Xoa dau: " << endl;
    // delHead(head);
    // printList(head);

    // delTail(head);
    // printList(head);

    delX(head, 2);
    printList(head);

    return 0;
}