template <class T>
class queue {
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const T& x) = 0;
    virtual T deQueue() = 0;
    virtual T getHead() const = 0;
    virtual ~queue() { }
};

template <class T>
class seqQueue : public queue<T> {
private:
    T* data;
    int maxSize;
    int front, rear;
    void doubleSpace();

public:
    seqQueue(int size = 10);
    ~seqQueue();
    bool isEmpty() const;
    void enQueue(const T& x);
    T deQueue();
    T getHead();
}
