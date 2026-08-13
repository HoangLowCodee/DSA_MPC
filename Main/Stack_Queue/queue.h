#include <iostream>

using namespace std;

const int MAX = 100;

struct Queue
{
    int a[MAX];
    int front, rear;
};

void init(Queue &q)
{
    q.front = 0;
    q.rear = -1;
}

bool isEmpty(Queue q)
{
    return q.rear < q.front;
}

bool isFull(Queue q)
{
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, int x)
{
    if (!isFull(q))
    {
        q.a[++q.rear] = x;
    }
}

void dequeue(Queue &q)
{
    if (!isEmpty(q))
    {
        q.front++;
    }
}

void get(Queue q)
{
    if (!isEmpty(q))
    {
        cout << q.a[q.front] << endl;
    }
}

void display(Queue q)
{
    if (!isEmpty(q))
    {
        for (int i = q.front; i <= q.rear; i++)
        {
            cout << q.a[i] << " ";
        }
        cout << endl;
    }
}
