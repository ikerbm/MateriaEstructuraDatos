#include <iostream>
#include <functional>
#include <vector>

using namespace std;

template <typename Key,typename Value>
class Map {
 private:
  class Node {
   private:
    Key k;
    Value v;
    Node* left;
    Node* right;

   public:
    Node(const Key& a,const Value& b) : k(a),v(b), left(nullptr), right(nullptr) {}

    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setLeft(Node* n) { left = n; }
    void setRight(Node* n) { right = n; }

    bool hasLeft() const { return left != nullptr; }
    bool hasRight() const { return right != nullptr; }
    bool isLeaf() const { return !hasLeft() && !hasRight(); }

    const Key& getKey() const { return k; }
    Key& getKey() { return k; }

    const Value& getValue() const { return v; }
    Value& getValue() { return v; }
  };

  Node* root;
  unsigned int sz;

 public:
  Map() : root(nullptr), sz(0) {}
  Map(const Map<Key,Value>& t) {
    root = copy(t.root);
    sz = t.sz;
  }
  ~Map() { clear(root); }

 private:
  void clear(Node* n) {
    if (n == nullptr) {
      return;
    } else if (n->isLeaf()) {
      delete n;
    } else {
      clear(n->getLeft());
      clear(n->getRight());
      delete n;
    }
  }
  Node* copy(Node* n) {
    if (n == nullptr) {
      return nullptr;
    } else if (n->isLeaf()) {
      return new Node(n->getKey(),n->getValue());
    } else {
      Node* cl = copy(n->getLeft());
      Node* cr = copy(n->getRight());
      Node* r = new Node(n->getKey(),n->getValue());
      r->setLeft(cl);
      r->setRight(cr);
      return r;
    }
  }
 public:
  bool empty() const { return root == nullptr; }
  unsigned int size() const { return sz; }

  void insert(const Key& k, const Value& v) {
     root = insert(k,v, root);
   }
 private:
  Node* insert(const Key& k, const Value& v, Node* n) {
    if (n == nullptr) {
      Node* x = new Node(k,v);
      sz++;
      return x;
    } else if (k < n->getKey()) {
      n->setLeft(insert(k,v, n->getLeft()));
      return n;
    } else {
      n->setRight(insert(k,v, n->getRight()));
      return n;
    }
  }
public:
  Value find(const Key& k) const {
    Node* find(k, root)
    if(n==nullptr)
      return Value();
    return n->getValue();
   }
   bool contains(const Key& k) const{
     return find(k,root)!=nullptr;
   }

 private:
  Node* find(const Key& k, Node* n) const {
    if (n == nullptr || k == n->getKey()) {
      return n;
    } else if (k < n->getKey()) {
      return find(k, n->getLeft());
    } else {
      // e > n->getData()
      return find(k, n->getRight());
    }
  }
/*
 public:
  void print() const { return print(root); }

 private:
  void print(Node* n) const {
    if (n == nullptr) {
      return;
    } else if (n->isLeaf()) {
      cout << n->getData() << endl;
    } else {
      print(n->getLeft());
      cout << n->getData() << endl;
      print(n->getRight());
    }
  }

 public:
  void inorder(function<void(const T& e)> f) const { inorder(f, root); }
 private:
  void inorder(function<void(const T& e)> f, Node* n) const {
    if (n == nullptr) {
      return;
    } else {
      inorder(f, n->getLeft());
      f(n->getData());
      inorder(f, n->getRight());
    }
  }

 public:
  void preorder(function<void(const T& e)> f) const { preorder(f, root); }
 private:
  void preorder(function<void(const T& e)> f, Node* n) const {
    if (n == nullptr) {
      return;
    } else {
      f(n->getData());
      preorder(f, n->getLeft());
      preorder(f, n->getRight());
    }
  }

 public:
  void postorder(function<void(const T& e)> f) const { postorder(f, root); }
 private:
  void postorder(function<void(const T& e)> f, Node* n) const {
    if (n == nullptr) {
      return;
    } else {
      postorder(f, n->getLeft());
      postorder(f, n->getRight());
      f(n->getData());
    }
  }
  */
};

int main() {
  std::cout << "Hello World!"<<endl;
  Map<string,int>edades;
  edades.insert("leidy",18);
  edades.insert("iker",18);
  edades.insert("juanjose",20);
  cout<<"tamaño "<<edades.size()<<endl;
  cout<<"edad de "<<edades.find("juanjose")<<endl;

  Map<string,string> cantantes;
  cantantes.insert("leidy","morat");
  cantantes.insert("iker","fanny lu");
  cantantes.insert("juan pablo","hoizer");

  cout<<cantantes.find("iker")<<endl;
  cout<<cantantes.find("juan jose")<<endl;

  cout<<endl;
}
