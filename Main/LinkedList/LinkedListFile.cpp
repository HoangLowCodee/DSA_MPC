#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SinhVien
{
    int maSV;
    string ten;
    double GPA;
};

struct Node
{
    SinhVien data;
    Node *next;
};

struct List
{
    Node *head = nullptr;
    Node *Tail = nullptr;
};

Node *createNode(SinhVien sv)
{
    Node *newNode = new Node;
    newNode->data = sv;
    newNode->next = nullptr;

    return newNode;
}

void insertTail(List &l, SinhVien sv)
{
    Node *newNode = createNode(sv);
    if (l.head == nullptr)
        l.head = l.Tail = newNode;
    else
    {
        l.Tail->next = newNode;
        l.Tail = newNode;
    }
}

bool loadFromFile(string nameFile, List &l)
{
    ifstream inFile(nameFile);

    if (!inFile.is_open())
    {
        cout << "Khong the mo file " << endl;
        return false;
    }

    int n;
    inFile >> n;
    inFile.ignore();

    for (int i = 0; i < n; i++)
    {
        SinhVien sv;
        inFile >> sv.maSV;
        inFile.ignore();
        getline(inFile, sv.ten);
        inFile >> sv.GPA;
        inFile.ignore();

        insertTail(l, sv);
    }

    inFile.close();
    cout << "Da lay du lieu" << endl;
    return true;
}

bool saveToFile(string nameFile, List l)
{
    ofstream outFile(nameFile);

    if (!outFile.is_open())
    {
        cout << "Khong the mo file" << endl;
        return false;
    }

    int count = 0;
    Node *cur = l.head;

    while (cur != nullptr)
    {
        count++;
        cur = cur->next;
    }

    outFile << count << endl;

    cur = l.head;
    while (cur != nullptr)
    {
        outFile << cur->data.maSV << endl;
        outFile << cur->data.ten << endl;
        outFile << cur->data.GPA << endl;
        cur = cur->next;
    }
    outFile.close();

    cout << "Da luu du lieu thanh cong" << endl;
    return true;
}

void output(List l)
{
    while (l.head != nullptr)
    {
        cout << endl;
        cout << "Ma Sinh Vien la: " << l.head->data.maSV << endl;
        cout << "Ten Sinh Vien la: " << l.head->data.ten << endl;
        cout << "GPA cua sinh vien la: " << l.head->data.GPA << endl;

        l.head = l.head->next;
    }
}

int main()
{
    List l;

    if (loadFromFile("SinhVienNode.txt", l))
    {
        cout << "Danh Sách Sinh Vien Tu File: " << endl;
        output(l);
    }

    saveToFile("SinhVienSave.txt", l);

    return 0;
}