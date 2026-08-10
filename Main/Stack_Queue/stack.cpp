// Các thao tác cơ bản trên stack
// reverse chuỗi
// parse số thập phân sang nhị phân

#include <iostream>

using namespace std;

const int MAX = 100;

struct Stack
{
    char a[MAX];
    int top;
};

void init(Stack &s)
{
    s.top = -1;
}

bool isFull(Stack s)
{
    if (s.top == MAX - 1)
    {
        cout << "Stack da full roi \n";
        return false;
    }
    return true;
}

bool isEmpty(Stack s)
{

    if (s.top == -1)
    {
        cout << "Stack dang rong: \n";
        return false;
    }
    return true;
}

void push(Stack &s, char data)
{
    if (isFull(s))
        s.a[++s.top] = data;
}

void pop(Stack &s)
{
    if (isEmpty(s))
        s.top--;
}

int get(Stack &s)
{
    if (isEmpty(s))
        return s.a[s.top];
    return -1;
}

// string hoang
//  char = {h,o,a,n,g};

void reverseStr(Stack &s, string str)
{

    for (int i = 0; i < str.length(); i++)
    {
        push(s, str[i]);
    }
    string newStr = "";
    cout << str.length() << endl;
    cout << s.top << endl;
    int length = s.top;

    for (int i = 0; i < str.length(); i++)
    {
        newStr += get(s);
        pop(s);
    }

    cout << "Chuoi sau khi reverse: " << newStr << endl;
}

void output(Stack s)
{
    if (isEmpty(s))
    {
        cout << "Stack: ";
        for (int i = 0; i <= s.top; i++)
            cout << s.a[i] << " ";
    }
}

void DecToBi(Stack s, int decData)
{
    // 100
    while (decData > 0)
    {
        push(s, decData % 2);
        decData /= 2;
    }

    cout <<"top: " << s.top << endl; // 0 - 6: 7 phần tử 

    int n = s.top;



    for (int i = 0; i <= n ; i++)
    {
        cout << get(s); // get
        pop(s); // pop giảm top xuống 1
    }
}

int main()
{
    Stack s;
    init(s);
    // push(s, 1);
    // push(s, 2);
    // push(s, 3);
    // push(s, 4);
    // push(s, 5);
    // push(s, 6);

    // output(s);
    // cout << endl;

    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // pop(s);
    // output(s);
    DecToBi(s, 100);

    return 0;
}