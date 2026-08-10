// 1. Nhập Xuất Danh Sách Sinh Viên Từ File

// 7. Cập nhật
//    Cập nhật thông tin sinh viên theo mã sinh viên
//       - Đổi tên
//       - Đổi GPA
//    Cập nhật toàn bộ GPA tăng thêm 0.1 (mô phỏng cộng điểm)

// 3. Thống kê theo khoa
//       - Tính GPA trung bình của từng khoa
//       - Liệt kê sinh viên có GPA cao nhất của mỗi khoa (1 sinh viên cao nhất)
//       - So sánh GPA trung bình giữa các khoa

// 2. Tách Danh Sách Sinh Viên Thành 2 Danh Sách Theo GPA
// 3. Gộp 2 Danh Sách Sinh Viên Thành 1 Danh Sách Và Sort Theo GPA

#include <iostream>
#include <fstream>
#include <string>
#include <cmath> // để sử dụng hàm round()

using namespace std;

struct SinhVien
{
    int maSV;
    string tenSV;
    double GPA;

    void input()
    {
        cout << "Nhap ma so sinh vien: ";
        cin >> maSV;
        cin.ignore();
        cout << "Nhap ten sinh vien: ";
        getline(cin, tenSV);
        cout << "Nhap GPA: ";
        cin >> GPA;
    }

    void output()
    {
        cout << "Ma so sinh vien: " << maSV << endl;
        cout << "Ten sinh vien: " << tenSV << endl;
        cout << "GPA: " << GPA << endl;
    }
};

struct Node
{
    SinhVien data;
    Node *next;
};

void init(Node *&head)
{
    head = nullptr;
}

Node *createNode(SinhVien data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

// Thêm phần tử vào cuối danh sách liên kết
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

void output(Node *head)
{
    while (head != nullptr)
    {
        cout << endl;
        head->data.output();
        head = head->next;
    }

    cout << endl;
}

/*
ifstream là cin nhưng đọc từ file
ofstream là cout nhưng ghi ra file

SinhVien tensv, masv, gpa....

data.txt
    1
    2
    3

cin >> a ;
inFile >> a;

ifstream -> input -> cin
ofstream -> output -> cout

Các bước thao tác với file:
1. Khai báo biến ifstream hoặc ofstream
2. Mở file
3. Kiểm tra file có mở thành công không
4. Thao tác với file -> đọc hoặc ghi
5. Đóng file
*/

bool inputFile(Node *&head, string nameFile)
{
    // 1. Khai báo biến ifstream hoặc ofstream
    // 2. Mở file
    ifstream inFile(nameFile);

    // 3. Kiểm tra file có mở thành công không
    // is_open
    if (!inFile.is_open())
    {
        cout << "Khong Mo File Duoc " << endl;
        return false;
    }

    // 4. Thao tác với file -> đọc hoặc ghi
    int n;
    inFile >> n;

    for (int i = 0; i < n; i++)
    {
        SinhVien sv;
        inFile >> sv.maSV;
        inFile.ignore();
        getline(inFile, sv.tenSV);
        inFile >> sv.GPA;

        addTail(head, sv);
    }

    // 5. đóng file
    inFile.close();
    return true;
}

// đếm số lượng phần từ của List
int lengthList(Node *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}

bool outputFile(Node *head, string nameFile)
{
    ofstream outFile(nameFile);

    if (!outFile.is_open())
    {
        cout << "Khong Mo File Duoc " << endl;
        return false;
    }

    int length = lengthList(head);

    outFile << length << endl;

    while (head != nullptr)
    {
        outFile << head->data.maSV << endl;
        outFile << head->data.tenSV << endl;
        outFile << head->data.GPA << endl;

        head = head->next;
    }

    outFile.close();
    return true;
}

// Cập nhật thông tin sinh viên theo mã sinh viên
bool updateData(Node *&head, int mssv)
{
    Node *curr = head;

    // Tìm kiếm sinh viên theo mã sinh viên
    while (curr->next != nullptr && curr->data.maSV != mssv)
    {
        curr = curr->next;
    }

    // Nếu tìm thấy sinh viên, cập nhật thông tin
    if (curr != nullptr)
    {
        string name;
        double GPA;
        cout << "Nhap ten muon thay doi: " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Nhap Diem GPA muon thay doi: " << endl;
        cin >> GPA;

        GPA = round(GPA * 100) / 100;

        curr->data.tenSV = name;
        curr->data.GPA = GPA;

        cout << "Da Update Thanh Cong" << endl;
        return true;
    }

    // Nếu không tìm thấy sinh viên, thông báo lỗi
    cout << "Khong Tim Thay Sinh Vien" << endl;

    return false;
}

// login - validate

// - register
// username
// email
// password

// điểm cộng thêm - convert Englisht -
void updateGPAAllData(Node *&head, double deltaGPA)
{
    Node *curr = head;

    while (curr->next != nullptr)
    {
        curr->data.GPA += deltaGPA;
        curr->data.GPA = round(curr->data.GPA * 100) / 100; // làm tròn đến 2 chữ số thập phân
        curr = curr->next;
    }
}

void splitListByGPA(Node *head, Node *&list1, Node *&list2, double threshold)
{
    while (head != nullptr)
    {
        if (head->data.GPA >= threshold)
        {
            addTail(list1, head->data);
        }
        else
        {
            addTail(list2, head->data);
        }
        head = head->next;
    }
}

// có 2 cách gộp list
// 1. sort trước rồi gộp đặt tên hàm là SortAndMerge
// 2. gộp trước rồi sort MergeAndSort

void MergeAndSort(Node *&list1, Node *&list2, Node *&mergedList)
{
    // Gộp hai danh sách
    Node *curr = list1;
    while (curr != nullptr)
    {
        addTail(mergedList, curr->data);
        curr = curr->next;
    }

    curr = list2;
    while (curr != nullptr)
    {
        addTail(mergedList, curr->data);
        curr = curr->next;
    }

    // Sắp xếp danh sách đã gộp theo GPA giảm dần
    for (Node *i = mergedList; i != nullptr; i = i->next)
    {
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (i->data.GPA < j->data.GPA)
            {
                SinhVien temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void interchangeSort(Node *&list)
{
    for (Node *i = list; i != nullptr; i = i->next)
    {
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (i->data.GPA < j->data.GPA)
            {
                SinhVien temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void selectionSort(Node *&list)
{
    for (Node *i = list; i != nullptr; i = i->next)
    {
        Node *maxNode = i;
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (j->data.GPA > maxNode->data.GPA)
            {
                maxNode = j;
            }
        }
        if (maxNode != i)
        {
            SinhVien temp = i->data;
            i->data = maxNode->data;
            maxNode->data = temp;
        }
    }
}

void intertionSort(Node *&list)
{
    if (list == nullptr || list->next == nullptr)
        return;

    Node *sortedList = nullptr;

    Node *current = list;
    while (current != nullptr)
    {
        Node *nextNode = current->next;

        if (sortedList == nullptr || current->data.GPA >= sortedList->data.GPA)
        {
            current->next = sortedList;
            sortedList = current;
        }
        else
        {
            Node *temp = sortedList;
            while (temp->next != nullptr && temp->next->data.GPA > current->data.GPA)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    list = sortedList;
}

void bubbleSort(Node *&list)
{
    if (list == nullptr || list->next == nullptr)
        return;

    bool swapped;
    do
    {
        swapped = false;
        Node *current = list;
        while (current->next != nullptr)
        {
            if (current->data.GPA < current->next->data.GPA)
            {
                SinhVien temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}


void quickSort(Node *&list)
{
    if (list == nullptr || list->next == nullptr)
        return;

    Node *pivot = list;
    Node *lessHead = nullptr;
    Node *greaterHead = nullptr;

    Node *current = list->next;
    while (current != nullptr)
    {
        if (current->data.GPA >= pivot->data.GPA)
        {
            addTail(lessHead, current->data);
        }
        else
        {
            addTail(greaterHead, current->data);
        }
        current = current->next;
    }

    quickSort(lessHead);
    quickSort(greaterHead);

    // Gộp danh sách đã sắp xếp
    if (lessHead != nullptr)
    {
        list = lessHead;
        Node *temp = lessHead;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = pivot;
    }
    else
    {
        list = pivot;
    }

    pivot->next = greaterHead;
}

void sortAndMerge(Node *&list1, Node *&list2, Node *&mergedList)
{
    // Sắp xếp danh sách list1 theo GPA giảm dần
    for (Node *i = list1; i != nullptr; i = i->next)
    {
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (i->data.GPA < j->data.GPA)
            {
                SinhVien temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    // Sắp xếp danh sách list2 theo GPA giảm dần
    for (Node *i = list2; i != nullptr; i = i->next)
    {
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (i->data.GPA < j->data.GPA)
            {
                SinhVien temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    // Gộp hai danh sách đã sắp xếp
    Node *curr = list1;
    while (curr != nullptr)
    {
        addTail(mergedList, curr->data);
        curr = curr->next;
    }

    curr = list2;
    while (curr != nullptr)
    {
        addTail(mergedList, curr->data);
        curr = curr->next;
    }
}

int main()
{
    Node *head;
    init(head);

    inputFile(head, "SinhVienNode.txt");

    // cout << "Cap Nhap Thong Tin Sinh Vien " << endl;
    // int mssv;
    // cout << "Nhap mssv can cap nhap: ";
    // cin >> mssv;

    // updateData(head, mssv);
    updateGPAAllData(head, 0.1);

    outputFile(head, "SinhVienSave.txt");

    Node *list1, *list2;
    init(list1);
    init(list2);
    splitListByGPA(head, list1, list2, 3.0);
    cout << "Danh Sach Sinh Vien Co GPA >= 3.0" << endl;
    output(list1);
    cout << "Danh Sach Sinh Vien Co GPA < 3.0" << endl;
    output(list2);

    return 0;
}
