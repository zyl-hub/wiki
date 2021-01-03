#pragma once
#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class BSTNode {
 public:
  int _key = -1;
  BSTNode* _lchild;
  BSTNode* _rchild;
  BSTNode* _parent;

  BSTNode(int key, BSTNode* lchild, BSTNode* rchild, BSTNode* parent)
      : _key(key), _lchild(lchild), _rchild(rchild), _parent(parent){};
};

class BSTree {
 private:
  BSTNode* _Root;

 public:
  BSTree() : _Root(NULL){};
  ~BSTree(){};

  void insert(int key);

 private:
  void insert(BSTNode*& tree, BSTNode* z);
};

void BSTree::insert(BSTNode*& tree, BSTNode* z) {
  BSTNode* parent = NULL;
  BSTNode* temp = tree;

  //寻找插入点
  while (temp != NULL) {
    parent = temp;
    if (z->_key > temp->_key)
      temp = temp->_rchild;
    else
      temp = temp->_lchild;
  }
  z->_parent = parent;
  if (parent == NULL)  //如果树本来就是空树，则直接把z节点插入根节点
    tree = z;
  else if (z->_key > parent->_key)  //如果z的值大于其双亲，则z为其双亲的右孩
    parent->_rchild = z;
  else
    parent->_lchild = z;
}

void BSTree::insert(int key) {
  //创建一个新的节点，使用构造函数初始化
  BSTNode* z = new BSTNode(key, NULL, NULL, NULL);
  if (!z)  //如果创建失败则返回
    return;
  //调用内部函数进行插入
  insert(_Root, z);
  if (z->_parent == nullptr)
    cout << -1 << endl;
  else
    cout << z->_parent->_key << endl;
}
