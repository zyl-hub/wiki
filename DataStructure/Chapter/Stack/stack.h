template <class T>
class stack {
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const T& x) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual ~stack() {};
};

template <class T>
class seqStack : public stack<T> {
private:
    T* elem;
    int top_p;
    int maxSize;
    void doubleSpace();

public:
    seqStack(int initSize = 10);
    ~seqStack();
    bool isEmpty() const;
    void push(const T& x);
    T pop();
    T top() const;
};

template <class T>
class linkStack : public stack<T> {
private:
    struct node {
        T data;
        node* next;
        node(const T& x, node* N = 0)
        {
            data = x;
            next = N;
        }
        node()
            : next(0)
        {
        }
        ~node() { }
    };

    node* top_p;

public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const T& x);
    T pop();
    T top() const;
};
