/*

Bài 3: Có n nguời chơi được đánh số từ 1 đến n ngồi thành vòng tròn và cùng chơi một trò
chơi với quy luật như sau: nếu người thứ nhất đếm 1 thì theo chiều kim đồng hồ những người
tiếp theo sẽ đếm 2, 3,… cho tới khi có người đếm đến số là một số nguyên tố người đó sẽ bị
loại khỏi vòng tròn, người kế tiếp sẽ tiếp tục đếm cho đến khi vòng tròn chỉ còn 1 người
(người chiến thắng).
Hãy chọn cấu trúc dữ liệu phù hợp để quản lý trò chơi trên, và cho biết: - -
Nếu người thứ nhất là người đếm 1 thì người còn lại trong vòng tròn là người thứ mấy?
Nếu người chiến thắng là người thứ k vậy người bắt đầu đếm từ 1 là người thứ mấy?
 -> Mở rộng: giải quyết 2 yêu cầu trên trong trường hợp sau khi một người bị loại khỏi vòng tròn thì
xoay chiều đếm (cùng chiều kim đồng hồ → ngược chiều và ngược lại).
 */

/*
input của trò chơi: 1 dãy số từ 1 tới n
output của trò chơi: chỉ còn 1 người duy nhất

Dang Sách liên kết vòng:
 => input là 1 danh sách liên kết vòng, mỗi node là 1 người chơi và mỗi node mang 1 giá trị là số nguyên từ 1 tới n
 => output là 1 node duy nhất còn lại trong danh sách liên kết vòng => in ra giá trị của node;



 Điều kiện dừng:
   => khi danh sách liên kết vòng chỉ còn 1 node duy nhất
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void init(Node *&head, Node *&tail)
{
    head = nullptr;
    tail = nullptr;
}

void addNode(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void deleteNode(Node *&head, Node *&tail, Node *&current)
{
    if (head == nullptr)
        return;

    // chỉ còn 1 node
    if (head == tail && head == current)
    {
        delete current;
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        return;
    }

    // node đầu
    if (current == head)
    {
        head = head->next;
        tail->next = head;
        delete current;
        current = head;
    }
    else
    {
        Node *prev = head;
        while (prev->next != current)
            prev = prev->next;

        prev->next = current->next;

        if (current == tail)
            tail = prev;

        delete current;
        current = prev->next;
    }
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void output(Node *head)
{
    if (head == nullptr)
        return;

    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// 1 tới n
// sort

int theFinalPlayer(Node *head, Node *tail)
{

    if (head == tail)
    {
        return head->data;
    }

    int count = 0;
    while (head->next != head)
    {
        cout << "Vong choi so: " << count / 8 + 1 << endl;
        Node *current = head;
        do
        {
            count++;
            cout << "So thu tu hien tai la: " << count << endl;

            cout << "Nguoi choi mang so thu tu hien tai la nguoi choi so : " << current->data << endl;

            if (isPrime(count))
            {
                cout << "Loai nguoi choi so " << current->data << endl;
                deleteNode(head, tail, current);

                cout << "Danh sach sau khi bi xoa: ";
                output(head);
                cout << endl;
            }
            else
            {
                current = current->next;
            }

        } while (current != head);
    }

    return head->data;
}

void theFinalPlayerVer2(Node *head, Node *tail, int winner)
{
    int idxFromplayer1 = theFinalPlayer(head, tail);

    cout << "Nguoi choi chien thang la nguoi choi so:  " << winner << endl;
    cout << " Nguoi choi bat dau dem tu 1 la nguoi choi so: " << abs(winner - idxFromplayer1 + 1) << endl;
}

// 7 số nguyên tố:
// kiểm tra
// => 3

// số người chơi:  1 2 3 4 5 6 7 8
// vòng 1 :        1 2 3 4 5 6 7 8
// còn lại:        1 4 6 8
// vong 2:         9 10 11 12
// còn lại:        1 4 8
// vòng 3:         13 14 15
// còn lại:        4 8
// vòng 4:         16 17
// còn lại:        4

// tìm số nguyên tố ở vị trí (n -1)

// nhập người chơi số n chiến thắng:
// điều kiện ( snt(n -1 ) -1)

// => thằng đếm số 1 đầu tiên là:

// số nguyên tố thứ 10 là 29

//

int main()
{

    Node *head, *tail;
    init(head, tail);

    for (int i = 0; i < 12; i++)
    {
        addNode(head, tail, i + 1);
    }

    cout << "Danh sach lien ket vong: ";
    output(head);

    // cout << "Tro choi nguoi cuoi cung: " << endl;
    // cout << "Bat dau tai nguoi choi so : 1" << endl;
    // int playerNumber = theFinalPlayer(head, tail);
    // cout << "va nguoi cuoi cung con sot lai la nguoi choi so: " << playerNumber << endl;

    cout << "Tro choi nguoi cuoi cung version 2: " << endl;
    theFinalPlayerVer2(head, tail, 6);

    return 0;
}