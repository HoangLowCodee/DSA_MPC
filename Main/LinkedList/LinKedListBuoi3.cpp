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

    return 0;
}
