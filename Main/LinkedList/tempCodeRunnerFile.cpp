#include <iostream>

using namespace std;

// danh sách liên kết đôi
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

// void init(Node *&head, Node *&tail)
// {
//     head = nullptr;
//     tail = nullptr;
// }

Node *createNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

void addTail(List &list, int data)
{
    Node *p = createNode(data);
    p->prev = list.tail;
    if (list.tail != nullptr)
        list.tail->next = p;
    else
        list.head = p;
    list.tail = p;
}

void addHead(List &list, int data)
{
    Node *p = createNode(data);
    p->next = list.head;
    if (list.head != nullptr)
        list.head->prev = p;
    else
        list.tail = p;
    list.head = p;
}

void outputHead(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// mergeList
// nhiều hơn 1 list
// tìm node cuối của list bất kỳ
// lấy node cuối trỏ đến đầu của list thứ 2
// .. tiếp tục với các list khác
//...
// null
bool mergeList(Node *list1, Node *list2, Node *&merge)
{

    if (list1 == nullptr || list2 == nullptr)
        return false;

    while (list1->next != nullptr)
    {
        list1 = list1->next;
    }
    merge = list1;
    list1->next = list2;
    list2->prev = list1;

    return true;
}

int main()
{
    List list;

    addTail(list, 1);
    addTail(list, 2);
    addHead(list, 3);
    addHead(list, 4);

    cout << "list 1: ";

    outputHead(list.head);

    cout << endl;

    // List list2;

    // addTail(list2, 1);
    // addTail(list2, 2);
    // addHead(list2, 3);
    // addHead(list2, 4);

    // Node *merge = nullptr;

    // if (mergeList(list.head, list2.head, merge))
    // {
    //     outputHead(merge);
    // }
    // else
    // {
    //     cout << "Muốn merge thì 2 list phải có giá trị thằng gà ahihi :>>";
    // }

    return 0;
}