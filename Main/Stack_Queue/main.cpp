#include "queue.h"


using namespace std;

int main()
{
    Queue q;
    init(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << "Queue elements: ";
    display(q);

    cout << "Front element: ";
    get(q);

    dequeue(q);
    cout << "After dequeue, queue elements: ";
    display(q);

    return 0;
}