#include <iostream>

using namespace std;

template <class elemType>
class linkQueue {
private:
    struct node {
        elemType data;
        elemType num;
        node* next;
        node(const elemType& x, const elemType& y, node* N = NULL)
        {
            data = x;
            num = y;
            next = N;
        }
        node()
            : next(NULL)
        {
        }
        ~node() { }
    };
    node *front, *rear;

public:
    linkQueue();
    ~linkQueue();
    void enQueue(const elemType& x, const elemType& y);
    elemType deQueue();
    bool isEmpty() const;
};

template <class elemType>
linkQueue<elemType>::linkQueue()
{
    front = rear = NULL;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
    node* tmp;
    while (front != NULL) {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType& x, const elemType& y)
{
    if (rear == NULL)
        front = rear = new node(x, y);
    else {
        node* t;
        t = front;
        while (t->data != x) {
            t = t->next;

            if (t == NULL)
                break;
        }
        if (t == NULL) {
            t = new node(x, y);
            rear->next = t;
            rear = rear->next;
        } else {
            node* newNode = new node(0, 0);
            rear->next = newNode;
            while (t->next->data == x) {
                t = t->next;
            }
            rear->next = NULL;
            node* h;
            h = new node(x, y);
            h->next = t->next;
            t->next = h;
        }
    }
}

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node* tmp = front;
    elemType value = front->num;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    delete tmp;
    return value;
}

template <class elemType>
bool linkQueue<elemType>::isEmpty() const
{
    return (front == NULL);
}

int main()
{

    int n, *p;

    cin >> n;

    p = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int q, *r;

    cin >> q;

    r = new int[q];

    linkQueue<int> A;

    int flag = 1;

    for (int i = 0; i < q; i++) {
        cin >> r[i];
    }

    for (int i = 0; i < q; i++) {
        if (r[i] == 0 && flag < n) {
            A.enQueue(p[flag - 1], flag);
            flag = flag + 1;
        }

        if (r[i] == 1) {

            if (A.isEmpty())
                cout << -1;

            else
                cout << A.deQueue();
        }
    }
}
