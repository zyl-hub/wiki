#ifndef LinkList_H_
#define LinkList_H
template <class T>
class list {
  public:
  virtual void clear() = 0;
  virtual int length() const = 0;
  virtual void insert(int i, const T& x) = 0;
  virtual void remove(int i) = 0;
  virtual int search(const T& x) const = 0;
  virtual T visit(int i) const = 0;
  virtual void traverse() const = 0;
  virtual ~list() {};
};

template <class T>
class seqList : public list<T> {
  private:
  T* data;
  int currentLength;
  int maxSize;
  void doubleSpace();

  public:
  seqList(int initialSize = 10);
  ~seqList();
  void clear();
  int length() const;
  void insert(int i, const T& x);
  void remove(int i);
  int search(const T& x) const;
  T visit(int i) const;
  void traverse() const;
};
#endif

template <class T>
class sLinkList : public list<T> {
  private:
  struct node {
    T data;
    node* next;

    node(const T& x, node* n = 0)
    {
      data = x;
      next = n;
    }

    node()
        : next(0)
    {
    }
    ~node() { }
  };

  node* head;
  int currentLength;

  node* move(int i) const;

  public:
  sLinkList();
  ~sLinkList()
  {
    clear();
    delete head;
  }

  void clear();
  int length() const { return currentLength; }
  void insert(int i, const T& x);
  void remove(int i);
  int search(const T& x) const;
  T visit(int i) const;
  void traverse() const;
  void erase(int i);
};
